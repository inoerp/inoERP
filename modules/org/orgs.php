<?php
$module_info = [
		array(
				"module" => "org",
				"class" => "org",
				"key_field" => "org",
				"primary_column" => "org_id"
		)
];
$pageTitle = " Organization - Create & Update all Orgs ";
?>
<?php include_once("../../include/basics/header.inc"); ?> 
<script src="org.js"></script>
<?php
$search_form = search::search_form('org', 'orgs', 'org_search');
if(!empty($pagination)){
$pagination_statement = $pagination->show_pagination($pagination, 'orgs', $pageno, $query_string );
}
?>

<?php  require_once(INC_BASICS . DS ."list_page.inc") ?>