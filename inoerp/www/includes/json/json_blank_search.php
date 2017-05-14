<?php
require_once __DIR__.'/../basics/wloader.inc';
$hideContextMenu = true;
$mode = 2;
global $s;
if (!empty($_GET['search_class_name'])) {
 $class_names = $_GET['search_class_name'];
} else if (!empty($_GET['class_name'])) {
 $class_names = $_GET['class_name'];
} else {
 $class_names[] = 'path';
 include_once(__DIR__.'/../../../inoerp_server/includes/functions/loader.inc');
 $path = new path();
 $all_search_paths = $path->findAll_searchPaths();
 $search_result_statement = "";
 $search_result_statement .= "<table class=\"table normal\"><thead><tr>";
 $search_result_statement .= '<th> Module </th>';
 $search_result_statement .= '<th> Search Details </th>';
 $search_result_statement .='</tr></thead>';
 If (!empty($all_search_paths)) {
	$search_result_statement .= '<tbody>';
	foreach ($all_search_paths as $key => $module_group) {
	 $search_result_statement .= ' <tr class="major_row"><td>' . $key . '</td><td><table class="second">';
	 foreach ($module_group as $paths) {
		$search_result_statement .='<tr class="minor_row">';
		$search_result_statement .='<td>' . $paths->name . '</td>';
		$search_result_statement .='<td>' . $paths->description . '</td>';
		$search_result_statement .='<td><a href="' . HOME_URL . $paths->path_link . '">' . HOME_URL . $paths->path_link . '</a></td>';
		$search_result_statement .='</tr>';
	 }
	 $search_result_statement .='</table></td></tr>';
	}
	$search_result_statement .='</tbody>';
 }
 $search_result_statement .='</table>';
 require_once(INC_BASICS . DS . "search_page.inc");
 return;
}
if (!empty($class_names)) {
 include_once(__DIR__.'/../../../inoerp_server/includes/functions/loader.inc');

 if ($class == 'ino_user' && !empty($_SESSION['user_roles'])) {
	if (!in_array('ADMIN', $_SESSION['user_roles'])) {
	 $access_level = null;
	}
 }
 
 if (empty($access_level) || ($access_level < 2 )) {
	echo '<div><div id="structure">' . access_denied() . '</div></div>';
	return;
 }

 //pre populate
 if (method_exists($$class, 'search_pre_populate')) {
	$ppl = call_user_func(array($$class, 'search_pre_populate'));
	if (!empty($ppl)) {
	 foreach ($ppl as $search_key => $search_val) {
		$_GET[$search_key] = $search_val;
	 }
	}
 }

// $search_form = search::x_search_form($class, 'search', 'main_search', $option_list);
// $search = new search();
 if (property_exists($$class, 'option_lists')) {
	$s->option_lists = $$class->option_lists;
 }
 if (!empty($_GET['search_order_by'][0])) {
	$s->setProperty('_search_order_by', $_GET['search_order_by'][0]);
 }
 if (!empty($_GET['search_asc_desc'][0])) {
	$s->setProperty('_search_asc_desc', $_GET['search_asc_desc'][0]);
 }
 if (!empty($_GET['per_page'][0])) {
	$s->setProperty('_per_page', $_GET['per_page'][0]);
 }
 $s->setProperty('_searching_class', $class);
 if (!empty($existing_search)) {
	foreach ($existing_search as $sk => $sv) {
	 if (!in_array($sv, $$class->initial_search)) {
		array_push($$class->initial_search, $sv);
	 }
	}
 }

 $s->setProperty('_initial_search_array', $$class->initial_search);
 if (property_exists($$class, 'search_groupBy')) {
	$s->setProperty('_group_by', $class::$search_groupBy);
 }
 if ((is_object($$class)) && property_exists($$class, 'search_functions')) {
	$s->setProperty('_search_functions', $$class->search_functions);
 }
 $search_form = $s->search_form($$class);


 include_once(__DIR__ . '/../template/json_blank_search_template.inc');
}
?>
