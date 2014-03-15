<?php require_once('content_type.inc') ?>
<?php
$search = new search();
$search->setProperty('_search_order_by', filter_input(INPUT_GET, 'search_order_by'));
$search->setProperty('_search_asc_desc', filter_input(INPUT_GET, 'search_asc_desc'));
$search->setProperty('_per_page', filter_input(INPUT_GET, 'per_page'));
$search->setProperty('_searching_class', 'content_type');
$search->setProperty('_show_update_path', 1);
$search->setProperty('_show_view_path', 1);
$search->setProperty('_initial_search_array', $$class->initial_search);
$search_form = $search->search_form($$class);
if (!empty($pagination)) {
 $pagination_statement = $pagination->show_pagination($pagination, 'content_types', $pageno, $query_string);
}
?>
<?php require_once(INC_BASICS . DS . "list_page.inc"); ?>