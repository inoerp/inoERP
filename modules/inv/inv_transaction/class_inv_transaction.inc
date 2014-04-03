<?php

class inv_transaction extends dbObject {

 protected static $table_name = "inv_transaction";
 public static $primary_column = "inv_transaction_id";
 public static $key_column = 'item_id';
 public static $module = "inv";
 public static $allowed_inv_transactions = [
		 '1' => 'Miscellaneous Issue',
		 '2' => 'Miscellaneous Receipt',
		 '3' => 'Subinventory Transfer'
 ];
 public $field_a = [
		 'inv_transaction_id',
		 'transaction_type_id',
		 'org_id',
		 'status',
		 'receipt_line_id',
		 'item_number',
		 'item_id',
		 'uom_id',
		 'lot_number',
		 'serial_number',
		 'logical_transaction_cb',
		 'document_type',
		 'document_number',
		 'document_id',
		 'wip_wo_bom_id',
		 'po_header_id',
		 'po_line_id',
		 'po_detail_id',
		 'reason',
		 'reference_type',
		 'reference_key_name',
		 'reference_key_value',
		 'description',
		 'from_org_id',
		 'from_subinventory_id',
		 'from_locator_id',
		 'quantity',
		 'from_account_id',
		 'to_org_id',
		 'to_subinventory_id',
		 'to_locator_id',
		 'to_account_id',
		 'unit_cost',
		 'costed_amount',
		 'transfer_to_gl_cb',
		 'ef_id',
		 'transaction_rev_enabled_cb',
		 'rev_start_number',
		 'created_by',
		 'creation_date',
		 'last_update_by',
		 'last_update_date',
 ];
 //variables used for showing data

 public $initial_search = [
		 "inv_transaction_id",
		 "transaction_type_id",
		 'status',
		 "item_id",
		 "org_id",
		 "item_number",
		 "creation_date",
		 "document_type",
		 "document_number"
 ];
 public $column = [
		 "inv_transaction_id",
		 "transaction_type_id",
		 'status',
		 "item_number",
		 "document_type",
		 "document_number",
		 "reason",
		 "reference",
		 "created_by",
		 "creation_date"];
 public $account = [
		 "from_account_id",
		 "to_account_id",
		 "account_id"];
 public $checkbox = [
		 "logical_transaction_cb",
		 "transfer_to_gl_cb",
		 "transaction_rev_enabled_cb"];
 public $fields_inForm_notInDataBase = [
		 "account_id",
		 'item_description'
 ];
 public $fields_inHeader_needsToBeInserted_inPOST = [
		 "org_id",
		 "transaction_type_id"
 ];
 public $requiredField = [
		 "item_number",
		 "uom_id",
		 "quantity",
		 "org_id",
		 "item_id",
		 "transaction_type_id"
 ];
 public $search = [
		 '_show_view_path' => 1,
 ];
 public $pageTitle = " Transaction - Create & View Transactions"; //page Title
 public $option_lists = [
		 'inv_transaction_class' => 'TRANSACTION_TYPE_CLASS'
 ];
 public $inv_transaction_id;
 public $transaction_type_id;
 public $org_id;
 public $status;
 public $receipt_line_id;
 public $item_number;
 public $item_id;
 public $uom_id;
 public $lot_number;
 public $serial_number;
 public $logical_transaction_cb;
 public $document_type;
 public $document_number;
 public $document_id;
 public $wip_wo_bom_id;
 public $po_header_id;
 public $po_line_id;
 public $po_detail_id;
 public $reason;
 public $reference_type;
 public $reference_key_name;
 public $reference_key_value;
 public $description;
 public $from_org_id;
 public $from_subinventory_id;
 public $from_locator_id;
 public $quantity;
 public $from_account_id;
 public $to_org_id;
 public $to_subinventory_id;
 public $to_locator_id;
 public $to_account_id;
 public $unit_cost;
 public $costed_amount;
 public $transfer_to_gl_cb;
 public $ef_id;
 public $transaction_rev_enabled_cb;
 public $rev_start_number;
 public $created_by;
 public $creation_date;
 public $last_update_by;
 public $last_update_date;
 public $time;
 public $msg;
 public $item_description;
 public $wip_wo_header_id;
 public $wo_number;
 public $available_quantity;
 public $transacted_quantity;
 public $total_quantity;

 public function __set($name, $value) {
	$this->$name = $value;
 }

 Public static function inv_transaction_class() {
	$option_header = option_header::find_by_name('TRANSACTION_TYPE_CLASS');
	$inv_transaction_class = option_line::find_by_option_id($option_header->option_id);
	return $inv_transaction_class;
 }

 public function _before_showing() {

	if (!(empty($this->transaction_type_id))) {
	 switch ($this->transaction_type_id) {
		case 1 :
		 $this->account_id = $this->to_account_id;
		 break;

		case 2 :
		 $this->account_id = $this->from_account_id;
		 break;

		default:
		 if (!empty($this->to_account_id)) {
			$this->account_id = $this->to_account_id;
		 } else {
			$this->account_id = $this->from_account_id;
		 }

		 break;
	 }
	}

	if (!empty($this->to_account_id)) {
	 $this->account_id = $this->to_account_id;
	} else {
	 $this->account_id = $this->from_account_id;
	}
 }

