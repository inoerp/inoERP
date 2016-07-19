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
 * prj_category_header
 *
 */
class prj_category_header extends dbObject {

 public static $table_name = "prj_category_header";
 public static $primary_column = "prj_category_header_id";
 public static $dependent_classes = ['prj_category_line'];
 public static $key_column = "category";
 public static $module = "prj";
 public static $system_info = [
  'name' => 'Category',
  'number' => '6008',
  'description' => 'Project Category',
  'version' => '0.1.1',
  'db_version' => '1001',
  'mod_version' => '1.1.1',
  'primary_entity_cb' => '',
  'module_name' => 'prj',
  'weight' => 11
 ];
 public $field_a = [
  'prj_category_header_id',
  'category',
  'description',
  'mandatory_cb',
  'effective_from',
  'effective_to',
  'one_code_only_cb',
  'allow_percent_cb',
  'total_hundred_cb',
  'created_by',
  'creation_date',
  'last_update_by',
  'last_update_date',
 ];
 public $initial_search = [
  'category',
  'description',
 ];
 public $requiredField = [
  'category',
 ];
 public $search = [
  '_show_update_path' => 1,
  '_show_view_path' => 1,
 ];
 public $pageTitle = " Project Category "; //page Title
 public $prj_category_header_id;
 public $category;
 public $description;
 public $mandatory_cb;
 public $effective_from;
 public $effective_to;
 public $one_code_only_cb;
 public $allow_percent_cb;
 public $total_hundred_cb;
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
