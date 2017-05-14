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
 * ar_receipt_header
 * Used for generating AR receipt and appling to AR Transactions
 * 
 */
class ar_receipt_header extends dbObject {

 public static $table_name = "ar_receipt_header";
 public static $dependent_classes = ['ar_receipt_line'];
 public static $primary_column = "ar_receipt_header_id";
 public static $primary_column2 = "receipt_number";
 public static $key_column = 'ar_customer_id';
 public static $module = "ar"; //same as gl_journal_source
 public static $gl_journal_category = "AR_RECEIPTS";
 public static $system_info = [
		 'name' => 'AR Receipt',
		 'number' => '1304',
		 'description' => 'Receive money & apply to invoices',
		 'version' => '0.1.1',
		 'db_version' => '1001',
		 'mod_version' => '1.1.1',
		 'dependent_class' => array('ar_receipt_line', 'ar_receipt_interface'),
		 'primary_entity_cb' => '',
		 'module_name' => 'ar',
		 'weight' => 4
 ];
 public static $receipt_status_a = [
		 'INCOMPLETE' => 'Incomplete',
		 'COMPLETE' => 'Complete',
		 'PENDING' => 'Pending Clearing',
		 'CLEARED' => 'Cleared',
		 'CLOSED' => 'Closed',
		 'CANCELLED' => 'Cancelled'
 ];
 public $receipt_action_a = [
		 'VIEW_JOURNAL' => 'View Journal',
		 'CANCEL' => 'Cancel Receipt',
		 'COMPLETE' => 'Complete Receipt',
		 'VERIFY_CLEARING' => 'Verify Clearing',
		 'CREATE_ACCOUNT' => 'Create Accounting',
		 'CLOSE' => 'Close Receipt',
 ];
 public $checkbox = [
//		 "rev_enabled_cb"
 ];
 public static $receipt_type_a = [
		 'MANUAL' => 'Manual',
		 'ELECTROINC' => 'Electronic',
		 'SYSTEM' => 'System',
 ];
 public $field_a = [
		 'ar_receipt_header_id',
		 'bu_org_id',
		 'ar_receipt_source_id',
		 'receipt_number',
		 'ar_customer_id',
		 'ar_customer_site_id',
		 'from_bank_header_id',
		 'description',
		 'from_bank_line_id',
		 'to_bank_header_id',
		 'header_amount',
		 'currency',
		 'doc_currency',
		 'to_bank_line_id',
		 'exchange_rate_type',
		 'exchange_rate',
		 'receipt_type',
		 'document_date',
		 'document_number',
		 'ledger_id',
		 'period_id',
		 'pay_group',
		 'receipt_method',
		 'approval_status',
		 'receipt_status',
		 'reference_type',
		 'reference_key_name',
		 'reference_key_value',
		 'gl_journal_header_id',
		 'created_by',
		 'creation_date',
		 'last_update_by',
		 'last_update_date'
 ];
 public $initial_search = [
		 'ar_receipt_header_id',
		 'receipt_number',
		 'ar_customer_id',
		 'from_bank_header_id',
		 'description',
		 'document_date',
		 'document_number',
		 'gl_journal_header_id',
		 'receipt_method',
		 'approval_status',
		 'receipt_status',
 ];
 public $requiredField = [
		 'bu_org_id',
		 'ar_receipt_source_id',
		 'ledger_id',
		 'period_id'
 ];
 public $fields_inForm_notInDataBase = [
		 "supplier_name",
		 "customer_number",
		 "ar_customer_site_name",
		 'so_number',
		 'sd_so_header_id',
		 'action',
		 'receipt_action',
		 'ar_transaction_header_id'
 ];
 public $notUpdatedFromWebForm = [
		 'gl_journal_header_id',
 ];
 public $fields_inDataBase_notInForm = [
		 'currency'
 ];
 public $profile_default = [
		 'exchange_rate_type' => 'gl_currency_conversion_type',
		 'bu_org_id' => 'org_bu_name_default'
 ];
 public $search_functions = [
		 'Organization' => 'search_bu_name',
 ];
 public $search = [
		 '_show_update_path' => 1,
		 '_update_action_meassge' => 'Update',
		 '_show_view_path' => 1,
//		 '_view_action_meassge' => 'View',
//		 '_extra_path' => '',
 ];
 public $pageTitle = " inoEMS - AR Receipt  "; //page Title
 public $ar_receipt_header_id;
 public $bu_org_id;
 public $ar_transaction_header_id;
 public $receipt_number;
 public $ar_receipt_source_id;
 public $ar_customer_id;
 public $ar_customer_site_id;
 public $from_bank_header_id;
 public $description;
 public $from_bank_line_id;
 public $to_bank_header_id;
 public $header_amount;
 public $currency;
 public $doc_currency;
 public $to_bank_line_id;
 public $exchange_rate_type;
 public $exchange_rate;
 public $receipt_type;
 public $document_date;
 public $document_number;
 public $ledger_id;
 public $period_id;
 public $pay_group;
 public $receipt_method;
 public $approval_status;
 public $receipt_status;
 public $reference_type;
 public $reference_key_name;
 public $reference_key_value;
 public $gl_journal_header_id;
 public $created_by;
 public $creation_date;
 public $last_update_by;
 public $last_update_date;
 public $customer_name;
 public $customer_number;
 public $ar_customer_site_name;
 public $so_number;
 public $sd_so_header_id;
 public $action;
 public $receipt_action;
 public $action_class_name;
 public $mode;
 public $multi_action_class_pc;
 public $multi_action_class_pc_value;
 private $_max_line_num;
 public $lines_from_transaction_header = false;

