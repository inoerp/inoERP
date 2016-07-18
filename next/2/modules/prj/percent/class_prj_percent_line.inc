<?php

class prj_percent_line extends dbObject {

 public static $table_name = "prj_percent_line";
 public static $primary_column = "prj_percent_line_id";
 public static $parent_primary_column = "prj_percent_header_id";
 public static $multi_search_primary_column = "prj_percent_header_id"; //this value is used in multi search hidden value
 public static $key_column = 'prj_project_line_id';
 public static $module = "prj";
 public $field_a = [
  'prj_percent_line_id',
  'prj_percent_header_id',
  'prj_project_header_id',
 'prj_project_line_id',
  'percent',
  'comment',
  'as_of_date',
  'created_by',
  'creation_date',
  'last_update_by',
  'last_update_date',
 ];
 public $requiredField = [
  'prj_percent_header_id',
  'prj_project_header_id',
 ];
 public $fields_inHeader_needsToBeInserted_inPOST = [
  "prj_percent_header_id"
 ];
 
  public $fields_inForm_notInDataBase = [
  'task_number',
   'task_description'
 ];
 
 public $prj_percent_line_id;
 public $prj_percent_header_id;
 public $prj_project_header_id;
 public $description;
 public $prj_project_line_id;
 public $percent;
 public $comment;
 public $as_of_date;
 public $created_by;
 public $creation_date;
 public $last_update_by;
 public $last_update_date;
 public $task_number;
 public $task_description;

}

//end of prj_percent_line class
?>