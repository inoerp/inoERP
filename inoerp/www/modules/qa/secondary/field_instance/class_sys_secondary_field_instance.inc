<?php

class sys_secondary_field_inst extends dbObject {

 public static $table_name = "sys_secondary_field_inst";
 public static $primary_column = "sys_secondary_field_inst_id";
 public static $key_column = 'reference_key_name';
 public static $module = "sys"; //same as gl_journal_source
 
 public static $system_info = [
  'name' => 'Secondary Field Instance',
  'number' => '2906',
  'description' => 'Secondary Field Instance',
  'version' => '0.1.1',
  'db_version' => '1001',
  'mod_version' => '1.1.1',
  'primary_entity_cb' => '',
  'module_name' => 'qa',
  'weight' => 11
 ];
 
 public static $display_type_a = [
  'TEXT' => 'Text',
  'SELECT' => 'Select',
  'MULTI_SELECT' => 'Multi Select',
  'TEXT_AREA' => 'Text Area',
  'CHECK_BOX' => 'Check Box',
 ];
 public $field_a = [
  'sys_secondary_field_inst_id',
  'sys_secondary_field_id',
  'reference_type',
  'referece_entity',
  'reference_key_name',
  'reference_key_value',
  'label',
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
  'sys_secondary_field_inst_id',
  'sys_secondary_field_id',
  'label',
 ];
 public $checkbox = [
  "active_cb",
 ];
 public $serializedFields = [
  'list_values',
 ];
 public $requiredField = [
  'sys_secondary_field_id',
 ];
 public $fields_inForm_notInDataBase = [
  "field_name",
  'field_type'
 ];
 public $sys_secondary_field_inst_id;
 public $sys_secondary_field_id;
 public $reference_type;
 public $referece_entity;
 public $reference_key_name;
 public $reference_key_value;
 public $label;
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
 public $pageTitle = "Secondary Field Instance "; //page Title

 Public static function sys_secondary_field_inst_type() {
  $option_header = option_header::find_by_name('sys_secondary_field_inst_TYPE');
  $ol = option_line::find_by_option_id($option_header->option_header_id);
  return $ol;
 }

 public static function findFieldNames_by_referenceKey($ref_key) {
  $sql = " 
    SELECT sefi.sys_secondary_field_inst_id, sefi.sys_secondary_field_id,  sefi.reference_type, 
    sefi.referece_entity,  sefi.reference_key_name,  sefi.reference_key_value, sefi.label, 
    sefi.control_type, sefi.control_value,  sefi.control_uom,  sefi.active_cb, 
    sefi.display_weight,  sefi.list_values,  sefi.lower_limit,  sefi.upper_limit, 
    sefi.list_value_option_type,  sefi.created_by,  sefi.creation_date,  sefi.last_update_by, sefi.last_update_date, sef.field_name, sef.sys_field_name, sef.field_type ";

  $sql .= " FROM sys_secondary_field_inst sefi
    LEFT JOIN sys_secondary_field sef ON sef.sys_secondary_field_id = sefi.sys_secondary_field_id ";

  $sql .= " WHERE sefi.reference_key_name = '{$ref_key}' 

";
  $result = self::find_by_sql($sql);
  return !empty($result) ? $result : false;
 }

 public static function find_by_referenceKey($ref_key) {
  $sql = " 
    SELECT sefi.sys_secondary_field_inst_id, sefi.sys_secondary_field_id,  sefi.reference_type, 
    sefi.referece_entity,  sefi.reference_key_name,  sefi.reference_key_value, sefi.label, 
    sefi.control_type, sefi.control_value,  sefi.control_uom,  sefi.active_cb, 
    sefi.display_weight,  sefi.list_values,  sefi.lower_limit,  sefi.upper_limit, 
    sefi.list_value_option_type,  sefi.created_by,  sefi.creation_date,  sefi.last_update_by, sefi.last_update_date, sef.field_name, sef.sys_field_name, sef.field_type ";

  $sql .= " FROM sys_secondary_field_inst sefi
    LEFT JOIN sys_secondary_field sef ON sef.sys_secondary_field_id = sefi.sys_secondary_field_id ";

  $sql .= " WHERE sefi.reference_key_name = '{$ref_key}' 

";
  $result = self::find_by_sql($sql);
  return !empty($result) ? $result : false;
 }

