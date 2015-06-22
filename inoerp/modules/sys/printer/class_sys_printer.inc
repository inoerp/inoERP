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
 * sys_printer
 *
 */


class sys_printer extends dbObject {

 public static $table_name = "sys_printer";
 public static $primary_column = "sys_printer_id";
 public static $key_column = 'printer_name';
 public static $module = "sys";
 public static $system_info = [
  'name' => 'Printer',
  'number' => '9106',
  'description' => 'Create & Mainten Printer',
  'version' => '0.1.1',
  'db_version' => '1001',
  'mod_version' => '1.1.1',
  'primary_entity_cb' => '',
  'module_name' => 'sys',
  'weight' => 6
 ];
 public $field_a = [
  'sys_printer_id',
  'printer_name',
  'printer_type',
  'manufacturer',
  'description',
  'ip_address',
  'port_number',
  'model_number',
  'created_by',
  'creation_date',
  'last_update_by',
  'last_update_date'
 ];
 public $initial_search = [
  'printer_name',
  'printer_type',
 ];
 public $requiredField = [
  'printer_name',
  'ip_address',
  'port_number',
 ];
 public $sys_printer_id;
 public $printer_name;
 public $printer_type;
 public $manufacturer;
 public $description;
 public $ip_address;
 public $port_number;
 public $model_number;
 public $created_by;
 public $creation_date;
 public $last_update_by;
 public $last_update_date;
 public $search = [
  '_show_update_path' => 1,
  '_show_view_path' => 1,
 ];
 public $pageTitle = " Printer  "; //page Title

 Public static function printer_type() {
  $option_header = option_header::find_by_name('SYS_PRINTER_TYPE');
  $ol = new option_line();
  $option_lines = $ol->findBy_parentId($option_header->option_header_id);
  return $option_lines;
 }

 public static function find_by_code($code) {
  $sql = " SELECT * FROM ";
  $sql .= self::$table_name;
  $sql .= " WHERE hold_code = '{$code}' ";
  $result = self::find_by_sql($sql);
  return !empty($result) ? array_pop($result) : false;
 }

}

//end of sys_printer class
?>