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
 * prj_expenditure_type_line
 *
 */
class prj_expenditure_type_line extends dbObject {

 public static $table_name = "prj_expenditure_type_line";
 public static $primary_column = "prj_expenditure_type_line_id";
 public static $parent_primary_column = "prj_expenditure_type_header_id";
 public static $key_column = "bu_org_id";
 public static $module = "prj";
 public $field_a = [
  'prj_expenditure_type_line_id',
  'prj_expenditure_type_header_id',
  'bu_org_id',
  'effective_from',
  'description',
  'effective_to',
  'uom_id',
  'currency',
  'rate',
  'created_by',
  'creation_date',
  'last_update_by',
  'last_update_date',
 ];
 public $initial_search = [
  'description',
 ];
 public $requiredField = [
  'prj_expenditure_type_header_id',
  'bu_org_id',
 ];
 public $search = [
  '_show_update_path' => 1,
  '_show_view_path' => 1,
 ];
 public $pageTitle = "Non-Labor Resource Line"; //page Title
 public $prj_expenditure_type_line_id;
 public $prj_expenditure_type_header_id;
 public $bu_org_id;
 public $effective_from;
 public $description;
 public $effective_to;
 public $uom_id;
 public $currency;
 public $rate;
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
