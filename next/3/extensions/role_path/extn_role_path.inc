<?php
$roles = role_path::roles();
$allPaths = path::find_all();

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

?>
