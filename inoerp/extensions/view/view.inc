<?php
//get view display types
$view_display_types = view::view_display_types();
$view_display_type_statement = "<Select class=\"view_display_type_select\" name=\"display_type\">";
$view_display_type_statement .= "<option value=\"\"></option>";
foreach ($view_display_types as $records) {
 if ($records->option_line_code == $view->display_type) {
	$selected_display_type = "selected";
 } else {
	$selected_display_type = "";
 }
 $view_display_type_statement .="<option class=\"view_display_type\" value=\"$records->option_line_code\"  $selected_display_type>";
 $view_display_type_statement .="$records->option_line_code</option>";
}
$view_display_type_statement .= "</Select>";
//check all view paths
//echo '<pre>';
//print_r($view);
//echo '<pre>';

$view_paths = path::find_all_view_paths();
if (!empty($view->view_id)) {
 $existing_view_paths_array = view_path::find_by_view_id($view->view_id);
} else {
 $existing_view_paths_array = "";
}
if (!empty($existing_view_paths_array)) {
 $view_path_statement = "";
 foreach ($existing_view_paths_array as $objects) {
	$view_path_statement .= "<select class=\"view_path\" name=\"view_path[]\">";
	$view_path_statement .= "<option value=\"\"> </option>";
	foreach ($view_paths as $recods) {
	 if ($recods->id_column_name == $objects->column_name) {
		$selected = "selected";
	 } else {
		$selected = "";
	 }
	 $view_path_statement .= "<option value=\"$recods->id_column_name\"";
	 $view_path_statement .= $selected;
	 $view_path_statement .= " > $recods->id_column_name" ." of "."$recods->name";
	 $view_path_statement .= "</option>";
	}
	$view_path_statement .= "<option value=\"remove\"> Remove </option>";
	$view_path_statement .= "<option value=\"delete\" class=\"delete\"> Delete </option>";
	$view_path_statement .= "</select>";
 }
} elseif (!empty($view_paths)) {
 $view_path_statement = "";
 $view_path_statement .= "<select class=\"view_path\" name=\"view_path[]\">";
 $view_path_statement .= "<option value=\"\"> </option>";
 foreach ($view_paths as $recods) {
	$view_path_statement .= "<option value=\"$recods->id_column_name\"";
	$view_path_statement .= " > $recods->id_column_name" ." of "."$recods->name";
	$view_path_statement .= "</option>";
 }
 $view_path_statement .= "<option value=\"remove\"> Remove </option>";
 $view_path_statement .= "</select>";
}

//end of view paths
//echo '<br/>$query_string is. '. $query_string;
//show live result if $query is not empty
if ((!empty($view->query))) {

 switch ($view->display_type) {
	case 'paragraph' :
	 $view_result = view::result_list_in_paragraph(base64_decode($view->query), $view->view_id, $pageno, $per_page, $query_string);
	 break;

	case 'table' :
	 $view_result = view::result_list_in_table(base64_decode($view->query), $view->view_id, $pageno, $per_page, $query_string);
	 break;

	default:
	 $view_result = "";
 }
} else {
 $view_result = "";
}
?>
