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
class prj_budget_header extends dbObject {

 public static $table_name = "prj_budget_header";
 public static $primary_column = "prj_budget_header_id";
 public static $dependent_classes = ['prj_budget_line'];
 public static $key_column = "version_name";
 public static $module = "prj";
 public static $system_info = [
  'name' => 'Project Budget',
  'number' => '6025',
  'description' => 'Project Budget',
  'version' => '0.1.1',
  'db_version' => '1001',
  'mod_version' => '1.1.1',
  'primary_entity_cb' => '',
  'module_name' => 'prj',
  'weight' => 11
 ];
 public $action_a = [
  'BASELINE' => 'Base Line',
  'MAKE_ORIGINAL' => 'Make Original',
  'MAKE_CURRENT' => 'Make Current',
  'NEW_REVISION' => 'New Revision',
 ];
 public $field_a = [
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
 public $pageTitle = " Project Budget "; //page Title
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

 public function _before_save() {

  if (!empty($this->action)) {
   $this->_do_action();
  }
 }

 private function _do_action() {
  global $ino_user;
  switch ($this->action) {
   case 'BASELINE':
    $this->baselined_cb = 1;
    $this->baselined_date = current_time(1);
    $this->baselined_by = $ino_user->username;
    break;

   case 'MAKE_ORIGINAL':
    $this->original_cb = 1;
    break;

   case 'MAKE_CURRENT':
    $this->current_cb = 1;
    break;

   case 'NEW_REVISION':
    $this->_create_new_revision();
    $this->version_number += 1;
    break;

   default :
    break;
  }
 }

 private function _create_new_revision() {
  $budget_rev_h = new prj_budget_rev_header();
  foreach ($budget_rev_h->field_a as $k => $v) {
   if (property_exists($budget_rev_h, $v)) {
    $budget_rev_h->$v = $this->$v;
   }
  }
  $budget_rev_h->save();
  
  if(empty($budget_rev_h->prj_budget_rev_header_id)){
   throw new Exception('No prj_budget_rev_header_id found');
  }

  $budget_lines = prj_budget_line::find_by_parent_id($this->prj_budget_header_id);
  foreach ($budget_lines as $budget_line) {
   $budget_rev_l = new prj_budget_rev_line();
   $budget_rev_l->prj_budget_rev_header_id = $budget_rev_h->prj_budget_rev_header_id;
   foreach ($budget_rev_l->field_a as $k => $v_line) {
    if (property_exists($budget_line, $v_line)) {
     $budget_rev_l->$v_line = $budget_line->$v_line;
    }
   }
   $budget_rev_l->save();
  }
 }

}

//end of path class
?>