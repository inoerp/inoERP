<?php
$class_names[] ='gl_ledger';
$pageTitle = " Ledger - Find All Ledgers ";
?>
<?php  include_once("../../../includes/functions/loader.inc");
 $search = new search();
 $search->setProperty('_search_order_by', filter_input(INPUT_GET, 'search_order_by'));
 $search->setProperty('_search_asc_desc', filter_input(INPUT_GET, 'search_asc_desc'));
 $search->setProperty('_per_page', filter_input(INPUT_GET, 'per_page'));
 $search->setProperty('_searching_class', $class);
 $search->setProperty('_initial_search_array', $$class->initial_search);
 $search_form = $search->search_form($$class);
 if(!empty($pagination)){
$pagination_statement = $pagination->show_pagination($pagination, 'find_ledger', $pageno, $query_string );
}
?>
<script src="ledger.js"></script>
<?php  require_once(INC_BASICS . DS ."find_page.inc") ?>