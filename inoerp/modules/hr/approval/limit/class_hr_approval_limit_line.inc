<?php

 class hr_approval_limit_line extends dbObject {

  public static $table_name = "hr_approval_limit_line";
  public static $primary_column = "hr_approval_limit_line_id";
  public static $parent_primary_column = "hr_approval_limit_header_id";
  public static $key_column = 'limit_object';
  public static $module = "hr";
  public static $limit_type_a = [
   'INCLUDE' => 'Include',
   'EXCLUDE' => 'Exclude'
  ];
  public $field_a = [
   'hr_approval_limit_line_id',
   'hr_approval_limit_header_id',
   'limit_object',
   'limit_type',
   'limit_range_low',
   'limit_range_high',
   'amount_limit',
   'inactive_date',
   'created_by',
   'creation_date',
   'last_update_by',
   'last_update_date',
  ];
  public $fields_inHeader_needsToBeInserted_inPOST = [
   "hr_approval_limit_header_id"
  ];
  public $requiredField = [
   'hr_approval_limit_header_id',
   'limit_object',
   'limit_type',
   'amount_limit',
  ];
  public $fields_inFormr_notinDataBase = [
   "monetary_value"
  ];
  public $hr_approval_limit_line_id;
  public $hr_approval_limit_header_id;
  public $limit_object;
  public $limit_type;
  public $limit_range_low;
  public $limit_range_high;
  public $amount_limit;
  public $inactive_date;
  public $created_by;
  public $creation_date;
  public $last_update_by;
  public $last_update_date;
  public $monetary_value;

  Public static function find_monetary_value_by_id($hr_approval_limit_line_id, $element_id = '', $element_value = '') {
   if (empty($hr_approval_limit_line_id)) {
    return null;
   }
   if (empty($element_id) || empty($element_value)) {
    $ele_entry_line = self::find_by_id($hr_approval_limit_line_id);
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
     $this_details = self::find_by_id($hr_approval_limit_line_id);
     $all_basic_lines = hr_approval_limit_header::find_all_basic_lines($this_details->hr_approval_limit_header_id);
     foreach ($all_basic_lines as $lines) {
      $total_amount += $lines->element_value;
     }
     $amount = ($total_amount * $this_details->element_value) / 100;
     break;

    case 'P_REGULAR' :
     $total_amount = 0;
     $this_details = self::find_by_id($hr_approval_limit_line_id);
     $all_basic_lines = hr_approval_limit_header::find_all_regular_lines($this_details->hr_approval_limit_header_id);
     foreach ($all_basic_lines as $lines) {
      $total_amount += $lines->element_value;
     }
     $amount = ($total_amount * $this_details->element_value) / 100;
     break;

    case 'P_BASIC_REGULAR' :
     $total_amount = 0;
     $this_details = self::find_by_id($hr_approval_limit_line_id);
     $all_basic_lines = hr_approval_limit_header::find_all_regular_lines($this_details->hr_approval_limit_header_id);
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