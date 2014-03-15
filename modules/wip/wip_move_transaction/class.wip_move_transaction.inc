<?php

class wip_move_transaction extends dbObject {

 protected static $table_name = "wip_move_transaction";
//  data base variables as stored database column name
 public static $field_array = [
		 'wip_move_transaction_id',
		 'wip_wo_header_id',
//		 'wo_routing_line_id',
//		 'wo_routing_detail_id',
		 'org_id',
		 'wo_number',
		 'item_number',
		 'item_id',
		 'from_routing_sequence',
		 'to_routing_sequence',
		 'from_operation_step',
		 'to_operation_step',
		 'transaction_type',
		 'transaction_date',
		 'move_quantity',
		 'reason',
		 'reference',
		 'scrap_account_id',
		 'sales_order_header_id',
		 'sales_order_line_id',
		 'created_by',
		 'creation_date',
		 'last_update_by',
		 'last_update_date',
 ];
//variables used for showing data
 public static $initial_search_array = [
		 'wip_move_transaction_id',
		 'wip_wo_header_id',
		 'org_id',
		 'wo_number',
		 'item_number',
		 'item_id'
 ];
 public static $column_array = [
		 'wip_move_transaction_id',
		 'wip_wo_header_id',
		 'org_id',
		 'wo_number',
		 'item_number',
		 'item_id',
		 'from_routing_sequence',
		 'to_routing_sequence',
		 'transaction_date',
		 'move_quantity'
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
		 'total_quantity'
 ];
 public static $fields_inHeader_needsToBeInserted_inPOST = [
 ];
 public static $base_encoded_array = [];
 public static $requiredField_array = [
		 'wip_wo_header_id',
//		 'wo_routing_line_id',
//		 'wo_routing_detail_id',
		 'org_id',
		 'from_routing_sequence',
		 'to_routing_sequence',
		 'from_operation_step',
		 'to_operation_step',
		 'transaction_type',
		 'transaction_date',
		 'move_quantity'
 ];
 public static $primary_column = "wip_move_transaction_id";
 public $wip_move_transaction_id;
 public $wip_wo_header_id;
 public $wo_routing_line_id;
 public $wo_routing_detail_id;
 public $org_id;
 public $wo_number;
 public $item_number;
 public $item_id;
 public $from_routing_sequence;
 public $to_routing_sequence;
 public $from_operation_step;
 public $to_operation_step;
 public $transaction_type;
 public $transaction_date;
 public $move_quantity;
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

 Public static function wip_transactions() {
	$option_header = option_header::find_by_name('WIP_TRANSACTIONS');
	$wip_transactions = option_line::find_by_option_id($option_header->option_header_id);
	return $wip_transactions;
 }

 private function wipMove_Resource_Transaction($routing_details, $charge) {
	$wip_resource_transaction = new wip_resource_transaction;
	foreach (wip_resource_transaction::$field_array as $key => $value) {
	 if (!empty($routing_details->$value)) {
		$wip_resource_transaction->$value = $routing_details->$value;
	 }
	}
	$wip_resource_transaction->org_id = $this->org_id;
	$wip_resource_transaction->transaction_type = 'WIP_RESOURCE_TRANSACTION';
	$wip_resource_transaction->reference = $this->wip_wo_header_id;
	$time = time();
	$wip_resource_transaction->creation_date = strftime("%Y-%m-%d %H:%M:%S", $time);
	$wip_resource_transaction->created_by = $_SESSION['user_name'];
	$wip_resource_transaction->transaction_date = $wip_resource_transaction->creation_date;
	$wip_resource_transaction->last_update_date = $wip_resource_transaction->creation_date;
	$wip_resource_transaction->last_update_by = $wip_resource_transaction->created_by;
	if ($charge === 1) {
	 $wip_resource_transaction->transaction_quantity = $this->move_quantity * $routing_details->usage;
	} elseif ($charge === -1) {
	 $wip_resource_transaction->transaction_quantity = -($this->move_quantity * $routing_details->usage);
	}
	$wip_resource_transaction->save();
	$wip_resource_transaction->_after_save();
 }

