<?php

class ar_transaction_detail extends dbObject {

 public static $table_name = "ar_transaction_detail";
 public static $primary_column = "ar_transaction_detail_id";
 public static $parent_primary_column = "ar_transaction_line_id";
 public static $key_column = 'detail_ac_id';
 public static $module = "ap";
 public $account = [
  'detail_ac_id'
 ];
 public $field_a = [
  'ar_transaction_detail_id',
  'ar_transaction_line_id',
  'ar_transaction_header_id',
  'detail_number',
  'account_type',
  'description',
  'amount',
  'gl_amount',
  'detail_ac_id',
  'status',
  'reference_type',
  'reference_key_name',
  'reference_key_value',
  'sd_so_header_id',
  'sd_so_line_id',
  'sd_so_detail_id',
  'period_id',
  'journal_created_cb',
  'created_by',
  'creation_date',
  'last_update_by',
  'last_update_date'
 ];
 public $requiredField = [
  'ar_transaction_line_id',
  'ar_transaction_header_id',
  'account_type',
  'amount',
  'detail_ac_id'
 ];
 public $dateField = [
  'need_by_date',
  'promise_date'
 ];
 public $fields_inForm_notInDataBase = [
  "om_so_number"
 ];
 public $fields_inHeader_needsToBeInserted_inPOST = [
  'ar_transaction_line_id',
  'ar_transaction_header_id'
 ];
 public $numberField = [
  'amount',
  'gl_amount'
 ];
 public $ar_transaction_detail_id;
 public $ar_transaction_line_id;
 public $ar_transaction_header_id;
 public $detail_number;
 public $account_type;
 public $description;
 public $amount;
 public $gl_amount;
 public $detail_ac_id;
 public $status;
 public $reference_type;
 public $reference_key_name;
 public $reference_key_value;
 public $sd_so_header_id;
 public $sd_so_line_id;
 public $sd_so_detail_id;
 public $period_id;
 public $journal_created_cb;
 public $created_by;
 public $creation_date;
 public $last_update_by;
 public $last_update_date;
 public $time;
 public $msg;

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
//	if (!empty($this->ar_transaction_detail_id) && ($this->journal_created_cb == 1)) {
//	 echo "<br>Update is not allowed as the journal lines have been created! "
//	 . "<br> Create credit memo if required";
//	 return -99;
//	}
 }

 public static function find_by_ar_transaction_lineId($ar_transaction_line_id) {
  $sql = "SELECT * FROM " . self::$table_name . " where ar_transaction_line_id = '{$ar_transaction_line_id}'";
  $result_array = self::find_by_sql($sql);
  return $result_array;
 }

 public function _after_save() {
  
 }

 public static function update_poDetail_status($ar_transaction_detail_id, $received_quantity = "", $accepted_quantity = "", $delivered_quantity = "", $invoiced_quantity = "", $paid_quantity = "") {
  global $error;
  global $db;
  //first get the existing recevived quantity
  $ar_transaction_details = self::find_by_id($ar_transaction_detail_id);
  $received_quantity_begining = $ar_transaction_details->received_quantity;
  $quantity = $ar_transaction_details->quantity;

  if ((!empty($ar_transaction_detail_id)) && ($quantity - ($received_quantity_begining + $received_quantity) >= 0 )) {
   $received_quantity += $received_quantity_begining;
   $sql = " UPDATE ";
   $sql .= self::$table_name;
   $sql .= " SET received_quantity = '{$received_quantity}' , ";
   $sql .= " accepted_quantity = '{$accepted_quantity}'  , ";
   $sql .= " delivered_quantity = '{$delivered_quantity}'  , ";
   $sql .= " invoiced_quantity = '{$invoiced_quantity}'  , ";
   $sql .= " paid_quantity = '{$paid_quantity}'   ";
   $sql .= " WHERE ar_transaction_detail_id = '{$ar_transaction_detail_id}' ";
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

//end of ar_transaction_detail class
?>