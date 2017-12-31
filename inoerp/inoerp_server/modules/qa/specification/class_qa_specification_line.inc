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
 * qa_specification_line
 *
 */
class qa_specification_line extends dbObject {

 public static $table_name = "qa_specification_line";
 public static $primary_column = "qa_specification_line_id";
 public static $parent_primary_column = "qa_specification_header_id";
 public static $key_column = "qa_ce_header_id";
 public static $module = "qa";
 public $field_a = [
  'qa_specification_line_id',
  'qa_specification_header_id',
  'qa_ce_header_id',
  'description',
  'uom_id',
  'enabled_cb',
  'user_range_low',
  'user_range_high',
  'user_target_value',
  'specification_range_high',
  'specification_range_low',
  'specification_target_value',
  'reasonable_range_low',
  'reasonable_range_high',
  'reasonable_target_value',
  'created_by',
  'creation_date',
  'last_update_by',
  'last_update_date',
 ];
 public $initial_search = [
  'qa_ce_header_id',
  'description',
 ];
 public $requiredField = [
  'qa_specification_header_id',
  'qa_ce_header_id',
 ];
 public $search = [
  '_show_update_path' => 1,
  '_show_view_path' => 1,
 ];
 public $fields_inForm_notInDataBase = [
  "employee_name",
  'task_number'
 ];
 public $pageTitle = " Specificaion Line"; //page Title
 public $qa_specification_line_id;
 public $qa_specification_header_id;
 public $qa_ce_header_id;
 public $description;
 public $uom_id;
 public $enabled_cb;
 public $user_range_low;
 public $user_range_high;
 public $user_target_value;
 public $specification_range_high;
 public $specification_range_low;
 public $specification_target_value;
 public $reasonable_range_low;
 public $reasonable_range_high;
 public $reasonable_target_value;
 public $created_by;
 public $creation_date;
 public $last_update_by;
 public $last_update_date;

}

//end of path class
?>
