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
 * fa_asset_book_info
 * Fixed Asset Class controls all the financial information such as reservation, depreciation, retired account etc.
 * 
 */
// public $rev_enabled_cb;  needs to be dropped - use fa_asset_book_info rev only
class fa_asset_book_info extends dbObject {

 public static $table_name = "fa_asset_book_info";
 public static $primary_column = "fa_asset_book_info_id";
// public static $dependent_book_infoes = ['inv_fa_asset_book_info_revision'];
 public static $key_column = 'fa_asset_id';
 public static $module = "fa";
// public static $js_fileName = 'modules/inv/fa_asset_book_info/js/multi_select.js';
 public static $system_info = [
  'name' => 'asset_book_info',
  'number' => '1405',
  'description' => 'Fixed Asset Book Information',
  'version' => '0.1.1',
  'db_version' => '1001',
  'mod_version' => '1.1.1',
  'primary_entity_cb' => '',
  'module_name' => 'fa',
  'weight' => 1
 ];
 public $account = [
  "default_ac_id"
 ];
 public static $action_a = [
  '1' => 'Activate',
  '2' => 'Activate WO GL Posting',
  '3' => 'Set for Activation',
 ];
 public static $status_a = [
  '1' => 'Entered',
  '2' => 'Activated',
  '3' => 'Set for Activation',
 ];
 public $field_a = [
  'fa_asset_book_info_id',
  'fa_asset_book_id',
  'fa_asset_id',
  'original_cost',
  'current_cost',
  'referece',
  'description',
  'salvage_value_amount',
  'salvage_value_percentage',
  'fa_depreciation_method_id',
  'life_months',
  'depreciation_cb',
//  'activated_cb',
  'date_in_service',
  'depreciation_start_date',
  'depreciation_limit_amount',
  'depreciation_limit_percentage',
  'status',
  'created_by',
  'creation_date',
  'last_update_by',
  'last_update_date',
 ];
 public $initial_search = [
  'fa_asset_book_info_id',
 ];
 public $numberField = [
  'deprecation_limit_amount',
  'depreciation_limit_percentage',
  'salvage_value_amount',
  'salvage_value_percentage',
  'original_cost',
  'current_cost',
  'ytd_depreciation',
  'accumulated_depreciation',
 ];
 public $requiredField = [
  'fa_asset_book_id',
  'fa_asset_id',
  'original_cost',
  'current_cost',
 ];
 public $fields_inForm_notInDataBase = [
  'ytd_depreciation',
  'new_current_cost',
  'accumulated_depreciation',
  'asset_number',
  'asset_book_name',
  'current_cost',
  'recoverable_amount',
  'recoverable_percentage',
  'action'
 ];
 public $search = [
  '_show_update_path' => 1,
  '_update_action_meassge' => 'Update',
  '_show_view_path' => 1,
 ];
 public $pageTitle = " Asset Book Info"; //page Title
 public $fa_asset_book_info_id;
 public $fa_asset_book_id;
 public $fa_asset_id;
 public $referece;
 public $original_cost;
 public $current_cost;
 public $description;
 public $ytd_depreciation;
 public $accumulated_depreciation;
 public $salvage_value_amount;
 public $salvage_value_percentage;
 public $fa_depreciation_method_id;
 public $life_months;
 public $activated_cb;
 public $status;
 public $depreciation_cb;
 public $new_current_cost;
 public $date_in_service;
 public $depreciation_start_date;
 public $depreciation_limit_amount;
 public $depreciation_limit_percentage;
 public $created_by;
 public $creation_date;
 public $last_update_by;
 public $last_update_date;
 public $asset_book_name;
 public $asset_number;
 public $recoverable_amount;
 public $recoverable_percentage;
 public $action;

 public function _before_save() {
  if (!empty($this->action)) {
   $this->_do_action();
  }

  if (empty($this->status)) {
   $this->status = 1;
  }


  if (!empty($this->new_current_cost)) {
   $this->_costChange_trnx();
   $this->current_cost = $this->new_current_cost;
  }
 }

 private function _costChange_trnx() {
  global $dbc;
  $asset_trnx = new fa_asset_transaction();
  $asset_trnx->fa_asset_id = $this->fa_asset_id;
  $asset_trnx->fa_asset_book_id = $this->fa_asset_book_id;
  $asset_trnx->fa_asset_book_info_id = $this->fa_asset_book_info_id;
  $asset_trnx->transaction_type = 'COST_ADJUST';
  $asset_trnx->reference_type = 'table';
  $asset_trnx->reference_key_name = 'fa_asset_book_info';
  $asset_trnx->reference_type = $this->fa_asset_book_info_id;
  $asset_trnx->create_journal = false;
  $asset_trnx->amout = $this->current_cost;
  try {
   $asset_trnx->_before_save();
   $asset_trnx->save();
   $asset_trnx->_after_save();
   echo '<br>Asset transaction is succesfully completed. Trnx id ' . $asset_trnx->fa_asset_transaction_id;
  } catch (Exception $e) {
   echo '<br>Failed to create asset transaction. Error @ fa_asset_book_info @@ ' . __LINE__ . ' <br> ' . $e->getMessage();
   $dbc->rollback = true;
  }
 }

