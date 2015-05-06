<?php

class fa_book_category_association extends dbObject {

 public static $table_name = "fa_book_category_association";
 public static $primary_column = "fa_book_category_association_id";
 public static $parent_primary_column = "fa_asset_category_id";
 public static $key_column = 'fa_asset_book_id';
 public static $module = "ap";
 public $field_a = [
  'fa_book_category_association_id',
  'fa_asset_category_id',
  'fa_asset_book_id',
  'asset_cost_ac_id',
  'asset_clearing_ac_id',
  'depreciation_expense_ac_id',
  'accumulated_depreciation_ac_id',
  'description',
  'bonus_expense_ac_id',
  'bonus_reserve_ac_id',
  'revalue_reserve_ac_id',
  'cip_cost_ac_id',
  'cip_clearing_ac_id',
  'unplanned_depreciation_expense_ac_id',
  'created_by',
  'creation_date',
  'last_update_by',
  'last_update_date',
 ];
 public $initial_search = [
  "fa_asset_category_id"
 ];
 public $requiredField = [
  'fa_asset_category_id',
  'fa_asset_book_id',
  'asset_cost_ac_id',
  'asset_clearing_ac_id',
  'depreciation_expense_ac_id',
  'accumulated_depreciation_ac_id',
  'cip_cost_ac_id',
  'cip_clearing_ac_id'
 ];
// public static $addressField = [
//  "site_address_id"
// ];
 public static $fields_inHeader_needsToBeInserted_inPOST = [
  'supplier_id'
 ];
 public $number_fields = [
  'fa_book_category_association_id',
  'fa_asset_category_id',
  'fa_asset_book_id',
  'asset_cost_ac_id',
  'asset_clearing_ac_id',
  'depreciation_expense_ac_id',
  'accumulated_depreciation_ac_id',
  'bonus_expense_ac_id',
  'bonus_reserve_ac_id',
  'revalue_reserve_ac_id',
  'cip_cost_ac_id',
  'cip_clearing_ac_id',
  'unplanned_depreciation_expense_ac_id',
 ];
 public $search = [
  '_update_path' => 'form.php?class_name=supplier',
  '_update_action_meassge' => 'Update',
 ];
 public $pageTitle = " Supplier Sites "; //page Title
 public $option_lists = [
  'fa_book_category_association_type' => 'SUPPLIER_SITE_TYPE',
  'ap_pay_on' => 'AP_PAY_ON'
 ];
 public $fa_book_category_association_id;
 public $fa_asset_category_id;
 public $fa_asset_book_id;
 public $asset_cost_ac_id;
 public $asset_clearing_ac_id;
 public $depreciation_expense_ac_id;
 public $accumulated_depreciation_ac_id;
 public $description;
 public $bonus_expense_ac_id;
 public $bonus_reserve_ac_id;
 public $revalue_reserve_ac_id;
 public $cip_cost_ac_id;
 public $cip_clearing_ac_id;
 public $unplanned_depreciation_expense_ac_id;
 public $created_by;
 public $creation_date;
 public $last_update_by;
 public $last_update_date;

 public static function find_by_asset_book_and_category($fa_asset_book_id, $fa_asset_category_id) {
  $sql = " SELECT * FROM ";
  $sql .= self::$table_name;
  $sql .= " WHERE fa_asset_book_id = '{$fa_asset_book_id}' ";
  $sql .= " AND fa_asset_category_id = '{$fa_asset_category_id}' ";
  $result_array = self::find_by_sql($sql);
  return !empty($result_array) ? array_pop($result_array) : false;
 }

 public static function find_all_sitesOfSupplier($supplier_id = "") {
  $sql = " SELECT * FROM ";
  $sql .= self::$table_name;
  $sql .= " WHERE supplier_id = '{$supplier_id}' ";

  $result = self::find_by_sql($sql);
  return $result;
 }

}

//end of fa_book_category_association class
?>