<?php
include_once("../../../includes/basics/basics.inc");
include("../../../tparty/mpdf/mpdf.php");
$mpdf = new mPDF('c');
ob_start();
global $si;
echo '<link href="../../../themes/default/layout.css"  media="all" rel="stylesheet" type="text/css" />';
echo '<link href="../../../themes/default/public.css" media="all" rel="stylesheet" type="text/css" />';
echo '<link href="../../../themes/default/print.css" media="all" rel="stylesheet" type="text/css"  />';
$ar_transaction_header = new ar_transaction_header();
$class = $class_first = 'ar_transaction_header';
$$class = $$class_first = &$ar_transaction_header;
$class_second = 'ar_transaction_line';
$$class_second = &$ar_transaction_line;
$class_third = 'ar_transaction_detail';
$$class_third = &$ar_transaction_detail;

if (!empty($_GET["ar_transaction_header_id"])) {
 $ar_transaction_header_id = ($_GET["ar_transaction_header_id"]);
 $ar_transaction_header->findBy_id($ar_transaction_header_id);
}

if (!empty($ar_transaction_header_id)) {
 $ar_transaction_line_object = ar_transaction_line::find_by_parent_id($ar_transaction_header_id);
 //assign the item number to the object
 foreach ($ar_transaction_line_object as &$ar_transaction_lines) {
	if (!empty($ar_transaction_lines->item_id_m)) {
	 $item = item::find_by_id($ar_transaction_lines->item_id_m);
	 $ar_transaction_lines->item_number = $item->item_number;
	}
 }
 if (count($ar_transaction_line_object) == 0) {
	$ar_transaction_line = new ar_transaction_line;
	$ar_transaction_line_object = array();
	array_push($ar_transaction_line_object, $ar_transaction_line);
 }
}
?>


<?php
$primary_column = 'ar_transaction_header_id';
$document_type = 'Invoice';
$document_type_number = "transaction_number";
$document_revision_number = "rev_number";
$document_showVar1 = "sales_person";
$document_showVar2 = "currency";
$document_showVar3 = "payment_term_id";
$document_showVar4 = "header_amount";

$external_entity_type = 'Customer';

$external_entity_headerClass = "ar_customer";
$external_entity_headerId = 'ar_customer_id';
$external_entity_headerName = 'customer_name';
$external_entity_headerNumber = 'customer_number';

$external_entity_lineClass = "ar_customer_site";
$external_entity_lineId = 'ar_customer_site_id';
$external_entity_lineName = 'customer_site_name';
$external_entity_lineNumber = 'customer_site_number';
$external_entity_addressId = 'site_address_id';

$payment_term = payment_term::find_by_id($$class->$document_showVar3);

//row 1 - left side header Info
$header_info_statement = "";
$header_info_statement .= "<ul>";
$header_info_statement .= "<li>$document_type : " . $ar_transaction_header->$document_type_number .  "</li>";
$header_info_statement .= "<li>" . gettext('Revision') . " : " . $ar_transaction_header->$document_revision_number . "</li>";
$header_info_statement .= "<li>" . gettext('Sales Person') . " : " . $ar_transaction_header->$document_showVar1 . "</li>";
$header_info_statement .= "<li>" . gettext('Currency') . " : " . $ar_transaction_header->$document_showVar2 . "</li>";
$header_info_statement .= "<li>" . gettext('Payment Term') . " : " . $ar_transaction_header->payment_term_id . "</li>";
$header_info_statement .= "<li>" . gettext('Amount') . " : " . $ar_transaction_header->$document_showVar4 . " & " . gettext('Tax') . " : " . $ar_transaction_header->tax_amount . "</li>";
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
// $external_entiry_info .= "<li> $address_value </li>";
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
			<th><?php echo gettext('Line') ?> #</th>
			<th><?php echo gettext('Type') ?></th>
			<th><?php echo gettext('Item Number/Description') ?></th>
			<th><?php echo gettext('Unit Price') ?></th>
			<th><?php echo gettext('Line Quantity') ?></th>
			<th><?php echo gettext('Line Price') ?></th>
			<th><?php echo gettext('Tax Amount') ?></th>
			<th><?php echo gettext('Order Number') ?></th>
			<th><?php echo gettext('Order Line') ?>#</th>
		 </tr>
		</thead>
		<tbody>
		 <?php
		 $count = 0;
		 foreach ($ar_transaction_line_object as $ar_transaction_line) {
			 ?>
			 <tr class="line_rows">
				<td><?php echo $$class_second->line_number; ?></td>
				<td><?php
				 $line_type = option_line::find_by_optionId_lineCode(133, $$class_second->line_type);
				 echo $line_type->option_line_value;
				 ?></td>
				<td><?php echo $$class_second->item_number . ' : ' . $$class_second->item_description; ?></td>
				<td><?php echo $$class_second->inv_unit_price; ?></td>
				<td><?php echo $$class_second->inv_line_quantity; ?></td>
				<td><?php echo $$class_second->inv_line_price; ?></td>
				<td><?php echo $$class_second->tax_amount; ?></td>
				<td><?php echo $$class_second->so_order_number; ?></td>
				<td><?php echo $$class_second->so_line_number; ?></td>
			 </tr>
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
//echo $html;
// send the captured HTML from the output buffer to the mPDF class for processing
$mpdf->WriteHTML($html);
download_send_headers("ar_transaction_print" . date("Y-m-d") . ".pdf");
$mpdf->Output();
exit;
?>
