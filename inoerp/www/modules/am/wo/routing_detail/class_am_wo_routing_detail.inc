<?php

class am_wo_routing_detail extends dbObject {

 public static $table_name = "am_wo_routing_detail";
 public static $primary_column = "am_wo_routing_detail_id";
 public static $key_column = 'resource_sequence';
 public static $module = "am";
 public $field_a = [
  'am_wo_routing_detail_id',
  'am_wo_routing_line_id',
  'am_wo_header_id',
  'resource_sequence',
  'charge_basis',
  'resource_id',
  'resource_usage',
  'resource_schedule',
  'assigned_units',
  'required_quantity',
  'applied_quantity',
  'charge_type',
  'standard_rate_cb',
  'created_by',
  'creation_date',
  'last_update_by',
  'last_update_date',
 ];
 public $checkbox = [
  'twenty_four_hr_cb',
  'standard_rate_cb'
 ];
 public $fields_inHeader_needsToBeInserted_inPOST = [
  'am_wo_header_id',
  'am_wo_routing_line_id'
 ];
 public $requiredField = [
  'am_wo_header_id',
  'resource_sequence',
  'am_wo_routing_line_id',
  'resource_sequence',
  'charge_basis',
  'resource_id'
 ];
 
 public $am_wo_routing_detail_id;
 public $am_wo_routing_line_id;
 public $am_wo_header_id;
 public $resource_sequence;
 public $charge_basis;
 public $resource_id;
 public $resource_usage;
 public $resource_schedule;
 public $assigned_units;
 public $required_quantity;
 public $applied_quantity;
 public $charge_type;
 public $standard_rate_cb;
 public $created_by;
 public $creation_date;
 public $last_update_by;
 public $last_update_date;
 public $msg;
 public $open_quantity;
 public $routing_sequence;
 public $department_id;

 public function __set($name, $value) {
  $this->$name = $value;
 }

 public static function find_by_wipWo_lineId($am_wo_routing_line_id) {
  $sql = "SELECT * FROM " . self::$table_name . " where am_wo_routing_line_id = '{$am_wo_routing_line_id}'";
  $result_array = self::find_by_sql($sql);
  return $result_array;
 }

}

//end of bom_detail_line class
?>