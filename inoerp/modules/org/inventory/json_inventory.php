<?php include_once("../../../includes/basics/basics.inc"); ?>
<div id="json_inventory_ac_all">
 <?php
  if ((!empty($_GET['ship_to_inventory'])) && ($_GET['find_account_details'] = 1)) {
   $org_id = $_GET['ship_to_inventory'];
   $in = new inventory();
   $inventory_i = $in->findBy_org_id($org_id);
   $cc = new coa_combination;

   if (!empty($cc->findBy_id($inventory_i->inv_ap_accrual_ac_id))) {
    echo '<div id="json_ap_accrual_ac_id">' . $cc->findBy_id($inventory_i->inv_ap_accrual_ac_id)->combination . '</div>';
   }
   if (!empty($cc->findBy_id($inventory_i->material_ac_id))) {
    echo '<div id="json_material_ac_id">' . $cc->findBy_id($inventory_i->material_ac_id)->combination . '</div>';
   }
   if (!empty($cc->findBy_id($inventory_i->inv_ppv_ac_id))) {
    echo '<div id="json_inv_ppv_ac_id">' . $cc->findBy_id($inventory_i->inv_ppv_ac_id)->combination . '</div>';
   }
  }
 ?>
</div>