 protected function _do_initial_defaults() {
	global $dbc;
	$this->receipt_status = 'INCOMPLETE';
	$fin_details = org::find_financial_details_from_orgId($this->bu_org_id);
	if ($fin_details) {
	 $this->currency = $fin_details->currency_code;
	} else {
	 $dbc->rollback = true;
	 echo "<br>Setup in complete. No currency found. Error @ " . __FILE__ . ' @@ line ' . __LINE__;
	}
 }

 private function _do_action() {
	if (($this->action == 'confirm_receipt')) {
	 $this->_confirm_receipt();
	 return 10;
	} else if (($this->action == 'COMPLETE')) {
	 $this->_complete_receipt();
	 return 10;
	}
 }

 private function _complete_receipt() {
	/*
	 * 1. Get the ar receipt source
	 * 2. Check if clearance is required for the receipt source
	 * 3. If clearance is not required change the status of the receipt to complete
	 * 4. If clearance is required then change the status of the receipt to pending clearance
	 */

	$receipt_source_i = ar_receipt_source::find_by_id($this->ar_receipt_source_id);
	if ($receipt_source_i) {
	 $clearance = $receipt_source_i->clearance;
	 if ($clearance == 'MATCHING') {
		$this->receipt_status = 'PENDING';
	 } else {
		$this->receipt_status = 'COMPLETE';
	 }
	}
 }

 public function _before_save() {
	if (empty($this->ar_receipt_header_id) && !empty($this->bu_org_id)) {
	 $this->_do_initial_defaults();
	}

	if (($this->receipt_action == 'REVERSE')) {
	 return -90;
	}
	if (!empty($this->action)) {
	 $this->_do_action();
	}

	if ((!empty($this->ar_receipt_header_id)) && ($this->action === 'CREATE_ACCOUNT')) {
	 $this->_create_accounting();
	 return 10;
	}

	if ((!empty($this->ar_receipt_header_id)) && ($this->receipt_action == 'CANCEL')) {
	 $this->_cancel_receipt();
	 return 10;
	}
 }

