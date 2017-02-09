<?php

class lms_dept_res_assignment extends dbObject {

 public static $table_name = "lms_dept_res_assignment";
 public static $primary_column = "lms_dept_res_assignment_id";
 public static $parent_primary_column = "lms_department_id";
 public static $key_column = 'lms_resource_id';
 public static $module = "lms";
//  data base variables as stored database column name
 public $field_a = [
		 'lms_dept_res_assignment_id',
		 'lms_department_id',
		 'description',
		 'lms_resource_id',
		 'status',
		 'cost_type',
		 'efficiency',
		 'utilization',
		 'no_of_units',
		 'resource_assignment_id',
		 'created_by',
		 'creation_date',
		 'last_update_by',
		 'last_update_date',
 ];
//variables used for showing data
 public $fields_inForm_notInDataBase = [
		 'cost_type_description',
		 'resource_description'
 ];
 public $requiredField = [
		 'lms_department_id',
		 'lms_resource_id',
 ];
 public $lms_dept_res_assignment_id;
 public $lms_department_id;
 public $description;
 public $lms_resource_id;
 public $status;
 public $cost_type;
 public $efficiency;
 public $utilization;
 public $no_of_units;
 public $resource_assignment_id;
 public $created_by;
 public $creation_date;
 public $last_update_by;
 public $last_update_date;
 public $time;
 public $msg;

 public function _before_showing() {
	if (!empty($this->lms_dept_res_assignment_id)) {
//	 $item = item::find_by_id($this->common_lms_item_id);
	 $this->cost_type_description = null;
	 $this->resource_description = null;
	} else {
	 $this->cost_type_description = null;
	 $this->resource_description = null;
	}
 }

 public static function find_by_lms_departmentId($lms_departmentId) {
	global $db;
	$sql = "SELECT * FROM " .
					self::$table_name .
					" where lms_department_id= '{$lms_departmentId}' ";
	$result = self::find_by_sql($sql);
	return $result;
 }

}

//end of lms_dept_res_assignment class
?>