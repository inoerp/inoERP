<?php

class option_line extends dbObject {

 public static $table_name = "option_line";
 public static $primary_column = "option_line_id";
 public static $key_column = 'option_line_code';
 public static $module = "sys";
 public static $parent_primary_column = 'option_header_id';
 public $field_a = [
  "option_header_id",
  "option_line_id",
  "option_line_code",
  "option_line_value",
  "description",
  'value_group_id',
  "priority",
  "status",
  'mapper1',
  'mapper2',
  "rev_enabled",
  "rev_number",
  "effective_start_date",
  "effective_end_date",
  "created_by",
  "creation_date",
  "last_update_by",
  "last_update_date"
 ];
 public $initial_search = [
  "option_header_id",
  "option_line_id",
  "option_line_code",
  "description"
 ];
 public $checkbox = [
  "rev_enabled",
 ];
 public $column = [
  "option_header_id",
  "option_line_id",
  "option_line_code",
  "description"
 ];
 public $fields_inHeader_needsToBeInserted_inPOST = [
  "option_header_id"
 ];
 public $requiredField = [
  "option_header_id",
  "option_line_code",
  "description"
 ];
 public $number_fields = [
  "option_header_id",
  "option_line_id",
  'value_group_id',
 ];
 public $option_header_id;
 public $option_line_id;
 public $option_line_code;
 public $option_line_value;
 public $description;
 public $value_group_id;
 public $priority;
 public $status;
 public $rev_enabled;
 public $rev_number;
 public $effective_start_date;
 public $effective_end_date;
 public $mapper1;
 public $mapper2;
 public $created_by;
 public $creation_date;
 public $last_update_by;
 public $last_update_date;
 public $msg;


 public function find_all_lines() {
  $sql = " SELECT * FROM " . self::$table_name;
  $result = self::find_by_sql($sql);
  return $result;
 }

 public static function find_by_option_id($id) {
//  $ol = new option_line();
 return option_line::find_by_parent_id($id);
 }

 public static function find_by_optionId_lineCode($option_id, $line_code) {
  $sql = "SELECT * FROM " . self::$table_name .
   " where option_line_code='{$line_code}' AND option_header_id='{$option_id}' ";
   $sql = ino_perPageSql_i($sql, 1);
  $result_array = self::find_by_sql($sql);
  return !empty($result_array) ? array_pop($result_array) : false;
 }
 
 public static function find_by_optionType_lineCode($option_type, $line_code) {
  $sql = "SELECT * FROM option_line ol, option_header oh 
    where ol.option_line_code='{$line_code}' 
    AND oh.option_type='{$option_type}' 
    AND oh.option_header_id = ol.option_header_id ";
    $sql = ino_perPageSql_i($sql, 1);
  $result_array = self::find_by_sql($sql);
  return !empty($result_array) ? array_pop($result_array) : false;
 }

 public static function install() {
  global $db;
  $sql = "
             CREATE TABLE IF NOT EXISTS `option_line` (
            `option_line_id` int(10) unsigned NOT NULL auto_increment,
            `option_id_l` int(12) NOT NULL,
            `option_line_code` varchar(50) NOT NULL,
            `value_l` varchar(50) NOT NULL,
            `description_l` varchar(255) default NULL,
            `efid_l` int(12) default NULL,
            `status_l` int(2) default '1',
            `rev_enabled_l` int(2) default '0',
            `rev_number_l` int(10) default NULL,
            `effective_start_date` varchar(50) default NULL,
            `effective_end_date` varchar(50) default NULL,
            `created_by_l` varchar(40) NOT NULL default '',
            `creation_date_l` varchar(50) default NULL,
            `last_update_by_l` varchar(40) NOT NULL default '',
            `last_update_date_l` varchar(50) default NULL,
            PRIMARY KEY  (`option_line_id`),
            UNIQUE KEY `option_code` (`option_line_code`),
            KEY `option_id` (`option_id_l`)
          ) ENGINE=MyISAM  DEFAULT CHARSET=latin1 ;
          ";
  $result = $db->query($sql);
  return !empty($result) ? $result : false;
 }

}

//end of path class
?>