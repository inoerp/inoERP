<?php

class hr_expense_tpl_header extends dbObject {

 public static $table_name = "hr_expense_tpl_header";
 public static $dependent_classes = ['hr_expense_tpl_line'];
 public static $primary_column = "hr_expense_tpl_header_id";
 public static $key_column = 'template_name';
 public static $module = "hr";
 public $field_a = [
  'hr_expense_tpl_header_id',
  'bu_org_id',
  'inactive_date',
  'template_name',
  'description',
  'created_by',
  'creation_date',
  'last_update_by',
  'last_update_date',
 ];
 
 
 public $initial_search = [
  'template_name',
  'description',
  'bu_org_id',
 ];
 public $requiredField = [
  'template_name',
  'bu_org_id',
 ];
 public $profile_default = [
  'bu_org_id' => 'org_bu_name_default',
 ];
 public $search = [
  '_show_update_path' => 1,
  '_show_view_path' => 1,
 ];
 public $pageTitle = " Expense Template "; //page Title
 public $option_lists = [
  'approval_status' => 'APPROVAL_STATUS',
 ];
 public $hr_expense_tpl_header_id;
 public $bu_org_id;
 public $inactive_date;
 public $template_name;
 public $description;
 public $created_by;
 public $creation_date;
 public $last_update_by;
 public $last_update_date;
 public $identification_id;
 public $employee_name;
 

 public function _before_save() {
  
 }

}

//end of hr_expense_tpl_header class
?>