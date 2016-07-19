<?php
if (!empty($_GET['role_code'])) {
 $role_code_h = $_GET['role_code'];
 $role_code_description = option_line::find_by_optionId_lineCode('119',$role_code_h)->description;
 $role_access_object = role_access::find_by_roleCode($role_code_h);
} else {
 $role_code_h = "";
 $role_code_description = '';
}

if(empty($role_access_object)){
 $role_access_object = [new role_access()];
}

$pageno = !empty($_GET['pageno']) ? $_GET['pageno'] : 1;
$per_page = !empty($_GET['per_page']) ? $_GET['per_page'] : 10;
$total_count = count($role_access_object);
$pagination = new pagination($pageno, $per_page, $total_count);
$pagination->setProperty('_path', 'form');
$position = ($pageno - 1) * $per_page;

?>