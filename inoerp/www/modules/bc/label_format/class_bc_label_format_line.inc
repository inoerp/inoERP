<?php

class bc_label_format_line extends dbObject {

 public static $table_name = "bc_label_format_line";
 public static $primary_column = "bc_label_format_line_id";
 public static $parent_primary_column = "bc_label_format_header_id";
 public static $key_column = 'field_name';
 public static $module = "bc";
 public static $value_type_a = [
  'TEXT' => 'Text',
  'SELECT' => 'Select',
  'MULTI_SELECT' => 'Multi Select',
  'TEXT_AREA' => 'Text Area',
  'CHECK_BOX' => 'Check Box',
 ];
 public $field_a = [
  'bc_label_format_line_id',
  'bc_label_format_header_id',
  'sys_field_name',
  'object_name',
  'field_name',
  'description',
  'created_by',
  'creation_date',
  'last_update_by',
  'last_update_date',
 ];
 public $fields_inHeader_needsToBeInserted_inPOST = [
  "bc_label_format_header_id"
 ];
 public $serializedFields = [
 ];
 public $requiredField = [
  'bc_label_format_header_id',
  'sys_field_name',
  'field_name'
 ];
 public $fields_inForm_notInDataBase = [
 ];
 public $bc_label_format_line_id;
 public $bc_label_format_header_id;
 public $sys_field_name;
 public $object_name;
 public $field_name;
 public $description;
 public $created_by;
 public $creation_date;
 public $last_update_by;
 public $last_update_date;


 Public static function find_monetary_value_by_id($bc_label_format_line_id, $element_id = '', $element_value = '') {
  if (empty($bc_label_format_line_id)) {
   return null;
  }
  if (empty($element_id) || empty($element_value)) {
   $ele_entry_line = self::find_by_id($bc_label_format_line_id);
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
    $this_details = self::find_by_id($bc_label_format_line_id);
    $all_basic_lines = bc_label_format_header::find_all_basic_lines($this_details->bc_label_format_header_id);
    foreach ($all_basic_lines as $lines) {
     $total_amount += $lines->element_value;
    }
    $amount = ($total_amount * $this_details->element_value) / 100;
    break;

   case 'P_REGULAR' :
    $total_amount = 0;
    $this_details = self::find_by_id($bc_label_format_line_id);
    $all_basic_lines = bc_label_format_header::find_all_regular_lines($this_details->bc_label_format_header_id);
    foreach ($all_basic_lines as $lines) {
     $total_amount += $lines->element_value;
    }
    $amount = ($total_amount * $this_details->element_value) / 100;
    break;

   case 'P_BASIC_REGULAR' :
    $total_amount = 0;
    $this_details = self::find_by_id($bc_label_format_line_id);
    $all_basic_lines = bc_label_format_header::find_all_regular_lines($this_details->bc_label_format_header_id);
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

}

//end of inv_transaction class
?>