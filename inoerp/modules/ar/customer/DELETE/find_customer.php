<?php
$module_info = [
		array(
				"module" => "ar",
				"class" => "ar_customer",
				"key_field" => "customer_number",
				"primary_column" => "ar_customer_id"
		)
];
$pageTitle = " Customer - Find Customers ";
$view_path = "customer_view";
?>
<?php include_once("../../../include/basics/header.inc"); ?> 
<script type='text/javascript' src="customer.js" ></script>
<?php
$search_form = search::search_form('ar_customer', 'find_customer', 'customer_search');

if(!empty($pagination)){
$pagination_statement = $pagination->show_pagination($pagination, 'find_customer', $pageno, $query_string );
}
//required for modules with multiple classes
$column_array = ar_customer::$column_array;
//include_find_page();
?>
<?php  require_once(INC_BASICS . DS ."find_page.inc") ?>