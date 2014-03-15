<?php include_once("../../../include/basics/header.inc"); ?>
<script src="inventory.js"></script>

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

  <?php include_template('footer.inc') ?>