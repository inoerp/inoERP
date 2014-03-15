<?php
$module_info = [
		array(
				"module" => "om_so",
				"class" => "all_om_so_v",
				"key_field" => "shipment_number",
				"primary_column" => "om_so_header_id"
		)
];
$pageTitle = " PO - Find all POs ";
$view_path = "om_so_view";
$update_path = "om_so";
?>
<?php include_once("../../include/basics/header.inc"); ?> 
<script type='text/javascript' src="om_so.js" ></script>
<?php
$search_form = search::search_form('all_om_so_v', 'all_om_so_v', 'search_all_om_so_v');
	if (!empty($search_result)) {
	 	 $search_result_statement = search::search_result('om_so', $column_array, $search_result, $primary_column, $view_path, 'om_so');
	}
if(!empty($pagination)){
$pagination_statement = $pagination->show_pagination($pagination, 'om_sos', $pageno, $query_string );
}
?>
<?php  require_once(INC_BASICS . DS ."list_page.inc"); ?>