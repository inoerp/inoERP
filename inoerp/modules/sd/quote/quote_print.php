<?php
include_once("../../../includes/basics/basics.inc");
include("../../../tparty/mpdf/mpdf.php");
$mpdf = new mPDF('c');
ob_start();
global $si;

echo '<link href="../../../themes/default/print.css" media="all" rel="stylesheet" type="text/css" />';
echo '<link href="quote.css" media="all" rel="stylesheet" type="text/css"  />';
$sd_quote_header = new sd_quote_header();
$class = $class_first = 'sd_quote_header';
$$class = $$class_first = &$sd_quote_header;
$class_second = 'sd_quote_line';
$$class_second = &$sd_quote_line;

if (!empty($_GET["sd_quote_header_id"])) {
 $sd_quote_header_id = ($_GET["sd_quote_header_id"]);
 $sd_quote_header->findBy_id($sd_quote_header_id);
}

if (!empty($sd_quote_header_id)) {
 $sd_quote_line_object = sd_quote_line::find_by_sd_quote_headerId($sd_quote_header_id);
 //assign the item number to the object
 foreach ($sd_quote_line_object as &$sd_quote_lines) {
  if (!empty($sd_quote_lines->item_id_m)) {
   $item = item::find_by_id($sd_quote_lines->item_id_m);
   $sd_quote_lines->item_number = $item->item_number;
  }
 }
 if (count($sd_quote_line_object) == 0) {
  $sd_quote_line = new sd_quote_line;
  $sd_quote_line_object = array();
  array_push($sd_quote_line_object, $sd_quote_line);
 }
}
?>


<?php
$primary_column = 'sd_quote_header_id';
$document_type = "Sales Quote";
$document_type_number = "quote_number";

$document_showVar1 = "sales_person_employee_id";
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
$header_info_statement .= "<li>$document_type : " . $sd_quote_header->$document_type_number . "</li>";
$header_info_statement .= "<li>" . gettext('Sales Person') . " : " . $sd_quote_header->$document_showVar1 . "</li>";
$header_info_statement .= "<li>" . gettext('Currency') . " : " . $sd_quote_header->$document_showVar2 . "</li>";
$header_info_statement .= "<li>" . gettext('Payment Term') . " : " . $sd_quote_header->payment_term_id . "</li>";
$header_info_statement .= "<li>" . gettext('Amount') . " : " . $sd_quote_header->$document_showVar4 . "</li>";
$header_info_statement .= "</ul>";


//row 1 - right side supplier/customer Info
$external_entiry_info = "";
if (!empty($$class->$external_entity_headerId)) {
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
   <table id="document_header_info">
    <tr>
     <td><?php echo!(empty($header_info_statement)) ? $header_info_statement : ""; ?></td>
     <td><?php echo!(empty($external_entiry_info)) ? $external_entiry_info : ""; ?></td>
    </tr>
   </table>

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
     foreach ($sd_quote_line_object as $sd_quote_line) {
      ?>
      <tr class="line_rows">
       <td><?php echo $$class_second->line_number ; ?></td>
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
download_send_headers("sd_quote_print" . date("Y-m-d") . ".pdf", 'pdf_format');
$mpdf->Output();
exit;
?>
