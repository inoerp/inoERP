<?php

class receipt_line extends dbObject {

 protected static $table_name = "receipt_line";
 public static $primary_column = "receipt_line_id";
 public static $parent_primary_column = "receipt_header_id";
 public static $multi_select_template_path = "modules/inv/receipt/receipt_template.php";
 public static $multi_search_primary_column = "receipt_header_id"; //this value is used in multi search hidden value
 public static $key_column = 'item_description';
 public static $module = "inv";
 public $field_a = [
		 'receipt_line_id',
		 'receipt_header_id',
		 'subinventory_id',
		 'transaction_type_id',
		 'locator_id',
		 'item_id',
		 'item_description',
		 'status',
		 'uom_id',
		 'transaction_quantity',
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

 public $account = [
		 "receving_account_id",
		 "accrual_account_id"
 ];
 public $fields_inForm_notInDataBase = [
		 'po_received_quantity',
		 'po_number',
		 'line_number',
		 'shipment_number',
		 'item_number',
		 'uom_name',
		 'supplier_id',
		 'supplier_number',
		 'supplier_name',
		 'supplier_site_id',
		 'supplier_site_number',
		 'supplier_site'
 ];
 public $fields_inHeader_needsToBeInserted_inPOST = [
		 "receipt_header_id",
		 'org_id'
 ];
 public static $requiredField = [
		 'receipt_header_id',
		 'subinventory_id',
		 'item_description',
		 'uom_id',
		 'transaction_quantity'
 ];
 public $receipt_line_id;
 public $receipt_header_id;
 public $subinventory_id;
 public $locator_id;
 public $item_id;
 public $item_description;
 public $status;
 public $uom_id;
 public $transaction_quantity;
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
 public $transaction_type_id;
 public $po_number;
 public $line_number;
 public $shipment_number;
 public $item_number;
 public $uom_name;
 public $supplier_id;
 public $supplier_number;
 public $supplier_name;
 public $supplier_site_id;
 public $supplier_site_number;
 public $supplier_site_name;

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

 private function _update_onhand() {
	$onhand = new onhand();

	switch ($this->transaction_type_id) {
	 case 4 :
		$onhand->setProperty('_to_org_id', $this->org_id);
		$onhand->setProperty('_to_subinventory_id', $this->subinventory_id);
		if (!empty($this->locator_id)) {
		 $onhand->setProperty('_to_locator_id', $this->locator_id);
		}
		$onhand->setProperty('_transaction_quantity', $this->received_quantity);
		$onhand->item_id = $this->item_id;
		$update_result = $onhand->updateOnhand();
		break;

	 case 51 :
		$onhand->setProperty('_from_org_id', $this->org_id);
		$onhand->setProperty('_from_subinventory_id', $this->from_subinventory_id);
		$onhand->setProperty('_from_locator_id', $this->from_locator_id);
		$onhand->setProperty('_transaction_quantity', $this->transaction_quantity);
		$onhand->item_id = $this->item_id;
		$update_result = $onhand->updateOnhand();
		break;

	 default:
		break;
	}
 }

 public function _after_save() {

	if (!empty($this->receipt_line_id)) {
	 try {
		po_detail::update_poDetail_status($this->po_detail_id, $this->received_quantity);
		echo "<br>PO Received Quantity is Sucessfully Updated ";
		if (!empty($this->item_id)) {
		 try {
			$this->_update_onhand();
			echo "<br>Onhand Quantity is Sucessfully Updated ";
		 } catch (Exception $e) {
			$update_satus = -99;
			echo "<br>OnhandUpdate Failed! Receipt Line Error @ " . __LINE__ . $e->getMessage();
		 }
		}
	 } catch (Exception $e) {
		$update_satus = -99;
		echo "<br>PO Detail Update Failed! Receipt Line Error @ " . __LINE__ . $e->getMessage();
	 }
	}
	if ($update_satus > 0) {
	 $this->status = 'Success';
	} else {
	 $this->status = 'Error';
	}
	$this->save();
 }

 public function multi_select_input_fields() {
	$multi_select_input = [
			'transaction_quantity'
	];
	return $multi_select_input;
 }

 public function multi_select_hidden_fields() {
	$multi_select_hidden = [
			'action_class_name',
			'supplier_id',
			'po_header_id',
			'ap_transaction_header_id',
			'mode',
			'action',
			'po_status',
			'show_block'
	];

	return $multi_select_hidden;
 }

}

?>