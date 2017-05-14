<?php

class ar_receipt_line extends dbObject {

 public static $table_name = "ar_receipt_line";
 public static $primary_column = "ar_receipt_line_id";
 public static $parent_primary_column = "ar_receipt_header_id";
 public static $multi_search_primary_column = "ar_receipt_header_id"; //this value is used in multi search hidden value
 public static $key_column = 'amount';
 public static $module = "ap";
 public static $line_type_a = [
		 'INVOICE' => 'Invoice',
		 'WF' => 'Write-off',
		 'REFUND' => 'Refund',
 ];
 public static $status_a = [
		 'CLEARED' => 'Cleared'
 ];
 public $field_a = [
		 'ar_receipt_line_id',
		 'ar_receipt_header_id',
		 'ar_transaction_header_id',
		 'line_number',
		 'line_type',
		 'ar_receivable_activity_id',
		 'amount',
		 'exchange_rate',
		 'line_description',
		 'gl_amount',
		 'status',
		 'line_source',
		 'reference_type',
		 'reference_key_name',
		 'reference_key_value',
		 'period_id',
		 'created_by',
		 'creation_date',
		 'last_update_by',
		 'last_update_date'
 ];
 public $requiredField = [
		 'ar_receipt_header_id',
		 'ar_transaction_header_id',
		 'line_number'
 ];
 public $numberField = [
		 'amount',
		 'exchange_rate',
		 'gl_amount'
 ];
 public $fields_inForm_notInDataBase = [
		 "transaction_number",
		 'invoiced_quantity',
		 'action',
		 'invoice_amount',
		 'remaining_amount',
 ];
 public $fields_inHeader_needsToBeInserted_inPOST = [
		 "ar_receipt_header_id"
 ];
 public $initial_search = [
		 'ar_receipt_header_id',
		 'ar_transaction_header_id',
		 'line_number',
		 'line_description',
		 'reference_key_value',
 ];
 public $ar_receipt_line_id;
 public $ar_receipt_header_id;
 public $line_number;
 public $line_type;
 public $ar_receivable_activity_id;
 public $amount;
 public $line_description;
 public $ar_transaction_header_id;
 public $gl_amount;
 public $exchange_rate;
 public $status;
 public $line_source;
 public $reference_type;
 public $reference_key_name;
 public $reference_key_value;
 public $period_id;
 public $created_by;
 public $creation_date;
 public $last_update_by;
 public $last_update_date;
 public $invoice_amount;
 public $remaining_amount;
 public $transaction_number;
 public $receipt_amount;

 public function _after_save() {
	if ($this->ar_receipt_line_id) {
	 //update the invoice paid amount
	 try {
		$this->_update_invoice_amount();
	 } catch (Exception $e) {
		echo "<br>Updating transaction paid amount failed @ ar_receipt_line after save" . $e->getMessage();
	 }
	}
 }

 public function _before_save() {
	//if there is a line id in the form then return 10 as no changes to paid lines are allowed
	if ($this->ar_receipt_line_id) {
	 echo "<br>You can't update any payment line.Cancel/Viod the receipt if required";
	 return 10;
	}
 }

 public function update_line_status($line_id, $line_status = 'CLEARED') {
	$ar_receipt_line_i = new ar_receipt_line();
	$ar_receipt_line_i->findBy_id($line_id);
	$ar_receipt_line_i->status = $line_status;
	$ar_receipt_line_i->save();
 }

 private function _update_invoice_amount() {
	if (!empty($this->ar_transaction_header_id)) {
	 $arth = new ar_transaction_header();
	 $arth_i = $arth->findBy_id($this->ar_transaction_header_id);
	 $arth->ar_transaction_header_id = $this->ar_transaction_header_id;
	 $arth->receipt_amount = $this->amount + $arth_i->receipt_amount;
	 if ($arth->receipt_amount <= $arth_i->header_amount) {
		$arth->save();
	 } else {
		echo "<br>Receipt amount is more than available balance. Or<br>The Transaction# $arth_i->transaction_number is fully paid ";
	 }
	}
 }

 private function _highest_line_number_from_header() {
	global $db;
	$sql = " SELECT max(line_number) as line_number FROM " . self::$table_name;
	$sql .= " WHERE ar_receipt_header_id= :ar_receipt_header_id ";
	$param_a = ['ar_receipt_header_id'];
	$value_a = ['ar_receipt_header_id' => $this->ar_receipt_header_id];
	$result = $db->findBy_sql($sql, $param_a, $value_a);
	return !empty($result) ? array_pop($result) : 0;
 }

 Public static function ar_receipt_line_types() {
	$option_header = option_header::find_by_name('PO_LINE_TYPE');
	$po_types = option_line::find_by_option_id($option_header->option_header_id);
	return $po_types;
 }

 public static function find_by_ar_receipt_headerId($ar_receipt_header_id) {
	$sql = "SELECT * FROM " . self::$table_name . " where ar_receipt_header_id = '{$ar_receipt_header_id}'";
	$result_array = self::find_by_sql($sql);
	return $result_array;
 }

 public function multi_select_input_fields() {
	$multi_select_input = [
			'inv_line_quantity',
			'inv_unit_price',
			'inv_line_price',
			'inv_line_type'
	];
	return $multi_select_input;
 }

 public function multi_select_hidden_fields() {
	$multi_select_hidden = [
			'action_class_name',
			'ar_customer_id',
			'po_header_id',
			'ar_receipt_header_id',
			'mode',
			'action',
			'po_status'
	];

	return $multi_select_hidden;
 }

 public function copy($ar_receipt_line_id) {
	global $db;
	$sql1 = " CREATE TEMPORARY TABLE tmptable SELECT * FROM ar_receipt_line WHERE `ar_receipt_line_id` = '{$ar_receipt_line_id}' ";
	if ($db->query($sql1)) {
	 $sql2 = "  UPDATE tmptable SET `ar_receipt_line_id` = '' ,
           `org_id` = '{$this->org_id}' 
          WHERE `ar_receipt_line_id` = '{$ar_receipt_line_id}' ";
	 if ($db->query($sql2)) {
		$sql3 = " INSERT INTO `ar_receipt_line` SELECT * FROM tmptable WHERE `ar_receipt_line_id` = '' ";
		if ($db->query($sql3)) {
		 $this->ar_receipt_line_id = $db->insert_id();
		 $this->msg = 1;
		} else {
		 $this->msg = 0;
		}
	 }
	}
	return $this->msg;
 }

}

//end of ar_receipt_line class
?>