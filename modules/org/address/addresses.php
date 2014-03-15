<?php require_once('address.inc') ?>
<?php
$search_form = search::search_form('address', 'addresses', 'address_search');
if(!empty($pagination)){
$pagination_statement = $pagination->show_pagination($pagination, 'addresses', $pageno, $query_string );
}
?>
<?php  require_once(INC_BASICS . DS ."list_page.inc") ?>