<?php

class hr_element_entry_tpl_header extends dbObject {

 public static $table_name = "hr_element_entry_tpl_header";
 public static $primary_column = "hr_element_entry_tpl_header_id";
 public static $dependent_classes = ['hr_element_entry_tpl_line'];
 public static $key_column = 'template_name';
 public static $module = "hr";
 public $field_a = [
  'hr_element_entry_tpl_header_id',
  'template_name',
  'description',
  'created_by',
  'creation_date',
  'last_update_by',
  'last_update_date',
 ];
 //variables used for showing data

 public $initial_search = [
  'template_name',
 ];
 public $requiredField = [
  'template_name',
 ];
 public $pageTitle = " Cost Element Entry Template "; //page Title
 public $search = [
  '_show_update_path' => 1,
  '_show_view_path' => 1,
 ];
 public $hr_element_entry_tpl_header_id;
 public $template_name;
 public $description;
 public $created_by;
 public $creation_date;
 public $last_update_by;
 public $last_update_date;
 public $employee_name;
 public $identification_id;

 public function _before_showing() {
  
 }

 Public static function find_all_tpl_lines_by_category($hr_element_entry_tpl_header_id, $category = 'E_REGULAR') {
  if (empty($hr_element_entry_tpl_header_id)) {
   return null;
  }
  $sql = " SELECT * 
       FROM hr_element_entry_tpl_header eeh, 
       hr_element_entry_tpl_line eel,
       hr_compensation_element hce
       WHERE eel.hr_element_entry_tpl_header_id = eeh.hr_element_entry_tpl_header_id
       AND eeh.hr_element_entry_tpl_header_id = '{$hr_element_entry_tpl_header_id}'
        AND hce.hr_compensation_element_id = eel.element_id
        
";
  if (is_array($category)) {
   $sql .= " AND hce.category IN " . "( '" . implode("','", $category) . "' )";
  } else {
   $sql .= " AND hce.category = '{$category}' ";
  }
  $result = self::find_by_sql($sql);
  return !empty($result) ? $result : false;
 }

 Public static function find_all_regular_tpl_lines($hr_element_entry_tpl_header_id) {
  return self::find_all_tpl_lines_by_category($hr_element_entry_tpl_header_id, 'E_REGULAR');
 }

 Public static function find_all_basic_tpl_lines($hr_element_entry_tpl_header_id) {
  return self::find_all_tpl_lines_by_category($hr_element_entry_tpl_header_id, 'E_BASIC');
 }

 Public static function find_all_basic_regular_tpl_lines($hr_element_entry_tpl_header_id) {
  return self::find_all_tpl_lines_by_category($hr_element_entry_tpl_header_id, array('E_BASIC', 'E_REGULAR'));
 }

 public static function find_by_employeeId($employee_id) {
  $sql = " SELECT * 
       FROM hr_element_entry_tpl_header eeh 
       WHERE eeh.hr_employee_id = '{$employee_id}'   
";
  $sql = ino_perPageSql_i($sql, 1);
  $result = self::find_by_sql($sql);
  return !empty($result) ? array_pop($result) : false;
 }

}

//end of bom class
?>