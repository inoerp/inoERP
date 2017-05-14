<?php

 class sys_extra_field_instance extends dbObject {

  public static $table_name = "sys_extra_field_instance";
  public static $primary_column = "sys_extra_field_instance_id";
  public static $key_column = 'sys_extra_field_id';
  public static $module = "sys"; //same as gl_journal_source
  public static $display_type_a = [
   'TEXT' => 'Text',
   'SELECT' => 'Select',
   'MULTI_SELECT' => 'Multi Select',
   'TEXT_AREA' => 'Text Area',
   'CHECK_BOX' => 'Check Box',
  ];
  public $field_a = [
   'sys_extra_field_instance_id',
   'sys_extra_field_id',
   'reference_type',
   'referece_entity',
   'reference_key_name',
   'reference_key_value',
   'field_label',
   'control_type',
   'control_value',
   'control_uom',
   'active_cb',
   'display_weight',
   'list_values',
   'lower_limit',
   'upper_limit',
   'list_value_option_type',
   'created_by',
   'creation_date',
   'last_update_by',
   'last_update_date',
  ];
  public $initial_search = [
   'sys_extra_field_instance_id',
   'sys_extra_field_id',
   'field_label',
  ];
  public $checkbox = [
   "active_cb",
  ];
  public $requiredField = [
   'sys_extra_field_id',
  ];
  public $fields_inForm_notInDataBase = [
   "field_name",
   'field_type'
  ];
  public $sys_extra_field_instance_id;
  public $sys_extra_field_id;
  public $reference_type;
  public $referece_entity;
  public $reference_key_name;
  public $reference_key_value;
  public $field_label;
  public $control_type;
  public $control_value;
  public $control_uom;
  public $active_cb;
  public $display_weight;
  public $list_values;
  public $lower_limit;
  public $upper_limit;
  public $list_value_option_type;
  public $created_by;
  public $creation_date;
  public $last_update_by;
  public $last_update_date;
  public $field_name;
  public $field_type;
  public $search = [
   '_show_update_path' => 1,
   '_show_view_path' => 1,
  ];
  public $pageTitle = " Extra Field Instance "; //page Title

  Public static function sys_extra_field_instance_type() {
   $option_header = option_header::find_by_name('SYS_extra_field_instance_TYPE');
   $ol = option_line::find_by_option_id($option_header->option_header_id);
   return $ol;
  }

  public static function find_by_referenceKeyValue($ref_key, $ref_value) {
   $sql = " 
    SELECT sefi.sys_extra_field_instance_id, sefi.sys_extra_field_id,  sefi.reference_type, 
    sefi.referece_entity,  sefi.reference_key_name,  sefi.reference_key_value, sefi.field_label, 
    sefi.control_type, sefi.control_value,  sefi.control_uom,  sefi.active_cb, 
    sefi.display_weight,  sefi.list_values,  sefi.lower_limit,  sefi.upper_limit, 
    sefi.list_value_option_type,  sefi.created_by,  sefi.creation_date,  sefi.last_update_by, sefi.last_update_date, sef.field_name, sef.sys_field_name, sef.field_type ";

   $sql .= " FROM sys_extra_field_instance sefi
    LEFT JOIN sys_extra_field sef ON sef.sys_extra_field_id = sefi.sys_extra_field_id ";

   $sql .= " WHERE sefi.reference_key_name = '{$ref_key}' 
    AND sefi.reference_key_value = '{$ref_value}' 

";
   $result = self::find_by_sql($sql);
   
   return !empty($result) ? $result : false;
  }

  public static function find_by_fieldName_referenceDetails($extra_field_name, $ref_key, $ref_value) {
   $ef_table = 'ef_' . $extra_field_name;

   $sql = " SELECT * FROM ";
   $sql .= $ef_table;
   $sql .= " WHERE reference_key_name = '{$ref_key}' AND reference_key_value='{$ref_value}' ";
   $sql = ino_perPageSql_i($sql, 1);
   $result = self::find_by_sql($sql);
   return !empty($result) ? array_pop($result) : false;
  }

  public static function find_by_extraFieldId($sys_extra_field_id) {
   $sql = " SELECT * FROM ";
   $sql .= self::$table_name;
   $sql .= " WHERE sys_extra_field_id = '{$sys_extra_field_id}' AND status='active'";
   $result = self::find_by_sql($sql);
   return !empty($result) ? $result : false;
  }

 }

//end of sys_extra_field_instance class
?>