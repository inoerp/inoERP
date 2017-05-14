<?php 
require_once __DIR__.'/../../../includes/basics/wloader.inc';
include_once(__DIR__.'/../../../../inoerp_server/includes/basics/basics.inc');


if ((!empty($_REQUEST['action'])) && ($_REQUEST['action'] = 'search')) {
 if (empty($_REQUEST['term'])) {
	exit;
 }
 $customer_name = $_REQUEST['term'];
 if (!empty($_REQUEST['primary_column1'])) {
	$primary_column1 = $_REQUEST['primary_column1'];
 }
 $customer = new mdm_bank();
 $customer->customer_name = $customer_name;
 if (!empty($primary_column1)) {
	$customer->org_id = $primary_column1;
	$data = $customer->searchBy_customerName_orgId();
 } else {
	$data = $customer->searchBy_customer_name();
 }
// JSON data
 echo json_encode($data);
 flush();

 //return from this file
 return;
}
 if ((!empty($_GET['mdm_bank_id'])) && (!empty($_GET['org_id']))) {
	echo '<div id="customer_bu_addresses">';
	$mdm_bank_id = $_GET['mdm_bank_id'];
	$org_id = $_GET['org_id'];
	$customer_bu_assigment = mdm_bank_bu::find_by_orgId_customerId($mdm_bank_id, $org_id);
 echo '</div>';
 }

 if ((!empty($_GET['mdm_bank_id'])) && ($_GET['find_all_sites'] = 1)) {
	 echo '<div id="json_customer_sites_all">';
	 $mdm_bank_id = $_GET['mdm_bank_id'];
	 if (!empty($_GET['org_id'])) {
		$org_id = $_GET['org_id'];
		$acs = new mdm_bank_site();

		if (mdm_bank_bu::validate_customerBuAssignment($mdm_bank_id, $org_id) == 1) {
		 echo '<div id="json_customerSites_find_all">'.
						 form::select_field_from_object('mdm_bank_site_id', $acs->findBy_parentId($mdm_bank_id), 'mdm_bank_site_id', 'customer_site_name', '', 'mdm_bank_site_id')
						 .'</div>';
		 $arcbu = new mdm_bank_bu();
		 $arcbu->mdm_bank_id = $mdm_bank_id;
		 $arcbu->org_id = $org_id;
		 $arcbu_i = $arcbu->findBy_orgId_customerId();
		 echo "<div id='receivable_ac_id'>".coa_combination::find_by_id($arcbu_i->receivable_ac_id)->combination.'</div>';
		} else {
		 echo "<div class=\"errorMsg\">Customer BU Assignment doesn't exists</div>";
		}
	 } else {
		echo form::select_field_from_object('mdm_bank_site_id', mdm_bank_site::find_all_sitesOfCustomer($mdm_bank_id), 'mdm_bank_site_id', 'customer_site_name', '', 'mdm_bank_site_id');
	 }
	 echo '</div>';
	}

//customer site details
 if ((!empty($_GET['mdm_bank_site_id'])) && ($_GET['find_site_details'] = 1)) {
	$customer_site_details = mdm_bank_site::find_by_id($_GET['mdm_bank_site_id']);
	echo header('Content-Type: application/json');
	echo json_encode($customer_site_details);
 }
 ?>