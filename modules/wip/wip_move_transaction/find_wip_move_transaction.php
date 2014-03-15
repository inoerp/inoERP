<?php require_once('wip_move_transaction.inc') ?>
<script type='text/javascript' src="wip_move_transaction.js" ></script>
<?php
$search_form = search::search_form('wip_move_transaction', 'find_wip_move_transaction', 'wip_move_transaction_search');
if(!empty($pagination)){
$pagination_statement = $pagination->show_pagination($pagination, 'find_wip_move_transaction', $pageno, $query_string );
}

//include_find_page();
?>
<?php  require_once(INC_BASICS . DS ."find_page.inc") ?>