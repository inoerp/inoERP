<?php

//$f = new inoform();
//$class = $class_first = 'inv_transaction';
//$$class = $$class_first = &$inv_transaction;
$class_second = 'am_wo_bom';
$$class_second = &$am_wo_bom;

$$class->document_type = 'Maintenance Work Order';
$$class->reference_type = 'table';

if (!empty($_GET["transaction_type_id"])) {
 $$class->transaction_type_id = $_GET['transaction_type_id'];
}

if (!empty($_GET['am_wo_header_id'])) {
 $am_wo_header_id = htmlentities($_GET["am_wo_header_id"]);
 $am_wo = am_wo_header::find_by_id($am_wo_header_id);
} else if (!empty($_GET["wo_number"])) {
 $wo_number = $_GET["wo_number"];
 $am_wo = am_wo_header::find_by_woNumber($wo_number);
 $am_wo_header_id = $am_wo->am_wo_header_id;
}
if (!empty($am_wo_header_id)) {
 $$class->org_id = $am_wo->org_id;
 $$class->am_wo_header_id = $am_wo_header_id;
 $$class->wo_number = $am_wo->wo_number;
 $am_wo_bom = new am_wo_bom;
 $am_wo_bom_object = $am_wo_bom->findBy_parentId($am_wo_header_id);
 if (count($am_wo_bom_object) == 0) {
  $am_wo_bom_object = array();
  array_push($am_wo_bom_object, $am_wo_bom);
 }

 $hidden_stmt = "<div id='allData' class='hidden'><table>";
 $count = 0;
 if (!empty($am_wo_bom_object) && !empty($$class->org_id)) {
  foreach ($am_wo_bom_object as $am_wo_bom) {
   $item = item::find_by_orgId_item_id_m($am_wo_bom->component_item_id_m, $$class->org_id);
   $$class_second->component_item_number = $item->item_number;
   $$class_second->component_description = $item->item_description;
   $$class_second->component_uom = $item->uom_id;
   $hidden_stmt .= "<tr class='$am_wo_bom->bom_sequence'>";
   $hidden_stmt .= "<td>" . form::text_field('am_wo_bom_id', $$class_second->am_wo_bom_id, '8', '50', 1, '', '', 1, 'am_wo_bom_id') . "</td>";
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

if ((!empty($am_wo_header_id)) && !empty($am_wo_bom_object)) {
 $bom_sequence_stament = '<select class=" select bom_sequence " name="bom_sequence[]">';
 foreach ($am_wo_bom_object as $array) {
  $bom_sequence_stament .='<option value="' . $array->bom_sequence . '" >';
  $bom_sequence_stament .= $array->component_item_number . '-' . $array->bom_sequence;
  $bom_sequence_stament .= '</option>';
 }
 $bom_sequence_stament .= '</select>';
}

if (empty($$class->transaction_type_id)) {
 $$class->transaction_type_id = 24;
}
?>