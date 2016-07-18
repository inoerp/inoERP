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
 public $checkbox = [
  "depriciation_cb"
 ];
 public $field_a = [
  'fa_asset_book_info_id',
  'fa_asset_book_id',
  'fa_asset_id',
  'original_cost',
  'current_cost',
  'referece',
  'description',
  'ytd_depreciation',
  'accumulated_depreciation',
  'salvage_value_amount',
  'salvage_value_percentage',
  'fa_depreciation_method_id',
  'life_months',
  'depriciation_cb',
  'date_in_service',
  'depriciation_start_date',
  'depriciation_limit_amount',
  'depriciation_limit_percentage',
  'created_by',
  'creation_date',
  'last_update_by',
  'last_update_date',
 ];
 public $initial_search = [
  'fa_asset_book_info_id',
 ];
 public $numberField = [
  'depriciation_limit_amount',
  'depriciation_limit_percentage',
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
  'asset_number',
  'asset_book_name',
  'current_cost',
  'recoverable_amount',
  'recoverable_percentage'
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
 public $depriciation_cb;
 public $date_in_service;
 public $depriciation_start_date;
 public $depriciation_limit_amount;
 public $depriciation_limit_percentage;
 public $created_by;
 public $creation_date;
 public $last_update_by;
 public $last_update_date;
 public $asset_book_name;
 public $asset_number;
 public $recoverable_amount;
 public $recoverable_percentage;

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