<?php

class view_path {
 public static $table_name = "view_path";
 //  data base variables as stored database column name
 public static $field_array = [
     "column_name",
     "path",
     "description",
		 "view_id"
		  ];
//variables used for showing data

 public static $initial_search_array = [
     "column_name",
     "path",
     "description",
 ];
 
 public static $checkbox_array = [
     		  ];
 
 public static $column_array = [
     "column_name",
     "path",
     "description",
 ];
 
 public static $base_encoded_array = [
		  ];
 
 public static $requiredField_array = [
       "column_name",
     "path",
     "description",
 ];
 
 public static $primary_column = "view_path_id";
 public $view_path_id;
 public $view_id;
 public $column_name;
 public $path;
 public $description;
 public $msg;

 public function __set($name, $value) {
  $this->$name = $value;
 }

 public static function find_by_sql($sql = "") {
  global $db;
  $result_set = $db->query($sql);
  $object_array = array();
  while ($row = $db->fetch_array($result_set)) {
   $object_array[] = self::instantiate($row);
  }//end of while Loop
  return $object_array;
 }

 public static function find_all() {
  $sql = " SELECT * FROM " . self::$table_name;
  $result = self::find_by_sql($sql);
  return $result;
 }

 public static function count_all() {
  global $db;
  $sql = "SELECT COUNT(*) FROM " . self::$table_name;
  $result_set = $db->query($sql);
  $row = $db->fetch_array($result_set);
  return array_shift($row);
 }

 public static function count_all_by_sql($sql) {
  global $db;
  $result_set = $db->query($sql);
  $row = $db->fetch_array($result_set);
  return array_shift($row);
 }

 public static function find_by_id($view_id) {
  $sql = "SELECT * FROM " . self::$table_name . " where view_id={$view_id} LIMIT 1";
  $result_array = self::find_by_sql($sql);
  return !empty($result_array) ? array_shift($result_array) : false;
 }
 
  public static function find_by_view_id($view_id) {
  $sql = " SELECT * FROM " . self::$table_name;
	$sql .= " WHERE view_id = '{$view_id}'";
  $result = self::find_by_sql($sql);
  return $result;
 }
 
   public static function find_by_columnName_viewId($column_name,$view_id) {
  $sql = " SELECT * FROM " . self::$table_name;
	$sql .= " WHERE view_id = '{$view_id}'";
	$sql .= " AND column_name = '{$column_name}' LIMIT 1";
  $result_array = self::find_by_sql($sql);
  return !empty($result_array) ? array_shift($result_array) : false;
 }

 private static function instantiate($record) {
  $object = new self;
  foreach ($record as $attribute => $value) {
   if ($object->has_attribute($attribute)) {
    $object->$attribute = $value;
   }
  }
  return $object;
 }

 Private function has_attribute($attribute) {
  $object_vars = get_object_vars($this);
  return array_key_exists($attribute, $object_vars);
 }

 public static function install() {
  global $db;
  $sql = "
		 ";
  $result = $db->query($sql);
  return !empty($result) ? $result : false;
 }

 public function save() {
//	echo '<br> in view path save';
  if (empty($this->view_path_id)) {
   $this->create();
  } else {
   $this->update($this->view_path_id);
  }
  return $this->msg;
 }

 public function create() {
  global $db;
  $field_arry_colums = array();
  $field_arry_values = array();
  foreach (self::$field_array as $key => $value) {
   $field_arry_colums[] = sprintf("`%s`", $value);
  }
  $field_colums = implode(',', $field_arry_colums);

  foreach (self::$field_array as $key => $value) {
   if (!empty($this->$value)) {
    $field_arry_values[] = sprintf("'%s'", $this->$value);
   } else {
    $field_arry_values[] = 'NULL';
   }
  }
  $field_values = implode(',', $field_arry_values);

  $sql = " INSERT INTO ";
  $sql.= self::$table_name;
  $sql.= ' ( ';
  $sql.= $field_colums;
  $sql.= ' ) ';
  $sql.= 'VALUES';
  $sql.= ' ( ';
  $sql.= $field_values;
  $sql.= ' ) ';

//echo "<br/>sql is $sql ";
  if ($db->query($sql)) {
   $this->view_path_id = $db->insert_id();
   $this->msg = 1;
  } else {
   $this->msg = 0;
  }
  return $this->msg;
 }

//end of create view

 public function update($view_path_id) {
	  global $db;
  $field_arry_values = array();

  foreach (self::$field_array as $key => $value) {
   if (isset($this->$value)) {
    $field_arry_values[] = sprintf("`%s` = '%s'", $value, $this->$value);
   }
  }
  $field_values = implode(',', $field_arry_values);

  $time = time();
  $last_update_date = strftime("%d-%m-%y %H:%M:%S", $time);
  $last_update_by = $_SESSION['user_name'];

  $sql = " UPDATE ";
  $sql.= self::$table_name;
  $sql .= " SET ";
  $sql.= $field_values;
//    $sql.= "`last_update_date` = '{$last_update_date}'," ;
//    $sql.= "`last_update_by` = '{$last_update_by }'" ;
  $sql.= " WHERE `view_path_id` = '{$view_path_id}' ";

//    echo "<br/>$sql is <br/>" . $sql;

  if ($db->query($sql)) {
   $this->msg = 2;
  } else {
   $this->msg = 0;
  }
  return $this->msg;
 }

}

//end of view class
?>



