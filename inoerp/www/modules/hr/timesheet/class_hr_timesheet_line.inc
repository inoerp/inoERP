<?php

class hr_timesheet_line extends dbObject {

 public static $table_name = "hr_timesheet_line";
 public static $primary_column = "hr_timesheet_line_id";
 public static $parent_primary_column = "hr_timesheet_header_id";
 public static $key_column = 'prj_project_header_id';
 public static $module = "hr";
 public $field_a = [
  'hr_timesheet_line_id',
  'hr_timesheet_header_id',
  'prj_project_header_id',
  'prj_project_line_id',
  'prj_work_type_id',
  'day1',
  'day2',
  'day3',
  'day4',
  'day5',
  'day6',
  'day7',
  'status',
  'purpose',
  'description',
  'created_by',
  'creation_date',
  'last_update_by',
  'last_update_date',
 ];
 public $initial_search = [
  'hr_timesheet_header_id',
  'claim_date',
  'receipt_amount'
 ];
 public $requiredField = [
  'hr_timesheet_header_id',
  'prj_project_header_id',
 ];
 public $fields_inForm_notInDataBase = [
  'project_number',
  "task_number",
 ];
 public $fields_inHeader_needsToBeInserted_inPOST = [
  "hr_timesheet_header_id"
 ];
 public $hr_timesheet_line_id;
 public $hr_timesheet_header_id;
 public $prj_project_header_id;
 public $prj_project_line_id;
 public $prj_work_type_id;
 public $day1;
 public $day2;
 public $day3;
 public $day4;
 public $day5;
 public $day6;
 public $day7;
 public $status;
 public $purpose;
 public $no_of_hrs;
 public $description;
 public $created_by;
 public $creation_date;
 public $last_update_by;
 public $last_update_date;
 public $project_number;
 public $task_number;

// public function _before_save() {
////  pa($_POST);
//  pa($this);
////  return 10;
// }



}

//end of hr_timesheet_line class
?>