<?php
$module_info = [
		array(
				"module" => "ar",
				"class" => "ar_customer",
				"key_field" => "customer_number",
				"primary_column" => "ar_customer_id"
		)
];
$pageTitle = " Customer - Find all Customers ";
$view_path = "customer_view";
$path = 'customer';
?>
<?php include_once("../../../include/basics/header.inc"); ?> 
<script type='text/javascript' src="customer.js" ></script>
<?php
$search_form = search::search_form('ar_customer', 'customers', 'customer_search');
if(!empty($pagination)){
$pagination_statement = $pagination->show_pagination($pagination, 'customers', $pageno, $query_string );
}
?>
<?php  require_once(INC_BASICS . DS ."list_page.inc"); ?>