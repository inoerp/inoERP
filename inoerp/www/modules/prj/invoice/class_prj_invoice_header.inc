<?php

/**
 * inoERP
 *
 * @copyright   2014 Nishit R. Das
 * @license     https://www.mozilla.org/MPL/2.0/
 * @link        http://inoideas.org
 * @source code https://github.com/inoerp/inoERP
 */

/**
 * prj_invoice_header
 * Contains all the prj_invoice_header information, such as - prj_invoice_header, prj_invoice_header_id, org_id,  type, etc.
 * 
 */
class prj_invoice_header extends dbObject {

 public static $table_name = "prj_invoice_header";
 public static $primary_column = "prj_invoice_header_id";
 public static $primary_column2 = "invoice_number";
 public static $key_column = 'prj_project_header_id';
 public static $dependent_classes = ['prj_invoice_line'];
 public static $module = "prj";
//  data base variables as stored database column name
 public static $system_info = [
  'name' => 'Project invoice',
  'number' => '6029',
  'description' => 'prj_invoice_header',
  'version' => '0.1.1',
  'db_version' => '1001',
  'mod_version' => '1.1.1',
  'primary_entity_cb' => '',
  'module_name' => 'prj',
  'weight' => 17
 ];
 public $action_a = [
  'RELEASE' => 'Release',
  'APPROVE' => 'Aprove',
  'TRANSFER' => 'Trasnfer',
 ];
 public static $status_a = [
  '1' => 'Working',
  '2' => 'Approved',
  '3' => 'Released',
  '4' => 'Transferred',
 ];
 public $field_a = [
  'prj_invoice_header_id',
  'bu_org_id',
  'invoice_status',
  'unearned_coa_id',
  'unbilled_coa_id',
//  'receivables_ac_id',
  'ar_customer_id',
  'ar_customer_site_id',
  'prj_agreement_header_id',
  'description',
  'prj_project_header_id',
  'transfer_status',
  'unearned_amount',
  'unbilled_amount',
  'receivables_amount',
  'currency',
  'doc_currency',
  'invoice_number',
  'exchange_rate_type',
  'exchange_rate',
  'release_date',
  'rejection_reason',
  'transfer_date',
  'document_number',
  'ledger_id',
  'period_id',
  'approval_status',
  'reference_type',
  'reference_key_name',
  'reference_key_value',
  'created_by',
  'creation_date',
  'last_update_by',
  'last_update_date',
 ];
//variables used for showing data
 public $initial_search = [
  'document_number',
  'description',
 ];
 public $requiredField = [
  'bu_org_id',
  'unearned_coa_id',
  'unbilled_coa_id',
  'receivables_ac_id',
  'prj_agreement_header_id',
  'prj_project_header_id',
 ];
 public $fields_inForm_notInDataBase = [
  'action',
 ];
 public $fields_inDataBase_notInForm = [
  'currency'
 ];
 public $search = [
  '_show_update_path' => 1,
  '_show_view_path' => 1,
 ];
 public $search_functions = [
  'Organization' => 'search_org_name'
 ];
 public $profile_default = [
  'exchange_rate_type' => 'gl_currency_conversion_type',
  'bu_org_id' => 'org_bu_name_default',
 ];
 public $pageTitle = " Project Invoice"; //page Title
 public $prj_invoice_header_id;
 public $bu_org_id;
 public $invoice_status;
 public $unearned_coa_id;
 public $unbilled_coa_id;
 public $receivables_ac_id;
 public $ar_customer_id;
 public $ar_customer_site_id;
 public $prj_agreement_header_id;
 public $description;
 public $prj_project_header_id;
 public $transfer_status;
 public $unearned_amount;
 public $unbilled_amount;
 public $receivables_amount;
 public $currency;
 public $doc_currency;
 public $invoice_number;
 public $exchange_rate_type;
 public $exchange_rate;
 public $release_date;
 public $rejection_reason;
 public $transfer_date;
 public $document_number;
 public $ledger_id;
 public $period_id;
 public $approval_status;
 public $reference_type;
 public $reference_key_name;
 public $reference_key_value;
 public $created_by;
 public $creation_date;
 public $last_update_by;
 public $last_update_date;
 public $prg_generate_draft_invoice_parameters = [
  'Organization' => 'search_business_org_nm',
  'Project From' => 'search_project_number_from',
  'Project To' => 'search_project_number_to',
  'Cost Type' => 'search_prj_cost_type_for_distribution',
 ];
 public $prg_generate_draft_invoice_details = [
  'name' => 'Generate Draft Revenue',
  'description' => 'Generate Draft Revenue',
 ];
 public $prg_create_invoice_account_parameters = [
  'Organization' => 'search_business_org_nm',
  'Project From' => 'search_project_number_from',
  'Project To' => 'search_project_number_to',
  'Cost Type' => 'search_prj_cost_type_for_distribution',
 ];
 public $prg_create_invoice_account_details = [
  'name' => 'Create Revenue Accounting',
  'description' => 'Create Revenue Accounting',
 ];

