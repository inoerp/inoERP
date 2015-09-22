<?php

class hd_service_contract_line extends dbObject {

 public static $table_name = "hd_service_contract_line";
 public static $primary_column = "hd_service_contract_line_id";
 public static $parent_primary_column = "hd_service_contract_header_id";
 public static $multi_search_primary_column = "hd_service_contract_header_id"; //this value is used in multi search hidden value
 public static $key_column = 'item_id_m';
 public static $module = "hd";
 public static $line_type_a = [
  'WARENTY' => 'Warenty',
  'EXTND_WARENTY' => 'Extended Warenty',
  'USAGE' => 'Usage',
  'SERVICE' => 'Service',
  'SUBSCRIPTION' => 'Subscription',
 ];
 public $field_a = [
  'hd_service_contract_line_id',
  'hd_service_contract_header_id',
  'line_number',
  'item_id_m',
  'item_description',
  'line_type',
  'unit_price',
  'line_price',
  'tax_code_id',
  'tax_amount',
  'line_quantity',
  'gl_tax_amount',
  'start_date',
  'line_description',
  'end_date',
  'duration_uom_id',
  'duration',
  'renewal_type',
  'uom_id',
  'status',
  'line_source',
  'reference_type',
  'reference_key_name',
  'reference_key_value',
  'counter_instance_id',
  'event_id',
  'termination_date',
  'period_id',
  'created_by',
  'creation_date',
  'last_update_by',
  'last_update_date',
 ];
 public $requiredField = [
  'hd_service_contract_header_id',
  'line_number',
  'item_id_m',
  'line_type',
 ];
 public $fields_inForm_notInDataBase = [
  'transaction_type',
  "transaction_number",
  "item_number",
  'customer_name',
  'customer_number',
  'item_description',
  'invoiced_quantity',
  'action',
  'so_order_number',
  'so_line_number',
 ];
 public $fields_inHeader_needsToBeInserted_inPOST = [
  "hd_service_contract_header_id"
 ];
 public $hd_service_contract_line_id;
 public $hd_service_contract_header_id;
 public $line_number;
 public $item_id_m;
 public $item_description;
 public $line_type;
 public $unit_price;
 public $line_price;
 public $tax_code_id;
 public $tax_amount;
 public $line_quantity;
 public $gl_tax_amount;
 public $start_date;
 public $line_description;
 public $end_date;
 public $duration_uom_id;
 public $duration;
 public $renewal_type;
 public $uom_id;
 public $status;
 public $line_source;
 public $reference_type;
 public $reference_key_name;
 public $reference_key_value;
 public $counter_instance_id;
 public $event_id;
 public $termination_date;
 public $period_id;
 public $created_by;
 public $creation_date;
 public $last_update_by;
 public $last_update_date;
 public $customer_name;
 public $customer_number;
 public $item_number;
 public $invoiced_quantity;
 public $action;
 public $transaction_type;
 public $so_order_number;
 public $so_line_number;

// public function _after_save() {
//  if (!empty($this->hd_service_contract_line_id)) {
//
//   $trnx_details = new hd_service_detail();
//   $trnx_details_i = $trnx_details->findBy_parentId($this->hd_service_contract_line_id);
//   //create transaction details
//   if (!$trnx_details_i) {
//    $trnx_type = hd_service_type::find_by_id($this->transaction_type);
//    $detail_num = 1;
//    $trnx_details->hd_service_contract_header_id = $this->hd_service_contract_header_id;
//    $trnx_details->hd_service_contract_line_id = $this->hd_service_contract_line_id;
//    $trnx_details->hd_service_detail_id = null;
//    $trnx_details->detail_number = $detail_num;
//    $detail_num++;
//    $trnx_details->detail_ac_id = $trnx_type->revenue_ac_id;
//    $trnx_details->account_type = ($this->line_type == 'GOODS' || 'SERVICES' ) ? 'ITEM' : $this->line_type;
//    $trnx_details->description = 'Revenue';
//    $trnx_details->amount = $this->inv_line_price;
//    $trnx_details->gl_amount = $this->gl_inv_line_price;
//    $trnx_details->audit_trial();
//    $trnx_details->save();
//    echo "<br> Transaction detail line for revenue is Successfully Created!";
//    if (!empty($this->tax_amount)) {
//     $trnx_details->hd_service_detail_id = null;
//     $trnx_details->detail_number = $detail_num;
//     $detail_num++;
//     $trnx_details->detail_ac_id = $trnx_type->tax_ac_id;
//     $trnx_details->account_type = 'TAX';
//     $trnx_details->description = 'Tax';
//     $trnx_details->amount = $this->tax_amount;
//     $trnx_details->gl_amount = $this->gl_tax_amount;
//     $trnx_details->audit_trial();
//     $trnx_details->save();
//     echo "<br> Transaction detail line for tax is Successfully Created!";
//    }
//   }
//  }
// }
//
// public function _before_save() {
//  if ((!empty($this->sd_so_header_id)) && ($this->hd_service_contract_header_id)) {
//   $current_highest_line_no = $this->_highest_line_number_from_header();
//   $this->line_number = $current_highest_line_no->line_number + 1;
//  }
//  if (empty($this->line_type)) {
//   $this->line_type = 'GOODS';
//  }
// }
//
// private function _highest_line_number_from_header() {
//  global $db;
//  $sql = " SELECT max(line_number) as line_number FROM " . self::$table_name;
//  $sql .= " WHERE hd_service_contract_header_id= :hd_service_contract_header_id ";
//  $param_a = ['hd_service_contract_header_id'];
//  $value_a = ['hd_service_contract_header_id' => $this->hd_service_contract_header_id];
//  $result = $db->findBy_sql($sql, $param_a, $value_a);
//  return !empty($result) ? array_pop($result) : 0;
// }

 Public static function hd_service_contract_line_types() {
  $option_header = option_header::find_by_name('PO_LINE_TYPE');
  $om_so_types = option_line::find_by_option_id($option_header->option_header_id);
  return $om_so_types;
 }

 public static function find_by_hd_service_contract_headerId($hd_service_contract_header_id) {
  $sql = "SELECT * FROM " . self::$table_name . " where hd_service_contract_header_id = '{$hd_service_contract_header_id}'";
  $result_array = self::find_by_sql($sql);
  return $result_array;
 }

 public function multi_select_input_fields() {
  $multi_select_input = [
   'inv_line_quantity',
   'inv_unit_price',
   'inv_line_price',
   'inv_line_type'
  ];
  return $multi_select_input;
 }

 public function multi_select_hidden_fields() {
  $multi_select_hidden = [
   'action_class_name',
   'customer_id',
   'sd_so_header_id',
   'hd_service_contract_header_id',
   'mode',
   'action',
   'om_so_status'
  ];

  return $multi_select_hidden;
 }

}

//end of hd_service_contract_line class
?>