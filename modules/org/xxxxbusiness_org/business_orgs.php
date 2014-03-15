<?php require_once('business_org.inc') ?>
<?php
$search_form = search::search_form('business_org', 'business_orgs', 'business_org_search');
if(!empty($pagination)){
$pagination_statement = $pagination->show_pagination($pagination, 'business_orgs', $pageno, $query_string );
}

?>
<?php  require_once(INC_BASICS . DS ."list_page.inc") ?>