 public function _before_save() {
//  if (!empty($this->revenue_status) && $this->revenue_status != 'WORKING') {
//   if ($this->_verify_status() < 0) {
//    return -90;
//   }
//  }
  if (!empty($this->action)) {
   $this->_do_action();
  }

  if (empty($this->invoice_status)) {
   $this->revenue_status = 'WORKING';
  }
 }

 private function _do_action() {
  switch ($this->action) {
   case 'RELEASE' :
    $this->invoice_status = '3';
    break;

   case 'APPROVE' :
    $this->invoice_status = '2';
    break;

   case 'TRANSFER' :
    $this->invoice_status = '4';
    $this->_create_gl_interface_lines($this->prj_project_header_id);
    break;

   default:
    break;
  }
 }

 private function _verify_status() {
  $return = 1;
  if ($this->revenue_status > 2) {
   echo "<br>You can't modify any invoice header in" . $this->status . " status";
   $return = -1;
  }
  return $return;
 }

 private $_prj_project_header_id_from;
 private $_cost_type_for_distribution;
 private $_prj_project_header_id_to;

 public static function find_byProjectHeaderId($prj_project_header_id) {
  $sql = " SELECT *
FROM prj_invoice_header 
WHERE prj_project_header_id = '{$prj_project_header_id}'

";
$sql = ino_perPageSql_i($sql, 1);
  $result = self::find_by_sql($sql);

  return !empty($result) ? array_pop($result) : false;
 }

 private function _create_draft_invoice($prj_project_header_id) {
  /*
   * 1. Find the revenue method for the project
   * 2. Verify the project status is in ('ACTIVE' , 'PENDING_CLOSURE' , 'INVOICE_HOLD')
   * 3. Find the billing method
   *    3.1 Event - Find all events with out full invoice and generate the corresponding invoice
   *    3.2 Work  - Find the % Completion of the project and multiply be approved revenue budget to get total invoice.
   *                Substract all the existing revenue to get the latest invoice amount.
   *    3.3 Cost - Find Actual Cost to Budgeted Cost to find cost ratio. Multiply cost ratio with invoice budget to get the total invoice amount.
   *               Substract all the existing invoice to get the latest invoice amount.
   * 4. Find all billable lines/amounts and corresponding invoice amount.
   * 5. Verify that the total invoice amount is less than the funded amount

   */
  global $dbc;

  $prj_i = new prj_project_header();
  $prj_i->findBy_id($prj_project_header_id);

  if ($prj_i && !(in_array($prj_i->project_status, ['ACTIVE', 'PENDING_CLOSURE', 'INVOICE_HOLD']))) {
   throw new Exception('Project status doesnt allow invoice creation');
  }
//  pa($prj_i);
  switch ($prj_i->billing_method) {
   case 'WW':
   case 'EW':
   case 'CW':
    try {
     $this->_create_invoiceByWork($prj_i);
    } catch (Exception $e) {
     $this->message .= "<br>Unable to save invoice by WORK " . $e->getMessage();
    }
    break;

   case 'CC':
    try {
     $this->_create_invoiceByCostToCost($prj_i);
    } catch (Exception $e) {
     $this->message .= "<br>Unable to save invoice by COST-TO-COST " . $e->getMessage();
    }
    break;

   case 'EE':
   case 'CE':
   case 'WE':
    try {
     $this->_create_invoiceByPercentComplete($prj_i);
    } catch (Exception $e) {
     $this->message .= "<br>Unable to save invoice by percent line " . $e->getMessage();
    }
    break;

   default:
    break;
  }
 }

