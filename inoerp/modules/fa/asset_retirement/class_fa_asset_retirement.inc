<?php

/**
 * inoERP
 *
 * @copyright   2014 Nishit R. Das
 * @license     https://www.mozilla.org/MPL/2.0/
 * @link        http://inoideas.org
 * @retirement code https://github.com/inoerp/inoERP
 */

/**
 * fa_asset_retirement 
 *
 */
class fa_asset_retirement extends dbObject {

 public static $table_name = "fa_asset_retirement";
 public static $primary_column = "fa_asset_retirement_id";
 public static $key_column = 'fa_asset_id';
 public static $parent_primary_column = "fa_asset_id";
 public static $module = "fa";
 public static $system_info = [
  'name' => 'Asset Retirement',
  'number' => '2605',
  'description' => 'Asset Retirement',
  'version' => '0.1.1',
  'db_version' => '1001',
  'mod_version' => '1.1.1',
  'primary_entity_cb' => '',
  'module_name' => 'fa',
  'weight' => 5
 ];
//  data base variables as stored database column name
 public $field_a = [
  'fa_asset_retirement_id',
  'fa_asset_id',
  'fa_asset_book_id',
  'source_type',
  'reference',
  'status',
  'description',
  'retired_units',
  'retired_cost',
  'proceed_of_sales',
  'cost_of_removals',
  'retirement_convention',
  'retire_date',
  'created_by',
  'creation_date',
  'last_update_by',
  'last_update_date',
 ];
//variables used for showing data
 public $initial_search = [
  'fa_asset_id',
  'reference',
 ];
 public $fields_inForm_notInDataBase = [
  'asset_number',
  'asset_description',
  'status',
  'type',
  'asset_book_name',
  'original_cost',
  'current_cost',
  'ytd_depreciation',
  'accumulated_depreciation',
 ];
 public $fields_inHeader_needsToBeInserted_inPOST = [
  'fa_asset_id',
 ];
 public $requiredField = [
  'fa_asset_id'
 ];
 public $search = [
  '_show_update_path' => 1,
  '_show_view_path' => 1,
 ];
 public $pageTitle = " Asset Retirement "; //page Title
 public $fa_asset_retirement_id;
 public $fa_asset_id;
 public $fa_asset_book_id;
 public $source_type;
 public $reference;
 public $status;
 public $description;
 public $retired_units;
 public $retired_cost;
 public $proceed_of_sales;
 public $cost_of_removals;
 public $retirement_convention;
 public $retire_date;
 public $created_by;
 public $creation_date;
 public $last_update_by;
 public $last_update_date;
 public $asset_number;
 public $asset_description;
 public $asset_book_name;
 public $original_cost;
 public $current_cost;
 public $ytd_depreciation;
 public $accumulated_depreciation;

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

}

//end of reretirement class
?>