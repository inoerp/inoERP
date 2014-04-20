<?php

class cst_item_cost_header extends dbObject {

 protected static $table_name = "cst_item_cost_header";
 public static $dependent_classes = ['cst_item_cost_line'];
 public static $primary_column = "cst_item_cost_header_id";
 public static $key_column = 'item_id';
 public static $module = "cst"; //same as gl_journal_source
// public static $js_fileName = 'modules/cst/item_cost/item_cost.js';
// public static $gl_journal_category = "AR_RECEIPTS";
 public $field_a = [
		 'cst_item_cost_header_id',
		 'org_id',
		 'bom_cost_type',
		 'item_id',
		 'based_on_rollup_cb',
		 'include_in_rollup_cb',
		 'sales_price',
		 'purchase_price',
		 'created_by',
		 'creation_date',
		 'last_update_by',
		 'last_update_date'
 ];
 public $initial_search = [
		 'item_id',
		 'based_on_rollup_cb',
		 'include_in_rollup_cb',
 ];
 public $column = [
		 'cst_item_cost_header_id',
		 'org_id',
		 'bom_cost_type',
		 'item_id',
		 'based_on_rollup_cb',
		 'include_in_rollup_cb',
		 'sales_price',
		 'purchase_price',
 ];
 public $requiredField = [
		 'org_id',
		 'bom_cost_type',
		 'item_id',
 ];
 public $checkbox = [
		 "based_on_rollup_cb",
		 'include_in_rollup_cb'
 ];
 public $fields_inForm_notInDataBase = [
		 "item_number",
		 "item_description",
		 "uom",
		 'action'
 ];
 public $search = [
		 '_show_update_path' => 1,
		 '_update_action_meassge' => 'Update',
		 '_show_view_path' => 1,
//		 '_view_action_meassge' => 'View',
//		 '_extra_path' => '',
 ];
 public $pageTitle = " CST - Item Cost  "; //page Title
 public $option_lists = [
//		 'receipt_types' => 'AR_RECEIPT_TYPE',
//		 'po_status' => 'PO_STATUS',
 ];
 public $search_functions = [
		 'Cost Type' => 'search_bom_cost_type',
		 'Item From' => 'search_item_number_from',
		 'Item To' => 'search_item_number_to',
 ];
 public $prg_standard_cost_update_parameters = [
		 'Organization' => 'search_org_name',
		 'Cost Type' => 'search_bom_cost_type',
		 'Item Number From' => 'search_item_number_from',
		 'Item Number To' => 'search_item_number_to',
		 'Item Id From' => 'search_item_id_from',
		 'Item Id To' => 'search_item_id_to'
 ];
 public $prg_standard_cost_update_details = [
		 'name' => 'Standard Cost Update',
		 'description' => 'Update Frozen Cost from a different cost type',
		 'Item To' => 'search_item_number_to'
 ];
 public $cst_item_cost_header_id;
 public $bom_cost_type;
 public $org_id;
 public $item_id;
 public $based_on_rollup_cb;
 public $include_in_rollup_cb;
 public $sales_price;
 public $purchase_price;
 public $created_by;
 public $creation_date;
 public $last_update_by;
 public $last_update_date;
 public $item_number;
 public $item_description;
 public $uom;
 public $action;
 public $message = '';
 public $parameters;

 Public static function transaction_action() {
	$option_header = option_header::find_by_name('CST_COST_ACTION');
	$lines = option_line::find_by_option_id($option_header->option_header_id);
	return $lines;
 }

 public function search_bom_cost_type() {
	$stmt = '';
	$stmt .= '<select id="bom_cost_type" class="select bom_cost_type" name="bom_cost_type" style="background-color: pink;">';
	$stmt .= '<option value=""></option>';
	$stmt .= '<option value="FROZEN">Frozen</option>
 <option value="PENDING">Pending</option>
<option value="GLOBAL">Global</option>
<option value="FUTURE">Future</option>
<option value="AVERAGE">Average</option>
</select>';
	return $stmt;
 }

