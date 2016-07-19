<?php

class bom_standard_operation_resource_assignment extends dbObject {

 public static $table_name = "bom_standard_operation_resource_assignment";
 public static $primary_column = "bom_standard_operation_resource_assignment_id";
 public static $parent_primary_column = "bom_standard_operation_id";
 public static $key_column = 'resource_sequence';
 public static $module = "bom";
//  data base variables as stored database column name
 public $field_a = [
		 'bom_standard_operation_resource_assignment_id',
		 'resource_sequence',
		 'bom_standard_operation_id',
		 'charge_basis',
		 'resource_id',
		 'resource_usage',
		 'resource_schedule',
		 'assigned_units',
		 'twenty_four_hr_cb',
		 'standard_rate_cb',
		 'charge_type',
		 'created_by',
		 'creation_date',
		 'last_update_by',
		 'last_update_date'
 ];
//variables used for showing data
 public $checkbox = [
		 'twenty_four_hr_cb',
		 'standard_rate_cb'
 ];
 public $requiredField = [
		 'bom_standard_operation_id',
		 'resource_sequence',
		 'resource_id'
 ];
 public $bom_standard_operation_id;
 public $cost_type_id;
 public $bom_standard_operation_resource_assignment_id;
 public $charge_basis;
 public $resource_id;
 public $resource_usage;
 public $resource_schedule;
 public $assigned_units;
 public $twenty_four_hr_cb;
 public $standard_rate_cb;
 public $charge_type;
 public $resource_sequence;
 public $created_by;
 public $creation_date;
 public $last_update_by;
 public $last_update_date;
 public $time;
 public $msg;

 public static function find_by_bom_standard_operationId($bom_standard_operationId) {
	global $db;
	$sql = "SELECT * FROM " .
					self::$table_name .
					" where bom_standard_operation_id= '{$bom_standard_operationId}' ";
	$result = self::find_by_sql($sql);
	return $result;
 }

}

//end of bom_standard_operation_resource_assignment class
?>