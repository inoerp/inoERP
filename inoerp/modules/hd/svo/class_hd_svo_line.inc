<?php

class hd_svo_line extends dbObject {

 public static $table_name = "hd_svo_line";
 public static $primary_column = "hd_svo_line_id";
 public static $parent_primary_column = "hd_svo_header_id";
 public static $key_column = 'item_id_m';
 public static $module = "sd";
 public static $action_a = [
  "PROCESS" => 'Process Order',
  "BOOK" => 'Book Order',
  "CANCEL" => 'Cancel Order',
 ];
 public $line_status_a = [
  'ENTERED' => 'Entered',
  'AWAITING_PICKING' => 'Awaiting Picking',
  'PICKED' => 'Picked',
  'PARTIAL_PICKED' => 'Partially Picked',
  'SHIPPED' => 'Shipped',
  'PARTIAL_SHIPPED' => 'Partial Shipped',
  'CLOSED' => 'Closed',
 ];
 public $field_a = [
  'hd_svo_line_id',
  'hd_svo_header_id',
  'line_number',
  'inv_org_id',
  'sd_so_header_id',
  'sd_so_line_id',
  'item_id_m',
  'quantity',
  'action_type_id',
  'status',
  'price_list_header_id',
  'price_date',
  'unit_price',
  'line_price',
  'line_status',
  'requested_date',
  'promise_date',
  'schedule_ship_date',
  'reference_doc_type',
  'reference_doc_number',
  'service_activity_header_id',
  'supply_source',
  'destination_type',
  'line_description',
  'uom_id',
  'return_reason',
  'created_by',
  'creation_date',
  'last_update_by',
  'last_update_date',
 ];
 public $requiredField = [
  'hd_svo_header_id',
  'line_number',
  'inv_org_id',
  'item_id_m',
  'quantity'
 ];
 public $fields_inForm_notInDataBase = [
  "svo_number",
  "item_number",
  'tax_code_value',
  'ar_transaction_number',
  'item_description',
  'so_number',
  'so_line_number',
  'logistic_action'
 ];
 public $fields_inHeader_needsToBeInserted_inPOST = [
  "hd_svo_header_id"
 ];
 public $hd_svo_line_id;
 public $hd_svo_header_id;
 public $line_number;
 public $inv_org_id;
 public $item_id_m;
 public $quantity;
 public $hd_service_type_header_id;
 public $sd_so_header_id;
 public $sd_so_line_id;
 public $action_type_id;
 public $status;
 public $price_list_header_id;
 public $price_date;
 public $unit_price;
 public $line_price;
 public $line_status;
 public $requested_date;
 public $promise_date;
 public $schedule_ship_date;
 public $reference_doc_type;
 public $reference_doc_number;
 public $service_activity_header_id;
 public $supply_source;
 public $destination_type;
 public $line_description;
 public $uom_id;
 public $return_reason;
 public $created_by;
 public $creation_date;
 public $last_update_by;
 public $last_update_date;
 public $time;
 public $msg;
 public $item_number;
 public $tax_code_value;
 public $ar_transaction_number;
 public $item_description;
 public $logistic_action;
 public $so_number;
 public $so_line_number;

 private function _validate_before_save() {
  $ret = 1;
  $item = item::find_by_orgId_item_id_m($this->item_id_m, $this->inv_org_id);
  if ($item) {
   if (empty($item->customer_ordered_cb)) {
    $ret = -90;
    echo "<br> The item is not enabled for Sales ";
   }
  } else {
   $ret = -90;
   echo "<br> The item is not assigned to the organization";
  }

  return $ret;
 }

 public function _before_save() {
  if ($this->_validate_before_save() < 0) {
   return -90;
  }

  if (!empty($this->action)) {
   $this->_do_action();
  }

  if ((empty($this->line_status)) && (empty($this->sd_so_line_id))) {
   $this->line_status = 'PENDING_IMPORT';
   echo "<div class='alert alert-danger'>Line status is updated to <strong> " . $this->line_status . ".</strong></div> ";
  }
 }

 public function _after_save() {
  
 }

 private function _do_action() {
  switch ($this->action) {
   case 'PROCESS':
    $this->_process_line_to_so();
    break;

   case 'PROCESS_ACTUALS':
    $this->copy_estimates();
    break;

   default :
    break;
  }
 }
 
 private function _process_line_to_so(){
  
 }
 
  public static function find_by_headerId_and_status($hd_svo_header_id, $line_status = 'PENDING_IMPORT') {
  $sql = "SELECT * FROM " .
   self::$table_name .
   " where hd_svo_header_id= '{$hd_svo_header_id}' AND line_status= '{$line_status}' ";
  $result = self::find_by_sql($sql);
  return $result;
 }

 public function findAll_ByOrgId($org_id, $status = '') {
  $sql = " SELECT * FROM " .
   self::$table_name .
   " WHERE shipping_org_id= :shipping_org_id  ";
  if (!empty($status)) {
   $sql .= " AND line_status = :line_status ";
   $value_a = ['shipping_org_id' => $org_id, 'line_status' => $status];
  } else {
   $value_a = ['shipping_org_id' => $org_id];
  }
  $result_array = $this->findBySql($sql, $value_a);
  return !empty($result_array) ? $result_array : false;
 }

 Public static function hd_svo_line_types() {
  $option_header = option_header::find_by_name('PO_LINE_TYPE');
  $po_types = option_line::find_by_option_id($option_header->option_header_id);
  return $po_types;
 }

// public static function find_by_hd_ro_headerId($hd_ro_header_id) {
//  $sql = "SELECT * FROM " . self::$table_name . " where hd_ro_header_id = '{$hd_ro_header_id}'";
//  $result_array = self::find_by_sql($sql);
//  return $result_array;
// }

 public static function find_by_orgId_itemId_ssd($org_id, $item_id_m = '', $ssd = '') {
  $sql = " SELECT * FROM ";
  $sql .= self::$table_name;
  $sql .= " WHERE shipping_org_id = '{$org_id}'";
  $sql .= " AND schedule_ship_date IS NOT NULL ";
  if (!empty($item_id_m)) {
   $sql .= " AND item_id_m = '{$item_id_m}'";
  }
  if (!empty($ssd)) {
   $sql .= " AND schedule_ship_date >= '{$ssd}'";
  }
  $result_array = self::find_by_sql($sql);
  return !empty($result_array) ? $result_array : false;
 }

}

//end of hd_svo_line class
?>