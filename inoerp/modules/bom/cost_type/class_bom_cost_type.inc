<?php

class bom_cost_type extends dbObject {

 
 public static $table_name = "bom_cost_type";
 public static $key_column = 'cost_type';
 public static $primary_column = "bom_cost_type_id";
 public static $module = "bom";
 public static $system_info = [
  'name' => 'Cost Type',
  'number' => '2403',
  'description' => 'BOM Cost Types',
  'version' => '0.1.1',
  'db_version' => '1001',
  'mod_version' => '1.1.1',
  'primary_entity_cb' => '',
  'module_name' => 'bom',
  'weight' => 3
 ];
//  data base variables as stored database column name
 public $field_a = [
  'bom_cost_type_id',
  'cost_type_code',
  'cost_type',
  'description',
  'org_id',
  'status',
  'multi_org_cb',
  'default_cost_type',
  'ef_id',
  'created_by',
  'creation_date',
  'last_update_by',
  'last_update_date',
 ];
//variables used for showing data
 public $initial_search = [
  'bom_cost_type_id',
  'cost_type_code',
  'cost_type',
  'description',
  'org_id'
 ];
 public $column = [
  'bom_cost_type_id',
  'cost_type_code',
  'cost_type',
  'description',
  'org_id',
  'status',
  'multi_org_cb'
 ];
 public $checkbox = [
  'multi_org_cb',
 ];
 public $requiredField = [
  'cost_type',
  'cost_type_code',
  'description',
  'org_id',
  'multi_org_cb',
 ];
 public $search = [
  '_show_update_path' => 1,
  '_show_view_path' => 1,
 ];
 public $pageTitle = " Cost Type - Create & Update BOM Cost Types "; //page Title
 public $option_list = [
//		 'calendar_option_line_code' => 'GL_CALENDAR_NAME',
 ]; //list of search fields which have options
 public $bom_cost_type_id;
 public $cost_type_code;
 public $cost_type;
 public $description;
 public $org_id;
 public $status;
 public $multi_org_cb;
 public $default_cost_type;
 public $ef_id;
 public $created_by;
 public $creation_date;
 public $last_update_by;
 public $last_update_date;
 public $time;
 public $msg;

}

//end of resource class
?>