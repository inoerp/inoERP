<?php
$module_info = [
		array(
				"module" => "gl",
				"class" => "payment_term",
				"key_field" => "payment_term",
				"primary_column" => "payment_term_id"
		)
];
$pageTitle = " Payment Term - Create & Update all Terms ";
$view_path = "payment_term_view";
?>
<?php include_once("../../../include/basics/header.inc"); ?> 
<script type='text/javascript' src="payment_term.js" ></script>
<?php
$search_form = search::search_form('payment_term', 'find_payment_term', 'payment_term_search');
if(!empty($pagination)){
$pagination_statement = $pagination->show_pagination($pagination, 'find_payment_term', $pageno, $query_string );
}
//required for modules with multiple classes
$column_array = payment_term::$column_array;
//include_find_page();
?>
<?php  require_once(INC_BASICS . DS ."find_page.inc") ?>