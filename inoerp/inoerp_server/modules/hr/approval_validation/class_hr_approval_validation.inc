<?php
/**
 * inoERP - Version 0.1.1
 *
 * @copyright 2014 Nishit R. Das
 * @license   https://www.mozilla.org/MPL/2.0/
 * @link       http://inoideas.org
 * @source code https://github.com/inoerp/inoERP
 */

/**
 * hr_approval_validation
 * 
 */

 class hr_approval_validation extends dbObject {

  public static $table_name = "hr_approval_validation";
  public static $module = "hr";
  
   public static $system_info = [
  'name' => 'Approval Validation',
  'number' => '3104',
  'description' => 'HR Approval Validation',
  'version' => '0.1.1',
  'db_version' => '1001',
  'mod_version' => '1.1.1',
  'primary_entity_cb' => '',
  'module_name' => 'hr',
  'weight' => 4
 ];
   
  public $reference_key_name;
  public $reference_key_value;
  public $approving_user_id;
  public $approving_doc_name;
  public $doc_amount;
  public $approval_hierarchy;
  public $notification_subject;
  public $notification_text;

  public function check_approval() {
   /* 1. Check the approval option for the BU - Employee Supervisor or Position Base
     2. Find the employee details of the current user
     3. Find the position(if not available then job) of the current employee
     4. Get the approval limits of the position/job
     5. If approval limit is good then approve the po
     6. ELse create an approal notification for the superviosr/role and put the PO in inProcess
    */
   $return_array = [];

   $position_approval_details = hr_employee_position_v::find_by_userId_docType($this->approving_user_id, $this->approving_doc_name);
   if (empty($position_approval_details)) {
    $return_array['status'] = 'ENTERED';
    $return_array['message'] = 'No approval limit found for the employee document combination';
    return $return_array;
   }
   foreach ($position_approval_details as $obj) {
    if ($obj->limit_object == 'TOTAL_AMOUNT') {
     $amount_limit = $obj->amount_limit;
     if ($amount_limit >= $this->doc_amount) {
      $return_array['status'] = 'APPROVED';
      $return_array['message'] = "PO Approved By $this->approving_user_id";
     } else {
      //create notification
      $return_array['status'] = 'INPROCESS';
      $return_array['message'] = " Approval request is submitted by user id $this->approving_user_id ";
     }
    }
   }
   if ($return_array['status'] == 'INPROCESS') {
    //create notification
    $notif = new sys_notification();
    $notif->notification_type = 'APPROVAL';
    $notif->notification_name = 'PO_APPROVAL';
    $notif->from_user_id = $this->approving_user_id;
//    $employee_details = hr_employee_p::find_by_id($this->employee_id);
    $notif->from_user = $position_approval_details[0]->first_name . ' ' . $position_approval_details[0]->last_name;
    if (empty($position_approval_details[0]->supervisor_employee_id)) {
     $return_array['status'] = 'INCOMPLETE';
     $return_array['message'] = " No Supervisor found for $notif->from_user ";
     return $return_array;
    }
    $supr_employee_details = hr_employee::find_by_id($position_approval_details[0]->supervisor_employee_id);
    $supr_user_details = ino_user::find_by_employeeId($position_approval_details[0]->supervisor_employee_id);
    $notif->to_user_id = $supr_user_details->user_id;
    $notif->to_user = $supr_employee_details->first_name . ' ' . $supr_employee_details->last_name;
    $notif->to_email = $supr_employee_details->email;
    $notif->reference_key_name = $this->reference_key_name;
    $notif->reference_key_value = $this->reference_key_value;
    $notif->status = 'OPEN';
    $notif->start_date = current_time(true);
    $notif->notification_subject = $this->notification_subject;
    $notif->text_field1 = $this->notification_text;
    $notif->audit_trial();
    $notif->save();
    $notif->_after_save();
   }
   return $return_array;
  }

 }

//end of hr_approval_validation class
?>