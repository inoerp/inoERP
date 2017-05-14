<?php

class extn_report_path extends dbObject {

 public static $table_name = "extn_report_path";
 public static $primary_column = "extn_report_path_id";
 public static $parent_primary_column = "extn_report_id";
 //  data base variables as stored database column name
 public $field_a = [
  "column_name",
  "path",
  "description",
  "extn_report_id"
 ];
//variables used for showing data

 public $initial_search = [
  "column_name",
  "path",
  "description",
 ];
 public $column = [
  "column_name",
  "path",
  "description",
 ];
 public $requiredField = [
  "column_name",
  "path",
  "description",
 ];
 public $extn_report_path_id;
 public $extn_report_id;
 public $column_name;
 public $path;
 public $description;
 public $msg;

 public static function find_by_extn_report_id($extn_report_id) {
  $sql = " SELECT * FROM " . self::$table_name;
  $sql .= " WHERE extn_report_id = '{$extn_report_id}'";
  $result = self::find_by_sql($sql);
  return $result;
 }

 public static function find_by_columnName_extn_reportId($column_name, $extn_report_id) {
  $sql = " SELECT * FROM " . self::$table_name;
  $sql .= " WHERE extn_report_id = '{$extn_report_id}'";
  $sql .= " AND column_name = '{$column_name}' ";
  $sql = ino_perPageSql_i($sql, 1);
  $result_array = self::find_by_sql($sql);
  return !empty($result_array) ? array_shift($result_array) : false;
 }

}

//end of extn_report class
?>