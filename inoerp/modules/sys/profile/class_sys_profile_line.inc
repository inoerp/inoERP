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

 public function __set($name, $value) {
	$this->$name = $value;
 }

 public function findBy_headerId_profileLevel($header_id, $profile_level){
	$sql = " SELECT * FROM ";
	$sql .= self::$table_name;
	$sql .= " WHERE sys_profile_header_id = :header_id AND profile_level = :profile_level ";
	
	$value_a = ['header_id' => $header_id, 'profile_level' => $profile_level ];
	$result = $this->findBySql($sql, $value_a);
	return !empty($result) ? $result : false;
 }
 
  public static function find_by_headerId_profileLevel($header_id, $profile_level){
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
					" where code={$code} AND sys_profile_header_id={$header_id} LIMIT 1 ";
	$result = self::find_by_sql($sql);
	return !empty($result) ? array_push($result) : $result;
 }

}

//end of path class
?>