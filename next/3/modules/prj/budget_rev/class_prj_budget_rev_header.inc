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
 * prj_budget_header
 *
 */
class prj_budget_rev_header extends dbObject {

 public static $table_name = "prj_budget_rev_header";
 public static $primary_column = "prj_budget_rev_header_id";
 public static $dependent_classes = ['prj_budget_rev_line'];
 public static $key_column = "version_name";
 public static $module = "prj";
 public static $system_info = [
  'name' => 'Project Budget',
  'number' => '6003',
  'description' => 'Project Budget Revision',
  'version' => '0.1.1',
  'db_version' => '1001',
  'mod_version' => '1.1.1',
  'primary_entity_cb' => '',
  'module_name' => 'prj',
  'weight' => 11
 ];

 public $field_a = [
  'prj_budget_rev_header_id',
  'prj_budget_header_id',
  'budget_type',
  'prj_project_header_id',
  'prj_project_line_id',
  'version_number',
  'version_name',
  'description',
  'status',
  'raw_cost',
  'burdened_cost',
  'labor_effort',
  'nlr_effort',
  'revenue',
  'current_cb',
  'original_cb',
  'baselined_by',
  'baselined_cb',
  'baselined_date',
  'created_by',
  'creation_date',
  'last_update_by',
  'last_update_date',
 ];
 public $initial_search = [
  'version_name',
  'version_number',
  'prj_budget_header_id',
 ];
 public $requiredField = [
  'prj_project_header_id',
  'version_name',
 ];
 public $fields_inForm_notInDataBase = [
  "project_number",
  "task_number",
  'action'
 ];
 public $search = [
  '_show_update_path' => 1,
  '_show_view_path' => 1,
 ];
 public $pageTitle = " Project Budget Revision"; //page Title
 public $prj_budget_rev_header_id;
 public $prj_budget_header_id;
 public $budget_type;
 public $prj_project_header_id;
 public $prj_project_line_id;
 public $version_number;
 public $version_name;
 public $description;
 public $status;
 public $raw_cost;
 public $burdened_cost;
 public $labor_effort;
 public $nlr_effort;
 public $revenue;
 public $current_cb;
 public $original_cb;
 public $baselined_by;
 public $baselined_cb;
 public $baselined_date;
 public $created_by;
 public $creation_date;
 public $last_update_by;
 public $last_update_date;
 public $msg;
 public $project_number;
 public $action;

// Public static function validation_types() {
//  $header = option_header::find_by_keyColumn('SYS_VALIDATION_TYPE');
//  $option_line = new option_line();
//  $lines = $option_line->findBy_parentId($header->option_header_id);
//  return $lines;
// }

}

//end of path class
?>