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
 * ar_receipt_source
 * 
 * 
 */
class ar_transaction_source extends dbObject {

 public static $table_name = "ar_transaction_source";
 public static $primary_column = "ar_transaction_source_id";
 public static $key_column = 'transaction_source';
 public static $module = "ar"; //same as gl_journal_source
 public static $system_info = [
  'name' => 'Transaction Source',
  'number' => '1308',
  'description' => 'AR Transaction Source',
  'version' => '0.1.1',
  'db_version' => '1001',
  'mod_version' => '1.1.1',
  'primary_entity_cb' => '',
  'module_name' => 'ar',
  'weight' => 8
 ];
 public static $template_type = [
  'header_tab' => 1,
  'line_tab' => 2,
  'nooffields_header_tab1' => 5,
  'nooffields_line_tab1' => 6,
  'nooffields_line_tab2' => 6,
 ];
 public static $source_type_a = [
  'MANUAL' => 'Manual',
  'IMPORT' => 'Import'
 ];
 public $field_a = [
  'ar_transaction_source_id',
  'transaction_source',
  'source_type',
  'bu_org_id',
  'legal_org_id',
  'invoice_type_id',
  'description',
  'cm_type_id',
  'payment_term_id',
  'status',
  'create_clearing_cb',
  'created_by',
  'creation_date',
  'last_update_by',
  'last_update_date'
 ];
 public $initial_search = [
  'ar_transaction_source_id',
  'transaction_source',
  'source_type',
 ];
 public $column = [
  'ar_transaction_source_id',
  'transaction_source',
  'source_type',
  'bu_org_id',
  'description',
 ];
 public $requiredField = [
  'transaction_source',
  'source_type',
  'bu_org_id',
  'legal_org_id',
 ];
 public $ar_transaction_source_id;
 public $transaction_source;
 public $source_type;
 public $bu_org_id;
 public $legal_org_id;
 public $invoice_type_id;
 public $description;
 public $cm_type_id;
 public $payment_term_id;
 public $status;
 public $create_clearing_cb;
 public $created_by;
 public $creation_date;
 public $last_update_by;
 public $last_update_date;
 public $search = [
  '_show_update_path' => 1,
  '_update_action_meassge' => 'Update',
  '_show_view_path' => 1,
 ];
 public $pageTitle = " AR - Transaction Source  "; //page Title

 public static function find_all_header_levels() {
  $sql = " SELECT * FROM ";
  $sql .= self::$table_name;
  $sql .= " WHERE level = 'HEADER' ";
  $result = self::find_by_sql($sql);
  return !empty($result) ? $result : false;
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

//end of ar_transaction_source class
?>