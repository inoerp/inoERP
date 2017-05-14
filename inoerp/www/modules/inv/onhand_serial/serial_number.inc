<?php

 $mode = 2;
 $readonly = 1;
 $serial_number_h = null;
 $inv_serial_number_id_h = null;

 $invs = new inv_serial_number();
 if (!empty($_GET['onhand_id'])) {
  $onhand_details = onhand_v::find_by_id($_GET['onhand_id']);
  $invs->org_id = $invs->current_org_id = $onhand_details->org_id;
  $invs->current_subinventory_id = $onhand_details->subinventory_id;
  $invs->item_id_m = $onhand_details->item_id_m;
  $invs->current_locator_id = $onhand_details->locator_id;
  $inv_onhand_serial_object = $invs->findBy_itemIdM_OrgId_status();
 } 
 
 if(empty($inv_onhand_serial_object)){
    $inv_onhand_serial_object = array($invs);
 }
 
?>