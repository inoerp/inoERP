<?php
$module_info = [
		array(
				"module" => "po",
				"class" => "po_header",
				"key_field" => "po_type",
				"primary_column" => "po_header_id"
		),
		array(
				"module" => "po",
				"class" => "po_line",
				"key_field" => "item_description",
				"primary_column" => "po_line_id"
		),
		array(
				"module" => "po",
				"class" => "po_detail",
				"key_field" => "shipment_number",
				"primary_column" => "po_detail_id"
		)
];
$pageTitle = " PO - Print ";
$view_path = "po_view";
?>
<?php include_once(__DIR__.'/../../includes/template/header_simple.inc'); ?>
<?php
$class = $class_first = 'po_header';
$$class = $$class_first = &$po_header;
$class_second = 'po_line';
$$class_second = &$po_line;
$class_third = 'po_detail';
$$class_third = &$po_detail;
?>

<?php
if (!empty($_GET["po_header_id"])) {
 $po_header_id = htmlentities($_GET["po_header_id"]);
} elseif (!empty($_POST["po_header_id"][0])) {
 $po_header_id = $_POST["po_header_id"][0];
} else {
 $po_line = new po_line();
 $po_line_object = array();
 array_push($po_line_object, $po_line);
//	$field_array = po_line::$field_array;
}

if (!empty($po_header_id)) {
 $po_line_object = po_line::find_by_po_headerId($po_header_id);
 //assign the item number to the object
 foreach ($po_line_object as &$po_lines) {
	if (!empty($po_lines->item_id_m)) {
	 $item = item::find_by_id($po_lines->item_id_m);
	 $po_lines->item_number = $item->item_number;
	}
 }
 if (count($po_line_object) == 0) {
	$po_line = new po_line;
	$po_line_object = array();
	array_push($po_line_object, $po_line);
 }
}
?>


<?php
$primary_column = 'po_header_id';
$document_type = "Purchase Order";
$document_type_number = "po_number";
$document_revision_number = "rev_number";
$document_showVar1 = "buyer";
$document_showVar2 = "currency";
$document_showVar3 = "payment_term_id";
$document_showVar4 = "header_amount";

$external_entity_type = 'Supplier';

$external_entity_headerClass = "supplier";
$external_entity_headerId = 'supplier_id';
$external_entity_headerName = 'supplier_name';
$external_entity_headerNumber = 'supplier_number';

$external_entity_lineClass = "supplier_site";
$external_entity_lineId = 'supplier_site_id';
$external_entity_lineName = 'supplier_site_name';
$external_entity_lineNumber = 'supplier_site_number';
$external_entity_addressId = 'site_address_id';

$payment_term = payment_term::find_by_id($$class->$document_showVar3);

//row 1 - left side header Info
$header_info_statement = "";
if (!empty($$class->$primary_column)) {
 $header_info_statement .= "<ul>";
 $header_info_statement .= "<li>$document_type : " . $$class->$document_type_number . "</li>";
 $header_info_statement .= "<li>" . gettext('Revision') . " : " . $$class->$document_revision_number . "</li>";
 $header_info_statement .= "<li>" . gettext('Buyer') . " : " . $$class->$document_showVar1 . "</li>";
 $header_info_statement .= "<li>" . gettext('Currency') . " : " . $$class->$document_showVar2 . "</li>";
 $header_info_statement .= "<li>" . gettext('Payment Term') . " : " . $payment_term->payment_term . "</li>";
 $header_info_statement .= "<li>" . gettext('Amount') . " : " . $$class->$document_showVar4 . "</li>";
 $header_info_statement .= "</ul>";
}

