<?php $show_submit_button = 1 ; ?>
<?php include_once("option.inc"); ?>
<?php
//set the option id of option line as 0
//@required : To create line form for new entry
//@required : To create line form where only header is entered
$option_id_l = 0;
?>

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

<!--   end of structure-->
<?php require_once('option_template.php') ?>