 private function _create_invoiceByPercentComplete($prj_i) {
  //check if project invoice exists
  $prj_invoice_i = self::find_byProjectHeaderId($prj_i->prj_project_header_id);
  if ($prj_invoice_i) {
   $prj_invoice_lines_i = prj_invoice_line::find_by_parent_id($prj_invoice_i->prj_invoice_header_id);
  } else {
   //create invoice header
   $prj_invoice_i = $this->_create_invoiceHeader($prj_i);
  }

  /*
   * 1. Find the total budgeted invoice and mulitply with % completion to get total invoice
   * 2. Find the total created invoice
   * 3. New invoice = 1 - 2 and create a new line for the invoice header
   */

  if (empty($prj_invoice_i)) {
   $this->message .= "<br>Uanble to create/find project invoice details ";
   throw new Exception("NO_PROJECT_HEADER_FOUND");
  } else {
   $this->message .= '<br>Using project invoice header id ' . $prj_invoice_i->prj_invoice_header_id;
  }

  $total_budget_amount = prj_budget_line::find_revBudgetAmount_byProjectHeaderId($prj_i->prj_project_header_id);
  $percent_comp = prj_percent_header::find_by_ColumnNameVal('prj_project_header_id', $prj_i->prj_project_header_id);
  if ($percent_comp) {
   $percent_val = $percent_comp[0]->percent;
  } else {
   $this->message .= "<br>Project completion % is 0 ";
   throw new Exception("ZERO_PROJECT_COMPLETION");
  }
  $invoice_amount = ($percent_val * $total_budget_amount) / 100;
  $existing_invoice_amount = prj_invoice_line::find_totalinvoice_projectHeaderId($prj_i->prj_project_header_id);
  $new_invoice_amount = $invoice_amount - $existing_invoice_amount;
  if ($new_invoice_amount > 0) {
   $line_description = "percent_val is $percent_val, total_budget_amount is $total_budget_amount and existing rev amount is $existing_invoice_amount ";
   $inv_line_params_a = [
    'new_inv_amount' => $new_invoice_amount,
    'line_description' => $line_description,
    'revenue_source' => 'PERCENT_COMPLETE',
    'revenue_category' => 'EVENT',
    'reference_key_name' => 'prj_percent_headerrev|prj_percent_header_id',
    'reference_key_value' => $percent_comp[0]->prj_percent_header_id,
   ];
   $this->_create_invoiceLines($prj_invoice_i, $inv_line_params_a);
  } else {
   $this->message .= "<br>New invoice amount is less than equal to zero as project percent completion status ";
   throw new Exception("ZERO_invoice_AMOUNT");
  }
 }

 private function _create_invoiceByCostToCost($prj_i) {
  //check if project invoice exists
  $prj_invoice_i = self::find_byProjectHeaderId($prj_i->prj_project_header_id);
  if ($prj_invoice_i) {
   $prj_invoice_lines_i = prj_invoice_line::find_by_parent_id($prj_invoice_i->prj_invoice_header_id);
  } else {
   //create invoice header
   $prj_invoice_i = $this->_create_invoiceHeader($prj_i);
  }

  if (empty($prj_invoice_i)) {
   $this->message .= "<br>Uanble to create/find project invoice details ";
   throw new Exception("NO_PROJECT_HEADER_FOUND");
  } else {
   $this->message .= '<br>Using project invoice header id ' . $prj_invoice_i->prj_invoice_header_id;
  }

  /*
   * 1. Find the ratio of actual cost to the approved budgeted cost 
   * 2. Find the total budgeted invoice and mulitply  cost ratio to get total invoice
   * 3. Find the total created invoice
   * 4. New invoice = 1 - 2 and create a new line for the invoice header
   */

  $budgeted_cost = prj_budget_line::find_budget_by_ProjectHeaderIdBudgetType($prj_i->prj_project_header_id, 'APPR_COST');
  if (empty($budgeted_cost)) {
   $this->msg .= '<br>No approved cost budget found';
   throw new Exception('NO_COST_BUDGET');
  }
  $toal_budgeted_cost = $budgeted_cost->raw_cost + $budgeted_cost->burden_cost;
  $actual_cost = prj_expenditure_line::find_totalExpenditure_by_projectHeaderId($prj_i->prj_project_header_id);
  if (empty($actual_cost)) {
   $this->msg .= '<br>No expenditure found';
   throw new Exception('NO_EXPENDITURE');
  }
  $toal_actual_cost = $actual_cost->line_amount + $actual_cost->burden_amount;

  $cost_ratio = $toal_actual_cost / $toal_budgeted_cost;

  $total_budget_amount = prj_budget_line::find_revBudgetAmount_byProjectHeaderId($prj_i->prj_project_header_id);
  if (empty($total_budget_amount)) {
   $this->msg .= '<br>No approved revenue found';
   throw new Exception('NO_APPROVED_REVENUE_BUDGET');
  }

  $inv_amount = ($cost_ratio * $total_budget_amount) / 100;
  $existing_inv_amount = prj_invoice_line::find_totalinvoice_projectHeaderId($prj_i->prj_project_header_id);
  $new_inv_amount = $inv_amount - $existing_inv_amount;

  if ($new_inv_amount > 0) {
   $line_description = "cost_ratio is $cost_ratio, total_budget_amount is $total_budget_amount and existing inv amount is $existing_inv_amount ";
   $inv_line_params_a = [
    'new_inv_amount' => $new_inv_amount,
    'line_description' => $line_description,
    'revenue_source' => 'ACTUAL_COST',
    'revenue_category' => 'COST_TO_COST',
    'reference_key_name' => '',
    'reference_key_value' => '',
   ];

   $this->_create_invoiceLines($prj_invoice_i, $inv_line_params_a);
  } else {
   $this->message .= "<br>New invoice amount is less than equal to zero as per expenditure";
   throw new Exception("ZERO_invoice_AMOUNT");
  }
 }

