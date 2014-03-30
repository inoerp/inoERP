<?php

class ar_transaction_header extends dbObject {

 protected static $table_name = "ar_transaction_header";
 public static $dependent_classes = ['ar_transaction_line', 'ar_transaction_detail'];
 public static $primary_column = "ar_transaction_header_id";
 public static $primary_column2 = "transaction_number";
 public static $key_column = 'ar_customer_id';
 public static $module = "ap"; //same as gl_journal_source
 public static $gl_journal_category = "AR_TRANSACTIONS";
 public $account = [
		 'receivable_ac_id'
 ];
 public $field_a = [
		 'ar_transaction_header_id',
		 'bu_org_id',
		 'transaction_type',
		 'transaction_number',
		 'ar_customer_id',
		 'ar_customer_site_id',
		 'document_owner',
		 'description',
		 'ship_to_id',
		 'bill_to_id',
		 'header_amount',
		 'receipt_amount',
		 'currency',
		 'document_currency',
		 'receivable_ac_id',
		 'payment_term_id',
		 'exchange_rate_type',
		 'exchange_rate',
		 'ef_id',
		 'transaction_status',
		 'document_date',
		 'document_number',
		 'ledger_id',
		 'period_id',
		 'payment_term_date',
		 'sales_person',
		 'receipt_method',
		 'approval_status',
		 'receipt_status',
		 'reference_type',
		 'reference_key_name',
		 'reference_key_value',
		 'sd_so_header_id',
		 'gl_journal_header_id',
		 'created_by',
		 'creation_date',
		 'last_update_by',
		 'last_update_date'
 ];
 public $initial_search = [
		 'ar_transaction_header_id',
		 'bu_org_id',
		 'ledger_id',
		 'period_id',
		 'transaction_type',
		 'transaction_number',
		 'document_number',
		 'ar_customer_id',
		 'ar_customer_site_id',
		 'document_owner',
		 'approval_status',
		 'gl_journal_header_id'
 ];
 public $column = [
		 'ar_transaction_header_id',
		 'document_number',
		 'transaction_type',
		 'transaction_number',
		 'header_amount',
		 'receipt_amount',
		 'ar_customer_id',
		 'ar_customer_site_id',
		 'bu_org_id',
		 'ledger_id',
		 'period_id',
		 'document_owner',
		 'document_currency',
		 'currency',
		 'gl_journal_header_id'
 ];
 public $requiredField = [
		 'bu_org_id',
		 'transaction_type',
		 'ar_customer_id',
		 'ar_customer_site_id',
		 'header_amount',
		 'currency',
		 'payment_term_id',
		 'document_date',
		 'ledger_id',
		 'period_id',
		 'receivable_ac_id'
 ];
 public $fields_inForm_notInDataBase = [
		 "customer_name",
		 "customer_number",
		 "customer_site_name",
		 'sd_so_number',
		 'sd_so_header_id',
		 'action',
		 'transaction_action'
 ];
 public $numberField = [
		 'header_amount'
 ];
 public $search = [
		 '_show_update_path' => 1,
		 '_update_action_meassge' => 'Update',
		 '_show_view_path' => 1,
//		 '_view_action_meassge' => 'View',
//		 '_extra_path' => '',
		 '_extra_path' => array('form.php?class_name=ar_payment_header&mode=9' => 'Pay',
				 'form.php?class_name=ar_transaction_header&mode=9&transaction_type=DEBIT_MEMO' => 'Credit')
 ];
 public $pageTitle = " AR Transaction - Invoice, Debit/Credit Memo, Deposit/Guarentee etc "; //page Title
 public $option_lists = [
		 'transaction_types' => 'AR_TRANSACTION_TYPE',
//		 'om_so_status' => 'AR_TRANSACTION_TYPE',
 ];
 public $ar_transaction_header_id;
 public $bu_org_id;
 public $transaction_type;
 public $transaction_number;
 public $ar_customer_id;
 public $ar_customer_site_id;
 public $document_owner;
 public $description;
 public $ship_to_id;
 public $bill_to_id;
 public $header_amount;
 public $receipt_amount;
 public $currency;
 public $document_currency;
 public $payment_term_id;
 public $receivable_ac_id;
 public $exchange_rate_type;
 public $exchange_rate;
 public $ef_id;
 public $transaction_status;
 public $document_date;
 public $document_number;
 public $ledger_id;
 public $period_id;
 public $payment_term_date;
 public $sales_person;
 public $receipt_method;
 public $approval_status;
 public $receipt_status;
 public $reference_type;
 public $reference_key_name;
 public $reference_key_value;
 public $sd_so_header_id;
 public $gl_journal_header_id;
 public $created_by;
 public $creation_date;
 public $last_update_by;
 public $last_update_date;
 public $customer_name;
 public $customer_number;
 public $sd_so_number;
 public $multi_action_class_pc;
 public $multi_action_class_pc_value;
 public $action;
 public $transaction_action;

