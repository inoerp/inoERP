<?php include_once("../../../includes/basics/basics.inc"); ?>
<?php
 if ((!empty($_GET['item_id_m'])) && (!empty($_GET['find_serial_list'])) && (!empty($_GET['status']))) {
  $isn = new inv_serial_number();
  $isn->item_id_m = $_GET['item_id_m'];
  $isn->find_nonres_serial = true;
  $isn->status = $_GET['status'];
  $isn->current_org_id = !empty($_GET['current_org_id']) ? $_GET['current_org_id'] : null;
  $isn->current_subinventory_id = !empty($_GET['current_subinventory_id']) ? $_GET['current_subinventory_id'] : null;
  $isn->current_locator_id = !empty($_GET['current_locator_id']) ? $_GET['current_locator_id'] : null;
  $data = $isn->findBasic_SerialInfo();
  if (count($data) > 0) {
   echo header('Content-Type: application/json');
   echo json_encode($data);
  }
 }
?>