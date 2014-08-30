<?php require_once('content.inc') ?>
<?php
$search_form = search::search_form('content', 'contents', 'business_search');
if(!empty($pagination)){
$pagination_statement = $pagination->show_pagination($pagination, 'contents', $pageno, $query_string );
}

?>
<?php  require_once(INC_BASICS . DS ."list_page.inc"); ?>