<?php
$module_info = [
		array(
				"module" => "bom",
				"class" => "bom_header",
				"key_field" => "item_id",
				"primary_column" => "bom_header_id"
		)
];
$pageTitle = " BOM - Find all BOMs ";
$view_path = "bom_view";
$update_path = "bom";
$extra_path1 = "indented_bom";
$extra_path1_msg = "Indented BOM";
?>
<?php include_once("../../include/basics/header.inc"); ?> 
<script type='text/javascript' src="bom.js" ></script>
<?php
$search_form = search::search_form('bom_header', 'boms', 'bom_search');
if (!empty($search_result)) {
 $search_result_statement = search::search_result('bom', $column_array, $search_result, $primary_column, $view_path,'', 'Update', $extra_path1, $extra_path1_msg );
}

if (!empty($pagination)) {
 $pagination_statement = $pagination->show_pagination($pagination, 'boms', $pageno, $query_string);
}
?>
<?php require_once(INC_BASICS . DS . "list_page.inc"); ?>