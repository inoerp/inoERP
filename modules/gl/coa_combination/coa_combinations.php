<?php
$module_info = [
		array(
				"module" => "gl",
				"class" => "coa_combination",
				"key_field" => "coa_id",
				"primary_column" => "coa_combination_id"
		)
];
$pageTitle = " Find and view all COA combinations  ";
$view_path = "value_group_view";
?>
<?php include_once("../../../include/basics/header.inc"); ?>
<script src="coa_combination.js"></script>
<?php

$search_form = search::search_form('coa_combination', 'coa_combinations', 'coa_combination_search');

if (!empty($search_result)) {
 $search_result_statement = search::search_result('coa_combination', $column_array, $search_result, $primary_column, $view_path, 'Y', 'Update');
}

if (!empty($pagination)) {
 $pagination_statement = $pagination->show_pagination($pagination, 'value_groups', $pageno, $query_string);
}
?>

<?php // require_once('options_template.php') ?>
<?php require_once(INC_BASICS . DS . "list_page.inc"); ?>
