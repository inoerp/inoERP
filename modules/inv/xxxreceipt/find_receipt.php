<?php require_once('inv_transaction.inc') ?>
<?php
$search_form = search::search_form('inv_transaction', 'find_inv_transaction', 'inv_transaction_search');
if(!empty($pagination)){
$pagination_statement = $pagination->show_pagination($pagination, 'find_inv_transaction', $pageno, $query_string );
}

//include_find_page();
?>
<?php  require_once(INC_BASICS . DS ."find_page.inc") ?>