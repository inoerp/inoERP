<?php

class bc_auto_trigger extends dbObject {

 public static $table_name = "bc_label_auto_trigger";
 public static $primary_column = "bc_label_auto_trigger_id";
 public static $key_column = "association_level_value";
 public static $module = "sys";
 public static $association_level_a  = [
  'SITE' => 'Site',
  'BUSINESS' => 'Business Org',
  'INVENTORY' => 'Inventory Org',
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

// public function findBy_name_context($profile_name, $level_name = 'SITE') {
//  $sql = " SELECT * FROM sys_profile_header " . self::$table_name;
//  $sql .= " WHERE  profile_name = :profile_name ";
//  $profile_name = !empty($profile_name) ? $profile_name : $this->profile_name;
//  $value_a = [ 'profile_name' => $profile_name];
//  if (!empty($profile_name)) {
//   $result_array = $this->findBySql($sql, $value_a);
//   $result_h = array_pop($result_array);
//  } else {
//   return false;
//  }
//
//  if (!empty($result_h)) {
//   //get line values
//   $result_l = $this->findBy_headerId_profileLevel($result_h->sys_profile_header_id, $level_name);
//   return $result_l;
//  } else {
//   return false;
//  }
// }
//
// public function find_default_profile($profile_name) {
//  $default_profile = null;
//  $all_proflies = $this->findAll_profile($profile_name);
//
//  if (!empty($_SESSION['user_id']) && !empty($all_proflies)) {
//   foreach ($all_proflies as $key => $profile) {
//    if (($profile->profile_level == 'USER') && ($profile->level_name == $_SESSION['user_id'])) {
//     $default_profile = $all_proflies[$key];
//     break;
//    }
//   }
//   if (!empty($default_profile)) {
//    return ($default_profile);
//   }
//  }
//
//  if (!empty($_SESSION['org_inv_name_default']) && !empty($all_proflies)) {
//   foreach ($all_proflies as $key => $profile) {
//    if (($profile->profile_level == 'INVENTORY') && ($profile->level_name == $_SESSION['org_inv_name_default'])) {
//     $default_profile = $all_proflies[$key];
//     break;
//    }
//   }
//   if (!empty($default_profile)) {
//    return ($default_profile);
//   }
//  }
//
//  if (!empty($_SESSION['org_bu_name_default']) && !empty($all_proflies)) {
//   foreach ($all_proflies as $key => $profile) {
//    if (($profile->profile_level == 'BUSINESS') && ($profile->level_name == $_SESSION['org_bu_name_default'])) {
//     $default_profile = $all_proflies[$key];
//     break;
//    }
//   }
//   if (!empty($default_profile)) {
//    return ($default_profile);
//   }
//  }
//
//  if (!empty($all_proflies)) {
//   foreach ($all_proflies as $key => $profile) {
//    if (($profile->profile_level == 'SITE')) {
//     $default_profile = $all_proflies[$key];
//     break;
//    }
//   }
//  }
//  return !empty($default_profile) ? ($default_profile) : false;
// }
//
// public function findAll_profile($profile_name) {
//  $sql = " SELECT sph.profile_name,sph.description,sph.class_name,
//           spl.bc_label_auto_trigger_id, spl.sys_profile_header_id, spl.profile_level, spl.level_name, spl.level_value
//           FROM sys_profile_header sph
//          LEFT JOIN bc_auto_trigger spl ON spl.sys_profile_header_id = sph.sys_profile_header_id 
//     WHERE sph.profile_name = :proflile_name ";
//  $value_a = ['proflile_name' => $profile_name];
//  $result = $this->findBySql($sql, $value_a);
//  return !empty($result) ? $result : false;
// }

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
 
  public static function find_by_transactionTypId($transaction_type_id) {
  $sql = " SELECT * FROM ";
  $sql .= self::$table_name;
  $sql .= " WHERE transaction_type_id = '{$transaction_type_id}' ";
  $result = self::find_by_sql($sql);
  return !empty($result) ? $result : false;
 }

 public static function find_all_lines() {
  $sql = " SELECT * FROM " . self::$table_name;
  $result = self::find_by_sql($sql);
  return $result;
 }

 public static function find_by_header_id($id) {
  $vgl = new bc_auto_trigger();
  return $vgl->findBy_parentId($id);
 }

 public static function find_by_optionId_lineCode($header_id, $code) {
  $sql = "SELECT * FROM " . self::$table_name .
   " where code={$code} AND sys_profile_header_id={$header_id} LIMIT 1 ";
  $result = self::find_by_sql($sql);
  return !empty($result) ? array_push($result) : $result;
 }

}

?>