 public function _before_submit() {
	if (!(empty($this->transaction_type_id))) {
	 switch ($this->transaction_type_id) {
		case 1 :
		 array_push($this->requiredField, 'to_account_id');
		 array_push($this->requiredField, 'from_subinventory_id');
		 $this->from_account_id = null;
		 $this->to_account_id = $this->account_id;
		 break;

		case 2 :
		 array_push($this->requiredField, 'from_account_id');
		 array_push($this->requiredField, 'to_subinventory_id');
		 $this->from_account_id = $this->account_id;
		 $this->to_account_id = null;
		 break;

		case 3 :
		 array_push($this->requiredField, 'to_subinventory_id');
		 array_push($this->requiredField, 'from_subinventory_id');
		 break;

		case 6 :
		 array_push($this->requiredField, 'wip_wo_bom_id');
		 break;

		default:
		 break;
	 }
	}
 }

 public function _after_save() {
	global $db;
	$onhand = new onhand();

	switch ($this->transaction_type_id) {
	 case 1 :
		$onhand->setProperty('_from_org_id', $this->org_id);
		$onhand->setProperty('_from_subinventory_id', $this->from_subinventory_id);
		$onhand->setProperty('_from_locator_id', $this->from_locator_id);
		$onhand->setProperty('_transaction_quantity', $this->quantity);
		$onhand->item_id = $this->item_id;
		$update_result = $onhand->updateOnhand();
		break;

	 case 2 :
	 case 5 :
		$onhand->setProperty('_to_org_id', $this->org_id);
		$onhand->setProperty('_to_subinventory_id', $this->to_subinventory_id);
		$onhand->setProperty('_to_locator_id', $this->to_locator_id);
		$onhand->setProperty('_transaction_quantity', $this->quantity);
		$onhand->item_id = $this->item_id;
		$update_result = $onhand->updateOnhand();
		break;

	 case 3 :
		$onhand->setProperty('_from_subinventory_id', $this->from_subinventory_id);
		$onhand->setProperty('_from_locator_id', $this->from_locator_id);
		$onhand->setProperty('_to_subinventory_id', $this->to_subinventory_id);
		$onhand->setProperty('_to_locator_id', $this->to_locator_id);
		$onhand->setProperty('_transaction_quantity', $this->quantity);
		$onhand->item_id = $this->item_id;
		$onhand->org_id = $this->org_id;
		$update_result = $onhand->updateOnhand();
		break;

	 default:
		break;
	}

	if ($update_result > 0) {
	 $this->status = 'Success';
	} else {
	 $this->status = 'Error';
	}
	$this->save();

	//update the item issue quantity on WO
	if (($this->transaction_type_id == 6) && (!empty($this->wip_wo_bom_id))) {
	 //update issued quantity
	 $wo_bom = wip_wo_bom::find_by_id($this->wip_wo_bom_id);
	 $update_wo_bom_class = new wip_wo_bom();
	 foreach (wip_wo_bom::$field_array as $key => $value) {
		$update_wo_bom_class->$value = $wo_bom->$value;
	 }

	 $update_wo_bom_class->issued_quantity += $this->quantity;
	 $update_wo_bom_class->save();
	}

	//update the item return quantity on WO
	if (($this->transaction_type_id == 7) && (!empty($this->wip_wo_bom_id))) {
	 //update issued quantity
	 $wo_bom = wip_wo_bom::find_by_id($this->wip_wo_bom_id);
	 $update_wo_bom_class = new wip_wo_bom();
	 foreach (wip_wo_bom::$field_array as $key => $value) {
		$update_wo_bom_class->$value = $wo_bom->$value;
	 }

	 $update_wo_bom_class->issued_quantity -= $this->quantity;

	 $update_wo_bom_class->save();
	}

	//update on WO Completion
	if (($this->transaction_type_id == 11) && (!empty($this->document_id))) {
	 //update issued quantity
	 $wip_wo = wip_wo_header::find_by_id($this->document_id);
	 $update_wip_wo = new wip_wo_header;
	 foreach ($wip_wo::$field_array as $key => $value) {
		$update_wip_wo->$value = $wip_wo->$value;
	 }
	 $update_wip_wo->completed_quantity += $this->quantity;
	 $time = time();
	 $update_wip_wo->last_unit_completed_date = strftime("%Y-%m-%d %H:%M:%S", $time);
	 if (empty($wip_wo->first_unit_completed_date)) {
		$update_wip_wo->first_unit_completed_date = $update_wip_wo->last_unit_completed_date;
	 }
	 if ($update_wip_wo->completed_quantity == $update_wip_wo->quantity) {
		$update_wip_wo->set_wo_status = 'COMPLETED';
	 }
	 $update_wip_wo->save();
	 $last_wo_routing_line = wip_wo_routing_line::find_lastOperation_by_wip_wo_headerId($this->document_id);
	 $update_wo_routing_line = new wip_wo_routing_line;
	 foreach ($last_wo_routing_line::$field_array as $key => $value) {
		$update_wo_routing_line->$value = $last_wo_routing_line->$value;
	 }
	 $update_wo_routing_line->tomove_quantity = $update_wo_routing_line->tomove_quantity - $this->quantity;
	 $update_wo_routing_line->save();

	 /* Start material transaction - issue all WIP Assembly Completion materials */
	 $all_bom_lines = wip_wo_bom::find_by_wip_wo_headerId($this->document_id);
	 $org_id = $this->org_id;
	 $quantity = $this->quantity;
	 $document_number = $this->document_number;
	 $document_id = $this->document_id;
	 foreach ($all_bom_lines as $bomline) {
		if ($bomline->wip_supply_type == 'ASSEMBLY_PULL') {
		 $inv_transaction = new inv_transaction;
		 $inv_transaction->org_id = $org_id;
		 $inv_transaction->transaction_type_id = 6;
		 $inv_transaction->item_id = $bomline->component_item_id;
		 $item = item::find_by_id($inv_transaction->item_id);
		 $inv_transaction->uom_id = $item->uom_id;
		 $inv_transaction->item_number = $item->item_number;
		 $inv_transaction->quantity = $bomline->usage_quantity * $quantity;
		 $inv_transaction->from_subinventory_id = $bomline->supply_sub_inventory;
		 $inv_transaction->from_locator_id = $bomline->supply_locator;
		 $inv_transaction->document_type = 'Work Order';
		 $inv_transaction->document_number = $document_number;
		 $inv_transaction->reference = 'wip_wo_header_id';
		 $inv_transaction->wip_wo_bom_id = $bomline->wip_wo_bom_id;
		 $inv_transaction->document_id = $document_id;
		 $time = time();
		 $inv_transaction->creation_date = strftime("%Y-%m-%d %H:%M:%S", $time);
		 $inv_transaction->created_by = $_SESSION['user_name'];
		 $inv_transaction->last_update_date = $inv_transaction->creation_date;
		 $inv_transaction->last_update_by = $inv_transaction->created_by;
		 $inv_transaction->save();
		 $inv_transaction->_after_save();
		}
	 }
	}

	//update on WO Return
	if (($this->transaction_type_id == 13) && (!empty($this->document_id))) {
	 //update issued quantity
	 $wip_wo = wip_wo_header::find_by_id($this->document_id);
	 $update_wip_wo = new wip_wo_header;
	 foreach ($wip_wo::$field_array as $key => $value) {
		$update_wip_wo->$value = $wip_wo->$value;
	 }
	 $update_wip_wo->completed_quantity -= $this->quantity;
	 $update_wip_wo->save();

	 $last_wo_routing_line = wip_wo_routing_line::find_lastOperation_by_wip_wo_headerId($this->document_id);
	 $update_wo_routing_line = new wip_wo_routing_line;
	 foreach ($last_wo_routing_line::$field_array as $key => $value) {
		$update_wo_routing_line->$value = $last_wo_routing_line->$value;
	 }
	 $update_wo_routing_line->tomove_quantity += $this->quantity;
	 $update_wo_routing_line->save();

	 /* Start material transaction - issue all WIP Assembly Completion materials */
	 $all_bom_lines = wip_wo_bom::find_by_wip_wo_headerId($this->document_id);
	 $org_id = $this->org_id;
	 $quantity = $this->quantity;
	 $document_number = $this->document_number;
	 $document_id = $this->document_id;
	 foreach ($all_bom_lines as $bomline) {
		if ($bomline->wip_supply_type == 'ASSEMBLY_PULL') {
		 $inv_transaction = new inv_transaction;
		 $inv_transaction->org_id = $org_id;
		 $inv_transaction->transaction_type_id = 7;
		 $inv_transaction->item_id = $bomline->component_item_id;
		 $item = item::find_by_id($inv_transaction->item_id);
		 $inv_transaction->uom_id = $item->uom_id;
		 $inv_transaction->item_number = $item->item_number;
		 $inv_transaction->quantity = $bomline->usage_quantity * $quantity;
		 $inv_transaction->to_subinventory_id = $bomline->supply_sub_inventory;
		 $inv_transaction->to_locator_id = $bomline->supply_locator;
		 $inv_transaction->document_type = 'Work Order';
		 $inv_transaction->document_number = $document_number;
		 $inv_transaction->reference = 'wip_wo_header_id';
		 $inv_transaction->wip_wo_bom_id = $bomline->wip_wo_bom_id;
		 $inv_transaction->document_id = $document_id;
		 $time = time();
		 $inv_transaction->creation_date = strftime("%Y-%m-%d %H:%M:%S", $time);
		 $inv_transaction->created_by = $_SESSION['user_name'];
		 $inv_transaction->last_update_date = $inv_transaction->creation_date;
		 $inv_transaction->last_update_by = $inv_transaction->created_by;
		 $inv_transaction->save();
		 $inv_transaction->_after_save();
		}
	 }
	}
 }

}

//end of inv_transaction class
?>