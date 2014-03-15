<?php
$module_info = [
		array(
				"module" => "bom",
				"class" => "bom_standard_operation",
				"key_field" => "standard_operation",
				"primary_column" => "bom_standard_operation_id"
		)
//	=
];
$pageTitle = " Standard Operation - Create & Update all Standard Operations ";
$view_path = "bom_standard_operation_view";
?>
<?php include_once("../../../include/basics/header.inc"); ?> 
<script type='text/javascript' src="bom_standard_operation.js" ></script>
<?php
$search_form = search::search_form('bom_standard_operation', 'find_bom_standard_operation', 'bom_standard_operation_search');
if(!empty($pagination)){
$pagination_statement = $pagination->show_pagination($pagination, 'find_bom_standard_operation', $pageno, $query_string );
}

//include_find_page();
?>
<?php  require_once(INC_BASICS . DS ."find_page.inc") ?>