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
 * ap_payment_schedule 
 *
 */
class ap_payment_schedule extends dbObject {

 public static $table_name = "ap_payment_schedule";
 public static $primary_column = "ap_payment_schedule_id";
 public static $key_column = 'ar_transaction_line_id';
 public static $parent_primary_column = "ar_transaction_header_id";
 public static $module = "ar";
 public static $system_info = [
  'name' => 'Payment Schedule',
  'number' => '1309',
  'description' => 'Revenue Schedule',
  'version' => '0.1.1',
  'db_version' => '1001',
  'mod_version' => '1.1.1',
  'primary_entity_cb' => '',
  'module_name' => 'ar',
  'weight' => 5
 ];
 public static $gl_journal_category = "AR_INVOICE";
 public static $adjustment_type_a = [
  'ADJ' => 'Adjustment'
 ];
//  data base variables as stored database column name
 public $field_a = [
  'revenue_schedule_id',
  'ar_transaction_header_id',
  'ar_transaction_line_id',
  'gl_date',
  'amount',
  'percentage',
  'description',
  'account_class',
  'gl_ac_id',
  'status',
  'reference_type',
  'reference_key_name',
  'reference_key_value',
  'gl_journal_header_id',
  'gl_journal_line_id',
  'created_by',
  'creation_date',
  'last_update_by',
  'last_update_date'
 ];
//variables used for showing data
 public $initial_search = [
  'ar_transaction_header_id',
  'description',
 ];
 public $fields_inForm_notInDataBase = [
  'transaction_number',
  'line_number',
  'transaction_status',
  'adjustment_type',
  'inv_line_price',
  'transaction_type',
  'transaction_class',
  'inv_unit_price',
  'document_owner',
  'trnx_description',
  'currency',
  'doc_currency',
  'exchange_rate_type',
  'trnx_exchange_rate',
  'document_date',
  'document_number',
  'ledger_id',
  'trnx_period_id',
 ];
 public $fields_inHeader_needsToBeInserted_inPOST = [
  'org_id',
  'ar_transaction_header_id'
 ];
 public $requiredField = [
  'ar_transaction_header_id',
  'gl_date',
  'amount',
  'ar_transaction_line_id',
 ];
 public $profile_default = [
  'org_id' => 'org_bu_name_default',
 ];
 public $search = [
  '_show_update_path' => 1,
  '_show_view_path' => 1,
 ];
 public $pageTitle = "Revenue Schedule"; //page Title
 public $revenue_schedule_id;
 public $ar_transaction_header_id;
 public $ar_transaction_line_id;
 public $gl_date;
 public $amount;
 public $percentage;
 public $description;
 public $account_class;
 public $status;
 public $reference_type;
 public $reference_key_name;
 public $reference_key_value;
 public $gl_journal_header_id;
 public $gl_journal_line_id;
 public $created_by;
 public $creation_date;
 public $last_update_by;
 public $last_update_date;
 public $gl_ac_id;

 private function _save_journal_header($ar_trnx_h) {
  $gjh = new gl_journal_header;

  if (empty($this->period_id)) {
   $gp = new gl_period();
   $current_open_period = $gp->current_open_period($ar_trnx_h->ledger_id);
   $gjh->period_id = $current_open_period->gl_period_id;
  } else {
   $gjh->period_id = $this->period_id;
  }

  $gjh->ledger_id = $ar_trnx_h->ledger_id;
  $gjh->status = 'ENTERED';
  $gjh->currency = $ar_trnx_h->currency;

  $gjh->journal_source = self::$module;
  $gjh->journal_category = self::$gl_journal_category;
  $gjh->reference_type = 'table';
  $gjh->reference_key_name = self::$table_name;
  $gjh->reference_key_value = $this->ap_payment_schedule_id;
  $gjh->journal_name = $gjh->journal_category . '-' . $gjh->reference_key_value;
  $gjh->description = $gjh->journal_name . '-' . current_time();
  $gjh->balance_type = 'A';
  $gjh->save();
  $this->gl_journal_header_id = $gjh->gl_journal_header_id;
  $this->update($this->ap_payment_schedule_id);
  echo "<br> The New Journal Header Id is " . $this->gl_journal_header_id;
  return $gjh->gl_journal_header_id;
 }

