<?php require_once('locator.inc') ?>
<?php
$search_form = search::search_form('locator', 'find_locator', 'locator_search');
if(!empty($pagination)){
$pagination_statement = $pagination->show_pagination($pagination, 'find_locator', $pageno, $query_string );
}
?>
<?php  require_once(INC_BASICS . DS ."find_page.inc") ?>