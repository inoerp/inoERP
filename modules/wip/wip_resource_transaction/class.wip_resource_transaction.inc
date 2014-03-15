<?php

class wip_resource_transaction extends dbObject {

 protected static $table_name = "wip_resource_transaction";
//  data base variables as stored database column name
 public static $field_array = [
		 'wip_resource_transaction_id',
		 'wip_wo_routing_line_id',
		 'wip_wo_routing_detail_id',
		 'wip_wo_header_id',
		 'org_id',
		 'transaction_type',
		 'transaction_date',
		 'transaction_quantity',
		 'reason',
		 'reference',
		 'scrap_account_id',
		 'sales_order_header_id',
		 'sales_order_line_id',
		 'created_by',
		 'creation_date',
		 'last_update_by',
		 'last_update_date'
 ];
//variables used for showing data
 public static $initial_search_array = [
		 'wip_resource_transaction_id',
		 'wip_wo_header_id',
		 'org_id',
		 'wo_number',
		 'item_number',
		 'item_id'
 ];
 public static $column_array = [
		 'wip_resource_transaction_id',
		 'wip_wo_header_id',
		 'org_id',
		 'wo_number',
		 'item_number',
		 'item_id',
		 'transaction_date',
		 'transaction_quantity'
 ];
 public static $account_array = [
		 'scrap_account_id'
 ];
 public static $checkbox_array = [
 ];
 public static $fields_inForm_notInDataBase = [
		 'remaining_quantity',
		 "item_description",
		 "uom",
		 'available_quantity',
		 'total_quantity',
		 'department_id'
 ];
 public static $fields_inHeader_needsToBeInserted_inPOST = [
		 'org_id',
		 'transaction_type',
		 'transaction_date'
 ];
 public static $base_encoded_array = [];
 public static $requiredField_array = [
		 'wip_wo_routing_line_id',
		 'wip_wo_routing_detail_id',
		 'wip_wo_header_id',
		 'org_id',
		 'transaction_type',
		 'transaction_date',
		 'transaction_quantity'
 ];
 public static $primary_column = "wip_resource_transaction_id";
 public $wip_resource_transaction_id;
 public $wip_wo_header_id;
 public $wip_wo_routing_line_id;
 public $wip_wo_routing_detail_id;
 public $org_id;

 public $transaction_type;
 public $transaction_date;
 public $transaction_quantity;
 public $reason;
 public $reference;
 public $scrap_account_id;
 public $sales_order_header_id;
 public $sales_order_line_id;
 public $created_by;
 public $creation_date;
 public $last_update_by;
 public $last_update_date;
 public $time;
 public $msg;
 public $remaining_quantity;
 public $item_description;
 public $uom;
 public $total_quantity;
 public $available_quantity;
 public $department_id;
  public $wo_number;
 public $item_number;
 public $item_id;
 public $routing_sequence;

 Public static function wip_transactions() {
	$option_header = option_header::find_by_name('WIP_TRANSACTIONS');
	$wip_transactions = option_line::find_by_option_id($option_header->option_header_id);
	return $wip_transactions;
 }

 public function _after_save() {
	global $db;
	//Insert in WIP WO BOM - item issues for operational pull
	if ((!empty($this->wip_resource_transaction_id)) && (!(empty($this->wip_wo_routing_detail_id))) && (!(empty($this->transaction_quantity)))) {
	 
	 $wip_wo_routing_detail = wip_wo_routing_detail::find_by_id($this->wip_wo_routing_detail_id);
	 $applied_quantity = $wip_wo_routing_detail->applied_quantity;
	 $wip_wo_routing_detail->applied_quantity = $applied_quantity + $this->transaction_quantity;
//	 echo '<pre>';
//	 print_r($wip_wo_routing_detail);
	 $this->msg = $wip_wo_routing_detail->save();
 }
 return $this->msg;
 }

 public function save() {
	$primary_column = static::$primary_column;
	if (empty($this->$primary_column)) {
	 $this->create();
	} else {
	 echo '<div class="message"> You are not allowed to update a completed move transaction!</div>';
	}
	return $this->msg;
 }

 public function _before_showing() {
	
 }

 public function _before_submit() {
	
 }

}

//end of resource class
?>



