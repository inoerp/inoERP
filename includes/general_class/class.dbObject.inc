<?php

class dbObject {

// protected static $table_name = "";
//  data base variables as stored database column name
 public static $field_array = [];
//variables used for showing data

 public static $initial_search_array = [];
 public static $checkbox_array = [];
 public static $column_array = [];
 public static $requiredField_array = [];
 public static $position_array = [1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25];
 public static $primary_column = "";
 public static $key_column = '';
 public static $parent_primary_column = null;
 public $time;
 public $msg;
 public $conn;
 public $field_a = [];

 function __construct() {
//	if (!empty(static::$table_name)) {
////	 echo '<br> table name '. static::$table_name;
//	 global $dbc;
//	 $sql_fields = " SHOW COLUMNS FROM  " . static::$table_name;
//	 $prepare = $dbc->connection->prepare($sql_fields);
//	 $prepare->execute();
//	 $fields = $prepare->fetchAll(PDO::FETCH_COLUMN, 0);
//	 static::$field_array = $fields;
//	 foreach ($fields as $key => $value) {
//		$this->$value = '';
//	 }
//	}
 }

 public function __set($name, $value) {
	$this->$name = $value;
 }

 public function get($var) {
	if (property_exists(get_called_class(), $var)) {
	 return $this->$var;
	} else {
	 return false;
	}
 }

 function query($sql) {
	echo "sql is $sql";
	global $dbc;
	if (!empty($sql)) {
	 $prepare = $dbc->connection->prepare($sql);
	 try {
		$prepare->execute();
		$result = $prepare->fetchAll(PDO::FETCH_CLASS);
		return $result;
	 } catch (PDOException $e) {
		print " Execution failed! in dbObject Query: " . $e->getMessage() . "<br/>";
	 }
	}
 }

// public function findBy_parentHeaderId($header_id) {
//	if (!empty(parent::$primary_column)) {
//	 $sql = "SELECT * FROM " . parent::$table_name . " where " . parent::$primary_column . " = '{$header_id}'";
//	 $result_array = $this->findBy_sql($sql);
//	} else {
//	 $result_array = false;
//	}
//	return $result_array;
// }

 public function findBy_sql($sql, $param_a, $value_a) {
	global $dbc;
	$stmt = $dbc->connection->prepare(" $sql ");
	foreach ($param_a as $key => $param) {
	 if (!empty($value_a[$param])) {
		$stmt->bindValue(":$param", $value_a[$param]);
	 } else {
		$stmt->bindValue(":$param", NULL);
	 }
	}
	try {
	 $stmt->execute();
	 $result = $stmt->fetchAll(PDO::FETCH_CLASS);
	 return $result;
	} catch (PDOException $e) {
	 $ie->page_exception = ['dbObject findBy id Error : ' => $e->getMessage()];
	 echo "Record couldnt be fetched !!: " . $e->getMessage();
	 return 0;
	}
 }

 /* End of public functions and start of public static functions  */

 public static function show_column_from_table($tableName = "") {
	global $dbc;
	$sql = " SHOW COLUMNS FROM $tableName ";
	$prepare = $dbc->connection->prepare($sql);
	$prepare->execute();
	$result_fetchAll = $prepare->fetchAll(PDO::FETCH_COLUMN, 0);
	return $result_fetchAll;
 }

 public static function show_allColumn_from_table($tableName = "") {
	global $dbc;
	$sql = " SHOW COLUMNS FROM $tableName ";
	$prepare = $dbc->connection->prepare($sql);
	$prepare->execute();
	$result_fetchAll = $prepare->fetchAll(PDO::FETCH_CLASS);
	return $result_fetchAll;
 }

 public static function show_table_details($tableName = "") {
	global $dbc;
	$sql = " SHOW COLUMNS FROM $tableName ";
	$prepare = $dbc->connection->prepare($sql);
	$prepare->execute();
	$result_fetchAll = $prepare->fetchAll(PDO::FETCH_CLASS);
	return $result_fetchAll;
 }

