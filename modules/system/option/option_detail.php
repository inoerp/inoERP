<?php 
$module_info = [
	array(
			"module"=>"option",
			"class"=>"option_detail",
			"key_field"=>"option_detail_value",
			"primary_column"=>"option_detail_id"			
			)
];
$pageTitle = " Option Detail - Create & Update all Option detail values "; 

?>
<?php include_once("../../../include/basics/header.inc"); ?>
<script src="option.js"></script>

 <?php

 if(!empty($_GET["option_line_id"])){
	$option_line_id = $_GET["option_line_id"];
 }elseif(!empty($_POST["option_line_id"][0]))
	{
	$option_line_id = $_POST["option_line_id"][0];
 } elseif(!empty($_POST["option_line_id"]))
	{
	$option_line_id = $_POST["option_line_id"];
 }else{
	exit("unable to find option line value!!");
 }
 
 if (!empty($option_line_id)) {
	$option_line_object = option_line::find_by_id($option_line_id);
  $option_header_object = option_header::find_by_id($option_line_object->option_header_id);
	$option_detail_object = option_detail::find_by_option_line_id($option_line_id);
  if (count($option_detail_object) == 0) {
    $option_detail = new option_detail();
	 $option_detail_object = array();
	 array_push($option_detail_object, $option_detail);
  }
}

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
<?php require_once('option_detail_template.php') ?>
