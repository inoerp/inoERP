<?php

 class po_rfq_detail extends dbObject {

  public static $table_name = "po_rfq_detail";
  public static $primary_column = "po_rfq_detail_id";
  public static $parent_primary_column = "po_rfq_line_id";
  public static $key_column = 'requirement_number';
  public static $module = "po";
  public static $requirement_type_a = [
   'REQUIRED' => 'Required',
   'OPTIONAL' => 'Optional',
   'DISPLAY_ONLY' => 'Display Only',
  ];
  public $field_a = [
   'po_rfq_detail_id',
   'po_rfq_header_id',
   'po_rfq_line_id',
   'reference_table',
   'reference_id',
   'requirement_number',
   'requirement_name',
   'max_evaludation_points',
   'description',
   'requirement_type',
   'target_value',
   'created_by',
   'creation_date',
   'last_update_by',
   'last_update_date',
  ];
  public $initial_search = [
   'po_rfq_detail_id',
   'reference_table',
   'reference_id',
   'requirement_number',
   'requirement_name',
  ];
  public $requiredField = [
   'requirement_number',
   'requirement_name',
  ];
    public $numberField = [
   'max_evaludation_points',
  ];
  public $fields_inForm_notInDataBase = [
  ];
  public $fields_inHeader_needsToBeInserted_inPOST = [
   'po_rfq_line_id',
   'po_rfq_header_id'
  ];
  public $po_rfq_detail_id;
  public $po_rfq_header_id;
  public $po_rfq_line_id;
  public $reference_table;
  public $reference_id;
  public $max_evaludation_points;
  public $requirement_number;
  public $requirement_name;
  public $description;
  public $requirement_type;
  public $target_value;
  public $created_by;
  public $creation_date;
  public $last_update_by;
  public $last_update_date;

  public static function find_by_po_rfq_lineId($po_rfq_line_id) {
   $sql = "SELECT * FROM " . self::$table_name . " where po_rfq_line_id = '{$po_rfq_line_id}'";
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

  public static function update_poDetail_status($po_rfq_detail_id, $received_quantity = "", $accepted_quantity = "", $delivered_quantity = "", $invoiced_quantity = "", $paid_quantity = "") {
   global $error;
   global $db;
   //first get the existing recevived quantity
   $po_rfq_details = self::find_by_id($po_rfq_detail_id);
   $received_quantity_begining = $po_rfq_details->received_quantity;
   $quantity = $po_rfq_details->quantity;

   if ((!empty($po_rfq_detail_id)) && ($quantity - ($received_quantity_begining + $received_quantity) >= 0 )) {
    $received_quantity += $received_quantity_begining;
    $sql = " UPDATE ";
    $sql .= self::$table_name;
    $sql .= " SET received_quantity = '{$received_quantity}' , ";
    $sql .= " accepted_quantity = '{$accepted_quantity}'  , ";
    $sql .= " delivered_quantity = '{$delivered_quantity}'  , ";
    $sql .= " invoiced_quantity = '{$invoiced_quantity}'  , ";
    $sql .= " paid_quantity = '{$paid_quantity}'   ";
    $sql .= " WHERE po_rfq_detail_id = '{$po_rfq_detail_id}' ";
   } else {
    $error['Received_Quantity'] = 'Received Quantity is Less than available Open Quantity';
    $msg = 9;
   }
   if (!empty($sql)) {
    if ($db->query($sql)) {
     $msg = 1;
    } else {
     $error['po_rfq_detail_STATUS_DB_UPDATE'] = 'PO Detail Status Data base update Failed';
     $msg = 0;
    }
   }
   ino_print_error();
   return $msg;
   //message 7 - number of open quantity is less than received quantity
  }

 }

//end of po_rfq_detail class
?>