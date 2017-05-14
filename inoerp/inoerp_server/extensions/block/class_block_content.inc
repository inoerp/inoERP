<?php

class block_content extends dbObject {

 public static $table_name = "block_content";
 public static $primary_column = "block_content_id";
 public static $key_column = "block_id";
 public static $module = "extension";
 //  data base variables as stored database column name

 public $field_a = [
  'block_content_id',
  "block_id",
  "info",
  "content",
  'content_php_cb',
  "created_by",
  "creation_date",
  "last_update_by",
  "last_update_date"
 ];
//variables used for showing data

 public $checkbox = [
  'content_php_cb'
 ];
 public $requiredField = [
  'block_id',
  "info",
  "content"
 ];
 public $block_content_id;
 public $block_id;
 public $info;
 public $content;
 public $content_php_cb;
 public $created_by;
 public $creation_date;
 public $last_update_by;
 public $last_update_date;
 public $time;
 public $msg;

 //dont delete below
 public static function find_by_block_id($id) {
  $sql = "SELECT * FROM " . self::$table_name . " where block_id='{$id}'  ";
  $sql = ino_perPageSql_i($sql, 1);
  $result_array = self::find_by_sql($sql);
  return !empty($result_array) ? array_pop($result_array) : false;
 }

}

//end of block class
?>