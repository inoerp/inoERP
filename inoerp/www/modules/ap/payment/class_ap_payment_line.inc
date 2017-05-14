<?php

class ap_payment_line extends dbObject {

 public static $table_name = "ap_payment_line";
 public static $primary_column = "ap_payment_line_id";
 public static $parent_primary_column = "ap_payment_header_id";
 public static $multi_search_primary_column = "ap_payment_header_id"; //this value is used in multi search hidden value
 public static $key_column = 'amount';
 public static $module = "ap";
 
  public static $line_status_a = [
		 'CLEARED' => 'Cleared'
 ];
	
 public $field_a = [
  'ap_payment_line_id',
  'ap_payment_header_id',
  'ap_transaction_header_id',
  'line_number',
  'amount',
  'line_description',
  'gl_amount',
  'exchange_rate',
  'line_status',
  'line_source',
  'reference_type',
  'reference_key_name',
  'reference_key_value',
  'period_id',
  'created_by',
  'creation_date',
  'last_update_by',
  'last_update_date'
 ];
 public $requiredField = [
  'ap_payment_header_id',
  'ap_transaction_header_id',
  'line_number'
 ];
 public $numberField = [
  'amount',
  'exchange_rate',
  'gl_amount'
 ];
 public $fields_inForm_notInDataBase = [
  "transaction_number",
  'invoiced_quantity',
  'action',
  'invoice_amount',
  'remaining_amount',
		 'payment_status'
 ];
 public $initial_search = [
  'ap_payment_line_id',
  'ap_payment_header_id',
  'ap_transaction_header_id',
  'line_number',
 ];
 public $fields_inHeader_needsToBeInserted_inPOST = [
  "ap_payment_header_id"
 ];
 public $ap_payment_line_id;
 public $ap_payment_header_id;
 public $ap_transaction_header_id;
 public $line_number;
 public $amount;
 public $line_description;
 public $gl_amount;
 public $exchange_rate;
 public $line_status;
 public $line_source;
 public $reference_type;
 public $reference_key_name;
 public $reference_key_value;
 public $period_id;
 public $created_by;
 public $creation_date;
 public $last_update_by;
 public $last_update_date;
 public $invoice_amount;
 public $remaining_amount;
 public $transaction_number;
 public $paid_amount;
 public $action;
 private $_max_line_num;
 public $lines_from_transaction_header = false;
 public $gl_journal_header_id;
 public $payment_status;

 public function _after_save() {
  if ($this->ap_payment_line_id) {
   //update the invoice paid amount
   try {
    $this->_update_invoice_amount();
   } catch (Exception $e) {
    echo "<br>Updating transaction paid amount failed @ ap_payment_line after save" . $e->getMessage();
   }
  }
 }

 public function _before_save() {

  //create acounting
  if ((!empty($this->ap_payment_header_id)) && (!empty($this->ap_payment_line_id)) && ($this->action === 'create_accounting')) {
	 if(!in_array($this->payment_status,  ['COMPLETE', 'CLEARED'])){
		echo '<br>Payment status does not allow account creation. Complete/Clear the payment';
		return 10;
	 }
	 
   //if journal header id excists then save journal lines only else first header & then lines
   $ap_payment_header = new ap_payment_header();
   $ap_payment_header->findBy_id($this->ap_payment_header_id);
   if (empty($ap_payment_header->gl_journal_header_id)) {
    try {
     $this->_save_journal_header($ap_payment_header);
    } catch (Exception $e) {
     echo "Create accounting failed" . $e->getMessage();
    }
   } else {
    $this->gl_journal_header_id = $ap_payment_header->gl_journal_header_id;
   }

   if (!empty($this->gl_journal_header_id)) {
    //check the status is not updated and then save/update journal lines
    $gjh = new gl_journal_header();
    $gjh->findBy_id($this->gl_journal_header_id);
    $max_line_num = $gjh->highest_line_num()->max_line_num;
    $this->_max_line_num = !empty($max_line_num) ? $max_line_num + 1 : 1;
    if ($gjh->status == 'ENTERED') {
     $this->_save_journal_lines($ap_payment_header);
    } else {
     echo "<br> The Journal Header \" $gjh->journal_name \" (id : $this->gl_journal_header_id ) is not in Entered Status."
     . "<br>From Subledger, You can only update Jouranls in Entered Status";
     return;
    }
   }

   return 10;
  }

  //if there is a line id in the form then return 10 as no changes to paid lines are allowed
  if ($this->ap_payment_line_id) {
   echo "<br>You can't update any payment line. Cancel/Viod the payment if ";
   return 10;
  }
 }

