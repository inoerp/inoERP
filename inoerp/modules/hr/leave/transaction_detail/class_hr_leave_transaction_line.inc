<?php

 class hr_leave_transaction_line extends dbObject {

  public static $table_name = "hr_leave_transaction_line";
  public static $primary_column = "hr_leave_transaction_line_id";
  public static $parent_primary_column = "hr_leave_transaction_header_id";
  public static $key_column = 'leave_type';
  public static $module = "hr";
  public static $transaction_type_a = [
   'ADDITION' => 'Addition',
   'ADDITION' => 'Addition'
  ];
  public $field_a = [
   'hr_leave_transaction_header_id',
   'leave_type',
   'transaction_type',
   'leave_quantity',
   'from_date',
   'to_date',
   'reason',
   'contact_details',
   'created_by',
   'creation_date',
   'last_update_by',
   'last_update_date',
  ];
  public $fields_inHeader_needsToBeInserted_inPOST = [
   "hr_leave_transaction_header_id"
  ];
  public $requiredField = [
   'leave_type',
   'transaction_type',
   'leave_quantity',
   'from_date'
  ];
  public $fields_inForm_notinDataBase = [
   "monetary_value"
  ];
  public $hr_leave_transaction_line_id;
  public $hr_leave_transaction_header_id;
  public $leave_type;
  public $transaction_type;
  public $leave_quantity;
  public $from_date;
  public $to_date;
  public $reason;
  public $contact_details;
  public $created_by;
  public $creation_date;
  public $last_update_by;
  public $last_update_date;

  Public static function find_monetary_value_by_id($hr_leave_transaction_line_id, $element_id = '', $element_value = '') {
   if (empty($hr_leave_transaction_line_id)) {
    return null;
   }
   if (empty($element_id) || empty($element_value)) {
    $ele_entry_line = self::find_by_id($hr_leave_transaction_line_id);
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
     $this_details = self::find_by_id($hr_leave_transaction_line_id);
     $all_basic_lines = hr_leave_transaction_header::find_all_basic_lines($this_details->hr_leave_transaction_header_id);
     foreach ($all_basic_lines as $lines) {
      $total_amount += $lines->element_value;
     }
     $amount = ($total_amount * $this_details->element_value) / 100;
     break;

    case 'P_REGULAR' :
     $total_amount = 0;
     $this_details = self::find_by_id($hr_leave_transaction_line_id);
     $all_basic_lines = hr_leave_transaction_header::find_all_regular_lines($this_details->hr_leave_transaction_header_id);
     foreach ($all_basic_lines as $lines) {
      $total_amount += $lines->element_value;
     }
     $amount = ($total_amount * $this_details->element_value) / 100;
     break;

    case 'P_BASIC_REGULAR' :
     $total_amount = 0;
     $this_details = self::find_by_id($hr_leave_transaction_line_id);
     $all_basic_lines = hr_leave_transaction_header::find_all_regular_lines($this_details->hr_leave_transaction_header_id);
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