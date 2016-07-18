<?php

class hd_service_contract_detail extends dbObject {

 public static $table_name = "hd_service_contract_detail";
 public static $primary_column = "hd_service_contract_detail_id";
 public static $parent_primary_column = "hd_service_contract_line_id";
 public static $key_column = 'item_id_m';
 public static $module = "hd";
 public $account = [
  'detail_ac_id'
 ];
 public static $level_a = [
  'ITEM' => 'Item',
  'CUSTOMER' => 'Customer'
 ];
 public $field_a = [
  'hd_service_contract_detail_id',
  'hd_service_contract_line_id',
  'item_id_m',
  'inv_serial_number_id',
  'detail_number',
  'ar_customer_id',
  'unit_price',
  'level',
  'line_ref',
  'renewal_type',
  'status',
  'reference_type',
  'reference_key_name',
  'reference_key_value',
  'description',
  'quantity',
  'uom_id',
  'line_amount',
  'start_date',
  'end_date',
  'duration_uom_id',
  'duration',
  'tax_amount',
  'created_by',
  'creation_date',
  'last_update_by',
  'last_update_date',
 ];
 public $requiredField = [
  'hd_service_contract_line_id',
  'item_id_m',
 ];
 public $dateField = [
  'start_date',
  'end_date',
 ];
 public $fields_inForm_notInDataBase = [
  "item_number",
  'serial_number'
 ];
 public $fields_inHeader_needsToBeInserted_inPOST = [
  'hd_service_contract_line_id'
 ];
 public $numberField = [
  'amount',
  'gl_amount'
 ];
 public $hd_service_contract_detail_id;
 public $hd_service_contract_line_id;
 public $item_id_m;
 public $inv_serial_number_id;
 public $detail_number;
 public $ar_customer_id;
 public $unit_price;
 public $level;
 public $line_ref;
 public $renewal_type;
 public $status;
 public $reference_type;
 public $reference_key_name;
 public $reference_key_value;
 public $description;
 public $quantity;
 public $uom_id;
 public $line_amount;
 public $start_date;
 public $end_date;
 public $duration_uom_id;
 public $duration;
 public $tax_amount;
 public $created_by;
 public $creation_date;
 public $last_update_by;
 public $last_update_date;
 public $time;
 public $msg;
 public $item_number;
 public $serial_number;

 private function _validate_delete() {
  if ($this->journal_created_cb == 1) {
   echo "<br>Delete is not allowed as the journal lines have been created! "
   . "<br> Create credit memo if required";
   return -99;
  } else {
   return 1;
  }
 }

 public function _before_delete() {
  return $this->_validate_delete();
 }

 public function _before_save() {
//	if (!empty($this->hd_service_contract_detail_id) && ($this->journal_created_cb == 1)) {
//	 echo "<br>Update is not allowed as the journal lines have been created! "
//	 . "<br> Create credit memo if required";
//	 return -99;
//	}
 }

 public static function find_by_hd_service_contract_lineId($hd_service_contract_line_id) {
  $sql = "SELECT * FROM " . self::$table_name . " where hd_service_contract_line_id = '{$hd_service_contract_line_id}'";
  $result_array = self::find_by_sql($sql);
  return !empty($result_array) ? $result_array : false;
 }

 public function _after_save() {
  
 }

 public static function update_poDetail_status($hd_service_contract_detail_id, $received_quantity = "", $accepted_quantity = "", $delivered_quantity = "", $invoiced_quantity = "", $paid_quantity = "") {
  global $error;
  global $db;
  //first get the existing recevived quantity
  $hd_service_contract_details = self::find_by_id($hd_service_contract_detail_id);
  $received_quantity_begining = $hd_service_contract_details->received_quantity;
  $quantity = $hd_service_contract_details->quantity;

  if ((!empty($hd_service_contract_detail_id)) && ($quantity - ($received_quantity_begining + $received_quantity) >= 0 )) {
   $received_quantity += $received_quantity_begining;
   $sql = " UPDATE ";
   $sql .= self::$table_name;
   $sql .= " SET received_quantity = '{$received_quantity}' , ";
   $sql .= " accepted_quantity = '{$accepted_quantity}'  , ";
   $sql .= " delivered_quantity = '{$delivered_quantity}'  , ";
   $sql .= " invoiced_quantity = '{$invoiced_quantity}'  , ";
   $sql .= " paid_quantity = '{$paid_quantity}'   ";
   $sql .= " WHERE hd_service_contract_detail_id = '{$hd_service_contract_detail_id}' ";
  } else {
   $error['Received_Quantity'] = 'Received Quantity is Less than available Open Quantity';
   $msg = 9;
  }
  if (!empty($sql)) {
   if ($db->query($sql)) {
    $msg = 1;
   } else {
    $error['PO_DETAIL_STATUS_DB_UPDATE'] = 'PO Detail Status Data base update Failed';
    $msg = 0;
   }
  }
  ino_print_error();
  return $msg;
  //message 7 - number of open quantity is less than received quantity
 }

}

//end of hd_service_contract_detail class
?>