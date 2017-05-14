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
 * qa_cp_assignment_header
 *
 */
class qa_cp_assignment_header extends dbObject {

 public static $table_name = "qa_cp_assignment_header";
 public static $primary_column = "qa_cp_assignment_header_id";
 public static $dependent_classes = ['qa_cp_assignment_line'];
 public static $key_column = "qa_cp_header_id";
 public static $module = "qa";
 public static $system_info = [
  'name' => 'Collection Plan Assignment',
  'number' => '2903',
  'description' => 'Quality Collection Plan Assignment',
  'version' => '0.1.1',
  'db_version' => '1001',
  'mod_version' => '1.1.1',
  'primary_entity_cb' => '',
  'module_name' => 'qa',
  'weight' => 11
 ];
 public $field_a = [
  'qa_cp_assignment_header_id',
  'qa_cp_header_id',
  'inv_transaction_id',
  'description',
  'effective_from',
  'effective_to',
  'mandatory_cb',
  'enabled_cb',
  'created_by',
  'creation_date',
  'last_update_by',
  'last_update_date',
 ];
 public $initial_search = [
  'inv_transaction_id',
 ];
 public $requiredField = [
  'qa_cp_header_id',
  'inv_transaction_id',
  'effective_from',
 ];
 public $search = [
  '_show_update_path' => 1,
  '_show_view_path' => 1,
 ];
 public $pageTitle = "Collection Plan Assignment "; //page Title
 public $qa_cp_assignment_header_id;
 public $qa_cp_header_id;
 public $inv_transaction_id;
 public $description;
 public $effective_from;
 public $effective_to;
 public $mandatory_cb;
 public $enabled_cb;
 public $created_by;
 public $creation_date;
 public $last_update_by;
 public $last_update_date;

// Public static function validation_types() {
//  $header = option_header::find_by_keyColumn('SYS_VALIDATION_TYPE');
//  $option_line = new option_line();
//  $lines = $option_line->findBy_parentId($header->option_header_id);
//  return $lines;
// }
}

//end of path class
?>