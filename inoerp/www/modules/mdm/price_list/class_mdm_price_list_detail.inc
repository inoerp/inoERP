<?php

class mdm_price_list_detail extends dbObject {

 public static $table_name = "mdm_price_list_detail";
 public static $primary_column = "mdm_price_list_detail_id";
 public static $parent_primary_column = "mdm_price_list_line_id";
 public static $key_column = 'qty_from';
 public static $module = "mdm";
 public $account = [
  'detail_ac_id'
 ];
 public $field_a = [
  'mdm_price_list_detail_id',
  'mdm_price_list_header_id',
  'mdm_price_list_line_id',
  'qty_from',
  'qty_to',
  'uom_id',
  'unit_price',
  'formula',
  'effective_start_date',
  'effective_end_date',
  'q_reference_key_name',
  'q_reference_key_value',
  'description',
  'created_by',
  'creation_date',
  'last_update_by',
  'last_update_date',
 ];
 public $requiredField = [
  'mdm_price_list_header_id',
  'mdm_price_list_line_id',
  'qty_from',
  'qty_to',
  'uom_id',
  'unit_price',
 ];
 public $fields_inForm_notInDataBase = [
  "item_number"
 ];
 public $fields_inHeader_needsToBeInserted_inPOST = [
  'mdm_price_list_line_id',
  'mdm_price_list_header_id'
 ];
 public $mdm_price_list_detail_id;
 public $mdm_price_list_header_id;
 public $mdm_price_list_line_id;
 public $qty_from;
 public $qty_to;
 public $uom_id;
 public $unit_price;
 public $formula;
 public $effective_start_date;
 public $effective_end_date;
 public $q_reference_key_name;
 public $q_reference_key_value;
 public $description;
 public $created_by;
 public $creation_date;
 public $last_update_by;
 public $last_update_date;
 public $time;
 public $msg;

 public static function find_by_mdm_price_list_lineId($mdm_price_list_line_id) {
  $sql = "SELECT * FROM " . self::$table_name . " where mdm_price_list_line_id = '{$mdm_price_list_line_id}'";
  $result_array = self::find_by_sql($sql);
  return $result_array;
 }

 public function _after_save() {
  
 }

 public function _before_save() {
  if (!empty($this->account_type) && ($this->account_type == 'TAX')) {
   //verify if detail line exists for tax, if not add. if exists update if the amount is different
   $this->_validate_tax_detail_line();
  }
 }

 private function _validate_tax_detail_line() {
  if (!empty($this->mdm_price_list_line_id) && !empty($this->mdm_price_list_detail_id)) {
   $trx_line = mdm_price_list_line::find_by_id($this->mdm_price_list_line_id);
   if ($trx_line && ($this->amount != $trx_line->tax_amount)) {
    $this->amount = $trx_line->tax_amount;
   }
  }
 }

 public static function find_taxLine_by_lineId($mdm_price_list_line_id) {
  $sql = "SELECT * FROM " . self::$table_name . " where mdm_price_list_line_id = '{$mdm_price_list_line_id}'"
   . "  AND account_type = 'TAX'  ";
  $sql = ino_perPageSql_i($sql, 1);
  $result_array = self::find_by_sql($sql);
  return !empty($result_array) ? array_pop($result_array) : false;
 }

 public function findTaxLine_byLineId($mdm_price_list_line_id = '') {
  $mdm_price_list_line_id = !empty($mdm_price_list_line_id) ? $mdm_price_list_line_id : $this->mdm_price_list_line_id;
  $sql = "SELECT * FROM " . self::$table_name . " where mdm_price_list_line_id = :mdm_price_list_line_id "
   . "  AND account_type = 'TAX' ";
  $sql = ino_perPageSql_i($sql, 1);
  $value_a = [ 'mdm_price_list_line_id' => $mdm_price_list_line_id];
  $result = $this->findBySql($sql, $value_a);
  return !empty($result) ? array_pop($result) : false;
 }

 public static function update_poDetail_status($mdm_price_list_detail_id, $received_quantity = "", $accepted_quantity = "", $delivered_quantity = "", $invoiced_quantity = "", $paid_quantity = "") {
  global $error;
  global $db;
  //first get the existing recevived quantity
  $mdm_price_list_details = self::find_by_id($mdm_price_list_detail_id);
  $received_quantity_begining = $mdm_price_list_details->received_quantity;
  $quantity = $mdm_price_list_details->quantity;

  if ((!empty($mdm_price_list_detail_id)) && ($quantity - ($received_quantity_begining + $received_quantity) >= 0 )) {
   $received_quantity += $received_quantity_begining;
   $sql = " UPDATE ";
   $sql .= self::$table_name;
   $sql .= " SET received_quantity = '{$received_quantity}' , ";
   $sql .= " accepted_quantity = '{$accepted_quantity}'  , ";
   $sql .= " delivered_quantity = '{$delivered_quantity}'  , ";
   $sql .= " invoiced_quantity = '{$invoiced_quantity}'  , ";
   $sql .= " paid_quantity = '{$paid_quantity}'   ";
   $sql .= " WHERE mdm_price_list_detail_id = '{$mdm_price_list_detail_id}' ";
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

//end of mdm_price_list_detail class
?>