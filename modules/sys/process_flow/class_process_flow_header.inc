<?php

class sys_process_flow_header extends dbObject {

 public static $table_name = "sys_process_flow_header";
 public static $primary_column = "sys_process_flow_header_id";
 public static $dependent_classes = ['sys_process_flow_line'];
 public static $key_column = "line_name";
 public static $module = "sys";
 public $field_a = [
		 'sys_process_flow_header_id',
		 'process_flow',
		 'module',
		 'level',
		 'description',
		 'created_by',
		 'creation_date',
		 'last_update_by',
		 'last_update_date',
 ];
 public $initial_search = [
		 'sys_process_flow_header_id',
		 'process_flow',
		 'module'
 ];
 public $column = [
		 'sys_process_flow_header_id',
		 'process_flow',
		 'module',
		 'level',
		 'description'
 ];
 public $requiredField = [
		 'process_flow',
		 'module'
 ];
 public $search = [
		 '_show_update_path' => 1,
		 '_show_view_path' => 1,
 ];
 
 public $pageTitle = " Process Flow Header "; 
 public $sys_process_flow_header_id;
 public $process_flow;
 public $module;
 public $level;
 public $description;
 public $created_by;
 public $creation_date;
 public $last_update_by;
 public $last_update_date;

// function __construct() {
//	global $dbc;
//	$sql_fields = " SHOW COLUMNS FROM  " . self::$table_name;
//	$prepare = $dbc->connection->prepare($sql_fields);
//	$prepare->execute();
//	$this->field_a = $prepare->fetchAll(PDO::FETCH_COLUMN, 0);
// }

 public function __set($name, $value) {
	$this->$name = $value;
 }

 Public static function validation_types() {
	$header = option_header::find_by_keyColumn('SYS_VALIDATION_TYPE');
	$option_line = new option_line();
	$lines = $option_line->findBy_parentId($header->option_header_id);
	return $lines;
 }

}

//end of path class
?>
