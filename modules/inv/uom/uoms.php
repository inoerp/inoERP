<?php require_once('uom.inc') ?>
<?php
$search_form = search::search_form('uom', 'uoms', 'business_search');
if(!empty($pagination)){
$pagination_statement = $pagination->show_pagination($pagination, 'uoms', $pageno, $query_string );
}

?>
<?php  require_once(INC_BASICS . DS ."list_page.inc"); ?>