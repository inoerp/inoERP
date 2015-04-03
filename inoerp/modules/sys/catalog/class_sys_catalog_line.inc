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
 * sys_catalog_line
 *
 */
class sys_catalog_line extends dbObject {

 public static $table_name = "sys_catalog_line";
 public static $primary_column = "sys_catalog_line_id";
 public static $parent_primary_column = "sys_catalog_header_id";
 public static $key_column = "line_name";
 public static $module = "sys";
 public $field_a = [
  'sys_catalog_line_id',
  'sys_catalog_header_id',
  'line_name',
  'sys_value_group_header_id',
  'description',
  'required_cb',
  'created_by',
  'creation_date',
  'last_update_by',
  'last_update_date',
 ];
 public $initial_search = [
  'line_name',
  'description',
 ];
 public $requiredField = [
  'sys_catalog_header_id',
  'line_name',
 ];
 public $fields_inForm_notInDataBase = [
  'sys_catalog_value_id',
  'line_value',
  'reference_table',
  'reference_id',
 ];
 public $search = [
  '_show_update_path' => 1,
  '_update_action_meassge' => 'Update',
  '_show_view_path' => 1,
 ];
 public $pageTitle = " Catalog Lines"; //page Title
 public $sys_catalog_line_id;
 public $sys_catalog_header_id;
 public $line_name;
 public $sys_value_group_header_id;
 public $description;
 public $required_cb;
 public $created_by;
 public $creation_date;
 public $last_update_by;
 public $last_update_date;
 public $msg;
 public $sys_catalog_value_id;
 public $line_value;
 public $reference_table;
 public $reference_id;

 Public static function validation_types() {
  $header = option_line::find_by_keyColumn('SYS_VALIDATION_TYPE');
  $option_line = new option_line();
  $lines = $option_line->findBy_parentId($header->option_line_id);
  return $lines;
 }

}

//end of path class
?>
