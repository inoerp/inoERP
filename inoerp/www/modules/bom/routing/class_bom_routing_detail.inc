<?php

class bom_routing_detail extends dbObject {
 public static $table_name = "bom_routing_detail";
 public static $primary_column = "bom_routing_detail_id";
 public static $parent_primary_column = "bom_routing_line_id";
 public static $key_column = 'resource_sequence';
 public static $module = "bom";
 
 public $field_a = [
		 'bom_routing_detail_id',
		 'bom_routing_line_id',
		 'bom_routing_header_id',
		 'resource_sequence',
		 'charge_basis',
		 'resource_id',
		 'resource_usage',
		 'resource_schedule',
		 'assigned_units',
		 'twenty_four_hr_cb',
		 'charge_type',
		 'standard_rate_cb',
		 'created_by',
		 'creation_date',
		 'last_update_by',
		 'last_update_date'
 ];

 public $checkbox = [
		 'twenty_four_hr_cb',
		 'standard_rate_cb'
 ];
 
 
 public $fields_inHeader_needsToBeInserted_inPOST = [
		 'bom_routing_line_id',
		 'bom_routing_header_id'
 ];
 
 public $requiredField = [
		 'bom_routing_line_id',
		 'bom_routing_header_id',
		 'resource_sequence',
		 'charge_basis',
		 'resource_id',
		 'resource_usage'
 ];

 public $bom_routing_detail_id;
 public $bom_routing_line_id;
 public $bom_routing_header_id;
 public $resource_sequence;
 public $charge_basis;
 public $resource_id;
 public $resource_usage;
 public $resource_schedule;
 public $assigned_units;
 public $twenty_four_hr_cb;
 public $charge_type;
 public $standard_rate_cb;
 public $created_by;
 public $creation_date;
 public $last_update_by;
 public $last_update_date;
 public $time;
 public $msg;

 public function __set($name, $value) {
	$this->$name = $value;
 }


 public static function find_by_routing_lineId($routing_line_id) {
	$sql = "SELECT * FROM " . self::$table_name . " where bom_routing_line_id = '{$routing_line_id}'";
	
	$result_array = self::find_by_sql($sql);
	return $result_array;
 }

}

//end of bom_detail_line class
?>