<?php

class view_path extends dbObject{
 public static $table_name = "view_path";
 public static $primary_column = "view_path_id";
 public static $parent_primary_column = "view_id";
 //  data base variables as stored database column name
 public $field_a = [
     "column_name",
     "path",
     "description",
		 "view_id"
		  ];
//variables used for showing data

 public $initial_search = [
     "column_name",
     "path",
     "description",
 ];
 
 public  $column = [
     "column_name",
     "path",
     "description",
 ];
 
 public $requiredField = [
       "column_name",
     "path",
     "description",
 ];
 
 
 public $view_path_id;
 public $view_id;
 public $column_name;
 public $path;
 public $description;
 public $msg;

 
  public static function find_by_view_id($view_id) {
  $sql = " SELECT * FROM " . self::$table_name;
	$sql .= " WHERE view_id = '{$view_id}'";
  $result = self::find_by_sql($sql);
  return $result;
 }
 
   public static function find_by_columnName_viewId($column_name,$view_id) {
  $sql = " SELECT * FROM " . self::$table_name;
	$sql .= " WHERE view_id = '{$view_id}'";
	$sql .= " AND column_name = '{$column_name}' ";
  $sql = ino_perPageSql_i($sql, 1);
  $result_array = self::find_by_sql($sql);
  return !empty($result_array) ? array_shift($result_array) : false;
 }

}

//end of view class
?>