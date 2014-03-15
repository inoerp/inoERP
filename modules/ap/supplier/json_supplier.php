<?php include_once("../../../includes/basics/basics.inc"); ?>
<?php
if ((!empty($_REQUEST['action'])) && ($_REQUEST['action'] = 'search')) {
 if (empty($_REQUEST['term'])) {
	exit;
 }
 $supplier_name = $_REQUEST['term'];
 if (!empty($_REQUEST['primary_column1'])) {
	$primary_column1 = $_REQUEST['primary_column1'];
 }
 $supplier = new supplier();
 $supplier->supplier_name = $supplier_name;
 if(!empty($primary_column1)){
	$supplier->org_id = $primary_column1;
	$data = $supplier->searchBy_supplierName_orgId();
 }else{
 $data = $supplier->searchBy_supplier_name();
 }
// JSON data
 echo json_encode($data);
 flush();

 //return from this file
 return;
}
?>

<div id="json_delete_line"> <?php json_delete('supplier'); ?> </div>
<div id="supplier_attachment">
 <div id="supplier_header_level_attachement">
	<?php
	if (!empty($_GET['supplier_id'])) {
	 $supplier_id = $_GET['supplier_id'];
	 $supplier_file = file::find_by_reference_table_and_id('supplier', $supplier_id);
	 echo file::attachment_statement($supplier_file);
	}
	?>
 </div>
</div>
<div id="supplier_bu_addresses">
 <?php
 if ((!empty($_GET['supplier_id'])) && (!empty($_GET['org_id']))) {
	$supplier_id = $_GET['supplier_id'];
	$org_id = $_GET['org_id'];
	 $sbu = new supplier_bu();
	$supplier_bu_assigment = $sbu->findBy_orgId_supplierId($org_id, $supplier_id);
	echo "<div id=\"bill_to_id\">$supplier_bu_assigment->org_billto_id</div>";
	echo "<div id=\"bill_to_address\">" . address::find_by_id($supplier_bu_assigment->org_billto_id)->address_name . "</div>";
	echo "<div id=\"ship_to_id\">$supplier_bu_assigment->org_shipto_id</div>";
	echo "<div id=\"ship_to_address\">" . address::find_by_id($supplier_bu_assigment->org_shipto_id)->address_name . "</div>";
 }
 ?>
</div>
<div id="json_supplier_sites_all">
 <div id="json_supplierSites_find_all"><?php
	if ((!empty($_GET['supplier_id'])) && ($_GET['find_all_sites'] = 1)) {
	 $supplier_id = $_GET['supplier_id'];
	 if (!empty($_GET['org_id'])) {
		$org_id = $_GET['org_id'];
		if (supplier_bu::validate_supplierBuAssignment($supplier_id, $org_id) == 1) {
		 echo form::select_field_from_object('supplier_site_id', supplier_site::find_all_sitesOfSupplier($supplier_id), 'supplier_site_id', 'supplier_site_name', '', 'supplier_site_id');
		} else {
		 echo "<div class=\"errorMsg\">Supplier BU Assignment doesn't exists</div>";
		}
	 } else {
		echo form::select_field_from_object('supplier_site_id', supplier_site::find_all_sitesOfSupplier($supplier_id), 'supplier_site_id', 'supplier_site_name', '', 'supplier_site_id');
	 }
	}
	?></div>
</div>
<!--//supplier site details-->
<div id="json_supplier_site_details">
 <?php
 if ((!empty($_GET['supplier_site_id'])) && ($_GET['find_site_details'] = 1)) {
	$supplier_site_id = $_GET['supplier_site_id'];
	$supplier_site_details = supplier_site::find_by_id($supplier_site_id);
	?>
  <div id = "json_supplier_site_currency">
	 <?php echo form::select_field_from_object('currency', option_header::currencies(), 'option_line_code', 'option_line_code', $supplier_site_details->currency, 'currency'); ?>
  </div>
  <div id= "json_supplier_site_payment_terms">
	 <?php echo form::select_field_from_object('payment_term_id', payment_term::find_all(), 'payment_term_id', 'payment_term', $supplier_site_details->payment_term_id, 'payment_term_id'); ?>
  </div>
 <?php }
 ?>
</div>