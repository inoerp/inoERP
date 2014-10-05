<?php
//$f = new inoform();
//$class = $class_first = 'inv_transaction';
//$$class = $$class_first = &$inv_transaction;
$class_second = 'wip_wo_bom';
$$class_second = &$wip_wo_bom;

$$class->document_type = 'Work Order';
$$class->reference_type = 'table';

if (!empty($_GET["transaction_type_id"])) {
 $$class->transaction_type_id = $_GET['transaction_type_id'];
}

if (!empty($_GET['wip_wo_header_id'])) {
 $wip_wo_header_id = htmlentities($_GET["wip_wo_header_id"]);
 $wip_wo = wip_wo_header::find_by_id($wip_wo_header_id);
} else if (!empty($_GET["wo_number"])) {
 $wo_number = $_GET["wo_number"];
 $wip_wo = wip_wo_header::find_by_woNumber($wo_number);
 $wip_wo_header_id = $wip_wo->wip_wo_header_id;
}
if (!empty($wip_wo_header_id)) {
 $$class->org_id = $wip_wo->org_id;
 $$class->wip_wo_header_id = $wip_wo_header_id;
 $$class->wo_number = $wip_wo->wo_number;
 $wip_wo_bom = new wip_wo_bom;
 $wip_wo_bom_object = $wip_wo_bom->findBy_parentId($wip_wo_header_id);
 if (count($wip_wo_bom_object) == 0) {
	$wip_wo_bom_object = array();
	array_push($wip_wo_bom_object, $wip_wo_bom);
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
   $hidden_stmt .= "<td>" .  $f->text_field('serial_generation', $item->serial_generation) . "</td>";
   $hidden_stmt .= "<td>" .  $f->text_field('lot_generation', $item->lot_generation) . "</td>";
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

if(empty($$class->transaction_type_id)){
 $$class->transaction_type_id = 6;
}
?>