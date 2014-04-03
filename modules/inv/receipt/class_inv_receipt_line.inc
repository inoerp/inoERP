<?php

class inv_receipt_line extends dbObject {

 protected static $table_name = "inv_receipt_line";
 public static $primary_column = "inv_receipt_line_id";
 public static $parent_primary_column = "inv_receipt_header_id";
 public static $multi_select_template_path = "modules/inv/receipt/receipt_template.php";
 public static $multi_search_primary_column = "inv_receipt_header_id"; //this value is used in multi search hidden value
 public static $key_column = 'item_description';
 public static $module = "inv";
 public $field_a = [
		 'inv_receipt_line_id',
		 'line_number',
		 'inv_receipt_header_id',
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
		 "inv_receipt_header_id",
		 'org_id',
		 'po_line_number',
		 'received_quantity',
		 'quantity'
 ];
 public $requiredField = [
		 'inv_receipt_header_id',
		 'subinventory_id',
		 'item_description',
		 'uom_id',
		 'transaction_quantity'
 ];
 public $inv_receipt_line_id;
 public $inv_receipt_header_id;
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
 public $po_line_number;
 public $quantity;
 public $received_quantity;

 Public static function inv_transaction_class() {
	$option_header = option_header::find_by_name('TRANSACTION_TYPE_CLASS');
	$inv_transaction_class = option_line::find_by_option_id($option_header->option_id);
	return $inv_transaction_class;
 }

 public function _after_save() {

	if (!empty($this->inv_receipt_line_id)) {
	 $update_satus = 0;
	 try {
		$po_d = new po_detail();
		$po_d_i = $po_d->findBy_id($this->po_detail_id);
		echo "<br>Existing received qty in PO : " . $po_d_i->received_quantity . '. Qty in new receipt line : ' . $this->transaction_quantity;
		$po_d->received_quantity = $this->transaction_quantity + $po_d_i->received_quantity;
		$po_d->po_detail_id = $po_d_i->po_detail_id;
		$po_d->audit_trial();
		$po_d->save();
		echo "<br>PO Received Quantity is Sucessfully Updated ";
		if (!empty($this->item_id)) {
		 try {
			$this->_create_inv_transactions();
			echo "<br>INV Transaction Lines are Sucessfully Created ";
		 } catch (Exception $e) {
			$update_satus = -99;
			echo "<br>Creating the transaction lines failed @ inv_receipt_line after save" . $e->getMessage();
		 }
		}
	 } catch (Exception $e) {
		$update_satus = -99;
		echo "<br>PO Detail Update Failed! Receipt Line Error @ " . __LINE__ . $e->getMessage();
	 }
	 if ($update_satus > 0) {
		$this->status = 'Success';
	 } else {
		$this->status = 'Error';
	 }
	 $this->save();
	}
 }

 public function _before_save() {
	//if there is a line id in the form then return 10 as no changes to paid lines are allowed
	if ($this->inv_receipt_line_id) {
	 echo "<br>You can't update any Receipt line. Reverse the transaction, if required ";
	 return 10;
	} else if (((empty($this->org_id) || (empty($this->transaction_type_id))) && (!empty($this->inv_receipt_header_id)))) {
	 $invrh = new inv_receipt_header();
	 $invrh_i = $invrh->findBy_id($this->inv_receipt_header_id);
	 $this->org_id = $invrh_i->org_id;
	 $this->transaction_type_id = $invrh_i->transaction_type_id;
	}
 }

 private function _create_inv_transactions() {
	$inv_transaction = new inv_transaction();

	switch ($this->transaction_type_id) {
	 case 5 :
		$inv_transaction->org_id = $this->org_id;
		$inv_transaction->to_subinventory_id = $this->subinventory_id;
		if (!empty($this->locator_id)) {
		 $inv_transaction->to_locator_id = $this->locator_id;
		}
		$inv_transaction->quantity = $this->transaction_quantity;
		$inv_transaction->item_id = $this->item_id;
		$inv_transaction->transaction_type_id = $this->transaction_type_id;
		$inv_transaction->po_detail_id = $this->po_detail_id;
		$inv_transaction->reference_type = 'table';
		$inv_transaction->reference_key_name = 'po_header';
		$inv_transaction->reference_key_value = $this->po_header_id;
		$inv_transaction->document_type = 'PO';
		$inv_transaction->document_number = $this->po_number;
		$inv_transaction->audit_trial();
		$inv_transaction->save();
		$update_result = $inv_transaction->_after_save();
		break;

	 case 51 :
		$inv_transaction->org_id = $this->org_id;
		$inv_transaction->from_subinventory_id = $this->subinventory_id;
		if (!empty($this->locator_id)) {
		 $inv_transaction->from_locator_id = $this->locator_id;
		}
		$inv_transaction->quantity = $this->transaction_quantity;
		$inv_transaction->item_id = $this->item_id;
		$inv_transaction->transaction_type_id = $this->transaction_type_id;
		$inv_transaction->po_detail_id = $this->po_detail_id;
		$inv_transaction->reference_type = 'table';
		$inv_transaction->reference_key_name = 'po_header';
		$inv_transaction->reference_key_value = $this->po_header_id;
		$inv_transaction->document_type = 'PO';
		$inv_transaction->document_number = $this->po_number;
		$inv_transaction->audit_trial();
		$inv_transaction->save();
		$update_result = $inv_transaction->_after_save();
		break;

	 default:
		break;
	}
 }

 private function _highest_line_number_from_header() {
	global $db;
	$sql = " SELECT max(line_number) as line_number FROM " . self::$table_name;
	$sql .= " WHERE ap_payment_header_id= :ap_payment_header_id ";
	$param_a = ['ap_payment_header_id'];
	$value_a = ['ap_payment_header_id' => $this->ap_payment_header_id];
	$result = $db->findBy_sql($sql, $param_a, $value_a);
	return !empty($result) ? array_pop($result) : 0;
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

//end of inv_receipt_line class
?>