 public static function find_by_sql($sql = "") {
	global $dbc;
	$prepare = $dbc->connection->prepare($sql);
	$prepare->execute();
	$result_fetchAll = $prepare->fetchAll(PDO::FETCH_CLASS);
	return $result_fetchAll;
 }

 public static function find_by_sql_array($sql = "") {
	global $dbc;
	$prepare = $dbc->connection->prepare($sql);
	$prepare->execute();
	$result = $prepare->fetchAll(PDO::FETCH_NUM);
	return $result;
 }

 public static function find_by_sql_all($sql = "") {
	global $dbc;
	$prepare = $dbc->connection->prepare($sql);
	$prepare->execute();
	$result_fetchAll = $prepare->fetchAll();
	return $result_fetchAll;
 }

 public static function find_all() {
	$sql = " SELECT * FROM " . static::$table_name;
	$result = static::find_by_sql($sql);
	return $result;
 }

 public static function find_few($no_of_records = 2) {
	$sql = " SELECT * FROM " . static::$table_name . " LIMIT $no_of_records ";
	$result = static::find_by_sql($sql);
	return $result;
 }

 public static function find_some_byIdArray($id_array) {
	$result_array = [];
	foreach ($id_array as $key => $value) {
	 $result = static::find_by_id($value);
	 array_push($result_array, $result);
	}
	return $result_array;
 }

 public static function count_all() {
	$sql = "SELECT COUNT(*) FROM " . static::$table_name;
	$result = static::find_by_sql_array($sql);
	return !empty($result) ? array_shift2($result) : false;
 }

 public static function count_all_by_sql($sql) {
	$result = static::find_by_sql_array($sql);
	return !empty($result) ? array_shift2($result) : false;
 }

 public static function find_by_id($id) {
	global $ie;
	global $dbc;
	$sql = " SELECT * FROM ";
	$sql.= static::$table_name;
	$sql.= " WHERE " . static::$primary_column . "= :primary_id ";
	$sql.= " LIMIT 1 ";
	$stmt = $dbc->connection->prepare(" $sql ");
	$stmt->bindParam(':primary_id', $id);
	try {
	 $stmt->execute();
	 $result = $stmt->fetchObject();
	} catch (PDOException $e) {
	 $ie->page_exception = ['dbObject findBy id Error : ' => $e->getMessage()];
	 echo "Record couldnt be saved!!: " . $e->getMessage();
	}
	return $result;
 }

 public function findAll($id) {
	global $ie;
	global $dbc;
	$sql = " SELECT * FROM ";
	$sql.= static::$table_name;
	$stmt = $dbc->connection->prepare(" $sql ");
	$stmt->bindParam(':primary_id', $id);
	try {
	 $stmt->execute();
	 $result = $stmt->fetchObject();
	} catch (PDOException $e) {
	 $ie->page_exception = ['dbObject findBy id Error : ' => $e->getMessage()];
	 echo "Record couldnt found!!: " . $e->getMessage();
	}
	if (!empty($result)) {
	 return $result;
	} else {
	 $ie->page_exception = ['dbObject findBy id Error : ' => 'No records found'];
	}
 }

 public function findBy_id($id) {
	global $ie;
	global $dbc;
	$sql = " SELECT * FROM ";
	$sql.= static::$table_name;
	$sql.= " WHERE " . static::$primary_column . "= :primary_id ";
	$sql.= " LIMIT 1 ";
	$stmt = $dbc->connection->prepare(" $sql ");
	$stmt->bindParam(':primary_id', $id);
	try {
	 $stmt->execute();
	 $result = $stmt->fetchObject();
	} catch (PDOException $e) {
	 $ie->page_exception = ['dbObject findBy id Error : ' => $e->getMessage()];
	 echo "Record couldnt found!!: " . $e->getMessage();
	}
	if (!empty($result)) {
	 return $result;
	} else {
	 $ie->page_exception = ['dbObject findBy id Error : ' => 'No records found'];
	}
 }