 private function _create_invoiceByWork($prj_i) {
  global $dbc;
  //check if project invoice exists
  $prj_invoice_i = self::find_byProjectHeaderId($prj_i->prj_project_header_id);
  if ($prj_invoice_i) {
   $prj_invoice_lines_i = prj_invoice_line::find_by_parent_id($prj_invoice_i->prj_invoice_header_id);
  } else {
   //create invoice header
   $prj_invoice_i = $this->_create_invoiceHeader($prj_i);
  }

  if (empty($prj_invoice_i)) {
   $this->message .= "<br>Uanble to create/find project invoice details ";
   throw new Exception("NO_PROJECT_HEADER_FOUND");
  } else {
   $this->message .= '<br>Using project invoice header id ' . $prj_invoice_i->prj_invoice_header_id;
  }

  /*
   * 1. Find all the expenditure lines with revene_calculated_cb is NULL and their expenditure type
   * 2. Find the rates for each of the expenditures to determine the invoice line amount
   * 3. Compare the sum of the revnue amounts against the budegted invoice.
   * 4. If invoice amount is less than budgeted invoice then save the record else exit the loop.
   */

  $expenditure_lines = prj_expenditure_line::find_lines_forInvoiceGeneration($prj_i->prj_project_header_id);
  if (empty($expenditure_lines)) {
   $this->msg .= '<br>No expenditure lines found';
   throw new Exception('NO_EXPENDITURE');
  }

  $total_budget_amount = prj_budget_line::find_revBudgetAmount_byProjectHeaderId($prj_i->prj_project_header_id);
  if (empty($total_budget_amount)) {
   $this->msg .= '<br>No approved revenue budget found';
   throw new Exception('NO_APPROVED_REVENUE_BUDGET');
  }

  //find invoice amount for each of the expenditure lines as per the project header rate schedule
  $existing_inv_amount = prj_invoice_line::find_totalinvoice_projectHeaderId($prj_i->prj_project_header_id);
  $new_inv_amount_cum = $existing_inv_amount;
  foreach ($expenditure_lines as $expenditure_line) {
   $inv_amount = null;
   $rates = prj_expenditure_line::find_billRates_fromLineIdSchedule($expenditure_line->prj_expenditure_line_id, $prj_i->employee_schedule_id, $prj_i->job_schedule_id, $prj_i->nlr_schedule_id);
   if ($rates) {
    if (!empty($rates->rate)) {
     $inv_amount = ($rates->quantity * $rates->rate);
    } else if (!empty($rates->mark_up_percentage)) {
     $inv_amount = ($rates->line_amount * mark_up_percentage) / 100 + $rates->line_amount;
    } else {
     $this->msg .= '<br>No rates found for expenditure id ' . $expenditure_line->prj_expenditure_line_id;
     throw new Exception('NO_RATE_FOUND_FOR_EXPENDITURE');
    }
   } else {
    $this->msg .= '<br>No rates found for expenditure id ' . $expenditure_line->prj_expenditure_line_id;
    throw new Exception('NO_RATE_FOUND_FOR_EXPENDITURE');
   }
   $new_inv_amount_cum += $inv_amount;
   if ($new_inv_amount_cum > $total_budget_amount) {
    $this->message .= "<br>invoice amount is more than budgeted amount ";
    throw new Exception("invoice_AMOUNT_MORE_THAN_BUDGET");
   }
   if ($inv_amount > 0) {
    $line_description = "invoice amount is $inv_amount";
    $inv_line_params_a = [
     'new_inv_amount' => $inv_amount,
     'line_description' => $line_description,
     'revenue_source' => 'ACTUAL_COST',
     'revenue_category' => 'WORK',
     'reference_key_name' => 'prj_expenditure_line',
     'reference_key_value' => $expenditure_line->prj_expenditure_line_id,
    ];
    try {
     $this->_create_invoiceLines($prj_invoice_i, $inv_line_params_a);
     //update expenditure 
     $prj_exl_j = new prj_expenditure_line();
     $prj_exl_j->findBy_id($expenditure_line->prj_expenditure_line_id);
     $prj_exl_j->revene_calculated_cb = 1;
     $prj_exl_j->save();
    } catch (Exception $e) {
     $dbc->rollback = true;
    }
   } else {
    $this->message .= "<br>New invoice amount is less than equal to zero as per expenditure";
    throw new Exception("ZERO_INVOICE_AMOUNT");
   }
  }
 }

