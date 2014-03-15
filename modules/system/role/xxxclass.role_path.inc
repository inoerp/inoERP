<?php

class role_path extends dbObject{

 protected static $table_name = "role_path";
//  data base variables as stored database column name
 public static $field_array = [
		 "role_path_id",
		 "role_id",
		 "path_id",
		 "created_by",
		 "creation_date",
		 "last_update_by",
		 "last_update_date"
 ];
 public static $initial_search_array = [
		 "role_path_id",
		 "role_id",
		 "path_id"
 ];
//variables used for showing data
 public static $checkbox_array = [
 ];
 public static $column_array = [
		 "role_path_id",
		 "role_id",
		 "path_id"
 ];
 public static $requiredField_array = [
		 "role_id",
		 "path_id"
 ];
 public static $primary_column = "role_path_id";
 public $role_id;
 public $role_path_id;
 public $path_id;
 public $created_by;
 public $creation_date;
 public $last_update_by;
 public $last_update_date;
 public $time;
 public $msg;

 public function __set($name, $value) {
	$this->$name = $value;
 }

 Public static function roles() {
	$option_type = option_header::find_by_name('USER_ROLES');
	$option_line = option_line::find_by_option_id($option_type->option_header_id);
	return $option_line;
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

 public static function count_all_by_sql($sql) {
	global $db;
	$result_set = $db->query($sql);
	$row = $db->fetch_array($result_set);
	return array_shift($row);
 }

 public static function count_all() {
	global $db;
	$sql = "SELECT COUNT(*) FROM " . self::$table_name;
	$result_set = $db->query($sql);
	$row = $db->fetch_array($result_set);
	return array_shift($row);
 }

// public static function find_all() {
//	$sql = " SELECT * FROM " . self::$table_name;
//	$result = self::find_by_sql($sql);
//	return $result;
// }

 public static function find_by_id($role_path_id) {
	$sql = "SELECT * FROM " . self::$table_name . " where role_path_id='{$role_path_id}' LIMIT 1";
	$result_array = self::find_by_sql($sql);
	return !empty($result_array) ? array_shift($result_array) : false;
 }

 public static function find_by_roleId($role_id) {
	$sql = "SELECT * FROM " . self::$table_name . " where role_id={$role_id} ";
	$result = self::find_by_sql($sql);
	return $result;
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

 public function save() {

	if (empty($this->role_path_id)) {
	 $this->create();
	} else {
	 $this->update($this->role_path_id);
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


	if ($db->query($sql)) {
	 $this->role_path_id = $db->insert_id();
	 $this->msg = 1;
	} else {
	 $this->msg = 0;
	}
	return $this->msg;
 }

//end of create role_path

 public function update($role_path_id) {
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
	$sql.= " WHERE `role_path_id` = '{$role_path_id}' ";

//    echo "<br/>$sql is <br/>" . $sql;

	if ($db->query($sql)) {
	 $this->msg = 2;
	} else {
	 $this->msg = 0;
	}
	return $this->msg;
 }

//end of update role_path

 public static function role_delete($role_path_id) {
	global $db;
	$role_path_id = $db->escape_value($role_path_id);
//        echo '<br/>roleid : ' . $role_id . '<br/>';

	$sql = "DELETE FROM `role_path` WHERE `role_path_id` = '{$role_path_id}' ";
//      $result = mysql_query($query);
	if ($db->query($sql)) {
	 return true;
	} else {
	 return false;
	}
 }

//end of update delete
//end of menu..if no role_path found then leave blank
//end of role_path class
}

?>
