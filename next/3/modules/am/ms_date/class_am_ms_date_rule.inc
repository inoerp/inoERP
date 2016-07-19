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
 * Item
 * Contains all the am_ms_date_rule information, such as - item_id_m, org_id, subinventory_id, etc.
 * 
 */
class am_ms_date_rule extends dbObject {

 public static $table_name = "am_ms_date_rule";
 public static $primary_column = "am_ms_date_rule_id";
 public static $parent_primary_column = "am_maintenance_schedule_id";
 public static $js_fileName = 'modules/inv/date_rule/js/multi_select_count.js';
 public static $key_column = "base_interval_days";
 public static $module = "am";
 public static $system_info = [
  'name' => 'MS Date Rule',
  'number' => '4109',
  'description' => 'Maintenace Schedule Date Rule',
  'version' => '0.1.1',
  'db_version' => '1001',
  'mod_version' => '1.1.1',
  'primary_entity_cb' => '',
  'module_name' => 'am',
  'weight' => 5
 ];
 public $field_a = [
  'am_ms_date_rule_id',
  'am_maintenance_schedule_id',
  'base_interval_days',
  'cycle_interval_days',
  'from_date',
  'to_date',
  'description',
  'created_by',
  'creation_date',
  'last_update_by',
  'last_update_date',
 ];
 public $initial_search = [
  'am_maintenance_schedule_id',
 ];
 public $requiredField = [
  'am_maintenance_schedule_id',
  'base_interval_days',
  'cycle_interval_days',
  'from_date',
 ];
 public $fields_inForm_notInDataBase = [
  'am_maintenance_schedule_id',
  'schedule_name',
  'schedule_number',
  'item_id_m',
  'am_asset_id',
  'effective_from_date',
  'effective_start_date',
  'description',
  "am_asset_number",
  'item_number',
  'org_id'
 ];
 public $pageTitle = " MS Date Rule "; //page Title
 public $am_ms_date_rule_id;
 public $am_maintenance_schedule_id;
 public $base_interval_days;
 public $from_date;
 public $to_date;
 public $description;
 public $created_by;
 public $creation_date;
 public $last_update_by;
 public $last_update_date;
 public $cycle_interval_days;
 public $schedule_name;
 public $am_asset_id;
 public $item_id_m;
 public $schedule_number;
 public $effective_from_date;
 public $effective_start_date;
 public $am_asset_number;
 public $item_number;
 public $org_id;

 public static function find_by_maintenance_schedule_id($am_maintenance_schedule_id) {
  $sql = " SELECT * FROM ";
  $sql .= self::$table_name;
  $sql .= " WHERE am_maintenance_schedule_id = '{$am_maintenance_schedule_id}' ";
  $sql .= " AND ( from_date IS NULL OR from_date <= NOW() ) ";
  $sql .= " AND ( to_date IS NULL OR to_date > NOW() ) ";
  $sql .= " ORDER BY  am_ms_date_rule_id ASC";

  $result = self::find_by_sql($sql);
  return !empty($result) ? array_pop($result) : false;
 }

}

//end of path class
?>