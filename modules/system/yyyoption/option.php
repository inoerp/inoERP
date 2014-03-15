<?php 
$module_info = [
	array(
			"module"=>"option",
			"class"=>"option_header",
			"key_field"=>"option_type",
			"primary_column"=>"option_header_id"			
			),
	array(
			"module"=>"option",
			"class"=>"option_line",
			"key_field"=>"option_line_code",
			"primary_column"=>"option_line_id"
			)
];
$pageTitle = " Option - Create & Update all Options "; 

?>
<?php include_once("../../../include/basics/header.inc"); ?>
<script src="option.js"></script>
<?php
//set the option id of option line as 0
//@required : To create line form for new entry
//@required : To create line form where only header is entered
$option_id_l = 0;
?>

 <?php
 
 if(!empty($_GET["option_header_id"])){
	$option_header_id = htmlentities($_GET["option_header_id"]);
 }elseif(!empty($_POST["option_header_id"][0]))
	{
	$option_header_id = $_POST["option_header_id"][0];
 }else {
   $option_line = new option_line();
	 $option_line_object = array();
	 array_push($option_line_object, $option_line);
//	$field_array = option_line::$field_array;
}
 
if (!empty($option_header_id)) {
	$option_line_object = option_line::find_by_option_id($option_header_id);
  if (count($option_line_object) == 0) {
    $option_line = new option_line;
	 $option_line_object = array();
	 array_push($option_line_object, $option_line);
  }
} 

//if((!empty($_POST["option_header_id"])) && 
//    (empty($_POST['submit_header'])) &&
//    (empty($_POST['submit_line']))) {
//  $option_header_id = $_POST["option_header_id"];
//  $option = option_header::find_by_id($option_header_id);
//  $option_line_object = option_line::find_by_option_id($option_header_id);
//  if (count($option_line_object) == 0) {
//    $option_header_id = 0;
//  }
//
//}

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
