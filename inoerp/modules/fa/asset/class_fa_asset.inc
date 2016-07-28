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
 * fa_asset
 * Fixed Asset Class controls all the financial information such as reservation, depreciation, retired account etc.
 * 
 */
// public $rev_enabled_cb;  needs to be dropped - use fa_asset rev only
class fa_asset extends dbObject {

 public static $table_name = "fa_asset";
 public static $primary_column = "fa_asset_id";
 public static $dependent_classes = ['fa_asset_assignment'];
 public static $key_column = 'asset_number';
 public static $module = "fa";
// public static $js_fileName = 'modules/inv/fa_asset/js/multi_select.js';
 public static $system_info = [
  'name' => 'Fixed Asset',
  'number' => '1407',
  'description' => 'Fixed Asset',
  'version' => '0.1.4',
  'db_version' => '1001',
  'mod_version' => '1.1.1',
  'primary_entity_cb' => '',
  'module_name' => 'fa',
  'weight' => 1
 ];
 public static $status_a = [
  'ACTIVE' => 'Active',
  'RETIRED' => 'Retired',
  'HOLD_DEPRECIATION' => 'Hold Depreciation',
 ];
 public static $type_a = [
  'CIP' => 'In Progress',
  'CAPITALIZED' => 'Capitalized',
  'EXPENSED' => 'Expensed',
 ];
 public $checkbox = [
  "physical_inventory_cb"
 ];
 public $field_a = [
  'fa_asset_id',
  'asset_number',
  'type',
  'tag_number',
  'serial_number',
  'key_number',
  'description',
  'status',
  'fa_asset_category_id',
  'units',
  'parent_asset_id',
  'manufacturer',
  'ap_supplier_id',
  'ap_supplier_site_id',
  'model_number',
  'warrranty_number',
  'lease_number',
  'physical_inventory_cb',
  'rev_enabled',
  'rev_number',
  'created_by',
  'creation_date',
  'last_update_by',
  'last_update_date',
 ];
 public $initial_search = [
  'fa_asset_id',
 ];
 public $requiredField = [
  'asset_number',
  'fa_asset_category_id',
  'units',
 ];
 public static $json_label_fields = [
  'asset_number',
  'asset_type',
  'asset_tag_number',
  'asset_serial_number',
  'asset_key_number',
  'asset_description',
  'fa_asset_id'
 ];
 public $fields_inForm_notInDataBase = [
 ];
 public $search = [
  '_show_update_path' => 1,
  '_update_action_meassge' => 'Update',
  '_show_view_path' => 1,
 ];
 public $pageTitle = " Fixed Asset"; //page Title
 public $fa_asset_id;
 public $asset_number;
 public $type;
 public $tag_number;
 public $serial_number;
 public $key_number;
 public $description;
 public $status;
 public $fa_asset_category_id;
 public $units;
 public $parent_asset_id;
 public $manufacturer;
 public $ap_supplier_id;
 public $ap_supplier_site_id;
 public $model_number;
 public $warrranty_number;
 public $lease_number;
 public $physical_inventory_cb;
 public $rev_enabled;
 public $rev_number;
 public $created_by;
 public $creation_date;
 public $last_update_by;
 public $last_update_date;

 public function findBy_fa_asset_id_m($fa_asset_id) {
  $sql = " SELECT * FROM ";
  $sql .= self::$table_name;
  $sql .= " WHERE fa_asset_id = fa_asset_id_m ";
  $sql .= " AND fa_asset_id = '{$fa_asset_id}' ";
  $result = $this->findBySql($sql);
  return !empty($result) ? array_pop($result) : false;
 }

 public static function find_all_assigned_orgs($fa_asset_number) {
  global $db;
  $sql = "SELECT * FROM " .
   self::$table_name .
   " where fa_asset_number= '{$fa_asset_number}' ";
  $result = $db->find_by_sql($sql);
  return $result;
 }
 
 public static function find_by_ColumnNameVal($columnName, $columnVal, $dependent_fields = '', $hidden_fields = '') {
  $sql = " SELECT   asset_number,
         type as asset_type, tag_number as asset_tag_number , serial_number as asset_serial_number,
         key_number as asset_key_number , description as asset_description, fa_asset_id
            FROM " . static::$table_name . " where " . $columnName . " LIKE  '%{$columnVal}%'  ";
  if (!empty($dependent_fields)) {
   foreach ($dependent_fields as $k => $v) {
    if (!empty($k) && !empty($v)) {
     $sql .= " AND $k = '{$v}' ";
    }
   }
  }

  if (!empty($hidden_fields)) {
   foreach ($hidden_fields as $k1 => $v1) {
    if (!empty($k1) && !empty($v1)) {
     $sql .= " AND $k1 = '{$v1}' ";
    }
   }
  }
//  echo $sql;
  $result_array = static::find_by_sql($sql);
  return !empty($result_array) ? ($result_array) : false;
 }


}

//end of fa_asset class
?>