 public function search_org_name() {
	global $f;
	$stmt = $f->select_field_from_object('org_id', org::find_all_inventory(), 'org_id', 'org', '', 'org_id', '', 1);
	return $stmt;
 }

 public function search_item_id_from() {
	$stmt = '<input id="item_id_from" class="textfield select_item_id item_id_from" '
					. 'type="text" title="" placeholder="From Item Id" size="20" maxlength="256" value="" '
					. 'name="from_item_id[]" >';
	return $stmt;
 }

 public function search_item_id_to() {
	$stmt = '<input id="item_id_to" class="textfield select_item_id item_id_to" '
					. 'type="text" title="" placeholder="To Item Id" size="20" maxlength="256" value="" '
					. 'name="to_item_id[]" >';
	return $stmt;
 }

 public function search_item_number_from() {
	$stmt = '<input id="item_number_from" class="textfield select_item_number item_number_from" '
					. 'type="text" title="" placeholder="From Item" size="20" maxlength="256" value="" '
					. 'name="from_item_number[]" >';
	return $stmt;
 }

 public function search_item_number_to() {
	$stmt = '<input id="item_number_to" class="textfield select_item_number item_number_to" '
					. 'type="text" title="" placeholder="To Item" size="20" maxlength="256" value="" '
					. 'name="to_item_number[]" >';
	return $stmt;
 }

 public function findBy_ItemId_CostType() {
	$sql = " SELECT * FROM  ";
	$sql .= self::$table_name;
	$sql .= " WHERE bom_cost_type =:bom_cost_type AND item_id = :item_id ";
	$sql .= " LIMIT 1 ";

	$param_a = ['bom_cost_type', 'item_id'];
	$value_a = ['bom_cost_type' => $this->bom_cost_type, 'item_id' => $this->item_id];
	$result = $this->findBy_sql($sql, $param_a, $value_a);
	return !empty($result) ? array_pop($result) : false;
 }

 public function find_frozen_cost() {
	$this->bom_cost_type = 'FROZEN';
	return $this->findBy_ItemId_CostType();
 }

 private function _update_journalHeaderId() {
	$arth = new cst_item_cost_header();
	$arth->cst_item_cost_header_id = $this->cst_item_cost_header_id;
	$arth->gl_journal_header_id = $this->gl_journal_header_id;
	$arth->created_by = $this->created_by;
	$arth->creation_date = $this->creation_date;
	$arth->last_update_by = $this->last_update_by;
	$arth->last_update_date = $this->last_update_date;
	$arth->save();
 }

 public function _before_save() {

	/* Check the cost type - If its FROZEN then show error message */
	if ((isset($this->bom_cost_type)) && ($this->bom_cost_type == 'FROZEN')) {
	 echo " You can't create/update item cost for frozen cost type. <br>"
	 . " Create Item cost in pending(or any user defined cost type)and then run standard cost update. ";
	 return -99;
	}
	if ((!empty($this->cst_item_cost_header_id)) && ($this->action == 'COST_UPDATE') && (($this->bom_cost_type != 'FROZEN'))) {
	 pa($this);
	 $this->_update_standard_cost();
	 return 10;
	}
	if ((!empty($this->cst_item_cost_header_id)) && ($this->action === 'create_accounting')) {
	 $asis_data = $this->findBy_id($this->cst_item_cost_header_id);
	 foreach ($asis_data as $key => $value) {
		$this->$key = $value;
	 }
	 //if journal header id excists then save journal lines only else first header & then lines
	 if (empty($this->gl_journal_header_id)) {
		try {
		 $this->_save_journal_header();
		 try {
			echo "<br>Accounting records are sucessfully created " . $this->gl_journal_header_id;
			$this->_update_journalHeaderId();
		 } catch (Exception $e) {
			echo "<br>Updating gl journal header id failed" . $e->getMessage();
		 }
		} catch (Exception $e) {
		 echo "Create accounting failed" . $e->getMessage();
		}
	 }
	 if (!empty($this->gl_journal_header_id)) {
		//check the status is not updated and then save/update journal lines
		$gjh = new gl_journal_header();
		$gjh_i = $gjh->findBy_id($this->gl_journal_header_id);
		if ($gjh_i->status == 'ENTERED') {
		 $this->_save_journal_lines();
		} else {
		 echo "<br> The Journal Header \" $gjh_i->journal_name \" (id : $this->gl_journal_header_id ) is not in Entered Status."
		 . "<br>From Subledger, You can only update Jouranls in Entered Status";
		 return;
		}
	 }

	 return 10;
	}

	if ((!empty($this->cst_item_cost_header_id)) && ($this->action == 'CANCEL')) {
	 $this->_cancel_transaction();
	 return 10;
	}
 }

