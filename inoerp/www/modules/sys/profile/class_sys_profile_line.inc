<?php

class sys_profile_line extends dbObject {

 public static $table_name = "sys_profile_line";
 public static $primary_column = "sys_profile_line_id";
 public static $parent_primary_column = "sys_profile_header_id";
 public static $key_column = "level_name";
 public static $module = "sys";
 public $field_a = [
  'sys_profile_line_id',
  'sys_profile_header_id',
  'profile_level',
  'level_name',
  'level_value',
  'created_by',
  'creation_date',
  'last_update_by',
  'last_update_date',
 ];
 public $initial_search = [
  'sys_profile_header_id',
  'profile_level',
  'level_name',
  'level_value',
 ];
 public $column = [
  'sys_profile_header_id',
  'profile_level',
  'level_name',
  'level_value',
 ];
 public $requiredField = [
  'profile_level',
  'level_name',
  'level_value',
 ];
 public $fields_inForm_notInDataBase = [
  'profile_name'
 ];
 public $fields_inHeader_needsToBeInserted_inPOST = [
  "sys_profile_header_id"
 ];
 public $pageTitle = " Profile Line"; //page Title
 public $sys_profile_line_id;
 public $sys_profile_header_id;
 public $profile_level;
 public $level_name;
 public $level_value;
 public $created_by;
 public $creation_date;
 public $last_update_by;
 public $last_update_date;
 public $profile_name;

 public function __set($name, $value) {
  $this->$name = $value;
 }

 public function __construct() {
  if (empty($_SESSION['username'])) {
   return;
  }
  if (empty($_SESSION['org_inv_name_default'])) {
   $default_profile_obj = $this->find_default_profile('org_inv_name_default');
   if (property_exists($default_profile_obj, 'level_value')) {
    $_SESSION['org_inv_name_default'] = $default_profile_obj->level_value;
   }
  }
  if (empty($_SESSION['org_bu_name_default'])) {
   $default_profile_obj1 = $this->find_default_profile('org_bu_name_default');
   if (property_exists($default_profile_obj1, 'level_value')) {
    $_SESSION['org_bu_name_default'] = $default_profile_obj1->level_value;
   }
  }
 }

 public function findBy_name_context($profile_name, $level_name = 'SITE') {
  $sql = " SELECT * FROM sys_profile_header " . self::$table_name;
  $sql .= " WHERE  profile_name = :profile_name ";
  $profile_name = !empty($profile_name) ? $profile_name : $this->profile_name;
  $value_a = [ 'profile_name' => $profile_name];
  if (!empty($profile_name)) {
   $result_array = $this->findBySql($sql, $value_a);
   $result_h = array_pop($result_array);
  } else {
   return false;
  }

  if (!empty($result_h)) {
   //get line values
   $result_l = $this->findBy_headerId_profileLevel($result_h->sys_profile_header_id, $level_name);
   return $result_l;
  } else {
   return false;
  }
 }

 public function find_default_profile($profile_name) {
  $default_profile = null;
  $all_proflies = $this->findAll_profile($profile_name);

  if (!empty($_SESSION['user_id']) && !empty($all_proflies)) {
   foreach ($all_proflies as $key => $profile) {
    if (($profile->profile_level == 'USER') && ($profile->level_name == $_SESSION['user_id'])) {
     $default_profile = $all_proflies[$key];
     break;
    }
   }
   if (!empty($default_profile)) {
    return ($default_profile);
   }
  }

  if (!empty($_SESSION['org_inv_name_default']) && !empty($all_proflies)) {
   foreach ($all_proflies as $key => $profile) {
    if (($profile->profile_level == 'INVENTORY') && ($profile->level_name == $_SESSION['org_inv_name_default'])) {
     $default_profile = $all_proflies[$key];
     break;
    }
   }
   if (!empty($default_profile)) {
    return ($default_profile);
   }
  }

  if (!empty($_SESSION['org_bu_name_default']) && !empty($all_proflies)) {
   foreach ($all_proflies as $key => $profile) {
    if (($profile->profile_level == 'BUSINESS') && ($profile->level_name == $_SESSION['org_bu_name_default'])) {
     $default_profile = $all_proflies[$key];
     break;
    }
   }
   if (!empty($default_profile)) {
    return ($default_profile);
   }
  }

  if (!empty($all_proflies)) {
   foreach ($all_proflies as $key => $profile) {
    if (($profile->profile_level == 'SITE')) {
     $default_profile = $all_proflies[$key];
     break;
    }
   }
  }
  return !empty($default_profile) ? ($default_profile) : false;
 }

 public function findAll_profile($profile_name) {
  $sql = " SELECT sph.profile_name,sph.description,sph.profile_class_name,
           spl.sys_profile_line_id, spl.sys_profile_header_id, spl.profile_level, spl.level_name, spl.level_value
           FROM sys_profile_header sph
          LEFT JOIN sys_profile_line spl ON spl.sys_profile_header_id = sph.sys_profile_header_id 
     WHERE sph.profile_name = :proflile_name ";
  $value_a = ['proflile_name' => $profile_name];
  $result = $this->findBySql($sql, $value_a);
  return !empty($result) ? $result : false;
 }

 public function findBy_headerId_profileLevel($header_id, $profile_level) {
  $sql = " SELECT * FROM ";
  $sql .= self::$table_name;
  $sql .= " WHERE sys_profile_header_id = :header_id AND profile_level = :profile_level ";

  $value_a = ['header_id' => $header_id, 'profile_level' => $profile_level];
  $result = $this->findBySql($sql, $value_a);
  return !empty($result) ? $result : false;
 }

 public static function find_by_headerId_profileLevel($header_id, $profile_level) {
  $sql = " SELECT * FROM ";
  $sql .= self::$table_name;
  $sql .= " WHERE sys_profile_header_id = '{$header_id}' AND profile_level = '{$profile_level}' ";

  $result = self::find_by_sql($sql);
  return !empty($result) ? $result : false;
 }

 public static function find_all_lines() {
  $sql = " SELECT * FROM " . self::$table_name;
  $result = self::find_by_sql($sql);
  return $result;
 }

 public static function find_by_header_id($id) {
  $vgl = new sys_profile_line();
  return $vgl->findBy_parentId($id);
 }

 public static function find_by_optionId_lineCode($header_id, $code) {
  $sql = "SELECT * FROM " . self::$table_name .
   " where code={$code} AND sys_profile_header_id={$header_id} ";
   $sql = ino_perPageSql_i($sql, 1);
  $result = self::find_by_sql($sql);
  return !empty($result) ? array_push($result) : $result;
 }

}

$profile_line = new sys_profile_line();
$prl = & $profile_line;
//end of path class
?>