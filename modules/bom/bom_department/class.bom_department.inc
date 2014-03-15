<?php

class bom_department extends dbObject {

 protected static $table_name = "bom_department";
 public static $primary_column = "bom_department_id";
 public static $key_column = 'department';
 public static $module = "bom";
//  data base variables as stored database column name
 public $field_a = [
		 'bom_department_id',
		 'department',
		 'description',
		 'org_id',
		 'status',
		 'department_type',
		 'location_id',
		 'resource_assignment_id',
		 'ef_id',
		 'created_by',
		 'creation_date',
		 'last_update_by',
		 'last_update_date'
 ];
//variables used for showing data
 public $initial_search = [
		 'bom_department_id',
		 'department',
		 'description',
		 'org_id',
		 'department_type',
		 'location_id'
 ];
 public $column = [
		 'bom_department_id',
		 'department',
		 'description',
		 'org_id',
		 'department_type',
		 'location_id'
 ];
 public $requiredField = [
		 'department',
		 'description',
		 'org_id'
 ];
 public $search = [
		 '_update_path' => 'modules/bom/bom_department/bom_department.php',
		 '_show_update_path' => 1,
		 '_update_action_meassge' => 'Update',
		 '_show_view_path' => 1,
 ];
 public $pageTitle = " BOM Departments - Find All Departments "; //page Title
 public $option_list = [
//		 'calendar_option_line_code' => 'GL_CALENDAR_NAME',
 ]; //list of search fields which have options
 public $bom_department_id;
 public $department;
 public $description;
 public $org_id;
 public $status;
 public $location_id;
 public $department_type;
 public $resource_assignment_id;
 public $ef_id;
 public $created_by;
 public $creation_date;
 public $last_update_by;
 public $last_update_date;
 public $time;
 public $msg;

 public function _before_showing() {
	
 }

 public function _before_submit() {
	
 }

}

//end of resource class
?>