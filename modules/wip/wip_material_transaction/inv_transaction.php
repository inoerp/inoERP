<?php $show_submit_button = 1; ?>
<?php
$module_info = [
		array(
				"module" => "inventory",
				"class" => "inv_transaction",
				"key_field" => "transaction_type_id",
				"primary_column" => "inv_transaction_id"
		),
		array(
				"module" => "wip",
				"class" => "wip_wo_bom",
				"key_field" => "bom_sequence",
				"primary_column" => "wip_wo_bom_id"
		)
];
$pageTitle = " WIP Material Transaction - Create & Update all Transactions ";
?>
<?php include_once("../../../include/basics/header.inc"); ?> 
<script src="inv_transaction.js"></script>
<!--Set the values for WIP Material Transaction-->
<?php
$class = $class_first = 'inv_transaction';
$$class = $$class_first = &$inv_transaction;
$class_second = 'wip_wo_bom';
$$class_second = &$wip_wo_bom;

$id_array = [6, 7];
$$class->document_type = 'Work Order';

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

 $wip_wo_bom_object = wip_wo_bom::find_by_wip_wo_headerId($wip_wo_header_id);
 if (count($wip_wo_bom_object) == 0) {
	$wip_wo_bom = new wip_wo_bom;
	$wip_wo_bom_object = array();
	array_push($wip_wo_bom_object, $wip_wo_bom);
 }
 echo "<div id='allData' class='hidden'><table>";
 $count = 0;
 foreach ($wip_wo_bom_object as $wip_wo_bom) {
	$item = item::find_by_id($wip_wo_bom->component_item_id);
	$$class_second->component_item_number = $item->item_number;
	$$class_second->component_description = $item->item_description;
	$$class_second->component_uom = $item->uom_id;
	?>         
	<tr class="<?php echo $wip_wo_bom->bom_sequence; ?>">
	 <td><?php form::text_field_wid2s('wip_wo_bom_id'); ?></td>
	 <td><?php form::text_field_wid2sm('bom_sequence'); ?></td>
	 <td><?php echo form::text_field('component_item_id', $$class_second->component_item_id, '8', '50', 1, '', '', 1, 'item_id'); ?></td>
	 <td><?php echo form::text_field('component_item_number', $$class_second->component_item_number, '20', '50', '', '', '', '', 'item_number'); ?></td>
	 <td><?php echo form::text_field('component_description', $$class_second->component_description, '20', '50', '', '', '', 1, 'item_description'); ?></td>
	 <td><?php echo form::select_field_from_object('component_uom', uom::find_all(), 'uom_id', 'uom', $$class_second->component_uom, '', '', 'uom'); ?></td>
	 <td><?php echo form::select_field_from_object('supply_sub_inventory', subinventory::find_all_of_org_id($$class->org_id), 'subinventory_id', 'subinventory', $$class_second->supply_sub_inventory, '', $readonly, 'sub_inventory', '', ''); ?></td>
	 <td><?php echo form::select_field_from_object('supply_locator', locator::find_all_of_subinventory($$class_second->supply_sub_inventory), 'locator_id', 'locator', $$class_second->supply_locator, '', $readonly, 'locator_id', '', ''); ?></td>
	</tr>
	<?php
	$count = $count + 1;
 }
 echo "</table></div>";
}
?>

<?php
if (!empty($wip_wo_header_id)) {
 $bom_sequence_stament = '<select class=" select bom_sequence " name="bom_sequence[]">';
 foreach ($wip_wo_bom_object as $array) {
	$bom_sequence_stament .='<option value="' . $array->bom_sequence . '" >';
	$bom_sequence_stament .= $array->component_item_number . '-' . $array->bom_sequence;
	$bom_sequence_stament .= '</option>';
 }
 $bom_sequence_stament .= '</select>';
}
?>
<?php require_once('inv_transaction_template.php') ?>
