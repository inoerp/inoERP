<?php

class receipt_line extends receipt_header {

 protected static $table_name = "receipt_line";
 public static $field_array = [
		 'receipt_line_id',
		 'receipt_header_id',
		 'subinventory_id',
		 'locator_id',
		 'item_id',
		 'item_description',
		 'status',
		 'uom_id',
		 'received_quantity',
		 'ref_doc_type',
		 'ref_doc_number',
		 'po_header_id',
		 'po_line_id',
		 'po_detail_id',
		 "receving_account_id",
		 "accrual_account_id",
		 'country_of_origin',
		 'lot_number',
		 'serial_number',
		 'created_by',
		 'creation_date',
		 'last_update_by',
		 'last_update_date',
		 
 ];
 //variables used for showing data

 public static $initial_search_array = [
 ];
 public static $column_array = [
 ];
 public static $account_array = [
		 "receving_account_id",
		 "accrual_account_id"
 ];
 public static $checkbox_array = [
 ];
 public static $fields_inForm_notInDataBase = [
		 'po_received_quantity'
 ];
 public static $fields_inHeader_needsToBeInserted_inPOST = [
		 "receipt_header_id",
		 'org_id'
 ];
 public static $requiredField_array = [
		 'receipt_header_id',
		 'subinventory_id',
		 'item_description',
		 'uom_id',
		 'received_quantity'
 ];
 public static $primary_column = "receipt_line_id";
 public $receipt_line_id;
 public $receipt_header_id;
 public $subinventory_id;
 public $locator_id;
 public $item_id;
 public $item_description;
 public $status;
 public $uom_id;
 public $received_quantity;
 public $ref_doc_type;
 public $ref_doc_number;
 public $po_header_id;
 public $po_line_id;
 public $po_detail_id;
 public $receving_account_id;
 public $accrual_account_id;
 public $country_of_origin;
 public $created_by;
 public $creation_date;
 public $last_update_by;
 public $last_update_date;
 public $time;
 public $msg;
 public $org_id;
 public $lot_number;
 public $serial_number;
 public $po_received_quantity;

 public function __set($name, $value) {
	$this->$name = $value;
 }

 Public static function inv_transaction_class() {
	$option_header = option_header::find_by_name('TRANSACTION_TYPE_CLASS');
	$inv_transaction_class = option_line::find_by_option_id($option_header->option_id);
	return $inv_transaction_class;
 }

 public static function find_all_by_receiptHeaderId($receipt_headerId) {

	$sql = " Select * from ";
	$sql .= self::$table_name;
	$sql .= " WHERE receipt_header_id = '{$receipt_headerId}'";

	$all_receipt_lines = self::find_by_sql($sql);

	return $all_receipt_lines;
 }

 public function _before_showing() {
	
 }

 public function _before_submit() {
	
 }

 public function save() {
	global $error;
	$poDetail_status = po_detail::update_poDetail_status($this->po_detail_id, $this->received_quantity);
	if ($poDetail_status == 1) {
	 $onhandUpdate_result = onhand::update_onhand($this->item_id, $this->org_id, $this->uom_id, $this->received_quantity, '', '', '', $this->org_id, $this->subinventory_id, $this->locator_id, $this->lot_number, $this->serial_number);
	 if (((!empty($this->subinventory_id)) && ($onhandUpdate_result['to_update_staus'] == 1))) {
		$this->create();
	 } else {
		$error['po_onahand_status'] = "Error in updating onHand Quantity";
	 }
	} else {
	 $error['po_detail_status'] = "Error in updating PO detail status";
	 $this->msg = 0;
	}
//	if (!empty($error)) {
//	 foreach ($error as $key => $value) {
//		echo "<br/><br/> $key : $value ";
//	 }
//	}
	ino_print_error($error);
	return $this->msg;
 }

 public function _after_save() {
	
 }

}
?>