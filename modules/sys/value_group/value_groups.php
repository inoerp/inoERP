<?php
if (!empty($_GET['sql'])) {
 $sql = $_GET['sql'];
}
$module_info = [
		array(
				"module" => "sys",
				"class" => "sys_value_group_header",
				"key_field" => "value_group",
				"primary_column" => "sys_value_group_header_id"
		)
];
$pageTitle = " Find and view all COA Combinations  ";
$view_path = "value_group_view";
?>
<?php include_once("../../../include/function/loader.inc"); ?>
<script src="value_group.js"></script>
<?php

$search_form = search::search_form('sys_value_group_header', 'value_groups', 'value_group_search');

if (!empty($search_result)) {
 $search_result_statement = search::search_result('value_group', $column_array, $search_result, $primary_column, $view_path, 'Y', 'Update Option');
}

if (!empty($pagination)) {
 $pagination_statement = $pagination->show_pagination($pagination, 'value_groups', $pageno, $query_string);
}
?>

<?php // require_once('options_template.php') ?>
<?php require_once(INC_BASICS . DS . "list_page.inc"); ?>