 private function _create_accounting() {
	if (in_array($this->receipt_status, ['COMPLETE', 'CLEARED'])) {
	 $this->findBy_id($this->ar_receipt_header_id);

	 //if journal header id excists then save journal lines only else first header & then lines
	 if (empty($this->gl_journal_header_id)) {
		try {
		 $this->_save_journal_header();
		} catch (Exception $e) {
		 echo "Create accounting failed" . $e->getMessage();
		}
	 }
	 if (!empty($this->gl_journal_header_id)) {
		//check the status is not updated and then save/update journal lines
		$gjh = new gl_journal_header();
		$gjh->findBy_id($this->gl_journal_header_id);
		$max_line_num = $gjh->highest_line_num()->max_line_num;
		$this->_max_line_num = !empty($max_line_num) ? $max_line_num + 1 : 1;
		if ($gjh->status == 'ENTERED') {
		 $this->_save_journal_lines();
		} else {
		 echo "<br> The Journal Header \" $gjh_i->journal_name \" (id : $this->gl_journal_header_id ) is not in Entered Status."
		 . "<br>From Subledger, You can only update Jouranls in Entered Status";
		 return;
		}
	 }
	} else {
	 echo '<br>Status does not allow accouting creation. Complete/Clear the transaction ';
	}
 }

 private function _confirm_receipt() {
	//find all interface lines group by customer name & invoice number
	//create interface headers for each customer
	echo "<br> in confirm receipt";
	$ar_int = new ar_receipt_interface();
	$all_lines = $ar_int->findAll_groupByCustomer();
	foreach ($all_lines as $ar_customer_site) {
	 //create a new receipt header
	 $arrh = new $this;
	 $total_header_amount = 0;
	 $ar_int_i = $ar_int->findBy_id($ar_customer_site[0]);
	 foreach ($arrh->field_a as $key => $value) {
		$arrh->$value = isset($ar_int_i->$value) ? $ar_int_i->$value : null;
	 }
	 $arrh->header_amount = $ar_int_i->amount;
	 $arrh->ar_receipt_source_id = 1;
	 try {
		$arrh->audit_trial();
		$arrh->save();
		$arrh->_after_save();
		foreach ($ar_customer_site as $site_key => $ar_int_id) {
		 $arrl = new ar_receipt_line();
		 $ar_int_j = $ar_int->findBy_id($ar_int_id);
		 foreach ($arrl->field_a as $arrl_key => $value) {
			$arrl->$value = isset($ar_int_j->$value) ? $ar_int_j->$value : null;
		 }
		 $arrl->ar_receipt_header_id = $arrh->ar_receipt_header_id;
		 $arrl->line_number = $site_key + 1;
		 $arrl->amount = $ar_int_j->amount;
		 $total_header_amount += $ar_int_j->amount;
		 try {
			$arrl->audit_trial();
			$arrl->save();
			$arrl->_after_save();
			$ar_int->ar_receipt_interface_id = $ar_int_id;
			try {
			 $ar_int->delete();
			} catch (Exception $e) {
			 echo "<br>Deleting Interface Line Failed" . $e->getMessage();
			}
		 } catch (Exception $e) {
			echo "<br>Creating receipt line failed" . $e->getMessage();
		 }
		}
		//update the header amount for receipt
		$arrh->header_amount = $total_header_amount;
		try {
		 $arrh->audit_trial();
		 $arrh->save();
		} catch (Exception $e) {
		 echo "<br>Updating receipt amount header failed" . $e->getMessage();
		}
	 } catch (Exception $e) {
		echo "<br>Creating receipt header failed" . $e->getMessage();
	 }
	}
 }

 public function _after_save() {
	if ((!empty($this->ar_receipt_header_id)) && empty($this->receipt_number)) {
	 $ar_receipt_header_id = $this->ar_receipt_header_id;
	 $bu_org_id = $this->bu_org_id;
	 $this->receipt_number = $bu_org_id . '-' . $ar_receipt_header_id;
	 echo '<br/> System created receipt number is ' . $this->receipt_number;
	 $this->save();
	}
 }

 public function _post_gl_process($ar_receipt_header_id) {
	try {
	 $this->findBy_id($ar_receipt_header_id);
	 $this->receipt_status = 'CLOSED';
	 $this->save();
	 return 1;
	} catch (Exception $e) {
	 echo "<br>Updating receipt status failed.Error @ ar_transaction_header @@ " . __LINE__ . $e->getMessage();
	 return -99;
	}
 }

