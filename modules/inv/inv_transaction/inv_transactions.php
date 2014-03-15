<?php require_once('inv_transaction.inc') ?>
<?php
$search_form = search::search_form('inv_transaction', 'inv_transactions', 'inv_transaction_search');
if(!empty($pagination)){
$pagination_statement = $pagination->show_pagination($pagination, 'inv_transactions', $pageno, $query_string );
}

?>
<?php  require_once(INC_BASICS . DS ."list_page.inc"); ?>