 public function update_moveTransaction_andAll($bom_lines, $toOrFrom, $transaction_type_id = 6) {
	$quantity = $this->move_quantity * $bom_lines->usage_quantity;

	$inv_transaction = new inv_transaction();
	foreach (inv_transaction::$field_array as $key => $value) {
	 $inv_transaction->$key = NULL;
	}
	$inv_transaction->transaction_type_id = $transaction_type_id;
	$inv_transaction->item_id = $bom_lines->component_item_id;
	$inv_transaction->org_id = $this->org_id;
	$inv_transaction->quantity = $this->move_quantity * $bom_lines->usage_quantity;

	if ($toOrFrom == 'from') {
	 $inv_transaction->from_subinventory_id = $bom_lines->supply_sub_inventory;
	 $inv_transaction->from_locator_id = $bom_lines->supply_locator;
	} elseif ($toOrFrom == 'to') {
	 $inv_transaction->to_subinventory_id = $bom_lines->supply_sub_inventory;
	 $inv_transaction->to_locator_id = $bom_lines->supply_locator;
	}

	$item = item::find_by_id($bom_lines->component_item_id);
	$inv_transaction->item_number = $item->item_number;
	$inv_transaction->uom_id = $item->uom_id;
	$inv_transaction->document_type = 'Work Order';
	$inv_transaction->document_number = $this->wo_number;
	$inv_transaction->document_id = $this->wip_wo_header_id;
	$inv_transaction->reference = 'wip_wo_header_id';
	$time = time();
	$inv_transaction->creation_date = strftime("%Y-%m-%d %H:%M:%S", $time);
	$inv_transaction->created_by = $_SESSION['user_name'];
	$inv_transaction->last_update_date = $inv_transaction->creation_date;
	$inv_transaction->last_update_by = $inv_transaction->created_by;

	$inv_transaction_satus = $inv_transaction->save();
	if ($inv_transaction_satus == 1) {
	 //update issued quantity
	 $update_wo_bom_class = new wip_wo_bom();
	 foreach (wip_wo_bom::$field_array as $key => $value) {
		$update_wo_bom_class->$value = $bom_lines->$value;
	 }
	 if ($toOrFrom == 'from') {
		$update_wo_bom_class->issued_quantity = $quantity + $bom_lines->issued_quantity;
	 } elseif ($toOrFrom == 'to') {
		$update_wo_bom_class->issued_quantity = $bom_lines->issued_quantity - $quantity;
	 }

	 $update_wo_bom_class->save();
	}
 }

