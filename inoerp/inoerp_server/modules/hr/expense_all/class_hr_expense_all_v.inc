<?php

class hr_expense_all_v extends dbObject {

 public static $table_name = "hr_expense_all_v";
 public static $primary_column = "hr_expense_line_id";
 public static $multi_search_primary_column = "ar_transaction_header_id"; //this value is used in multi search hidden value
// public static $js_fileName = 'modules/ar/transaction/js/multi_select_ar.js';
 public static $key_column = 'hr_expense_line_id';
 public static $system_info = [
  'name' => 'Transaction Interface',
  'number' => '3129',
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

 private function create_hr_expense_all_v() {
  $sql = "
CREATE OR REPLACE VIEW hr_expense_all_v
(
hr_expense_header_id,   bu_org_id,   hr_employee_id,   claim_date,    status,   purpose,   
doc_currency,   department_id,   reason,   currency,   exchange_rate_type,   exchange_rate,   header_amount,
hr_expense_line_id,  line_number,   line_claim_date,   receipt_amount,   receipt_currency,   expense_type,
line_status,   line_purpose,   start_date,   line_exchange_rate, supplier_id
)
AS
SELECT 
eh.hr_expense_header_id,   eh.bu_org_id,   eh.hr_employee_id,   eh.claim_date,    eh.status,   eh.purpose,   
eh.doc_currency,   eh.department_id,   eh.reason,   eh.currency,   eh.exchange_rate_type,   eh.exchange_rate,   eh.header_amount,
el.hr_expense_line_id,  el.line_number,   el.claim_date,   el.receipt_amount,   el.receipt_currency,   el.expense_type,
el.status,   el.purpose,   el.start_date,   el.exchange_rate, user.supplier_id

FROM hr_expense_header eh,
hr_expense_line el,
ino_user as user
  
WHERE 
el.hr_expense_header_id = eh.hr_expense_header_id
AND user.hr_employee_id = eh.hr_employee_id  
";
 }

}

//end of po_requisition_detail class
?>