 public function _after_save() {
	
 }

 private function _update_standard_cost() {
	/*
	 * 1. First check if frozen cost exists for the item_id 
	 * 2. Copy the header and create/update frozen
	 * 3. Copy all the line and update with the new frozen cost header id
	 */
	$this->findBy_id($this->cst_item_cost_header_id);
	$ich = new cst_item_cost_header();
	foreach ($this->field_a as $key => $value) {
	 $ich->$value = $this->$value;
	}
	$existing_fozen_cost = $this->find_frozen_cost();
	if (!empty($existing_fozen_cost)) {
	 $ich->cst_item_cost_header_id = $existing_fozen_cost->cst_item_cost_header_id;
	} else {
	 $ich->cst_item_cost_header_id = null;
	}
	$ich->bom_cost_type = 'FROZEN';
	$ich->audit_trial();
	try {
	 $ich->save();
	 if (!empty($ich->cst_item_cost_header_id)) {
		$this->message .=" <br>Item cost heade is sucessfully updated for cst_item_cost_header_id " . $ich->cst_item_cost_header_id;
		//save cost line
		$this->_update_standard_cost_lines($ich);
	 }
	} catch (Excption $e) {
	 echo "<br>Saving frozen cost header failed!" . $e->getMessage();
	}
 }

 private function _update_standard_cost_lines(&$header_obj) {
	$icl = new cst_item_cost_line();
	$all_cost_lines = $icl->findBy_parentId($this->cst_item_cost_header_id);
	if (empty($all_cost_lines)) {
	 $this->message .= "<br/>Leaving Standard cost update as no cost line exists";
	 return;
	}
	foreach ($all_cost_lines as $cost_line) {
	 foreach ($icl->field_a as $key => $value) {
		$icl->$value = $cost_line->$value;
	 }
	 //check if line already exists by searching cost_element_id and header_id
	 $icl->cst_item_cost_header_id = $header_obj->cst_item_cost_header_id;
	 $icl->cost_element_id = $cost_line->cost_element_id;
	 $icl->cost_element_type = $cost_line->cost_element_type;
	 $existing_line = $icl->findBy_headerId_elementId();
	 if (!empty($existing_line)) {
		$icl->cst_item_cost_line_id = $existing_line->cst_item_cost_line_id;
	 } else {
		$icl->cst_item_cost_line_id = null;
	 }
	 try {
		$icl->audit_trial();
		$icl->save();
	 } catch (Exception $e) {
		echo "<br>Saving frozen cost line failed!" . $e->getMessage();
	 }
	}
 }

