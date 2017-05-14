<?php

 class sys_pflow_action_val extends dbObject {
 public static $system_info = [
  'name' => 'Process Flow Action Value',
  'number' => '9446',
  'description' => 'Process Flow Action Value',
  'version' => '0.1.1',
  'db_version' => '1001',
  'mod_version' => '1.1.1',
  'dependent_class' => array('sys_process_flow_line', 'sys_process_flow_action'),
  'primary_entity_cb' => '',
  'module_name' => 'sys',
  'weight' => 7
 ];
 
  public static $table_name = "sys_pflow_action_val";
  public static $primary_column = "sys_pflow_action_val_id";
  public static $parent_primary_column = "sys_process_flow_line_id";
  public static $key_column = "line_name";
  public static $module = "sys";
  public $field_a = [
   'sys_pflow_action_val_id',
   'sys_process_flow_action_id',
   'value',
   'comment',
   'action_user_id',
   'action_duration',
   'created_by',
   'creation_date',
   'last_update_by',
   'last_update_date',
  ];
  public $initial_search = [
   'sys_process_flow_action_id',
  ];
  public $requiredField = [
   'sys_process_flow_action_id',
   'value',
   'action_user_id',
  ];
  public $fields_inHeader_needsToBeInserted_inPOST = [
   "sys_process_flow_header_id"
  ];
  public $pageTitle = " Process Flow Line Value"; //page Title
  public $sys_pflow_action_val_id;
  public $sys_process_flow_action_id;
  public $value;
  public $comment;
  public $action_user_id;
  public $action_duration;
  public $created_by;
  public $creation_date;
  public $last_update_by;
  public $last_update_date;

 }

//end of path class
?>