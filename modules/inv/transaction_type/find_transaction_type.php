<?php require_once('transaction_type.inc') ?>
<?php
$search_form = search::search_form('transaction_type', 'find_transaction_type', 'transaction_type_search');
if(!empty($pagination)){
$pagination_statement = $pagination->show_pagination($pagination, 'find_transaction_type', $pageno, $query_string );
}

//include_find_page();
?>
<?php  require_once(INC_BASICS . DS ."find_page.inc") ?>