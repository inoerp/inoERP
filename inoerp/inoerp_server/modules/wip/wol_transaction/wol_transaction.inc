<?php

$$class->document_type = 'WOL Transaction';
$$class->reference_type = 'table';

if (!empty($_GET['item_id_m'])) {
 $$class->item_id_m = $item_id_m = ($_GET["item_id_m"]);
 $$class->org_id = $org_id = ($_GET["org_id"]);
}

$$class->revision_name = !empty($_GET['revision_name']) ? $_GET['revision_name'] : null;

if (!empty($$class->wip_wol_transaction_id)) {
 $inv_trns_details = inv_transaction::find_by_refName_refValue('wip_wol_transaction', $$class->wip_wol_transaction_id);
 if (!empty($inv_trns_details)) {
  $wip_wo_bom_object = [];
  foreach ($inv_trns_details as $trnx_data_rec) {
   $x1 = new wip_wol_transaction_line();
   foreach ($trnx_data_rec as $key => $val) {
    if (property_exists($x1, $key)) {
     $x1->$key = $val;
    }
    $x1->component_item_id_m = $trnx_data_rec->item_id_m;
    $x1->quantity = $trnx_data_rec->quantity;
    if ($$class->transaction_type_id = 10) {
     $x1->supply_sub_inventory = !empty($trnx_data_rec->from_subinventory_id) ? $trnx_data_rec->from_subinventory_id : null;
     $x1->supply_lcator = !empty($trnx_data_rec->from_locator_id) ? $trnx_data_rec->from_locator_id : null;
    } else {
     $x1->supply_sub_inventory = !empty($trnx_data_rec->to_subinventory_id) ? $trnx_data_rec->to_subinventory_id : null;
     $x1->supply_lcator = !empty($trnx_data_rec->to_locator_id) ? $trnx_data_rec->to_locator_id : null;
    }
   }
   array_push($wip_wo_bom_object, $x1);
  }
 }
} else if (!empty($item_id_m) && !empty($org_id)) {
 $bom_header_byItem = bom_header::find_by_itemId_orgId($item_id_m, $org_id);
 $bom_header_id = $bom_header_byItem->bom_header_id;
 $wip_wo_bom_object = bom_line::find_by_bomHeaderId_revNumber($bom_header_id, $$class->revision_name);
}


if (empty($wip_wo_bom_object)) {
 $wip_wo_bom_object = array(new bom_line());
}

if (empty($$class->transaction_type_id)) {
 $$class->transaction_type_id = 10;
}

if (!empty($$class->item_id_m)) {
 $$class->item_number = item::find_by_item_id_m($$class->item_id_m)->item_number;
}

if (!empty($$class->item_id_m) && !empty($$class->org_id)) {
 $revision_name_a = inv_item_revision::find_by_itemIdM_orgId($$class->item_id_m, $$class->org_id);
}
if (empty($revision_name_a)) {
 $revision_name_a = [];
}
?>