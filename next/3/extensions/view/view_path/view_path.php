<?php
$extension = 'view_path';
$key_field = 'column_name';
$primary_column = "view_path_id";
$pageTitle = " View - Create & update view path ";
$required_field_flag = 1;
?>
<?php include_once("../../../include/basics/header.inc"); ?>
<script src="view.js"></script>

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

<?php require_once('view_template.php') ?>
