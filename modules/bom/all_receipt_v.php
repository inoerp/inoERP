<?php
$module_info = [
		array(
				"module" => "inventory",
				"class" => "all_receipt_v",
				"key_field" => "item_description",
				"primary_column" => "receipt_header_id"
		)
];
$pageTitle = " Receipt - Find all Receipts ";
$view_path = "receipt_view";

?>
<?php 
include_once("../../../include/basics/header.inc"); ?> 
<script type='text/javascript' src="receipt.js" ></script>
<?php

$search_form = search::search_form('all_receipt_v', 'all_receipt_v', 'search_all_receipt_v');
	if (!empty($search_result)) {
	 	 $search_result_statement = search::search_result('receipt', $column_array, $search_result, $primary_column, $view_path, 'Y', 'Update');
	}
if(!empty($pagination)){
$pagination_statement = $pagination->show_pagination($pagination, 'all_receipt_v', $pageno, $query_string );
}
?>
<?php  require_once(INC_BASICS . DS ."list_page.inc"); ?>