 private function _create_invoiceByEvent($prj_i) {
  $all_lines = prj_event_line::find_allNoninvoiceLines_byProjectHeaderId($prj_i->prj_project_header_id);
  if (empty($all_lines)) {
   $this->message .= "<br>No elligible lines found for  prj_project_header_id {$prj_i->prj_project_header_id} ";
   throw new Exception("NO_ELLIGIBLE_LINES");
  }
  //check if project invoice exists
  $prj_invoice_i = self::find_byProjectHeaderId($prj_i->prj_project_header_id);
  if ($prj_invoice_i) {
   $prj_invoice_lines_i = prj_invoice_line::find_by_parent_id($prj_invoice_i->prj_invoice_header_id);
  } else {
   //create invoice header
   $prj_invoice_i = $this->_create_invoiceHeader($prj_i);
  }


  /*
   * 1. Find the total budgeted invoice and mulitply with % completion to get total invoice
   * 2. Find the total created invoice
   * 3. New invoice = 1 - 2 and create a new line for the invoice header
   */
  if (empty($prj_invoice_i)) {
   $this->message .= "<br>Uanble to create/find project invoice details ";
   throw new Exception("NO_PROJECT_HEADER_FOUND");
  }

  $total_budget_amount = prj_budget_line::find_revBudgetAmount_byProjectHeaderId($prj_i->prj_project_header_id);
  $percent_comp = prj_percent_header::find_by_ColumnNameVal('prj_project_header_id', $prj_i->prj_project_header_id);
  if ($percent_comp) {
   $percent_val = $percent_comp->percent;
  } else {
   $this->message .= "<br>Project completion % is 0 ";
   throw new Exception("ZERO_PROJECT_COMPLETION");
  }
  $rev_amount = ($percent_val * $total_budget_amount) / 100;
  $existing_rev_amount = prj_invoice_line::find_totalinvoice_projectHeaderId($prj_i->prj_project_header_id);
  $new_rev_amount = $rev_amount - $existing_rev_amount;
  if ($new_rev_amount > 0) {
   $this->_create_invoiceLines($prj_invoice_i, $new_rev_amount);
  } else {
   $this->message .= "<br>New invoice amount is less than equal to zero as project percent completion status ";
   throw new Exception("ZERO_invoice_AMOUNT");
  }
 }

