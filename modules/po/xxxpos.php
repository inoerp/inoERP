<?php
$module_info = [
		array(
				"module" => "po",
				"class" => "po_header",
				"key_field" => "po_type",
				"primary_column" => "po_header_id"
		)
];
$pageTitle = " PO - Find all POs ";
$view_path = "po_view";
?>
<?php include_once("../../include/basics/header.inc"); ?> 
<script type='text/javascript' src="po.js" ></script>
<?php
$search_form = search::search_form('po_header', 'pos', 'po_search');
	if (!empty($search_result)) {
	 $search_result = po_header::instantiate_extra_fields($search_result);
//	 echo "<pre>";
//	 print_r($search_result);
	 
	 $search_result_statement = search::search_result('po', $column_array, $search_result, $primary_column, $view_path, $update_path);
//		 $return_value['search_result'] = $search_result;
	}
if(!empty($pagination)){
$pagination_statement = $pagination->show_pagination($pagination, 'pos', $pageno, $query_string );
}
?>
<?php  require_once(INC_BASICS . DS ."list_page.inc"); ?>