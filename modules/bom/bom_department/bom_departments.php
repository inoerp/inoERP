<?php require_once('bom_department.inc') ?>
<?php
$search_form = search::search_form('bom_department', 'bom_departments', 'business_search');
if(!empty($pagination)){
$pagination_statement = $pagination->show_pagination($pagination, 'bom_departments', $pageno, $query_string );
}

?>
<?php  require_once(INC_BASICS . DS ."list_page.inc"); ?>