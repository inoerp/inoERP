<?php
//$f = new inoform();
//$class = $class_first = 'inv_transaction';
//$$class = $$class_first = &$inv_transaction;
$class_second = 'pm_batch_line';
$$class_second = &$pm_batch_line;

$$class->document_type = 'Batch';
$$class->reference_type = 'table';

if (!empty($_GET["transaction_type_id"])) {
 $$class->transaction_type_id = $_GET['transaction_type_id'];
}

if (!empty($_GET['pm_batch_header_id'])) {
 $pm_batch_header_id = ($_GET["pm_batch_header_id"]);
 $pm_batch = pm_batch_header::find_by_id($pm_batch_header_id);
} else if (!empty($_GET["batch_name"])) {
 $batch_name = $_GET["batch_name"];
 $pm_batch = pm_batch_header::find_by_batchName($batch_name);
 $pm_batch_header_id = $pm_batch->pm_batch_header_id;
}
if (!empty($pm_batch_header_id)) {
 $$class->org_id = $pm_batch->org_id;
 $$class->pm_batch_header_id = $pm_batch_header_id;
 $$class->batch_name = $pm_batch->batch_name;
 $pm_batch_bom_object = pm_batch_line::find_all_lines_with_byProductIng_by_headerId($pm_batch_header_id);
 if (count($pm_batch_bom_object) == 0) {
	$pm_batch_bom_object = [new pm_batch_line()];
 }

 $hidden_stmt = "<div id='allData' class='hidden'><table>";
 $count = 0;
 if (!empty($pm_batch_bom_object) && !empty($$class->org_id)) {
	foreach ($pm_batch_bom_object as $pm_batch_bom) {
	 $item = item::find_by_orgId_item_id_m($pm_batch_bom->item_id_m, $$class->org_id);
//	 $$class_second->component_item_number = $item->item_number;
//	 $$class_second->component_description = $item->item_description;
//	 $$class_second->component_uom = $item->uom_id;
	 $hidden_stmt .= "<tr class='$pm_batch_bom->bom_sequence'>";
	 $hidden_stmt .= "<td>" . form::text_field('line_id', $$class_second->line_id, '8', '50', 1, '', '', 1, 'line_id') . "</td>";
	 $hidden_stmt .= "<td>" . form::text_field('line_type', $$class_second->line_type, '8', '50', 1, '', '', 1, 'line_type') . "</td>";
	 $hidden_stmt .= "<td>" . form::text_field('item_id_m', $$class_second->item_id_m, '8', '50', 1, '', '', 1, 'item_id_m') . "</td>";
	 $hidden_stmt .= "<td>" . form::text_field('item_number', $$class_second->item_number, '20', '50', '', '', '', '', 'item_number') . "</td>";
	 $hidden_stmt .= "<td>" . form::text_field('item_description', $$class_second->item_description, '20', '50', '', '', '', 1, 'item_description') . "</td>";
   $hidden_stmt .= "<td>" . form::text_field('step_no', $$class_second->step_no, '8', '50', 1, '', '', 1, 'step_no') . "</td>";
	 $hidden_stmt .= "<td>" . form::select_field_from_object('uom_id', uom::find_all(), 'uom_id', 'uom_name', $$class_second->uom_id, '', '', 'uom') . "</td>";
	 $hidden_stmt .= "<td>" . form::select_field_from_object('subinventory_id', subinventory::find_all_of_org_id($$class->org_id), 'subinventory_id', 'subinventory', $$class_second->subinventory_id, '', $readonly, 'sub_inventory', '', '') . "</td>";
	 $hidden_stmt .= "<td>" . form::select_field_from_object('locator_id', locator::find_all_of_subinventory($$class_second->subinventory_id), 'locator_id', 'locator', $$class_second->locator_id, '', $readonly, 'locator_id', '', '') . "</td>";
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

if ((!empty($pm_batch_header_id)) && !empty($pm_batch_bom_object)) {
 $bom_sequence_stament = '<select class=" select bom_sequence " name="bom_sequence[]">';
 foreach ($pm_batch_bom_object as $array) {
	$bom_sequence_stament .='<option data-line_type="' . $array->line_type .'"  value="' . $array->line_id . '" >';
	$bom_sequence_stament .=  $array->step_no . '-'.$array->item_number . '-' . $array->item_description ;
	$bom_sequence_stament .= '</option>';
 }
 $bom_sequence_stament .= '</select>';
}

if(empty($$class->transaction_type_id)){
 $$class->transaction_type_id = 29;
}
?>