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
 * qa_cp_assignment_line
 *
 */
class qa_cp_assignment_line extends dbObject {

 public static $table_name = "qa_cp_assignment_line";
 public static $primary_column = "qa_cp_assignment_line_id";
 public static $parent_primary_column = "qa_cp_assignment_header_id";
 public static $key_column = "trigger_name";
 public static $module = "qa";
 public $field_a = [
  'qa_cp_assignment_line_id',
  'qa_cp_assignment_header_id',
  'trigger_name',
  'description',
  'value_from',
  'value_to',
  'condition',
  'enabled_cb',
  'created_by',
  'creation_date',
  'last_update_by',
  'last_update_date',
 ];
 public $initial_search = [
  'trigger_name',
  'value_from',
  'description',
 ];
 public $requiredField = [
  'qa_cp_assignment_header_id',
  'qa_collection_element_header_id',
  'sequence',
 ];
 public $search = [
  '_show_update_path' => 1,
  '_show_view_path' => 1,
 ];
 public $pageTitle = " Collection Plan Line"; //page Title
 public $qa_cp_assignment_line_id;
 public $qa_cp_assignment_header_id;
 public $trigger_name;
 public $description;
 public $value_from;
 public $value_to;
 public $condition;
 public $enabled_cb;
 public $created_by;
 public $creation_date;
 public $last_update_by;
 public $last_update_date;

}

//end of path class
?>
