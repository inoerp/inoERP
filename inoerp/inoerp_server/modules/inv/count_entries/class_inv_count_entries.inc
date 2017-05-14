<?php

/**
 * inoERP
 *
 * @copyright   2014 Nishit R. Das
 * @license     https://www.mozilla.org/MPL/2.0/
 * @link        http://inoideas.org
 * @source code https://github.com/inoerp/inoERP
 */

/**
 * Item
 * Contains all the inv_count_entries information, such as - item_id_m, org_id, subinventory_id, etc.
 * 
 */
class inv_count_entries extends dbObject {

 public static $table_name = "inv_count_entries";
 public static $primary_column = "inv_count_entries_id";
 public static $parent_primary_column = "inv_count_schedule_id";
 public static $dependent_classes = ['inv_count_schedule'];
 public static $js_fileName = 'modules/inv/count_entries/js/multi_select_count.js';
 public static $key_column = "item_id_m";
 public static $module = "inv";
 public static $system_info = [
		 'name' => 'Count Entries',
		 'number' => '2105',
		 'description' => 'Inventory Count Entries',
		 'version' => '0.1.1',
		 'db_version' => '1001',
		 'mod_version' => '1.1.1',
		 'primary_entity_cb' => '',
		 'module_name' => 'inv',
		 'weight' => 5
 ];
 public static $count_entries_action_a = [
		 'APPROVE' => 'Approve Count',
		 'REJECT' => 'Reject Count',
		 'RECOUNT' => 'Schedule Re-count',
 ];
 public $field_a = [
		 'inv_count_entries_id',
		 'inv_count_schedule_id',
		 'item_id_m',
		 'uom_id',
		 'org_id',
		 'subinventory_id',
		 'locator_id',
		 'lot_number',
		 'serial_number',
		 'schedule_date',
		 'adjustment_ac_id',
		 'status',
		 'reason',
		 'reference',
		 'counted_by',
		 'count_date',
		 'count_qty',
		 'system_qty',
		 'adjusted_qty',
		 'description',
		 'created_by',
		 'creation_date',
		 'last_update_by',
		 'last_update_date',
 ];
 public $initial_search = [
		 'inv_count_entries_id',
		 'inv_count_schedule_id',
		 'item_id_m',
 ];
 public $column = [
		 'inv_count_entries_id',
		 'inv_count_schedule_id',
		 'item_id_m',
		 'uom_id',
		 'org_id',
		 'subinventory_id',
		 'locator_id',
		 'lot_number',
		 'serial_number',
 ];
 public $requiredField = [
		 'inv_count_schedule_id',
 ];
 public $fields_inForm_notInDataBase = [
		 'inv_count_header_id',
		 'count_name',
		 'item_number',
		 'item_description',
		 'adjusted_value',
		 'action_class_name',
		 'mode',
		 'action',
		 'approval_action'
 ];
 public $pageTitle = " Enter Inventory Count "; //page Title
 public $inv_count_entries_id;
 public $inv_count_schedule_id;
 public $item_id_m;
 public $uom_id;
 public $org_id;
 public $subinventory_id;
 public $locator_id;
 public $lot_number;
 public $serial_number;
 public $schedule_date;
 public $adjustment_ac_id;
 public $status;
 public $reason;
 public $reference;
 public $counted_by;
 public $count_date;
 public $count_qty;
 public $system_qty;
 public $adjusted_qty;
 public $description;
 public $created_by;
 public $creation_date;
 public $last_update_by;
 public $last_update_date;
 public $inv_count_header_id;
 public $count_name;
 public $item_number;
 public $item_description;
 public $adjusted_value;
 public $action;
 public $action_class_name;
 public $mode;
 public $multi_action_class_pc;
 public $multi_action_class_pc_value;
 public $approval_action;

 public static function find_by_header_id($id) {
	$vgl = new inv_count_entries();
	return $vgl->findBy_parentId($id);
 }

