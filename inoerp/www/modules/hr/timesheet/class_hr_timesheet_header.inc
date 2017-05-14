<?php

class hr_timesheet_header extends dbObject implements hr_approval_int {

 public static $table_name = "hr_timesheet_header";
 public static $dependent_classes = ['hr_timesheet_line'];
 public static $primary_column = "hr_timesheet_header_id";
 public static $key_column = 'hr_employee_id';
 public static $module = "hr";
 public $field_a = [
  'hr_timesheet_header_id',
  'hr_timesheet_period_id',
  'approver_employee_id',
  'entered_on',
  'approved_on',
  'hr_employee_id',
  'approved_date',
  'approved_by_employee_id',
  'status',
  'created_by',
  'creation_date',
  'last_update_by',
  'last_update_date',
 ];
 public static $status_a = [
  'ENTERED' => 'Entered',
  'APPR_HOLD' => 'Approval Hold',
  'APPROVED' => 'Approved',
  'FREEZED' => 'Freezed',
 ];
 public $action_a = [
  'APPROVE' => 'Approve / Send For Approval',
 ];
 public $initial_search = [
  'hr_employee_id',
  'approver_employee_id',
 ];
 public $requiredField = [
  'hr_timesheet_period_id',
  'approver_employee_id',
  'entered_on',
  'hr_employee_id',
 ];
 public $fields_inForm_notInDataBase = [
  'identification_id',
  "employee_name",
  'approver_employee_name',
  'action'
 ];
 public $search = [
  '_show_update_path' => 1,
  '_show_view_path' => 1,
 ];
 public $pageTitle = " Timesheet "; //page Title
 public $hr_timesheet_header_id;
 public $hr_timesheet_period_id;
 public $approver_employee_id;
 public $entered_on;
 public $approved_on;
 public $hr_employee_id;
 public $approved_date;
 public $approved_by_employee_id;
 public $status;
 public $created_by;
 public $creation_date;
 public $last_update_by;
 public $last_update_date;
 public $identification_id;
 public $employee_name;
 public $approver_employee_name;
 public $action;
 

 public function _after_save() {
  if (($this->action == 'APPROVE')) {
   try {
    $this->send_document_for_approval();
    echo "<br>Approval action is sucessfully completed";
   } catch (Exception $e) {
    echo "<br>Failed to complete the approval action. Error @ " . __FILE__ . ' @@ line ' . __LINE__ . '<br>' . $e->getMessage();
    return -90;
   }
  }
 }

 public static function find_by_buOrgId_status($bu_org_id, $status = "") {
  $sql = " SELECT * FROM ";
  $sql .= self::$table_name;
  $sql .= " WHERE bu_org_id = '{$bu_org_id}' ";
  if (!empty($status)) {
   $sql .= " AND status = '{$status}' ";
  }
  $result = self::find_by_sql($sql);
  return !empty($result) ? ($result) : false;
 }

 private function send_document_for_approval() {
  $approving_user_id = $_SESSION['user_id'];
  $ts_h = new hr_timesheet_header();
  $ts_h->findBy_id($this->hr_timesheet_header_id);

  $emp_i = new hr_employee();
  $emp_i->findBy_id($this->hr_employee_id);

  //create notification
  $notif = new sys_notification();
  $notif->notification_type = 'APPROVAL';
  $notif->notification_name = 'TIMESHEET';
  $notif->from_user_id = $approving_user_id;
//    $employee_details = hr_employee_p::find_by_id($this->employee_id);
  $notif->from_user = $emp_i->first_name . ' ' . $emp_i->last_name;
  if (empty($emp_i->supervisor_employee_id)) {
   $comment_msg = " No Supervisor found for $notif->from_user ";
   $this->write_comment($approving_user_id, $comment_msg);
   $ts_h->status = 'APPR_HOLD';
   $ts_h->save();
   return;
  }
  $supr_employee_details = hr_employee::find_by_id($emp_i->supervisor_employee_id);
  $supr_user_details = ino_user::find_by_employeeId($emp_i->supervisor_employee_id);
  $notif->to_user_id = $supr_user_details->user_id;
  $notif->to_user = $supr_employee_details->first_name . ' ' . $supr_employee_details->last_name;
  $notif->to_email = $supr_employee_details->email;
  $notif->reference_key_name = 'hr_timesheet_header';
  $notif->reference_key_value = $this->hr_timesheet_header_id;
  $notif->status = 'OPEN';
  $notif->start_date = current_time(true);
  $notif->notification_subject = "Timesheet Entry From " . $notif->from_user . ' Claim#' . $this->hr_timesheet_header_id;
  $notif->text_field1 = "<br>Name :  " . $notif->from_user;
  $notif->text_field1 .= "<br>Etered Date : $this->entered_on (Employee Id : $this->hr_employee_id) ";
  
  $notif->save();
  $notif->_after_save();

  $ts_h->status = 'INPROCESS';
  $ts_h->save();

  $comment_msg = " Timesheet is sent for approval to $notif->to_user ";
  $this->write_comment($approving_user_id, $comment_msg);
 }

 public function approve_document() {
  $approving_user_id = $_SESSION['user_id'];
  $ts_h = new hr_timesheet_header();
  $ts_h->findBy_id($this->hr_timesheet_header_id);

  $user_i = ino_user::find_by_id($approving_user_id);

  $ts_h->status = 'APPROVED';
  $comment_msg = " Timesheet is Approved By $approving_user_id ";

  $ts_h->approved_by_employee_id = $user_i->hr_employee_id;
  $ts_h->approved_on = current_time();
  $ts_h->update_changesOnly($ts_h->hr_timesheet_header_id);
  $ts_h->write_comment($approving_user_id, $comment_msg);
 }

 public function notification_action($obj) {
  $this->findBy_id($obj->reference_key_value);
  if ($obj->notification_action == 'APPROVE') {
   try {
    $this->approve_document();
   } catch (Exception $e) {
    $this->rollback = true;
    echo "<br> Unable to complete the approval process " . $e->getMessage();
   }
  } else if ($obj->notification_action == 'REJECT') {
   $this->status = 'REJECTED';
   $this->approved_by = $obj->to_user;
   $this->approved_date = current_time();
   $this->update($this->hr_timesheet_header_id);
  }
 }

}

//end of hr_timesheet_header class
?>