<?php include_once("../../../include/basics/header.inc"); ?>
<script src="enterprise.js"></script>

<div id="json_save_header">
 <?php
 if (!empty($_POST['headerData'])) {
	$postArray = get_postArray_From_jqSearializedArray($_POST['headerData']);
	$postArray['submit_enterprise'] = '1';
	$_POST = $postArray;

	$enterprise = Pre_Loading_Function('org', 'enterprise', 'org_id', 'enterprise_id');
	if (!empty($enterprise->enterprise_id)) {
	 echo '<div class="message">Header is sucessfully saved! </div>';
	 echo '<div id="headerId">' . $enterprise->enterprise_id . '</div>';
	} else {
	 echo ' Error code:  ! ';
	}
 }
 ?>
</div>

  <?php include_template('footer.inc') ?>