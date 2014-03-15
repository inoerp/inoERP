<?php
 $hideContextMenu = true;
if (!empty($_GET['class_name'])) {
 $class_names = $_GET['class_name'];
} else {
$class_names[] = 'path';
 include_once("includes/functions/loader.inc");
 $path = new path();
 $all_search_paths = $path->findAll_searchPaths();
 $search_result_statement = "";
 $search_result_statement .= "<table class=\"normal\"><thead><tr>";
 $search_result_statement .= '<th> Search Name </th>';
 $search_result_statement .= '<th> Description </th>';
 $search_result_statement .= '<th> Module </th>';
 $search_result_statement .= '<th> Link </th>';
 $search_result_statement .='</tr></thead>';
 If (!empty($all_search_paths)) {
	$search_result_statement .= '<tbody>';
	foreach ($all_search_paths as $record) {
	 $search_result_statement .='<tr>';
	 $search_result_statement .='<td>' . $record->name . '</td>';
	 $search_result_statement .='<td>' . $record->description . '</td>';
	 $search_result_statement .='<td>' . $record->module_id . '</td>';
	 $search_result_statement .='<td><a href="' . HOME_URL . $record->path_link . '">' . HOME_URL . $record->path_link . '</a></td>';
	 $search_result_statement .='</tr>';
	}
	$search_result_statement .='</tbody>';
 }
 $search_result_statement .='</table>';
//	 echo '<pre>';
//	 print_r($all_search_paths);
 require_once(INC_BASICS . DS . "list_page.inc");
}
if (!empty($class_names)) {
 include_once("includes/functions/loader.inc");
 
// $search_form = search::x_search_form($class, 'search', 'main_search', $option_list);
 $search = new search();
 if(property_exists($$class, 'option_lists')){
 $search->option_lists = $$class->option_lists;
 }
 $search->setProperty('_search_order_by', filter_input(INPUT_GET, 'search_order_by'));
 $search->setProperty('_search_asc_desc', filter_input(INPUT_GET, 'search_asc_desc'));
 $search->setProperty('_per_page', filter_input(INPUT_GET, 'per_page'));
 $search->setProperty('_searching_class', $class);
 $search->setProperty('_initial_search_array', $$class->initial_search);
 $search_form = $search->search_form($$class);
 
 require_once(INC_BASICS . DS . "search_page.inc");
}
?>