 public function findBy_parentId($id, $order_by_field = '', $order_by_seq = 'ASC') {
	if (empty($id)) {
	 return false;
	}
	global $ie;
	global $dbc;
	$sql = " SELECT * FROM ";
	$sql.= static::$table_name;
	$sql.= " WHERE " . static::$parent_primary_column . "= :primary_id ";
	if (!empty($order_by_field)) {
	 $sql.= " ORDER BY {$order_by_field} $order_by_seq ";
	}
	$stmt = $dbc->connection->prepare(" $sql ");
	$stmt->bindParam(':primary_id', $id);
	try {
	 $stmt->execute();
	 $result = $stmt->fetchAll(PDO::FETCH_CLASS);
	} catch (PDOException $e) {
	 $ie->page_exception = ['dbObject findBy parent id Error : ' => $e->getMessage()];
	}
	if (!empty($result)) {
	 return $result;
	} else {
	 $ie->page_exception = ['dbObject findBy parent id Error : ' => 'No records found'];
	 return false;
	}
 }

 public static function find_by_id_array($id) {
	global $dbc;
	$sql = "SELECT * FROM " . static::$table_name . " where `" . static::$primary_column . "` ='{$id}'  LIMIT 1";
	$result_array = static::find_by_sql_array($sql);
	return !empty($result_array) ? array_shift($result_array) : false;
 }

 public static function find_by_keyColumn($columnName) {
	$sql = "SELECT * FROM " . static::$table_name . " where `" . static::$key_column . "` ='{$columnName}'  LIMIT 1";
	$result_array = static::find_by_sql($sql);
	return !empty($result_array) ? array_shift($result_array) : false;
 }

 public static function find_by_keyColumn_array($columnName) {
	global $dbc;
	$sql = "SELECT * FROM " . static::$table_name . " where `" . static::$columnName . "` ='{$columnName}'  LIMIT 1";
	$result_array = static::find_by_sql_array($sql);
	return !empty($result_array) ? array_shift($result_array) : false;
 }

