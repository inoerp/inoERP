<?php include_once("../../../includes/basics/basics.inc"); ?>
<?php

if ((!empty($_GET['item_id_m'])) && (!empty($_GET['find_onhand_details'])) && (!empty($_GET['org_id'])) && (!empty($_GET['subinventory_id']))) {
 $onhand = new onhand_v();
 $onhand->item_id_m = ($_GET['item_id_m']);
 $onhand->org_id = ($_GET['org_id']);
 $onhand->subinventory_id = ($_GET['subinventory_id']);
 $onhand->locator_id = (!empty($_GET['locator_id'])) ? $_GET['locator_id'] : null;
 $onhand_i = $onhand->findBy_itemIdm_location();
 $onhand_a = [];
 $onhand_sum = 0;
 $reservable_onhand_sum = 0;
 echo header('Content-Type: application/json');
 if (($onhand_i) && count($onhand_i) >= 1) {
  foreach ($onhand_i as $onhand_obj) {
   $onhand_sum += $onhand_obj->onhand;
   $reservable_onhand_sum += $onhand_obj->reservable_onhand;
  }
 }
// pa($onhand_i);
 $onhand_a['onhand'] = $onhand_sum;
 $onhand_a['reservable_onhand'] = $reservable_onhand_sum;
 if (!empty($onhand_i) && count($onhand_i) == 1) {
  $onhand_a['onhand_id'] = $onhand_i[0]->onhand_id;
 }
 echo json_encode(($onhand_a));
}
?>