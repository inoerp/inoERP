<?php

class fa_asset_transaction extends dbObject {

 public static $table_name = "fa_asset_transaction";
 public static $primary_column = "fa_asset_transaction_id";
 public static $parent_primary_column = "fa_asset_id";
 public static $key_column = "fa_asset_id";
 public static $module = "fa";
 public static $gl_journal_category_a = [
  'ADD' => 'FA_ADITTION',
  'RET' => 'FA_RETIREMENT',
  'ADJUST' => 'FA_ADJUSTMENT',
  'TRANSFER' => 'FA_TRANSFER',
  'COST_ADJUST' => 'FA_COST_ADJUSTMENT',
 ];
 public static $system_info = [
  'name' => 'Asset  Transaction',
  'number' => '1413',
  'description' => 'FA Asset Transaction',
  'version' => '0.1.1',
  'db_version' => '1001',
  'mod_version' => '1.1.1',
  'primary_entity_cb' => '',
  'module_name' => 'fa',
  'weight' => 6
 ];
 public static $transaction_type_a = [
  'ADD' => 'Addition',
  'RET' => 'Retirement',
  'ADJUST' => 'Adjsument',
  'TRANSFER' => 'Transfer',
  'COST_ADJUST' => 'Cost Adjustment',
 ];
 public $field_a = [
  'fa_asset_transaction_id',
  'fa_asset_id',
  'fa_asset_book_info_id',
  'fa_asset_book_id',
  'transaction_type',
  'quantity',
  'amout',
  'gl_journal_header_id',
  'gl_journal_line_id',
  'description',
  'reference_type',
  'reference_key_name',
  'reference_key_value',
  'created_by',
  'creation_date',
  'last_update_by',
  'last_update_date',
 ];
 public $initial_search = [
  'fa_asset_transaction_id',
  'fa_asset_id',
  'transaction_type',
 ];
 public $requiredField = [
  'fa_asset_id',
  'transaction_type',
 ];
 public $fields_inForm_notInDataBase = [
  'asset_number',
  'asset_type',
  'tag_number',
  'serial_number',
  'key_number',
  'asset_description',
 ];
 public $pageTitle = "Asset Transactions  "; //page Title
 public $fa_asset_transaction_id;
 public $fa_asset_id;
 public $transaction_type;
 public $quantity;
 public $amout;
 public $gl_journal_header_id;
 public $gl_journal_line_id;
 public $description;
 public $fa_asset_book_info_id;
 public $fa_asset_book_id;
 public $reference_type;
 public $reference_key_name;
 public $reference_key_value;
 public $create_journal = false;
 public $created_by;
 public $creation_date;
 public $last_update_by;
 public $last_update_date;

 public function _before_save() {
//  return 10;
 }

 public function _after_save() {
  if ($this->create_journal) {
   $this->_create_journal_header();
   if (!empty($this->gl_journal_header_id)) {
    $this->_create_journal_lines();
   }
  }
 }

 private function _create_journal_header() {
  global $dbc;
  $asset_book_i = fa_asset_book::find_by_id($this->fa_asset_book_id);
  $fin_info = org::find_financial_details_from_orgId($asset_book_i->bu_org_id);

  $gp = new gl_period();
  $current_open_period = $gp->current_open_period($fin_info->ledger_id);

  $gjh = new gl_journal_header;
  $gjh->ledger_id = $fin_info->ledger_id;
  $gjh->status = 'ENTERED';
  $gjh->currency = $fin_info->currency_code;
  $gjh->period_id = $current_open_period->gl_period_id;
  $gjh->journal_source = self::$module;
  $gjh->journal_category = self::$gl_journal_category_a[$this->transaction_type];
  $gjh->reference_type = 'table';
  $gjh->reference_key_name = self::$table_name;
  $gjh->reference_key_value = $this->fa_asset_transaction_id;
  $gjh->journal_name = $gjh->journal_category . '-' . $gjh->reference_key_value;
  $gjh->description = $gjh->journal_name . '-' . current_time();
  $gjh->balance_type = 'A';
  $gjh->status = 'U';
  try {
   $gjh->save();
   $this->gl_journal_header_id = $gjh->gl_journal_header_id;
   echo "<br> Jounral Header Id #" . $this->gl_journal_header_id . ' is created';
   $this->save();
  } catch (Exception $e) {
   $dbc->rollback = 1;
   echo "<br> Failed Saving Jounral Header . Error @ fa_asset_tranaction @@ " . __LINE__ . ' <br> ' . $e->getMessage();
  }
 }

 private function _create_journal_lines() {
  global $dbc;
  $fa_book_category_assoc_i = fa_book_category_assoc::find_all_accounts_byAssetBookId($this->fa_asset_id, $this->fa_asset_book_id);
  if (empty($fa_book_category_assoc_i)) {
   $dbc->rollback = 1;
   echo "<br>fa_book_category_assoc is missing";
   return;
  } else if (empty($fa_book_category_assoc_i->asset_cost_ac_id) || empty($fa_book_category_assoc_i->asset_clearing_ac_id)) {
   $dbc->rollback = 1;
   echo "<br>cost or clearing account is missing for fa_book_category_assoc";
   return;
  }

  $new_gjl = new gl_journal_line();
  $new_gjl->gl_journal_header_id = $this->gl_journal_header_id;
  $new_gjl->line_num = 1;
  $new_gjl->status = 'U';
  $new_gjl->code_combination_id = $fa_book_category_assoc_i->asset_cost_ac_id;
  $new_gjl->total_dr = $new_gjl->total_ac_dr = $this->amout;
  $new_gjl->description = 'Transaction ' . $this->transaction_type . ' for asset id ' . $this->fa_asset_id;
  $new_gjl->reference_type = 'table';
  $new_gjl->reference_key_name = self::$table_name;
  $new_gjl->reference_key_value = $this->fa_asset_transaction_id;
  $new_gjl->save();

  $new_gjl1 = new gl_journal_line();
  $new_gjl1->gl_journal_header_id = $this->gl_journal_header_id;
  $new_gjl1->line_num = 2;
  $new_gjl1->status = 'U';
  $new_gjl1->code_combination_id = $fa_book_category_assoc_i->asset_clearing_ac_id;
  $new_gjl1->total_cr = $new_gjl1->total_ac_cr = $this->amout;
  $new_gjl1->description = 'Transaction ' . $this->transaction_type . ' for asset id ' . $this->fa_asset_id;
  $new_gjl1->reference_type = 'table';
  $new_gjl1->reference_key_name = self::$table_name;
  $new_gjl1->reference_key_value = $this->fa_asset_transaction_id;
  $new_gjl1->save();
 }

 public static function find_by_invTransactionId($inv_transaction_id) {
  $sql = " SELECT * FROM ";
  $sql .= self::$table_name;
  $sql .= " WHERE inv_transaction_id = '{$inv_transaction_id}'  ";
  $result = self::find_by_sql($sql);
  return !empty($result) ? ($result) : false;
 }

 public static function find_by_invSerialNumberId($fa_asset_number_id) {
  $sql = " SELECT * FROM ";
  $sql .= self::$table_name;
  $sql .= " WHERE fa_asset_number_id = '{$fa_asset_number_id}'  ";
  $result = self::find_by_sql($sql);
  return !empty($result) ? ($result) : false;
 }

}

//end of path class
?>