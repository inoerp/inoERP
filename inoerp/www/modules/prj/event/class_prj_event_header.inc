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
 * prj_event_header
 *
 */
class prj_event_header extends dbObject {

 public static $table_name = "prj_event_header";
 public static $primary_column = "prj_event_header_id";
 public static $dependent_classes = ['prj_event_line'];
 public static $key_column = "event_name";
 public static $module = "prj";
 public static $system_info = [
  'name' => 'Project event',
  'number' => '6009',
  'description' => 'Project event',
  'version' => '0.1.1',
  'db_version' => '1001',
  'mod_version' => '1.1.1',
  'primary_entity_cb' => '',
  'module_name' => 'prj',
  'weight' => 11
 ];
 public $field_a = [
  'prj_event_header_id',
  'event_name',
  'description',
  'prj_project_header_id',
  'billing_amount',
  'revenue_amount',
  'event_number',
  'created_by',
  'creation_date',
  'last_update_by',
  'last_update_date',
 ];
 public $initial_search = [
  'event_name',
  'description',
 ];
 public $requiredField = [
  'event_name',
  'prj_project_header_id',
 ];
 public $fields_inForm_notInDataBase = [
  "project_number",
  "task_number",
 ];
 public $search = [
  '_show_update_path' => 1,
  '_show_view_path' => 1,
 ];
 public $pageTitle = " Project Event "; //page Title
 public $prj_event_header_id;
 public $event_name;
 public $description;
 public $prj_project_header_id;
 public $billing_amount;
 public $revenue_amount;
 public $event_number;
 public $created_by;
 public $creation_date;
 public $last_update_by;
 public $last_update_date;
 public $project_number;

// Public static function validation_types() {
//  $header = option_header::find_by_keyColumn('SYS_VALIDATION_TYPE');
//  $option_line = new option_line();
//  $lines = $option_line->findBy_parentId($header->option_header_id);
//  return $lines;
// }
}

//end of path class
?>