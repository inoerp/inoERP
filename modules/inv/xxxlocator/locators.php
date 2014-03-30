<?php require_once('locator.inc') ?>
<?php
$search_form = search::search_form('locator', 'locators', 'business_search');
if(!empty($pagination)){
$pagination_statement = $pagination->show_pagination($pagination, 'locators', $pageno, $query_string );
}

?>
<?php  require_once(INC_BASICS . DS ."list_page.inc"); ?>