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
 * am_activity_reference
 * Fixed Asset Class controls all the financial information such as reservation, depreciation, retired account etc.
 * 
 */
// public $rev_enabled_cb;  needs to be dropped - use am_activity_reference rev only
class am_activity_reference extends dbObject {

 public static $table_name = "am_activity_reference";
 public static $primary_column = "am_activity_reference_id";
 public static $parent_primary_column = "am_asset_id";
 public static $key_column = 'activity_item_id_m';
 public static $module = "am";
// public static $js_fileName = 'modules/inv/am_activity_reference/js/multi_select.js';
 public static $system_info = [
  'name' => 'Activity Reference',
  'number' => '4102',
  'description' => 'Activity Reference',
  'version' => '0.1.4',
  'db_version' => '1001',
  'mod_version' => '1.1.1',
  'primary_entity_cb' => '',
  'module_name' => 'am',
  'weight' => 1
 ];
 public $checkbox = [
  "physical_inventory_cb"
 ];
 public $field_a = [
  'am_activity_reference_id',
  'am_asset_id',
  'activity_item_id_m',
  'priority',
  'start_date',
  'end_date',
  'description',
  'activity_cause',
  'activity_type',
  'accounting_class_id',
  'owning_department_id',
  'shutdown_type',
  'activity_source',
  'created_by',
  'creation_date',
  'last_update_by',
  'last_update_date',
 ];
 public $initial_search = [
  'am_asset_id',
 ];
 public $requiredField = [
  'am_asset_id',
  'activity_item_id_m',
 ];
 public $fields_inForm_notInDataBase = [
  'activity_item_number'
 ];
 public $search = [
  '_show_update_path' => 1,
  '_update_action_meassge' => 'Update',
  '_show_view_path' => 1,
 ];
 public $pageTitle = " Asset Maintenance "; //page Title
 public $am_activity_reference_id;
 public $am_asset_id;
 public $activity_item_id_m;
 public $priority;
 public $start_date;
 public $end_date;
 public $description;
 public $activity_cause;
 public $activity_type;
 public $accounting_class_id;
 public $owning_department_id;
 public $shutdown_type;
 public $activity_source;
 public $created_by;
 public $creation_date;
 public $last_update_by;
 public $last_update_date;
 public $activity_item_number;

 public function findBy_am_activity_reference_id_m($am_activity_reference_id) {
  $sql = " SELECT * FROM ";
  $sql .= self::$table_name;
  $sql .= " WHERE am_activity_reference_id = am_activity_reference_id_m ";
  $sql .= " AND am_activity_reference_id = '{$am_activity_reference_id}' ";
  $result = $this->findBySql($sql);
  return !empty($result) ? array_pop($result) : false;
 }

 public static function find_all_assigned_orgs($am_activity_reference_number) {
  global $db;
  $sql = "SELECT * FROM " .
   self::$table_name .
   " where am_activity_reference_number= '{$am_activity_reference_number}' ";
  $result = $db->find_by_sql($sql);
  return $result;
 }

}

//end of am_activity_reference class
?>