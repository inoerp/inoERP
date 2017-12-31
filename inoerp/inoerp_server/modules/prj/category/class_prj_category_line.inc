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
 * prj_category_line
 *
 */
class prj_category_line extends dbObject {

 public static $table_name = "prj_category_line";
 public static $primary_column = "prj_category_line_id";
 public static $parent_primary_column = "prj_category_header_id";
 public static $key_column = "category_code";
 public static $module = "prj";
 public $field_a = [
  'prj_category_line_id',
  'prj_category_header_id',
  'category_code',
  'effective_from',
  'description',
  'effective_to',
  'created_by',
  'creation_date',
  'last_update_by',
  'last_update_date',
 ];
 public $initial_search = [
  'category_code',
  'description',
 ];
 public $requiredField = [
  'prj_category_header_id',
  'category_code',
  'description',
 ];
 public $search = [
  '_show_update_path' => 1,
  '_show_view_path' => 1,
 ];
 public $pageTitle = "Project Category Lines"; //page Title
 public $prj_category_line_id;
 public $prj_category_header_id;
 public $category_code;
 public $effective_to;
 public $description;
 public $effective_from;
 public $created_by;
 public $creation_date;
 public $last_update_by;
 public $last_update_date;

 Public static function validation_types() {
  $header = option_line::find_by_keyColumn('SYS_VALIDATION_TYPE');
  $option_line = new option_line();
  $lines = $option_line->findBy_parentId($header->option_line_id);
  return $lines;
 }

}

//end of path class
?>
