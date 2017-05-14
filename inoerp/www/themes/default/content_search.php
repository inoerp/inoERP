<?php
if (property_exists($$class, 'option_lists')) {
 $s->option_lists = $$class->option_lists;
}
$s->setProperty('_search_order_by', filter_input(INPUT_GET, 'search_order_by'));
$s->setProperty('_search_asc_desc', filter_input(INPUT_GET, 'search_asc_desc'));
$s->setProperty('_per_page', filter_input(INPUT_GET, 'per_page'));
$s->setProperty('_searching_class', $class);
$s->setProperty('_initial_search_array', $$class->initial_search);
if (property_exists($$class, 'search_groupBy')) {
 $s->setProperty('_group_by', $$class->search_groupBy);
}
if (property_exists($$class, 'search_functions')) {
 $s->setProperty('_search_functions', $$class->search_functions);
}
$search_form = $search->search_form($$class);
?>
<?php require_once(INC_BASICS . DS . "list_page.inc"); ?>