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
 * prj_resource_list_header
 *
 */
class prj_resource_list_header extends dbObject {

 public static $table_name = "prj_resource_list_header";
 public static $primary_column = "prj_resource_list_header_id";
 public static $dependent_classes = ['prj_resource_list_line'];
 public static $key_column = "list_name";
 public static $module = "prj";
 public static $system_info = [
  'name' => 'Resource List',
  'number' => '6017',
  'description' => 'Resource List',
  'version' => '0.1.1',
  'db_version' => '1001',
  'mod_version' => '1.1.1',
  'primary_entity_cb' => '',
  'module_name' => 'prj',
  'weight' => 11
 ];
 public $field_a = [
  'prj_resource_list_header_id',
  'list_name',
  'description',
  'effective_from',
  'effective_to',
  'created_by',
  'creation_date',
  'last_update_by',
  'last_update_date',
 ];
 public $initial_search = [
  'list_name',
  'description',
 ];
 public $requiredField = [
  'list_name',
 ];
 public $search = [
  '_show_update_path' => 1,
  '_show_view_path' => 1,
 ];
 public $pageTitle = " Project Resource List "; //page Title
 public $prj_resource_list_header_id;
 public $list_name;
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

}

//end of path class
?>
