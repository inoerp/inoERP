<?php

//$f = new inoform();
//$class = $class_first = 'inv_transaction';
//$$class = $$class_first = &$inv_transaction;
$class_second = 'wip_wo_bom';
$$class_second = &$wip_wo_bom;

$$class->document_type = 'WOL';
$$class->reference_type = 'table';

if (!empty($_GET["transaction_type_id"])) {
 $$class->transaction_type_id = $_GET['transaction_type_id'];
}

if (!empty($_GET['item_id_m'])) {
 $item_id_m = ($_GET["item_id_m"]);
 $org_id = ($_GET["org_id"]);
}

if (!empty($item_id_m) && !empty($org_id)) {
 $$class->org_id = $org_id;
 $$class->item_id_m = $item_id_m;
 $revision_name = !empty($_GET['revision_name']) ? $_GET['revision_name'] : null;
 $bom_header_byItem = bom_header::find_by_itemId_orgId($this->item_id_m, $this->org_id);
 $bom_header_id = $bom_header_byItem->bom_header_id;
 $wip_wo_bom_object = bom_line::find_by_bomHeaderId_revNumber($bom_header_id, $revision_name);

  if (empty($wip_wo_bom_object)) {
  $wip_wo_bom_object = array(new bom_line());
 }

 $hidden_stmt = "<div id='allData' class='hidden'><table>";
 $count = 0;
 if (!empty($wip_wo_bom_object) && !empty($$class->org_id)) {
  foreach ($wip_wo_bom_object as $wip_wo_bom) {
   $item = item::find_by_orgId_item_id_m($wip_wo_bom->component_item_id_m, $$class->org_id);
   $$class_second->component_item_number = $item->item_number;
   $$class_second->component_description = $item->item_description;
   $$class_second->component_uom = $item->uom_id;
   $hidden_stmt .= "<tr class='$wip_wo_bom->bom_sequence'>";
   $hidden_stmt .= "<td>" . form::text_field('wip_wo_bom_id', $$class_second->wip_wo_bom_id, '8', '50', 1, '', '', 1, 'wip_wo_bom_id') . "</td>";
   $hidden_stmt .= "<td>" . form::text_field('bom_sequence', $$class_second->bom_sequence, '8', '50', 1, '', '', 1, 'bom_sequence') . "</td>";
   $hidden_stmt .= "<td>" . form::text_field('component_item_id_m', $$class_second->component_item_id_m, '8', '50', 1, '', '', 1, 'item_id_m') . "</td>";
   $hidden_stmt .= "<td>" . form::text_field('component_item_number', $$class_second->component_item_number, '20', '50', '', '', '', '', 'item_number') . "</td>";
   $hidden_stmt .= "<td>" . form::text_field('component_description', $$class_second->component_description, '20', '50', '', '', '', 1, 'item_description') . "</td>";
   $hidden_stmt .= "<td>" . form::select_field_from_object('component_uom', uom::find_all(), 'uom_id', 'uom_name', $$class_second->component_uom, '', '', 'uom') . "</td>";
   $hidden_stmt .= "<td>" . form::select_field_from_object('supply_sub_inventory', subinventory::find_all_of_org_id($$class->org_id), 'subinventory_id', 'subinventory', $$class_second->supply_sub_inventory, '', $readonly, 'sub_inventory', '', '') . "</td>";
   $hidden_stmt .= "<td>" . form::select_field_from_object('supply_locator', locator::find_all_of_subinventory($$class_second->supply_sub_inventory), 'locator_id', 'locator', $$class_second->supply_locator, '', $readonly, 'locator_id', '', '') . "</td>";
   $hidden_stmt .= "<td>" . $f->text_field('serial_generation', $item->serial_generation) . "</td>";
   $hidden_stmt .= "<td>" . $f->text_field('lot_generation', $item->lot_generation) . "</td>";
   $hidden_stmt .= "</tr>";
   $count = $count + 1;
  }
 }

 $hidden_stmt .= "</table></div>";
}
?>

<?php

if ((!empty($wip_wo_header_id)) && !empty($wip_wo_bom_object)) {
 $bom_sequence_stament = '<select class=" select bom_sequence " name="bom_sequence[]">';
 foreach ($wip_wo_bom_object as $array) {
  $bom_sequence_stament .='<option value="' . $array->bom_sequence . '" >';
  $bom_sequence_stament .= $array->component_item_number . '-' . $array->bom_sequence;
  $bom_sequence_stament .= '</option>';
 }
 $bom_sequence_stament .= '</select>';
}

if (empty($$class->transaction_type_id)) {
 $$class->transaction_type_id = 10;
}

 if (!empty($$class->item_id_m) && !empty($$class->org_id)) {
  $revision_name_a = inv_item_revision::find_by_itemIdM_orgId($$class->item_id_m, $$class->org_id);
 } 
 if(empty($revision_name_a)){
  $revision_name_a = [];
 }
 
?>