<?php

class inv_transaction extends dbObject {

 public static $table_name = "inv_transaction";
 public static $primary_column = "inv_transaction_id";
 public static $key_column = 'item_id';
 public static $module = "inv";
 public static $gl_journal_category = "INV_INVENTORY";
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
		 'sd_so_line_id',
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
		 'gl_journal_header_id',
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
		 "reference_type",
		 "created_by",
		 "creation_date"];
 public $account = [
		 "from_account_id",
		 "to_account_id",
		 "account_id"];
 public $checkbox = [
		 "logical_transaction_cb",
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
//		 "item_number",
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
 public $sd_so_line_id;
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
 public $gl_journal_header_id;
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
 public $account_id;

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
		case 7 :
		 array_push($this->requiredField, 'wip_wo_bom_id');
		 array_push($this->requiredField, 'wip_wo_header_id');
		 $this->reference_key_name = !empty($this->reference_key_name) ? $this->reference_key_name : 'wip_wo_header';
		 $this->reference_key_value = !empty($this->reference_key_value) ? $this->reference_key_value : $this->wip_wo_header_id;
		 break;

		default:
		 break;
	 }
	}
 }

 private function _save_journal_header() {
	$inv = new inventory();
	$inv_i = $inv->findRelatedDetail_ByOrgId($this->org_id);
	$gled = new gl_ledger();
	$gled->findBy_id($inv_i->ledger_id);
	$gp = new gl_period();
	$current_open_period = $gp->current_open_period($inv_i->ledger_id);
	$gjh = new gl_journal_header;
	$gjh->ledger_id = $inv_i->ledger_id;
	$gjh->status = 'ENTERED';
	$gjh->currency = $gled->currency_code;
	$gjh->period_id = $current_open_period->gl_period_id;
	$gjh->journal_source = self::$module;
	$gjh->journal_category = self::$gl_journal_category;
	$gjh->reference_type = 'table';
	$gjh->reference_key_name = self::$table_name;
	$gjh->reference_key_value = $this->inv_transaction_id;
	$gjh->journal_name = $gjh->journal_category . '-' . $gjh->reference_key_value;
	$gjh->description = $gjh->journal_name . '-' . current_time();
	$gjh->balance_type = 'A';
	$gjh->audit_trial();
	$gjh->save();
	$this->gl_journal_header_id = $gjh->gl_journal_header_id;
	echo "<br> The New Journal Header Id is " . $this->gl_journal_header_id;
	return $gjh->gl_journal_header_id;
 }

 private function _save_journal_lines($data_a) {
	global $dbc;
	$new_gjl = new gl_journal_line();
	$new_gjl->gl_journal_header_id = $this->gl_journal_header_id;
	$new_gjl->line_num = $data_a['line_number'];
	$new_gjl->status = 'U';
	$new_gjl->code_combination_id = $data_a['account_id'];
	if (($data_a['dr_cr']) == 'dr') {
	 $new_gjl->total_dr = $data_a['amount'];
	 $new_gjl->total_ac_dr = $data_a['amount'];
	} else {
	 $new_gjl->total_cr = $data_a['amount'];
	 $new_gjl->total_ac_cr = $data_a['amount'];
	}
	$new_gjl->description = 'Inv Transaction Id ' . $this->inv_transaction_id . ' item id ' . $this->item_id;
	$new_gjl->reference_type = 'table';
	$new_gjl->reference_key_name = 'inv_transaction';
	$new_gjl->reference_key_value = $this->inv_transaction_id;
	$new_gjl->audit_trial();
	$new_gjl->save();
	$dbc->confirm();
 }

 private function _cretae_journal_line_array($element_value_a, $subinventory_id, $dr_cr, $line_number = '1') {
	$journal_line_a = [];
	$subinv = new subinventory();
	$subinv_i = $subinv->findBy_id($subinventory_id);
	$total_amount = 0;
	foreach ($element_value_a as $key => $value) {
	 if (!empty($value)) {
		$total_amount += $value * $this->quantity;
		$journal_line['line_number'] = $line_number;
		$line_number++;
		$journal_line['amount'] = $value * $this->quantity;
		switch ($key) {
		 case 'mat' :
			$journal_line['account_id'] = $subinv_i->material_ac_id;
			break;
		 case 'moh' :
			$journal_line['account_id'] = $subinv_i->material_oh_ac_id;
			break;
		 case 'oh' :
			$journal_line['account_id'] = $subinv_i->overhead_ac_id;
			break;
		 case 'res' :
			$journal_line['account_id'] = $subinv_i->resource_ac_id;
			break;
		 case 'osp' :
			$journal_line['account_id'] = $subinv_i->osp_ac_id;
			break;
		 case 'default' :
			$journal_line['account_id'] = $subinv_i->material_ac_id;
			break;
		}
		$journal_line['dr_cr'] = $dr_cr;
		array_push($journal_line_a, $journal_line);
	 }
	}
	return $journal_line_a;
 }

 private function _cretae_wipJournal_line_array($element_value_a, $wip_accounting_group_id, $dr_cr, $line_number = '999', $variance = false) {
	$journal_line_a = [];
	$wip_acg = new wip_accounting_group();
	$wip_acg->findBy_id($wip_accounting_group_id);
	$total_amount = 0;
	foreach ($element_value_a as $key => $value) {
	 if (!empty($value)) {
		$total_amount += $value * $this->quantity;
		$journal_line['line_number'] = $line_number;
		$line_number++;
		$journal_line['amount'] = $value * $this->quantity;
		switch ($key) {
		 case 'mat' :
			$journal_line['account_id'] = ($variance == true) ? $wip_acg->var_material_ac_id : $wip_acg->material_ac_id;
			break;
		 case 'moh' :
			$journal_line['account_id'] = ($variance == true) ? $wip_acg->var_material_oh_ac_id : $wip_acg->material_oh_ac_id;
			break;
		 case 'oh' :
			$journal_line['account_id'] = ($variance == true) ? $wip_acg->var_overhead_ac_id : $wip_acg->overhead_ac_id;
			break;
		 case 'res' :
			$journal_line['account_id'] = ($variance == true) ? $wip_acg->var_resource_ac_id : $wip_acg->resource_ac_id;
			break;
		 case 'osp' :
			$journal_line['account_id'] = ($variance == true) ? $wip_acg->var_osp_ac_id : $wip_acg->osp_ac_id;
			break;
		 case 'default' :
			$journal_line['account_id'] = ($variance == true) ? $wip_acg->var_material_ac_id : $wip_acg->material_ac_id;
			break;
		}
		$journal_line['dr_cr'] = $dr_cr;
		array_push($journal_line_a, $journal_line);
	 }
	}
	return $journal_line_a;
 }

 public function _after_save() {
	global $db;
	$onhand = new onhand();
	$journal_line_a = [];
	$element_array = ['mat', 'moh', 'oh', 'res', 'osp'];
	foreach ($element_array as $key => $value) {
	 $$value = 0;
	}

	$ich = new cst_item_cost_header();
	$ich->item_id = $this->item_id;
	$ich->bom_cost_type = 'FROZEN';
	$ich_i = $ich->findBy_ItemId_CostType();
	$icl = new cst_item_cost_line();
	$icl_i = $icl->findBy_parentId($ich_i->cst_item_cost_header_id);
	if (!empty($icl_i)) {
	 foreach ($icl_i as $cost_lines) {
		$mat += array_search('MAT', ((array) $cost_lines)) ? $cost_lines->amount : 0;
		$moh += array_search('MOH', ((array) $cost_lines)) ? $cost_lines->amount : 0;
		$oh += array_search('OH', ((array) $cost_lines)) ? $cost_lines->amount : 0;
		$res += array_search('RES', ((array) $cost_lines)) ? $cost_lines->amount : 0;
		$osp += array_search('OSP', ((array) $cost_lines)) ? $cost_lines->amount : 0;
	 }
	}
	$element_value_a = ['mat' => $mat, 'moh' => $moh, 'oh' => $oh, 'res' => $res, 'osp' => $osp];

	switch ($this->transaction_type_id) {
	 case 1 :
	 case 6 :
	 case 12 :
	 case 13 :
	 case 15 :
		$onhand->setProperty('_from_org_id', $this->org_id);
		$onhand->setProperty('_from_subinventory_id', $this->from_subinventory_id);
		$onhand->setProperty('_from_locator_id', $this->from_locator_id);
		$onhand->setProperty('_transaction_quantity', $this->quantity);
		$onhand->item_id = $this->item_id;
		$update_result = $onhand->updateOnhand();
		//create journals for Misc Issue/ WIP Return 
		$journal_line_a = $this->_cretae_journal_line_array($element_value_a, $this->from_subinventory_id, 'cr', 1);
		$line_number = 1;
		if ($this->transaction_type_id == 6 || $this->transaction_type_id == 12 || $this->transaction_type_id == 13) {
		 $line_number = 1;
		 foreach ($journal_line_a as $journal_line) {
			if ($journal_line['line_number'] > $line_number) {
			 $line_number = $journal_line['line_number'];
			}
		 }
		 $line_number++;
		 //get journal lines from wip
		 $woh = new wip_wo_header();
		 $woh->findBy_id($this->wip_wo_header_id);
		 $wip_accounting_group_id = $woh->wip_accounting_group_id;
		 $wip_journal_line_a = $this->_cretae_wipJournal_line_array($element_value_a, $wip_accounting_group_id, 'dr', $line_number);
		 $journal_line_a = array_merge($journal_line_a, $wip_journal_line_a);
		}
		//form misc issue - debit the entered account
		if ($this->transaction_type_id == 1) {
		 $total_amount = 0;
		 $line_number = 1;
		 foreach ($journal_line_a as $journal_line) {
			$total_amount += $journal_line['amount'];
			if ($journal_line['line_number'] > $line_number) {
			 $line_number = $journal_line['line_number'];
			}
		 }
		 $line_number++;
		 if (!empty($total_amount)) {
			$journal_line['line_number'] = $line_number;
			$journal_line['amount'] = $total_amount;
			$journal_line['account_id'] = $this->account_id;
			$journal_line['dr_cr'] = 'dr';
			array_push($journal_line_a, $journal_line);
		 }
		}
//for SO Shipment Debit the COGS account
		if ($this->transaction_type_id == 15) {
		 $inv = new inventory();
		 $inv_i = $inv->findBy_org_id($this->org_id);
		 $total_amount = 0;
		 $line_number = 1;
		 foreach ($journal_line_a as $journal_line) {
			$total_amount += $journal_line['amount'];
			if ($journal_line['line_number'] > $line_number) {
			 $line_number = $journal_line['line_number'];
			}
		 }
		 $line_number++;
		 if (!empty($total_amount)) {
			$journal_line['line_number'] = $line_number;
			$journal_line['amount'] = $total_amount;
			$journal_line['account_id'] = $inv_i->cogs_ac_id;
			$journal_line['dr_cr'] = 'dr';
			array_push($journal_line_a, $journal_line);
		 }
		}
		break;

	 case 2 :
	 case 5 :
	 case 7 :
	 case 10 :
	 case 11 :
		$onhand->setProperty('_to_org_id', $this->org_id);
		$onhand->setProperty('_to_subinventory_id', $this->to_subinventory_id);
		$onhand->setProperty('_to_locator_id', $this->to_locator_id);
		$onhand->setProperty('_transaction_quantity', $this->quantity);
		$onhand->item_id = $this->item_id;
		$update_result = $onhand->updateOnhand();
		//create journals for  Misc Receipt/ WIP Assembly Completion
		$journal_line_a = $this->_cretae_journal_line_array($element_value_a, $this->to_subinventory_id, 'dr', 1);


		if ($this->transaction_type_id == 5) {
		 $po_v = new po_all_v();
		 $po_v->po_detail_id = $this->po_detail_id;
		 $po_v_i = $po_v->findBy_poDetailId();
		 $accural_amount = $this->quantity * $po_v_i->unit_price;
		 $total_amount = 0;
		 $line_number = 1;
		 foreach ($journal_line_a as $journal_line) {
			$total_amount += $journal_line['amount'];
			if ($journal_line['line_number'] > $line_number) {
			 $line_number = $journal_line['line_number'];
			}
		 }
		 $line_number++;
		 if (!empty($accural_amount)) {
			$journal_line['line_number'] = $line_number;
			$journal_line['amount'] = $accural_amount;
			$journal_line['account_id'] = $po_v_i->accrual_ac_id;
			$journal_line['dr_cr'] = 'cr';
			array_push($journal_line_a, $journal_line);
		 }

		 //PPV if the Accrual & Standard Cost Amounts are differnt
		 if ($accural_amount - $total_amount != 0) {
			$line_number++;
			$ppv_amount = $accural_amount - $total_amount;
			$journal_line['line_number'] = $line_number;
			$journal_line['amount'] = $ppv_amount;
			$journal_line['account_id'] = $po_v_i->ppv_ac_id;
			if ($ppv_amount > 0) {
			 $journal_line['dr_cr'] = 'dr';
			} else {
			 $journal_line['dr_cr'] = 'cr';
			}
			array_push($journal_line_a, $journal_line);
		 }
		}

		if ($this->transaction_type_id == 7 || $this->transaction_type_id == 11 || $this->transaction_type_id == 10) {
		 $line_number = 1;
		 foreach ($journal_line_a as $journal_line) {
			if ($journal_line['line_number'] > $line_number) {
			 $line_number = $journal_line['line_number'];
			}
		 }
		 $line_number++;
		 //get journal lines from wip
		 $woh = new wip_wo_header();
		 $woh->findBy_id($this->wip_wo_header_id);
		 $wip_accounting_group_id = $woh->wip_accounting_group_id;
		 $wip_journal_line_a = $this->_cretae_wipJournal_line_array($element_value_a, $wip_accounting_group_id, 'cr', $line_number);
		 $journal_line_a = array_merge($journal_line_a, $wip_journal_line_a);
		}

		if ($this->transaction_type_id == 2) {
		 $total_amount = 0;
		 $line_number = 1;
		 foreach ($journal_line_a as $journal_line) {
			$total_amount += $journal_line['amount'];
			if ($journal_line['line_number'] > $line_number) {
			 $line_number = $journal_line['line_number'];
			}
		 }
		 $line_number++;
		 if (!empty($total_amount)) {
			$journal_line['line_number'] = $line_number;
			$journal_line['amount'] = $total_amount;
			$journal_line['account_id'] = $this->account_id;
			$journal_line['dr_cr'] = 'cr';
			array_push($journal_line_a, $journal_line);
		 }
		}

		break;

	 case 3 :
	 case 14 :
		$onhand->setProperty('_from_subinventory_id', $this->from_subinventory_id);
		$onhand->setProperty('_from_locator_id', $this->from_locator_id);
		$onhand->setProperty('_to_subinventory_id', $this->to_subinventory_id);
		$onhand->setProperty('_to_locator_id', $this->to_locator_id);
		$onhand->setProperty('_transaction_quantity', $this->quantity);
		$onhand->item_id = $this->item_id;
		$onhand->org_id = $this->org_id;
		$update_result = $onhand->updateOnhand();
		$journal_line_from_a = $this->_cretae_journal_line_array($element_value_a, $this->from_subinventory_id, 'cr', 1);
		$line_number = 1;
		foreach ($journal_line_from_a as $journal_line) {
		 if ($journal_line['line_number'] > $line_number) {
			$line_number = $journal_line['line_number'];
		 }
		}
		$line_number++;
		$journal_line_to_a = $this->_cretae_journal_line_array($element_value_a, $this->to_subinventory_id, 'dr', $line_number);
		$journal_line_a = array_merge($journal_line_from_a, $journal_line_to_a);
		break;

	 default:
		break;
	}

	if ($update_result > 0) {
	 $this->_save_journal_header();
//	 pa($journal_line_a);
	 foreach ($journal_line_a as $journal_lines) {
		$this->_save_journal_lines($journal_lines);
	 }
	 $this->status = 'Success';
	} else {
	 $this->status = 'Error';
	}
	//update the transaction status
	$this->save();

	//update the item issue quantity on WO
	if (($this->transaction_type_id == 6) && (!empty($this->wip_wo_bom_id))) {
	 //update issued quantity
	 $wo_bom = new wip_wo_bom();
	 $wo_bom_i = $wo_bom->findBy_id($this->wip_wo_bom_id);
	 $wo_bom->wip_wo_bom_id = $this->wip_wo_bom_id;
	 $wo_bom->issued_quantity = $wo_bom_i->issued_quantity + $this->quantity;
	 $wo_bom->audit_trial();
	 $wo_bom->save();
	}

	//update the item return quantity on WO
	if (($this->transaction_type_id == 7) && (!empty($this->wip_wo_bom_id))) {
	 //update return quantity
	 $wo_bom = new wip_wo_bom();
	 $wo_bom_i = $wo_bom->findBy_id($this->wip_wo_bom_id);
	 $wo_bom->wip_wo_bom_id = $this->wip_wo_bom_id;
	 $wo_bom->issued_quantity = $wo_bom_i->issued_quantity - $this->quantity;
	 $wo_bom->audit_trial();
	 $wo_bom->save();
	}

	//update on WO Completion
	if (($this->transaction_type_id == 11) && (!empty($this->document_id))) {
	 //update issued quantity
	 $wip_woh = new wip_wo_header();
	 $wip_woh_i = $wip_woh->findBy_id($this->document_id);
	 $wip_woh->wip_wo_header_id = $wip_woh_i->wip_wo_header_id;
	 $wip_woh->completed_quantity = $wip_woh_i->completed_quantity + $this->quantity;
	 $wip_woh->audit_trial();
	 $wip_woh->last_unit_completed_date = $wip_woh->last_update_date;
	 if (empty($wip_woh_i->first_unit_completed_date)) {
		$wip_woh->first_unit_completed_date = $wip_woh->last_unit_completed_date;
	 }
	 if ($wip_woh->completed_quantity == $wip_woh->quantity) {
		$wip_woh->set_wo_status = 'COMPLETED';
	 }

	 $wip_woh->save();

	 //update the to_move qty of last operation
	 $last_wo_routing_line = wip_wo_routing_line::find_lastOperation_by_wip_wo_headerId($this->document_id);
	 $update_wo_routing_line = new wip_wo_routing_line;
	 $update_wo_routing_line->wip_wo_routing_line_id = $last_wo_routing_line->wip_wo_routing_line_id;
	 $update_wo_routing_line->audit_trial();
	 $update_wo_routing_line->tomove_quantity = $last_wo_routing_line->tomove_quantity - $this->quantity;
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
		 $inv_transaction->audit_trial();
		 $inv_transaction->save();
		 $inv_transaction->_after_save();
		}
	 }
	}

	//update on WO Return
	if (($this->transaction_type_id == 13) && (!empty($this->document_id))) {
	 //update issued quantity
	 $wip_woh = new wip_wo_header();
	 $wip_woh_i = $wip_woh->findBy_id($this->document_id);
	 $wip_woh->wip_wo_header_id = $wip_woh_i->wip_wo_header_id;
	 $wip_woh->completed_quantity = $wip_woh_i->completed_quantity - $this->quantity;
	 $wip_woh->audit_trial();
	 $wip_woh->last_unit_completed_date = $wip_woh->last_update_date;
	 if (empty($wip_woh_i->first_unit_completed_date)) {
		$wip_woh->first_unit_completed_date = $wip_woh->last_unit_completed_date;
	 }
	 if ($wip_woh->completed_quantity == $wip_woh->quantity) {
		$wip_woh->set_wo_status = 'COMPLETED';
	 }
	 $wip_woh->save();

	 //update the to_move qty of last operation
	 $last_wo_routing_line = wip_wo_routing_line::find_lastOperation_by_wip_wo_headerId($this->document_id);
	 $update_wo_routing_line = new wip_wo_routing_line;
	 $update_wo_routing_line->wip_wo_routing_line_id = $last_wo_routing_line->wip_wo_routing_line_id;
	 $update_wo_routing_line->audit_trial();
	 $update_wo_routing_line->tomove_quantity = $last_wo_routing_line->tomove_quantity + $this->quantity;
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
		 $inv_transaction->audit_trial();
		 $inv_transaction->save();
		 $inv_transaction->_after_save();
		}
	 }
	}
 }

}

//end of inv_transaction class
?>