 public function __set($name, $value) {
	switch ($value) {
	 case $value:


		break;

	 default:
		$this->$name = $value;
		break;
	}
 }

 private function _update_journalHeaderId() {
	$arth = new ar_transaction_header();
	$arth->ar_transaction_header_id = $this->ar_transaction_header_id;
	$arth->gl_journal_header_id = $this->gl_journal_header_id;
	$arth->created_by = $this->created_by;
	$arth->creation_date = $this->creation_date;
	$arth->last_update_by = $this->last_update_by;
	$arth->last_update_date = $this->last_update_date;
	$arth->save();
 }

 public function _before_save() {

	if ((!empty($this->ar_transaction_header_id)) && ($this->action === 'create_accounting')) {
	 $asis_data = $this->findBy_id($this->ar_transaction_header_id);
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

	if ((!empty($this->ar_transaction_header_id)) && ($this->transaction_action == 'CANCEL')) {
	 $this->_cancel_transaction();
	 return 10;
	}
 }

 public function _after_save() {
	global $db;
	if (!$this->transaction_number) {
	 echo '<br/> No transaction number is entered';
	}
	if ((!empty($this->ar_transaction_header_id)) && empty($this->transaction_number)) {
	 $ar_transaction_header_id = $this->ar_transaction_header_id;
	 $bu_org_id = $this->bu_org_id;
	 $this->transaction_number = $bu_org_id . '-' . $ar_transaction_header_id;
	 echo '<br/> System created transaction number is ' . $this->transaction_number;
	 $this->save();
	}
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
	$gjh->reference_key_value = $this->ar_transaction_header_id;
	$gjh->journal_name = $gjh->journal_category . '-' . $gjh->reference_key_value;
	$gjh->description = $gjh->journal_name . '-' . current_time();
	$gjh->balance_type = 'A';
	$gjh->audit_trial();
	try{
	 $gjh->save();
	 $this->gl_journal_header_id = $gjh->gl_journal_header_id;
	 echo "<br> Jounral Header Id #".$this->gl_journal_header_id. ' is created' ;
	}catch(Exception $e){
	 echo "<br> Failed Saving Jounral Header".$e->getMessage() ;
	}
	
	
 }

 private function _save_journal_lines() {
	$artl = new ar_transaction_line();
	$all_lines = $artl->findBy_parentId($this->ar_transaction_header_id);
	foreach ($all_lines as $lines) {
	 $artd = new ar_transaction_detail();
	 $all_details = $artd->findBy_parentId($lines->ar_transaction_line_id);
	 foreach ($all_details as $deatils) {
		$new_gjl = new gl_journal_line();
		$new_gjl->gl_journal_header_id = $this->gl_journal_header_id;
		$new_gjl->line_num = $deatils->detail_number;
		$new_gjl_i = $new_gjl->findBy_headerId_lineNum();
		if($new_gjl_i){
		$new_gjl->gl_journal_line_id = $new_gjl_i->gl_journal_line_id;
		}
		$new_gjl->status = 'U';
		$new_gjl->code_combination_id = $deatils->detail_ac_id;
		if ($this->transaction_type == 'CREDIT_MEMO') {
		 $new_gjl->total_dr = $deatils->amount;
		 $new_gjl->total_ac_dr = $deatils->amount;
		} else {
		 $new_gjl->total_cr = $deatils->amount;
		 $new_gjl->total_ac_cr = $deatils->amount;
		}
		$new_gjl->description = 'AR Trnx detail #' . $deatils->detail_number . ' of trxn# ' . $this->transaction_number;
		$new_gjl->reference_type = 'table';
		$new_gjl->reference_key_name = 'ar_transaction_detail';
		$new_gjl->reference_key_value = $deatils->ar_transaction_detail_id;
		$new_gjl->audit_trial();
		$new_gjl->save();
	 }
	}

//	save the Receviable Account
  $receviable_gjl = new gl_journal_line();
	$receviable_gjl->gl_journal_header_id = $this->gl_journal_header_id;
	$receviable_gjl->line_num = 999;
	$receviable_gjl_i = $receviable_gjl->findBy_headerId_lineNum();
	if ($receviable_gjl_i) {
	 $receviable_gjl->gl_journal_line_id = $receviable_gjl_i->gl_journal_line_id;
	}
	$receviable_gjl->status = 'U';
	$receviable_gjl->code_combination_id = $this->receivable_ac_id;
		if ($this->transaction_type == 'CREDIT_MEMO') {
	 $receviable_gjl->total_cr = $this->header_amount;
	 $receviable_gjl->total_ac_cr = $this->header_amount;
	} else {
	 $receviable_gjl->total_dr = $this->header_amount;
	 $receviable_gjl->total_ac_dr = $this->header_amount;
	}
	$receviable_gjl->description = 'AR Trnx Receviable of ' . $this->transaction_number;
	$receviable_gjl->reference_type = 'table';
	$receviable_gjl->reference_key_name = 'ar_transaction_header';
	$receviable_gjl->reference_key_value = $this->ar_transaction_header_id;
	$receviable_gjl->audit_trial();
	$receviable_gjl->save();
 }

 public static function instantiate_extra_fields(&$array_of_objects) {
	if (count($array_of_objects) > 0) {
	 foreach ($array_of_objects as &$this_object) {
		$customer_details = customer::find_by_id($this_object->ar_customer_id);
		$this_object->customer_name = $customer_details->customer_name;
		$this_object->customer_number = $customer_details->customer_number;
		$customer_site_details = customer_site::find_by_id($this_object->ar_customer_site_id);
		$this_object->customer_site_name = $customer_site_details->customer_site_name;
	 }
	}
	return $array_of_objects;
 }

 Public static function transaction_types() {
	$option_header = option_header::find_by_name('AR_TRANSACTION_TYPE');
	$transaction_types = option_line::find_by_option_id($option_header->option_header_id);
	return $transaction_types;
 }

 Public static function transaction_action() {
	$option_header = option_header::find_by_name('AR_TRANSACTION_ACTION');
	$transaction_types = option_line::find_by_option_id($option_header->option_header_id);
	return $transaction_types;
 }

 Public static function ar_approval_status() {
	$option_header = option_header::find_by_name('AP_APPROVAL_STATUS');
	$ar_approval_status = option_line::find_by_option_id($option_header->option_header_id);
	return $ar_approval_status;
 }

 public function copy($ar_transaction_header_id) {
	global $db;
	$sql1 = " CREATE TEMPORARY TABLE tmptable SELECT * FROM ar_transaction_header WHERE `ar_transaction_header_id` = '{$ar_transaction_header_id}' ";
	if ($db->query($sql1)) {
	 $sql2 = "  UPDATE tmptable SET `ar_transaction_header_id` = '' ,
           `org_id` = '{$this->org_id}' 
          WHERE `ar_transaction_header_id` = '{$ar_transaction_header_id}' ";
	 if ($db->query($sql2)) {
		$sql3 = " INSERT INTO `ar_transaction_header` SELECT * FROM tmptable WHERE `ar_transaction_header_id` = '' ";
		if ($db->query($sql3)) {
		 $this->ar_transaction_header_id = $db->insert_id();
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
	 $this->ar_approval_status = 'ENTER';
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

 private function _cancel_transaction() {
	if (empty($this->ar_transaction_header_id)) {
	 echo "<br>Cancellation failed!. No transaction header id found.";
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
		echo "Journal Reversal Failed!. Error @ class_ar_transaction_header _cancel_transaction" . $e->getMessage();
		return;
	 }
	}

	//update PO & invoice
	try {
	 $this->_cancel_transaction_poInv_lines();
	 try {
		$this->_cancel_transaction_header();
	 } catch (Exception $e) {
		echo "PO Header Update Failed!. Error @ class_ar_transaction_header _cancel_transaction" . $e->getMessage();
		return;
	 }
	} catch (Exception $e) {
	 echo "PO Detail Update Failed!. Error @ class_ar_transaction_header _cancel_transaction" . $e->getMessage();
	 return;
	}
 }

 private function _cancel_transaction_header() {
	$new_arth = new ar_transaction_header();
	$new_arth_i = $new_arth->findBy_id($this->ar_transaction_header_id);
	$new_arth->arproval_status = 'CANCELLED';
	$new_arth->header_amount = '0.0';
	$new_arth->ar_transaction_header_id = $new_arth_i->ar_transaction_header_id;
	$new_arth->audit_trial();
	pa($new_arth);
	try {
	 $new_arth->save();
	} catch (Exception $e) {
	 echo "AP Transaction Lines Update Failed!. Error @ class_ar_transaction_header _transaction_cancell_poInv_lines " . $e->getMessage();
	 return;
	}
 }


 //needs to be updated after SD SO
 private function _cancel_transaction_poInv_lines() {
	$aptl = new ar_transaction_line();
	$all_lines = $aptl->findBy_parentId($this->ar_transaction_header_id);
	foreach ($all_lines as $lines) {

	 if (!empty($lines->om_so_detail_id)) {
		$om_so_detail = new om_so_detail();
		$om_so_detail_i = $om_so_detail->findBy_id($lines->om_so_detail_id);
		$om_so_detail->om_so_detail_id = $om_so_detail_i->om_so_detail_id;
		$om_so_detail->invoiced_quantity = $om_so_detail->invoiced_quantity - $lines->inv_line_quantity;
		$om_so_detail->audit_trial();
		try {
		 $om_so_detail->save();
		} catch (Exception $e) {
		 echo "PO Details Update Failed!. Error @ class_ar_transaction_header _transaction_cancell_poInv_lines " . $e->getMessage();
		 return;
		}
	 }
//update the invlice details
	 $aptd = new ar_transaction_detail();
	 $all_details = $aptd->findBy_parentId($lines->ar_transaction_line_id);
	 foreach ($all_details as $details) {
		$new_aptd = new ar_transaction_detail();
		$new_aptd_i = $new_aptd->findBy_id($details->ar_transaction_detail_id);
		$new_aptd->status = 'Cancelled';
		$new_aptd->amount = '0.0';
		$new_aptd->ar_transaction_detail_id = $new_aptd_i->ar_transaction_detail_id;
		$new_aptd->audit_trial();
		try {
		 $new_aptd->save();
		} catch (Exception $e) {
		 echo "AP Transaction Details Update Failed!. Error @ class_ar_transaction_header _transaction_cancell_poInv_lines " . $e->getMessage();
		 return;
		}
	 }

	 //update the invoice lines
	 $new_aptl = new ar_transaction_line();
	 $new_aptl_i = $new_aptl->findBy_id($lines->ar_transaction_line_id);
	 $new_aptl->status = 'Cancelled';
	 $new_aptl->inv_line_quantity = '0.0';
	 $new_aptl->inv_line_price = '0.0';
	 $new_aptl->ar_transaction_line_id = $new_aptl_i->ar_transaction_line_id;
	 $new_aptl->audit_trial();
	 try {
		$new_aptl->save();
	 } catch (Exception $e) {
		echo "AP Transaction Lines Update Failed!. Error @ class_ar_transaction_header _transaction_cancell_poInv_lines " . $e->getMessage();
		return;
	 }
	}
 }

 public function get_details_from_om_so_header() {
	if (empty($this->sd_so_header_id)) {
	 return false;
	}
	$po = new om_so_header();
	$om_so_i = $po->findBy_id($this->sd_so_header_id);
	$this->bu_org_id = $om_so_i->bu_org_id;
	$this->transaction_type = 'INVOICE';
	$this->om_so_number = $om_so_i->om_so_number;
	$this->ar_customer_id = $om_so_i->ar_customer_id;
	$this->ar_customer_site_id = $om_so_i->ar_customer_site_id;
	$this->document_currency = $om_so_i->currency;
	$this->payment_term_id = $om_so_i->payment_term_id;
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
			'action'
	];

	return $multi_select_hidden;
 }

}

//end of ar_transaction_header class
?>