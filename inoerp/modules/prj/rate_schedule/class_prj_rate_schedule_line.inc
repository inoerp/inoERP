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
 * prj_rate_schedule_line
 *
 */
class prj_rate_schedule_line extends dbObject {

 public static $table_name = "prj_rate_schedule_line";
 public static $primary_column = "prj_rate_schedule_line_id";
 public static $parent_primary_column = "prj_rate_schedule_header_id";
 public static $key_column = "reference_key_value";
 public static $module = "prj";
 public static $resource_type_a = [
  'HR_EMPLOYEE' => 'Employee',
  'HR_JOB' => 'Job',
  'ORG' => 'Business Org',
  'PRJ_EXPENDITURE_TYPE' => 'Expenditure Type',
  'REVENUE_CATEGORY' => 'Revenue Category',
  'EXPENDITURE_CATEGORY' => 'Expenditure Category'
 ];
 public $field_a = [
  'prj_rate_schedule_line_id',
  'prj_rate_schedule_header_id',
  'reference_key_name',
  'effective_from',
  'description',
  'effective_to',
  'reference_key_value',
  'uom_id',
  'rate',
  'mark_up_percentage',
  'resource_name',
  'created_by',
  'creation_date',
  'last_update_by',
  'last_update_date',
 ];
 public $initial_search = [
  'resource_type',
 ];
 public $requiredField = [
  'prj_rate_schedule_header_id',
  'reference_key_name',
  'reference_key_value',
  'uom_id',
 ];
 public $search = [
  '_show_update_path' => 1,
  '_show_view_path' => 1,
 ];
 public $fields_inForm_notInDataBase = [
  "employee_name",
 ];
 public $pageTitle = "Resource Rate"; //page Title
 public $prj_rate_schedule_line_id;
 public $prj_rate_schedule_header_id;
 
 public $effective_from;
 public $description;
 public $effective_to;
 public $reference_key_name;
 public $reference_key_value;
 public $uom_id;
 public $rate;
 public $resource_name;
 public $mark_up_percentage;
 public $created_by;
 public $creation_date;
 public $last_update_by;
 public $last_update_date;
 public $employee_name;
 
  Public static function resource_class() {
  $header = option_header::find_by_keyColumn('PRJ_RESOURCE_CLASS');
  $option_line = new option_line();
  $lines = $option_line->findBy_parentId($header->option_header_id);
  return $lines;
 }

 public static function staticVar_init($staticvar) {
  foreach (self::${$staticvar} as $key => $value) {
   self::${$staticvar}[$key] = gettext($value);
  }
 }

}

//end of path class
prj_rate_schedule_line::staticVar_init('resource_type_a');
?>
