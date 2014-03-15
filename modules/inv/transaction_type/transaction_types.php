<?php require_once('transaction_type.inc') ?>
<?php
$search_form = search::search_form('transaction_type', 'transaction_types', 'business_search');
if(!empty($pagination)){
$pagination_statement = $pagination->show_pagination($pagination, 'transaction_types', $pageno, $query_string );
}

?>
<?php  require_once(INC_BASICS . DS ."list_page.inc"); ?>