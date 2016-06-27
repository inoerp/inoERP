<?php

class ap_transaction_line extends dbObject {

 public static $table_name = "ap_transaction_line";
 public static $primary_column = "ap_transaction_line_id";
 public static $parent_primary_column = "ap_transaction_header_id";
 public static $multi_search_primary_column = "ap_transaction_header_id"; //this value is used in multi search hidden value
 public static $key_column = 'item_description';
 public static $module = "ap";
 public $field_a = [
  'ap_transaction_line_id',
  'ap_transaction_header_id',
  'line_number',
  'item_id_m',
  'item_description',
  'inv_line_quantity',
  'inv_unit_price',
  'inv_line_price',
  'tax_code_id',
  'tax_amount',
  'gl_tax_amount',
  'gl_inv_line_price',
  'line_type',
  'line_description',
  'asset_cb',
  'fa_asset_category_id',
  'prj_project_header_id',
  'prj_project_line_id',
  'uom_id',
  'status',
  'line_source',
  'po_header_id',
  'po_line_id',
  'po_detail_id',
  'ref_transaction_header_id',
  'ref_transaction_line_id',
  'period_id',
  'reference_type',
  'reference_key_name',
  'reference_key_value',
  'created_by',
  'creation_date',
  'last_update_by',
  'last_update_date'
 ];
 public $requiredField = [
  'ap_transaction_header_id',
  'line_number',
  'item_description',
  'inv_line_quantity',
  'inv_unit_price',
  'inv_line_price',
 ];
 public $fields_inForm_notInDataBase = [
  "transaction_number",
  "item_number",
  'supplier_name',
  'supplier_number',
  'item_description',
  'uom_id',
  'action',
  'tax_code_value',
  'line_quantity',
  'unit_price',
  'gl_line_price',
  'line_price',
  'invoiced_quantity',
  'invoicing_open_quantity',
  'cm_transaction_header_id',
  'credit_line_quantity',
  'credit_unit_price',
  'detail_ac_id',
  'inv_doc_currency',
  'doc_currency'
 ];
 public $fields_inHeader_needsToBeInserted_inPOST = [
  "ap_transaction_header_id"
 ];
 public $numberField = [
  'inv_line_quantity',
  'inv_unit_price',
  'inv_line_price',
  'tax_amount',
  'gl_tax_amount',
  'gl_inv_line_price',
 ];
 public $ap_transaction_line_id;
 public $ap_transaction_header_id;
 public $line_number;
 public $item_id_m;
 public $inv_line_quantity;
 public $inv_unit_price;
 public $inv_line_price;
 public $reference_type;
 public $reference_key_name;
 public $reference_key_value;
 public $line_type;
 public $line_description;
 public $tax_code_id;
 public $tax_amount;
 public $gl_tax_amount;
 public $gl_inv_line_price;
 public $asset_cb;
 public $fa_asset_category_id;
 public $prj_project_header_id;
 public $prj_project_line_id;
 public $uom;
 public $ef_id;
 public $status;
 public $line_source;
 public $po_header_id;
 public $po_line_id;
 public $po_detail_id;
 public $ref_transaction_header_id;
 public $ref_transaction_line_id;
 public $period_id;
 public $created_by;
 public $creation_date;
 public $last_update_by;
 public $last_update_date;
 public $supplier_name;
 public $supplier_number;
 public $item_number;
 public $item_description;
 public $uom_id;
 public $action;
 public $tax_code_value;
 public $line_quantity;
 public $unit_price;
 public $invoiced_quantity;
 public $invoicing_open_quantity;
 public $cm_transaction_header_id;
 public $credit_line_quantity;
 public $credit_unit_price;
 public $detail_ac_id;
 public $gl_line_price;
 public $line_price;
 public $doc_currency;
 public $inv_doc_currency;

 private function _validate_delete() {
  if (!empty($this->po_detail_id) || ($this->ap_transaction_header_id)) {
   echo "<br>Delete is not allowed for this line as references (po_detail_id /ap_transaction_header_id ) exists ";
   return -99;
  } else {
   return 1;
  }
 }

 public function _before_delete() {
  return $this->_validate_delete();
 }

