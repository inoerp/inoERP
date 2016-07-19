<?php include_once("../../../../includes/basics/basics.inc"); ?>
<?php
 if ((!empty($_GET['item_id_m'])) && (!empty($_GET['find_revision'])) && (!empty($_GET['org_id']))) {
  $data = inv_item_revision::find_by_itemIdM_orgId($_GET['item_id_m'], $_GET['org_id']);
  if (count($data) > 0) {
   echo header('Content-Type: application/json');
   echo json_encode($data);
  }
 }
?>