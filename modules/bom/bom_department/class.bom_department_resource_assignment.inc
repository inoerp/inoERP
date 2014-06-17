<?php

class bom_department_resource_assignment extends dbObject {

 public static $table_name = "bom_department_resource_assignment";
 public static $primary_column = "bom_department_resource_assignment_id";
 public static $parent_primary_column = "bom_department_id";
 public static $key_column = 'resource_id';
 public static $module = "bom";
//  data base variables as stored database column name
 public $field_a = [
		 'bom_department_resource_assignment_id',
		 'bom_department_id',
		 'cost_type_id',
		 'resource_id',
		 'no_of_units',
		 'efficiency',
		 'utilization',
		 'created_by',
		 'creation_date',
		 'last_update_by',
		 'last_update_date'
 ];
//variables used for showing data
 public $fields_inForm_notInDataBase = [
		 'cost_type_description',
		 'resource_description'
 ];
 public $requiredField = [
		 'bom_department_id',
		 'cost_type_id',
		 'resource_id'
 ];
 public $bom_department_id;
 public $cost_type_id;
 public $bom_department_resource_assignment_id;
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
	if (!empty($this->bom_department_resource_assignment_id)) {
//	 $item = item::find_by_id($this->common_bom_item_id);
	 $this->cost_type_description = null;
	 $this->resource_description = null;
	} else {
	 $this->cost_type_description = null;
	 $this->resource_description = null;
	}
 }

 public static function find_by_bom_departmentId($bom_departmentId) {
	global $db;
	$sql = "SELECT * FROM " .
					self::$table_name .
					" where bom_department_id= '{$bom_departmentId}' ";
	$result = self::find_by_sql($sql);
	return $result;
 }

}

//end of bom_department_resource_assignment class
?>