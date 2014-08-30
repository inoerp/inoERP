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

?>
<?php 
$_GET['po_status']='Approved';
include_once("../../include/basics/header.inc"); ?> 
<script type='text/javascript' src="po.js" ></script>
<?php

$search_form = search::search_form('all_po_v', 'expected_receipts', 'search_expected_receipts');
	if (!empty($search_result)) {
//	 $search_result = po_header::instantiate_extra_fields($search_result);
//	 echo "<pre>";
//	 print_r($search_result);
	 	 $search_result_statement = search::search_result('po_receipt', $column_array, $search_result, $primary_column, $view_path, 'Y', 'Receive');
//		 $return_value['search_result'] = $search_result;
	}
if(!empty($pagination)){
$pagination_statement = $pagination->show_pagination($pagination, 'expected_receipts', $pageno, $query_string );
}
?>
<?php  require_once(INC_BASICS . DS ."list_page.inc"); ?>