 private function _save_journal_header() {
	$gjh = new gl_journal_header;
	$gjh->ledger_id = $this->ledger_id;
	$gjh->status = 'ENTERED';
	$gjh->currency = $this->doc_currency;
	$gjh->period_id = $this->period_id;
	$gjh->journal_source = self::$module;
	$gjh->journal_category = self::$gl_journal_category;
	$gjh->reference_type = 'table';
	$gjh->reference_key_name = self::$table_name;
	$gjh->reference_key_value = $this->ar_receipt_header_id;
	$gjh->journal_name = $gjh->journal_category . '-' . $gjh->reference_key_value;
	$gjh->description = $gjh->journal_name . '-' . current_time();
	$gjh->balance_type = 'A';
	try {
	 $gjh->save();
	 $this->gl_journal_header_id = $gjh->gl_journal_header_id;
	 echo "<br> Jounral Header Id #" . $this->gl_journal_header_id . ' is created';
	 //need to create a new insatnce of ar_receipt_header as the gl_journal_header_id is not allowed to updated from webform
	 $ar_rh = new ar_receipt_header();
	 $ar_rh->findBy_id($this->ar_receipt_header_id);
	 $ar_rh->gl_journal_header_id = $gjh->gl_journal_header_id;
	 $ar_rh->save();
	} catch (Exception $e) {
	 echo "<br> Failed Saving Jounral Header" . $e->getMessage();
	}
 }

 private function _get_cash_ac_fromBU() {
	$bu_org = new business();
	$bu_org->org_id = $this->bu_org_id;
	$bu_org_i = $bu_org->findBy_orgId();
	if ($bu_org_i->cash_ac_id) {
	 $cash_ac_id = $bu_org_i->cash_ac_id;
	} else {
	 echo "Cash ac doesnot exist.Using default account";
	 $cash_ac_id = 300;
	}
	return $cash_ac_id;
 }

