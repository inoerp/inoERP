<?php
if (!empty($_GET['role_code'])) {
 $role_code_h = $_GET['role_code'];
 $role_code_description = option_line::find_by_optionId_lineCode('119',$role_code_h)->description;
} else {
 $role_code_h = "";
 $role_code_description = '';
}

$role_access_object = [];

if (!(empty($search_result))) {
 foreach ($search_result as $object) {
	array_push($role_access_object, $object);
 }
 if (!empty($pagination)) {
	$pagination->setProperty('_path', 'form');
	$pagination_statement = $pagination->show_pagination();
 }
} else if (!(empty($$class))) {
 array_push($role_access_object, $$class);
} else {
 $role_access = new role_access();
 array_push($role_access_object, $role_access);
}

?>
