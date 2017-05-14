<?php

class sys_value_group_line extends dbObject {

 public static $table_name = "sys_value_group_line";
 public static $primary_column = "sys_value_group_line_id";
 public static $parent_primary_column = "sys_value_group_header_id";
 public static $key_column = "code";
 public static $module = "sys";
 public static $query_order_by_field = 'code_value';
 public $field_a = [
		 'sys_value_group_line_id',
		 'sys_value_group_header_id',
		 'code_value',
		 'code',
		 'description',
		 'account_qualifier',
		 'status',
		 'parent_cb',
		 'parent_line_id',
		 'effective_start_date',
		 'effective_end_date',
		 'created_by',
		 'creation_date',
		 'last_update_by',
		 'last_update_date'
 ];
 public $checkbox = [
		 "parent_cb",
 ];
 public $initial_search = [
		 'sys_value_group_line_id',
		 'sys_value_group_header_id',
		 'code_value',
		 'code',
		 'description',
		 'account_qualifier'
 ];
 public $column = [
		 'sys_value_group_line_id',
		 'sys_value_group_header_id',
		 'code_value',
		 'code',
		 'description',
		 'account_qualifier'
 ];
 public $requiredField = [
		 'sys_value_group_header_id',
		 'code_value',
		 'code',
 ];
 public $fields_inHeader_needsToBeInserted_inPOST = [
		 "sys_value_group_header_id"
 ];
 
   public $number_fields = [
  "sys_value_group_header_id",
    'sys_value_group_line_id'
 ];
   
 public $pageTitle = " Value Group - Find All Calue Group Lines "; //page Title
 public $sys_value_group_line_id;
 public $sys_value_group_header_id;
 public $code_value;
 public $code;
 public $description;
 public $account_qualifier;
 public $allow_budgeting_cb;
 public $allow_posting_cb;
 public $status;
 public $parent_cb;
 public $parent_line_id;
 public $effective_start_date;
 public $effective_end_date;
 public $created_by;
 public $creation_date;
 public $last_update_by;
 public $last_update_date;
 public $msg;

//function __construct() {
//	global $dbc;
//	$sql_fields = " SHOW COLUMNS FROM  " . self::$table_name;
//	$prepare = $dbc->connection->prepare($sql_fields);
//	$prepare->execute();
//	self::$field_array = $prepare->fetchAll(PDO::FETCH_COLUMN, 0);
// }

 public function __set($name, $value) {
	$this->$name = $value;
 }

 public static function find_all_lines() {
	$sql = " SELECT * FROM " . self::$table_name;
	$result = self::find_by_sql($sql);
	return $result;
 }

 public static function find_by_header_id($id) {
	$vgl = new sys_value_group_line();
	return $vgl->findBy_parentId($id,'code','ASC');
 }

 public static function find_by_optionId_lineCode($header_id, $code) {
	$sql = "SELECT * FROM " . self::$table_name .
					" where code={$code} AND sys_value_group_header_id={$header_id} ";
          $sql = ino_perPageSql_i($sql, 1);
	$result = self::find_by_sql($sql);
	return !empty($result) ? array_push($result) : $result;
 }

}

//end of path class
?>