<?php
$module_info = [
		array(
				"module" => "site_control",
				"class" => "site_control_header",
				"key_field" => "item_id",
				"primary_column" => "site_control_header_id"
		)
];
$pageTitle = " BOM - Find all BOMs ";
$view_path = "site_control_view";
$update_path = "site_control";
$extra_path1 = "indented_site_control";
$extra_path1_msg = "Indented BOM";
?>
<?php include_once("../../include/basics/header.inc"); ?> 
<script type='text/javascript' src="site_control.js" ></script>
<?php
$search_form = search::search_form('site_control_header', 'site_controls', 'site_control_search');
if (!empty($search_result)) {
 $search_result_statement = search::search_result('site_control', $column_array, $search_result, $primary_column, $view_path,'', 'Update', $extra_path1, $extra_path1_msg );
}

if (!empty($pagination)) {
 $pagination_statement = $pagination->show_pagination($pagination, 'site_controls', $pageno, $query_string);
}
?>
<?php require_once(INC_BASICS . DS . "list_page.inc"); ?>