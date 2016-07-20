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
 * ar_transaction_type
 * 
 * 
 */
class ar_transaction_type extends dbObject {

 public static $table_name = "ar_transaction_type";
 public static $primary_column = "ar_transaction_type_id";
 public static $key_column = 'ar_transaction_type';
 public static $module = "ar"; //same as gl_journal_source
 public static $system_info = [
  'name' => 'Transaction Type',
  'number' => '1307',
  'description' => 'AR Transaction Type',
  'version' => '0.1.1',
  'db_version' => '1001',
  'mod_version' => '1.1.1',
  'primary_entity_cb' => '',
  'module_name' => 'ar',
  'weight' => 7
 ];
 public $field_a = [
  'ar_transaction_type_id',
  'ar_transaction_type',
  'transaction_class',
  'bu_org_id',
  'legal_org_id',
  'invoice_type_id',
  'description',
  'cm_type_id',
  'payment_term_id',
  'status',
  'receivable_ac_id',
  'revenue_ac_id',
  'tax_ac_id',
  'freight_ac_id',
  'clearing_ac_id',
  'unbilled_receivable_ac_id',
  'unearned_revenue_ac_id',
  'br_receivable_ac_id',
  'br_offset_ac_id',
  'ar_revenue_rule_header_id',
  'receivable_rule',
  'created_by',
  'creation_date',
  'last_update_by',
  'last_update_date',
 ];
 public $initial_search = [
  'ar_transaction_type',
  'transaction_class',
  'bu_org_id',
  'legal_org_id',
  'description',
 ];
 public $column = [
  'ar_transaction_type',
  'transaction_class',
  'bu_org_id',
  'legal_org_id',
  'description',
 ];
 public $requiredField = [
  'ar_transaction_type',
  'transaction_class',
  'bu_org_id',
  'legal_org_id',
 ];
 
 public $ar_transaction_type_id;
 public $ar_transaction_type;
 public $transaction_class;
 public $bu_org_id;
 public $legal_org_id;
 public $invoice_type_id;
 public $description;
 public $cm_type_id;
 public $payment_term_id;
 public $status;
 public $receivable_ac_id;
 public $revenue_ac_id;
 public $tax_ac_id;
 public $freight_ac_id;
 public $clearing_ac_id;
 public $unbilled_receivable_ac_id;
 public $unearned_revenue_ac_id;
 public $br_receivable_ac_id;
 public $br_offset_ac_id;
 public $receivable_rule;
 public $ar_revenue_rule_header_id;
 public $created_by;
 public $creation_date;
 public $last_update_by;
 public $last_update_date;
 public $search = [
  '_show_update_path' => 1,
  '_update_action_meassge' => 'Update',
  '_show_view_path' => 1,
 ];
 public $pageTitle = " AR - Transaction Type  "; //page Title

 public static function find_all_by_buOrgId($bu_org_id) {
  $sql = " SELECT * FROM ";
  $sql .= self::$table_name;
  $sql .= " WHERE bu_org_id = '{$bu_org_id}' ";
  $result = self::find_by_sql($sql);
  return !empty($result) ? $result : false;
 }

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

//end of ar_transaction_type class
?>