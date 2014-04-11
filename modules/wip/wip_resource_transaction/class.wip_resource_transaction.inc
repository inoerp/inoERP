<?php

class wip_resource_transaction extends dbObject {

 protected static $table_name = "wip_resource_transaction";
 public static $dependent_classes = ['wip_wo_bom', 'wip_wo_routing_line', 'wip_wo_routing_detail'];
 public static $primary_column = "wip_resource_transaction_id";
 public static $key_column = 'wip_wo_routing_detail_id';
 public static $module = "wip";
//  data base variables as stored database column name
 public $field_a = [
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
 public $initial_search = [
		 'wip_resource_transaction_id',
		 'wip_wo_header_id',
		 'org_id',
		 'wo_number',
		 'item_number',
		 'item_id'
 ];
 public $column = [
		 'wip_resource_transaction_id',
		 'wip_wo_header_id',
		 'org_id',
		 'wo_number',
		 'item_number',
		 'item_id',
		 'transaction_date',
		 'transaction_quantity'
 ];
 public $account = [
		 'scrap_account_id'
 ];
 public $fields_inForm_notInDataBase = [
		 'remaining_quantity',
		 'item_id',
		 'item_number',
		 "item_description",
		 "uom",
		 'available_quantity',
		 'total_quantity',
		 'department_id'
 ];
 public $fields_inHeader_needsToBeInserted_inPOST = [
		 'org_id',
		 'transaction_type',
		 'transaction_date'
 ];
 public $requiredField = [
		 'wip_wo_routing_line_id',
		 'wip_wo_routing_detail_id',
		 'wip_wo_header_id',
		 'org_id',
		 'transaction_type',
		 'transaction_date',
		 'transaction_quantity'
 ];
 
  public $search = [
		 '_show_update_path' => 1,
		 '_show_view_path' => 1,
 ];
 public $pageTitle = " Resource Trnx - WIP Work Order  Resource Transaction "; //page Title
 public $option_lists = [
//		 'wip_wo_type' => 'WIP_WO_TYPE',
//		 'wip_wo_status' => 'WIP_WO_STATUS',
 ];
 
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
	 $wip_wo_routing_detail = new wip_wo_routing_detail();
	 $wip_wo_routing_detail_i = $wip_wo_routing_detail->findBy_id($this->wip_wo_routing_detail_id);
	 $wip_wo_routing_detail->wip_wo_routing_detail_id = $wip_wo_routing_detail_i->wip_wo_routing_detail_id;
	 $wip_wo_routing_detail->applied_quantity = $wip_wo_routing_detail_i->applied_quantity + $this->transaction_quantity;
	 try {
		$wip_wo_routing_detail->audit_trial();
		$wip_wo_routing_detail->save();
		echo "<br> The resource quantity is sucessfully applied ";
	 } catch (Exception $e) {
		echo "<br> Resource quantity application " . $e->getMessage();
	 }
	}
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

 public function _before_save() {
	
 }

}

//end of resource class
?>



