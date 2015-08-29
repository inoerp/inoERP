<?php

class ap_import_claim_v extends dbObject {

 public static $table_name = "ap_import_claim_v";
 public static $primary_column = "hr_expense_line_id";
 public static $multi_search_primary_column = "ar_transaction_header_id"; //this value is used in multi search hidden value
// public static $js_fileName = 'modules/ar/transaction/js/multi_select_ar.js';
 public static $key_column = 'hr_expense_line_id';
 public static $system_info = [
  'name' => 'Transaction Interface',
  'number' => '1306',
  'description' => 'AP Import Claim',
  'version' => '0.1.1',
  'db_version' => '1001',
  'mod_version' => '1.1.1',
  'primary_entity_cb' => '',
  'module_name' => 'ar',
  'weight' => 6
 ];
 public $field_a = [
  'hr_expense_header_id',
  'bu_org_id',
  'hr_employee_id',
  'claim_date',
  'status',
  'purpose',
  'doc_currency',
  'department_id',
  'reason',
  'currency',
  'exchange_rate_type',
  'exchange_rate',
  'header_amount',
  'hr_expense_line_id',
  'line_number',
  'line_claim_date',
  'receipt_amount',
  'receipt_currency',
  'expense_type',
  'line_status',
  'line_purpose',
  'start_date',
  'line_exchange_rate',
  'supplier_id',
 ];
 public $initial_search = [
  'hr_expense_header_id',
  'bu_org_id',
  'hr_employee_id',
 ];
 public $dateField = [
  'document_date'
 ];
 
  public $fields_inForm_notInDataBase = [
  'action'
 ];
  
 public $prg_import_expense_claim_parameters = [
  'Business Org' => 'search_business_org',
 ];
 public $prg_import_expense_claim_details = [
  'name' => 'Import Expense Claim',
  'description' => 'Import Expense Claim',
 ];
 public $pageTitle = " Import Expense Claim "; //page Title
 public $hr_expense_header_id;
 public $bu_org_id;
 public $hr_employee_id;
 public $claim_date;
 public $status;
 public $purpose;
 public $doc_currency;
 public $department_id;
 public $reason;
 public $currency;
 public $exchange_rate_type;
 public $exchange_rate;
 public $header_amount;
 public $hr_expense_line_id;
 public $line_number;
 public $line_claim_date;
 public $receipt_amount;
 public $receipt_currency;
 public $expense_type;
 public $line_status;
 public $line_purpose;
 public $start_date;
 public $line_exchange_rate;
 public $supplier_id;
 public $action;

 public function distinct_customer_sites() {
  $sql = " SELECT DISTINCT(ar_customer_site_id) FROM ";
  $sql .= self::$table_name;
  $result = $this->findBySql($sql);
  return !empty($result) ? array_pop($result) : false;
 }

 private function create_ap_import_claim_v() {
  $sql = "
CREATE OR REPLACE VIEW ap_import_claim_v
(
hr_expense_header_id,   bu_org_id,   hr_employee_id,   claim_date,    status,   purpose,   
doc_currency,   department_id,   reason,   currency,   exchange_rate_type,   exchange_rate,   header_amount,
supplier_id
)
AS
SELECT 
eh.hr_expense_header_id,   eh.bu_org_id,   eh.hr_employee_id,   eh.claim_date,    eh.status,   eh.purpose,   
eh.doc_currency,   eh.department_id,   eh.reason,   eh.currency,   eh.exchange_rate_type,   eh.exchange_rate,   eh.header_amount,
user.supplier_id , he.first_name, he.last_name, he.identification_id

FROM hr_expense_header eh,
user,
hr_employee he
  
WHERE eh.status = 'APPROVED'
AND user.hr_employee_id = eh.hr_employee_id  
AND he.hr_employee_id = eh.hr_employee_id  
";
 }

 public function findBy_customerSiteId_buOrgId($customer_site_id, $bu_org_id) {
  $sql = " SELECT * FROM ";
  $sql .= self::$table_name;
  $sql .= " WHERE ar_customer_site_id = '{$customer_site_id}' AND bu_org_id = '{$bu_org_id}' ";
  $result = $this->findBySql($sql);
  return !empty($result) ? ($result) : false;
 }

 private function _create_transaction_from_post() {
  if (empty($_POST)) {
   return;
  }

//	pa($this);
//	pa($_POST);
//  pa($this->findAll());

  $create_trnx_h = $this->_create_transaction_header();
  if ($create_trnx_h < 0) {
   return;
  }
  $this->_create_transaction_line_from_post();
 }

