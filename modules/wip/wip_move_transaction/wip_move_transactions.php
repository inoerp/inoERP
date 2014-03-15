<?php
$module_info = [
		array(
				"module" => "wip",
				"class" => "wip_move_transaction",
				"key_field" => "wo_routing_line_id",
				"primary_column" => "wip_move_transaction_id"
		)
//	=
];

$pageTitle = " WO Move Transaction ";
$view_path = "wip_move_transaction_view";
$update_path = 'A';
?>
<?php include_once("../../../include/basics/header.inc"); ?> 
<script type='text/javascript' src="wip_move_transaction.js" ></script>
<?php
$search_form = search::search_form('wip_move_transaction', 'wip_move_transactions', 'wip_move_transaction_search');
if(!empty($pagination)){
$pagination_statement = $pagination->show_pagination($pagination, 'wip_move_transactions', $pageno, $query_string );
}


?>
<?php require_once(INC_BASICS . DS ."list_page.inc"); ?>