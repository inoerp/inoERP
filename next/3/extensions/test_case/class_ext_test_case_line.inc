<?php

class ext_test_case_line extends dbObject {

 public static $table_name = "ext_test_case_line";
 public static $primary_column = "ext_test_case_line_id";
 public static $parent_primary_column = "ext_test_case_header_id";
 public static $key_column = 'step_action';
 public static $module = "ext";
 public $field_a = [
		 'ext_test_case_line_id',
		 'ext_test_case_header_id',
		 'line_number',
		 'step_action',
		 'input',
		 'expected_result',
		 'created_by',
		 'creation_date',
		 'last_update_by',
		 'last_update_date',
 ];
 //variables used for showing data


 public $fields_inHeader_needsToBeInserted_inPOST = [
		 "ext_test_case_header_id"
 ];
 public $requiredField = [
		 'ext_test_case_header_id',
		 'line_number',
		 'step_action'
 ];
 
 
 public $ext_test_case_line_id;
public $ext_test_case_header_id;
public $line_number;
public $step_action;
public $input;
public $expected_result;
public $created_by;
public $creation_date;
public $last_update_by;
public $last_update_date;

}

//end of ext_test_case_line class
?>