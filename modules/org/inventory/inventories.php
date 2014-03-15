<?php require_once('inventory.inc') ?>
<?php
$search_form = search::search_form('inventory', 'inventories', 'business_search');
if(!empty($pagination)){
$pagination_statement = $pagination->show_pagination($pagination, 'inventories', $pageno, $query_string );
}

?>
<?php  require_once(INC_BASICS . DS ."list_page.inc") ?>