<?php

class po_shipment extends po_line {

 protected static $table_name = "po_shipment";
 public static $account_array = [
 ];
 public static $checkbox_array = [
		 "rev_enabled_cb"
 ];
 public static $field_array = [
		 'po_shipment_id',
		 'po_line_id',
		 'po_header_id',
		 'shipment_number',
		 'sub_inventory_id',
		 'locator_id',
		 'requestor',
		 'ship_to_location',
		 'quantity',
		 'need_by_date',
		 'promise_date',
		 'charge_ac_id',
		 'accrual_ac_id',
		 'receving_ac_id',
		 'ppv_ac_id',
		 "ef_id",
		 "created_by",
		 "creation_date",
		 "last_update_by",
		 "last_update_date"
 ];
 public static $initial_search_array = [
 ];
 public static $column_array = [
 ];
 public static $requiredField_array = [
		 'po_line_id',
		 'po_header_id',
		 'shipment_number',
		 'charge_ac_id',
		 'accrual_ac_id',
		 'receving_ac_id',
		 'ppv_ac_id',
 ];
 public static $addressField_array = [
 ];
 public static $fields_inForm_notInDataBase = [
		 "po_number"
 ];
 public static $fields_inHeader_needsToBeInserted_inPOST = [
 ];
 public static $otherField_array = [
 ];
 public static $primary_column = "po_shipment_id";
 
 public $po_shipment_id;
 public $po_line_id;
 public $po_header_id;
 public $shipment_number;
 public $sub_inventory_id;
 public $locator_id;
 public $requestor;
 public $ship_to_location;
 public $quantity;
 public $need_by_date;
 public $promise_date;
 public $charge_ac_id;
 public $accrual_ac_id;
 public $receving_ac_id;
 public $ppv_ac_id;
 public $created_by;
 public $creation_date;
 public $last_update_by;
 public $last_update_date;
 public $time;
 public $msg;
 
   public static function find_by_po_lineId($po_line_id) {
	$sql = "SELECT * FROM " . self::$table_name . " where po_line_id = '{$po_line_id}'";
	$result_array = self::find_by_sql($sql);
	return $result_array;
 }

}

//end of po_shipment class
?>