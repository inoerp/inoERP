<?php require_once('enterprise.inc') ?>
<?php
$search_form = search::search_form('enterprise', 'enterprises', 'enterprise_search');
if(!empty($pagination)){
$pagination_statement = $pagination->show_pagination($pagination, 'enterprises', $pageno, $query_string );
}

?>
<?php  require_once(INC_BASICS . DS ."list_page.inc") ?>