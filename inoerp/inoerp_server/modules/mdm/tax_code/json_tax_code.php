<?php 

require_once __DIR__.'/../../../includes/basics/wloader.inc';
include_once(__DIR__.'/../../../../inoerp_server/includes/basics/basics.inc');


if (!empty($_GET['org_id']) && !empty($_GET['in_out_tax']) && ($_GET['find_all_tax'] = 1)) {
 echo '<div id="json_tax_code_find_all">';
 if ($_GET['in_out_tax'] == 'IN') {
	$all_tax_codes = mdm_tax_code::find_all_inTax_by_inv_org_id($_GET['org_id']);
  if(!$all_tax_codes){
   $all_tax_codes = mdm_tax_code::find_all_inTax_by_bu_org_id($_GET['org_id']);
  }
 } elseif ($_GET['in_out_tax'] == 'OUT') {
	$all_tax_codes = mdm_tax_code::find_all_outTax_by_inv_org_id($_GET['org_id']);
    if(!$all_tax_codes){
   $all_tax_codes = mdm_tax_code::find_all_outTax_by_bu_org_id($_GET['org_id']);
  }
 }
 if (empty($all_tax_codes)) {
	return false;
 } else {
	foreach ($all_tax_codes as $tax_code) {
	 $tax_class = (!empty($tax_code->percentage)) ? 'p_' . $tax_code->percentage : 'a_' . $tax_code->tax_amount;
	 echo '<option data-percentage="'.$tax_code->percentage.'"  data-amount="'.$tax_code->tax_amount.'" '
    . ' class="' . $tax_class . '"  value="' . $tax_code->mdm_tax_code_id . '"';
	 echo '>' . $tax_code->tax_code . '</option>';
	}
 }
 echo '</div>';
}
?>

