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

 private $_cost_type_for_distribution;
 private $_prj_project_header_id_to;
 private $_prj_project_header_id_from;

 public function prg_distribute_cost($seralized_parameters) {
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
     $this->_distribute_cost($i);
    } catch (Exception $e) {
     $this->message .= "<br>Failed to complete distribute cost program " . $e->getMessage();
    }
   }
  } else if (!empty($this->_prj_project_header_id_from)) {
   try {
    $this->_distribute_cost($this->_prj_project_header_id_from);
   } catch (Exception $e) {
    $this->message .= "<br>Failed to complete distribute cost program " . $e->getMessage();
   }
  } else {
   //find all projects with line in NULL or ENTERED status and distribute them
   $this->message .= '<br>Running program for all available projects ';
   $all_lines_a = prj_revenue_line::find_distinctProject_byStatus();
   if ($all_lines_a) {
    foreach ($all_lines_a as $el_obj) {
     $this->_distribute_cost($el_obj->prj_project_header_id);
    }
   }
  }





  return $this->message;
 }

 private function _distribute_cost($prj_project_header_id) {
  /*
   * 1. Find the project id and get the burden list of the project
   * 2. Find all revenue lines where status is null or Entered
   * 3. For each revenue line find corresponding burden cost using find_burdenDetails_fromrevenueLine
   *    3.1 Find the revenue type
   *    3.2 Get the burden structure from the burden list
   *    3.3 Check if the revenue type has a burden cost base in the burden structure
   *    3.4.Find the burden cost code of the burden cost base
   *    3.5 Get the burden rate from the burden structure
   * 4. Create burden revenue
   * 5. Find all revenue debit and credit accounts
   */
  global $dbc;

  $all_exp_lines = prj_revenue_line::find_by_headerId_Status($prj_project_header_id);
  if (empty($all_exp_lines)) {
   $this->message .= "<br>No elligible lines for  prj_project_header_id $prj_project_header_id ";
   return true;
  }


  foreach ($all_exp_lines as $k => $exp_lines) {
   //create the burden details
//   echo '<br> prj_revenue_line_id :' . $exp_lines->prj_revenue_line_id;
   $burden_lines = prj_revenue_line::find_burdenDetails_fromrevenueLine($exp_lines->prj_revenue_line_id);
   $burden_line_amount = 0;

   if ($burden_lines) {
    //create burden lines
    foreach ($burden_lines as $burden_line) {
     $buredn_l = new prj_burden_revenue();
     $buredn_l->prj_revenue_line_id = $burden_line->prj_revenue_line_id;
     if (!empty($burden_line->burden_value)) {
      $buredn_l->burden_amount = $burden_line->burden_value;
     } else if (!empty($burden_line->multiplier)) {
      $buredn_l->burden_amount = $burden_line->multiplier * $exp_lines->quantity;
     }
     $burden_line_amount += $buredn_l->burden_amount;
     $buredn_l->prj_burden_cost_base_id = $burden_line->burden_cost_base_id;
     $buredn_l->prj_revenue_type_header_id = $burden_line->prj_revenue_type_header_id;
     $buredn_l->prj_project_header_id = $burden_line->prj_project_header_id;
     $buredn_l->prj_project_line_id = $burden_line->prj_project_line_id;
     $buredn_l->prj_burden_list_header_id = $burden_line->prj_burden_list_header_id;
     $buredn_l->prj_burden_structure_header_id = $burden_line->prj_burden_structure_header_id;
     $buredn_l->prj_burden_costcode_id = $burden_line->burden_cost_code_id;
     $buredn_l->multiplier = $burden_line->multiplier;
     $buredn_l->burden_value = $burden_line->burden_value;
     try {
//      pa($buredn_l);
      $buredn_l->save();
     } catch (Exception $e) {
      $dbc->rollback = true;
     }
    }
   }

   //get the accounts
   $prj_el = new prj_revenue_line();
   $prj_el->findBy_id($exp_lines->prj_revenue_line_id);
   $prj_eh = prj_revenue_header::find_by_id($prj_el->prj_revenue_header_id);
   $el_accounts = prj_revenue_line::find_accountDetails_fromrevenueLine($exp_lines->prj_revenue_line_id);
   $expn_document_type = $prj_eh->revenue_class . '_EXPEN';
   $clear_document_type = $prj_eh->revenue_class . '_CLEAR';
   $default_exp_ac_id = $default_exp_clr_ac_id = null;
   if (!$el_accounts) {
    return;
   }

   foreach ($el_accounts as $el_acc) {
    switch ($el_acc->document_type) {
     case $expn_document_type:
      $prj_el->debit_ac_id = $el_acc->ac_id;
      break;

     case $clear_document_type:
      $prj_el->credit_ac_id = $el_acc->ac_id;
      break;

     default:
      if ($el_acc->document_type == 'DEFAULT_EXPEN') {
       $default_exp_ac_id = $el_acc->ac_id;
      } else if ($el_acc->document_type == 'DEFAULT_EXPEN_CLEAR') {
       $default_exp_clr_ac_id = $el_acc->ac_id;
      }
      break;
    }
   }

   if (empty($prj_el->debit_ac_id) && !empty($default_exp_ac_id)) {
    $prj_el->debit_ac_id = $default_exp_ac_id;
    echo "<br>Using default debit account id ";
   } else if (empty($prj_el->debit_ac_id) && empty($default_exp_ac_id)) {
    echo "<br>No debit account found. Complete the default account setup";
   }

   if (empty($prj_el->credit_ac_id) && !empty($default_exp_clr_ac_id)) {
    $prj_el->credit_ac_id = $default_exp_clr_ac_id;
    echo "<br>Using default credit account id ";
   } else if (empty($prj_el->credit_ac_id) && empty($default_exp_clr_ac_id)) {
    echo "<br>No credit account found. Complete the default account setup";
   }
   $prj_el->burden_amount = $burden_line_amount;
   $prj_el->status = 'DISTRIBUTED';


   try {
//    pa($prj_el);
    $prj_el->save();
   } catch (Exception $e) {
    $dbc->rollback = true;
   }
  }
 }

 private function _create_burenlines() {
  
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