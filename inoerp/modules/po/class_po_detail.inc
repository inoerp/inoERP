<?php

 class po_detail extends dbObject {

  public static $table_name = "po_detail";
  public static $primary_column = "po_detail_id";
  public static $parent_primary_column = "po_line_id";
  public static $key_column = 'shipment_number';
  public static $module = "po";
  public static $invoice_match_type_a = [
   'TWO_WAY' => '2 Way',
   'THREE_WAY' => '3 Way',
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
   'po_detail_id',
   'po_line_id',
   'po_header_id',
   'shipment_number',
   'subinventory_id',
   'locator_id',
   'requestor',
   'ship_to_location_id',
   'invoice_match_type',
   'quantity',
   'need_by_date',
   'promise_date',
   'charge_ac_id',
   'accrual_ac_id',
   'budget_ac_id',
   'ppv_ac_id',
   "ef_id",
   "received_quantity",
   "accepted_quantity",
   'delivered_quantity',
   'invoiced_quantity',
   'paid_quantity',
   "created_by",
   "creation_date",
   "last_update_by",
   "last_update_date"
  ];
  public $initial_search = [
   "po_header_id",
   "po_number",
   "supplier_id",
   "supplier_name",
   "supplier_number",
   "supplier_site_name",
   "buyer"
  ];
  public $column = [
   "po_header_id",
   "po_line_id",
   "po_detail_id",
//		 "supplier_id",
   "creation_date"
  ];
  public $requiredField = [
   'po_line_id',
   'po_header_id',
   'shipment_number',
   'charge_ac_id',
   'accrual_ac_id',
   'ppv_ac_id',
  ];
  public $dateField = [
   'need_by_date',
   'promise_date'
  ];
  public $numberField = [
   'quantity',
  ];
  public $notUpdatedFromWebForm = [
   "received_quantity",
   "accepted_quantity",
   'delivered_quantity',
   'invoiced_quantity',
   'paid_quantity',
  ];
  public $fields_inForm_notInDataBase = [
   "po_number",
   "supplier_name",
   "supplier_number",
   "supplier_site_name",
  ];
  public $fields_inHeader_needsToBeInserted_inPOST = [
   'po_line_id',
   'po_header_id'
  ];
  public static $otherField_array = [
  ];
  public $po_detail_id;
  public $po_line_id;
  public $po_header_id;
  public $shipment_number;
  public $subinventory_id;
  public $locator_id;
  public $requestor;
  public $invoice_match_type;
  public $ship_to_location_id;
  public $quantity;
  public $need_by_date;
  public $promise_date;
  public $charge_ac_id;
  public $accrual_ac_id;
  public $budget_ac_id;
  public $ppv_ac_id;
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
  public $po_number;
  public $supplier_name;
  public $supplier_number;
  public $supplier_site_name;

  public static function find_by_po_lineId($po_line_id) {
   $sql = "SELECT * FROM " . self::$table_name . " where po_line_id = '{$po_line_id}'";
   $result_array = self::find_by_sql($sql);
   return $result_array;
  }

  public function _before_delete() {
   if (!empty($this->received_quantity) || !empty($this->accepted_quantity) || !empty($this->delivered_quantity) ||
     !empty($this->invoiced_quantity) || !empty($this->paid_quantity)) {
    echo "<br>Delete is not allowed as transaction exists for the PO Detail Lines. ";
    return -99;
   } else {
    return 1;
   }
  }

  public static function update_poDetail_status($po_detail_id, $received_quantity = "", $accepted_quantity = "", $delivered_quantity = "", $invoiced_quantity = "", $paid_quantity = "") {
   global $error;
   global $db;
   //first get the existing recevived quantity
   $po_details = self::find_by_id($po_detail_id);
   $received_quantity_begining = $po_details->received_quantity;
   $quantity = $po_details->quantity;

   if ((!empty($po_detail_id)) && ($quantity - ($received_quantity_begining + $received_quantity) >= 0 )) {
    $received_quantity += $received_quantity_begining;
    $sql = " UPDATE ";
    $sql .= self::$table_name;
    $sql .= " SET received_quantity = '{$received_quantity}' , ";
    $sql .= " accepted_quantity = '{$accepted_quantity}'  , ";
    $sql .= " delivered_quantity = '{$delivered_quantity}'  , ";
    $sql .= " invoiced_quantity = '{$invoiced_quantity}'  , ";
    $sql .= " paid_quantity = '{$paid_quantity}'   ";
    $sql .= " WHERE po_detail_id = '{$po_detail_id}' ";
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

//end of po_detail class
?>