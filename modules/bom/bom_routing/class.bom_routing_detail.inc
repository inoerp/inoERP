<?php

class bom_routing_detail extends bom_routing_line {

 protected static $table_name = "bom_routing_detail";
 public static $field_array = [
		 'bom_routing_detail_id',
		 'bom_routing_line_id',
		 'bom_routing_header_id',
		 'resource_sequence',
		 'charge_basis',
		 'resource_id',
		 'usage',
		 'schedule',
		 'assigned_units',
		 'twenty_four_hr_cb',
		 'charge_type',
		 'standard_rate_cb',
		  'created_by',
		 'creation_date',
		 'last_update_by',
		 'last_update_date'
 ];
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
 public static $addressField_array = [
 ];
 public static $fields_inForm_notInDataBase = [
 ];
 public static $fields_inHeader_needsToBeInserted_inPOST = [
		 		 'bom_routing_line_id',
		 'bom_routing_header_id'
 ];
 public static $base_encoded_array = [];
 public static $requiredField_array = [
		 'bom_routing_line_id',
		 'bom_routing_header_id',
		 'resource_sequence',
		 'charge_basis',
		 'resource_id',
		 'usage'
 ];
 public static $otherField_array = [
 ];
 public static $primary_column = "bom_routing_detail_id";
 public $bom_routing_detail_id;
 public $bom_routing_line_id;
 public $bom_routing_header_id;
 public $resource_sequence;
 public $charge_basis;
 public $resource_id;
 public $usage;
 public $schedule;
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

 public function _after_save() {
	
 }

 public function _before_showing() {
	
 }

 public function _before_submit() {
	
 }
 
   public static function find_by_routing_lineId($routing_line_id) {
	$sql = "SELECT * FROM " . self::$table_name . " where bom_routing_line_id = '{$routing_line_id}'";
	$result_array = self::find_by_sql($sql);
	return $result_array;
 }

}

//end of bom_detail_line class
?>