<?php
if (!empty($_GET['user_group_code'])) {
 $user_group_code_h = $_GET['user_group_code'];
 $user_group_code_description = option_line::find_by_optionId_lineCode('223',$user_group_code_h)->description;
 $user_group_access_object = user_group_access::find_by_groupCode($user_group_code_h);
} else {
 $user_group_code_h = "";
 $user_group_code_description = '';
}

if(empty($user_group_access_object)){
 $user_group_access_object = [new user_group_access()];
}

$pageno = !empty($_GET['pageno']) ? $_GET['pageno'] : 1;
$per_page = !empty($_GET['per_page']) ? $_GET['per_page'] : 10;
$total_count = count($user_group_access_object);
$pagination = new pagination($pageno, $per_page, $total_count);
$pagination->setProperty('_path', 'form');
$position = ($pageno - 1) * $per_page;

?>