 private static function instantiate($record) {
	$object = new static;
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

 protected function audit_trial() {
	$this->creation_date = current_time();
	if ((isset($_SESSION)) && (!empty($_SESSION['username']))) {
	 $this->created_by = $_SESSION['username'];
	} else {
	 $this->created_by = 'selfWeb';
	}
	$this->last_update_date = $this->creation_date;
	$this->last_update_by = $this->created_by;
 }

 public function save() {
	$primary_column = static::$primary_column;
	if (empty($this->$primary_column)) {
	 $this->create();
	} else {
	 $this->update($this->$primary_column);
	}
	return $this->msg;
 }

 public function create() {
	global $dbc;
	$primary_column = static::$primary_column;
	if (property_exists($this, 'field_a')) {
	 $field_array = $this->field_a;
	} else {
	 $field_array = static::$field_array;
	}
	$field_colums = '';
	foreach ($field_array as $key => $value) {
	 $field_colums .= $value . ', ';
	}
	$field_colums = rtrim($field_colums, ', ');

	$field_values = '';
	foreach ($field_array as $key => $value) {
	 $field_values .= ':' . $value . ', ';
	}
	$field_values = rtrim($field_values, ', ');
//write SQL
	$sql = " INSERT INTO ";
	$sql.= static::$table_name;
	$sql.= ' ( ';
	$sql.= $field_colums;
	$sql.= ' ) ';
	$sql.= 'VALUES';
	$sql.= ' ( ';
	$sql.= $field_values;
	$sql.= ' ) ';
	$stmt = $dbc->connection->prepare(" $sql ");
//Bind parameters
	foreach ($field_array as $key => $value) {
	 if (!empty($this->$value)) {
		$stmt->bindParam(":$value", $this->$value);
	 } else {
		$stmt->bindvalue(":$value", null, PDO::PARAM_INT);
	 }
	}
	try {
	 $stmt->execute();
	 $this->$primary_column = $dbc->connection->lastInsertId();
	 $this->msg = 1;
	} catch (PDOException $e) {
	 $this->msg = 0;
	 echo "Record couldnt be saved!!: Error Code : DBO01 " . $e->getMessage() . "<br/>";
	}

//	$field_arry_colums = array();
//	$field_arry_values = array();
//	foreach (static::$field_array as $key => $value) {
//	 $field_arry_colums[] = sprintf("`%s`", $value);
//	}
//	$field_colums = implode(',', $field_arry_colums);
//
//	foreach (static::$field_array as $key => $value) {
//	 if (!empty($this->$value)) {
//		$field_arry_values[] = sprintf("'%s'", $this->$value);
//	 } else {
//		$field_arry_values[] = 'NULL';
//	 }
//	}
//	$field_values = implode(',', $field_arry_values);
//
//	$sql = " INSERT INTO ";
//	$sql.= static::$table_name;
//	$sql.= ' ( ';
//	$sql.= $field_colums;
//	$sql.= ' ) ';
//	$sql.= 'VALUES';
//	$sql.= ' ( ';
//	$sql.= $field_values;
//	$sql.= ' ) ';
//
////	echo '<div class="message"><br/>$sql is : ' . $sql . '</div>';
//	$primary_column = static::$primary_column;
//
//	$prepare = $dbc->connection->prepare($sql);
//
//	if ($prepare->execute()) {
//	 $this->$primary_column = $dbc->connection->lastInsertId();
//	 $this->msg = 1;
//	} else {
//	 echo "\nRecord couldnt be saved:\n";
//	 $dbc->connection->errorInfo();
//
//	 $this->msg = 0;
//	}
	return $this->msg;
 }

//update function
 public function update($id) {
	global $ie;
	global $dbc;
	if (property_exists($this, 'field_a')) {
	 $field_array = $this->field_a;
	} else {
	 $field_array = static::$field_array;
	}
	$field_stmt = '';
	foreach ($field_array as $key => $value) {
	 if (!empty($this->$value)) {
		$field_stmt .= $value . ' = :' . $value . ', ';
	 }
	}
	$field_stmt_f = rtrim($field_stmt, ', ');
//write SQL
	$sql = " UPDATE ";
	$sql.= static::$table_name;
	$sql .= " SET ";
	$sql.= $field_stmt_f;
	$sql.= " WHERE " . static::$primary_column . "= :primary_id ";

	$stmt = $dbc->connection->prepare(" $sql ");
//Bind parameters
	foreach ($field_array as $key => $value) {
	 if (!empty($this->$value)) {
		$stmt->bindParam(":$value", $this->$value);
	 }
	}
	$time = time();
	$last_update_date = strftime("%d-%m-%y %H:%M:%S", $time);
	if (!empty($_SESSION['user_name'])) {
	 $last_update_by = $_SESSION['user_name'];
	} else {
	 $last_update_by = 'admin';
	}
	$stmt->bindParam(':last_update_by', $last_update_by);
	$stmt->bindParam(':last_update_date', $last_update_date);
	$stmt->bindParam(':primary_id', $id);
	try {
	 $stmt->execute();
	 $this->msg = 1;
	} catch (PDOException $e) {
	 $this->msg = 0;
	 echo "<div class='message'>failing for sql is $sql</div>";
	 echo "Record could not be updated !!: " . $e->getMessage();
	}
	return $this->msg;
 }

 public static function delete($id) {
	global $dbc;

	$sql = " DELETE FROM ";
	$sql .= static::$table_name;
	$sql .= " WHERE  ";
	$sql .= static::$primary_column . "= '{$id}' ";

//	echo '<div class="message"><br/>$sql is : '. $sql. '</div>';
	$prepare = $dbc->connection->prepare($sql);

	if ($prepare->execute()) {
	 return true;
	} else {
	 return false;
	}
 }

}

//end of content_type class

$dbObject = new dbObject();
$db = & $dbObject;
?>