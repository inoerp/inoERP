<?php
$_GET['wo_status']='RELEASED';
$module_info = [
		array(
				"module" => "wip",
				"class" => "wip_wo_header",
				"key_field" => "item_id",
				"primary_column" => "wip_wo_header_id"
		)
];
$pageTitle = " Work Order - Find all WOs ";
$view_path = "wip_wo_view";
$update_path = "wip_wo";
?>
<?php include_once("../../../include/basics/header.inc"); ?> 
<script type='text/javascript' src="wip_wo.js" ></script>
<link href="wip_wo.css" media="all" rel="stylesheet" type="text/css" />
<?php
$search_form = search::search_form('wip_wo_header', 'find_wip_wo_released', 'wip_wo_released_search');
if(!empty($pagination)){
$pagination_statement = $pagination->show_pagination($pagination, 'find_wip_wo_released', $pageno, $query_string );
}

//include_find_page();
?>
<?php  require_once(INC_BASICS . DS ."find_page.inc") ?>