 public function prg_standard_cost_update($parameters, $program_id=null) {
	global $p;
	$p = new sys_program();
	if(!empty($program_id)){
	 $p->findBy_id($program_id);
	}else{
	 return ;
	}

	if (!empty($parameters['org_id'][0])) {
	 $org_id = $parameters['org_id'][0];
	 $this->message .= '<br> Entered Org Id is : ' . $org_id;
	} else {
	 $this->message .= '<br> Error! : No org id found @ cst_item_cost_header ' . __LINE__;
	 $p->message = $this->message;
	 $p->status = 'Error';
	 $p->save();
	 return -99;
	}

	if (!empty($parameters['bom_cost_type'][0])) {
	 $bom_cost_type = $parameters['bom_cost_type'][0];
	 $this->message .= '<br> Entered BOM Cost Type is : ' . $bom_cost_type;
	} else {
	 $this->message .= '<br> Error! : No BOM Cost Type is found @ cst_item_cost_header ' . __LINE__;
	 $p->message = $this->message;
	 $p->status = 'Error';
	 $p->save();
	 return -99;
	}

	if (isset($parameters['from_item_id'][0])) {
	 $this->message .= "<br/>Using Standard cost update by Item Id ";
	 $from_item_id = $parameters['from_item_id'][0];
	 if (!empty($parameters['to_item_id'][0])) {
		$to_item_id = $parameters['to_item_id'][0];
	 } else {
		$to_item_id = $from_item_id;
	 }
	 $item = new item();
	 $item_range = $item->findBy_itemIdRange($from_item_id, $to_item_id);
	 foreach ($item_range as $items) {
		$ich = new cst_item_cost_header();
		$ich->item_id = $items->item_id;
		$ich->bom_cost_type = $bom_cost_type;
		$ich_i = $ich->findBy_ItemId_CostType();
		if (!empty($ich_i)) {
		 $ich->cst_item_cost_header_id = $ich_i->cst_item_cost_header_id;
		 try {
			$ich->_update_standard_cost();
			$this->message .= "<br/>Standard cost update is sucessfully updated for item_id - " . $ich->item_id .
							' bom_cost_type : ' . $ich->bom_cost_type;
		 } catch (Exception $e) {
			$this->message .= "<br/>Standard cost update fialed for Item id " . $ich->item_id . $e->getMessage();
		 }
		} else {
		 $this->message .= "<br/>Leaving Standard cost update as no cost exists item_id - " . $ich->item_id .
						 ' bom_cost_type : ' . $ich->bom_cost_type;
		}
	 }
	 $p->message = $this->message;
	 $p->status = 'Completed';
	 $p->save();
	 return 10;
	}

	if (isset($parameters['from_item_number'][0])) {
	 $from_item_number = $parameters['from_item_number'][0];
	 if (!empty($parameters['to_item_number'][0])) {
		$to_item_number = $parameters['to_item_number'][0];
	 } else {
		$to_item_number = $from_item_number;
	 }
	 $item = new item();
	 $item_range = $item->findBy_itemNumberRange_OrgId($from_item_number, $to_item_number, $org_id);

	 foreach ($item_range as $items) {
		$ich = new cst_item_cost_header();
		$ich->item_id = $items->item_id;
		$ich->bom_cost_type = $bom_cost_type;
		$ich_i = $ich->findBy_ItemId_CostType();
		if (!empty($ich_i)) {
		 $ich->cst_item_cost_header_id = $ich_i->cst_item_cost_header_id;
		 try {
			$ich->_update_standard_cost();
		 } catch (Exception $e) {
			$this->message .= "<br/>Standard cost update fialed for Item id " . $ich->item_id . $e->getMessage();
		 }
		} else {
		 $this->message .= "<br/>Leaving Standard cost update as no cost exists";
		}
	 }
	 $p->message = $this->message;
	 $p->status = 'Completed';
	 $p->save();
	 return 10;
	}
	echo $this->message;
	return;
 }

 private function _save_journal_header() {
	$gjh = new gl_journal_header;
	$gjh->ledger_id = $this->ledger_id;
	$gjh->status = 'ENTERED';
	$gjh->currency = $this->document_currency;
	$gjh->period_id = $this->period_id;
	$gjh->journal_source = self::$module;
	$gjh->journal_category = self::$gl_journal_category;
	$gjh->reference_type = 'table';
	$gjh->reference_key_name = self::$table_name;
	$gjh->reference_key_value = $this->cst_item_cost_header_id;
	$gjh->journal_name = $gjh->journal_category . '-' . $gjh->reference_key_value;
	$gjh->description = $gjh->journal_name . '-' . current_time();
	$gjh->balance_type = 'A';
	$gjh->audit_trial();
	$gjh->save();
	$this->gl_journal_header_id = $gjh->gl_journal_header_id;
	echo "<br> The New Journal Header Id is " . $this->gl_journal_header_id;
 }

