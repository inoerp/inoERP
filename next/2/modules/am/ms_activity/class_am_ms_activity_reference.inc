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
 * am_ms_activity_reference
 * Fixed Asset Class controls all the financial information such as reservation, depreciation, retired account etc.
 * 
 */
// public $rev_enabled_cb;  needs to be dropped - use am_ms_activity_reference rev only
class am_ms_activity_reference extends dbObject {

 public static $table_name = "am_ms_activity_reference";
 public static $primary_column = "am_ms_activity_reference_id";
 public static $key_column = 'activity_item_id_m';
 public static $parent_primary_column = "am_maintenance_schedule_id";
 public static $module = "am";
// public static $js_fileName = 'modules/inv/am_ms_activity_reference/js/multi_select.js';
 public static $system_info = [
  'name' => 'MS Activity Reference',
  'number' => '1401',
  'description' => 'MS Activity Reference',
  'version' => '0.1.4',
  'db_version' => '1001',
  'mod_version' => '1.1.1',
  'primary_entity_cb' => '',
  'module_name' => 'am',
  'weight' => 1
 ];
 public $checkbox = [
  "physical_inventory_cb",
  'repeat_in_cycle_cb'
 ];
 public $field_a = [
  'am_ms_activity_reference_id',
  'am_maintenance_schedule_id',
  'activity_item_id_m',
  'last_date',
  'start_date',
  'end_date',
  'description',
  'interval_multiple',
  'repeat_in_cycle_cb',
  'last_cb',
  'created_by',
  'creation_date',
  'last_update_by',
  'last_update_date',
 ];
 public $initial_search = [
  'am_asset_id',
 ];
 public $requiredField = [
  'am_maintenance_schedule_id',
  'activity_item_id_m',
 ];
 public $fields_inForm_notInDataBase = [
  'activity_item_number',
  'activity_item_description'
 ];
 public $search = [
  '_show_update_path' => 1,
  '_update_action_meassge' => 'Update',
  '_show_view_path' => 1,
 ];
 public $pageTitle = " MS Activity Reference "; //page Title
 public $am_ms_activity_reference_id;
 public $am_maintenance_schedule_id;
 public $activity_item_id_m;
 public $last_date;
 public $start_date;
 public $end_date;
 public $description;
 public $interval_multiple;
 public $repeat_in_cycle_cb;
 public $last_cb;
 public $created_by;
 public $creation_date;
 public $last_update_by;
 public $last_update_date;
 public $activity_item_number;

 public function findBy_am_ms_activity_reference_id_m($am_ms_activity_reference_id) {
  $sql = " SELECT * FROM ";
  $sql .= self::$table_name;
  $sql .= " WHERE am_ms_activity_reference_id = am_ms_activity_reference_id_m ";
  $sql .= " AND am_ms_activity_reference_id = '{$am_ms_activity_reference_id}' ";
  $result = $this->findBySql($sql);
  return !empty($result) ? array_pop($result) : false;
 }

 public static function find_all_assigned_orgs($am_ms_activity_reference_number) {
  global $db;
  $sql = "SELECT * FROM " .
   self::$table_name .
   " where am_ms_activity_reference_number= '{$am_ms_activity_reference_number}' ";
  $result = $db->find_by_sql($sql);
  return $result;
 }
 
  public static function find_by_scheduleId($am_maintenance_schedule_id) {
  $sql = "SELECT * FROM " .
   self::$table_name .
   " where am_maintenance_schedule_id= '{$am_maintenance_schedule_id}' ";
  $result = self::find_by_sql($sql);
  return !empty($result) ? $result : false;
 }

}

//end of am_ms_activity_reference class
?>