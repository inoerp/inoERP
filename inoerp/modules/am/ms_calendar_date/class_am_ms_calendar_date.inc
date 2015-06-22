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
 * Contains all the am_ms_calendar_date information, such as - item_id_m, org_id, subinventory_id, etc.
 * 
 */
class am_ms_calendar_date extends dbObject {

 public static $table_name = "am_ms_calendar_date";
 public static $primary_column = "am_ms_calendar_date_id";
 public static $parent_primary_column = "am_maintenance_schedule_id";
 public static $js_fileName = 'modules/inv/calendar_date/js/multi_select_count.js';
 public static $key_column = "date";
 public static $module = "am";
 public static $system_info = [
  'name' => 'MS Calendar Date',
  'number' => '4108',
  'description' => 'Maintenace Schedule Calendar Date',
  'version' => '0.1.1',
  'db_version' => '1001',
  'mod_version' => '1.1.1',
  'primary_entity_cb' => '',
  'module_name' => 'am',
  'weight' => 5
 ];
 public $field_a = [
  'am_ms_calendar_date_id',
  'am_maintenance_schedule_id',
  'date',
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
  'date',
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
 public $pageTitle = " MS Calendar Date "; //page Title
 public $am_ms_calendar_date_id;
 public $am_maintenance_schedule_id;
 public $date;
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

  $result = self::find_by_sql($sql);
  return !empty($result) ? $result : false;
 }

}

//end of path class
?>