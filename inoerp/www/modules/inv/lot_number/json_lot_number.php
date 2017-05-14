<?php 

require_once __DIR__.'/../../../includes/basics/wloader.inc';
include_once(__DIR__.'/../../../../inoerp_server/includes/basics/basics.inc');


 if ((!empty($_GET['item_id_m'])) && (!empty($_GET['find_lot_list'])) && (!empty($_GET['org_id'])) && (!empty($_GET['status']))) {
  $iln = new inv_lot_number();
  $iln->item_id_m = $_GET['item_id_m'];
  $iln->org_id = $_GET['org_id'];
  $iln->status = $_GET['status'];
  $iln->subinventory_id = !empty($_GET['subinventory_id']) ? $_GET['subinventory_id'] : null;
  $iln->locator_id = !empty($_GET['locator_id']) ? $_GET['locator_id'] : null;
  $data = $iln->findBasic_lotInfo();
  if (count($data) > 0) {
   echo header('Content-Type: application/json');
   echo json_encode($data);
  }
 }
?>