<?php
 $hideContextMenu = true;
 $hideBlock = true;
if (!empty($_GET['class_name'])) {
 $class_names = $_GET['class_name'];
 $pageTitle = " $class_names - Select value of $class_names ";
} else {
 $path_access = -1;
}
if (!empty($class_names)) {
 include_once("includes/functions/loader.inc");
  if (empty($access_level) || ($access_level < 2 )) {
	access_denied();
	return;
 }
 $search = new search();
 $search->setProperty('_search_order_by', filter_input(INPUT_GET, 'search_order_by'));
 $search->setProperty('_search_asc_desc', filter_input(INPUT_GET, 'search_asc_desc'));
 $search->setProperty('_per_page', filter_input(INPUT_GET, 'per_page'));
 $search->setProperty('_searching_class', $class);
 $search->setProperty('_form_post_link', 'select');
 $search->setProperty('_initial_search_array', $$class->initial_search);
 $search_form = $search->search_form($$class);
 
 if (!empty($pagination)) {
	$pagination->setProperty('_path','select');
	$pagination_statement = $pagination->show_pagination();
 }
}
?>
<?php require_once(INC_BASICS . DS . "select_page.inc") ?>