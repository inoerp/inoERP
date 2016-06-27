<?php

class ar_transaction_line extends dbObject {

 public static $table_name = "ar_transaction_line";
 public static $primary_column = "ar_transaction_line_id";
 public static $parent_primary_column = "ar_transaction_header_id";
 public static $multi_search_primary_column = "ar_transaction_header_id"; //this value is used in multi search hidden value
 public static $key_column = 'item_description';
 public static $module = "ap";
 public $field_a = [
  'ar_transaction_line_id',
  'ar_transaction_header_id',
  'line_number',
  'item_id_m',
  'item_description',
  'inv_line_quantity',
  'inv_unit_price',
  'tax_code_id',
  'tax_amount',
  'gl_inv_line_price',
  'gl_tax_amount',
  'inv_line_price',
  'line_type',
  'line_description',
  'asset_cb',
  'fa_asset_category_id',
  'prj_project_header_id',
  'prj_project_line_id',
  'uom_id',
  'status',
  'line_source',
  'sd_so_header_id',
  'sd_so_line_id',
  'sd_so_detail_id',
  'period_id',
  'reference_type',
  'reference_key_name',
  'reference_key_value',
  'revenue_ac_id',
  'tax_ac_id',
  'created_by',
  'creation_date',
  'last_update_by',
  'last_update_date'
 ];
 public $requiredField = [
  'ar_transaction_header_id',
  'line_number',
  'item_description',
  'inv_line_quantity',
  'inv_unit_price',
  'inv_line_price',
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
  "ar_transaction_header_id"
 ];
 public $numberField = [
  'inv_line_quantity',
  'inv_unit_price',
  'inv_line_price',
  'tax_amount',
  'gl_tax_amount',
  'gl_inv_line_price',
 ];
 public $ar_transaction_line_id;
 public $ar_transaction_header_id;
 public $line_number;
 public $item_id_m;
 public $inv_line_quantity;
 public $inv_unit_price;
 public $inv_line_price;
 public $tax_code_id;
 public $tax_amount;
 public $gl_inv_line_price;
 public $gl_tax_amount;
 public $reference_type;
 public $reference_key_name;
 public $reference_key_value;
 public $line_type;
 public $line_description;
 public $asset_cb;
 public $fa_asset_category_id;
 public $prj_project_header_id;
 public $prj_project_line_id;
 public $status;
 public $line_source;
 public $sd_so_header_id;
 public $sd_so_line_id;
 public $sd_so_detail_id;
 public $period_id;
 public $revenue_ac_id;
 public $tax_ac_id;
 public $created_by;
 public $creation_date;
 public $last_update_by;
 public $last_update_date;
 public $customer_name;
 public $customer_number;
 public $item_number;
 public $item_description;
 public $uom_id;
 public $invoiced_quantity;
 public $action;
 public $transaction_type;
 public $so_order_number;
 public $so_line_number;

 public function _after_save() {
  if (!empty($this->ar_transaction_line_id)) {

   $trnx_details = new ar_transaction_detail();
   $trnx_details_i = $trnx_details->findBy_parentId($this->ar_transaction_line_id);
   //create transaction details
   if (!$trnx_details_i) {
    $trnx_type = ar_transaction_type::find_by_id($this->transaction_type);
    $detail_num = 1;
    $trnx_details->ar_transaction_header_id = $this->ar_transaction_header_id;
    $trnx_details->ar_transaction_line_id = $this->ar_transaction_line_id;
    $trnx_details->ar_transaction_detail_id = null;
    $trnx_details->detail_number = $detail_num;
    $detail_num++;
    $trnx_details->detail_ac_id = !empty($this->revenue_ac_id) ?  $this->revenue_ac_id : $trnx_type->revenue_ac_id;
    $trnx_details->account_type = ($this->line_type == 'GOODS' || 'SERVICES' ) ? 'ITEM' : $this->line_type;
    $trnx_details->description = 'Revenue';
    $trnx_details->amount = $this->inv_line_price;
    $trnx_details->gl_amount = $this->gl_inv_line_price;
    $trnx_details->save();
    echo "<br> Transaction detail line for revenue is Successfully created!";
    if (!empty($this->tax_amount)) {
     $trnx_details->ar_transaction_detail_id = null;
     $trnx_details->detail_number = $detail_num;
     $detail_num++;
     $trnx_details->detail_ac_id = !empty($this->tax_ac_id) ?  $this->tax_ac_id : $trnx_type->revenue_ac_id;
     $trnx_details->account_type = 'TAX';
     $trnx_details->description = 'Tax';
     $trnx_details->amount = $this->tax_amount;
     $trnx_details->gl_amount = $this->gl_tax_amount;
     $trnx_details->save();
     echo "<br> Transaction detail line for tax is Successfully Created!";
    }
   }
  }
 }

 public function _before_save() {
  if ((!empty($this->sd_so_header_id)) && ($this->ar_transaction_header_id)) {
   $current_highest_line_no = $this->_highest_line_number_from_header();
   $this->line_number = $current_highest_line_no->line_number + 1;
  }
  if (empty($this->line_type)) {
   $this->line_type = 'GOODS';
  }
 }

 private function _highest_line_number_from_header() {
  global $db;
  $sql = " SELECT max(line_number) as line_number FROM " . self::$table_name;
  $sql .= " WHERE ar_transaction_header_id= :ar_transaction_header_id ";
  $param_a = ['ar_transaction_header_id'];
  $value_a = ['ar_transaction_header_id' => $this->ar_transaction_header_id];
  $result = $db->findBy_sql($sql, $param_a, $value_a);
  return !empty($result) ? array_pop($result) : 0;
 }

 Public static function ar_transaction_line_types() {
  $option_header = option_header::find_by_name('PO_LINE_TYPE');
  $om_so_types = option_line::find_by_option_id($option_header->option_header_id);
  return $om_so_types;
 }

 Public static function find_sumAmounts($ar_transaction_header_id) {
  $sql = " SELECT SUM(inv_line_price) as total_line_amount, SUM(tax_amount) as total_tax_amount, ar_transaction_line_id
FROM ar_transaction_line
WHERE ar_transaction_header_id = '{$ar_transaction_header_id}'
GROUP BY ar_transaction_header_id ";

  $result = self::find_by_sql($sql);
  return !empty($result) ? array_pop($result) : null;
 }

 public static function find_by_ar_transaction_headerId($ar_transaction_header_id) {
  $sql = "SELECT * FROM " . self::$table_name . " where ar_transaction_header_id = '{$ar_transaction_header_id}'";
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
   'ar_transaction_header_id',
   'mode',
   'action',
   'om_so_status'
  ];

  return $multi_select_hidden;
 }

 public function copy($ar_transaction_line_id) {
  global $db;
  $sql1 = " CREATE TEMPORARY TABLE tmptable SELECT * FROM ar_transaction_line WHERE `ar_transaction_line_id` = '{$ar_transaction_line_id}' ";
  if ($db->query($sql1)) {
   $sql2 = "  UPDATE tmptable SET `ar_transaction_line_id` = '' ,
           `org_id` = '{$this->org_id}' 
          WHERE `ar_transaction_line_id` = '{$ar_transaction_line_id}' ";
   if ($db->query($sql2)) {
    $sql3 = " INSERT INTO `ar_transaction_line` SELECT * FROM tmptable WHERE `ar_transaction_line_id` = '' ";
    if ($db->query($sql3)) {
     $this->ar_transaction_line_id = $db->insert_id();
     $this->msg = 1;
    } else {
     $this->msg = 0;
    }
   }
  }
  return $this->msg;
 }

}

//end of ar_transaction_line class
?>