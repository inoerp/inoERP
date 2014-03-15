<?php
$module_info = [
		array(
				"module" => "sys",
				"class" => "sys_value_group_header",
				"key_field" => "value_group",
				"primary_column" => "sys_value_group_header_id"
		)
];
$pageTitle = " Find and view all value groups  ";
$view_path = "value_group_view";
?>
<?php include_once("../../../include/basics/header.inc"); ?>
<script src="value_group.js"></script>
<?php
$search_form = search::search_form('sys_value_group_header', 'find_value_group', 'wip_value_group');
if(!empty($pagination)){
$pagination_statement = $pagination->show_pagination($pagination, 'find_wip_wo', $pageno, $query_string );
}

//include_find_page();
?>
<?php  require_once(INC_BASICS . DS ."find_page.inc") ?>