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
 * sys_catalog_header
 *
 */
class sys_catalog_header extends dbObject {

 public static $table_name = "sys_catalog_header";
 public static $primary_column = "sys_catalog_header_id";
 public static $dependent_classes = ['sys_catalog_line'];
 public static $key_column = "catalog";
 public static $module = "sys";
 public static $system_info = [
  'name' => 'Catalog',
  'number' => '9118',
  'description' => 'Create & Update Catalog',
  'version' => '0.1.1',
  'db_version' => '1001',
  'mod_version' => '1.1.1',
  'primary_entity_cb' => '',
  'module_name' => 'sys',
  'weight' => 11
 ];
 public static $status_a = [
  'active' =>'Active',
  'inactive' =>'Inactive',
 ];
 public $field_a = [
  'sys_catalog_header_id',
  'catalog',
  'description',
  'parent_catalog_header_id',
  'status',
  'created_by',
  'creation_date',
  'last_update_by',
  'last_update_date',
 ];
 public $initial_search = [
  'catalog',
  'description',
 ];
 public $requiredField = [
  'catalog',
 ];
 public $search = [
  '_show_update_path' => 1,
  '_update_action_meassge' => 'Update',
  '_show_view_path' => 1,
 ];
 public $pageTitle = " Catalog "; //page Title
 public $sys_catalog_header_id;
 public $catalog;
 public $description;
 public $parent_catalog_header_id;
 public $status;
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
