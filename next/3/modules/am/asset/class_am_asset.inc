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
 * am_asset
 * Fixed Asset Class controls all the financial information such as reservation, depreciation, retired account etc.
 * 
 */
// public $rev_enabled_cb;  needs to be dropped - use am_asset rev only
class am_asset extends dbObject {

 public static $table_name = "am_asset";
 public static $primary_column = "am_asset_id";
 public static $dependent_classes = ['am_activity_reference'];
 public static $key_column = 'asset_number';
 public static $module = "fa";
// public static $js_fileName = 'modules/inv/am_asset/js/multi_select.js';
 public static $system_info = [
  'name' => 'Asset Maintenance',
  'number' => '4101',
  'description' => 'Asset Maintenance',
  'version' => '0.1.4',
  'db_version' => '1001',
  'mod_version' => '1.1.1',
  'primary_entity_cb' => '',
  'module_name' => 'am',
  'weight' => 1
 ];
 public static $type_a = [
  'COMPONENT' => 'Component',
  'CAPITALIZED' => 'Capitalized',
  'EXPENSED' => 'Expensed',
 ];
 public static $status_a = [
  'ACTIVE' => 'Active',
  'RUNNING' => 'Running',
  'STOPPED' => 'Stopped',
  'MAINTAINED' => 'Maintained',
 ];
 public $checkbox = [
  "physical_inventory_cb"
 ];
 public $field_a = [
  'am_asset_id',
  'asset_number',
  'type',
  'tag_number',
  'serial_number',
  'owning_department_id',
  'owning_employee_id',
  'description',
  'status',
  'am_asset_category_id',
  'wip_accounting_group_id',
  'parent_asset_id',
  'manufacturer',
  'org_id',
  'item_id_m',
  'equipment_item_id_m',
  'model_number',
  'warranty_number',
  'warranty_exp_date',
  'maintainable_cb',
  'subinventory_id',
  'locator_id',
  'address_id',
  'fa_asset_id',
  'production_org_id',
  'created_by',
  'creation_date',
  'last_update_by',
  'last_update_date',
 ];
 public $initial_search = [
  'asset_number',
 ];
 public $requiredField = [
  'asset_number',
  'type',
  'serial_number',
  'owning_department_id',
  'wip_accounting_group_id'
 ];
 public $fields_inForm_notInDataBase = [
  "item_number",
  "item_description",
  'address_name'
 ];
 public $search = [
  '_show_update_path' => 1,
  '_update_action_meassge' => 'Update',
  '_show_view_path' => 1,
 ];
 
  public $profile_default = [
  'org_id' => 'org_inv_name_default',
 ];
  
 public $pageTitle = " Asset Maintenance "; //page Title
 public $am_asset_id;
 public $asset_number;
 public $type;
 public $tag_number;
 public $serial_number;
 public $owning_department_id;
 public $owning_employee_id;
 public $description;
 public $status;
 public $am_asset_category_id;
 public $wip_accounting_group_id;
 public $parent_asset_id;
 public $manufacturer;
 public $org_id;
 public $item_id_m;
 public $equipment_item_id_m;
 public $model_number;
 public $warranty_number;
 public $warranty_exp_date;
 public $maintainable_cb;
 public $subinventory_id;
 public $locator_id;
 public $address_id;
 public $fa_asset_id;
 public $production_org_id;
 public $created_by;
 public $creation_date;
 public $last_update_by;
 public $last_update_date;
 public $item_number;
 public $item_description;
 public $address_name;

 public function findBy_am_asset_id_m($am_asset_id) {
  $sql = " SELECT * FROM ";
  $sql .= self::$table_name;
  $sql .= " WHERE am_asset_id = am_asset_id_m ";
  $sql .= " AND am_asset_id = '{$am_asset_id}' ";
  $result = $this->findBySql($sql);
  return !empty($result) ? array_pop($result) : false;
 }

 public static function find_all_assigned_orgs($am_asset_number) {
  global $db;
  $sql = "SELECT * FROM " .
   self::$table_name .
   " where am_asset_number= '{$am_asset_number}' ";
  $result = $db->find_by_sql($sql);
  return $result;
 }

 public static function find_by_orgId($org_id) {
  global $db;
  $sql = "SELECT * FROM " .
   self::$table_name .
   " where org_id= '{$org_id}' ";
  $result = self::find_by_sql($sql);
  return !empty($result) ? $result : false;
 }

}

//end of am_asset class
?>