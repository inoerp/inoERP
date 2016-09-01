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
 * ar_transaction_adjustment 
 *
 */
class ar_transaction_adjustment extends dbObject {

 public static $table_name = "ar_transaction_adjustment";
 public static $primary_column = "ar_transaction_adjustment_id";
 public static $key_column = 'ar_transaction_line_id';
 public static $parent_primary_column = "ar_transaction_header_id";
 public static $module = "ar";
 public static $system_info = [
  'name' => 'Transaction Adjustments',
  'number' => '2610',
  'description' => 'Transaction Adjustments',
  'version' => '0.1.1',
  'db_version' => '1001',
  'mod_version' => '1.1.1',
  'primary_entity_cb' => '',
  'module_name' => 'ar',
  'weight' => 5
 ];
 public static $gl_journal_category = "AR_ADJUSTMENT";
 public static $adjustment_type_a = [
  'ADJ' => 'Adjustment'
 ];
//  data base variables as stored database column name
 public $field_a = [
  'ar_transaction_adjustment_id',
  'ar_transaction_header_id',
  'ar_receivable_activity_id',
  'adjustment_amount',
  'gl_adjustment_amount',
  'exchange_rate',
  'adjustment_quantity',
  'description',
  'adjustment_date',
  'adjustment_ac_id',
  'ar_transaction_line_id',
  'reason',
  'status',
  'line_source',
  'reference_type',
  'reference_key_name',
  'reference_key_value',
  'period_id',
  'gl_journal_header_id',
  'created_by',
  'creation_date',
  'last_update_by',
  'last_update_date'
 ];
//variables used for showing data
 public $initial_search = [
  'ar_transaction_header_id',
  'ar_receivable_activity_id',
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
  'ar_receivable_activity_id',
  'adjustment_amount',
  'adjustment_ac_id',
  'ar_transaction_line_id',
 ];
 public $profile_default = [
  'org_id' => 'org_bu_name_default',
 ];
 public $search = [
  '_show_update_path' => 1,
  '_show_view_path' => 1,
 ];
 public $pageTitle = "Transaction Adjustments"; //page Title
 public $ar_transaction_adjustment_id;
 public $ar_transaction_header_id;
 public $ar_receivable_activity_id;
 public $adjustment_amount;
 public $adjustment_quantity;
 public $exchange_rate;
 public $gl_adjustment_amount;
 public $description;
 public $adjustment_date;
 public $adjustment_ac_id;
 public $ar_transaction_line_id;
 public $reason;
 public $status;
 public $line_source;
 public $reference_type;
 public $reference_key_name;
 public $reference_key_value;
 public $period_id;
 public $gl_journal_header_id;
 public $created_by;
 public $creation_date;
 public $last_update_by;
 public $last_update_date;
 public $transaction_number;
 public $line_number;
 public $transaction_status;
 public $adjustment_type;
 public $inv_line_price;
 public $transaction_type;
 public $transaction_class;
 public $inv_unit_price;
 public $document_owner;
 public $trnx_description;
 public $currency;
 public $doc_currency;
 public $exchange_rate_type;
 public $trnx_exchange_rate;
 public $document_date;
 public $document_number;
 public $ledger_id;
 public $trnx_period_id;

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
  $gjh->reference_key_value = $this->ar_transaction_adjustment_id;
  $gjh->journal_name = $gjh->journal_category . '-' . $gjh->reference_key_value;
  $gjh->description = $gjh->journal_name . '-' . current_time();
  $gjh->balance_type = 'A';
  $gjh->save();
  $this->gl_journal_header_id = $gjh->gl_journal_header_id;
  $this->update($this->ar_transaction_adjustment_id);
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
  $new_gjl->description = 'AR Transaction Adjustment ' . $this->ar_transaction_adjustment_id;
  $new_gjl->reference_type = 'table';
  $new_gjl->reference_key_name = 'ar_transaction_adjustment_id';
  $new_gjl->reference_key_value = $this->ar_transaction_adjustment_id;
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
  $new_gjl2->description = 'AR Transaction Adjustment ' . $this->ar_transaction_adjustment_id;
  $new_gjl2->reference_type = 'table';
  $new_gjl2->reference_key_name = 'ar_transaction_adjustment_id';
  $new_gjl2->reference_key_value = $this->ar_transaction_adjustment_id;
  $new_gjl2->save();
 }

 public function _after_save() {
  global $dbc;
//create journals
  if (!empty($this->ar_transaction_adjustment_id) && empty($this->gl_journal_header_id)) {
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