 private function _save_journal_lines() {
	//	Cr the receviable account 
	$arrl = new ar_receipt_line();
	$arth = new ar_transaction_header();

	$all_receipt_lines = $arrl->findBy_parentId($this->ar_receipt_header_id);
	foreach ($all_receipt_lines as $receipt_lines) {
	 $ar_transaction_header_id = $receipt_lines->ar_transaction_header_id;
	 $arth_i = $arth->findBy_id($ar_transaction_header_id);
	 $receviable_gjl = new gl_journal_line();
	 $receviable_gjl->gl_journal_header_id = $this->gl_journal_header_id;
	 $receviable_gjl->reference_type = 'table';
	 $receviable_gjl->reference_key_name = 'ar_receipt_line';
	 $receviable_gjl->reference_key_value = $receipt_lines->ar_receipt_line_id;
	 //check if line lready exists
	 $jl_exists = $receviable_gjl->findBy_reference_keyName_keyValue();
	 if ($jl_exists) {
		$receviable_gjl->gl_journal_line_id = $jl_exists->gl_journal_line_id;
		$receviable_gjl->line_num = $jl_exists->line_num;
		$receviable_gjl->status = $jl_exists->status;
	 } else {
		$receviable_gjl->gl_journal_line_id = null;
		$receviable_gjl->line_num = $this->_max_line_num;
		$receviable_gjl->status = 'U';
		$this->_max_line_num++;
	 }
	 $receviable_gjl->code_combination_id = $arth_i->receivable_ac_id;
	 $receviable_gjl->total_cr = $receipt_lines->amount;
	 $receviable_gjl->total_ac_cr = $receipt_lines->amount;
	 if (!empty($this->transaction_number)) {
		$receviable_gjl->description = 'AR Trnx Receviable of ' . $this->transaction_number;
	 } else {
		$receviable_gjl->description = 'AR Trnx Receviable of ' . $this->ar_transaction_header_id;
	 }
	 $receviable_gjl->audit_trial();
	 $receviable_gjl->save();
	}

	//	Dr the cash account 
	$bank_ac = new mdm_bank_account();
	$bank_ac_id = ar_receipt_source::find_by_id($this->ar_receipt_source_id)->bank_account_id;
	$bank_ac->findBy_id($bank_ac_id);
	$cash_ac_id = $bank_ac->cash_ac_id;

	if (empty($cash_ac_id)) {
	 $cash_ac_id = $this->_get_cash_ac_fromBU();
	}

	$cash_gjl = new gl_journal_line();
	$cash_gjl->gl_journal_header_id = $this->gl_journal_header_id;
	$cash_gjl->reference_type = 'table';
	$cash_gjl->reference_key_name = 'ar_receipt_header';
	$cash_gjl->reference_key_value = $this->ar_receipt_header_id;
	//check if line lready exists
	$jl_exists_cash = $cash_gjl->findBy_reference_keyName_keyValue();
	if ($jl_exists_cash) {
	 $cash_gjl->gl_journal_line_id = $jl_exists_cash->gl_journal_line_id;
	 $cash_gjl->line_num = $jl_exists_cash->line_num;
	 $cash_gjl->status = $jl_exists_cash->status;
	} else {
	 $cash_gjl->gl_journal_line_id = null;
	 $cash_gjl->status = 'U';
	 $cash_gjl->line_num = $this->_max_line_num;
	 $this->_max_line_num++;
	}
	$cash_gjl->code_combination_id = $cash_ac_id;
	$cash_gjl->total_dr = $this->header_amount;
	$cash_gjl->total_ac_dr = $this->header_amount;
	$cash_gjl->description = 'AR Receipt of ' . $this->receipt_number;
	$cash_gjl->audit_trial();
	try {
	 $cash_gjl->save();
	 echo "<br> Cash Ac is Cr. Journal Line Id is " . $cash_gjl->gl_journal_line_id;
	} catch (Exception $e) {
	 echo "<br>Updating gl journal line for Cash Ac failed" . $e->getMessage();
	}
 }

 public static function instantiate_extra_fields(&$array_of_objects) {
	if (count($array_of_objects) > 0) {
	 foreach ($array_of_objects as &$this_object) {
		$supplier_details = supplier::find_by_id($this_object->ar_customer_id);
		$this_object->supplier_name = $supplier_details->supplier_name;
		$this_object->customer_number = $supplier_details->customer_number;
		$ar_customer_site_details = ar_customer_site::find_by_id($this_object->ar_customer_site_id);
		$this_object->ar_customer_site_name = $ar_customer_site_details->ar_customer_site_name;
	 }
	}
	return $array_of_objects;
 }

 Public static function receipt_types() {
	$option_header = option_header::find_by_name('AR_RECEIPT_TYPE');
	$transaction_types = option_line::find_by_option_id($option_header->option_header_id);
	return $transaction_types;
 }

 Public static function ar_approval_status() {
	$option_header = option_header::find_by_name('APPROVAL_STATUS');
	$ar_approval_status = option_line::find_by_option_id($option_header->option_header_id);
	return $ar_approval_status;
 }

 public function copy($ar_receipt_header_id) {
	global $db;
	$sql1 = " CREATE TEMPORARY TABLE tmptable SELECT * FROM ar_receipt_header WHERE `ar_receipt_header_id` = '{$ar_receipt_header_id}' ";
	if ($db->query($sql1)) {
	 $sql2 = "  UPDATE tmptable SET `ar_receipt_header_id` = '' ,
           `org_id` = '{$this->org_id}' 
          WHERE `ar_receipt_header_id` = '{$ar_receipt_header_id}' ";
	 if ($db->query($sql2)) {
		$sql3 = " INSERT INTO `ar_receipt_header` SELECT * FROM tmptable WHERE `ar_receipt_header_id` = '' ";
		if ($db->query($sql3)) {
		 $this->ar_receipt_header_id = $db->insert_id();
		 $this->msg = 1;
		} else {
		 $this->msg = 0;
		}
	 }
	}
	return $this->msg;
 }