 public function _after_save() {
  
 }

 private function _do_action() {
  if (empty($this->fa_asset_book_info_id)) {
   echo "<br>First save the record before taking any action";
   return false;
  }
  $fa_asset_book_info_current = self::find_by_id($this->fa_asset_book_info_id);
  if ($fa_asset_book_info_current->status == 2) {
   echo "<br>Asset is already activated. You cant change status from action";
   return false;
  }

  switch ($this->action) {
   case 1:
    $this->_activiate_assetBook();
    break;

   case 2:
    $this->_activiate_assetBook_woPosting();
    break;


   case 3:
    $this->_set_assetBook_forActivation();
    break;
  }
 }

 private function _activiate_assetBook() {
  global $dbc;
  if ($this->status == 1) {
   $this->_create_asset_transaction(1);
   $this->status = 2;
   $this->save();
  } else {
   echo '<br>Asset is already activated. You can not reactivate it. ';
   $dbc->rollback = true;
  }
 }

 private function _activiate_assetBook_woPosting() {
  $this->_create_asset_transaction();
  $this->status = 2;
  $this->save();
 }

 private function _set_assetBook_forActivation() {
  $this->status = 3;
  $this->save();
 }

 private function _create_asset_transaction($create_journal = false) {
  global $dbc;
  $asset_trnx = new fa_asset_transaction();
  $asset_trnx->fa_asset_id = $this->fa_asset_id;
  $asset_trnx->fa_asset_book_id = $this->fa_asset_book_id;
  $asset_trnx->fa_asset_book_info_id = $this->fa_asset_book_info_id;
  $asset_trnx->transaction_type = 'ADD';
  $asset_trnx->reference_type = 'table';
  $asset_trnx->reference_key_name = 'fa_asset_book_info';
  $asset_trnx->reference_type = $this->fa_asset_book_info_id;
  if ($create_journal) {
   $asset_trnx->create_journal = 1;
  }
  $asset_trnx->amout = $this->current_cost;
  try {
   $asset_trnx->_before_save();
   $asset_trnx->save();
   $asset_trnx->_after_save();
  } catch (Exception $e) {
   echo '<br>Failed to create asset transaction. Error @ fa_asset_book_info @@ ' . __LINE__ . ' <br> ' . $e->getMessage();
   $dbc->rollback = true;
  }
 }

 Public static function asset_book_info_type() {
  $option_header = option_header::find_by_name('FA_ASSET_CLASS_TYPE');
  $ol = option_line::find_by_option_id($option_header->option_header_id);
  return $ol;
 }

 public function findBy_assetId_bookId() {
  $sql = " SELECT * FROM ";
  $sql .= self::$table_name;
  $sql .= " WHERE fa_asset_id = :fa_asset_id ";
  $sql .= " AND fa_asset_book_id = :fa_asset_book_id ";
  $value_a = ['fa_asset_id' => $this->fa_asset_id, 'fa_asset_book_id' => $this->fa_asset_book_id];
  $result = $this->findBySql($sql, $value_a);
  return !empty($result) ? array_pop($result) : false;
 }

 public static function find_by_assetId_bookId($fa_asset_book_id, $fa_asset_id) {
  $sql = "SELECT * FROM " .
   self::$table_name .
   " where fa_asset_book_id= '{$fa_asset_book_id}'  AND fa_asset_id = '{$fa_asset_id}' ";
  $result = self::find_by_sql($sql);
  return !empty($result) ? array_pop($result) : false;
 }

 public function findBy_bookId() {
  $sql = " SELECT * FROM ";
  $sql .= self::$table_name;
  $sql .= " WHERE fa_asset_book_id = :fa_asset_book_id ";
  $value_a = [ 'fa_asset_book_id' => $this->fa_asset_book_id];
  $result = $this->findBySql($sql, $value_a);
  return !empty($result) ? ($result) : false;
 }

 public static function find_by_bookId($fa_asset_book_id) {
  $sql = "SELECT * FROM " .
   self::$table_name .
   " where fa_asset_book_id= '{$fa_asset_book_id}'  ";
  $result = self::find_by_sql($sql);
  return !empty($result) ? ($result) : false;
 }

}

//end of fa_asset_book_info class
?>