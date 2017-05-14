<?php

class ap_transaction_detail extends dbObject {

 public static $table_name = "ap_transaction_detail";
 public static $primary_column = "ap_transaction_detail_id";
 public static $parent_primary_column = "ap_transaction_line_id";
 public static $key_column = 'detail_ac_id';
 public static $module = "ap";
 public $checkbox = ['journal_created_cb'];
 public $account = [
  'detail_ac_id'
 ];
 public $field_a = [
  'ap_transaction_detail_id',
  'ap_transaction_line_id',
  'ap_transaction_header_id',
  'account_type',
  'description',
  'amount',
  'gl_amount',
  'detail_ac_id',
  'status',
  'reference_type',
  'reference_key_name',
  'reference_key_value',
  'po_header_id',
  'po_line_id',
  'po_detail_id',
  'journal_created_cb',
  'period_id',
  'created_by',
  'creation_date',
  'last_update_by',
  'last_update_date'
 ];
 public $requiredField = [
  'ap_transaction_line_id',
  'ap_transaction_header_id',
  'account_type',
  'amount',
  'gl_amount',
  'detail_ac_id'
 ];
 public $dateField = [
  'need_by_date',
  'promise_date'
 ];
 public $numberField = [
  'amount',
  'gl_amount'
 ];
 public $fields_inForm_notInDataBase = [
  "po_number"
 ];
 public $fields_inHeader_needsToBeInserted_inPOST = [
  'ap_transaction_line_id',
  'ap_transaction_header_id'
 ];
 public static $otherField_array = [
 ];
 public $ap_transaction_detail_id;
 public $ap_transaction_line_id;
 public $ap_transaction_header_id;
 public $detail_number;
 public $account_type;
 public $description;
 public $amount;
 public $gl_amount;
 public $detail_ac_id;
 public $journal_created_cb;
 public $status;
 public $reference_type;
 public $reference_key_name;
 public $reference_key_value;
 public $po_header_id;
 public $po_line_id;
 public $po_detail_id;
 public $period_id;
 public $created_by;
 public $creation_date;
 public $last_update_by;
 public $last_update_date;
 public $time;
 public $msg;

 public static function find_by_ap_transaction_lineId($ap_transaction_line_id) {
  $sql = "SELECT * FROM " . self::$table_name . " where ap_transaction_line_id = '{$ap_transaction_line_id}'";
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
  if (!empty($this->ap_transaction_line_id) && !empty($this->ap_transaction_detail_id)) {
   $trx_line = ap_transaction_line::find_by_id($this->ap_transaction_line_id);
   if ($trx_line && ($this->amount != $trx_line->tax_amount)) {
    $this->amount = $trx_line->tax_amount;
   }
  }
 }

 public static function find_taxLine_by_lineId($ap_transaction_line_id) {
  $sql = "SELECT * FROM " . self::$table_name . " where ap_transaction_line_id = '{$ap_transaction_line_id}'"
   . "  AND account_type = 'TAX' ";
  switch (DB_TYPE) {
   case 'ORACLE' :
    $sql .= ' AND ' . ino_perPageSql(1);
    break;

   default:
    $sql .= ino_perPageSql(1);
    break;
  }
  $result_array = self::find_by_sql($sql);
  return !empty($result_array) ? array_pop($result_array) : false;
 }

 public function findTaxLine_byLineId($ap_transaction_line_id = '') {
  $ap_transaction_line_id = !empty($ap_transaction_line_id) ? $ap_transaction_line_id : $this->ap_transaction_line_id;
  $sql = "SELECT * FROM " . self::$table_name . " where ap_transaction_line_id = :ap_transaction_line_id "
   . "  AND account_type = 'TAX'  ";
  switch (DB_TYPE) {
   case 'ORACLE' :
    $sql .= ' AND ' . ino_perPageSql(1);
    break;

   default:
    $sql .= ino_perPageSql(1);
    break;
  }
  $value_a = [ 'ap_transaction_line_id' => $ap_transaction_line_id];
  $result = $this->findBySql($sql, $value_a);
  return !empty($result) ? array_pop($result) : false;
 }

 public static function update_poDetail_status($ap_transaction_detail_id, $received_quantity = "", $accepted_quantity = "", $delivered_quantity = "", $invoiced_quantity = "", $paid_quantity = "") {
  global $error;
  global $db;
  //first get the existing recevived quantity
  $ap_transaction_details = self::find_by_id($ap_transaction_detail_id);
  $received_quantity_begining = $ap_transaction_details->received_quantity;
  $quantity = $ap_transaction_details->quantity;

  if ((!empty($ap_transaction_detail_id)) && ($quantity - ($received_quantity_begining + $received_quantity) >= 0 )) {
   $received_quantity += $received_quantity_begining;
   $sql = " UPDATE ";
   $sql .= self::$table_name;
   $sql .= " SET received_quantity = '{$received_quantity}' , ";
   $sql .= " accepted_quantity = '{$accepted_quantity}'  , ";
   $sql .= " delivered_quantity = '{$delivered_quantity}'  , ";
   $sql .= " invoiced_quantity = '{$invoiced_quantity}'  , ";
   $sql .= " paid_quantity = '{$paid_quantity}'   ";
   $sql .= " WHERE ap_transaction_detail_id = '{$ap_transaction_detail_id}' ";
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

//end of ap_transaction_detail class
?>