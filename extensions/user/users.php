<?php require_once('user.inc') ?>
<?php
$search_form = search::search_form('user', 'users', 'business_search');
if(!empty($pagination)){
$pagination_statement = $pagination->show_pagination($pagination, 'users', $pageno, $query_string );
}

?>
<?php  require_once(INC_BASICS . DS ."list_page.inc"); ?>