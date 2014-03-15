<?php
$extension = 'category';
$key_field = 'category';
//$primary_column = "category_id";
$categoryTitle = " Category - Create & update contents ";
$required_field_flag = 1;
?>
<?php include_once("../../include/basics/header.inc"); ?>
<script src="category.js"></script>
<?php
if(!empty($_GET['new_category_parent_id'])){
 $new_category_parent_id = $_GET['new_category_parent_id'];
}else{
 $new_category_parent_id="";
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

<?php require_once('category_template.php') ?>
