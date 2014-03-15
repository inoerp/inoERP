<?php
$module_info = [
		array(
				"module" => "wip",
				"class" => "wip_wo_header",
				"key_field" => "item_id",
				"primary_column" => "wip_wo_header_id"
		)
];

$option_lists = [
		'wo_type'=>'WIP_WO_TYPE',
		'wo_status' =>'WIP_WO_STATUS'
		];

$pageTitle = " Work Order - Find all WOs ";
$view_path = "wip_wo_view";
$update_path = "wip_wo";
?>
<?php include_once("../../../include/basics/header.inc"); ?> 
<script type='text/javascript' src="wip_wo.js" ></script>
<link href="wip_wo.css" media="all" rel="stylesheet" type="text/css" />

<?php
$search_form = search::search_form('wip_wo_header', 'wip_wos', 'wos_search', $option_lists);
	if (!empty($search_result)) {
	 	 $search_result_statement = search::search_result('wip_wo', $column_array, $search_result, $primary_column, $view_path, '', 'Update WO');
	}
if(!empty($pagination)){
$pagination_statement = $pagination->show_pagination($pagination, 'pos', $pageno, $query_string );
}
?>
<?php  require_once(INC_BASICS . DS ."list_page.inc"); ?>