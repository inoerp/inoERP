<?php require_once('bom_cost_type.inc') ?>
<?php
$search_form = search::search_form('bom_cost_type', 'bom_cost_types', 'business_search');
if(!empty($pagination)){
$pagination_statement = $pagination->show_pagination($pagination, 'bom_cost_types', $pageno, $query_string );
}

?>
<?php  require_once(INC_BASICS . DS ."list_page.inc"); ?>