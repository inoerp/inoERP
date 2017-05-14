<?php

class hr_expense_header extends dbObject implements hr_approval_int {

 public static $table_name = "hr_expense_header";
 public static $dependent_classes = ['hr_expense_line'];
 public static $primary_column = "hr_expense_header_id";
 public static $key_column = 'hr_employee_id';
 public static $module = "hr";
 public $field_a = [
  'hr_expense_header_id',
  'claim_number',
  'bu_org_id',
  'hr_employee_id',
  'claim_date',
  'approved_date',
  'approved_by',
  'approved_by_employee_id',
  'status',
  'purpose',
  'expense_template_id',
  'doc_currency',
  'department_id',
  'reason',
  'contact_details',
  'currency',
  'exchange_rate_type',
  'exchange_rate',
  'header_amount',
  'created_by',
  'creation_date',
  'last_update_by',
  'last_update_date',
 ];
 public static $status_a = [
  'ENTERED' => 'Entered',
  'APPR_HOLD' => 'Approval Hold',
  'APPROVED' => 'Approved',
  'INPROCESS' => 'InProcess',
  'INVOICED' => 'Invoiced',
  'CANCELLD' => 'Cancelled',
 ];
 public $action_a = [
  'PRINT' => 'Print',
  'APPROVE' => 'Approve / Send For Approval',
  'INVOICED' => 'Invoiced',
  'CANCEL' => 'Cancel',
 ];
 public $fields_inDataBase_notInForm = [
  'currency'
 ];
 public $initial_search = [
  'hr_employee_id',
  'claim_date',
  'approved_date',
  'approved_by',
 ];
 public $requiredField = [
  'hr_employee_id',
  'claim_date',
  'approved_by_employee_id',
  'expense_template_id',
  'doc_currency',
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
 public $pageTitle = " Employee Expense "; //page Title
 public $option_lists = [
  'approval_status' => 'APPROVAL_STATUS',
 ];
 public $profile_default = [
  'exchange_rate_type' => 'gl_currency_conversion_type',
  'bu_org_id' => 'org_bu_name_default',
  'ship_to_id' => 'ship_to_address_default',
  'bill_to_id' => 'bill_to_address_default'
 ];
 public $hr_expense_header_id;
 public $bu_org_id;
 public $claim_number;
 public $hr_employee_id;
 public $claim_date;
 public $approved_date;
 public $approved_by;
 public $approved_by_employee_id;
 public $status;
 public $purpose;
 public $expense_template_id;
 public $doc_currency;
 public $currency;
 public $department_id;
 public $exchange_rate_type;
 public $exchange_rate;
 public $reason;
 public $contact_details;
 public $header_amount;
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
    $this->approve_document();
    echo "<br>Approval action is sucessfully completed";
   } catch (Exception $e) {
    echo "<br>Failed to complete the approval action. Error @ " . __FILE__ . ' @@ line ' . __LINE__ . '<br>' . $e->getMessage();
    return -90;
   }
  }
  if (empty($this->claim_number) && !empty($this->hr_expense_header_id)) {
   $this->_set_claim_number();
  }
 }

 private function _set_claim_number() {
  $this->claim_number = $this->bu_org_id . '-' . $this->hr_expense_header_id;
  $this->save();
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

 public function approve_document() {
  /* 1. Check the approval option for the BU - Employee Supervisor or Position Base
    2. Find the employee details of the current user
    3. Find the position(if not available then job) of the current employee
    4. Get the approval limits of the position/job
    5. If approval limit is good then approve the po
    6. ELse create an approal notification for the superviosr/role and put the PO in inProcess
   */
  $hr_control = hr_control::find_by_org_id($this->bu_org_id);
  if ($hr_control) {
   switch ($hr_control->expense_claim_approval) {
    case 'SUPERVISOR' :
     $this->_approve_by_supervisor();
     break;
    case 'AMOUNT_LIMIT' :
     $this->_approve_by_amount_limit();
     break;
   }
  } else {
   throw new Exception("No HR control found for the bu_org_id" . $this->bu_org_id);
  }
 }

 private function _approve_by_supervisor() {
  $approving_user_id = $_SESSION['user_id'];
  $exp_claim = new hr_expense_header();
  $exp_claim->findBy_id($this->hr_expense_header_id);

  $emp_i = new hr_employee();
  $emp_i->findBy_id($this->hr_employee_id);

  //create notification
  $notif = new sys_notification();
  $notif->notification_type = 'APPROVAL';
  $notif->notification_name = 'EXPENSE_CLAIM';
  $notif->from_user_id = $approving_user_id;
//    $employee_details = hr_employee_p::find_by_id($this->employee_id);
  $notif->from_user = $emp_i->first_name . ' ' . $emp_i->last_name;
  if (empty($emp_i->supervisor_employee_id)) {
   $comment_msg = " No Supervisor found for $notif->from_user ";
   $this->write_comment($approving_user_id, $comment_msg);
   $exp_claim->status = 'APPR_HOLD';
   $exp_claim->save();
   return;
  }
  $supr_employee_details = hr_employee::find_by_id($emp_i->supervisor_employee_id);
  $supr_user_details = ino_user::find_by_employeeId($emp_i->supervisor_employee_id);
  $notif->to_user_id = $supr_user_details->user_id;
  $notif->to_user = $supr_employee_details->first_name . ' ' . $supr_employee_details->last_name;
  $notif->to_email = $supr_employee_details->email;
  $notif->reference_key_name = 'hr_expense_header';
  $notif->reference_key_value = $this->hr_expense_header_id;
  $notif->status = 'OPEN';
  $notif->start_date = current_time(true);
  $notif->notification_subject = "Expense Claim From " . $notif->from_user . ' Claim#' . $this->hr_expense_header_id;
  $notif->text_field1 = "<br>Name :  " . $notif->from_user;
  $notif->text_field1 = "<br>Purpose :  " . $this->purpose;
  $notif->text_field1 = "<br>Reason :  " . $this->reason;
  $notif->text_field1 .= "<br>Currency : $this->doc_currency &nbsp;&nbsp; Amount : $this->header_amount";
  $notif->text_field1 .= "<br>Claim Date : $this->claim_date (Employee Id : $this->hr_employee_id) ";
  $notif->text_field1 .= "<br>Contact Details : $this->contact_details ";
  $notif->save();
  $notif->_after_save();

  $exp_claim->status = 'INPROCESS';
  $exp_claim->save();

  $comment_msg = " Claim is sent for approval to $notif->to_user ";
  $this->write_comment($approving_user_id, $comment_msg);
 }

 private function _approve_by_amount_limit() {
  $approving_user_id = $_SESSION['user_id'];
  $exp_claim = new hr_expense_header();
  $exp_claim->findBy_id($this->hr_expense_header_id);
  $position_approval_details = hr_employee_position_v::find_by_userId_docType($approving_user_id, 'EXPENSE_CLAIM');
  if (empty($position_approval_details)) {
   echo "<br>No approval limit found";
   throw new Exception("No approval limit found for user id " . $approving_user_id);
  }

  foreach ($position_approval_details as $obj) {
   if ($obj->limit_object == 'TOTAL_AMOUNT') {
    $amount_limit = $obj->amount_limit;
    if ($amount_limit >= $this->header_amount) {
     $exp_claim->status = 'APPROVED';
     $comment_msg = " Expense Claim is Approved By $approving_user_id ";
    } else {
     //create notification
     $exp_claim->status = 'INPROCESS';
     $comment_msg = " Approval request is submitted by user id $approving_user_id ";
    }
   }
  }
  if ($exp_claim->status == 'INPROCESS') {
   //create notification
   $notif = new sys_notification();
   $notif->notification_type = 'APPROVAL';
   $notif->notification_name = 'EXPENSE_CLAIM';
   $notif->from_user_id = $approving_user_id;
//    $employee_details = hr_employee_p::find_by_id($this->employee_id);
   $notif->from_user = $position_approval_details[0]->first_name . ' ' . $position_approval_details[0]->last_name;
   if (empty($position_approval_details[0]->supervisor_employee_id)) {
    $comment_msg = " No Supervisor found for $notif->from_user ";
    $this->write_comment($approving_user_id, $comment_msg);
    $exp_claim->status = 'APPR_HOLD';
    $exp_claim->save();
    return;
   }
   $supr_employee_details = hr_employee::find_by_id($position_approval_details[0]->supervisor_employee_id);
   $supr_user_details = ino_user::find_by_employeeId($position_approval_details[0]->supervisor_employee_id);
   $notif->to_user_id = $supr_user_details->user_id;
   $notif->to_user = $supr_employee_details->first_name . ' ' . $supr_employee_details->last_name;
   $notif->to_email = $supr_employee_details->email;
   $notif->reference_key_name = 'hr_expense_header';
   $notif->reference_key_value = $this->hr_expense_header_id;
   $notif->status = 'OPEN';
   $notif->start_date = current_time(true);
   $notif->notification_subject = "Expense Claim From " . $notif->from_user . ' Claim#' . $this->hr_expense_header_id;
   $notif->text_field1 = "<br>Name :  " . $notif->from_user;
   $notif->text_field1 = "<br>Purpose :  " . $this->purpose;
   $notif->text_field1 = "<br>Reason :  " . $this->reason;
   $notif->text_field1 .= "<br>Currency : $this->doc_currency &nbsp;&nbsp; Amount : $this->header_amount";
   $notif->text_field1 .= "<br>Claim Date : $this->claim_date (Employee Id : $this->hr_employee_id) ";
   $notif->text_field1 .= "<br>Contact Details : $this->contact_details ";
   $notif->save();
   $notif->_after_save();
  }
  $exp_claim->approved_by = $position_approval_details[0]->first_name . ' ' . $position_approval_details[0]->last_name;
  $exp_claim->approved_date = current_time();
  $exp_claim->update_changesOnly($exp_claim->hr_expense_header_id);
  $exp_claim->write_comment($approving_user_id, $comment_msg);
 }

 public function notification_action($obj) {
  $this->findBy_id($obj->reference_key_value);
  if ($obj->notification_action == 'APPROVE') {
   try {
    $this->_approve_by_amount_limit();
   } catch (Exception $e) {
    $this->rollback = true;
    echo "<br> Unable to complete the approval process " . $e->getMessage();
   }
  } else if ($obj->notification_action == 'REJECT') {
   $this->status = 'REJECTED';
   $this->approved_by = $obj->to_user;
   $this->approved_date = current_time();
   $this->update($this->hr_expense_header_id);
  }
 }

}

//end of hr_expense_header class
?>