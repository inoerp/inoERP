<?php

class wip_wo_routing_detail extends dbObject {

 protected static $table_name = "wip_wo_routing_detail";
 public static $field_array = [
		 'wip_wo_routing_detail_id',
		 'wip_wo_header_id',
		 'wip_wo_routing_line_id',
		 'resource_sequence',
		 'charge_basis',
		 'resource_id',
		 'usage',
		 'schedule',
		 'assigned_units',
		 'charge_type',
		 'standard_rate_cb',
		 'required_quantity',
		 'applied_quantity',
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
		 'wip_wo_header_id',
		 'wip_wo_routing_line_id'
 ];
 public static $base_encoded_array = [];
 public static $requiredField_array = [
		 'wip_wo_header_id',
		 'wip_wo_routing_line_id',
		 'resource_sequence',
		 'charge_basis',
		 'resource_id'
 ];
 public static $otherField_array = [
 ];
 public static $primary_column = "wip_wo_routing_detail_id";
 public $wip_wo_routing_detail_id;
 public $wip_wo_routing_line_id;
 public $wip_wo_header_id;
 public $resource_sequence;
 public $charge_basis;
 public $resource_id;
 public $usage;
 public $schedule;
 public $assigned_units;
 public $twenty_four_hr_cb;
 public $charge_type;
 public $standard_rate_cb;
 public $required_quantity;
 public $applied_quantity;
 public $created_by;
 public $creation_date;
 public $last_update_by;
 public $last_update_date;
 public $time;
 public $msg;
 public $open_quantity;
  public $routing_sequence;
	 public $department_id;

 public function __set($name, $value) {
	$this->$name = $value;
 }

 public function _after_save() {
	
 }

 public function _before_showing() {
	
 }

 public function _before_submit() {
	
 }

 public static function find_by_wipWo_lineId($wip_wo_routing_line_id) {
	$sql = "SELECT * FROM " . self::$table_name . " where wip_wo_routing_line_id = '{$wip_wo_routing_line_id}'";
	$result_array = self::find_by_sql($sql);
	return $result_array;
 }

}

//end of bom_detail_line class
?>



