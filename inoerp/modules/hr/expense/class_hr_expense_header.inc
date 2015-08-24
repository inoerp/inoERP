<?php

class hr_expense_header extends dbObject {

 public static $table_name = "hr_expense_header";
 public static $dependent_classes = ['hr_expense_line'];
 public static $primary_column = "hr_expense_header_id";
 public static $key_column = 'hr_employee_id';
 public static $module = "hr";
 public $field_a = [
  'hr_expense_header_id',
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
  'created_by',
  'creation_date',
  'last_update_by',
  'last_update_date',
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
//  'expense_template_id',
  'doc_currency',
 ];
 public $fields_inForm_notInDataBase = [
  'identification_id',
  "employee_name",
  'approved_by_employee_id'
 ];
 public $search = [
  '_show_update_path' => 1,
  '_show_view_path' => 1,
 ];
 public $pageTitle = " Employee Expense "; //page Title
 public $option_lists = [
  'approval_status' => 'APPROVAL_STATUS',
 ];
 public $hr_expense_header_id;
 public $hr_employee_id;
 public $claim_date;
 public $approved_date;
 public $approved_by;
 public $approved_by_employee_id;
 public $status;
 public $purpose;
 public $expense_template_id;
 public $doc_currency;
 public $department_id;
 public $reason;
 public $contact_details;
 public $created_by;
 public $creation_date;
 public $last_update_by;
 public $last_update_date;
 public $identification_id;
 public $employee_name;
 

 

 public function _before_save() {

 }


 Public static function so_status() {
  $option_header = option_header::find_by_name('hr_expense_STATUS');
  $so_status = option_line::find_by_option_id($option_header->option_header_id);
  return $so_status;
 }

}

//end of hr_expense_header class
?>