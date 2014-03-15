<?php
$module_info = [
		array(
				"module" => "po",
				"class" => "all_po_v",
				"key_field" => "shipment_number",
				"primary_column" => "po_header_id"
		)
];
$pageTitle = " PO - Find all POs ";
$view_path = "po_view";
$update_path = "po";
?>
<?php include_once("../../include/basics/header.inc"); ?> 
<script type='text/javascript' src="po.js" ></script>
<?php

$search_form = search::search_form('all_po_v', 'all_po_v', 'search_all_po_v');
	if (!empty($search_result)) {
//	 $search_result = po_header::instantiate_extra_fields($search_result);
//	 echo "<pre>";
//	 print_r($search_result);
	 	 $search_result_statement = search::search_result('po', $column_array, $search_result, $primary_column, $view_path, 'po');
//		 $return_value['search_result'] = $search_result;
	}
if(!empty($pagination)){
$pagination_statement = $pagination->show_pagination($pagination, 'pos', $pageno, $query_string );
}
?>
<?php  require_once(INC_BASICS . DS ."list_page.inc"); ?>