 public static function find_by_parentId_abcCode($parent_id, $abc_code) {
	$sql = " SELECT * FROM " . self::$table_name;
	$sql .= " WHERE inv_count_header_id = '{$parent_id}' AND class_code = '{$abc_code}'  ";
	$sql = ino_perPageSql_i($sql, 1);
	$result = self::find_by_sql($sql);
	return !empty($result) ? array_pop($result) : false;
 }

 private function _tolerance_updates($inv_count_header_obj, $condition_type = '') {
	$onhand = new onhand();
	$onhand->item_id_m = $this->item_id_m;
	$onhand->org_id = !empty($this->org_id) ? $this->org_id : null;
	$onhand->subinventory_id = !empty($this->subinventory_id) ? $this->subinventory_id : null;
	$onhand->locator_id = !empty($this->locator_id) ? $this->locator_id : null;

	$onhand_i = $onhand->findBy_itemIdm_location();
	$item_onhand = 0;
	if ($onhand_i) {
	 foreach ($onhand_i as $onhand_obj) {
		$item_onhand += $onhand_obj->onhand;
	 }
	}
	$this->system_qty = $item_onhand;

	$onhand_qty_variance = $item_onhand - $this->count_qty;
	$this->adjusted_qty = $onhand_qty_variance;

	$item_cost_i = cst_item_cost_v::find_cost_by_itemId_orgId($this->item_id_m, $this->org_id, 'FROZEN');
	if (empty($item_cost_i)) {
	 $this->_approve_count_entry();
	 return true;
	}
	$item_cost = $item_cost_i->standard_cost;
	$system_onhand_value = !empty($item_cost) ? ($item_onhand * $item_cost) : 0;
	$entered_onhand_value = !empty($item_cost) ? ($this->count_qty * $item_cost) : 0;

	$onhand_value_variance = $system_onhand_value - $entered_onhand_value;
	$this->adjusted_value = $onhand_value_variance;

	switch ($condition_type) {
	 case 'NEVER' :
		$this->_approve_count_entry();
		break;
	 case 'OUT_OF_TOLERANCE_ANY' :
		if (($onhand_qty_variance > $inv_count_header_obj->quantity_variance_positive) ||
						($onhand_qty_variance < $inv_count_header_obj->quantity_variance_negative) ||
						($onhand_value_variance > $inv_count_header_obj->value_variance_positive) ||
						($onhand_value_variance < $inv_count_header_obj->value_variance_negative)) {
		 $this->status = 'PENDING_APPROVAL';
		} else {
		 $this->_approve_count_entry();
		 $this->status = 'COMPLETE';
		}
		break;

	 case 'OUT_OF_TOLERANCE_ANY' :
		if (($onhand_qty_variance > $inv_count_header_obj->quantity_variance_positive) &&
						($onhand_qty_variance < $inv_count_header_obj->quantity_variance_negative) &&
						($onhand_value_variance > $inv_count_header_obj->value_variance_positive) &&
						($onhand_value_variance < $inv_count_header_obj->value_variance_negative)) {
		 $this->status = 'PENDING_APPROVAL';
		} else {
		 $this->_approve_count_entry();
		 $this->status = 'COMPLETE';
		}
		break;

	 case 'default' :
		break;
	}

	return;
 }

 private function _update_data() {
	if (empty($this->inv_count_header_id)) {
	 throw new Exception('No inv_count_header_id found. Error @ _find_status of class_inv_count_entries');
	} else if (empty($this->item_id_m)) {
	 throw new Exception('No item_id_m found. Error @ _find_status of class_inv_count_entries');
	}
	$inv_count_header = new inv_count_header();
	$inv_count_header->findBy_id($this->inv_count_header_id);
	$inv_cs = new inv_count_schedule();
	$inv_cs->findBy_id($this->inv_count_schedule_id);
	switch ($inv_count_header->approval_required) {
	 case 'NEVER':
		$this->_tolerance_updates($inv_count_header, 'NEVER');
		$this->status = 'COMPLETE';
		break;

	 case 'ALWAYS':
		$this->_tolerance_updates($inv_count_header, 'ALWAYS');
		$this->status = 'PENDING_APPROVAL';
		break;

	 case 'OUT_OF_TOLERANCE_ALL':
		$this->_tolerance_updates($inv_count_header, 'OUT_OF_TOLERANCE_ALL');
		break;

	 case 'OUT_OF_TOLERANCE_ANY':
		$this->_tolerance_updates($inv_count_header, 'OUT_OF_TOLERANCE_ANY');
		break;

	 case 'default':
		$this->_tolerance_updates($inv_count_header);
		$this->status = 'COMPLETE';
		break;
	}
	$inv_cs->status = $this->status;
	$inv_cs->save();
 }

