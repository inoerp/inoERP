<?php require_once('item.inc') ?>
<?php
$search_form = search::search_form('item', 'find_item', 'item_search');
if(!empty($pagination)){
$pagination_statement = $pagination->show_pagination($pagination, 'find_item', $pageno, $query_string );
}

//include_find_page();
?>
<?php  require_once(INC_BASICS . DS ."find_page.inc") ?>