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
 * Contains all the am_ms_meter_rule information, such as - item_id_m, org_id, subinventory_id, etc.
 * 
 */
class am_ms_meter_rule extends dbObject {

 public static $table_name = "am_ms_meter_rule";
 public static $primary_column = "am_ms_meter_rule_id";
 public static $parent_primary_column = "am_maintenance_schedule_id";
 public static $js_fileName = 'modules/inv/meter_rule/js/multi_select_count.js';
 public static $key_column = "base_interval";
 public static $module = "am";
 public static $system_info = [
  'name' => 'MS Meter Rule',
  'number' => '4111',
  'description' => 'Maintenace Schedule Meter Rule',
  'version' => '0.1.1',
  'db_version' => '1001',
  'mod_version' => '1.1.1',
  'primary_entity_cb' => '',
  'module_name' => 'am',
  'weight' => 5
 ];
 public $field_a = [
  'am_ms_meter_rule_id',
  'am_maintenance_schedule_id',
  'am_meter_id',
  'from_date',
  'to_date',
  'base_interval',
  'cycle_interval',
  'last_reading',
  'created_by',
  'creation_date',
  'last_update_by',
  'last_update_date'
 ];
 public $initial_search = [
  'am_maintenance_schedule_id',
 ];
 public $requiredField = [
  'am_maintenance_schedule_id',
  'am_meter_id',
  'base_interval',
  'cycle_interval',
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
  'org_id',
  'meter_name',
  'rate',
  'uom_id',
  'rate'
 ];
 public $pageTitle = " MS Meter Rule "; //page Title
 public $am_ms_meter_rule_id;
 public $am_maintenance_schedule_id;
 public $am_meter_id;
 public $meter_name;
 public $from_date;
 public $to_date;
 public $base_interval;
 public $cycle_interval;
 public $last_reading;
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
 public $rate;
 public $uom_id;

}

//end of path class
?>