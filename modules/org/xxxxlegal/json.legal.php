<?php include_once("../../../include/basics/header.inc"); ?>
<script src="legal.js"></script>

<div id="json_save_header">
 <?php
 if (!empty($_POST['headerData'])) {
	$postArray = get_postArray_From_jqSearializedArray($_POST['headerData']);
	$postArray['submit_legal'] = '1';
	$_POST = $postArray;

	$legal = Pre_Loading_Function('org', 'legal', 'org_id', 'legal_id');
	if (!empty($legal->legal_id)) {
	 echo '<div class="message">Header is sucessfully saved! </div>';
	 echo '<div id="headerId">' . $legal->legal_id . '</div>';
	} else {
	 echo ' Error code:  ! ';
	}
 }
 ?>
</div>

  <?php include_template('footer.inc') ?>