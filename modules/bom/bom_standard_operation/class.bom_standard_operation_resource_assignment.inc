<?php

class bom_standard_operation_resource_assignment extends bom_standard_operation {

 protected static $table_name = "bom_standard_operation_resource_assignment";
//  data base variables as stored database column name
 public static $field_array = [
		 'bom_standard_operation_resource_assignment_id',
		 'bom_standard_operation_id',
		 'resource_sequence',
		 'charge_basis',
		 'resource_id',
		 'usage',
		 'schedule',
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
 public static $initial_search_array = [

 ];
 public static $column_array = [

 ];
 public static $account_array = [
 ];
 public static $checkbox_array = [
		 'twenty_four_hr_cb',
		 'standard_rate_cb'
 ];
 public static $fields_inForm_notInDataBase = [
 ];
 public static $fields_inHeader_needsToBeInserted_inPOST = [
 ];
 public static $base_encoded_array = [];
 public static $requiredField_array = [
		 'bom_standard_operation_id',
		 'resource_sequence',
		 'resource_id'
 ];
 public static $primary_column = "bom_standard_operation_resource_assignment_id";
 public $bom_standard_operation_id;
 public $cost_type_id;
 public $bom_standard_operation_resource_assignment_id;
 public $charge_basis;
 public $resource_id;
 public $usage;
 public $schedule;
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



