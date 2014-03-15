<?php require_once('uom.inc') ?>
<?php
$search_form = search::search_form('uom', 'find_uom', 'uom_search');
if(!empty($pagination)){
$pagination_statement = $pagination->show_pagination($pagination, 'find_uom', $pageno, $query_string );
}

//include_find_page();
?>
<?php  require_once(INC_BASICS . DS ."find_page.inc") ?>