<?php

class sys_process_flow_action extends dbObject {

 public static $table_name = "sys_process_flow_action";
 public static $primary_column = "sys_process_flow_action_id";
 public static $parent_primary_column = "sys_process_flow_line_id";
 public static $key_column = "pf_action_type";
 public static $module = "sys";
 public static $pf_action_type_a = [
  'APPROVAL' => 'Approval',
  'INFORMATION' => 'Information',
 ];
 public $field_a = [
  'sys_process_flow_action_id',
  'sys_process_flow_line_id',
  'action_number',
  'role_code',
  'user_id',
  'pf_action_type',
  'required_cb',
  'object_name',
  'object_primary_id',
  'created_by',
  'creation_date',
  'last_update_by',
  'last_update_date',
 ];
 public $initial_search = [
  'sys_process_flow_line_id',
 ];
 public $requiredField = [
  'sys_process_flow_line_id',
  'pf_action_type',
 ];
 public $fields_inHeader_needsToBeInserted_inPOST = [
  "sys_process_flow_header_id"
 ];
 public $fields_inForm_notInDataBase = [
  "username",
 ];
 public $pageTitle = " Process Flow Action "; //page Title
 public $sys_process_flow_action_id;
 public $sys_process_flow_line_id;
 public $action_number;
 public $role_code;
 public $pf_action_type;
 public $user_id;
 public $required_cb;
 public $created_by;
 public $creation_date;
 public $last_update_by;
 public $last_update_date;
 public $username;
  public $object_name;
 public $object_primary_id;

}

//end of path class
?>