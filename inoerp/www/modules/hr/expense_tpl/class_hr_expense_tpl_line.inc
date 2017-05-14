<?php

class hr_expense_tpl_line extends dbObject {

 public static $table_name = "hr_expense_tpl_line";
 public static $primary_column = "hr_expense_tpl_line_id";
 public static $parent_primary_column = "hr_expense_tpl_header_id";
 public static $key_column = 'expense_item';
 public static $module = "hr";
 public $field_a = [
  'hr_expense_tpl_line_id',
  'hr_expense_tpl_header_id',
  'expense_item',
  'expense_category',
  'tax_code_id',
  'expense_ac_id',
  'inactive_date',
  'prj_expenditure_type_header_id',
  'policy_schedule_id',
  'created_by',
  'creation_date',
  'last_update_by',
  'last_update_date',
 ];
 public $initial_search = [
  'expense_item',
  'expense_category',
 ];
 public $requiredField = [
  'hr_expense_tpl_header_id',
  'expense_item',
  'expense_category',
 ];
 public $fields_inForm_notInDataBase = [
 ];
 public $fields_inHeader_needsToBeInserted_inPOST = [
  "hr_expense_tpl_header_id"
 ];
 public $hr_expense_tpl_line_id;
 public $hr_expense_tpl_header_id;
 public $expense_item;
 public $expense_category;
 public $tax_code_id;
 public $expense_ac_id;
 public $inactive_date;
 public $prj_expenditure_type_header_id;
 public $policy_schedule_id;
 public $created_by;
 public $creation_date;
 public $last_update_by;
 public $last_update_date;


}

//end of hr_expense_tpl_line class
?>