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
 * am_maintenance_schedule
 * Fixed maintenance_schedule Class controls all the financial information such as reservation, depreciation, retired account etc.
 * 
 */
// public $rev_enabled_cb;  needs to be dropped - use am_maintenance_schedule rev only
class am_maintenance_schedule extends dbObject {

 public static $table_name = "am_maintenance_schedule";
 public static $primary_column = "am_maintenance_schedule_id";
 public static $dependent_classes = ['am_ms_activity_reference'];
 public static $key_column = 'schedule_name';
 public static $module = "am";
// public static $js_fileName = 'modules/inv/am_maintenance_schedule/js/multi_select.js';
 public static $system_info = [
  'name' => 'Maintenance Schedule',
  'number' => '4104',
  'description' => 'Maintenance Schedule',
  'version' => '0.1.4',
  'db_version' => '1001',
  'mod_version' => '1.1.1',
  'primary_entity_cb' => '',
  'module_name' => 'am',
  'weight' => 1
 ];
 public static $schedule_basis_a = [
  'BASE_DATE' => 'Base Date',
  'ACTUATL_START_DATE' => 'Actual Start Date',
  'ACTUATL_END_DATE' => 'Actual End Date'
 ];
 public static $schedule_method_a = [
  'FORWARD' => 'Forward From Start Date',
  'BACKWARD' => 'BAckward From End Data'
 ];
 public static $status_a = [
  'ACTIVE' => 'Active',
  'INACTIVE' => 'Inactive',
  'PLANNING_ONLY' => 'Planning Only'
 ];
 public $checkbox = [
  "create_wo_cb",
  'reschedule_wo_cb'
 ];
 public $field_a = [
  'am_maintenance_schedule_id',
  'schedule_name',
  'schedule_number',
  'item_id_m',
  'am_asset_id',
  'effective_start_date',
  'effective_end_date',
  'wo_status',
  'description',
  'intervals_per_cycle',
  'create_wo_cb',
  'current_cycle',
  'current_cycle_interval',
  'schedule_basis',
  'schedule_basis_date',
  'schedule_method',
  'reschedule_wo_cb',
  'org_id',
  'address_id',
  'status',
  'created_by',
  'creation_date',
  'last_update_by',
  'last_update_date',
 ];
 public $initial_search = [
  'schedule_name',
 ];
 public $requiredField = [
  'schedule_name',
  'org_id',
  'schedule_basis',
  'schedule_basis_date',
  'schedule_method',
 ];
 public $fields_inForm_notInDataBase = [
  "am_asset_number",
  'item_number',
 ];
 public $search = [
  '_show_update_path' => 1,
  '_update_action_meassge' => 'Update',
  '_show_view_path' => 1,
 ];
 public $pageTitle = " Maintenance Scheduler "; //page Title
 public $am_maintenance_schedule_id;
 public $schedule_name;
 public $am_asset_id;
 public $item_id_m;
 public $schedule_number;
 public $effective_end_date;
 public $effective_start_date;
 public $wo_status;
 public $description;
 public $intervals_per_cycle;
 public $create_wo_cb;
 public $current_cycle;
 public $current_cycle_interval;
 public $schedule_basis;
 public $schedule_basis_date;
 public $schedule_method;
 public $reschedule_wo_cb;
 public $org_id;
 public $address_id;
 public $created_by;
 public $creation_date;
 public $last_update_by;
 public $last_update_date;
 public $am_asset_number;
 public $item_number;

 public function findBy_am_maintenance_schedule_id_m($am_maintenance_schedule_id) {
  $sql = " SELECT * FROM ";
  $sql .= self::$table_name;
  $sql .= " WHERE am_maintenance_schedule_id = am_maintenance_schedule_id_m ";
  $sql .= " AND am_maintenance_schedule_id = '{$am_maintenance_schedule_id}' ";
  $result = $this->findBySql($sql);
  return !empty($result) ? array_pop($result) : false;
 }

 public static function find_all_assigned_orgs($am_maintenance_schedule_number) {
  global $db;
  $sql = "SELECT * FROM " .
   self::$table_name .
   " where am_maintenance_schedule_number= '{$am_maintenance_schedule_number}' ";
  $result = $db->find_by_sql($sql);
  return $result;
 }
 
  public function findBy_orgId_itemIdM_otherDetails() {
  $sql = " SELECT * FROM ";
  $sql .= self::$table_name;
  $sql .= " WHERE item_id_m = '{$this->item_id_m}' ";
  $sql .= " AND org_id = '{$this->org_id}' ";
  $sql .= " AND status = 'ACTIVE' ";
  $sql .= " AND ( effective_start_date IS NULL OR effective_start_date <= NOW() ) ";
  $sql .= " AND ( effective_end_date IS NULL OR effective_end_date > NOW() ) ";
  
  $result = $this->findBySql($sql);
  return !empty($result) ? $result : false;
 }
 
   public function findBy_orgId_assetId_otherDetails() {
  $sql = " SELECT * FROM ";
  $sql .= self::$table_name;
  $sql .= " WHERE am_asset_id = '{$this->am_asset_id}' ";
  $sql .= " AND org_id = '{$this->org_id}' ";
  $sql .= " AND status = 'ACTIVE' ";
  $sql .= " AND ( effective_start_date IS NULL OR effective_start_date <= NOW() ) ";
  $sql .= " AND ( effective_end_date IS NULL OR effective_end_date > NOW() ) ";
  
  $result = $this->findBySql($sql);
  return !empty($result) ? $result : false;
 }

}

//end of am_maintenance_schedule class
?>