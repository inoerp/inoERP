<?php include_once("../../../include/basics/header.inc"); ?>
<script src="customer.js"></script>

<div id="json_save_header"> <?php json_save('ar', 'ar_customer', 'customer_number', 'ar_customer_id'); ?></div>
<div id="json_save_line"> <?php json_saveLineData('ar', 'ar_customer_site', 'customer_site_name', 'ar_customer_site_id'); ?></div>
<div id="json_delete_line"> <?php json_delete('customer'); ?> </div>

<div id="customer_attachment">
 <div id="customer_header_level_attachement">
	<?php
	if (!empty($_GET['ar_customer_id'])) {
	 $ar_customer_id = $_GET['ar_customer_id'];
	 $customer_file = file::find_by_reference_table_and_id('customer', $ar_customer_id);
	 echo file::attachment_statement($customer_file);
	}
	?>
 </div>
</div>

<div id="customer_bu_addresses">
 <?php
 if ((!empty($_GET['ar_customer_id'])) && (!empty($_GET['org_id']))) {
	$ar_customer_id = $_GET['ar_customer_id'];
	$org_id = $_GET['org_id'];
	$customer_bu_assigment = customer_bu::find_by_orgId_customerId($ar_customer_id, $org_id);
	echo "<div id=\"bill_to_id\">$customer_bu_assigment->org_billto_id</div>";
	echo "<div id=\"bill_to_address\">" . address::find_by_id($customer_bu_assigment->org_billto_id)->address_name . "</div>";
	echo "<div id=\"ship_to_id\">$customer_bu_assigment->org_shipto_id</div>";
	echo "<div id=\"ship_to_address\">" . address::find_by_id($customer_bu_assigment->org_shipto_id)->address_name . "</div>";
 }
 ?>
</div>

<div id="json_customer_sites_all">
 <div id="json_customerSites_find_all"><?php
 if ((!empty($_GET['ar_customer_id'])) && ($_GET['find_all_sites'] = 1)) {
	$ar_customer_id = $_GET['ar_customer_id'];
	if (!empty($_GET['org_id'])) {
	 $org_id = $_GET['org_id'];
	 if (customer_bu::validate_customerBuAssignment($ar_customer_id, $org_id) == 1) {
		echo form::select_field_from_object('ar_customer_site_id', customer_site::find_all_sitesOfCustomer($ar_customer_id), 'ar_customer_site_id', 'customer_site_name', '', 'ar_customer_site_id');
	 } else {
		echo "<div class=\"errorMsg\">Customer BU Assignment doesn't exists</div>";
	 }
	} else {
	 echo form::select_field_from_object('ar_customer_site_id', customer_site::find_all_sitesOfCustomer($ar_customer_id), 'ar_customer_site_id', 'customer_site_name', '', 'ar_customer_site_id');
	}
 }
 ?></div>
</div>


<!--//customer site details-->
<div id="json_customer_site_details">
 <?php
 if ((!empty($_GET['ar_customer_site_id'])) && ($_GET['find_site_details'] = 1)) {
	$ar_customer_site_id = $_GET['ar_customer_site_id'];
	$customer_site_details = customer_site::find_by_id($ar_customer_site_id);
	?>
  <div id = "json_customer_site_currency">
	 <?php echo form::select_field_from_object('currency', option_header::currencies(), 'option_line_code', 'option_line_code', $customer_site_details->currency, 'currency'); ?>
  </div>
  <div id= "json_customer_site_payment_terms">
	 <?php echo form::select_field_from_object('payment_term_id', payment_term::find_all(), 'payment_term_id', 'payment_term', $customer_site_details->payment_term_id, 'payment_term_id'); ?>
  </div>
 <?php }
 ?>
</div>


<?php include_template('footer.inc') ?>