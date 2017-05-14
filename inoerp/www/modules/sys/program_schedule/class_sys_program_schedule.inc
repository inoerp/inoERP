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
 * 
 *
 */
class sys_program_schedule extends dbObject {

 public static $table_name = "sys_program_schedule";
 public static $primary_column = "sys_program_schedule_id";
 public static $key_column = 'program_name';
// public static $dependent_classes = ['sys_program_schedule_reference'];
 public static $module = "sys";
 public static $system_info = [
  'name' => 'Program Schedule',
  'number' => '8201',
  'description' => 'Program Schdule',
  'version' => '0.1.1',
  'db_version' => '1001',
  'mod_version' => '1.1.1',
  'primary_entity_cb' => '',
  'module_name' => 'sys',
  'weight' => 13
 ];
 public static $request_type_a = [
  'REPORT' => 'Report',
  'PROGRAM' => 'Program'
 ];
 public static $frequency_uom_a = [
  'MINUTELY' => 'Minutely',
  'HOURLY' => 'Hourly',
  'DAILY' => 'Daily',
  'WEEKLY' => 'Weekly',
  'MONTHLY' => 'Monthly',
  'CALENDAR' => 'Calendar'
 ];
 public $field_a = [
  'sys_program_schedule_id',
  'frequency_uom',
  'frequency_value',
  'one_time_cb',
  'increase_date_parameter_cb',
  'program_name',
  'request_type',
  'description',
  'parameter',
  'module_name',
  'program_class_name',
  'report_query',
  'status',
  'start_date_time',
  'op_email_address',
  'op_email_format',
  'output_path',
  'created_by',
  'creation_date',
  'last_update_by',
  'last_update_date',
 ];
 public $column = [
  'sys_program_schedule_id',
  'frequency_uom',
  'frequency_value',
  'one_time_cb',
  'increase_date_parameter_cb',
  'request_type',
  'program_name',
  'description',
  'module_name',
  'program_class_name',
  'status',
  'start_date_time',
 ];
 public $initial_search = [
  'program_name',
  'description',
  'program_class_name'
 ];
 public $requiredField = [
  'program_name',
  'program_class_name',
 ];
 public $base_encoded_array = [
  "report_query"
 ];
 public $sys_program_schedule_id;
 public $frequency_uom;
 public $frequency_value;
 public $one_time_cb;
 public $increase_date_parameter_cb;
 public $program_name;
 public $description;
 public $parameter;
 public $module_name;
 public $request_type;
 public $program_class_name;
 public $report_query;
 public $status;
 public $start_date_time;
 public $op_email_address;
 public $op_email_format;
 public $output_path;
 public $created_by;
 public $creation_date;
 public $last_update_by;
 public $last_update_date;
 public $search = [
  '_show_update_path' => 1,
  '_show_view_path' => 1,
 ];
 public $pageTitle = " Program Schedule  "; //page Title

 public static function find_by_reference($ref_obj, $ref_id) {
  $sql = " SELECT cont.sys_program_schedule_id,cont.contact_name, cont.last_name, cont.first_name, cont.middle_name, 
   cont.mobile_number, cont.office_number, cont.contact_number2, cont.email_id, cont.website, cont.email_id2,
   cont.fax_no, cont.timezone, cont.time_to_contact, cont.type, cont.status, cont.job_titile, 
   cont.created_by, cont.creation_date, cont.last_update_by, cont.last_update_date, cr.sys_program_schedule_reference_id, 
   cr.sys_program_schedule_id, cr.status, cr.reference_type, cr.reference_table, cr.reference_id, cr.created_by, 
   cr.creation_date, cr.last_update_by, cr.last_update_date 

FROM sys_program_schedule cont,
sys_program_schedule_reference cr 

WHERE cr.sys_program_schedule_id = cont.sys_program_schedule_id
AND cr.reference_table = '{$ref_obj}'
 AND cr.reference_id = '{$ref_id}'
";

  $result = self::find_by_sql($sql);
//  echo $sql; pa($result);
  return !empty($result) ? ($result) : false;
 }

 public static function staticVar_init($staticvar) {
  foreach (self::${$staticvar} as $key => $value) {
   self::${$staticvar}[$key] = gettext($value);
  }
 }

}

//end of sys_program_schedule class
sys_program_schedule::staticVar_init('frequency_uom_a');
?>
