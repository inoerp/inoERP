<?php

 class cc_co_template_line extends dbObject {

  public static $table_name = "cc_co_template_line";
  public static $primary_column = "cc_co_template_line_id";
  public static $parent_primary_column = "cc_co_template_header_id";
  public static $key_column = 'field_name';
  public static $module = "cc";
  public static $value_type_a = [
   'TEXT' => 'Text',
   'SELECT' => 'Select',
   'MULTI_SELECT' => 'Multi Select',
   'TEXT_AREA' => 'Text Area',
   'CHECK_BOX' => 'Check Box',
  ];
  public $field_a = [
   'cc_co_template_line_id',
   'cc_co_template_header_id',
   'field_name',
   'required_cb',
   'label',
   'value_type',
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
  public $fields_inHeader_needsToBeInserted_inPOST = [
   "cc_co_template_header_id"
  ];
  public $serializedFields = [
   'list_values',
  ];
  public $requiredField = [
   'cc_co_template_header_id',
   'field_name',
  ];
  public $fields_inForm_notInDataBase = [
   "item_number",
  ];
  public $cc_co_template_line_id;
  public $cc_co_template_header_id;
  public $field_name;
  public $required_cb;
  public $label;
  public $value_type;
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
  public $item_number;

  Public static function find_monetary_value_by_id($cc_co_template_line_id, $element_id = '', $element_value = '') {
   if (empty($cc_co_template_line_id)) {
    return null;
   }
   if (empty($element_id) || empty($element_value)) {
    $ele_entry_line = self::find_by_id($cc_co_template_line_id);
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
     $this_details = self::find_by_id($cc_co_template_line_id);
     $all_basic_lines = cc_co_template_header::find_all_basic_lines($this_details->cc_co_template_header_id);
     foreach ($all_basic_lines as $lines) {
      $total_amount += $lines->element_value;
     }
     $amount = ($total_amount * $this_details->element_value) / 100;
     break;

    case 'P_REGULAR' :
     $total_amount = 0;
     $this_details = self::find_by_id($cc_co_template_line_id);
     $all_basic_lines = cc_co_template_header::find_all_regular_lines($this_details->cc_co_template_header_id);
     foreach ($all_basic_lines as $lines) {
      $total_amount += $lines->element_value;
     }
     $amount = ($total_amount * $this_details->element_value) / 100;
     break;

    case 'P_BASIC_REGULAR' :
     $total_amount = 0;
     $this_details = self::find_by_id($cc_co_template_line_id);
     $all_basic_lines = cc_co_template_header::find_all_regular_lines($this_details->cc_co_template_header_id);
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