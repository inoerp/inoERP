<?php 
require_once __DIR__.'/../../../includes/basics/wloader.inc';
include_once(__DIR__.'/../../../../inoerp_server/includes/basics/basics.inc');

?>
<div id="json_inventory_ac_all">
 <?php
  if ((!empty($_GET['ship_to_inventory'])) && ($_GET['find_account_details'] = 1)) {
   $org_id = $_GET['ship_to_inventory'];
   $in = new inventory();
   $inventory_i = $in->findBy_org_id($org_id);
   $cc = new coa_combination;

   if (!empty($cc->findBy_id($inventory_i->inv_ap_accrual_ac_id))) {
    $inv_ap_accrual_ac = $cc->findBy_id($inventory_i->inv_ap_accrual_ac_id);
    echo '<div id="json_ap_accrual_ac_id" data-ac_id="' . $inv_ap_accrual_ac->coa_combination_id . '">' . $inv_ap_accrual_ac->combination . '</div>';
   }
   if (!empty($cc->findBy_id($inventory_i->material_ac_id))) {
    $material_ac = $cc->findBy_id($inventory_i->material_ac_id);
    echo '<div id="json_material_ac_id" data-ac_id="' . $material_ac->coa_combination_id . '">'. $material_ac->combination . '</div>';
   }
   if (!empty($cc->findBy_id($inventory_i->inv_ppv_ac_id))) {
    $inv_ppv_ac = $cc->findBy_id($inventory_i->inv_ppv_ac_id);
    echo '<div id="json_inv_ppv_ac_id" data-ac_id="' . $inv_ppv_ac->coa_combination_id . '">'. $inv_ppv_ac->combination . '</div>';
   }
  }
 ?>
</div>