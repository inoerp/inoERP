<?php
/**
 * inoERP
 *
 * @copyright   2014 Nishit R. Das
 * @license     https://www.mozilla.org/MPL/2.0/
 * @link        http://inoideas.org
 * @source code https://github.com/inoerp/inoERP
 */

/**
 * hr_leave_transaction
 * All Leave Transactions
 * Contains all the hr_leave_transaction information, such as - employee_id, requsted_date , approved_date, description, etc
 * 
 */
 class hr_leave_transaction extends dbObject {

  public static $table_name = "hr_leave_transaction";
  public static $primary_column = "hr_leave_transaction_id";
  public static $key_column = 'employee_id';
  public static $module = "hr";
  public static $transaction_type_a = [
   'NEGATIVE' => 'Neagtive',
   'POSITIVE' => 'Positive',
  ];
  public static $leave_status_a = [
   'ENTERED' => 'Entered',
   'APPROVED' => 'Approved',
   'CANCELLED' => 'Cancelled',
  ];
  public $leave_action_a = [
   'CANCEL' => 'Cancel',
  ];
  public $field_a = [
   'hr_leave_transaction_id',
   'employee_id',
   'requsted_date',
   'approved_date',
   'approved_by',
   'approved_by_employee_id',
   'leave_status',
   'leave_type',
   'transaction_type',
   'leave_quantity',
   'from_date',
   'to_date',
   'reason',
   'contact_details',
   'sys_notification_group_id',
   'sys_notification_id',
   'created_by',
   'creation_date',
   'last_update_by',
   'last_update_date',
  ];
  public $initial_search = [
   'hr_leave_transaction_id',
   'employee_id',
  ];
  public $fields_inForm_notInDataBase = [
   "employee_name",
   'identification_id',
   'leave_action',
  ];
  public $requiredField = [
   'employee_id',
   'requsted_date',
   'from_date',
   'to_date',
  ];
  public $number_fields = [
   'leave_quantity'
  ];
  
  public $hr_leave_transaction_id;
  public $employee_id;
  public $requsted_date;
  public $approved_date;
  public $approved_by;
  public $approved_by_employee_id;
  public $leave_status;
  public $leave_type;
  public $transaction_type;
  public $leave_quantity;
  public $from_date;
  public $to_date;
  public $reason;
  public $contact_details;
  public $created_by;
  public $creation_date;
  public $last_update_by;
  public $last_update_date;
  public $employee_name;
  public $identification_id;
  public $sys_notification_id;
  public $sys_notification_group_id;
  public $leave_action;
  public $search = [
   '_show_update_path' => 1,
   '_show_view_path' => 1,
  ];
  public $pageTitle = " HR Leave Transactions  "; //page Title

  public function _before_save() {
   $start_date = new DateTime($this->from_date);
   $to_date = new DateTime($this->to_date);

   if ($start_date > $to_date) {
    echo "To date can't be less than from date";
//    pa($start_date);pa($to_date);pa($start_date->diff($to_date, false));
    return -99;
   }
   if (empty($this->leave_status)) {
    $this->leave_status = 'ENTERED';
   }

   if (empty($this->leave_quantity)) {
    $no_of_days = $to_date->diff($start_date, false);
    $this->leave_quantity = $no_of_days->days;
   }
  }

  public function _after_save() {
   if (!empty($this->hr_leave_transaction_id) && empty($this->sys_notification_id) && !empty($this->employee_id)) {
    //create notification
    $notif = new sys_notification();
    $notif->notification_type = 'APPROVAL';
    $notif->notification_name = 'LEAVE_APPLICATION';
    $notif->from_user_id = $_SESSION['user_id'];
    $employee_details = hr_employee::find_by_id($this->employee_id);
    $supr_employee_details = hr_employee::find_by_id($employee_details->supervisor_employee_id);
    $supr_user_details = ino_user::find_by_employeeId($employee_details->supervisor_employee_id);
    $notif->to_user_id = $supr_user_details->user_id;
    $notif->from_user = $employee_details->first_name . ' ' . $employee_details->last_name;
    $notif->to_user = $supr_employee_details->first_name . ' ' . $supr_employee_details->last_name;
    $notif->to_email = $supr_employee_details->email;
    $notif->reference_key_name = 'hr_leave_transaction';
    $notif->reference_key_value = $this->hr_leave_transaction_id;
    $notif->status = 'OPEN';
    $notif->start_date = current_time(true);
    $notif->notification_subject = "Leave Application From " . $notif->from_user;
    $notif->text_field1 = "<br>Leave Type : $this->leave_type ";
    $notif->text_field1 .= "<br>From Date : $this->from_date &nbsp;&nbsp; To Date : $this->to_date";
    $notif->text_field1 .= "<br>Reason : $this->reason ";
    $notif->text_field1 .= "<br>Contact : $this->contact_details ";
    $notif->audit_trial();
    $notif->save();
    $notif->_after_save();
   }
  }

  private function _leave_approved() {
   $lb = new hr_leave_balance();
   $lb_i = $lb->findBy_employeeId_leaveType($this->employee_id, $this->leave_type);
   foreach ($lb_i as $k => $v) {
    $lb->$k = $v;
   }
   $lb->total_available -= $this->leave_quantity;
   $lb->audit_trial();
   $lb->update($lb->hr_leave_balance_id);
  }

  public function notification_action($obj) {
   $this->findBy_id($obj->reference_key_value);
   if ($obj->notification_action == 'APPROVE') {
    try {
     $this->leave_status = 'APPROVED';
     $this->_leave_approved();
    } catch (Exception $e) {
     $this->rollback = true;
     echo "<br> Unable to complete the leave process " . $e->getMessage();
    }
   } else if ($obj->notification_action == 'REJECT') {
    $this->leave_status = 'REJECTED';
   }
   $this->approved_by = $obj->to_user;
   $this->approved_date = current_time();
   $this->audit_trial();
   $this->update($this->hr_leave_transaction_id);
  }

//  public function _before_showing() {
//   if (!empty($this->employee_id)) {
//    $emp_details = hr_employee::find_by_id($this->employee_id);
//    $this->identification_id = $emp_details->identification_id;
//    $this->employee_name = $emp_details->first_name . ' ' . $emp_details->last_name;
//   }
//  }

  public static function find_all_line_levels() {
   $sql = " SELECT * FROM ";
   $sql .= self::$table_name;
   $sql .= " WHERE level = 'LINE' ";
   $result = self::find_by_sql($sql);
   return !empty($result) ? $result : false;
  }

  public static function find_by_transactionClass($class) {
   $sql = " SELECT * FROM ";
   $sql .= self::$table_name;
   $sql .= " WHERE type_class = '{$class}' AND status='active'";
   $result = self::find_by_sql($sql);
   return $result;
  }

  public static function usage_sum_by_employeeId_leaveType($leave_type) {
   $sql = " SELECT SUM(leave_quantity) as total_leave FROM ";
   $sql .= self::$table_name;
   $sql .= " WHERE leave_type = '{$leave_type}' AND leave_status='APPROVED' AND transaction_type='NEGATIVE' ";
   $result = self::find_by_sql($sql);
   return !empty($result) ? $result[0]->total_leave : false;
  }

 }

//end of hr_leave_transaction class
?>