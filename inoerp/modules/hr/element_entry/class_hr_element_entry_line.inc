<?php

class hr_element_entry_line extends dbObject {

 public static $table_name = "hr_element_entry_line";
 public static $primary_column = "hr_element_entry_line_id";
 public static $parent_primary_column = "hr_element_entry_header_id";
 public static $key_column = 'element_id';
 public static $module = "hr";
 public $field_a = [
  'hr_element_entry_line_id',
  'hr_element_entry_header_id',
  'element_id',
  'element_value',
  'end_date',
  'description',
  'created_by',
  'creation_date',
  'last_update_by',
  'last_update_date',
 ];
 public $fields_inHeader_needsToBeInserted_inPOST = [
  "hr_element_entry_header_id"
 ];
 public $requiredField = [
  'hr_element_entry_header_id',
  'element_id',
  'element_value',
 ];
 public $fields_inFormr_notinDataBase = [
  "monetary_value"
 ];
 public $hr_element_entry_header_id;
 public $hr_element_entry_line_id;
 public $element_id;
 public $element_value;
 public $end_date;
 public $description;
 public $created_by;
 public $creation_date;
 public $last_update_by;
 public $last_update_date;
 public $monetary_value;

 Public static function find_monetary_value_by_id($hr_element_entry_line_id, $element_id = '', $element_value = '') {
  if (empty($hr_element_entry_line_id)) {
   return null;
  }
  if (empty($element_id) || empty($element_value)) {
   $ele_entry_line = self::find_by_id($hr_element_entry_line_id);
   $element_id = $ele_entry_line->element_id;
   $element_value = $ele_entry_line->element_value;
  }
  $ele_details = hr_compensation_element::find_by_id($element_id);
  $amount = null;

  switch ($ele_details->calculation_rule) {
   case 'FLAT' :
    $amount = $element_value;
    break;

   case 'P_BASIC' :
    $total_amount = 0;
    $this_details = self::find_by_id($hr_element_entry_line_id);
    $all_basic_lines = hr_element_entry_header::find_all_basic_lines($this_details->hr_element_entry_header_id);
    foreach ($all_basic_lines as $lines) {
     $total_amount += $lines->element_value;
    }
    $amount = ($total_amount * $this_details->element_value) / 100;
    break;

   case 'P_REGULAR' :
    $total_amount = 0;
    $this_details = self::find_by_id($hr_element_entry_line_id);
    $all_basic_lines = hr_element_entry_header::find_all_regular_lines($this_details->hr_element_entry_header_id);
    foreach ($all_basic_lines as $lines) {
     $total_amount += $lines->element_value;
    }
    $amount = ($total_amount * $this_details->element_value) / 100;
    break;

   case 'P_BASIC_REGULAR' :
    $total_amount = 0;
    $this_details = self::find_by_id($hr_element_entry_line_id);
    $all_basic_lines = hr_element_entry_header::find_all_regular_lines($this_details->hr_element_entry_header_id);
    foreach ($all_basic_lines as $lines) {
     $total_amount += $lines->element_value;
    }
    $amount = ($total_amount * $this_details->element_value) / 100;
    break;

   case 'default' :
    break;
  }
  return $amount;
 }

 public static function find_by_parentId_elementId($headerId, $elementId) {
  $sql = " SELECT * 
       FROM hr_element_entry_line eel 
       WHERE eel.hr_element_entry_header_id = '{$headerId}'   
        AND eel.element_id = '{$elementId}'
";
 $sql = ino_perPageSql_i($sql, 1);
  $result = self::find_by_sql($sql);
  return !empty($result) ? array_pop($result) : false;
 }

}

//end of inv_transaction class
?>