 private function _save_journal_header(&$ap_payment_header) {
  $gjh = new gl_journal_header;
  $gjh->ledger_id = $ap_payment_header->ledger_id;
  $gjh->status = 'ENTERED';
  $gjh->currency = $ap_payment_header->currency;
  $gjh->period_id = $ap_payment_header->period_id;
  $gjh->journal_source = self::$module;
  $gjh->journal_category = 'AP_PAYMENTS';
  $gjh->reference_type = 'table';
  $gjh->reference_key_name = self::$table_name;
  $gjh->reference_key_value = $ap_payment_header->ap_payment_header_id;
  $gjh->journal_name = $gjh->journal_category . '-' . $gjh->reference_key_value;
  $gjh->description = $gjh->journal_name . '-' . current_time();
  $gjh->balance_type = 'A';
  $gjh->audit_trial();
  try {
   $gjh->save();
   $this->gl_journal_header_id = $gjh->gl_journal_header_id;
   echo "<br> Jounral Header Id #" . $this->gl_journal_header_id . ' is created';
   //need to create a new insatnce of ap_transaction_header as the gl_journal_header_id is not allowed to updated from webform
   $ap_th = new ap_payment_header();
   $ap_th->findBy_id($this->ap_payment_header_id);
   $ap_th->gl_journal_header_id = $gjh->gl_journal_header_id;
   $ap_th->audit_trial();
   $ap_th->save();
  } catch (Exception $e) {
   echo "<br> Failed Saving Journal Header" . $e->getMessage();
  }
 }

 private function _save_journal_lines(&$ap_payment_header) {
  global $dbc;
  $ret = 1;
//	Dr the liability account 
  $appc = new ap_payable_control();
  $appc->findBy_orgId($ap_payment_header->bu_org_id);
//  
//  pa($this);

  $invoice_lia_accoutns = gl_journal_line_v::find_by_referenceDetails('ap_transaction_header', $this->ap_transaction_header_id, 'cr');

  if ($invoice_lia_accoutns) {
   if (count($invoice_lia_accoutns) > 1) {
    echo '<div class="error-msg">Multiple credit lines found for the invoice. Correct the invoice journal '
    . 'Journal header id is ' . $invoice_lia_accoutns[0]->gl_journal_header_id . ' </div>';
    $ret = -99;
   } else {
    $liability_account_id = $invoice_lia_accoutns[0]->code_combination_id;
   }
  } else {
   echo '<div class="error-msg">Invoice journals not found. Check if the invoice is accounted. </div>';
   $ret = -99;
  }

  if ($ret < 0) {
   $dbc->rollback = true;
   return $ret;
  }

  $liability_gjl = new gl_journal_line();
  $liability_gjl->gl_journal_header_id = $this->gl_journal_header_id;
  $liability_gjl->line_num = 1;
  $liability_gjl->reference_type = 'table';
  $liability_gjl->reference_key_name = 'ap_payment_line';
  $liability_gjl->reference_key_value = $this->ap_payment_line_id;
  //check if line lready exists
  $jl_exists = $liability_gjl->findBy_reference_keyName_keyValue();
  if ($jl_exists) {
   $liability_gjl->gl_journal_line_id = $jl_exists->gl_journal_line_id;
   $liability_gjl->line_num = $jl_exists->line_num;
   $liability_gjl->status = $jl_exists->status;
  } else {
   $liability_gjl->gl_journal_line_id = null;
   $liability_gjl->line_num = $this->_max_line_num;
   $liability_gjl->status = 'U';
   $this->_max_line_num++;
  }
  $liability_gjl->code_combination_id = $liability_account_id;
  $liability_gjl->total_dr = $this->gl_amount;
  $liability_gjl->total_ac_dr = $this->gl_amount;
  $liability_gjl->description = 'AP Trnx Liability of ' . $ap_payment_header->payment_number;

  try {
   $liability_gjl->save();
   echo "<br> Supplier Liability Ac is Debited. Journal Line Id is " . $liability_gjl->gl_journal_line_id;
  } catch (Exception $e) {
   echo "<br>Updating gl journal line for Libaility Ac failed" . $e->getMessage();
  }
  //	Cr the cash account 
  /*
   * Check the processing method of the paymen. If cash account exists then use it else use the default BU cash account
   */
  $cash_ac_id = null;
  if (!empty($this->processing_method)) {
   $processing_met_d = ap_payment_process::find_by_id($ap_payment_header->processing_method);
   if ($processing_met_d && !empty($processing_met_d->cash_ac_id)) {
    $cash_ac_id = $processing_met_d->cash_ac_id;
   }
  }

  if (empty($cash_ac_id)) {
   $bu_org = new business();
   $bu_org->org_id = $ap_payment_header->bu_org_id;
   $bu_org_i = $bu_org->findBy_orgId();
   if ($bu_org_i->cash_ac_id) {
    $cash_ac_id = $bu_org_i->cash_ac_id;
   } else {
    $dbc->rollback = true;
    echo '<div class="error-msg">No cash account found. You can assign cash accounts either in the processing method or in the business unit. </div>';
    return -99;
   }
  }

  $cash_gjl = new gl_journal_line();
  $cash_gjl->gl_journal_header_id = $this->gl_journal_header_id;
  $cash_gjl->reference_type = 'table';
  $cash_gjl->reference_key_name = 'ap_payment_header';
  $cash_gjl->reference_key_value = $this->ap_payment_header_id;

  //check if line already exists
  $jl_exists_cash = $cash_gjl->findBy_reference_keyName_keyValue();
  
  if ($jl_exists_cash) {
   $cash_gjl->gl_journal_line_id = $jl_exists_cash->gl_journal_line_id;
   $cash_gjl->line_num = $jl_exists_cash->line_num;
   $cash_gjl->status = $jl_exists_cash->status;
  } else {
   $cash_gjl->gl_journal_line_id = null;
   $cash_gjl->line_num = $this->_max_line_num;
   $cash_gjl->status = 'U';
   $this->_max_line_num++;
  }
  $cash_gjl->code_combination_id = $cash_ac_id;
  $cash_gjl->total_cr = $ap_payment_header->header_amount;
  $cash_gjl->total_ac_cr = $ap_payment_header->header_amount;
  $cash_gjl->description = 'AP Payment of ' . $ap_payment_header->payment_number;
  $cash_gjl->audit_trial();

  try {
   $cash_gjl->save();
   echo "<br> Cash Ac is Cr. Journal Line Id is " . $cash_gjl->gl_journal_line_id;
  } catch (Exception $e) {
   echo "<br>Updating gl journal line for Cash Ac failed" . $e->getMessage();
  }
 }