 private function _validate_tax_detail_line() {
  $tax_detail_detail = new ap_transaction_detail();
  $tax_detail_detail->ap_transaction_line_id = $this->ap_transaction_line_id;
  $tax_detail_detail_i = $tax_detail_detail->findTaxLine_byLineId();

  if ($tax_detail_detail_i) {
   return;
  }
  $inv_header = ap_transaction_header::find_by_id($this->ap_transaction_header_id);
  $po_control = po_purchasing_control::find_by_org_id($inv_header->bu_org_id);
  $tax_detail_detail->ap_transaction_header_id = $this->ap_transaction_header_id;
  $tax_detail_detail->amount = $this->tax_amount;
  $tax_detail_detail->gl_amount = $this->gl_tax_amount;
  $tax_detail_detail->account_type = 'TAX';
  $tax_detail_detail->detail_ac_id = $po_control->tax_ac_id;
  $tax_detail_detail->audit_trial();
  $tax_detail_detail->save();
 }

 private function _create_transaction_details() {
  if (($this->action === 'match_purchase_order') && (!empty($this->po_line_id)) && (!empty($this->po_detail_id))) {
   $ap_th = new ap_transaction_header();
   $ap_th->findBy_id($this->ap_transaction_header_id);
   $po_d = new po_detail();
   $po_d_i = $po_d->findBy_id($this->po_detail_id);
   $ap_td = new ap_transaction_detail();
   $ap_td->ap_transaction_line_id = $this->ap_transaction_line_id;
   $ap_td->ap_transaction_header_id = $this->ap_transaction_header_id;
   $ap_td->detail_number = 1;
   $ap_td->account_type = 'ACCRUAL';
   $ap_td->description = '';
   $ap_td->amount = $this->inv_line_price;
   $ap_td->gl_amount = $this->gl_inv_line_price;
   $ap_td->detail_ac_id = $po_d_i->charge_ac_id;
   $ap_td->status = '';
   $ap_td->reference_type = 'table';
   $ap_td->reference_key_name = 'po_header';
   $ap_td->reference_key_value = $this->po_header_id;
   $ap_td->po_header_id = $this->po_header_id;
   $ap_td->po_line_id = $this->po_line_id;
   $ap_td->po_detail_id = $this->po_detail_id;
   $ap_td->period_id = $ap_th->period_id;
   $ap_td->audit_trial();
   //update PO details
   foreach ($po_d_i as $pd_key => $pd_value) {
    $po_d->$pd_key = $pd_value;
   }

   echo "<br>Quanitities are in PO : " . $po_d->invoiced_quantity . ' in Inv Line : ' . $this->inv_line_quantity . ' : Submitted by form ' . $this->invoiced_quantity;
   $po_d->invoiced_quantity += $this->inv_line_quantity;
   $po_d->save();
   $ap_td->save();

   //update the ap transaction header amount
   $ap_th->header_amount += $this->inv_line_price;
   $ap_th->tax_amount += $this->tax_amount;
   $ap_th->save();
   
  }
 }

 public function _after_save() {
  if (($this->action === 'match_purchase_order') && (!empty($this->ap_transaction_line_id)) && (!empty($this->po_line_id)) && (!empty($this->po_detail_id))) {
   $this->_create_transaction_details();
  }
  if (!empty($this->tax_amount)) {
   //verify if detail line exists for tax, if not add. 
   $this->_validate_tax_detail_line();
  }
 }