 private function _save_journal_lines($ar_trnx_h) {
  global $dbc;
//create 1st line
  $new_gjl = new gl_journal_line();
  $new_gjl->gl_journal_header_id = $this->gl_journal_header_id;
  $new_gjl->line_num = 1;
  $new_gjl->status = 'U';

  if ($this->adjustment_amount > 0) {
   $new_gjl->total_dr = $this->adjustment_amount;
   $new_gjl->total_ac_dr = $this->gl_adjustment_amount;
   $new_gjl->code_combination_id = $ar_trnx_h->receivable_ac_id;
  } else {
   $new_gjl->total_cr = $this->adjustment_amount;
   $new_gjl->total_ac_cr = $this->gl_adjustment_amount;
   $new_gjl->code_combination_id = $this->adjustment_ac_id;
  }
  $new_gjl->description = 'AR Transaction Adjustment ' . $this->ap_payment_schedule_id;
  $new_gjl->reference_type = 'table';
  $new_gjl->reference_key_name = 'ap_payment_schedule_id';
  $new_gjl->reference_key_value = $this->ap_payment_schedule_id;
  $new_gjl->save();

//create2nd line
  $new_gjl2 = new gl_journal_line();
  $new_gjl2->gl_journal_header_id = $this->gl_journal_header_id;
  $new_gjl2->line_num = 2;
  $new_gjl2->status = 'U';

  if ($this->adjustment_amount > 0) {
   $new_gjl2->total_cr = $this->adjustment_amount;
   $new_gjl2->total_ac_cr = $this->gl_adjustment_amount;
   $new_gjl2->code_combination_id = $this->adjustment_ac_id;
  } else {
   $new_gjl2->total_dr = $this->adjustment_amount;
   $new_gjl2->total_ac_dr = $this->gl_adjustment_amount;
   $new_gjl2->code_combination_id = $ar_trnx_h->receivable_ac_id;
  }
  $new_gjl2->description = 'AR Transaction Adjustment ' . $this->ap_payment_schedule_id;
  $new_gjl2->reference_type = 'table';
  $new_gjl2->reference_key_name = 'ap_payment_schedule_id';
  $new_gjl2->reference_key_value = $this->ap_payment_schedule_id;
  $new_gjl2->save();
 }

 public function _after_save() {
  global $dbc;
//create journals
  if (!empty($this->ap_payment_schedule_id) && empty($this->gl_journal_header_id)) {
   $ar_trnx_h = new ar_transaction_header();
   $ar_trnx_h->findBy_id($this->ar_transaction_header_id);
   try {
    $this->_save_journal_header($ar_trnx_h);
    if (!empty($this->gl_journal_header_id)) {
     $this->_save_journal_lines($ar_trnx_h);
    }
   } Catch (Exceptio $e) {
    echo "<br>Failed to save journals. Error @ " . get_class($this) . ' @@ line ' . __LINE__ . '<br>' . $e->getMessage();
    $dbc->rollback = true;
   }
  }
 }

 public function _before_save() {
  $ret = 1;
  $ar_trnx_h_i = ar_transaction_header::find_by_id($this->ar_transaction_header_id);
  if ($ar_trnx_h_i->transaction_status != 'CLOSED') {
   echo "<div class='alert alert-danger alert-dismissible' role='alert'>The transactio is not yet closed. You can directly modify the transaction</div>";
   return 10;
  }


  if (empty($this->adjustment_ac_id)) {
   try {
    $this->_get_adjustment_ac();
   } catch (Exception $e) {
    $ret = -90;
    echo "<br>No adjustment ac found. Error @ " . get_class($this) . ' @@ line ' . __LINE__ . '<br>' . $e->getMessage();
   }
  }

  if (empty($this->adjustment_date)) {
   $this->adjustment_date = current_time(1);
  }

  return $ret;
 }

 public function save() {
  $primary_column = static::$primary_column;
  if (empty($this->$primary_column)) {
   $this->create();
  } else {
   echo '<div class="message"> You are not allowed to update a completed adjustment!</div>';
  }
  return $this->msg;
 }

 private function _get_adjustment_ac() {
  if (empty($this->ar_receivable_activity_id)) {
   throw new Exception('No receivable activity found');
  } else {
   $this->adjustment_ac_id = ar_receivable_activity::find_by_id($this->ar_receivable_activity_id)->activity_ac_id;
  }
 }

 public static function total_adjustmentAmount_by_transactionHeaderId($ar_transaction_header_id) {
  $sql = " SELECT SUM(adjustment_amount) as adjustment_amount FROM ";
  $sql .= self::$table_name;
  $sql .= " WHERE ar_transaction_header_id = '{$ar_transaction_header_id}' ";

  $result_a = self::find_by_sql($sql);
  return !empty($result_a) ? $result_a[0]->adjustment_amount : '0.00';
 }

}

//end of resource class
?>