 private function _update_invoice_amount() {
  if (!empty($this->ap_transaction_header_id)) {
   $apth = new ap_transaction_header();
   $apth->findBy_id($this->ap_transaction_header_id);
   $apth->ap_transaction_header_id = $this->ap_transaction_header_id;
   $apth->paid_amount += $this->amount;
   if ($apth->paid_amount <= $apth->header_amount) {
    if ($apth->paid_amount == $apth->header_amount) {
     $apth->payment_status = 'FULLY_PAID';
    } else {
     $apth->payment_status = 'PARTITALY_PAID';
    }

    $apth->audit_trial();
    $apth->save();
   } else {
    echo "<br> The Transaction# $apth->transaction_number is fully paid ";
    $this->rollback = true;
   }
  }
 }

 private function _highest_line_number_from_header() {
  global $db;
  $sql = " SELECT max(line_number) as line_number FROM " . self::$table_name;
  $sql .= " WHERE ap_payment_header_id= :ap_payment_header_id ";
  $param_a = ['ap_payment_header_id'];
  $value_a = ['ap_payment_header_id' => $this->ap_payment_header_id];
  $result = $db->findBy_sql($sql, $param_a, $value_a);
  return !empty($result) ? array_pop($result) : 0;
 }

 Public static function ap_payment_line_types() {
  $option_header = option_header::find_by_name('PO_LINE_TYPE');
  $po_types = option_line::find_by_option_id($option_header->option_header_id);
  return $po_types;
 }

 public static function find_by_ap_payment_headerId($ap_payment_header_id) {
  $sql = "SELECT * FROM " . self::$table_name . " where ap_payment_header_id = '{$ap_payment_header_id}'";
  $result_array = self::find_by_sql($sql);
  return $result_array;
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

 public function copy($ap_payment_line_id) {
  global $db;
  $sql1 = " CREATE TEMPORARY TABLE tmptable SELECT * FROM ap_payment_line WHERE `ap_payment_line_id` = '{$ap_payment_line_id}' ";
  if ($db->query($sql1)) {
   $sql2 = "  UPDATE tmptable SET `ap_payment_line_id` = '' ,
           `org_id` = '{$this->org_id}' 
          WHERE `ap_payment_line_id` = '{$ap_payment_line_id}' ";
   if ($db->query($sql2)) {
    $sql3 = " INSERT INTO `ap_payment_line` SELECT * FROM tmptable WHERE `ap_payment_line_id` = '' ";
    if ($db->query($sql3)) {
     $this->ap_payment_line_id = $db->insert_id();
     $this->msg = 1;
    } else {
     $this->msg = 0;
    }
   }
  }
  return $this->msg;
 }

}

//end of ap_payment_line class
?>