<?php
$extension = 'view';
$key_field = 'view';
$primary_column = "view_id";
$pageTitle = " View - Create & update view ";
$required_field_flag = 1;
?>
<?php include_once("../../include/basics/header.inc"); ?>
<link href="view.css" media="all" rel="stylesheet" type="text/css" />
<script src="view.js"></script>

<?php
//get all table names
$table_name_array = view::find_all_tables();
if (($table_name_array) & (count($table_name_array) > 0)) {
 $table_option_statement = "";
 $table_option_statement .="<option></option>";
 foreach ($table_name_array as $table) {
	$table_option_statement .= '<option class="select table option" value="' . $table .
					'">' . $table . '</option>';
 }
}
//end of all table names
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

if ($run_functions_after_save >= 1) {
 //check the combination of view_id & column name exists
 $path_array = $_POST['view_path'];
 foreach ($path_array as $key => $value) {
	$view_path = new view_path;
	$view_path->view_id = $view->view_id;
	$view_path->column_name = $value;
	$path_array = path::find_by_idColumn_name($value);
	$view_path->path = $path_array->value;
//		echo '<pre>';
//	print_r($view_path);
//	echo '<pre>';
	$viewId_columnName_exists_array = view_path::find_by_columnName_viewId($view_path->column_name, $view_path->view_id);
	if (!empty($viewId_columnName_exists_array) && !empty($viewId_columnName_exists_array->view_path_id)) {
	 $view_path->view_path_id = $viewId_columnName_exists_array->view_path_id;
	}
	$view_path->save();
 }
}

if (!empty($msg)) {
 $show_message = '<div id="dialog_box">';
 foreach ($msg as $key => $value) {
	$x = $key + 1;
	$show_message .= 'Message ' . $x . ' : ' . $value . '<br />';
 }
 $show_message .= '</div>';
}
?>

<?php require_once('view_template.php') ?>
