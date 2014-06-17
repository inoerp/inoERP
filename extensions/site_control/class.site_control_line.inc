<?php

class site_control_line extends dbObject {

 public static $table_name = "site_control_line";
 public static $field_array = [
		 'bom_header_id',
		 'site_control_line_id',
		 'bom_sequence',
		 'routing_sequence',
		 'component_item_id',
		 'usage_basis',
		 'usage_quantity',
		 'auto_request_material_cb',
		 'effective_start_date',
		 'effective_end_date',
		 'eco_number',
		 'eco_implemented_cb',
		 'planning_percentage',
		 'yield',
		 'include_in_cost_rollup_cb',
		 'wip_supply_type',
		 'supply_sub_inventory',
		 'supply_locator',
		 "ef_id",
		 'created_by',
		 'creation_date',
		 'last_update_by',
		 'last_update_date'
 ];
 //variables used for showing data

 public static $initial_search_array = [
 ];
 public static $column_array = [
 ];
 public static $account_array = [
 ];
 public static $checkbox_array = [
 ];
 public static $fields_inForm_notInDataBase = [
		 "component_item_number",
		 "component_description",
		 "component_uom"
 ];
 public static $fields_inHeader_needsToBeInserted_inPOST = [
		 "bom_header_id"
 ];
 public static $requiredField_array = [
		 'bom_sequence',
		 'routing_sequence',
		 'component_item_id',
		 'usage_quantity'
 ];
 public static $primary_column = "site_control_line_id";
 public $site_control_line_id;
 public $bom_header_id;
 public $bom_sequence;
 public $routing_sequence;
 public $component_item_id;
 public $usage_basis;
 public $usage_quantity;
 public $auto_request_material_cb;
 public $effective_start_date;
 public $effective_end_date;
 public $eco_number;
 public $eco_implemented_cb;
 public $planning_percentage;
 public $yield;
 public $include_in_cost_rollup_cb;
 public $wip_supply_type;
 public $supply_sub_inventory;
 public $supply_locator;
 public $created_by;
 public $creation_date;
 public $last_update_by;
 public $last_update_date;
 public $time;
 public $msg;
 public $component_item_number;
 public $component_description;
 public $component_uom;

 public function __set($name, $value) {
	$this->$name = $value;
 }

// Public static function inv_transaction_class() {
//	$option_header = option_header::find_by_name('TRANSACTION_TYPE_CLASS');
//	$inv_transaction_class = option_line::find_by_option_id($option_header->option_id);
//	return $inv_transaction_class;
// }

 public static function find_all_by_bomHeaderId($bom_headerId) {

	$sql = " Select * from ";
	$sql .= self::$table_name;
	$sql .= " WHERE bom_header_id = '{$bom_headerId}'";

	$all_site_control_lines = self::find_by_sql($sql);

	return $all_site_control_lines;
 }

 public function _before_showing() {
	
 }

 public function _before_submit() {
	
 }

// public function save() {
//	global $error;
//	$poDetail_status = po_detail::update_poDetail_status($this->po_detail_id, $this->received_quantity);
//	if ($poDetail_status == 1) {
//	 $onhandUpdate_result = onhand::update_onhand($this->item_id, $this->org_id, $this->uom_id, $this->received_quantity, '', '', '', $this->org_id, $this->subinventory_id, $this->locator_id, $this->lot_number, $this->serial_number);
//	 if (((!empty($this->subinventory_id)) && ($onhandUpdate_result['to_update_staus'] == 1))) {
//		$this->create();
//	 } else {
//		$error['po_onahand_status'] = "Error in updating onHand Quantity";
//	 }
//	} else {
//	 $error['po_detail_status'] = "Error in updating PO detail status";
//	 $this->msg = 0;
//	}
////	if (!empty($error)) {
////	 foreach ($error as $key => $value) {
////		echo "<br/><br/> $key : $value ";
////	 }
////	}
//	ino_print_error($error);
//	return $this->msg;
// }

 public function _after_save() {
	
 }

}

//end of inv_transaction class
?>



