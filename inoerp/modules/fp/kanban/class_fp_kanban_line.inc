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
 * fp_kanban_line
 *
 */
class fp_kanban_line extends dbObject {

 public static $table_name = "fp_kanban_line";
 public static $primary_column = "fp_kanban_line_id";
 public static $parent_primary_column = "fp_kanban_header_id";
 public static $key_column = "fp_kanban_header_id";
 public static $module = "prj";
 public static $card_status_a = [
  'ACTIVE' => 'Active',
  'INACTIVE' => 'In active',
  'CANCELLED' => 'Cancelled'
 ];
 public static $supply_status_a = [
  'UNKNOWN' => 'Unknown',
  'FULL' => 'Full',
  'EMPTY' => 'Empty',
  'INPROCESS' => 'InProcess',
  'HOLD' => 'On Hold',
 ];
 public static $card_type_a = [
  'MANUAL' => 'Manual',
  'AUTO' => 'Automatic'
 ];
 public $field_a = [
  'fp_kanban_line_id',
  'fp_kanban_header_id',
  'description',
  'card_number',
  'replenish_cb',
  'card_status',
  'supply_status',
  'kanban_size',
  'card_type',
  'created_by',
  'creation_date',
  'last_update_by',
  'last_update_date',
 ];
 public $initial_search = [
  'description',
  'card_number',
 ];
 public $requiredField = [
  'fp_kanban_header_id',
  'kanban_size'
 ];
 public $search = [
  '_show_update_path' => 1,
  '_show_view_path' => 1,
 ];
 public $pageTitle = "Kanban Cards"; //page Title
 public $fp_kanban_line_id;
 public $fp_kanban_header_id;
 public $description;
 public $card_number;
 public $replenish_cb;
 public $card_status;
 public $supply_status;
 public $kanban_size;
 public $card_type;
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

 Public static function highest_card_number() {
  $sql = " SELECT MAX(card_number) as max_number from fp_kanban_line ";
  $result = self::find_by_sql($sql);
  return !empty($result) ? $result[0]->card_number : 0;
 }

}

//end of path class
?>
