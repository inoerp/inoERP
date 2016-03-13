<?php

class pm_process_operation_line extends dbObject {

 public static $table_name = "pm_process_operation_line";
 public static $primary_column = "pm_process_operation_line_id";
 public static $parent_primary_column = "pm_process_operation_header_id";
 public static $key_column = 'step_no';
 public static $module = "pm";
 
  public static $release_type_a = [
  'AUTO' => 'Automatic',
  'MANUAL' => 'Manual'
 ];
  
 public $field_a = [
  'pm_process_operation_line_id',
  'pm_process_operation_header_id',
  'step_no',
  'pm_operion_header_id',
  'uom_id',
  'release_type',
  'min_quantity',
  'description',
  'step_quantity',
  'created_by',
  'creation_date',
  'last_update_by',
  'last_update_date',
 ];
 public $requiredField = [
  'pm_process_operation_header_id',
  'step_no'
 ];
 public $fields_inHeader_needsToBeInserted_inPOST = [
  "pm_process_operation_header_id"
 ];
 public $pm_process_operation_line_id;
 public $pm_process_operation_header_id;
 public $step_no;
 public $pm_operion_header_id;
 public $uom_id;
 public $release_type;
 public $min_quantity;
 public $description;
 public $step_quantity;
 public $created_by;
 public $creation_date;
 public $last_update_by;
 public $last_update_date;

 public static function find_by_headerId_and_buOrgId($pm_process_operation_header_id, $bu_org_id) {
  $sql = "SELECT * FROM " .
   self::$table_name .
   " where pm_process_operation_header_id= '{$pm_process_operation_header_id}' AND bu_org_id= '{$bu_org_id}' LIMIT 1 ";
  $result = self::find_by_sql($sql);
  return !empty($result) ? array_pop($result) : false;
 }

}

//end of pm_process_operation_line class
?>