 private function _save_journal_lines() {

	//	Dr the cash account 
	$bu_org = new business();
	$bu_org->org_id = $this->bu_org_id;
	$bu_org_i = $bu_org->findBy_orgId();
	if ($bu_org_i->cash_ac_id) {
	 $cash_ac_id = $bu_org_i->cash_ac_id;
	} else {
	 echo "Cash ac doesnot exist.Using default account";
	 $cash_ac_id = 300;
	}

	$cash_gjl = new gl_journal_line();
	$cash_gjl->gl_journal_header_id = $this->gl_journal_header_id;
	$cash_gjl->line_num = 1;
	$cash_gjl_i = $cash_gjl->findBy_headerId_lineNum();
	if ($cash_gjl_i) {
	 $cash_gjl->gl_journal_line_id = $cash_gjl_i->gl_journal_line_id;
	}
	$cash_gjl->status = 'U';
	$cash_gjl->code_combination_id = $cash_ac_id;
	$cash_gjl->total_dr = $this->header_amount;
	$cash_gjl->total_ac_dr = $this->header_amount;
	$cash_gjl->description = 'AR Receipt of ' . $this->receipt_number;
	$cash_gjl->reference_type = 'table';
	$cash_gjl->reference_key_name = 'cst_item_cost_header';
	$cash_gjl->reference_key_value = $this->cst_item_cost_header_id;
	$cash_gjl->audit_trial();

	try {
	 $cash_gjl->save();
	 echo "<br> Cash Ac is Cr. Journal Line Id is " . $cash_gjl->gl_journal_line_id;
	} catch (Exception $e) {
	 echo "<br>Updating gl journal line for Cash Ac failed" . $e->getMessage();
	}


	//	Cr the receviable account 
	$arrl = new cst_item_cost_line();
	$arth = new ar_transaction_header();
	$line_num = 1;
	$all_receipt_lines = $arrl->findBy_parentId($this->cst_item_cost_header_id);
	foreach ($all_receipt_lines as $receipt_lines) {
	 $line_num++;
	 $ar_transaction_header_id = $receipt_lines->ar_transaction_header_id;
	 $arth_i = $arth->findBy_id($ar_transaction_header_id);
	 $receviable_gjl = new gl_journal_line();
	 $receviable_gjl->gl_journal_header_id = $this->gl_journal_header_id;
	 $receviable_gjl->line_num = $line_num;
	 $receviable_gjl_i = $receviable_gjl->findBy_headerId_lineNum();
	 if ($receviable_gjl_i) {
		$receviable_gjl->gl_journal_line_id = $receviable_gjl_i->gl_journal_line_id;
	 }
	 $receviable_gjl->status = 'U';
	 $receviable_gjl->code_combination_id = $arth_i->receivable_ac_id;
	 $receviable_gjl->total_cr = $receipt_lines->amount;
	 $receviable_gjl->total_ac_cr = $receipt_lines->amount;
	 if (!empty($this->transaction_number)) {
		$receviable_gjl->description = 'AR Trnx Receviable of ' . $this->transaction_number;
	 } else {
		$receviable_gjl->description = 'AR Trnx Receviable of ' . $this->ar_transaction_header_id;
	 }
	 $receviable_gjl->reference_type = 'table';
	 $receviable_gjl->reference_key_name = 'ar_transaction_header';
	 $receviable_gjl->reference_key_value = $this->ar_transaction_header_id;
	 $receviable_gjl->audit_trial();
	 $receviable_gjl->save();
	}
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
			'program_name'
	];

	return $multi_select_hidden;
 }

}

//end of cst_item_cost_header class
?>