<?php

class ap_import_claim_v extends dbObject {

 public static $table_name = "ap_import_claim_v";
 public static $primary_column = "hr_expense_header_id";
 public static $multi_search_primary_column = "ar_transaction_header_id"; //this value is used in multi search hidden value
// public static $js_fileName = 'modules/ar/transaction/js/multi_select_ar.js';
 public static $key_column = 'hr_expense_header_id';
 public static $system_info = [
  'name' => 'Import Claim',
  'number' => '1205',
  'description' => 'AP Import Claim',
  'version' => '0.1.1',
  'db_version' => '1001',
  'mod_version' => '1.1.1',
  'primary_entity_cb' => '',
  'module_name' => 'ar',
  'weight' => 6
 ];
 public $field_a = [
  'claim_number',
  'hr_expense_header_id',
  'bu_org_id',
  'first_name',
  'last_name',
  'identification_id',
  'claim_date',
  'header_amount',
  'status',
  'purpose',
  'hr_employee_id',
  'doc_currency',
  'department_id',
  'reason',
  'currency',
  'exchange_rate_type',
  'exchange_rate',
  'supplier_id',
 ];
 public $initial_search = [
  'claim_number',
  'hr_expense_header_id',
  'bu_org_id',
  'first_name',
  'last_name',
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
 public $claim_number;
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
 public $supplier_id;
 public $first_name;
 public $last_name;
 public $identification_id;
 private $_ap_transaction_header_id;
 private $_expense_ac_id;
 private $_period_id;
 private $_cost_center_val;
 public $action;

 public static function find_by_buOrgId($bu_org_id) {
  $sql = " SELECT * FROM ";
  $sql .= self::$table_name;
  $sql .= " WHERE bu_org_id = '{$bu_org_id}' ";
  $result = self::find_by_sql($sql);
  return !empty($result) ? ($result) : false;
 }

 private function create_ap_import_claim_v() {
  $sql = "
CREATE OR REPLACE VIEW ap_import_claim_v
(
claim_number, hr_expense_header_id,   bu_org_id,   hr_employee_id,   claim_date,    status,   purpose,   
doc_currency,   department_id,   reason,   currency,   exchange_rate_type,   exchange_rate,   header_amount,
supplier_id, first_name, last_name, identification_id
)
AS
SELECT 
eh.claim_number, eh.hr_expense_header_id,   eh.bu_org_id,   eh.hr_employee_id,   eh.claim_date,    eh.status,   eh.purpose,   
eh.doc_currency,   eh.department_id,   eh.reason,   eh.currency,   eh.exchange_rate_type,   eh.exchange_rate,   eh.header_amount,
user.supplier_id , he.first_name, he.last_name, he.identification_id

FROM hr_expense_header eh,
ino_user  user,
hr_employee he
  
WHERE eh.status = 'APPROVED'
AND user.hr_employee_id = eh.hr_employee_id  
AND he.hr_employee_id = eh.hr_employee_id  
";
 }

 public function create_ap_transaction() {
  global $dbc;
  $this->_ap_transaction_header_id = $this->_create_transaction_header();
  if ($this->_ap_transaction_header_id < 0) {
   $exp_msg = "Unable to cretae to AP Transaction Header. Error @ " . __LINE__ . ' @@ file ' . __FILE__;
   $code = "UTC_AP_TRANSACTION_HEADER";
   throw new Exception($exp_msg, $code);
  }
  try {
   $this->_create_transaction_line();
   $hr_eh = new hr_expense_header();
   $hr_eh->findBy_id($this->hr_expense_header_id);
   $hr_eh->status = 'INVOICED';
   $hr_eh->save();
  } catch (Exception $e) {
   $dbc->rollback = true;
   $exp_msg = "Unable to cretae to AP Transaction Line. Error @ " . __LINE__ . ' @@ file ' . __FILE__;
   $code = "UTC_AP_TRANSACTION_LINE";
   throw new Exception($exp_msg, $code, $e);
  }
 }

 private function _create_transaction_header() {
  $ap_th = new ap_transaction_header();
  $ap_th->bu_org_id = $this->bu_org_id;
  $ap_th->transaction_type = 'EXPENSE_REPORT';
  $ap_th->document_date = current_time(true);
  $ap_th->doc_currency = $this->doc_currency;
  $hr_con_i = hr_control::find_by_org_id($this->bu_org_id);
//  pa($hr_con_i);
  $this->_expense_ac_id = $hr_con_i->expense_claim_ac_id;
  $department_id_i = sys_value_group_line::find_by_id($this->department_id);
  $this->_cost_center_val = $department_id_i->code;
  $ap_th->supplier_id = $this->supplier_id;
  //if  supplier id is empty get supplier & supplier site from hr_control else get default supplier site id from supplier
  if (empty($ap_th->supplier_id)) {
   $ap_th->supplier_id = $hr_con_i->supplier_id;
   $ap_th->supplier_site_id = $hr_con_i->supplier_site_id;
   $supplier_site_i = supplier_site::find_by_id($ap_th->supplier_site_id);
   $ap_th->payment_term_id = $supplier_site_i->payment_term_id;
  } else {
   $supplier_site_i = supplier_site::find_primary_supplierSite($ap_th->supplier_id);
   $ap_th->supplier_site_id = $supplier_site_i->supplier_site_id;
   $ap_th->payment_term_id = $supplier_site_i->payment_term_id;
  }
//pa($supplier_site_i);
  $org_fin_details = org::find_financial_details_from_orgId($this->bu_org_id);
  $ap_th->ledger_id = $org_fin_details->ledger_id;
  $gp = new gl_period();
  $current_open_period = $gp->current_open_period($org_fin_details->ledger_id);
  $ap_th->period_id = $current_open_period->gl_period_id;
  $this->_period_id = $ap_th->period_id;
  $ap_th->currency = $org_fin_details->currency_code;
  $ap_th->hr_employee_id = $this->hr_employee_id;
  $ap_th->header_amount = $this->header_amount;
  $ap_th->exchange_rate_type = $this->exchange_rate_type;
  $ap_th->exchange_rate = $this->exchange_rate;
  $ap_th->save();
  $ap_th->_after_save();
  if (!empty($ap_th)) {
   $this->_ap_transaction_header_id = $ap_th->ap_transaction_header_id;
   return $ap_th->ap_transaction_header_id;
  } else {
   return -90;
  }
 }

 private function _create_transaction_line() {
  $hr_exp_lines = hr_expense_line::find_by_parent_id($this->hr_expense_header_id);
  $line_num = 1;
  if (empty($hr_exp_lines)) {
   return -1;
  }
  foreach ($hr_exp_lines as $k => $hr_exp_line) {
   $ap_tl = new ap_transaction_line();
   $ap_tl->ap_transaction_header_id = $this->_ap_transaction_header_id;
   $ap_tl->line_number = $line_num;
   $ap_tl->line_type = 'EXPENSE';
   $ap_tl->line_description = 'Expense Claim Line Id ' . $hr_exp_line->hr_expense_line_id;
   $ap_tl->item_description = $hr_exp_line->expense_type . '|' . $hr_exp_line->claim_date;
   $ap_tl->inv_unit_price = $hr_exp_line->receipt_amount;
   $ap_tl->inv_line_price = $hr_exp_line->receipt_amount;
   $ap_tl->line_quantity = 1;
   $ap_tl->reference_type = 'table';
   $ap_tl->reference_key_name = 'hr_expense_line';
   $ap_tl->reference_key_value = $hr_exp_line->hr_expense_line_id;
   $ap_tl->line_quantity = 1;
   $ap_tl->uom_id = '27';
   $ap_tl->save();
   $this->_create_transaction_details($ap_tl);
   $line_num++;
  }
 }

 private function _create_transaction_details($ap_tl) {
  $ap_td = new ap_transaction_detail();
  $ap_td->ap_transaction_line_id = $ap_tl->ap_transaction_line_id;
  $ap_td->ap_transaction_header_id = $ap_tl->ap_transaction_header_id;
  $ap_td->detail_number = 1;
  $ap_td->account_type = 'ACCRUAL';
  $ap_td->description = 'Expense Claim';
  $ap_td->amount = $ap_tl->inv_line_price;
  $ap_td->gl_amount = $ap_tl->inv_line_price;
  $new_comb = coa_combination::find_new_combination($this->_expense_ac_id, ['cost_center' => $this->_cost_center_val]);
  if ($new_comb) {
   $ap_td->detail_ac_id = $new_comb->coa_combination_id;
  } else {
   $ap_td->detail_ac_id = $this->_expense_ac_id;
   $this->message = '<br> Account combination with the deparment is not valid. Using default account<br>';
  }

  $ap_td->status = '';
  $ap_td->reference_type = 'table';
  $ap_td->reference_key_name = 'hr_expense_line';
  $ap_td->reference_key_value = $ap_tl->reference_key_value;
  $ap_td->period_id = $this->_period_id;
  $ap_td->save();
 }

 public function _before_save() {

  if (($this->action == 'import_expense_claim')) {
   echo "<br> Starting to Import Transactions";
   $this->create_ap_transaction();
  }
  return 10;
 }

 public function prg_import_expense_claim($seralized_parameters) {
  /*
   *  1. First Import all lines with the same customer site id
   */
  $parameters = unserialize($seralized_parameters);
  $this->message = '<br> Starting import_expense_claim program....<br>';
  if (!empty($parameters['bu_org_id'][0])) {
   $bu_org_id = $parameters['bu_org_id'][0];
   $this->message .= '<br> Entered Bu org Id is : ' . $bu_org_id;
  } else {
   $this->message .= '<br> Error! : No BU org id found @ file ' . __FILE__ . ' @@ line' . __LINE__;
   return $this->message;
  }

//	Find all expense claim header in approved state from the bu org _id
  $all_exp_claims = self::find_by_buOrgId($bu_org_id);
  if (!empty($all_exp_claims)) {
   foreach ($all_exp_claims as $exp_claim) {
    $ap_imp_clm = new ap_import_claim_v();
    $ap_imp_clm->findBy_id($exp_claim->hr_expense_header_id);
    try {
     $ap_imp_clm->create_ap_transaction();
     $this->message .= '<br>Transaction is sucessfully created for hr_expense_header_id ' . $exp_claim->hr_expense_header_id;
    } catch (Exception $e) {
     $this->message .= '<br>Uanble to create transaction. Error @ file ' . __FILE__ . ' @@ line' . __LINE__;
    }
   }
  } else {
   $this->message .= '<br>No expnese found for import in bu_org_id ' . $bu_org_id;
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