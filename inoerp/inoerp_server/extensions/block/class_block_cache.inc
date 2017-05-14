<?php

class block_cache extends dbObject {

 public static $table_name = "block_cache";
// public static $primary_column = "block_cache_id";
 public static $key_column = "block_id";
 public static $module = "extension";
 //  data base variables as stored database column name
 public $field_a = [
		 "block_id",
		 "session_id",
		 "block_data"
 ];
//variables used for showing data

 public $checkbox = [
		 'content_php_cb'
 ];
 public $requiredField = [
		 "block_id",
		 "session_id",
 ];
 public $block_id;
 public $session_id;
 public $block_data;

 //dont delete below
 public static function find_by_block_id($id) {
	$sql = "SELECT * FROM " . self::$table_name . " where block_id='{$id}'  ";
  $sql = ino_perPageSql_i($sql, 1);
	$result_array = self::find_by_sql($sql);
	return !empty($result_array) ? array_shift($result_array) : false;
 }

 public function findBy_sessionId() {
	$sql = " SELECT * FROM ";
	$sql .= self::$table_name;
	$sql .= " WHERE session_id = :session_id ";
	$value_a = ['session_id' => $this->session_id];
	$result = $this->findBySql($sql, $value_a);
	return !empty($result) ? ($result) : false;
 }

 public function delete_allBy_sessionId() {
	global $dbc;
	$sql = " DELETE FROM ";
	$sql .= static::$table_name;
	$sql .= " WHERE  ";
	$sql .= "session_id = :session_id ";

	$stmt = $dbc->connection->prepare($sql);
	$stmt->bindParam(':session_id', $this->session_id);
	$stmt->execute();
 }

 public function findBy_blockId_sessionId() {
	$sql = " SELECT * FROM ";
	$sql .= self::$table_name;
	$sql .= " WHERE block_id = :block_id and session_id = :session_id ";
	$sql = ino_perPageSql_i($sql, 1);
	$value_a = ['block_id' => $this->block_id, 'session_id' => $this->session_id];
	$result = $this->findBySql($sql, $value_a);
	return !empty($result) ? array_pop($result) : false;
 }

}

//end of block class
?>