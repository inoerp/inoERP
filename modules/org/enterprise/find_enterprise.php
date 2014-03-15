<?php require_once('enterprise.inc') ?>
<?php
$search_form = search::search_form('enterprise', 'find_enterprise', 'enterprise_search');
if(!empty($pagination)){
$pagination_statement = $pagination->show_pagination($pagination, 'find_enterprise', $pageno, $query_string );
}

//include_find_page();
?>
<?php  require_once(INC_BASICS . DS ."find_page.inc") ?>