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
 * prj_nlr_header
 *
 */
class prj_nlr_header extends dbObject {

 public static $table_name = "prj_nlr_header";
 public static $primary_column = "prj_nlr_header_id";
 public static $dependent_classes = ['prj_nlr_line'];
 public static $key_column = "resource_name";
 public static $module = "prj";
 public static $system_info = [
  'name' => 'nlr',
  'number' => '6013',
  'description' => 'Project nlr',
  'version' => '0.1.1',
  'db_version' => '1001',
  'mod_version' => '1.1.1',
  'primary_entity_cb' => '',
  'module_name' => 'prj',
  'weight' => 11
 ];
 public $field_a = [
  'prj_nlr_header_id',
  'resource_name',
  'prj_expenditure_type_id',
  'description',
  'equipment_cb',
  'effective_from',
  'effective_to',
  'created_by',
  'creation_date',
  'last_update_by',
  'last_update_date',
 ];
 public $initial_search = [
  'resource_name',
  'description',
 ];
 public $requiredField = [
  'resource_name',
 ];
 public $search = [
  '_show_update_path' => 1,
  '_show_view_path' => 1,
 ];
 public $pageTitle = " Non-Labor Resources "; //page Title
 
 public $prj_nlr_header_id;
 public $resource_name;
 public $prj_expenditure_type_id;
 public $description;
 public $equipment_cb;
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

}

//end of path class
?>
