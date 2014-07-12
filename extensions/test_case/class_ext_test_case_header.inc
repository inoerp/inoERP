<?php

class ext_test_case_header extends dbObject {

 public static $table_name = "ext_test_case_header";
 public static $dependent_classes = ['ext_test_case_line'];
 public static $primary_column = "ext_test_case_header_id";
 public static $key_column = 'module_name';
 public static $module = "ext";
 Public $field_a = [
		 'ext_test_case_header_id',
		 'module_name',
		 'name',
		 'description',
		 'created_by',
		 'creation_date',
		 'last_update_by',
		 'last_update_date',
 ];
//variables used for showing data

 public $initial_search = [
		 'module_name',
		 'name',
 ];
 public $column = [
		 'ext_test_case_header_id',
		 'module_name',
		 'name',
		 'description',
 ];
 public $requiredField = [
		 'module_name',
		 'name',
 ];
 public $search = [
		 '_show_view_path' => 1,
		 '_show_update_path' => 1,
 ];
 public $pageTitle = " Test Case "; //page Title
 public $ext_test_case_header_id;
 public $module_name;
 public $name;
 public $description;
 public $created_by;
 public $creation_date;
 public $last_update_by;
 public $last_update_date;

}

?>