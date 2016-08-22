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
 * transaction_type
 * Contains all the transaction_type information, such as - transaction_type, transaction_type_id, type_class,  type_class, etc.
 * 
 */
class transaction_type extends dbObject {

 public static $table_name = "transaction_type";
 public static $primary_column = "transaction_type_id";
 public static $key_column = 'transaction_type';
 public static $module = "inv"; //same as gl_journal_source
 public static $system_info = [
  'name' => 'Transaction Type',
  'number' => '2115',
  'description' => 'Transaction Type',
  'version' => '0.1.1',
  'db_version' => '1001',
  'mod_version' => '1.1.1',
  'primary_entity_cb' => '',
  'module_name' => 'inv',
  'weight' => 15
 ];
 public $field_a = [
  "transaction_type_id",
  'transaction_type_number',
  "transaction_type",
  "type_class",
  "transaction_action",
  "description",
  "allow_negative_balance_cb",
  "account_id",
  "ef_id",
  "status",
  "rev_enabled_cb",
  "rev_number",
  "created_by",
  "creation_date",
  "last_update_by",
  "last_update_date"
 ];
 public $initial_search = [
  "transaction_type_id",
  'transaction_type_number',
  "transaction_type",
  "type_class",
  "transaction_action",
  "description"
 ];

 public $account = [
  "account_id"
 ];
 public $checkbox = [
  "rev_enabled_cb",
  "allow_negative_balance_cb"
 ];
 public $requiredField = [
  "transaction_type",
  'transaction_type_number',
  "type_class",
  "transaction_action"
 ];
 public $transaction_type_id;
 public $transaction_type;
 public $transaction_type_number;
 public $type_class;
 public $transaction_action;
 public $description;
 public $allow_negative_balance_cb;
 public $account_id;
 public $ef_id;
 public $status;
 public $rev_enabled_cb;
 public $rev_number;
 public $created_by;
 public $creation_date;
 public $last_update_by;
 public $last_update_date;
 public $time;
 public $msg;
 public $search = [
  '_show_update_path' => 1,
  '_update_action_meassge' => 'Update',
  '_show_view_path' => 1,
 ];
 public $pageTitle = " INV - Transaction Type  "; //page Title
 public $option_lists = [
  'transaction_type_class' => 'TRANSACTION_TYPE_CLASS',
  'transaction_action' => 'INV_TRANSACTION_ACTION',
 ];

// public $search_functions = [
//		 'Cost Type' => 'search_bom_cost_type',
//		 'Item From' => 'search_item_number_from',
//		 'Item To' => 'search_item_number_to',
//		 'Organization' => 'search_org_name',
// ];

 Public static function transaction_type_class() {
  $option_header = option_header::find_by_name('TRANSACTION_TYPE_CLASS');
  $transaction_type_class = option_line::find_by_option_id($option_header->option_header_id);
  return $transaction_type_class;
 }

 Public static function transaction_action() {
  $option_header = option_header::find_by_name('INV_TRANSACTION_ACTION');
  $transaction_action = option_line::find_by_option_id($option_header->option_header_id);
  return $transaction_action;
 }

 Public static function transaction_action_description($line_code) {
  $option_header = option_header::find_by_name('INV_TRANSACTION_ACTION');
  $transaction_action = option_line::find_by_optionId_lineCode($option_header->option_header_id, $line_code);
  return $transaction_action;
 }

 Public static function transaction_action_by_code($code) {
  $option_header = option_header::find_by_name('INV_TRANSACTION_ACTION');
  $transaction_action = option_line::find_by_option_id($option_header->option_header_id);
  return $transaction_action;
 }

 public static function find_by_transactionNumber($number) {
  $sql = " SELECT * FROM ";
  $sql .= self::$table_name;
  $sql .= " WHERE transaction_type_number = '{$number}' ";
  $sql = ino_perPageSql_i($sql, 1);
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

//end of transaction_type class
?>