<?php

class hr_payslip_line extends dbObject {

 public static $table_name = "hr_payslip_line";
 public static $primary_column = "hr_payslip_line_id";
 public static $parent_primary_column = "hr_payslip_header_id";
 public static $key_column = 'hr_compensation_element_id';
 public static $module = "hr";
 public $field_a = [
  'hr_payslip_line_id',
  'hr_payslip_header_id',
  'hr_compensation_element_id',
  'element_value',
  'period',
  'created_by',
  'creation_date',
  'last_update_by',
  'last_update_date',
 ];
 public $fields_inHeader_needsToBeInserted_inPOST = [
  "hr_payslip_header_id"
 ];
 public $requiredField = [
  'hr_payslip_header_id',
  'hr_compensation_element_id',
  'element_value',
 ];
 public $fields_inFormr_notinDataBase = [
  "monetary_value"
 ];
 public $hr_payslip_line_id;
 public $hr_payslip_header_id;
 public $hr_compensation_element_id;
 public $element_value;
 public $period;
 public $created_by;
 public $creation_date;
 public $last_update_by;
 public $last_update_date;

//  
}

//end of inv_transaction class
?>