<?php

class ent_sys_webpage_line extends dbObject {

 public static $table_name = "ent_sys_webpage_line";
 public static $primary_column = "ent_sys_webpage_line_id";
 public static $parent_primary_column = "ent_sys_webpage_header_id";
 public static $key_column = 'billing_type';
 public static $module = "sys";
 public $field_a = [
		 'ent_sys_webpage_line_id',
		 'ent_sys_webpage_header_id',
		 'report_label',
		 'user_role',
		 'user_id',
		 'report_group',
		 'report_type',
		 'report_id',
		 'priority',
		 'created_by',
		 'creation_date',
		 'last_update_by',
		 'last_update_date',
 ];
 public $requiredField = [
		 'ent_sys_webpage_header_id',
		 'billing_type',
		 'service_activity_id',
 ];
 public $fields_inHeader_needsToBeInserted_inPOST = [
		 "ent_sys_webpage_header_id"
 ];
 
 public $ent_sys_webpage_line_id;
 public $ent_sys_webpage_header_id;
 public $report_label;
 public $user_role;
 public $user_id;
 public $report_group;
 public $report_type;
 public $report_id;
 public $priority;
 public $created_by;
 public $creation_date;
 public $last_update_by;
 public $last_update_date;

}

//end of ent_sys_webpage_line class
?>