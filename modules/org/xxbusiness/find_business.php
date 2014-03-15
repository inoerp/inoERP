<?php require_once('business.inc') ?>
<?php
$search_form = search::search_form('business', 'find_business', 'business_search');
if(!empty($pagination)){
$pagination_statement = $pagination->show_pagination($pagination, 'find_business', $pageno, $query_string );
}

//include_find_page();
?>
<?php  require_once(INC_BASICS . DS ."find_page.inc") ?>