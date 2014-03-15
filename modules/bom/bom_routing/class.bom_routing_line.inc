<?php

class bom_routing_line extends bom_routing_header {

 protected static $table_name = "bom_routing_line";
 public static $field_array = [
		 'bom_routing_line_id',
		 'bom_routing_header_id',
		 'routing_sequence',
		 'standard_operation_id',
		 'department_id',
		 'description',
		 'count_point_cb',
		 'auto_charge_cb',
		 'backflush_cb',
		 'minimum_transfer_quantity',
		 'lead_time_percentage',
		 'effective_start_date',
		 'effective_end_date',
		 'eco_number',
		 'eco_implemented_cb',
		 'include_in_rollup_cb',
		 'referenced_cb',
		 'yield',
		 'cumm_yield',
		 'ef_id',
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
		 "count_point_cb",
		 'backflush_cb',
		 'auto_charge_cb',
		 'referenced_cb',
		 'include_in_rollup_cb'
 ];
 public static $addressField_array = [
 ];
 public static $fields_inForm_notInDataBase = [
 ];
 public static $fields_inHeader_needsToBeInserted_inPOST = [
 ];
 public static $base_encoded_array = [];
 public static $requiredField_array = [
		 'bom_routing_header_id',
		 'routing_sequence',
		 'department_id'
 ];
 public static $otherField_array = [
 ];
 public static $primary_column = "bom_routing_line_id";
 public $bom_routing_line_id;
 public $bom_routing_header_id;
 public $routing_sequence;
 public $standard_operation_id;
 public $department_id;
 public $description;
 public $lead_time_percentage;
 public $count_point_cb;
 public $auto_charge_cb;
 public $effective_start_date;
 public $effective_end_date;
 public $eco_number;
 public $eco_implemented_cb;
 public $backflush_cb;
 public $yield;
 public $include_in_rollup_cb;
 public $minimum_transfer_quantity;
 public $referenced_cb;
 public $cumm_yield;
 public $ef_id;
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

 public static function find_by_routing_headerId($routing_header_id) {
	$sql = "SELECT * FROM " . self::$table_name . " where bom_routing_header_id = '{$routing_header_id}'";
	$result_array = self::find_by_sql($sql);
	return $result_array;
 }

 public static function find_by_itemId($item_id) {
	$routingHeaderOfItem = bom_routing_header::find_by_itemId($item_id);
	$bom_routing_header_id = $routingHeaderOfItem[0]->bom_routing_header_id;
	$routing_line_details = self::find_by_routing_headerId($bom_routing_header_id);
	return $routing_line_details;
 }

}

//end of bom_routing_line class
?>