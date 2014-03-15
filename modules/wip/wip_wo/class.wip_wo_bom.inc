<?php

class wip_wo_bom extends dbObject {

 protected static $table_name = "wip_wo_bom";
//  data base variables as stored database column name
 public static $field_array = [
		 'wip_wo_bom_id',
		 'wip_wo_header_id',
		 'bom_sequence',
		 'routing_sequence',
		 'component_item_id',
		 'usage_basis',
		 'usage_quantity',
		 'yield',
		 'wip_supply_type',
		 'supply_sub_inventory',
		 'supply_locator',
		 'required_quantity',
		 'issued_quantity',
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
 ];
 public static $fields_inForm_notInDataBase = [
		 "component_item_number",
		 "component_description",
		 "component_uom",
		 'open_quantity'
 ];
 public static $fields_inHeader_needsToBeInserted_inPOST = [
		  'wip_wo_header_id'
 ];
 public static $base_encoded_array = [];
 public static $requiredField_array = [
		 'wip_wo_header_id',
		 'bom_sequence',
		 'routing_sequence',
		 'component_item_id',
		 'usage_basis',
		 'usage_quantity'
 ];
 public static $primary_column = "wip_wo_bom_id";
 public $wip_wo_bom_id;
 public $wip_wo_header_id;
 public $bom_sequence;
 public $routing_sequence;
 public $component_item_id;
 public $usage_basis;
 public $usage_quantity;
 public $yield;
 public $required_quantity;
 public $issued_quantity;
 public $wip_supply_type;
 public $supply_sub_inventory;
 public $supply_locator;
 public $created_by;
 public $creation_date;
 public $last_update_by;
 public $last_update_date;
 public $time;
 public $msg;
 public $component_item_number;
 public $component_description;
 public $component_uom;
 public $open_quantity;

 public static function find_by_wip_wo_headerId($wi_wo_header_id) {
	global $db;
	$sql = "SELECT * FROM " .
					self::$table_name .
					" where wip_wo_header_id= '{$wi_wo_header_id}' ";
	$result = self::find_by_sql($sql);
	return $result;
 }
 
  public static function find_by_wipWoHeaderId_and_routingSequence($wip_wo_header_id, $routing_sequence) {
	global $db;
	$sql = "SELECT * FROM " .
					self::$table_name .
					" where wip_wo_header_id= '{$wip_wo_header_id}' 
					 AND routing_sequence= '{$routing_sequence}' ";
	$result = self::find_by_sql($sql);
	return $result;
 }

}

//end of wip_wo_bom class
?>



