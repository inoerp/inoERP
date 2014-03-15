<?php

class inv_transaction extends transaction_type {

 protected static $table_name = "inv_transaction";
 public static $field_array = [
		 "inv_transaction_id",
		 "transaction_type_id",
		 "item_id",
		 "org_id",
		 "item_number",
		 "uom_id",
		 "lot_number",
		 "serial_number",
		 "logical_transaction_cb",
		 "document_type",
		 "document_number",
		 "document_id",
		 "reason",
		 "reference",
		 "description",
		 "from_org_id",
		 "from_subinventory_id",
		 "from_locator_id",
		 "quantity",
		 "from_account_id",
		 "to_org_id",
		 "to_subinventory_id",
		 "to_locator_id",
		 "to_account_id",
		 "unit_cost",
		 "costed_amount",
		 "transfer_to_gl_cb",
		 "ef_id",
		 'wip_wo_bom_id',
		 "transaction_rev_enabled_cb",
		 "rev_start_number",
		 "created_by",
		 "creation_date",
		 "last_update_by",
		 "last_update_date"];
 //variables used for showing data

 public static $initial_search_array = [
		 "inv_transaction_id",
		 "transaction_type_id",
		 "item_id",
		 "org_id",
		 "item_number",
		 "creation_date",
		 "document_type",
		 "document_number"
 ];
 public static $column_array = [
		 "inv_transaction_id",
		 "transaction_type_id",
		 "item_number",
		 "document_type",
		 "document_number",
		 "reason",
		 "reference",
		 "created_by",
		 "creation_date"];
 public static $account_array = ["from_account_id",
		 "to_account_id",
		 "account_id"];
 public static $checkbox_array = ["logical_transaction_cb",
		 "transfer_to_gl_cb",
		 "transaction_rev_enabled_cb"];
 public static $fields_inForm_notInDataBase = [
		 "account_id",
		 'item_description'
 ];
 public static $fields_inHeader_needsToBeInserted_inPOST = [
		 "org_id",
		 "transaction_type_id"
 ];
 public static $requiredField_array = [
		 "item_number",
		 "uom_id",
		 "quantity",
		 "org_id",
		 "item_id",
		 "transaction_type_id"];
 public static $primary_column = "inv_transaction_id";
 public $inv_transaction_id;
 public $transaction_type_id;
 public $org_id;
 public $item_id;
 public $item_description_ref;
 public $item_revision_ref;
 public $uom_id;
 public $item_number;
 public $lot_number;
 public $serial_number;
 public $reason;
 public $reference;
 public $description;
 public $from_org_id;
 public $from_subinventory_id;
 public $from_locator_id;
 public $quantity;
 public $from_account_id;
 public $account;
 public $account_id;
 public $unit_cost;
 public $to_org_id;
 public $to_subinventory_id;
 public $to_locator_id;
 public $to_account_id;
 public $costed_amount;
 public $transfer_to_gl_cb;
 public $logical_transaction_cb;
 public $document_type;
 public $document_number;
 public $document_id;
 public $ef_id;
 public $transaction_rev_enabled_cb;
 public $rev_start_number;
 public $wip_wo_bom_id;
 public $po_detail_id;
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
		 array_push(self::$requiredField_array, 'to_account_id');
		 array_push(self::$requiredField_array, 'from_subinventory_id');
		 $this->from_account_id = "";
		 $this->to_account_id = $this->account_id;
		 break;

		case 2 :
		 array_push(self::$requiredField_array, 'from_account_id');
		 array_push(self::$requiredField_array, 'to_subinventory_id');
		 $this->from_account_id = $this->account_id;
		 $this->to_account_id = "";
		 break;

		case 3 :
		 array_push(self::$requiredField_array, 'to_subinventory_id');
		 array_push(self::$requiredField_array, 'from_subinventory_id');
		 break;

		case 6 :
		 array_push(self::$requiredField_array, 'wip_wo_bom_id');
		 break;

		default:
		 break;
	 }
	}
 }

 public function save() {
	$update_result = onhand::update_onhand($this->item_id, $this->org_id, $this->uom_id, $this->quantity, $this->from_org_id, $this->from_subinventory_id, $this->from_locator_id, $this->to_org_id, $this->to_subinventory_id, $this->to_locator_id, $this->lot_number, $this->serial_number);

	if (((!empty($this->to_subinventory_id)) && ($update_result['to_update_staus'] == 1)) || ((!empty($this->from_subinventory_id)) && ($update_result['from_update_staus'] == 1))) {
	 $this->create();
	} else {
	 $this->msg = 0;
	}
	return $this->msg;
 }

 public function _after_save() {
	global $db;

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