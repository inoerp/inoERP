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
 * sys_hold
 *
 */


class sys_hold extends dbObject {

 public static $table_name = "sys_hold";
 public static $primary_column = "sys_hold_id";
 public static $key_column = 'hold_code';
 public static $module = "sys";
 public static $system_info = [
  'name' => 'Hold',
  'number' => '9103',
  'description' => 'Create & Mainten Holds',
  'version' => '0.1.1',
  'db_version' => '1001',
  'mod_version' => '1.1.1',
  'primary_entity_cb' => '',
  'module_name' => 'sys',
  'weight' => 3
 ];
 public $field_a = [
  'sys_hold_id',
  'hold_code',
  'hold_name',
  'hold_type',
  'manual_released_cb',
  'access_level',
  'description',
  'status',
  'created_by',
  'creation_date',
  'last_update_by',
  'last_update_date',
 ];
 public $initial_search = [
  'hold_code',
  'hold_name',
  'hold_type',
 ];
 public $requiredField = [
  'hold_code',
  'hold_name',
  'hold_type',
 ];
 public $sys_hold_id;
 public $hold_code;
 public $hold_name;
 public $hold_type;
 public $access_level;
 public $manual_released_cb;
 public $description;
 public $status;
 public $created_by;
 public $creation_date;
 public $last_update_by;
 public $last_update_date;
 public $search = [
  '_show_update_path' => 1,
  '_show_view_path' => 1,
 ];
 public $pageTitle = " System holds  "; //page Title

 Public static function hold_type() {
  $option_header = option_header::find_by_name('SYS_HOLD_TYPE');
  $ol = new option_line();
  $option_lines = $ol->findBy_parentId($option_header->option_header_id);
  return $option_lines;
 }

 public static function findBy_code($hold_code) {
  $sql = " SELECT * FROM ";
  $sql .= self::$table_name;
  $sql .= " WHERE hold_code = :hold_code ";
  $value_a = ['hold_code' => $hold_code];
  $result = $this->findBySql($sql, $value_a);
  return !empty($result) ? array_pop($result) : false;
 }

 public static function find_by_code($code) {
  $sql = " SELECT * FROM ";
  $sql .= self::$table_name;
  $sql .= " WHERE hold_code = '{$code}' ";
  $result = self::find_by_sql($sql);
  return !empty($result) ? array_pop($result) : false;
 }

 public static function find_all_line_levels() {
  $sql = " SELECT * FROM ";
  $sql .= self::$table_name;
  $sql .= " WHERE level = 'LINE' ";
  $result = self::find_by_sql($sql);
  return !empty($result) ? $result : false;
 }

 public static function find_by_transactionClass($class) {
  $sql = " SELECT * FROM ";
  $sql .= self::$table_name;
  $sql .= " WHERE type_class = '{$class}' AND status='active'";
  $result = self::find_by_sql($sql);
  return $result;
 }

}

//end of sys_hold class
?>