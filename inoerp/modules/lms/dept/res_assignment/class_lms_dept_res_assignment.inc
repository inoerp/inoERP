<?php

class lms_dept_res_assignment extends dbObject {

 public static $table_name = "lms_dept_res_assignment";
 public static $primary_column = "lms_dept_res_assignment_id";
 public static $parent_primary_column = "lms_department_id";
 public static $key_column = 'resource_id';
 public static $module = "bom";
//  data base variables as stored database column name
 public $field_a = [
		 'lms_stnd_op_res_assignment_id',
		 'resource_sequence',
		 'lms_standard_operation_id',
		 'charge_basis',
		 'resource_id',
		 'resource_usage',
		 'resource_schedule_cb',
		 'assigned_units',
		 'twenty_four_hr_cb',
		 'standard_rate_cb',
		 'charge_type',
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
		 'cost_type_id',
		 'resource_id'
 ];
 public $lms_department_id;
 public $cost_type_id;
 public $lms_dept_res_assignment_id;
 public $resource_id;
 public $cost_type_description;
 public $resource_description;
 public $no_of_units;
 public $efficiency;
 public $utilization;
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