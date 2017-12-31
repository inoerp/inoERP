<?php
include_once("../../includes/basics/basics.inc");
include("../../tparty/mpdf/mpdf.php");
$mpdf = new mPDF('c');
ob_start();
global $si;
echo '<link href="../../themes/default/public.css" media="all" rel="stylesheet" type="text/css" />';
echo '<link href="po.css" media="all" rel="stylesheet" type="text/css"  />';
$po_header = new po_header();
$class = $class_first = 'po_header';
$$class = $$class_first = &$po_header;
$class_second = 'po_line';
$$class_second = &$po_line;
$class_third = 'po_detail';
$$class_third = &$po_detail;

if (!empty($_GET["po_header_id"])) {
 $po_header_id = ($_GET["po_header_id"]);
 $po_header->findBy_id($po_header_id);
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
$header_info_statement .= "<ul>";
$header_info_statement .= "<li>$document_type : " . $po_header->$document_type_number .  "</li>";
$header_info_statement .= "<li>" . gettext('Revision') . " : " . $po_header->$document_revision_number . "</li>";
$header_info_statement .= "<li>" . gettext('Buyer') . " : " . $po_header->$document_showVar1 . "</li>";
$header_info_statement .= "<li>" . gettext('Currency') . " : " . $po_header->$document_showVar2 . "</li>";
$header_info_statement .= "<li>" . gettext('Payment Term') . " : " . $po_header->payment_term_id . "</li>";
$header_info_statement .= "<li>" . gettext('Amount') . " : " . $po_header->$document_showVar4 . "</li>";
$header_info_statement .= "</ul>";


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
	<div class="half_page left logo">
	 <div class="logo">
		<img src="<?php echo HOME_URL . $si->logo_path ?>" class="logo_image" /></div>
	 <h2><?php echo $si->site_name; ?></h2> 
	</div>
	<div class="half_page right bu_details"><?php echo!(empty($$class->bu_org_id)) ? org::print_orgDetails_inLine($$class->bu_org_id) : ""; ?> </div>
 </div>
 <div id="print_body">
	<div class="full_page">
	 <div class="half_page left header_info"><?php echo!(empty($header_info_statement)) ? $header_info_statement : ""; ?> </div>
	 <div class="half_page right external_entiry_info"><?php echo!(empty($external_entiry_info)) ? $external_entiry_info : ""; ?> </div>
	</div>
	<div class="full_page"></div>
	<div class="full_page">
		<!--<span class="heading">PO Lines & Shipments </span>-->
	 <table class="form_line_data_table">
		<thead> 
		 <tr class="line_header">
			<th><?php echo gettext('L-S') ?> #</th>
			<th><?php echo gettext('Type') ?></th>
			<th><?php echo gettext('Item Number') ?></th>
			<th><?php echo gettext('Unit Price') ?></th>
			<th><?php echo gettext('Line Quantity') ?></th>
			<th><?php echo gettext('Item Description') ?></th>
			<th><?php echo gettext('Ship To Location') ?></th>
			<th><?php echo gettext('Quantity') ?></th>
			<th><?php echo gettext('Need By Date') ?></th>
		 </tr>
		</thead>
		<tbody>
		 <?php
		 $count = 0;
		 foreach ($po_line_object as $po_line) {
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
			$detailCount = 0;
			foreach ($po_detail_object as $po_detail) {
			 $class_third = 'po_detail';
			 $$class_third = &$po_detail;
			 ?>
			 <tr class="line_rows">
				<td><?php echo $$class_second->line_number . '-' . $$class_third->shipment_number; ?></td>
				<td><?php
				 $line_type = option_line::find_by_optionId_lineCode(133, $$class_second->line_type);
				 echo $line_type->option_line_value;
				 ?></td>
				<td><?php echo $$class_second->item_number; ?></td>
				<td><?php echo $$class_second->unit_price; ?></td>
				<td><?php echo $$class_second->line_quantity; ?></td>
				<td><?php echo $$class_second->item_description; ?></td>
				<td><?php echo $$class_third->ship_to_location_id; ?></td>
				<td><?php echo $$class_third->quantity; ?></td>
				<td><?php echo $$class_third->need_by_date; ?></td>
			 </tr>
			 <?php
			 $detailCount++;
			}
			?>
			<?php
			$count = $count + 1;
		 }
		 ?>
		</tbody>
	 </table>
	</div>
 </div>
</div>

<div id="print_footer">
</div>
<?php
$html = ob_get_contents();
ob_end_clean();
echo $html;
// send the captured HTML from the output buffer to the mPDF class for processing
//$mpdf->WriteHTML($html);
//download_send_headers("po_print" . date("Y-m-d") . ".pdf", 'pdf_format');
//$mpdf->Output();
exit;
?>