 public function _after_save() {
	global $db;

	//Insert in WIP WO BOM - item issues for operational pull
	if ((!empty($this->wip_move_transaction_id)) && (!(empty($this->from_routing_sequence))) && (!(empty($this->to_routing_sequence)))) {
	 $wip_wo_header_id = $this->wip_wo_header_id;

	 $wip_wo_routing_line_from = wip_wo_routing_line::find_by_wipWoHeaderId_and_routingSequence($wip_wo_header_id, $this->from_routing_sequence);
	 //start from opartion quantity update
	 $from_operation_step = $this->from_operation_step . '_quantity';
	 if (isset($wip_wo_routing_line_from->$from_operation_step)) {
		$begining_from_quantity = $wip_wo_routing_line_from->$from_operation_step;
	 }
	 $end_from_quantity = $begining_from_quantity - $this->move_quantity;
	 $wip_wo_routing_line_from->$from_operation_step = $end_from_quantity;
	 $from_qty_update_status = $wip_wo_routing_line_from->save();

	 //start to opartion quantity update
	 $wip_wo_routing_line_to = wip_wo_routing_line::find_by_wipWoHeaderId_and_routingSequence($wip_wo_header_id, $this->to_routing_sequence);
	 $to_operation_step = $this->to_operation_step . '_quantity';

	 /*
		 Begining of WIP BOM and Onhand Update
		*/
	 $from_routing_sequence = $this->from_routing_sequence;
	 $to_routing_sequence = $this->to_routing_sequence;
	 $from_routing_step = $this->from_operation_step;
	 $to_routing_step = $this->to_operation_step;

	 //Moving from 10 to 10 OR 20 to 20
	 if (($from_routing_sequence == $to_routing_sequence ) && ( $from_routing_step != $to_routing_step)) {
		//check if auto count & backflush is enabled
		if (($wip_wo_routing_line_from->count_point_cb == 1) && ($wip_wo_routing_line_from->backflush_cb == 1)) {
		 $all_wo_bom_lines = wip_wo_bom::find_by_wipWoHeaderId_and_routingSequence($wip_wo_header_id, $from_routing_sequence);
		 if ($from_routing_step == 'queue') {
			//back flush
			foreach ($all_wo_bom_lines as $bom_lines) {
			 //reduce onhand
			 if ($bom_lines->wip_supply_type == 'OPERATION_PULL') {
				$this->update_moveTransaction_andAll($bom_lines, 'from', $transaction_type_id = 6);
			 }
			}
		 } elseif ($to_routing_step == 'queue') {
			//return back flush
			foreach ($all_wo_bom_lines as $bom_lines) {
			 if ($bom_lines->wip_supply_type == 'OPERATION_PULL') {
				$this->update_moveTransaction_andAll($bom_lines, 'to', $transaction_type_id = 7);
			 }
			}
		 }
		}

		/* Resource Charges
		 * 1. Check if auto charge & count point is enabled
		 * 2. If moved from Queue then resource is charged
		 * 3. If move out of Queue resource charged is removed */
		if (($wip_wo_routing_line_from->count_point_cb == 1) && ($wip_wo_routing_line_from->auto_charge_cb == 1)) {
//		 $routing_line = wip_wo_routing_line::find_by_wipWoHeaderId_and_routingSequence($wip_wo_header_id, $from_routing_sequence);
		 $all_routing_details = wip_wo_routing_detail::find_by_wipWo_lineId($wip_wo_routing_line_from->wip_wo_routing_line_id);

		 if ($from_routing_step == 'queue') {
			//back flush
			foreach ($all_routing_details as $routing_details) {
			 //charge resource
			 if ($routing_details->charge_type == 'WIP_MOVE') {
				$this->wipMove_Resource_Transaction($routing_details, 1);
			 }
			}
		 } elseif ($to_routing_step == 'queue') {
			//return back flush
			foreach ($all_routing_details as $routing_details) {
			 //charge resource
			 if ($routing_details->charge_type == 'WIP_MOVE') {
				$this->wipMove_Resource_Transaction($routing_details, -1);
			 }
			}
		 }
		}
	 }

	 /* Moving from 10 to 30 OR 20 to 50, etc
		* 1. For the movement between same sequence i.e 10 to 10 or 10 to 20
		* 2. Movement between two end operations i.e 10 to 30
		* 3. End operation 30 Que to Run
		*/

	 if (($from_routing_sequence < $to_routing_sequence)) {
		//$from_routing_sequence transactions check if auto count & backflush is enabled
		if (($wip_wo_routing_line_from->count_point_cb == 1) && ($wip_wo_routing_line_from->backflush_cb == 1)) {
		 $all_wo_bom_lines = wip_wo_bom::find_by_wipWoHeaderId_and_routingSequence($wip_wo_header_id, $from_routing_sequence);
		 if ($from_routing_step == 'queue') {
			//back flush
			foreach ($all_wo_bom_lines as $bom_lines) {
			 //reduce onhand
			 if ($bom_lines->wip_supply_type == 'OPERATION_PULL') {
				$this->update_moveTransaction_andAll($bom_lines, 'from', $transaction_type_id = 6);
			 }
			}
		 }
		}
		//Resource Charges
		if (($wip_wo_routing_line_from->count_point_cb == 1) && ($wip_wo_routing_line_from->auto_charge_cb == 1)) {
//		 $routing_line = wip_wo_routing_line::find_by_wipWoHeaderId_and_routingSequence($wip_wo_header_id, $from_routing_sequence);
		 $all_routing_details = wip_wo_routing_detail::find_by_wipWo_lineId($wip_wo_routing_line_from->wip_wo_routing_line_id);
		 if ($from_routing_step == 'queue') {
			//back flush
			foreach ($all_routing_details as $routing_details) {
			 //charge resource
			 if ($routing_details->charge_type == 'WIP_MOVE') {
				$this->wipMove_Resource_Transaction($routing_details, 1);
			 }
			}
		 }
		}

		//all inbetween routing lines
		$all_inBetween_routingSteps = wip_wo_routing_line::find_by_wipWoHeaderId_and_fromToRoutingSequence($wip_wo_header_id, $from_routing_sequence, $to_routing_sequence);
		foreach ($all_inBetween_routingSteps as $inbtween_routing_lines) {
		 //$to_routing_sequence transactions check if auto count & backflush is enabled
		 if (($inbtween_routing_lines->count_point_cb == 1) && ($inbtween_routing_lines->backflush_cb == 1)) {
			$all_wo_bom_lines = wip_wo_bom::find_by_wipWoHeaderId_and_routingSequence($wip_wo_header_id, $inbtween_routing_lines->routing_sequence);
			//back flush
			foreach ($all_wo_bom_lines as $bom_lines) {
			 //reduce onhand
			 if ($bom_lines->wip_supply_type == 'OPERATION_PULL') {
				$this->update_moveTransaction_andAll($bom_lines, 'from', $transaction_type_id = 6);
			 }
			}
		 }
		}
		//Resource Charges
		foreach ($all_inBetween_routingSteps as $inbtween_routing_lines) {
		 if (($inbtween_routing_lines->count_point_cb == 1) && ($inbtween_routing_lines->auto_charge_cb == 1)) {
			$all_routing_details = wip_wo_routing_detail::find_by_wipWo_lineId($inbtween_routing_lines->wip_wo_routing_line_id);
			//back flush
			foreach ($all_routing_details as $routing_details) {
			 //charge resource
			 if ($routing_details->charge_type == 'WIP_MOVE') {
				$this->wipMove_Resource_Transaction($routing_details, 1);
			 }
			}
		 }
		}

		//$to_routing_sequence transactions check if auto count & backflush is enabled
		if (($wip_wo_routing_line_to->count_point_cb == 1) && ($wip_wo_routing_line_to->backflush_cb == 1)) {
		 $all_wo_bom_lines = wip_wo_bom::find_by_wipWoHeaderId_and_routingSequence($wip_wo_header_id, $to_routing_sequence);
		 if ($to_routing_step != 'queue') {
			//back flush
			foreach ($all_wo_bom_lines as $bom_lines) {
			 //reduce onhand
			 if ($bom_lines->wip_supply_type == 'OPERATION_PULL') {
				$this->update_moveTransaction_andAll($bom_lines, 'from', $transaction_type_id = 6);
			 }
			}
		 }
		}
		//resource Charges
		if (($wip_wo_routing_line_to->count_point_cb == 1) && ($wip_wo_routing_line_to->auto_charge_cb == 1)) {
//		 $routing_line = wip_wo_routing_line::find_by_wipWoHeaderId_and_routingSequence($wip_wo_header_id, $from_routing_sequence);
		 $all_routing_details = wip_wo_routing_detail::find_by_wipWo_lineId($wip_wo_routing_line_to->wip_wo_routing_line_id);
		 if ($to_routing_step != 'queue') {
			//back flush
			foreach ($all_routing_details as $routing_details) {
			 //charge resource
			 if ($routing_details->charge_type == 'WIP_MOVE') {
				$this->wipMove_Resource_Transaction($routing_details, 1);
			 }
			}
		 }
		}
	 }

	 //Moving from 50 to 20 OR 40 to 10, etc
	 if (($from_routing_sequence > $to_routing_sequence)) {

		//$from_routing_sequence transactions check if auto count & backflush is enabled
		if (($wip_wo_routing_line_from->count_point_cb == 1) && ($wip_wo_routing_line_from->backflush_cb == 1)) {
		 $all_wo_bom_lines = wip_wo_bom::find_by_wipWoHeaderId_and_routingSequence($wip_wo_header_id, $from_routing_sequence);
		 if ($from_routing_step != 'queue') {
			//back flush
			foreach ($all_wo_bom_lines as $bom_lines) {
			 //reduce onhand
			 if ($bom_lines->wip_supply_type == 'OPERATION_PULL') {
				$this->update_moveTransaction_andAll($bom_lines, 'to', $transaction_type_id = 7);
			 }
			}
		 }
		}
		//Resource Charges
		if (($wip_wo_routing_line_from->count_point_cb == 1) && ($wip_wo_routing_line_from->auto_charge_cb == 1)) {
//		 $routing_line = wip_wo_routing_line::find_by_wipWoHeaderId_and_routingSequence($wip_wo_header_id, $from_routing_sequence);
		 $all_routing_details = wip_wo_routing_detail::find_by_wipWo_lineId($wip_wo_routing_line_from->wip_wo_routing_line_id);
		 if ($from_routing_step != 'queue') {
			//back flush
			foreach ($all_routing_details as $routing_details) {
			 //charge resource
			 if ($routing_details->charge_type == 'WIP_MOVE') {
				$this->wipMove_Resource_Transaction($routing_details, -1);
			 }
			}
		 }
		}

		//all inbetween routing lines
		$all_inBetween_routingSteps = wip_wo_routing_line::find_by_wipWoHeaderId_and_fromToRoutingSequence($wip_wo_header_id, $to_routing_sequence, $from_routing_sequence);
		foreach ($all_inBetween_routingSteps as $inbtween_routing_lines) {
		 //$to_routing_sequence transactions check if auto count & backflush is enabled
		 if (($inbtween_routing_lines->count_point_cb == 1) && ($inbtween_routing_lines->backflush_cb == 1)) {
			$all_wo_bom_lines = wip_wo_bom::find_by_wipWoHeaderId_and_routingSequence($wip_wo_header_id, $inbtween_routing_lines->routing_sequence);
			//back flush
			foreach ($all_wo_bom_lines as $bom_lines) {
			 //reduce onhand
			 if ($bom_lines->wip_supply_type == 'OPERATION_PULL') {
				$this->update_moveTransaction_andAll($bom_lines, 'to', $transaction_type_id = 7);
			 }
			}
		 }
		}
		//in bewteen Resource Charges
		foreach ($all_inBetween_routingSteps as $inbtween_routing_lines) {
		 if (($inbtween_routing_lines->count_point_cb == 1) && ($inbtween_routing_lines->auto_charge_cb == 1)) {
			$all_routing_details = wip_wo_routing_detail::find_by_wipWo_lineId($inbtween_routing_lines->wip_wo_routing_line_id);
			//back flush
			foreach ($all_routing_details as $routing_details) {
			 //charge resource
			 if ($routing_details->charge_type == 'WIP_MOVE') {
				$this->wipMove_Resource_Transaction($routing_details, -1);
			 }
			}
		 }
		}

		//$to_routing_sequence transactions check if auto count & backflush is enabled
		if (($wip_wo_routing_line_to->count_point_cb == 1) && ($wip_wo_routing_line_to->backflush_cb == 1)) {
		 $all_wo_bom_lines = wip_wo_bom::find_by_wipWoHeaderId_and_routingSequence($wip_wo_header_id, $to_routing_sequence);
		 if ($to_routing_step == 'queue') {
			//back flush
			foreach ($all_wo_bom_lines as $bom_lines) {
			 //reduce onhand
			 if ($bom_lines->wip_supply_type == 'OPERATION_PULL') {
				$this->update_moveTransaction_andAll($bom_lines, 'to', $transaction_type_id = 7);
			 }
			}
		 }
		}
		//resource Charges
		if (($wip_wo_routing_line_to->count_point_cb == 1) && ($wip_wo_routing_line_to->auto_charge_cb == 1)) {
//		 $routing_line = wip_wo_routing_line::find_by_wipWoHeaderId_and_routingSequence($wip_wo_header_id, $from_routing_sequence);
		 $all_routing_details = wip_wo_routing_detail::find_by_wipWo_lineId($wip_wo_routing_line_to->wip_wo_routing_line_id);
		 if ($to_routing_step == 'queue') {
			//back flush
			foreach ($all_routing_details as $routing_details) {
			 //charge resource
			 if ($routing_details->charge_type == 'WIP_MOVE') {
				$this->wipMove_Resource_Transaction($routing_details, -1);
			 }
			}
		 }
		}
	 }

	 /*
		 End of WIP BOM and Onhand Update
		*/
	 if (isset($wip_wo_routing_line_to->$to_operation_step)) {
		$begining_to_quantity = $wip_wo_routing_line_to->$to_operation_step;
	 } else {
		$begining_to_quantity = 0;
	 }
	 $end_to_quantity = $begining_to_quantity + $this->move_quantity;
	 $wip_wo_routing_line_to->$to_operation_step = $end_to_quantity;
	 $to_qty_update_status = $wip_wo_routing_line_to->save();

	 if (($from_qty_update_status == 1 || $from_qty_update_status == 2) && ($to_qty_update_status == 1 || $to_qty_update_status == 2 )) {
		echo "<div class='message'>From & To Step Quantity update sucessfull! </div>";
		$this->msg = 1;
	 } elseif (($from_qty_update_status == 1 || $from_qty_update_status == 2)) {
		echo "<div class='message'>From Quantity update sucessfull! but To Quantity Update Failed!! </div> ";
		$this->msg = 0;
	 } elseif (($to_qty_update_status == 1 || $to_qty_update_status == 2)) {
		echo "<div class='message'>To Quantity update sucessfull! but From Quantity Update Failed!! </div> ";
		$this->msg = 0;
	 } else {
		echo "<div class='message'>From & To Step Quantity update failed! </div>";
		$this->msg = 0;
	 }
	}

	/* Start of WIP Resource Transaction.
	 * 1. Verify if 
	 */

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



