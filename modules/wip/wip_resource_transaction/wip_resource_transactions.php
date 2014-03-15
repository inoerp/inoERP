<?php
$module_info = [
		array(
				"module" => "wip",
				"class" => "wip_resource_transaction",
				"key_field" => "wo_routing_line_id",
				"primary_column" => "wip_resource_transaction_id"
		)
//	=
];

$pageTitle = " WO Resource Transaction ";
$view_path = "wip_resource_transaction_view";
$update_path = 'A';
?>
<?php include_once("../../../include/basics/header.inc"); ?> 
<script type='text/javascript' src="wip_resource_transaction.js" ></script>
<?php
$search_form = search::search_form('wip_resource_transaction', 'wip_resource_transactions', 'wip_resource_transaction_search');
if(!empty($pagination)){
$pagination_statement = $pagination->show_pagination($pagination, 'wip_resource_transactions', $pageno, $query_string );
}


?>
<?php require_once(INC_BASICS . DS ."list_page.inc"); ?>