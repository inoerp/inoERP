<?php

class sys_process_flow_header extends dbObject {

 public static $table_name = "sys_process_flow_header";
 public static $primary_column = "sys_process_flow_header_id";
 public static $dependent_classes = ['sys_process_flow_line'];
 public static $key_column = "process_flow";
 public static $module = "sys";
 public static $type_a = [
		 'APPROVAL' => 'Approval',
		 'DOCUMENT' => 'Document'
 ];
 public $field_a = [
		 'sys_process_flow_header_id',
		 'process_flow',
		 'module_name',
		 'status',
		 'type',
		 'description',
		 'created_by',
		 'creation_date',
		 'last_update_by',
		 'last_update_date',
 ];
 public $initial_search = [
		 'sys_process_flow_header_id',
		 'process_flow',
		 'module_name'
 ];
 public $column = [
		 'sys_process_flow_header_id',
		 'process_flow',
		 'module_name',
		 'level',
		 'description'
 ];
 public $requiredField = [
		 'process_flow',
		 'module_name'
 ];
 public $search = [
		 '_show_update_path' => 1,
		 '_show_view_path' => 1,
 ];
 
 public $pageTitle = " Process Flow Header "; 
 public $sys_process_flow_header_id;
 public $process_flow;
 public $type;
 public $module_name;
 public $status;
 public $description;
 public $created_by;
 public $creation_date;
 public $last_update_by;
 public $last_update_date;


 Public static function validation_types() {
	$header = option_header::find_by_keyColumn('SYS_VALIDATION_TYPE');
	$option_line = new option_line();
	$lines = $option_line->findBy_parentId($header->option_header_id);
	return $lines;
 }

}

//end of path class
?>