 private function _create_invoiceHeader($prj_i) {
  $prj_invoice_header_h = new prj_invoice_header();
  $prj_invoice_header_h->prj_project_header_id = $prj_i->prj_project_header_id;
  $prj_invoice_header_h->bu_org_id = $prj_i->bu_org_id;
  $prj_invoice_header_h->invoice_status = 'ENTERED';
  $org_fin_details = org::find_financial_details_from_orgId($prj_i->bu_org_id);
  $prj_invoice_header_h->ledger_id = $org_fin_details->ledger_id;
  $prj_invoice_header_h->currency = $org_fin_details->currency_code;
  $prj_invoice_header_h->doc_currency = $prj_i->doc_currency;
  $prj_invoice_header_h->exchange_rate_type = 'CORP';

  $gp = new gl_period();
  $gl_period_id = $gp->current_open_period($org_fin_details->ledger_id);
  if (!empty($gl_period_id)) {
   $prj_invoice_header_h->period_id = $gl_period_id->gl_period_id;
  } else {
   $this->message .= "<br>No open GL period found ";
   throw new Exception("NO_OPEN_GL_PERIOD");
  }

//  pa($prj_invoice_header_h);
  if ($prj_invoice_header_h->currency == $prj_invoice_header_h->doc_currency) {
   $prj_invoice_header_h->exchange_rate = 1;
  } else {
   $rate = gl_currency_conversion::find_rate($prj_invoice_header_h->doc_currency, $prj_invoice_header_h->currency, 'CORP');
   $prj_invoice_header_h->exchange_rate = $rate;
  }

  //unearned revenue
  $defalt_act_urevenue = prj_default_account::find_default_account('UNEARNED_REVENUE', $prj_i->prj_project_type_id, $prj_i->accounting_group);
  if ($defalt_act_urevenue) {
   $prj_invoice_header_h->unearned_coa_id = $defalt_act_urevenue->ac_id;
  } else {
   $this->message .= "<br>No Unearned revenue account found. Complete the project default account setup ";
   throw new Exception("NO_UNEARNED_REVENUE_ACCOUNT");
  }

  //unbilled receviable
  $defalt_act_ureceivable = prj_default_account::find_default_account('UNBILL_RECE', $prj_i->prj_project_type_id, $prj_i->accounting_group);
  if ($defalt_act_ureceivable) {
   $prj_invoice_header_h->unbilled_coa_id = $defalt_act_ureceivable->ac_id;
  } else {
   $this->message .= "<br>No unbilled Receivables account found. Complete the project default account setup ";
   throw new Exception("NO_UNBILLED_RECEIVABLES_ACCOUNT");
  }

//  pa($prj_invoice_header_h);
  $prj_invoice_header_h->save();
  return $prj_invoice_header_h;
 }

 private function _create_invoiceLines($prj_invoice_i, array $rev_line_params_a) {
  $prj_invoice_line_l = new prj_invoice_line();
  $prj_invoice_line_l->prj_invoice_header_id = $prj_invoice_i->prj_invoice_header_id;
  $prj_invoice_line_l->revenue_source = $rev_line_params_a['revenue_source'];
  $prj_invoice_line_l->revenue_category = $rev_line_params_a['revenue_category'];
  $prj_invoice_line_l->amount = $rev_line_params_a['new_rev_amount'];
  $prj_invoice_line_l->description = $rev_line_params_a['line_description'];
  $prj_invoice_line_l->reference_key_name = $rev_line_params_a['reference_key_name'];
  $prj_invoice_line_l->reference_key_value = $rev_line_params_a['reference_key_value'];

  $max_line_num = prj_invoice_line::find_highest_line_num($prj_invoice_i->prj_invoice_header_id);
  $prj_invoice_line_l->line_number = !empty($max_line_num) ? $max_line_num + 1 : 1;
  try {
   $prj_invoice_line_l->save();
   $this->message .= "<br>Project invoice line is successfully created";
  } catch (Exception $e) {
   $this->message .= "<br>Unable to save invoice lines";
  }
 }

