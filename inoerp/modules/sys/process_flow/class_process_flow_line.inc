<?php

class sys_process_flow_line extends dbObject {

 public static $table_name = "sys_process_flow_line";
 public static $primary_column = "sys_process_flow_line_id";
 public static $parent_primary_column = "sys_process_flow_header_id";
 public static $key_column = "line_name";
 public static $module = "sys";
 public static $line_type_a = [
		 'start' => 'Start',
		 'end' => 'End',
		 'activity' => 'Activity',
		 'decision' => 'Decision',
 ];
 public $field_a = [
		 'sys_process_flow_line_id',
		 'sys_process_flow_header_id',
		 'line_number',
		 'line_name',
		 'line_type',
		 'description',
		 'class_name',
		 'method_name',
		 'next_line_seq_pass',
		 'next_line_seq_fail',
		 'next_line_seq_onhold',
		 'created_by',
		 'creation_date',
		 'last_update_by',
		 'last_update_date',
 ];
 public $initial_search = [
		 'sys_process_flow_line_id',
		 'line_name',
 ];
 public $column = [
		 'sys_process_flow_line_id',
		 'sys_process_flow_header_id',
		 'line_name',
		 'description',
		 'class_name',
		 'method_name',
		 'next_line_id_pass',
		 'next_line_id_fail',
 ];
 public $requiredField = [
		 'sys_process_flow_header_id',
		 'line_name',
 ];
 public $fields_inHeader_needsToBeInserted_inPOST = [
		 "sys_process_flow_header_id"
 ];
 public static $query_order_by_field = 		 "line_number" ;
 public static $query_order_by_value = "ASC";
 public $pageTitle = " Process Flow Line "; //page Title
 public $sys_process_flow_line_id;
 public $sys_process_flow_header_id;
 public $line_number;
 public $line_name;
 public $line_type;
 public $description;
 public $class_name;
 public $method_name;
 public $next_line_seq_pass;
 public $next_line_seq_fail;
 public $next_line_seq_onhold;
 public $created_by;
 public $creation_date;
 public $last_update_by;
 public $last_update_date;

}

//end of path class
?>