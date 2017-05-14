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
 * prj_resource_list_line
 *
 */
class prj_resource_list_line extends dbObject {

 public static $table_name = "prj_resource_list_line";
 public static $primary_column = "prj_resource_list_line_id";
 public static $parent_primary_column = "prj_resource_list_header_id";
 public static $key_column = "resource_type";
 public static $module = "prj";
 public static $resource_type_a = [
  'HR_EMPLOYEE' => 'Employee',
  'HR_JOB' => 'Job',
  'ORG' => 'Business Org',
  'PRJ_EXPENDITURE_TYPE' => 'Expenditure Type',
  'REVENUE_CATEGORY'  => 'Revenue Category',
  'EXPENDITURE_CATEGORY' => 'Expenditure Category'
 ];
 public $field_a = [
  'prj_resource_list_line_id',
  'prj_resource_list_header_id',
  'resource_type',
  'effective_from',
  'description',
  'effective_to',
  'hr_employee_id',
  'hr_job_id',
  'org_id',
  'prj_expenditure_type_id',
  'revenue_category',
  'expenditure_category',
  'created_by',
  'creation_date',
  'last_update_by',
  'last_update_date',
 ];
 public $initial_search = [
  'resource_type',
 ];
 public $requiredField = [
  'prj_resource_list_header_id',
  'resource_type',
 ];
 public $search = [
  '_show_update_path' => 1,
  '_show_view_path' => 1,
 ];
 
  public $fields_inForm_notInDataBase = [
  "employee_name",
 ];
  
 public $pageTitle = "Resource List"; //page Title
 public $prj_resource_list_line_id;
 public $prj_resource_list_header;
 public $resource_type;
 public $effective_from;
 public $description;
 public $effective_to;
 public $hr_employee_id;
 public $hr_job_id;
 public $org_id;
 public $prj_expenditure_type_id;
 public $revenue_category;
 public $expenditure_category;
 public $created_by;
 public $creation_date;
 public $last_update_by;
 public $last_update_date;
 public $employee_name;

 Public static function validation_types() {
  $header = option_line::find_by_keyColumn('SYS_VALIDATION_TYPE');
  $option_line = new option_line();
  $lines = $option_line->findBy_parentId($header->option_line_id);
  return $lines;
 }

 public static function staticVar_init($staticvar) {
  foreach (self::${$staticvar} as $key => $value) {
   self::${$staticvar}[$key] = gettext($value);
  }
 }

}

//end of path class
prj_resource_list_line::staticVar_init('resource_type_a');
?>
