<?php require_once('subinventory.inc') ?>
<?php
$search_form = search::search_form('subinventory', 'subinventorys', 'business_search');
if(!empty($pagination)){
$pagination_statement = $pagination->show_pagination($pagination, 'subinventorys', $pageno, $query_string );
}

?>
<?php  require_once(INC_BASICS . DS ."list_page.inc") ?>