 public static function find_by_fieldName_referenceDetails($secondary_field_name, $ref_key, $ref_value) {
  $ef_table = 'sf_' . $secondary_field_name;

  $sql = " SELECT * FROM ";
  $sql .= $ef_table;
  $sql .= " WHERE reference_key_name = '{$ref_key}' AND reference_key_value='{$ref_value}' ";
  $sql = ino_perPageSql_i($sql, 1);
  $result = self::find_by_sql($sql);
  return !empty($result) ? array_pop($result) : false;
 }

 public static function secondary_field_stmt($secondary_field_object, $class_id_value) {
  global $f;
  if ($secondary_field_object) {
   $class_name = $secondary_field_object[0]->reference_key_name;
   $secondary_field_stmt = "<ul class=\"secondary_field $class_name column free_column\">";
   foreach ($secondary_field_object as $ef) {
    if (empty($ef->field_name)) {
     continue;
    }
    $ef_table = 'sf_' . $ef->sys_field_name;
    $class_id_value = is_array($class_id_value) ? $class_id_value[0] : $class_id_value;
    $ef_all_value = self::find_by_fieldName_referenceDetails($ef->sys_field_name, $class_name, $class_id_value);

    if ($ef_all_value) {
     $ef_value_key = $ef_table . '_value';
     $ef_value = $ef_all_value->$ef_value_key;
    } else {
     $ef_value = null;
    }

    $lable = !empty($ef->label) ? $ef->label : ucwords(str_replace('_', ' ', $ef->sys_field_name));
    $secondary_field_stmt .= "<li><label>$lable </label>";
    switch ($ef->field_type) {
     case 'LIST':
      if (!empty($ef->list_values)) {
       $arr = unserialize($ef->list_values);
       $secondary_field_stmt .= $f->select_field_from_array($ef->sys_field_name, $arr, $ef_value);
      } else {
       $secondary_field_stmt .= $f->text_field($ef->sys_field_name, $ef_value);
      }
      break;

     case 'BOOLEAN' :
      $secondary_field_stmt .= $f->checkBox_field($ef->sys_field_name, $ef_value);
      break;

     case 'FILE' :
      $ef_file_name = $ef->sys_field_name . '_file';
      $file_details = extn_file::find_by_fieldName_referenceTable_and_id($ef->sys_field_name, $class_name, $class_id_value);
      $secondary_field_stmt .= ino_attachement($file_details, $ef_file_name);
      $secondary_field_stmt .= $f->hidden_field($ef->sys_field_name, $ef_value);
      break;

     case 'IMAGE' :
      $ef_file_name = $ef->sys_field_name . '_file';
//      $file_details = extn_file::find_by_fieldName_referenceTable_and_id($ef->sys_field_name, $class_name, $ef_value);
//       $secondary_field_stmt .= ino_attachement($file_details, $ef_file_name);
      $file_id = !empty($ef_value) ? $ef_value : '';
      $secondary_field_stmt .= $f->image_field($ef->sys_field_name, $file_id, '', '', 'img-small');
      $secondary_field_stmt .= $f->hidden_field($ef->sys_field_name, $ef_value);
      break;

     case 'OPTION_LIST' :
      if (!empty($ef->list_value_option_type)) {
       $secondary_field_stmt .= $f->select_field_from_object($ef->sys_field_name, option_line::find_by_parent_id($ef->list_value_option_type), 'option_line_code', 'option_line_value', $ef_value);
      } else {
       $secondary_field_stmt .= $f->text_field($ef->sys_field_name, $ef_value);
      }
      break;
     default :
      $secondary_field_stmt .= $f->text_field($ef->sys_field_name, $ef_value);
      break;
    }

    $secondary_field_stmt .= '</li>';
   }
   $secondary_field_stmt .='</ul>';
  }
  return $secondary_field_stmt;
 }

 public static function find_by_secondaryFieldId($sys_secondary_field_id) {
  $sql = " SELECT * FROM ";
  $sql .= self::$table_name;
  $sql .= " WHERE sys_secondary_field_id = '{$sys_secondary_field_id}' AND status='active'";
  $result = self::find_by_sql($sql);
  return !empty($result) ? $result : false;
 }

}

//end of sys_secondary_field_inst class
?>