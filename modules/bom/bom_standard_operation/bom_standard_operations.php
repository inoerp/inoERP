<?php require_once('bom_standard_operation.inc') ?>
<?php
$search_form = search::search_form('bom_standard_operation', 'bom_standard_operations', 'business_search');
if(!empty($pagination)){
$pagination_statement = $pagination->show_pagination($pagination, 'bom_standard_operations', $pageno, $query_string );
}

?>
<?php  require_once(INC_BASICS . DS ."list_page.inc"); ?>