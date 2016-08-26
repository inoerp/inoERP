<?php

class pm_process_operation_line extends dbObject {

 public static $table_name = "pm_process_operation_line";
 public static $primary_column = "pm_process_operation_line_id";
 public static $parent_primary_column = "pm_process_operation_header_id";
 public static $key_column = 'activity_code';
 public static $module = "pm";
 public static $release_type_a = [
  'AUTO' => 'Automatic',
  'MANUAL' => 'Manual'
 ];
 public $field_a = [
  'pm_process_operation_line_id',
  'pm_process_operation_header_id',
  'activity_code',
  'description',
  'activity_factror',
  'sequence_dependency_cb',
  'offset_interval',
  'breakable_cb',
  'material_scheduled_cb',
  'created_by',
  'creation_date',
  'last_update_by',
  'last_update_date',
 ];
 public $requiredField = [
  'pm_process_operation_header_id',
  'activity_code'
 ];
 public $fields_inHeader_needsToBeInserted_inPOST = [
  "pm_process_operation_header_id"
 ];
 public $pm_process_operation_line_id;
 public $pm_process_operation_header_id;
 public $activity_code;
 public $description;
 public $activity_factror;
 public $sequence_dependency_cb;
 public $offset_interval;
 public $breakable_cb;
 public $material_scheduled_cb;
 public $created_by;
 public $creation_date;
 public $last_update_by;
 public $last_update_date;

 public static function find_by_headerId_and_buOrgId($pm_process_operation_header_id, $bu_org_id) {
  $sql = "SELECT * FROM " .
   self::$table_name .
   " where pm_process_operation_header_id= '{$pm_process_operation_header_id}' AND bu_org_id= '{$bu_org_id}'  ";
   $sql = ino_perPageSql_i($sql, 1);
  $result = self::find_by_sql($sql);
  return !empty($result) ? array_pop($result) : false;
 }

}

//end of pm_process_operation_line class
?>