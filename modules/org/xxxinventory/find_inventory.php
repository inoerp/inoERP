<?php require_once('inventory.inc') ?>
<?php
$search_form = search::search_form('inventory', 'find_inventory', 'inventory_search');
if(!empty($pagination)){
$pagination_statement = $pagination->show_pagination($pagination, 'find_inventory', $pageno, $query_string );
}

//include_find_page();
?>
<?php  require_once(INC_BASICS . DS ."find_page.inc") ?>