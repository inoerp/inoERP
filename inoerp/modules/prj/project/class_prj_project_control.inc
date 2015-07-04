<?php

class prj_project_control extends dbObject {

 public static $table_name = "prj_project_control";
 public static $primary_column = "prj_project_control_id";
 public static $parent_primary_column = "prj_project_header_id";
 public static $key_column = 'description';
 public static $module = "hd";
 public static $source_a = [
  'ESTIMATES' => 'Estimates',
  'WORK_ORDER' => 'Work Order',
 ];
//  data base variables as stored database column name
 public $field_a = [
  'prj_project_control_id',
  'prj_project_header_id',
  'prj_expenditure_type_id',
  'prj_expenditure_category_code',
  'description',
  'start_date',
  'end_date',
  'prj_nlr_header_id',
  'hr_employee_id',
  'hr_job_id',
  'billable_cb',
  'chargeable_cb',
  'created_by',
  'creation_date',
  'last_update_by',
  'last_update_date',
 ];
//variables used for showing data
 public $fields_inForm_notInDataBase = [
 ];
 public $fields_inHeader_needsToBeInserted_inPOST = [
  'prj_project_header_id'
 ];
 public $requiredField = [
  'prj_project_header_id',
 ];
 public $prj_project_control_id;
 public $prj_project_header_id;
 public $prj_expenditure_type_id;
 public $prj_expenditure_category_code;
 public $description;
 public $start_date;
 public $end_date;
 public $prj_nlr_header_id;
 public $hr_employee_id;
 public $hr_job_id;
 public $billable_cb;
 public $chargeable_cb;
 public $created_by;
 public $creation_date;
 public $last_update_by;
 public $last_update_date;


 public static function find_by_wip_wo_headerId($wi_wo_header_id) {
  global $db;
  $sql = "SELECT * FROM " .
   self::$table_name .
   " where wip_wo_header_id= '{$wi_wo_header_id}' ";
  $result = self::find_by_sql($sql);
  return $result;
 }

}

//end of prj_project_control class
?>