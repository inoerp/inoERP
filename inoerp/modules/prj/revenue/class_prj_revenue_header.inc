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
 * prj_revenue_header
 * Contains all the prj_revenue_header information, such as - prj_revenue_header, prj_revenue_header_id, org_id,  type, etc.
 * 
 */
class prj_revenue_header extends dbObject {

 public static $table_name = "prj_revenue_header";
 public static $primary_column = "prj_revenue_header_id";
 public static $primary_column2 = "revenue_number";
 public static $key_column = 'prj_project_header_id';
 public static $dependent_classes = ['prj_revenue_line'];
 public static $module = "prj";
//  data base variables as stored database column name
 public static $system_info = [
  'name' => 'Project Revenue',
  'number' => '6011',
  'description' => 'prj_revenue_header',
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
  'WORKING' => 'Working',
  'RELEASED' => 'Released',
  'APPROVED' => 'Approved',
  'TRANSFERRED' => 'Transferred',
 ];
 public $field_a = [
  'prj_revenue_header_id',
  'bu_org_id',
  'revenue_status',
  'unearned_coa_id',
  'unbilled_coa_id',
  'revenue_coa_id',
  'prj_agreement_header_id',
  'description',
  'prj_project_header_id',
  'transfer_status',
  'unearned_amount',
  'unbilled_amount',
  'revenue_amount',
  'currency',
  'doc_currency',
  'revenue_number',
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
  'gl_journal_header_id',
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
  'revenue_coa_id',
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
 public $prg_distribute_cost_parameters = [
  'Organization' => 'search_business_org_nm',
  'Project From' => 'search_project_number_from',
  'Project To' => 'search_project_number_to',
  'Cost Type' => 'search_prj_cost_type_for_distribution',
 ];
 public $prg_distribute_cost_details = [
  'name' => 'Distribute revenue',
  'description' => 'Distribute Project revenue',
 ];
 public $pageTitle = " Project Revenue"; //page Title
 public $prj_revenue_header_id;
 public $bu_org_id;
 public $revenue_status;
 public $unearned_coa_id;
 public $unbilled_coa_id;
 public $revenue_coa_id;
 public $prj_agreement_header_id;
 public $description;
 public $prj_project_header_id;
 public $transfer_status;
 public $unearned_amount;
 public $unbilled_amount;
 public $revenue_amount;
 public $currency;
 public $doc_currency;
 public $revenue_number;
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
 public $gl_journal_header_id;
 public $created_by;
 public $creation_date;
 public $last_update_by;
 public $last_update_date;
 public $prg_generate_draft_revenue_parameters = [
  'Organization' => 'search_business_org_nm',
  'Project From' => 'search_project_number_from',
  'Project To' => 'search_project_number_to',
  'Cost Type' => 'search_prj_cost_type_for_distribution',
 ];
 public $prg_generate_draft_revenue_details = [
  'name' => 'Distribute Expenditure',
  'description' => 'Distribute Project Expenditure',
 ];

 public function _before_save() {
  if (!empty($this->status) && $this->status != 'WORKING') {
   if ($this->_verify_status() < 0) {
    return -90;
   }
  }
  if (!empty($this->action)) {
   $this->_do_action();
  }

  if (empty($this->status)) {
   $this->status = 'WORKING';
  }
 }

 private function _do_action() {
  switch ($this->action) {
   case 'RELEASE' :
    $this->status = 'RELEASED';
    break;

   default:
    break;
  }
 }

 private function _verify_status() {
  $return = 1;
  switch ($this->status) {
   case 'RELEASED' :
    if ($this->action_a != 'REVERSE') {
     echo "<br>You can only reverse a released revenue";
     $return = -1;
    }
    break;

   case 'REVERSED' :
   case 'COSTED':
    echo "<br>You can't modify any revenue in" . $this->status . " status";
    $return = -1;
    break;

   default:
    break;
  }
  return $return;
 }

 private $_prj_project_header_id_from;
 private $_cost_type_for_distribution;
 private $_prj_project_header_id_to;

 public static function find_byProjectHeaderId($prj_project_header_id) {
  $sql = " SELECT *
FROM prj_revenue_header 
WHERE prj_project_header_id = '{$prj_project_header_id}'
LIMIT 1 
";

  $result = self::find_by_sql($sql);

  return !empty($result) ? array_pop($result) : false;
 }

 private function _create_draft_revenue($prj_project_header_id) {
  /*
   * 1. Find the revenue method for the project
   * 2. Verify the project status is in ('ACTIVE' , 'PENDING_CLOSURE' , 'INVOICE_HOLD')
   * 3. Find the billing method
   *    3.1 Event - Find all events with out full revenue and generate the corresponding revenue
   *    3.2 Work  - Find the % Completion of the project and multiply be approved revenue budget to get total revenue.
   *               Substract all the existing revenue to get the latest revenue amount.
   *    3.3 Cost - Find Actual Cost to Budgeted Cost to find cost ratio. Multiply cost ratio with Revenue budget to get the total revenue amount.
   *               Substract all the existing revenue to get the latest revenue amount.
   * 4. Find all billable lines/amounts and corresponding revenue amount.
   * 5. Verify that the total revenue amount is less than the funded amount

   */
  global $dbc;

  $prj_i = new prj_project_header();
  $prj_i->findBy_id($prj_project_header_id);

  if ($prj_i && !(in_array($prj_i->project_status, ['ACTIVE', 'PENDING_CLOSURE', 'INVOICE_HOLD']))) {
   throw new Exception('Project status doesnt allow revenue creation');
  }
//  pa($prj_i);
  switch ($prj_i->billing_method) {
   case 'WW':
   case 'WE':
    break;

   case 'CC':
   case 'CE':
   case 'CW':
    break;

   case 'EE':
   case 'EW':
    try {
     $this->_create_revenueByPercentComplete($prj_i);
    } catch (Exception $e) {
     $this->message .= "<br>Unable to save revenue by percent line " . $e->getMessage();
    }
    break;

   default:
    break;
  }
 }

 private function _create_revenueByPercentComplete($prj_i) {
  //check if project revenue exists
  $prj_revenue_i = self::find_byProjectHeaderId($prj_i->prj_project_header_id);
  if ($prj_revenue_i) {
   $prj_revenue_lines_i = prj_revenue_line::find_by_parent_id($prj_revenue_i->prj_revenue_header_id);
  } else {
   //create revenue header
   $prj_revenue_i = $this->_create_revenueHeader($prj_i);
  }


  /*
   * 1. Find the total budgeted revenue and mulitply with % completion to get total revenue
   * 2. Find the total created revenue
   * 3. New revenue = 1 - 2 and create a new line for the revenue header
   */
  if (empty($prj_revenue_i)) {
   $this->message .= "<br>Uanble to create/find project revenue details ";
   throw new Exception("NO_PROJECT_HEADER_FOUND");
  } else {
   $this->message .= '<br>Using project revenue header id ' . $prj_revenue_i->prj_revenue_header_id;
  }

  $total_budget_amount = prj_budget_line::find_budgetAmount_byProjectHeaderId($prj_i->prj_project_header_id);
  $percent_comp = prj_percent_header::find_by_ColumnNameVal('prj_project_header_id', $prj_i->prj_project_header_id);
  if ($percent_comp) {
   $percent_val = $percent_comp[0]->percent;
  } else {
   $this->message .= "<br>Project completion % is 0 ";
   throw new Exception("ZERO_PROJECT_COMPLETION");
  }
  $rev_amount = ($percent_val * $total_budget_amount) / 100;
  $existing_rev_amount = prj_revenue_line::find_totalRevenue_projectHeaderId($prj_i->prj_project_header_id);
  $new_rev_amount = $rev_amount - $existing_rev_amount;
  if ($new_rev_amount > 0) {
   $line_description = "percent_val is $percent_val, total_budget_amount is $total_budget_amount and existing rev amount is $existing_rev_amount ";
   $this->_create_revenueLines($prj_revenue_i, $new_rev_amount, $line_description);
  } else {
   $this->message .= "<br>New revenue amount is less than equal to zero as project percent completion status ";
   throw new Exception("ZERO_REVENUE_AMOUNT");
  }
 }

 private function _create_revenueByEvent($prj_i) {
  $all_lines = prj_event_line::find_allNonRevenueLines_byProjectHeaderId($prj_i->prj_project_header_id);
  if (empty($all_lines)) {
   $this->message .= "<br>No elligible lines found for  prj_project_header_id {$prj_i->prj_project_header_id} ";
   throw new Exception("NO_ELLIGIBLE_LINES");
  }
  //check if project revenue exists
  $prj_revenue_i = self::find_byProjectHeaderId($prj_i->prj_project_header_id);
  if ($prj_revenue_i) {
   $prj_revenue_lines_i = prj_revenue_line::find_by_parent_id($prj_revenue_i->prj_revenue_header_id);
  } else {
   //create revenue header
   $prj_revenue_i = $this->_create_revenueHeader($prj_i);
  }


  /*
   * 1. Find the total budgeted revenue and mulitply with % completion to get total revenue
   * 2. Find the total created revenue
   * 3. New revenue = 1 - 2 and create a new line for the revenue header
   */
  if (empty($prj_revenue_i)) {
   $this->message .= "<br>Uanble to create/find project revenue details ";
   throw new Exception("NO_PROJECT_HEADER_FOUND");
  }

  $total_budget_amount = prj_budget_line::find_budgetAmount_byProjectHeaderId($prj_i->prj_project_header_id);
  $percent_comp = prj_percent_header::find_by_ColumnNameVal('prj_project_header_id', $prj_i->prj_project_header_id);
  if ($percent_comp) {
   $percent_val = $percent_comp->percent;
  } else {
   $this->message .= "<br>Project completion % is 0 ";
   throw new Exception("ZERO_PROJECT_COMPLETION");
  }
  $rev_amount = ($percent_val * $total_budget_amount) / 100;
  $existing_rev_amount = prj_revenue_line::find_totalRevenue_projectHeaderId($prj_i->prj_project_header_id);
  $new_rev_amount = $rev_amount - $existing_rev_amount;
  if ($new_rev_amount > 0) {
   $this->_create_revenueLines($prj_revenue_i, $new_rev_amount);
  } else {
   $this->message .= "<br>New revenue amount is less than equal to zero as project percent completion status ";
   throw new Exception("ZERO_REVENUE_AMOUNT");
  }
 }

 private function _create_revenueHeader($prj_i) {
  $prj_revenue_header_h = new prj_revenue_header();
  $prj_revenue_header_h->prj_project_header_id = $prj_i->prj_project_header_id;
  $prj_revenue_header_h->bu_org_id = $prj_i->bu_org_id;
  $prj_revenue_header_h->revenue_status = 'ENTERED';
  $org_fin_details = org::find_financial_details_from_orgId($prj_i->bu_org_id);
  $prj_revenue_header_h->ledger_id = $org_fin_details->ledger_id;
  $prj_revenue_header_h->currency = $org_fin_details->currency_code;
  $prj_revenue_header_h->doc_currency = $prj_i->doc_currency;
  $prj_revenue_header_h->exchange_rate_type = 'CORP';

  $gp = new gl_period();
  $gl_period_id = $gp->current_open_period($org_fin_details->ledger_id);
  if (!empty($gl_period_id)) {
   $prj_revenue_header_h->period_id = $gl_period_id->gl_period_id;
  } else {
   $this->message .= "<br>No open GL period found ";
   throw new Exception("NO_OPEN_GL_PERIOD");
  }

  if ($prj_revenue_header_h->currency == $prj_revenue_header_h->doc_currency) {
   $prj_revenue_header_h->exchange_rate = 1;
  } else {
   gl_currency_conversion::find_rate($from_currency, $to_currency, $currency_conversion_type);
  }
  $defalt_act_revenue = prj_default_account::find_default_account('REVENUE', $prj_i->prj_project_type_id, $prj_i->accounting_group);
  if ($defalt_act_revenue) {
   $prj_revenue_header_h->revenue_coa_id = $defalt_act_revenue->ac_id;
  } else {
   $this->message .= "<br>No revenue account found. Complete the project default account setup ";
   throw new Exception("NO_REVENUE_ACCOUNT");
  }

  $defalt_act_urevenue = prj_default_account::find_default_account('UNEARNED_REVENUE', $prj_i->prj_project_type_id, $prj_i->accounting_group);
  if ($defalt_act_urevenue) {
   $prj_revenue_header_h->unearned_coa_id = $defalt_act_urevenue->ac_id;
  } else {
   $this->message .= "<br>No Unearned revenue account found. Complete the project default account setup ";
   throw new Exception("NO_UNEARNED_REVENUE_ACCOUNT");
  }

  $defalt_act_ureceivable = prj_default_account::find_default_account('UNBILL_RECE', $prj_i->prj_project_type_id, $prj_i->accounting_group);
  if ($defalt_act_ureceivable) {
   $prj_revenue_header_h->unbilled_coa_id = $defalt_act_ureceivable->ac_id;
  } else {
   $this->message .= "<br>No unbilled Receivables account found. Complete the project default account setup ";
   throw new Exception("NO_UNBILLED_RECEIVABLES_ACCOUNT");
  }

//  pa($prj_revenue_header_h);
  $prj_revenue_header_h->save();
  return $prj_revenue_header_h;
 }

 private function _create_revenueLines($prj_revenue_i, $new_rev_amount,$line_description) {
  $prj_revenue_line_l = new prj_revenue_line();
  $prj_revenue_line_l->prj_revenue_header_id = $prj_revenue_i->prj_revenue_header_id;
  $prj_revenue_line_l->revenue_source = 'PERCENT_COMPLETE';
  $prj_revenue_line_l->revenue_category = 'EVENT';
  $prj_revenue_line_l->amount = $new_rev_amount;
  $prj_revenue_line_l->description = $line_description;
  $max_line_num = prj_revenue_line::find_highest_line_num($prj_revenue_i->prj_revenue_header_id);
  $prj_revenue_line_l->line_number = !empty($max_line_num) ? $max_line_num + 1 : 1;
  try {
   $prj_revenue_line_l->save();
   $this->message .= "<br>Project revenue line is successfully created";
  } catch (Exception $e) {
   $this->message .= "<br>Unable to save revenue lines";
  }
 }

 public function prg_generate_draft_revenue($seralized_parameters) {
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
   $this->message .= "<br>Using from project header id " . $this->_prj_project_header_id_from;
  }

  if (isset($parameters['cost_type_for_distribution'][0])) {
   $this->_cost_type_for_distribution = $parameters['cost_type_for_distribution'][0];
   $this->message .= "<br>Using distribution type " . $this->_cost_type_for_distribution;
  }

  if (!empty($parameters['prj_project_header_id_to'][0])) {
   $this->_prj_project_header_id_to = $parameters['prj_project_header_id_to'][0];
   $this->message .= "<br>Using to project header id " . $this->_prj_project_header_id_to;
   for ($i = $this->_prj_project_header_id_from; $i <= $this->_prj_project_header_id_to; $i++) {
    try {
     $this->_create_draft_revenue($i);
    } catch (Exception $e) {
     $this->message .= "<br>Failed to complete create draft revenue program " . $e->getMessage();
    }
   }
  } else if (!empty($this->_prj_project_header_id_from)) {
   try {
    $this->_create_draft_revenue($this->_prj_project_header_id_from);
   } catch (Exception $e) {
    $this->message .= "<br>Failed to complete create draft revenue program " . $e->getMessage();
   }
  } else {
   //find all projects with line in NULL or ENTERED status and generate draft revenue for them
   $this->message .= '<br>Running program for all available projects ';
   $all_lines_a = prj_expenditure_line::find_distinctProject_byStatus();
   if ($all_lines_a) {
    foreach ($all_lines_a as $el_obj) {
     $this->_create_draft_revenue($el_obj->prj_project_header_id);
    }
   }
  }





  return $this->message;
 }

// public $expclass_

 public function multi_select_hidden_fields() {
  $multi_select_hidden = [
   'mode',
   'show_block'
  ];

  return $multi_select_hidden;
 }

}

//end of prj_revenue_header class
?>