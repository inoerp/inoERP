<?php include_once("../../../includes/basics/basics.inc"); ?>
<?php

 global $f;
 if ((!empty($_GET['gl_ledger_id'])) && (!empty($_GET['find_ledger_details']))) {
  $data = [];
  $ledger_id = $_GET['gl_ledger_id'];
  $data['ledger_id'] = $ledger_id;

  if (!empty($ledger_id)) {

   $ledger = new gl_ledger();
   $ledger_i = $ledger->findBy_id($ledger_id);
   $data['currency'] = $ledger_i->currency_code;
   $data['coa_id'] = $ledger_i->coa_id;
   $gp = new gl_period();
   $all_open_periods = $gp->find_all_periods($ledger_id, 'OPEN');
   $period_id = $gp->current_open_period($ledger_id, 'OPEN')->gl_period_id;
   $period_name_stmt = $f->select_field_from_object('period_id', $all_open_periods, 'gl_period_id', 'period_name', $period_id, 'period_id', '', 1);
   $data['period_name_stmt'] = $period_name_stmt;
   $data['period_id'] = $period_id;
  }
  if (count($data) == 0) {
   return false;
  } else {
   echo header('Content-Type: application/json');
   echo json_encode($data);
  }
 }
?>