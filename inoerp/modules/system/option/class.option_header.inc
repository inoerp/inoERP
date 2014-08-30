<?php

class option_header extends dbObject {

 protected static $table_name = "option_header";
 public static $access_level_array = [
     'system' => 'System',
     'user' => 'User',
     'both' => 'Both'
 ];
 public static $field_array = [
     "option_header_id",
     "option_type",
     "access_level",
     "description",
     "module",
     'option_assignments',
		 "efid",
     "status",
     "rev_enabled",
     "rev_number",
     "created_by",
     "creation_date",
     "last_update_by",
     "last_update_date"
 ];
 public static $initial_search_array = [
     "option_header_id",
     "option_type",
     "description",
 ];
 public static $checkbox_array = [
 ];
 public static $column_array = [
     "option_header_id",
     "option_type",
     "description",
     "module"
 ];
 public static $base_encoded_array = [];
// public static $requiredField_array = [
//     "option_type",
//     "access_level",
//     "description",
//     "module",
// ];
  public $requiredField = [
     "option_type",
     "access_level",
     "description",
     "module",
 ];
 public static $primary_column = "option_header_id";
  public static $key_column = 'option_type';
 public $option_header_id;
 public $access_level;
 public $option_type;
 public $description;
 public $module;
 public $option_assignments;
 public $value_group_id;
 public $efid;
 public $status;
 public $rev_enabled;
 public $rev_number;
 public $created_by;
 public $creation_date;
 public $last_update_by;
 public $last_update_date;
 public $time;
 public $msg;
 public static $dir = __DIR__;

 public function __set($name, $value) {
  $this->$name = $value;
 }

 Public static function countries() {
  $option_header = self::find_by_name('COUNTRY');
  $countries = option_line::find_by_option_id($option_header->option_header_id);
  return $countries;
 }

 Public static function currencies() {
  $option_header = self::find_by_name('CURRENCY');
  $currencies = option_line::find_by_option_id($option_header->option_header_id);
  return $currencies;
 }

 Public static function exception_actions() {
  $option_header = self::find_by_name('EXCEPTION_ACTION');
  $exception_actions = option_line::find_by_option_id($option_header->option_header_id);
  return $exception_actions;
 }

 Public static function option_assignments() {
  $option_header = self::find_by_name('OPTION_ASSIGNMENT');
  $result = option_line::find_by_option_id($option_header->option_header_id);
  return $result;
 }

 public static function find_all_headers() {
  $sql = " SELECT * FROM " . self::$table_name;
  $result = self::find_by_sql($sql);
  return $result;
 }

 public static function find_by_name($option_types) {
  global $db;
  $sql = "SELECT * FROM " . self::$table_name . " where option_type LIKE '%{$option_types}%' LIMIT 1";
  $result_array = self::find_by_sql($sql);
  return !empty($result_array) ? array_shift($result_array) : false;
 }

 public static function find_by_exact_name($option_types) {
  global $db;
  $sql = "SELECT * FROM " . self::$table_name . " WHERE option_type = '$option_types' LIMIT 1";
  $result_array = self::find_by_sql($sql);
  return !empty($result_array) ? array_shift($result_array) : false;
 }

 public static function install() {
  global $db;
  $sql = "
          CREATE TABLE IF NOT EXISTS `option_header` (
            `option_id` int(10) unsigned NOT NULL auto_increment,
            `access_level` varchar(20) NOT NULL default 'both',
            `option_type` varchar(50) NOT NULL,
            `description` varchar(200) default NULL,
            `module` varchar(50) NOT NULL default 'system',
            `efid` int(12) default NULL,
            `status` varchar(20) default NULL,
            `rev_enabled` varchar(20) default NULL,
            `rev_number` int(10) default NULL,
            `created_by` varchar(40) NOT NULL default '',
            `creation_date` varchar(50) default NULL,
            `last_update_by` varchar(40) NOT NULL default '',
            `last_update_date` varchar(50) default NULL,
            PRIMARY KEY  (`option_id`),
            UNIQUE KEY `option_type` (`option_type`)
          ) ENGINE=MyISAM  DEFAULT CHARSET=latin1 AUTO_INCREMENT=59 ";
  $result = $db->query($sql);

  return !empty($result) ? $result : false;
 }

 public function save() {
  if (empty($this->option_header_id)) {
   $check_option_type = $this->check_option_type();
   if ($check_option_type == 0) {
    $this->create();
   } else {
    $this->msg = "Option type already exists";
   }
  } else {
   $this->update($this->option_header_id);
  }
  return $this->msg;
 }

 private function check_option_type() {
  global $db;
  $sql = "SELECT * FROM " . self::$table_name . " where option_type='{$this->option_type}' ";
  $result_array = self::find_by_sql($sql);
  if (count($result_array) > 0) {
   $this->msg = 1;
  } else {
   $this->msg = 0;
  }
  return $this->msg;
 }

}

//end of path class
?>