 private function _create_transaction_header() {
  $sd_so_header_id = $this->sd_so_header_id;
  $sd_so = new sd_so_header();
  $sd_so->findBy_id($sd_so_header_id);

  $ar_th = new ar_transaction_header();
  $ar_th->bu_org_id = $this->bu_org_id;
  $ar_th->ledger_id = $this->ledger_id;
  $ledger = new gl_ledger();
  $ledger->findBy_id($ar_th->ledger_id);

  $ar_th->transaction_type = $this->transaction_type;
  $ar_th->ar_customer_id = $this->ar_customer_id;
  $ar_th->ar_customer_site_id = $this->ar_customer_site_id;
  $ar_th->ship_to_id = $sd_so->ship_to_id;
  $ar_th->bill_to_id = $sd_so->bill_to_id;
  $ar_th->doc_currency = $sd_so->doc_currency;
  $ar_th->currency = $ledger->currency_code;
  $ar_th->bill_to_id = $sd_so->bill_to_id;
  $gp = new gl_period();
  $ar_th->period_id = $gp->current_open_period($ar_th->ledger_id, 'OPEN')->gl_period_id;
  $ar_tt = new ar_transaction_type();
  $ar_tt->findBy_id($ar_th->transaction_type);
  $ar_th->receivable_ac_id = $ar_tt->receivable_ac_id;
  $ar_th->transaction_class = $ar_tt->transaction_class;
  $ar_th->payment_term_id = $sd_so->payment_term_id;
  $ar_th->payment_term_date = $sd_so->payment_term_date;
  $ar_th->document_date = current_time(1);
  $ar_th->reference_type = 'table';
  $ar_th->reference_key_name = 'sd_so_header_id';
  $ar_th->reference_key_value = $ar_th->sd_so_header_id = $sd_so_header_id;
  $ar_th->sd_so_number = $sd_so->so_number;
  $ar_th->audit_trial();
  try {
   $ar_th->save();
  } catch (Exception $e) {

   echo "<br>Failed to create the transaction header. Error @ap_import_claim_v "
   . "@@ Line" . __LINE__ . '<br>' . $e->getMessage();
   $this->rollback = true;
   return -99;
  }
  echo "<br> Transaction header is succefully created. Header Id/ Number - " . $ar_th->ar_transaction_header_id;
  $ar_th->transaction_number = $ar_th->bu_org_id . '-' . $ar_th->ar_transaction_header_id;
  $ar_th->save();
  $this->_ar_transaction_header_id = $ar_th->ar_transaction_header_id;
  return $ar_th->ar_transaction_header_id;
 }

 private function _create_transaction_line_from_post() {
  global $dbc;
  $line_number = 0;

  for ($i = 0; $i < count($_POST['item_description']); $i++) {
   $line_number ++;
   if (empty($this->_ar_transaction_header_id)) {
    return;
   }

   //update the sales order line 
   $sol = new sd_so_line();
   $sol->findBy_id($_POST['sd_so_line_id'][$i]);
   $qty_available_for_inv = $sol->shipped_quantity - $sol->invoiced_quantity;
   if ($qty_available_for_inv <= 0) {
    echo "<br> Line is not available for invoicing . Qty available for invoicing is " . $qty_available_for_inv;
    $dbc->rollback = true;
    return -99;
   }

   $ar_tl = new ar_transaction_line();
   $ar_tl->ar_transaction_line_id = null;
   $ar_tl->line_number = $line_number;
   $ar_tl->ar_transaction_header_id = $this->_ar_transaction_header_id;
   $ar_tl->item_id_m = $_POST['item_id_m'][$i];
   $ar_tl->item_description = $_POST['item_description'][$i];
   $ar_tl->inv_line_quantity = $_POST['inv_line_quantity'][$i];
   $ar_tl->inv_unit_price = $_POST['inv_unit_price'][$i];
   $ar_tl->gl_inv_line_price = $_POST['gl_inv_line_price'][$i];
   $ar_tl->inv_line_price = $_POST['inv_line_price'][$i];
   $ar_tl->tax_code_id = $_POST['tax_code_id'][$i];
   $ar_tl->tax_amount = $_POST['tax_amount'][$i];
   $ar_tl->gl_tax_amount = $_POST['gl_tax_amount'][$i];
   $ar_tl->line_type = $_POST['line_type'][$i];
   $ar_tl->uom_id = $_POST['uom_id'][$i];
   $ar_tl->sd_so_header_id = $_POST['sd_so_header_id'][$i];
   $ar_tl->reference_type = 'table';
   $ar_tl->reference_key_name = 'sd_so_line_id';
   $ar_tl->reference_key_value = $ar_tl->sd_so_line_id = $_POST['sd_so_line_id'][$i];
   $ar_tl->audit_trial();
   $ar_tl->save();

   //update transaction header amount
   $ar_th = new ar_transaction_header();
   $ar_th->findBy_id($ar_tl->ar_transaction_header_id);
   $ar_th->header_amount += $ar_tl->inv_line_price;
   $ar_th->tax_amount += $ar_tl->tax_amount;
   $ar_th->save();

   //update so line details
   $sol->invoiced_quantity = $ar_tl->inv_line_quantity;
   $sol->ar_transaction_header_id = $ar_tl->ar_transaction_header_id;
   $sol->ar_transaction_line_id = $ar_tl->ar_transaction_line_id;
   $sol->line_status = 'CLOSED';
   $sol->audit_trial();
   $sol->save();

   //delete interface line
   $this->ap_import_claim_v_id = $_POST['ap_import_claim_v_id'][$i];
   $this->delete();

   //unset all objects
   unset($ar_tl);
   unset($sol);
   unset($this->ap_import_claim_v_id);
  }
 }

