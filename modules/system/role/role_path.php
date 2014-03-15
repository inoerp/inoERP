<?php
$module_info = [
		array(
				"module" => "role",
				"class" => "role_path",
				"key_field" => "option_type",
				"primary_column" => "path_id"
		)
];
$pageTitle = " Role path - Create & Update role path ";
?>
<?php include_once("../../../include/basics/header.inc"); ?>
<script src="role_path.js"></script>
<?php
$roles = role_path::roles();
$allPaths = path::find_all();
//echo'checking------------------------------------';
//echo'<pre>';
//print_r($role_path);
//echo'<pre>';

if(!empty($_GET['role_id'])){
 $role_id = $_GET['role_id'];
}else{
 $role_id = "";
}

if(!empty($role_id)){
 $role = option_line::find_by_id($role_id);
 $role_path_object = role_path::find_by_roleId($role_id);
   if (count($role_path_object) == 0) {
	$role_path = new role_path();
	$role_path_object = array();
	array_push($role_path_object, $role_path);
 }
}else{
 $role = new option_line();
 	$role_path = new role_path();
	$role_path_object = array();
	array_push($role_path_object, $role_path);
}
//
//echo '<pre>';
//print_r($role_path_object);
//echo '<pre>';

if (!empty($msg)) {
 $show_message = '<div id="dialog_box">';
  foreach ($msg as $key => $value) {
   $x = $key + 1;
   $show_message .= 'Message ' . $x . ' : ' . $value . '<br />';
  }
 $show_message .= '</div>';
}
?>

<?php require_once('role_path_template.php') ?>
