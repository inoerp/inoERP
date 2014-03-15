<?php include_once("../../../includes/basics/basics.inc"); ?>
<div id="json_save_header">
 <?php
 if (!empty($_POST['headerData'])) {
	$postArray = get_postArray_From_jqSearializedArray($_POST['headerData']);
	$postArray['submit_inventory'] = '1';
	$_POST = $postArray;

	$inventory = Pre_Loading_Function('org', 'inventory', 'org_id', 'inventory_id');
	if (!empty($inventory->inventory_id)) {
	 echo '<div class="message">Header is sucessfully saved! </div>';
	 echo '<div id="headerId">' . $inventory->inventory_id . '</div>';
	} else {
	 echo ' Error code:  ! ';
	}
 }
 ?>
</div>

<div id="json_inventory_ac_all">
 <?php
 if ((!empty($_GET['ship_to_inventory'])) && ($_GET['find_account_details'] = 1)) {
	$org_id = $_GET['ship_to_inventory'];
	echo '<br/> in 1';
	$in = new inventory();
	$inventory_i = $in->findBy_org_id($org_id);
  $cc = new coa_combination;
	
	echo '<div id="json_ap_accrual_ac_id">' . $cc->findBy_id($inventory_i->inv_ap_accrual_ac_id)->combination. '</div>';
	echo '<div id="json_material_ac_id">' . $cc->findBy_id($inventory_i->material_ac_id)->combination . '</div>';
	echo '<div id="json_inv_ppv_ac_id">' . $cc->findBy_id($inventory_i->inv_ppv_ac_id)->combination . '</div>';
 }
 ?>
</div>