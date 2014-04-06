<?php

class bom_overhead_resource_assignment extends bom_overhead {

 protected static $table_name = "bom_overhead_resource_assignment";
 public static $primary_column = "bom_overhead_resource_assignment_id";
 public static $key_column = 'bom_overhead_id';
 public static $module = "bom";
//  data base variables as stored database column name
 public $field_a = [
		 'bom_overhead_resource_assignment_id',
		 'bom_overhead_id',
		 'cost_type_id',
		 'resource_id',
		 'created_by',
		 'creation_date',
		 'last_update_by',
		 'last_update_date'
 ];

 public $fields_inForm_notInDataBase = [
		 'cost_type_description',
		 'resource_description'
 ];

 public $requiredField= [
		 'bom_overhead_id',
		 'cost_type_id',
		 'resource_id'
 ];
 
 public $bom_overhead_id;
 public $cost_type_id;
 public $bom_overhead_resource_assignment_id;
 public $resource_id;
 public $cost_type_description;
 public $resource_description;
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

//end of bom_overhead_resource_assignment class
?>