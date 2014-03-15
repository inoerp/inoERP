<?php include_once("../../../include/basics/header.inc"); ?>
<script src="business_org.js"></script>

<div id="json_save_header">
 <?php
 if (!empty($_POST['headerData'])) {
	$postArray = get_postArray_From_jqSearializedArray($_POST['headerData']);
	$postArray['submit_business_org'] = '1';
	$_POST = $postArray;

	$business_org = Pre_Loading_Function('org', 'business_org', 'org_id', 'business_id');
	if (!empty($business_org->business_id)) {
	 echo '<div class="message">Header is sucessfully saved! </div>';
	 echo '<div id="headerId">' . $business_org->business_id . '</div>';
	} else {
	 echo ' Error code:  ! ';
	}
 }
 ?>
</div>

  <?php include_template('footer.inc') ?>