 public function save() {
	$primary_column = static::$primary_column;
	if (empty($this->$primary_column)) {
	 $this->approval_status = 'ENTER';
	 $this->create();
	} else {
	 $this->update($this->$primary_column);
	}
	return $this->msg;
 }

 /* 1. Reverse the journal header
	* 2. Update the PO lines
	* 3. Update the transaction header & line 
	*/

 private function _cancel_receipt() {
	global $dbc;
	if (empty($this->ar_receipt_header_id)) {
	 echo "<br>Cancellation failed!. No receipt header id found.";
	}
	if (!empty($this->gl_journal_header_id)) {
	 $gjh = new gl_journal_header();
	 $gjh_i = $gjh->findBy_id($this->gl_journal_header_id);
	 foreach ($gjh_i as $key => $value) {
		$gjh->$key = $value;
	 }
	 $gjh->status = 'REVERSED';
	 try {
		$gjh->_before_save();
	 } catch (Exception $e) {
		$dbc->rollback = 1;
		echo "Journal Reversal Failed!. Error @ class_ar_receipt_header _cancel_transaction" . $e->getMessage();
		return;
	 }
	}

	$this->_cancel_ar_receipt_lines();
	$this->_cancel_receipt_header();
 }

 private function _cancel_receipt_header() {
	global $dbc;
	$new_apth = new ar_receipt_header();
	$new_apth_i = $new_apth->findBy_id($this->ar_receipt_header_id);
	$new_apth->receipt_status = 'CANCELLED';
	$new_apth->header_amount = '0.0';
	$new_apth->ar_receipt_header_id = $new_apth_i->ar_receipt_header_id;
	try {
	 $new_apth->save();
	} catch (Exception $e) {
	 $dbc->rollback = 1;
	 echo "AR Transaction Lines Update Failed!. Error @ class_ar_receipt_header _transaction_cancell_poInv_lines " . $e->getMessage();
	 return;
	}
 }

 private function _cancel_ar_receipt_lines() {
	global $dbc;
	$aprl = new ar_receipt_line();
	$all_lines = $aprl->findBy_parentId($this->ar_receipt_header_id);
	foreach ($all_lines as $lines) {
	 $ar_lines = new ar_receipt_line();
	 $ar_lines->findBy_id($lines->ar_receipt_line_id);

//update transaction
	 if (!empty($ar_lines->ar_transaction_header_id)) {
		$arth = new ar_transaction_header();
		$arth->findBy_id($ar_lines->ar_transaction_header_id);
		$arth->receipt_amount = $arth->receipt_amount - $ar_lines->amount;
		if ($arth->receipt_amount >= 0) {
		 $arth->save();
		} else {
		 $dbc->rollback = 1;
		 echo "<br>Receipt amount is less than Zero (" . $arth->receipt_amount . ".) Error @ ar_receipt_header @@ line " . ' ' . __LINE__;
		 return;
		}
	 }

	 $ar_lines->amount = $ar_lines->gl_amount = 0;
	 $ar_lines->status = 'CANCELLED';
	 $ar_lines->save();
	}
 }

 public function get_details_from_ar_transaction_header() {
	if (empty($this->ar_transaction_header_id)) {
	 return false;
	}
	$ar_th = new ar_transaction_header();
	$ar_th->findBy_id($this->ar_transaction_header_id);
	$this->bu_org_id = $ar_th->bu_org_id;
	$this->receipt_type = 'MANUAL';
	$this->currency = $ar_th->currency;
	$this->ar_customer_id = $ar_th->ar_customer_id;
	$this->ar_customer_site_id = $ar_th->ar_customer_site_id;
	$this->doc_currency = $ar_th->doc_currency;
	$this->lines_from_transaction_header = 9;
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
			'show_block'
	];

	return $multi_select_hidden;
 }

}

//end of ar_receipt_header class
?>