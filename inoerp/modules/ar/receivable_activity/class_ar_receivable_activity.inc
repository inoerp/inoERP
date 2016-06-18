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
 * ar_receivable_activity
 * 
 * 
 */
class ar_receivable_activity extends dbObject {

 public static $table_name = "ar_receivable_activity";
 public static $primary_column = "ar_receivable_activity_id";
 public static $key_column = 'receivable_activity';
 public static $module = "ar";
 public static $system_info = [
  'name' => 'AR Receipt Source',
  'number' => '1305',
  'description' => 'Receipt Source',
  'version' => '0.1.1',
  'db_version' => '1001',
  'mod_version' => '1.1.1',
  'primary_entity_cb' => '',
  'module_name' => 'ar',
  'weight' => 5
 ];
 public static $template_type = [
  'header_tab' => 1,
  'line_tab' => 2,
  'nooffields_header_tab1' => 5,
  'nooffields_line_tab1' => 6,
  'nooffields_line_tab2' => 6,
 ];
 public static $creation_method_a = [
  'MANUAL' => 'Manual',
  'AUTOMATIC' => 'Automatic',
  'AP_AR_NETTING' => 'AP-AR Netting',
 ];
 public static $remittance_method_a = [
  'NO_REMITTANCE' => 'No Remittance',
  'STANDARD' => 'Standard'
 ];
 public static $clearance_method_a = [
  'DIRECT' => 'Direct',
  'AUTOMATIC' => 'Automatic',
  'MATCHING' => 'Matching',
 ];
 public $field_a = [
  'ar_receivable_activity_id',
  'receivable_activity',
  'receipt_type',
  'creation_method',
  'bu_org_id',
  'description',
  'remittance',
  'clearance',
  'bank_account_id',
  'sync_receipt_number_cb',
  'status',
  'created_by',
  'creation_date',
  'last_update_by',
  'last_update_date',
 ];
 public $initial_search = [
  'ar_receivable_activity_id',
  'receivable_activity',
  'receipt_type',
 ];
 public $column = [
  'ar_receivable_activity_id',
  'receivable_activity',
  'receipt_type',
  'creation_method',
  'bu_org_id',
 ];
 public $fields_inForm_notInDataBase = [
  'account_number',
  'country',
  'bank_name',
  'bank_number',
  'description',
  'bank_name_short',
  'bank_name_alt',
  'branch_name',
  'branch_number',
  'ifsc_code',
  'swift_code',
  'routing_number',
  'iban_code',
 ];
 public $requiredField = [
  'receivable_activity',
  'receipt_type',
  'creation_method',
  'bu_org_id',
  'remittance',
  'clearance',
  'bank_account_id',
 ];
 public $ar_receivable_activity_id;
 public $receivable_activity;
 public $receipt_type;
 public $creation_method;
 public $bu_org_id;
 public $description;
 public $remittance;
 public $clearance;
 public $bank_account_id;
 public $sync_receipt_number_cb;
 public $status;
 public $created_by;
 public $creation_date;
 public $last_update_by;
 public $last_update_date;
 public $country;
 public $account_number;
 public $bank_name;
 public $bank_number;
 public $bank_name_short;
 public $bank_name_alt;
 public $branch_name;
 public $branch_number;
 public $ifsc_code;
 public $swift_code;
 public $routing_number;
 public $iban_code;
 public $search = [
  '_show_update_path' => 1,
  '_show_view_path' => 1,
 ];
 public $pageTitle = " AR - Receipt Source ";

 public static function find_by_buOrgId($bu_org_id) {
  $sql = " SELECT * FROM ";
  $sql .= self::$table_name;
  $sql .= " WHERE bu_org_id = '{$bu_org_id}' AND status='active'";
  $result = self::find_by_sql($sql);
  return !empty($result) ? $result : false;
 }

 public function findBy_buOrgId($bu_org_id = '') {
  $bu_org_id = empty($bu_org_id) ? $this->bu_org_id : $bu_org_id;
  $sql = " SELECT * FROM ";
  $sql .= self::$table_name;
  $sql .= " WHERE bu_org_id = '{$bu_org_id}' AND status='active'";
  $result = $this->findBySql($sql);
  return !empty($result) ? $result : false;
 }

}

//end of ar_receivable_activity class
?>