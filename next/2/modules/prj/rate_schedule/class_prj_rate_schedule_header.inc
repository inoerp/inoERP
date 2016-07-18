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
 * prj_rate_schedule_header
 *
 */
class prj_rate_schedule_header extends dbObject {

 public static $table_name = "prj_rate_schedule_header";
 public static $primary_column = "prj_rate_schedule_header_id";
 public static $dependent_classes = ['prj_rate_schedule_line'];
 public static $key_column = "schedule_name";
 public static $module = "prj";
 public static $system_info = [
  'name' => 'Rate Schedule',
  'number' => '6016',
  'description' => 'Rate Schedule',
  'version' => '0.1.1',
  'db_version' => '1001',
  'mod_version' => '1.1.1',
  'primary_entity_cb' => '',
  'module_name' => 'prj',
  'weight' => 11
 ];
 
 public static $rate_type_a = [
  'EMPLOYEE' => 'Employee',
  'JOB' => 'Job',
  'NON_LABOR' => 'Non Labor',
  'RESOURCE_CLASS' => 'Resource Class'
 ];
 public $field_a = [
  'prj_rate_schedule_header_id',
  'bu_org_id',
  'schedule_name',
  'rate_type',
  'description',
  'effective_from',
  'effective_to',
  'created_by',
  'creation_date',
  'last_update_by',
  'last_update_date',
 ];
 public $initial_search = [
  'schedule_name',
  'description',
 ];
 public $requiredField = [
  'bu_org_id',
  'schedule_name',
 ];
 public $search = [
  '_show_update_path' => 1,
  '_show_view_path' => 1,
 ];
 public $pageTitle = " Project Resource Schedule "; //page Title
 public $prj_rate_schedule_header_id;
 public $bu_org_id;
 public $schedule_name;
 public $rate_type;
 public $description;
 public $effective_from;
 public $effective_to;
 public $created_by;
 public $creation_date;
 public $last_update_by;
 public $last_update_date;
 public $msg;

 Public static function validation_types() {
  $header = option_header::find_by_keyColumn('SYS_VALIDATION_TYPE');
  $option_line = new option_line();
  $lines = $option_line->findBy_parentId($header->option_header_id);
  return $lines;
 }
 
 
 public static function find_all_by_rateType($rate_type='EMPLOYEE'){
  
  $sql = " SELECT * FROM ";
  $sql .= self::$table_name ;
  $sql .= " WHERE rate_type = '{$rate_type}' " ;
  
  $result = self::find_by_sql($sql);
  
  return !empty($result) ? $result : false;
 }

}

//end of path class
?>
