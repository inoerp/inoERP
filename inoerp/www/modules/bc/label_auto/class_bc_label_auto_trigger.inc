<?php

class bc_label_auto_trigger extends dbObject {

 public static $table_name = "bc_label_auto_trigger";
 public static $primary_column = "bc_label_auto_trigger_id";
 public static $key_column = "association_level_value";
 public static $module = "sys";
 public static $system_info = [
  'name' => 'BC Auto-trigger',
  'number' => '9220',
  'description' => 'Barcode label auto trigger',
  'version' => '0.1.1',
  'db_version' => '1001',
  'mod_version' => '1.1.1',
  'primary_entity_cb' => '',
  'module_name' => 'bc',
  'weight' => 1
 ];
 public static $association_level_a = [
  'SITE' => 'Site',
  'BUSINESS' => 'Business Org',
  'INVENTORY' => 'Inventory Org',
  'FROM_SUBINV' => 'From Subinventory',
 ];
 public $field_a = [
  'bc_label_auto_trigger_id',
  'bc_label_format_header_id',
  'transaction_type_id',
  'association_level_value',
  'association_level',
  'sys_printer_id',
  'enabled_cb',
  'description',
  'created_by',
  'creation_date',
  'last_update_by',
  'last_update_date',
 ];
 public $initial_search = [
  'bc_label_format_header_id',
 ];
 public $requiredField = [
  'bc_label_format_header_id',
  'association_level_value',
  'transaction_type_id',
  'association_level',
  'sys_printer_id',
 ];
 public $fields_inForm_notInDataBase = [
 ];
 public $fields_inHeader_needsToBeInserted_inPOST = [
 ];
 public $pageTitle = " Barcode Auto Trigger "; //page Title
 public $bc_label_auto_trigger_id;
 public $bc_label_format_header_id;
 public $transaction_type_id;
 public $association_level_value;
 public $association_level;
 public $sys_printer_id;
 public $enabled_cb;
 public $description;
 public $created_by;
 public $creation_date;
 public $last_update_by;
 public $last_update_date;

 public function __construct() {
  if (empty($_SESSION['username'])) {
   return;
  }
  if (empty($_SESSION['org_inv_name_default'])) {
   $_SESSION['org_inv_name_default'] = $this->find_default_profile('org_inv_name_default')->level_value;
  }
  if (empty($_SESSION['org_bu_name_default'])) {
   $_SESSION['org_bu_name_default'] = $this->find_default_profile('org_bu_name_default')->level_value;
  }
 }

 public function findBy_transactionId_associationLevel($header_id, $assoc_level) {
  $sql = " SELECT * FROM ";
  $sql .= self::$table_name;
  $sql .= " WHERE transaction_type_id = :header_id AND association_level = :association_level ";

  $value_a = ['transaction_type_id' => $header_id, 'association_level' => $assoc_level];
  $result = $this->findBySql($sql, $value_a);
  return !empty($result) ? $result : false;
 }

 public static function find_by_transactionId_associationLevel($transaction_type_id, $assoc_level = '') {
  $sql = " SELECT * FROM ";
  $sql .= self::$table_name;
  $sql .= " WHERE transaction_type_id = '{$transaction_type_id}' ";
  if (!empty($assoc_level)) {
   $sql .= "  AND association_level = '{$assoc_level}' ";
  }

  $result = self::find_by_sql($sql);
  return !empty($result) ? $result : false;
 }

 public static function find_by_transactionTypId($trnx_obj) {
//   pa($trnx_obj);
//   return false;
  $sql = " SELECT * FROM ";
  $sql .= self::$table_name;
  $sql .= " WHERE transaction_type_id = '{$trnx_obj->transaction_type_id}' ";
  $sql .= " AND  ( association_level = 'SITE'  || ";
  $sql .= "       association_level = 'FROM_SUBINV'  AND association_level_value = '{$trnx_obj->from_subinventory_id}' || ";
  $sql .= "       association_level = 'INVENTORY'  AND association_level_value = '{$trnx_obj->org_id}' ) ";
  $result = self::find_by_sql($sql);
//  echo $sql;
  return !empty($result) ? $result : false;
 }

 public static function find_all_lines() {
  $sql = " SELECT * FROM " . self::$table_name;
  $result = self::find_by_sql($sql);
  return $result;
 }

 public static function find_by_header_id($id) {
  $vgl = new bc_label_auto_trigger();
  return $vgl->findBy_parentId($id);
 }

 public static function find_by_optionId_lineCode($header_id, $code) {
  $sql = "SELECT * FROM " . self::$table_name .
   " where code={$code} AND sys_profile_header_id={$header_id} ";

  switch (DB_TYPE) {
   case 'ORACLE' :
    $sql .= ' AND ' . ino_perPageSql(1);
    break;

   default:
    $sql .= ino_perPageSql(1);
    break;
  }
  $result = self::find_by_sql($sql);
  return !empty($result) ? array_push($result) : $result;
 }

}

?>