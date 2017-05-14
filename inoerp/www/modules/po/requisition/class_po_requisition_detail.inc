<?php
/* Below are appllicable only for IRs
 *  "received_quantity",
  "accepted_quantity",
  'delivered_quantity',
  'invoiced_quantity',
*
 * 
 *  */


class po_requisition_detail extends dbObject {

 public static $table_name = "po_requisition_detail";
 public static $primary_column = "po_requisition_detail_id";
 public static $parent_primary_column = "po_requisition_line_id";
 public static $key_column = 'shipment_number';
 public static $module = "po_requisition";
 public $ir_status_a = [
  'PAR_RECEIVED' => 'Partially Received',
  'FULL_RECEIVED' => 'Fully Received',
 ];
 public $account = [
  'charge_ac_id',
  'accrual_ac_id',
  'budget_ac_id',
  'ppv_ac_id',
 ];
 public $checkbox = [
  "rev_enabled_cb"
 ];
 public $field_a = [
  'po_requisition_detail_id',
  'po_requisition_line_id',
  'po_requisition_header_id',
  'shipment_number',
  'subinventory_id',
  'locator_id',
  'requestor',
  'ship_to_location_id',
  'quantity',
  'need_by_date',
  'promise_date',
  'charge_ac_id',
  'accrual_ac_id',
  'budget_ac_id',
  'ppv_ac_id',
  "ef_id",
  'order_number',
  'order_type',
  "received_quantity",
  "accepted_quantity",
  'delivered_quantity',
  'invoiced_quantity',
  'paid_quantity',
  'ir_status',
  "created_by",
  "creation_date",
  "last_update_by",
  "last_update_date"
 ];
 public $initial_search = [
  "po_requisition_header_id",
  "po_requisition_number",
  "supplier_id",
  "supplier_name",
  "supplier_number",
  "supplier_site_name",
  "buyer"
 ];
 public $dateFields = [
  'need_by_date'
 ];
 
  public $requiredField = [
  'po_requisition_line_id',
  'po_requisition_header_id',
  'shipment_number',
  'charge_ac_id',
  'accrual_ac_id',
  'ppv_ac_id',
 ];
  
 public $dateField = [
  'need_by_date',
  'promise_date'
 ];
 public $fields_inForm_notInDataBase = [
  "po_requisition_number",
  "supplier_name",
  "supplier_number",
  "supplier_site_name",
 ];
 public $fields_inHeader_needsToBeInserted_inPOST = [
  'po_requisition_line_id',
  'po_requisition_header_id'
 ];
 public static $otherField_array = [
 ];
 public $po_requisition_detail_id;
 public $po_requisition_line_id;
 public $po_requisition_header_id;
 public $shipment_number;
 public $subinventory_id;
 public $locator_id;
 public $requestor;
 public $ship_to_location_id;
 public $quantity;
 public $need_by_date;
 public $promise_date;
 public $charge_ac_id;
 public $accrual_ac_id;
 public $budget_ac_id;
 public $ppv_ac_id;
 public $order_number;
 public $order_type;
 public $ir_status;
 public $created_by;
 public $creation_date;
 public $last_update_by;
 public $last_update_date;
 public $time;
 public $msg;
 public $received_quantity;
 public $accepted_quantity;
 public $delivered_quantity;
 public $invoiced_quantity;
 public $paid_quantity;
 public $po_requisition_number;
 public $supplier_name;
 public $supplier_number;
 public $supplier_site_name;

 public static function find_by_po_requisition_lineId($po_requisition_line_id) {
  $sql = "SELECT * FROM " . self::$table_name . " where po_requisition_line_id = '{$po_requisition_line_id}'";
  $result_array = self::find_by_sql($sql);
  return $result_array;
 }

 public function _before_save() {
  if (!empty($this->order_number)) {
   echo " Action not allowed!. <br>"
   . " Requisition has already been converted to order# " . $this->order_number;
   return -99;
  }
 }

 public function _after_save() {
  
 }

 public static function update_po_requisitionDetail_status($po_requisition_detail_id, $received_quantity = "", $accepted_quantity = "", $delivered_quantity = "", $invoiced_quantity = "", $paid_quantity = "") {
  global $error;
  global $db;
  //first get the existing recevived quantity
  $po_requisition_details = self::find_by_id($po_requisition_detail_id);
  $received_quantity_begining = $po_requisition_details->received_quantity;
  $quantity = $po_requisition_details->quantity;

  if ((!empty($po_requisition_detail_id)) && ($quantity - ($received_quantity_begining + $received_quantity) >= 0 )) {
   $received_quantity += $received_quantity_begining;
   $sql = " UPDATE ";
   $sql .= self::$table_name;
   $sql .= " SET received_quantity = '{$received_quantity}' , ";
   $sql .= " accepted_quantity = '{$accepted_quantity}'  , ";
   $sql .= " delivered_quantity = '{$delivered_quantity}'  , ";
   $sql .= " invoiced_quantity = '{$invoiced_quantity}'  , ";
   $sql .= " paid_quantity = '{$paid_quantity}'   ";
   $sql .= " WHERE po_requisition_detail_id = '{$po_requisition_detail_id}' ";
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

//end of po_requisition_detail class
?>