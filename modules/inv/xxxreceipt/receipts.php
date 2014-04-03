<?php require_once('receipt.inc') ?>
<?php
$search_form = search::search_form('receipt_header', 'receipts', 'receipt_search');
if(!empty($pagination)){
$pagination_statement = $pagination->show_pagination($pagination, 'receipts', $pageno, $query_string );
}

?>
<?php  require_once(INC_BASICS . DS ."list_page.inc"); ?>