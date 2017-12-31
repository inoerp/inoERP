<?php 
include_once(__DIR__.'/../../../includes/basics/wloader.inc');
include_once(__DIR__."/../../../../inoerp_server/includes/basics/basics.inc"); 

 global $f;
 if ((!empty($_GET['bu_org_id'])) && (!empty($_GET['find_bu_details']))) {
  $data = [];
  $bu_org_id = $_GET['bu_org_id'];

  $ar_transaction_type = ar_transaction_type::find_all_by_buOrgId($bu_org_id);
  $ar_trnx_type_stmt = $f->select_field_from_object('transaction_type', $ar_transaction_type, 'ar_transaction_type_id', 'ar_transaction_type', '', 'transaction_type', '', 1);
  $data['ar_transaction_type'] = $ar_trnx_type_stmt;

  $legal_org_id = org::find_by_id($bu_org_id)->legal_org_id;
  $ledger_id = legal::find_by_orgId($legal_org_id)->ledger_id;
  $data['ledger_id'] = $ledger_id;

  if (!empty($ledger_id)) {

   $ledger = new gl_ledger();
   $ledger_i = $ledger->findBy_id($ledger_id);
   if ($ledger_i) {
    $data['currency'] = $ledger_i->currency_code;
    $gp = new gl_period();
    $all_open_periods = $gp->find_all_periods($ledger_id, 'OPEN');
    $period_id = $gp->current_open_period($ledger_id, 'OPEN')->gl_period_id;
    $period_name_stmt = $f->select_field_from_object('period_id', $all_open_periods, 'gl_period_id', 'period_name', $period_id, 'period_id', '', 1);
    $data['period_name_stmt'] = $period_name_stmt;
    $data['period_id'] = $period_id;
    $data['output_tax'] = $f->select_field_from_object('tax_code_id', mdm_tax_code::find_all_outTax_by_bu_org_id($bu_org_id), 'mdm_tax_code_id', 'tax_code', '', '', 'output_tax medium', '', '', '', '', '', 'percentage');
   }
  }
  if (count($data) == 0) {
   return false;
  } else {
   echo header('Content-Type: application/json');
   echo json_encode($data);
  }
 }
?>