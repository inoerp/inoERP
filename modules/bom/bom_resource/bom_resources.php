<?php require_once('bom_resource.inc') ?>
<?php
$search_form = search::search_form('bom_resource', 'bom_resources', 'business_search');
if(!empty($pagination)){
$pagination_statement = $pagination->show_pagination($pagination, 'bom_resources', $pageno, $query_string );
}

?>
<?php  require_once(INC_BASICS . DS ."list_page.inc"); ?>