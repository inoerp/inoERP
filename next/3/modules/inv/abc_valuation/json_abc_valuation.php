<?php include_once("../../../includes/basics/basics.inc"); ?>
<?php

if ((!empty($_GET['inv_abc_valuation_id'])) && (!empty($_GET['find_valuation_details'])) &&
    (!empty($_GET['element_type'])) && (!empty($_GET['element_value']))) {
 switch ($_GET['element_type']) {
  case 'seq_number':
   $data = inv_abc_valuation_result::find_by_parentId_seqNumber($_GET['inv_abc_valuation_id'], $_GET['element_value']);
   break;

  case 'cum_value':
   $data = inv_abc_valuation_result::find_by_parentId_cumValue($_GET['inv_abc_valuation_id'], $_GET['element_value']);
   break;

  default:
   break;
 }

 if (count($data) == 0) {
  return false;
 } else {
  echo header('Content-Type: application/json');
  echo json_encode($data);
 }
}
?>