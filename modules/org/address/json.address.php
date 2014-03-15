<?php include_once("../../../include/basics/header.inc"); ?>
<script src="address.js"></script>

<div id="json_save_header">
 <?php
 if (!empty($_POST['headerData'])) {
	$postArray = get_postArray_From_jqSearializedArray($_POST['headerData']);
	$postArray['submit_address'] = '1';
	$_POST = $postArray;

	$address = Pre_Loading_Function('address', 'address', 'address_name', 'address_id');
	if (!empty($address->address_id)) {
	 echo '<div class="message">Header is sucessfully saved! </div>';
	 echo '<div id="headerId">' . $address->address_id . '</div>';
	} else {
	 echo ' Error code:  ! ';
	}
 }
 ?>
</div>

  <?php include_template('footer.inc') ?>