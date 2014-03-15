<?php
$module_info = [
		array(
				"module" => "bom",
				"class" => "bom_routing_header",
				"key_field" => "item_id",
				"primary_column" => "bom_routing_header_id"
		)
];
$pageTitle = " Routings - Find all Routings ";
$view_path = "bom_routing_view";
$update_path = "bom_routing";
?>
<?php include_once("../../../include/basics/header.inc"); ?> 
<script type='text/javascript' src="bom_routing.js" ></script>
<?php
//$search_form = search::search_form('all_bom_routing_v', 'all_bom_routing_v', 'search_all_bom_routing_v');
//	if (!empty($search_result)) {
//	 	 $search_result_statement = search::search_result('bom_routing', $column_array, $search_result, $primary_column, $view_path, 'bom_routing');
//	}
//if(!empty($pagination)){
//$pagination_statement = $pagination->show_pagination($pagination, 'bom_routings', $pageno, $query_string );
//}
//?>

<?php
$search_form = search::search_form('bom_routing_header', 'bom_routings', 'bom_routing_search');
if (!empty($search_result)) {
 $search_result_statement = search::search_result('bom_routing', $column_array, $search_result, $primary_column, $view_path,'', 'Update' );
}

if (!empty($pagination)) {
 $pagination_statement = $pagination->show_pagination($pagination, 'bom_routings', $pageno, $query_string);
}
?>
<?php require_once(INC_BASICS . DS . "list_page.inc"); ?>