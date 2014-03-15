<?php require_once('business_org.inc') ?>
<?php
$search_form = search::search_form('business_org', 'find_business_org', 'business_org_search');
if(!empty($pagination)){
$pagination_statement = $pagination->show_pagination($pagination, 'find_business_org', $pageno, $query_string );
}

//include_find_page();
?>
<?php  require_once(INC_BASICS . DS ."find_page.inc") ?>