<?php

 class hr_approval_object extends dbObject {

  public static $table_name = "hr_approval_object";
  public static $primary_column = "hr_approval_object_id";
  public static $key_column = 'object_code';
  public static $module = "hr";
  public static $value_type_a = [
   'STATIC' => 'Static List',
   'DYNAMIC' => 'Dynamic Data',
  ];
  public static $return_type_a = [
   'BOOLEAN' => 'Boolean',
   'DATE' => 'Date',
   'NUMBER' => 'Number',
   'CURRENCY' => 'Currency',
   'STRING' => 'String',
   'LIST' => 'List',
  ];
  public $field_a = [
   'hr_approval_object_id',
   'object_name',
   'object_code',
   'description',
   'value_type',
   'object_value',
   'return_type',
   'created_by',
   'creation_date',
   'last_update_by',
   'last_update_date',
  ];
  public $initial_search = [
   'hr_approval_object_id',
   'name',
   'description',
  ];
  public $requiredField = [
   'object_name',
   'value_type',
   'object_value',
  ];
  public $hr_approval_object_id;
  public $object_name;
  public $object_code;
  public $description;
  public $value_type;
  public $object_value;
  public $return_type;
  public $created_by;
  public $creation_date;
  public $last_update_by;
  public $last_update_date;
  public $search = [
   '_show_update_path' => 1,
   '_show_view_path' => 1,
  ];
  public $pageTitle = " HR Approval Objects  "; //page Title

  public static function find_by_code() {
   $sql = " SELECT * FROM ";
   $sql .= self::$table_name;
   $sql .= " WHERE level = 'HEADER' ";
   $result = self::find_by_sql($sql);
   return !empty($result) ? $result : false;
  }

//  public static function find_all_line_levels() {
//   $sql = " SELECT * FROM ";
//   $sql .= self::$table_name;
//   $sql .= " WHERE level = 'LINE' ";
//   $result = self::find_by_sql($sql);
//   return !empty($result) ? $result : false;
//  }

 }

//end of hr_approval_object class
?>