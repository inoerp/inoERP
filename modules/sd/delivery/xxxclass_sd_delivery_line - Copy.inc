<?php

class sd_delivery_line extends dbObject {

 protected static $table_name = "sd_delivery_line";
 public static $primary_column = "sd_delivery_line_id";
 public static $parent_primary_column = "sd_delivery_header_id";
 public static $multi_select_template_path = "modules/sd/delivery/delivery_template.php";
 
 public static $multi_search_primary_column = "sd_delivery_header_id"; //this value is used in multi search hidden value
 public static $key_column = 'item_description';
 public static $module = "inv";
 public $field_a = [
		 'sd_delivery_line_id',
		 'sd_delivery_header_id',
		 'sd_so_header_id',
		 'sd_so_line_id',
		 'shipping_org_id',
		 'item_id',
		 'quantity',
		 'staging_subinventory_id',
		 'staging_locator_id',
		 'delivery_status',
		 'picking_date',
		 'actual_ship_date',
		 'reference_doc_type',
		 'reference_doc_number',
		 'line_uom_id',
		 'volume_uom_id',
		 'total_volume',
		 'weight_uom_id',
		 'total_weight',
		 'created_by',
		 'creation_date',
		 'last_update_by',
		 'last_update_date',
 ];
 //variables used for showing data

 public $account = [
 ];
 public $fields_inForm_notInDataBase = [
		 'so_line_shipped_quantity',
		 'so_number',
		 'so_line_number',
		 'shipment_number',
		 'item_number',
		 'item_description',
		 'line_uom_id',
		 'ar_customer_id',
		 'ar_customer_number',
		 'ar_customer_name',
		 'ar_customer_site_id',
		 'ar_customer_site_number',
		 'ar_customer_site',
		 'multi_action_class_pc',
		 'multi_action_class_pc_value',
		 'action'
 ];
 public $fields_inHeader_needsToBeInserted_inPOST = [
		 "sd_delivery_header_id",
		 'org_id',
		 'so_line_number',
		 'shipped_quantity',
		 'quantity'
 ];
 public $requiredField = [
		 'sd_so_header_id',
		 'sd_so_line_id',
		 'staging_subinventory_id',
		 'item_description',
		 'line_uom_id',
		 'quantity'
 ];
 public $sd_delivery_line_id;
 public $sd_delivery_header_id;
 public $sd_so_header_id;
 public $sd_so_line_id;
 public $shipping_org_id;
 public $item_id;
 public $quantity;
 public $staging_subinventory_id;
 public $staging_locator_id;
 public $delivery_status;
 public $picking_date;
 public $actual_ship_date;
 public $reference_doc_type;
 public $reference_doc_number;
 public $line_uom_id;
 public $volume_uom_id;
 public $total_volume;
 public $weight_uom_id;
 public $total_weight;
 public $created_by;
 public $creation_date;
 public $last_update_by;
 public $last_update_date;
 public $line_number;
 public $shipment_number;
 public $item_number;
 public $uom_id;
 public $ar_customer_id;
 public $ar_customer_number;
 public $ar_customer_name;
 public $ar_customer_site_id;
 public $ar_customer_site_number;
 public $ar_customer_site_name;
 public $so_number;
 public $so_line_number;
 public $shipped_quantity;
 public $multi_action_class_pc;
 public $multi_action_class_pc_value;
 public $action;
 public $item_description;

 public function _after_save() {

	if (!empty($this->sd_delivery_line_id)) {
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
			echo "<br>Creating the transaction lines failed @ sd_delivery_line after save" . $e->getMessage();
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
	if ((empty($this->line_number)) && (!empty($this->sd_delivery_header_id))) {
	 $current_highest_line_no = $this->_highest_line_number_from_header();
	 $this->line_number = $current_highest_line_no->line_number + 1;
	}

	if (((empty($this->org_id) || (empty($this->transaction_type_id))) && (!empty($this->sd_delivery_header_id)))) {
	 $invrh = new sd_delivery_header();
	 $invrh_i = $invrh->findBy_id($this->sd_delivery_header_id);
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
	$sql .= " WHERE sd_delivery_header_id = :sd_delivery_header_id ";
	$param_a = ['sd_delivery_header_id'];
	$value_a = ['sd_delivery_header_id' => $this->sd_delivery_header_id];
	$result = $db->findBy_sql($sql, $param_a, $value_a);
	return !empty($result) ? array_pop($result) : 0;
 }

 public function multi_select_input_fields() {
	$multi_select_input = [
	];
	return $multi_select_input;
 }

 public function multi_select_hidden_fields() {
	$multi_select_hidden = [
			'action_class_name',
			'mode',
			'action',
			'show_block',
	];

	return $multi_select_hidden;
 }

}

//end of sd_delivery_line class
?>