 public function _before_save() {

  if (empty($this->line_type)) {
   $this->line_type = 'GOODS';
  }
  if ((!empty($this->po_header_id)) && ($this->action != 'apply_transaction') && ($this->ap_transaction_header_id)) {
   $current_highest_line_no = $this->_highest_line_number_from_header();
   $this->line_number = $current_highest_line_no->line_number + 1;
  }
  if (($this->action === 'match_purchase_order') && (!empty($this->po_line_id)) && (!empty($this->po_detail_id))) {

   if ($this->doc_currency != $this->inv_doc_currency) {
    ino_showWarning_message('Invoice Matching failed as PO Currency (' . $this->doc_currency . ') and Invoice Currency (' . $this->inv_doc_currency . ') are different');
    return -90;
   }

   if (empty(trim($this->inv_line_quantity))) {
    $this->inv_line_quantity = $this->invoicing_open_quantity;
   }
   $exchng_rate = !empty($this->line_price) ? ($this->gl_line_price / $this->line_price) : 1;
   $tax_rate = !empty($this->line_price) ? ($this->tax_amount / $this->line_price) : 0;
   $this->inv_unit_price = !empty(trim($this->inv_unit_price)) ? $this->inv_unit_price : $this->unit_price;
   $this->inv_line_price = !empty(trim($this->inv_line_price)) ? $this->inv_line_price : ( $this->inv_unit_price * $this->inv_line_quantity);
   $this->gl_inv_line_price = ($this->inv_line_price) * $exchng_rate;
   $this->tax_amount = $tax_rate * $this->inv_line_price;
   $this->gl_tax_amount = $this->tax_amount * $exchng_rate;
  }
  if (($this->action == 'apply_transaction') && (!empty($this->po_line_id)) && (!empty($this->po_detail_id))) {
   $this->reference_type = 'table';
   $this->reference_key_name = 'ap_transaction_line';
   $this->reference_key_value = $this->ap_transaction_line_id;
   $this->ref_transaction_header_id = $this->ap_transaction_header_id;
   $this->ap_transaction_header_id = $this->cm_transaction_header_id;
   $current_highest_line_no = $this->_highest_line_number_from_header();
   $this->line_number = $current_highest_line_no->line_number + 1;
   $this->ref_transaction_line_id = $this->ap_transaction_line_id;
   $this->ap_transaction_line_id = null;
   $this->inv_unit_price = !empty(trim($this->credit_unit_price)) ? $this->credit_unit_price : $this->inv_unit_price;
   if (!empty(trim($this->credit_line_quantity))) {
    $this->inv_line_quantity = $this->credit_line_quantity;
   }
   $this->inv_line_quantity = -$this->inv_line_quantity;
   $this->inv_line_price = $this->inv_unit_price * $this->inv_line_quantity;
  }
 }

 private function _highest_line_number_from_header($ap_transaction_header_id = '') {
  $ap_transaction_header_id = !empty($ap_transaction_header_id) ? $ap_transaction_header_id : $this->ap_transaction_header_id;
  $sql = " SELECT max(line_number) as line_number FROM " . self::$table_name;
  $sql .= " WHERE ap_transaction_header_id= :ap_transaction_header_id ";
  $value_a = ['ap_transaction_header_id' => $ap_transaction_header_id];
  $result = $this->findBySql($sql, $value_a);
  return !empty($result) ? array_pop($result) : 0;
 }

 Public static function ap_transaction_line_types() {
  $option_header = option_header::find_by_name('PO_LINE_TYPE');
  $po_types = option_line::find_by_option_id($option_header->option_header_id);
  return $po_types;
 }

 public static function find_by_ap_transaction_headerId($ap_transaction_header_id) {
  $sql = "SELECT * FROM " . self::$table_name . " where ap_transaction_header_id = '{$ap_transaction_header_id}'";
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
   'supplier_id',
   'ap_transaction_header_id',
   'action',
   'mode',
   'po_status',
   'supplier_site_id',
   'inv_doc_currency'
  ];

  return $multi_select_hidden;
 }

 public function copy($ap_transaction_line_id) {
  global $db;
  $sql1 = " CREATE TEMPORARY TABLE tmptable SELECT * FROM ap_transaction_line WHERE `ap_transaction_line_id` = '{$ap_transaction_line_id}' ";
  if ($db->query($sql1)) {
   $sql2 = "  UPDATE tmptable SET `ap_transaction_line_id` = '' ,
           `org_id` = '{$this->org_id}' 
          WHERE `ap_transaction_line_id` = '{$ap_transaction_line_id}' ";
   if ($db->query($sql2)) {
    $sql3 = " INSERT INTO `ap_transaction_line` SELECT * FROM tmptable WHERE `ap_transaction_line_id` = '' ";
    if ($db->query($sql3)) {
     $this->ap_transaction_line_id = $db->insert_id();
     $this->msg = 1;
    } else {
     $this->msg = 0;
    }
   }
  }
  return $this->msg;
 }

}

//end of ap_transaction_line class
?>