 private function _create_transaction_line_prg($all_lines, $ar_transaction_header_id) {
  $line_number = 0;
  $msg = '<br>Starting to create transaction lines..';
  foreach ($all_lines as $obj) {
   $line_number ++;

   //update the sales order line 
   $sol = new sd_so_line();
   $sol->findBy_id($obj->sd_so_line_id);
   if (in_array($sol->line_status, array('SHIPPED', 'AWAITING_INVOICING'))) {
    $msg .= "<br> Line is not available for invoicing. Line Id is " . $obj->sd_so_line_id;
    continue;
   }

   $ar_tl = new ar_transaction_line();
   $ar_tl->ar_transaction_line_id = null;
   $ar_tl->line_number = $line_number;
   $ar_tl->ar_transaction_header_id = $ar_transaction_header_id;
   $ar_tl->item_id_m = $obj->item_id_m;
   $ar_tl->item_description = $obj->item_description;
   $ar_tl->inv_line_quantity = $obj->inv_line_quantity;
   $ar_tl->inv_unit_price = $obj->inv_unit_price;
   $ar_tl->inv_line_price = $obj->inv_line_price;
   $ar_tl->gl_inv_line_price = $obj->gl_inv_line_price;
   $ar_tl->tax_code_id = $obj->tax_code_id;
   $ar_tl->tax_amount = $obj->tax_amount;
   $ar_tl->gl_tax_amount = $obj->gl_tax_amount;
   $ar_tl->line_type = $obj->line_type;
   $ar_tl->uom_id = $obj->uom_id;
   $ar_tl->sd_so_header_id = $obj->sd_so_header_id;
   $ar_tl->reference_type = 'table';
   $ar_tl->reference_key_name = 'sd_so_line_id';
   $ar_tl->reference_key_value = $ar_tl->sd_so_line_id = $obj->sd_so_line_id;
   $ar_tl->audit_trial();
   $ar_tl->save();
   $msg .= "<br> Line is Successfullycreated. Line id id " . $ar_tl->ar_transaction_line_id;

   //update so line details
   $sol->invoiced_quantity = $ar_tl->inv_line_quantity;
   $sol->ar_transaction_header_id = $ar_tl->ar_transaction_header_id;
   $sol->ar_transaction_line_id = $ar_tl->ar_transaction_line_id;
   $sol->line_status = 'CLOSED';
   $sol->audit_trial();
   $sol->save();
   $msg .= "<br> SO Line is Successfullyupdated. Line id id " . $sol->sd_so_line_id;

   //delete interface line
   $this->ap_import_claim_v_id = $obj->ap_import_claim_v_id;
   $this->delete();

   //unset all objects
   unset($ar_tl);
   unset($sol);
   unset($this->ap_import_claim_v_id);
  }
  return $msg;
 }

 public function _before_save() {

  if (($this->action == 'import_expense_claim')) {
   echo "<br> Starting to Import Transactions";
   pa($this);
//   $this->_create_transaction_from_post();
  }
  return 10;
 }

 public function prg_ap_import_claim($seralized_parameters) {
  /*
   *  1. First Import all lines with the same customer site id
   */
  $output_a = [];
  $parameters = unserialize($seralized_parameters);
  $this->message = '<br> Starting to Import AR Transactions....<br>';
  if (!empty($parameters['bu_org_id'][0])) {
   $bu_org_id = $parameters['bu_org_id'][0];
   $this->message .= '<br> Entered Bu org Id is : ' . $bu_org_id;
  } else {
   $this->message .= '<br> Error! : No BU org id found @ po_requisition_interface ' . __LINE__;
   return $this->message;
  }

//	1. Lines with same customer site id
  $all_customer_sites = $this->distinct_customer_sites();
  foreach ($all_customer_sites as $cst_site_id) {
   $all_lines = $this->findBy_customerSiteId_buOrgId($cst_site_id, $bu_org_id);
   if (empty($all_lines)) {
    return;
   }
   //create header on basis of first object
   $ar_ti_prg = new ap_import_claim_v();
   foreach ($all_lines[0] as $key => $value) {
    if (property_exists($ar_ti_prg, $key)) {
     $ar_ti_prg->$key = $value;
    }
   }
   $ar_ti_prg->_create_transaction_header();
   $this->message .= "<br> Transaction header is succefully created. Header Id/ Number - " . $ar_ti_prg->_ar_transaction_header_id;

   //create lines for each object
   $this->message .=$this->_create_transaction_line_prg($all_lines, $ar_ti_prg->_ar_transaction_header_id);
  }

  return $this->message;
 }

 public function multi_select_input_fields() {
  $multi_select_input = [
  ];
  return $multi_select_input;
 }

 public function multi_select_hidden_fields() {
  $multi_select_hidden = [
   'action_class_name',
   'mode',
   'action',
   'show_block'
  ];

  return $multi_select_hidden;
 }

}

//end of po_requisition_detail class
?>