//row 1 - right side supplier/customer Info
$external_entiry_info = "";
if (!empty($$class->$external_entity_lineId)) {
 $external_entity_headerDetails = $external_entity_headerClass::find_by_id($$class->$external_entity_headerId);
 $external_entity_lineDetails = $external_entity_lineClass::find_by_id($$class->$external_entity_lineId);

 if (!empty($external_entity_addressId)) {
	$address = address::find_by_id($external_entity_lineDetails->$external_entity_addressId);
	$address_value = address::show_adrees_details_inLine($address);
 }

 $external_entiry_info .= "<ul>";
 $external_entiry_info .= "<li>$external_entity_type : " . $external_entity_headerDetails->$external_entity_headerName . " </li>";
 $external_entiry_info .= "<li>  " . gettext('Number') . "  : " . $external_entity_headerDetails->$external_entity_headerNumber . " </li>";
 $external_entiry_info .= "<li>  " . gettext('Site Name') . "  : " . $external_entity_lineDetails->$external_entity_lineName . "</li>";
 $external_entiry_info .= "<li>  " . gettext('Site Number') . "  : " . $external_entity_lineDetails->$external_entity_lineNumber . "</li>";
 $external_entiry_info .= "<li> $address_value </li>";
 $external_entiry_info .= "</ul>";
}
?>
<div id="page_print">
 <div id="print_header">
	<div class="half_page left logo"><?php echo gettext('Site Logo') ?> </div>
	<div class="half_page right bu_details"><?php echo!(empty($$class->bu_org_id)) ? org::print_orgDetails_inLine($$class->bu_org_id) : ""; ?> </div>
 </div>
 <div id="print_body">
	<div class="full_page">
	 <div class="half_page left header_info"><?php echo!(empty($header_info_statement)) ? $header_info_statement : ""; ?> </div>
	 <div class="half_page right external_entiry_info"><?php echo!(empty($external_entiry_info)) ? $external_entiry_info : ""; ?> </div>
	</div>
	<div class="full_page"></div>
	<div class="full_page">
		<!--<span class="heading"><?php //echo gettext('PO Lines & Shipments') ?> </span>-->
	 <table class="form_line_data_table">
		<thead> 
		 <tr class="line_header">
			<th><?php echo gettext('Line Number') ?></th>
			<th><?php echo gettext('Type') ?></th>
			<th><?php echo gettext('Item Number') ?></th>
			<th><?php echo gettext('Unit Price') ?></th>
			<th><?php echo gettext('Line Quantity') ?></th>
			<th><?php echo gettext('Item Description') ?></th>
			<th><?php echo gettext('Line Description') ?></th>
		 </tr>
		</thead>

		<?php
		$count = 0;
		foreach ($po_line_object as $po_line) {
		 ?>
 		<tbody>
 		 <tr class="line_rows">
 		<tbody class="form_data_line_tbody">
 		<td><?php echo $$class_second->line_number; ?></td>
 		<td><?php
			$line_type = option_line::find_by_id($$class_second->line_type);
			echo $line_type->option_line_code;
			?></td>
 		<td><?php echo $$class_second->item_number; ?></td>
		<td><?php echo $$class_second->unit_price; ?></td>
		<td><?php echo $$class_second->line_quantity; ?></td>
 		<td><?php echo $$class_second->item_description; ?></td>
 		<td><?php echo $$class_second->line_description; ?></td>
 		</tr>
 		<tbody class="form_data_detail_tbody">

 		 <tr class="detail_header"> 
 			<th class="blank"></th>
 			<th><?php echo gettext('Ship To Location') ?></th>
 			<th><?php echo gettext('Quantity') ?></th>
 			<th><?php echo gettext('Need By Date') ?></th>
 			<th><?php echo gettext('Promise Date') ?></th>
 		 </tr>
			<?php
			$po_line_id = $po_line->po_line_id;
			if (!empty($po_line_id)) {
			 $po_detail_object = po_detail::find_by_po_lineId($po_line_id);
			} else {
			 $po_detail_object = array();
			}
			if (count($po_detail_object) == 0) {
			 $po_detail = new po_detail();
			 $po_detail_object = array();
			 array_push($po_detail_object, $po_detail);
			}
			?>
			<?php
			$detailCount = 0;
			foreach ($po_detail_object as $po_detail) {
			 $class_third = 'po_detail';
			 $$class_third = &$po_detail;
			 ?>
			 <tr class="po_detail<?php echo $count . '-' . $detailCount; ?> <?php echo $detailCount != 0 ? ' new_object' : '' ?>">
				<td class="blank"></td>
				<td><?php echo $$class_third->ship_to_location_id; ?></td>
				<td><?php echo $$class_third->quantity; ?></td>
				
				<td><?php echo $$class_third->need_by_date; ?></td>
				<td><?php echo $$class_third->promise_date; ?></td>
			 </tr>
			 <?php
			 $detailCount++;
			}
			?>
 		</tbody>

 		</tbody>
		 <?php
		 $count = $count + 1;
		}
		?>
		</tbody>
	 </table>
	</div>
 </div>
</div>

<tr></tr>
<tr></tr>
</table>
</div>
</div>
<div id="print_footer">
</div>
</div>