 private function _approve_count_entry() {
	$inv_transaction = new inv_transaction();
	$inv_transaction->org_id = $this->org_id;
	if ($this->adjusted_qty > 0) {
	 $inv_transaction->transaction_type_id = 16;
	 $inv_transaction->from_subinventory_id = $this->subinventory_id;
	 $inv_transaction->from_locator_id = $this->locator_id;
	} else {
	 $inv_transaction->transaction_type_id = 17;
	 $inv_transaction->to_subinventory_id = $this->subinventory_id;
	 $inv_transaction->to_locator_id = $this->locator_id;
	}
	$inv_transaction->account_id = $this->adjustment_ac_id;
	$inv_transaction->quantity = abs($this->adjusted_qty);
	$inv_transaction->item_id_m = $this->item_id_m;
	$inv_transaction->uom_id = $this->uom_id;
	$inv_transaction->document_type = 'Cycle Count Adj';
	$inv_transaction->document_number = $this->inv_count_entries_id;
	$inv_transaction->document_id = $this->inv_count_header_id;
	$inv_transaction->reference = 'inv_count_header';
	$inv_transaction->save();

	$inv_transaction->_after_save();
 }

 public function _before_save() {
	if (!empty($this->approval_action) && !empty($this->inv_count_entries_id) && !empty($this->inv_count_schedule_id)) {
	 $inv_cs = new inv_count_schedule();
	 $inv_cs->findBy_id($this->inv_count_schedule_id);
	 switch ($this->approval_action) {
		case 'APPROVE' :
		 $this->_approve_count_entry();
		 $this->status = 'COMPLETE';
		 $inv_cs->status = 'COMPLETE';
		 break;

		case 'REJECT' :
		 $this->status = 'COMPLETE';
		 $inv_cs->status = 'COMPLETE';
		 break;

		case 'RECOUNT' :
		 $this->delete();
		 $inv_cs->status = 'UNCOUNTED';
		 break;

		case 'default' :
		 break;
	 }

	 $inv_cs->audit_trial();
	 $inv_cs->save();
	 $this->audit_trial();
	 $this->save();

//    pa($this);
	 return 10;
	}

	if (empty($this->approval_action) && empty($this->status)) {
	 if (!empty($_POST['inv_count_header_id'][0])) {
		$this->inv_count_header_id = $_POST['inv_count_header_id'][0];
	 } else {
		$this->inv_count_header_id = $count_schedule->inv_count_header_id;
	 }

	 try {
		$this->_update_data();
	 } catch (Exception $e) {
		echo "<br>Failed to updte the count entrie. Error @ class_inv_count_entries @@ " . __LINE__ . $e->getMessage();
	 }
	}
 }

 public function multi_select_input_fields() {
	global $f;

	$multi_select_stmt = $f->select_field_from_array('approval_action', self::$count_entries_action_a, '');
	$multi_select_input = [
			'approval_action' => $multi_select_stmt
	];
//   return $multi_select_stmt;
 }

 public function multi_select_select_fields() {
	global $f;

	$approval_action_stmt = $f->select_field_from_array('approval_action', self::$count_entries_action_a, '', '', '');
	$multi_select_select = [
			'approval_action' => $approval_action_stmt
	];

	return $multi_select_select;
 }

 public function multi_select_hidden_fields() {
	$multi_select_hidden = [
			'action_class_name',
			'mode',
			'action',
			'show_block'
	];

	return $multi_select_hidden;
 }

}

//end of path class
?>