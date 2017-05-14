<?php

class bc_label_format_header extends dbObject {

 public static $table_name = "bc_label_format_header";
 public static $primary_column = "bc_label_format_header_id";
 public static $dependent_classes = ['bc_label_format_line'];
 public static $key_column = 'format_name';
 public static $module = "bc";
 public static $system_info = [
  'name' => 'BC Auto-trigger',
  'number' => '9202',
  'description' => 'Barcode label format',
  'version' => '0.1.1',
  'db_version' => '1001',
  'mod_version' => '1.1.1',
  'dependent_class' => array('bc_label_format_line'),
  'primary_entity_cb' => '',
  'module_name' => 'bc',
  'weight' => 2
 ];
 public $field_a = [
  'bc_label_format_header_id',
  'label_type',
  'format_name',
  'disable_date',
  'default_cb',
  'description',
  'generator_class_name',
  'generator_function_name',
  'created_by',
  'creation_date',
  'last_update_by',
  'last_update_date',
 ];
 //variables used for showing data

 public $initial_search = [
  'format_name'
 ];
 public $requiredField = [
  'label_type',
  'format_name',
 ];
 public $pageTitle = " Barcode Label Format "; //page Title
 public $search = [
  '_show_update_path' => 1,
  '_show_view_path' => 1,
 ];
 public $bc_label_format_header_id;
 public $generator_function_name;
 public $generator_class_name;
 public $label_type;
 public $format_name;
 public $disable_date;
 public $default_cb;
 public $description;
 public $created_by;
 public $creation_date;
 public $last_update_by;
 public $last_update_date;

 public function _before_showing() {
  
 }

 Public static function label_type() {
  $option_header = option_header::find_by_name('BC_LABEL_TYPE');
  $ol = option_line::find_by_option_id($option_header->option_header_id);
  return $ol;
 }

 public static function find_by_employeeId($employee_id) {
  $sql = " SELECT * 
       FROM bc_label_format_header eeh 
       WHERE eeh.employee_id = '{$employee_id}'   
";
  switch (DB_TYPE) {
   case 'ORACLE' :
    $sql .= ' AND ' . ino_perPageSql(1);
    break;

   default:
    $sql .= ino_perPageSql(1);
    break;
  }
  $result = self::find_by_sql($sql);
  return !empty($result) ? array_pop($result) : false;
 }

}

//end of bom class
?>