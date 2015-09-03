<?php

class hr_timesheet_line extends dbObject {

 public static $table_name = "hr_timesheet_line";
 public static $primary_column = "hr_timesheet_line_id";
 public static $parent_primary_column = "hr_timesheet_header_id";
 public static $key_column = 'timesheet_type';
 public static $module = "hr";
 public $field_a = [
  'hr_timesheet_line_id',
  'hr_timesheet_header_id',
  'work_date',
  'prj_project_header_id',
  'prj_project_line_id',
  'prj_work_type_id',
  'no_of_hrs',
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
  'claim_date',
  'receipt_amount',
//  'receipt_currency',
  'timesheet_type',
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
 public $work_date;
 public $prj_project_header_id;
 public $prj_project_line_id;
 public $prj_work_type_id;
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

 public function _before_save() {
  if (empty($this->hr_timesheet_line_id) && empty($this->status)) {
   $this->status = 'ENTERED';
  }
 }

 Public static function hr_timesheet_line_types() {
  $option_header = option_header::find_by_name('PO_LINE_TYPE');
  $po_types = option_line::find_by_option_id($option_header->option_header_id);
  return $po_types;
 }

}

//end of hr_timesheet_line class
?>