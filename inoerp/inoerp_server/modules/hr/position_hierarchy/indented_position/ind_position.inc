<!--Start of this page-->
<?php
if (!empty($$class->item_id_m)) {
 $item = item::find_by_id($$class->item_id_m);
 $$class->item_number = $item->item_number;
 $$class->item_description = $item->item_description;
 $$class->uom = $item->uom_id;
}

function indentedBom_tab1($indetned_bom_lines) {
 $indented_bom_statment = '<td>';
 $indented_bom_statment .= form::text_field('bom_line_id', $indetned_bom_lines->bom_line_id, '8');
 $indented_bom_statment .= '</td>';
 $indented_bom_statment .= '<td>';
 $indented_bom_statment .= form::text_field('bom_sequence', $indetned_bom_lines->bom_sequence, '8');
 $indented_bom_statment .= '</td>';
 $indented_bom_statment .= '<td>';
 $indented_bom_statment .= form::text_field('routing_sequence', $indetned_bom_lines->routing_sequence, '8');
 $indented_bom_statment .= '</td>';
 $indented_bom_statment .= '<td>';
 $indented_bom_statment .= form::text_field('component_item_id_m', $indetned_bom_lines->component_item_id_m, '8');
 $indented_bom_statment .= '</td>';
 $indented_bom_statment .= '<td>';
 $indented_bom_statment .= form::text_field('component_item_number', $indetned_bom_lines->component_item_number, '20', '50', 1, '', '', '', 'item_number');
 $indented_bom_statment .= '</td>';
 $indented_bom_statment .= '<td>';
 $indented_bom_statment .= form::text_field('component_description', $indetned_bom_lines->component_description, '20', '50', '', '', '', '', 'component_description');
 $indented_bom_statment .= '</td>';
 $indented_bom_statment .= '<td>';
 $indented_bom_statment .= form::select_field_from_object('component_uom', uom::find_all(), 'uom_id', 'uom_name', $indetned_bom_lines->component_uom, '', '', 'component_uom');
 $indented_bom_statment .= '</td>';
 $indented_bom_statment .= '<td>';
 $indented_bom_statment .= form::text_field('usage_basis', $indetned_bom_lines->usage_basis, '12', '50', '', '', '', '', 'usage_basis');
 $indented_bom_statment .= '</td>';
 $indented_bom_statment .= '<td>';
 $indented_bom_statment .= form::text_field('usage_quantity', $indetned_bom_lines->usage_quantity, '8', '50', '', '', '', '', 'usage_quantity');
 $indented_bom_statment .= '</td>';
 return $indented_bom_statment;
}

function indentedBom_tab2($indetned_bom_lines) {
 $indented_bom_statment = '<td>';
 $indented_bom_statment .= form::date_fieldAnyDay('effective_start_date', $indetned_bom_lines->effective_start_date);
 $indented_bom_statment .= '</td>';
 $indented_bom_statment .= '<td>';
 $indented_bom_statment .= form::date_fieldAnyDay('effective_end_date', $indetned_bom_lines->effective_end_date);
 $indented_bom_statment .= '</td>';
 $indented_bom_statment .= '<td>';
 $indented_bom_statment .= form::text_field('eco_number', $indetned_bom_lines->eco_number, '20');
 $indented_bom_statment .= '</td>';
 $indented_bom_statment .= '<td>';
 $indented_bom_statment .= form::checkBox_field('eco_implemented_cb', $indetned_bom_lines->eco_implemented_cb, 'eco_implemented_cb', 1);
 $indented_bom_statment .= '</td>';
 return $indented_bom_statment;
}

function indentedBom_tab3($indetned_bom_lines) {
 $indented_bom_statment = '<td>';
 $indented_bom_statment .= form::text_field('planning_percentage', $indetned_bom_lines->planning_percentage, '20');
 $indented_bom_statment .= '</td>';
 $indented_bom_statment .= '<td>';
 $indented_bom_statment .= form::text_field('yield', $indetned_bom_lines->yield, '20');
 $indented_bom_statment .= '</td>';
 $indented_bom_statment .= '<td>';
 $indented_bom_statment .= form::select_field_from_object('wip_supply_type', bom_header::wip_supply_type(), 'option_line_code', 'option_line_code', $indetned_bom_lines->wip_supply_type, 'wip_supply_type', 1, '', '');
 $indented_bom_statment .= '</td>';
 $indented_bom_statment .= '<td>';
 $indented_bom_statment .= form::text_field('supply_sub_inventory', $indetned_bom_lines->supply_sub_inventory, '20');
 $indented_bom_statment .= '</td>';
 $indented_bom_statment .= '<td>';
 $indented_bom_statment .= form::text_field('supply_locator', $indetned_bom_lines->supply_locator, '20');
 $indented_bom_statment .= '</td>';
 $indented_bom_statment .= '<td>';
 $indented_bom_statment .= form::checkBox_field('include_in_cost_rollup_cb', $indetned_bom_lines->include_in_cost_rollup_cb, 'eco_implemented_cb', 1);
 $indented_bom_statment .= '</td>';
 return $indented_bom_statment;
}

function show_indentedBom($indented_bom_lines, $tabNumber = 'tab1', $nextLevel = 1) {
 global $rowCount;
 //First line with row count zero is shown on template page
 if ($rowCount == 0) {
	$rowCount ++;
 }

 $level = $nextLevel;
 $i = $level;
 if ($level < 10) {
	if (!empty($indented_bom_lines)) {
	 ${"indentedBom" . $i} = bom_header::find_by_itemId($indented_bom_lines->component_item_id_m);
	}
	if (!empty(${"indentedBom" . $i})) {
	 echo "";
	 $bom_header_id = ${"indentedBom" . $i}->bom_header_id;
	 ${"indented_bom_line_object" . $i} = bom_line::find_all_by_bomHeaderId($bom_header_id);
	 foreach (${"indented_bom_line_object" . $i} as ${"indented_bom_lines" . $i}) {
		$item = item::find_by_id(${"indented_bom_lines" . $i}->component_item_id_m);
		${"indented_bom_lines" . $i}->component_item_number = $item->item_number;
		${"indented_bom_lines" . $i}->component_description = $item->item_description;
		${"indented_bom_lines" . $i}->component_uom = $item->uom_id;
		?>
		<tr class="bom_line<?php echo $rowCount ?>">
		 <td> <?php echo!empty($rowCount) ? $rowCount : ''; ?> </td>
		 <td class="<?php echo 'L' . $level; ?>"> <?php echo 'L: ' . $level; ?> </td>
		 <?php
		 $tabFunction = 'indentedBom_' . $tabNumber;
		 $indented_bom_statment = $tabFunction(${"indented_bom_lines" . $i});
		 echo $indented_bom_statment;
		 $rowCount++;
		 ?>
		</tr>
		<?php
		show_indentedBom(${"indented_bom_lines" . $i}, $tabNumber, $level + 1);
	 }
	}
 }
}
?>
<!--End of this page-->
