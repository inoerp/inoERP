<?php require_once('legal.inc') ?>
<?php
$search_form = search::search_form('legal', 'legals', 'legal_search');
if(!empty($pagination)){
$pagination_statement = $pagination->show_pagination($pagination, 'legals', $pageno, $query_string );
}

?>
<?php  require_once(INC_BASICS . DS ."list_page.inc") ?>