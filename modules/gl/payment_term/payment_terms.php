<?php

$module_info = [
		array(
				"module" => "gl",
				"class" => "payment_term",
				"key_field" => "payment_term",
				"primary_column" => "payment_term_id"
		)
];
$pageTitle = " Payment Term - Create & Update all terms ";
$view_path = "payment_term_view";
?>
<?php include_once("../../../include/basics/header.inc"); ?> 
<script type='text/javascript' src="payment_term.js" ></script>
<?php

$search_form = search::search_form('payment_term', 'payment_terms', 'payment_term_search');
if (!empty($pagination)) {
 $pagination_statement = $pagination->show_pagination($pagination, 'payment_terms', $pageno, $query_string);
}
?>
<?php require_once(INC_BASICS . DS . "list_page.inc"); ?>