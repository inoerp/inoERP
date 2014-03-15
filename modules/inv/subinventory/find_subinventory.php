<?php require_once('subinventory.inc') ?>
<?php
$search_form = search::search_form('subinventory', 'find_subinventory', 'subinventory_search');
if(!empty($pagination)){
$pagination_statement = $pagination->show_pagination($pagination, 'find_subinventory', $pageno, $query_string );
}

//include_find_page();
?>
<?php  require_once(INC_BASICS . DS ."find_page.inc") ?>