 public function prg_generate_draft_invoice($seralized_parameters) {
  $parameters = unserialize($seralized_parameters);
  $this->message = '<br> Start of Distribute Cost Program ';

  if (!empty($parameters['bu_org_id'][0])) {
   $this->bu_org_id = $parameters['bu_org_id'][0];
   $this->message .= '<br> Entered Org Id is : ' . $this->bu_org_id;
  } else {
   $this->message .= '<br> Error! : No org id found @  ' . __FILE__ . ' @@ ' . __LINE__;
   return $this->message;
  }

  if (!empty($parameters['prj_project_header_id_from'][0])) {
   $this->_prj_project_header_id_from = $parameters['prj_project_header_id_from'][0];
   $this->message .= "<br>Using to project header id from " . $this->_prj_project_header_id_from;
  }

  if (!empty($parameters['prj_project_header_id_to'][0])) {
   $this->_prj_project_header_id_to = $parameters['prj_project_header_id_to'][0];
   $this->message .= "<br>Using from project header id to " . $this->_prj_project_header_id_to;
  }

  if (!empty($this->_prj_project_header_id_from) && !empty($this->_prj_project_header_id_to)) {
   for ($i = $this->_prj_project_header_id_from; $i <= $this->_prj_project_header_id_to; $i++) {
    try {
     $this->_create_draft_invoice($i);
    } catch (Exception $e) {
     $this->message .= "<br>Failed to complete create draft invoice program " . $e->getMessage();
    }
   }
  } else if (!empty($this->_prj_project_header_id_from)) {
   $all_projects = prj_project_header::find_by_id_gl($this->_prj_project_header_id_from, '>=');
   if ($all_projects) {
    foreach ($all_projects as $project) {
     try {
      $this->_create_draft_invoice($project->prj_project_header_id);
     } catch (Exception $e) {
      $this->message .= "<br>Failed to complete create draft invoice program " . $e->getMessage();
     }
    }
   }
  } else if (!empty($this->_prj_project_header_id_to)) {
   $all_projects = prj_project_header::find_by_id_gl($this->_prj_project_header_id_to, '<=');
   if ($all_projects) {
    foreach ($all_projects as $project) {
     try {
      $this->_create_draft_invoice($project->prj_project_header_id);
     } catch (Exception $e) {
      $this->message .= "<br>Failed to complete create draft invoice program " . $e->getMessage();
     }
    }
   }
  } else {
   //find all projects with line in NULL or ENTERED status and generate draft invoice for them
   $this->message .= '<br>Running program for all available projects ';
   $all_lines_a = prj_expenditure_line::find_distinctProject_byStatus();
   if ($all_lines_a) {
    foreach ($all_lines_a as $el_obj) {
     $this->_create_draft_invoice($el_obj->prj_project_header_id);
    }
   }
  }
  return $this->message;
 }

 public function prg_create_invoice_account($seralized_parameters) {
  $parameters = unserialize($seralized_parameters);
  $this->message = '<br> Start invoice accounting Program ';

  if (!empty($parameters['bu_org_id'][0])) {
   $this->bu_org_id = $parameters['bu_org_id'][0];
   $this->message .= '<br> Entered Org Id is : ' . $this->bu_org_id;
  } else {
   $this->message .= '<br> Error! : No org id found @  ' . __FILE__ . ' @@ ' . __LINE__;
   return $this->message;
  }

  if (!empty($parameters['prj_project_header_id_from'][0])) {
   $this->_prj_project_header_id_from = $parameters['prj_project_header_id_from'][0];
   $this->message .= "<br>Using to project header id from " . $this->_prj_project_header_id_from;
  }

  if (!empty($parameters['prj_project_header_id_to'][0])) {
   $this->_prj_project_header_id_to = $parameters['prj_project_header_id_to'][0];
   $this->message .= "<br>Using from project header id to " . $this->_prj_project_header_id_to;
  }

  if (!empty($this->_prj_project_header_id_from) && !empty($this->_prj_project_header_id_to)) {
   for ($i = $this->_prj_project_header_id_from; $i <= $this->_prj_project_header_id_to; $i++) {
    try {
     $this->_create_gl_interface_lines($i);
    } catch (Exception $e) {
     $this->message .= "<br>Failed to complete create draft invoice program " . $e->getMessage();
    }
   }
  } else if (!empty($this->_prj_project_header_id_from)) {
   $all_projects = prj_project_header::find_by_id_gl($this->_prj_project_header_id_from, '>=');
   if ($all_projects) {
    foreach ($all_projects as $project) {
     try {
      $this->_create_gl_interface_lines($project->prj_project_header_id);
     } catch (Exception $e) {
      $this->message .= "<br>Failed to complete create draft invoice program " . $e->getMessage();
     }
    }
   }
  } else if (!empty($this->_prj_project_header_id_to)) {
   $all_projects = prj_project_header::find_by_id_gl($this->_prj_project_header_id_to, '<=');
   if ($all_projects) {
    foreach ($all_projects as $project) {
     try {
      $this->_create_gl_interface_lines($project->prj_project_header_id);
     } catch (Exception $e) {
      $this->message .= "<br>Failed to complete create draft invoice program " . $e->getMessage();
     }
    }
   }
  } else {
   //find all projects invoice lines where journal header id is null
   $this->message .= '<br>Running program for all available projects ';
   $all_lines_a = prj_expenditure_line::find_distinctProject_byStatus();
   if ($all_lines_a) {
    foreach ($all_lines_a as $el_obj) {
     $this->_create_draft_invoice($el_obj->prj_project_header_id);
    }
   }
  }

  return $this->message;
 }

// public $expclass_

