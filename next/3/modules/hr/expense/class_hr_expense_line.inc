<?php

class hr_expense_line extends dbObject {

 public static $table_name = "hr_expense_line";
 public static $primary_column = "hr_expense_line_id";
 public static $parent_primary_column = "hr_expense_header_id";
 public static $key_column = 'expense_type';
 public static $module = "hr";
 public static $status_a = [
  'ENTERED' => 'Entered',
  'VERIFIED' => 'Verified',
  'INVOICES' => 'Invoiced'
 ];
 public $field_a = [
  'hr_expense_line_id',
  'hr_expense_header_id',
  'line_number',
  'claim_date',
  'receipt_amount',
  'receipt_currency',
  'expense_type',
  'status',
  'purpose',
  'start_date',
  'daily_rate',
  'no_of_days',
  'expense_location',
  'vendor_name',
  'vendor_details',
  'original_receipt_missing_cb',
  'exchange_rate',
  'per_diem_rate',
  'per_diem_days',
  'mileage_uom_id',
  'mileage_distace',
  'mileage_rate',
  'cc_transaction_id',
  'cc_transaction_date',
  'cc_age',
  'cc_transaction_amount',
  'created_by',
  'creation_date',
  'last_update_by',
  'last_update_date',
 ];
 public $initial_search = [
  'hr_expense_header_id',
  'claim_date',
  'receipt_amount'
 ];
 public $requiredField = [
  'hr_expense_header_id',
  'claim_date',
  'receipt_amount',
//  'receipt_currency',
  'expense_type',
 ];
 public $fields_inForm_notInDataBase = [
 ];
 public $fields_inHeader_needsToBeInserted_inPOST = [
  "hr_expense_header_id"
 ];
 public $hr_expense_line_id;
 public $hr_expense_header_id;
 public $claim_date;
 public $receipt_amount;
 public $receipt_currency;
 public $expense_type;
 public $status;
 public $purpose;
 public $start_date;
 public $daily_rate;
 public $no_of_days;
 public $expense_location;
 public $vendor_name;
 public $vendor_details;
 public $original_receipt_missing_cb;
 public $exchange_rate;
 public $line_number;
 public $per_diem_rate;
 public $per_diem_days;
 public $mileage_uom_id;
 public $mileage_distace;
 public $mileage_rate;
 public $cc_transaction_id;
 public $cc_transaction_date;
 public $cc_age;
 public $cc_transaction_amount;
 public $created_by;
 public $creation_date;
 public $last_update_by;
 public $last_update_date;

 public function _before_save() {
  if (empty($this->hr_expense_line_id) && empty($this->status)) {
   $this->status = 'ENTERED';
  }
  
 }

 Public static function hr_expense_line_types() {
  $option_header = option_header::find_by_name('PO_LINE_TYPE');
  $po_types = option_line::find_by_option_id($option_header->option_header_id);
  return $po_types;
 }

}

//end of hr_expense_line class
?>