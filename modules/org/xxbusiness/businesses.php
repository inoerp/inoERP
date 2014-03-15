<?php require_once('business.inc') ?>
<?php
$search_form = search::search_form('business', 'businesses', 'business_search');
if(!empty($pagination)){
$pagination_statement = $pagination->show_pagination($pagination, 'businesses', $pageno, $query_string );
}

?>
<?php  require_once(INC_BASICS . DS ."list_page.inc") ?>