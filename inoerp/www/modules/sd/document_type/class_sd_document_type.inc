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
 * sd_document_type
 * Contains all the sd_document_type information, such as - document_type_name, bu_org_id_r,level, etc
 *
 */
class sd_document_type extends dbObject {

 public static $table_name = "sd_document_type";
 public static $primary_column = "sd_document_type_id";
 public static $key_column = 'document_type_name';
 public static $module = "inv"; //same as gl_journal_source
 public static $system_info = [
  'name' => 'Sales Document Type',
  'number' => '2306',
  'description' => 'Create & Mainten Sales Document Type',
  'version' => '0.1.1',
  'db_version' => '1001',
  'mod_version' => '1.1.1',
  'primary_entity_cb' => '',
  'module_name' => 'sd',
  'weight' => 6
 ];
 public $field_a = [
  'sd_document_type_id',
  'document_type_name',
  'bu_org_id_r',
  'level',
  'type',
  'description',
  'category',
  'supply_source',
  'process_flow_id',
  'default_line_document',
  'price_list_header_id',
  'default_shipfrom_org_id',
  'destination_type',
  'ar_transaction_type',
  'ar_transaction_source',
  'created_by',
  'creation_date',
  'last_update_by',
  'last_update_date'
 ];
 public $initial_search = [
  'sd_document_type_id',
  'document_type_name',
  'level',
  'type',
  'description'
 ];
 public $column = [
  'sd_document_type_id',
  'document_type_name',
  'level',
  'type',
  'description',
 ];
 public $requiredField = [
  'document_type_name',
  'level',
  'type',
 ];
 public static $level_a = [
  'HEADER' => 'Header',
  'LINE' => 'Line'
 ];
 public static $type_a = [
  'SALES_AGREEMENT' => 'Sales Agreement',
  'SALES_ORDER' => 'Sales Order'
 ];
 public static $supply_source_a = [
  'WIP' => 'Job/Work Order',
  'INV' => 'Inventory',
  'PUR' => 'Supplier'
 ];
 public static $category_a = [
  'ORDER' => 'Order',
  'RETURN' => 'Return',
  'BOTH' => 'Both',
 ];
 public static $destination_type_a = [
  'EXTERNAL' => 'Customer',
  'INTERNAL' => 'Internal'
 ];
 public $sd_document_type_id;
 public $document_type_name;
 public $bu_org_id_r;
 public $level;
 public $type;
 public $supply_source;
 public $description;
 public $category;
 public $process_flow_id;
 public $default_line_document;
 public $price_list_header_id;
 public $default_shipfrom_org_id;
 public $destination_type;
 public $ar_transaction_type;
 public $ar_transaction_source;
 public $created_by;
 public $creation_date;
 public $last_update_by;
 public $last_update_date;
 public $search = [
  '_show_update_path' => 1,
  '_update_action_meassge' => 'Update',
  '_show_view_path' => 1,
 ];
 public $pageTitle = " SD - Document Type  "; //page Title

 public static function find_all_header_levels($bu_org_id_r = '') {
  $sql = " SELECT * FROM ";
  $sql .= self::$table_name;
  $sql .= " WHERE level = 'HEADER' ";
  $value_a = [];
  if (!empty($bu_org_id_r)) {
   $sql .= " AND bu_org_id_r = :bu_org_id_r ";
   $value_a = ['bu_org_id_r' => $bu_org_id_r];
  }

  $result = self::find_by_sql_i($sql, $value_a);
  return !empty($result) ? $result : false;
 }

 public static function find_all_line_levels($bu_org_id_r='') {
  $sql = " SELECT * FROM ";
  $sql .= self::$table_name;
  $sql .= " WHERE level = 'LINE' ";
  $value_a = [];
  if (!empty($bu_org_id_r)) {
   $sql .= " AND bu_org_id_r = :bu_org_id_r ";
   $value_a = ['bu_org_id_r' => $bu_org_id_r];
  }
  $result = self::find_by_sql_i($sql, $value_a);
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

//end of sd_document_type class
?>