<?php

class lms_department extends dbObject {

 public static $table_name = "lms_department";
 public static $primary_column = "lms_department_id";
 public static $dependent_classes = ['lms_dept_res_assignment'];
 public static $key_column = 'department';
 public static $module = "lms";
 public static $system_info = [
		 'name' => 'Departments',
		 'number' => '8310',
		 'description' => 'LMS Departments',
		 'version' => '0.1.1',
		 'db_version' => '1001',
		 'mod_version' => '1.1.1',
		 'dependent_class' => array('lms_dept_res_assignment'),
		 'primary_entity_cb' => '',
		 'module_name' => 'lms',
		 'weight' => 2
 ];
 //  data base variables as stored database column name
 public $field_a = [
		 'lms_department_id',
		 'department',
		 'description',
		 'org_id',
		 'status',
		 'location_id',
		 'department_type',
		 'default_basis',
		 'absorption_ac_id',
		 'resource_assignment_id',
		 'created_by',
		 'creation_date',
		 'last_update_by',
		 'last_update_date',
 ];
//variables used for showing data
 public $initial_search = [
		 'department',
		 'description',
		 'department_type',
 ];
 public $requiredField = [
		 'department',
		 'org_id',
		 'department_type'
 ];
 public $search = [
		 '_show_update_path' => 1,
		 '_update_action_meassge' => 'Update',
		 '_show_view_path' => 1,
 ];
 public $pageTitle = " LMS Departments"; //page Title
 public $option_list = [
		 'lms_department_type' => 'LMS_DEPARTMENT_TYPE',
 ]; //list of search fields which have options
 public $lms_department_id;
 public $department;
 public $description;
 public $org_id;
 public $status;
 public $location_id;
 public $department_type;
 public $default_basis;
 public $absorption_ac_id;
 public $resource_assignment_id;
 public $created_by;
 public $creation_date;
 public $last_update_by;
 public $last_update_date;
 public $time;
 public $msg;

 Public static function lms_department_type() {
	$option_header = option_header::find_by_exact_name('LMS_DEPARTMENT_TYPE');
	$resource_type = option_line::find_by_option_id($option_header->option_header_id);
	return $resource_type;
 }

}

//end of resource class
?>