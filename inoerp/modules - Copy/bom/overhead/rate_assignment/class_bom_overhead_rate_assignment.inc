<?php

class bom_overhead_rate_assignment extends dbObject {

 public static $table_name = "bom_overhead_rate_assignment";
 public static $primary_column = "bom_overhead_rate_assignment_id";
 public static $key_column = 'bom_overhead_id';
 public static $module = "bom";
//  data base variables as stored database column name
 public $field_a = [
		 'bom_overhead_rate_assignment_id',
		 'bom_overhead_id',
		 'bom_cost_type',
		 'default_basis',
		 'rate',
		 'created_by',
		 'creation_date',
		 'last_update_by',
		 'last_update_date'
 ];
 public $fields_inForm_notInDataBase = [
		 'cost_type_description',
		 'resource_description'
 ];
 public $requiredField = [
		 'bom_overhead_id',
		 'bom_cost_type',
		 'rate'
 ];
 public $bom_overhead_id;
 public $bom_cost_type;
 public $bom_overhead_rate_assignment_id;
 public $rate;
 public $default_basis;
 public $created_by;
 public $creation_date;
 public $last_update_by;
 public $last_update_date;
 public $time;
 public $msg;

 public static function find_by_bom_overheadId($bom_overheadId) {
	global $db;
	$sql = "SELECT * FROM " .
					self::$table_name .
					" where bom_overhead_id= '{$bom_overheadId}' ";
	$result = self::find_by_sql($sql);
	return $result;
 }

}

//end of bom_overhead_rate_assignment class
?>