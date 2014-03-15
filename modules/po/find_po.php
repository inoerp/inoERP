<?php
$module_info = [
		array(
				"module" => "ap",
				"class" => "supplier",
				"key_field" => "supplier_number",
				"primary_column" => "supplier_id"
		)
];
$pageTitle = " Supplier - Create & Update all Suppliers ";
$view_path = "supplier_view";
?>
<?php include_once("../../../include/basics/header.inc"); ?> 
<script type='text/javascript' src="supplier.js" ></script>
<?php
$search_form = search::search_form('supplier', 'find_supplier', 'supplier_search');
if(!empty($pagination)){
$pagination_statement = $pagination->show_pagination($pagination, 'find_supplier', $pageno, $query_string );
}
//required for modules with multiple classes
$column_array = supplier::$column_array;
//include_find_page();
?>
<?php  require_once(INC_BASICS . DS ."find_page.inc") ?>