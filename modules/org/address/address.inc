<?php
$module_info = [
		array(
				"module" => "address",
				"class" => "address",
				"key_field" => "address_name",
				"primary_column" => "address_id"
		)
];
$pageTitle = " Address - Create & Update all addresses ";
$view_path = "address_view";
?>
<?php include_once("../../../include/basics/header.inc"); ?> 
<script src="address.js"></script>
<?php 
if (!empty($msg)) {
 $show_message = '<div id="dialog_box">';
 foreach ($msg as $key => $value) {
	$x = $key + 1;
	$show_message .= 'Message ' . $x . ' : ' . $value . '<br />';
 }
 $show_message .= '</div>';
}
?>
