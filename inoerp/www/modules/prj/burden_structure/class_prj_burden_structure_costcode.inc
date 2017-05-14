<?php

class prj_burden_struct_costcode extends dbObject {

 public static $table_name = "prj_burden_struct_costcode";
 public static $primary_column = "prj_burden_struct_costcode_id";
 public static $parent_primary_column = "prj_burden_structure_header_id";
 public static $key_column = 'burden_cost_code_id';
 public static $module = "prj";
//  data base variables as stored database column name
 public $field_a = [
  'prj_burden_struct_costcode_id',
  'prj_burden_structure_header_id',
  'burden_cost_code_id',
  'description',
  'burden_cost_base_id',
  'priority',
  'created_by',
  'creation_date',
  'last_update_by',
  'last_update_date',
 ];
//variables used for showing data
 public $fields_inHeader_needsToBeInserted_inPOST = [
  'prj_burden_structure_header_id'
 ];
 public $requiredField = [
  'prj_burden_structure_header_id',
  'burden_cost_code_id',
  'burden_cost_base_id',
 ];
 public $prj_burden_struct_costcode_id;
 public $prj_burden_structure_header_id;
 public $burden_cost_code_id;
 public $description;
 public $burden_cost_base_id;
 public $priority;
 public $created_by;
 public $creation_date;
 public $last_update_by;
 public $last_update_date;

}

//end of prj_burden_struct_costcode class
?>