 private function _create_gl_interface_lines($prj_project_header_id) {
  $prj_rev_h_a = prj_invoice_header::find_by_fieldVal(['prj_project_header_id' => $prj_project_header_id]);
  if ($prj_rev_h_a) {
   $prj_rev_h = $prj_rev_h_a[0];
  } else {
   return false;
  }

  if ($prj_rev_h->invoice_status < 3) {
   $this->message .= '<br>invoice status does not allow interface to GL ';
  }
  $sql = " SELECT * FROM prj_invoice_line ";
  $sql .= " WHERE prj_invoice_header_id = '{$prj_rev_h->prj_invoice_header_id}' ";
  $sql .= " AND gl_journal_interface_cb IS NULL ";
  $all_rev_lines = self::find_by_sql($sql);

  if ($all_rev_lines) {
   foreach ($all_rev_lines as $rev_line) {
    $this->_insert_gl_interface($rev_line, $prj_rev_h);
   }
  }
 }

 private function _insert_gl_interface($rev_line, $rev_header) {
  global $dbc, $debug;
  $project = prj_project_header::find_by_id($rev_header->prj_project_header_id);
  $fin_details = prj_project_header::find_financial_details_from_projectHeaderId($project->prj_project_header_id);
  if (!$fin_details) {
   $msg = "<br>Finance details not found";
   if (!empty($debug)) {
    $msg .= "<br> Error @ " . __FILE__ . ' @@ line ' . __LINE__;
   }
   throw new Exception($msg);
  }
  $gl_int = new gl_journal_interface();
  $gl_int->ledger_id = $fin_details->ledger_id;
  $gl_int->status = 'ENTERED';
  $gl_int->currency = $fin_details->currency_code;

  if (!empty($project->doc_currency)) {
   $gl_int->doc_currency = $project->doc_currency;
   $gl_int->exchange_type = $project->exchange_rate_type;
   $gl_int->exchange_rate = $project->exchange_rate;
  } else {
   $gl_int->doc_currency = $fin_details->currency_code;
   $gl_int->exchange_type = 'NA';
   $gl_int->exchange_rate = 1;
  }
  $gp = new gl_period();
  $gl_int->period_id = $gp->current_open_period($fin_details->ledger_id, 'OPEN')->gl_period_id;
  $gl_int->journal_source = self::$module;
  $gl_int->journal_category = self::$gl_journal_category;
  $gl_int->reference_type = 'table';
  $gl_int->reference_key_name = self::$table_name;
  $gl_int->reference_key_value = '-1';
  $gl_int->journal_name = $gl_int->journal_category . '-' . $gl_int->reference_key_value;
  $gl_int->description = $gl_int->journal_name . '-' . current_time();
  $gl_int->balance_type = 'A';
  $gl_int->reference_type = 'table';
  $gl_int->reference_key_name = 'prj_invoice_line';
  $gl_int->reference_key_value = $rev_line->prj_invoice_line_id;
  $gl_int->gl_journal_interface_id = null;
  $gl_int->code_combination_id = $rev_header->invoice_coa_id;
  $gl_int->total_cr = $gl_int->total_ac_cr = $rev_line->amount;
  $gl_int->line_reference_key_name = 'prj_invoice_line';
  $gl_int->line_reference_key_value = $rev_line->prj_invoice_line_id;
  $gl_int->line_status = 'N';
  try {
   $gl_int->save();
   $gl_int->gl_journal_interface_id = null;
   $gl_int->code_combination_id = $rev_header->unbilled_coa_id;
   $gl_int->total_dr = $gl_int->total_ac_dr = $rev_line->amount;
   $gl_int->total_cr = $gl_int->total_cr = null;
   $gl_int->save();
   $prl = new prj_invoice_line();
   $prl->findBy_id($rev_line->prj_invoice_line_id);
   $prl->gl_journal_interface_cb = true;
   $prl->save();
  } catch (Exception $e) {
   echo "<br>Unable to insert interface lines. Error @ " . __FILE__ . ' @@ line ' . __LINE__ . $e->getMessage();
   $dbc->rollback = true;
  }
 }

 public function multi_select_hidden_fields() {
  $multi_select_hidden = [
   'mode',
   'show_block'
  ];

  return $multi_select_hidden;
 }

}

//end of prj_invoice_header class
?>