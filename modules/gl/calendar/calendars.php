<?php

$module_info = [
		array(
				"module" => "gl",
				"class" => "gl_calendar",
				"key_field" => "description",
				"primary_column" => "gl_calendar_id"
		)
];

$option_lists = [
		'option_line_code' => 'GL_CALENDAR_NAME',
		'calendar_type' => 'GL_CALENDAR_NAME'
];

$pageTitle = " Calendars  - Create & Update all Calendars ";
$view_path = "calendar_view";
?>
<?php include_once("../../../include/basics/header.inc"); ?>
<script src="calendar.js"></script>
<?php

$search_form = search::search_form('gl_calendar', 'calendars', 'calendar_search',$option_lists);

if (!empty($search_result)) {
 $search_result_statement = search::search_result('calendar', $column_array, $search_result, $primary_column, $view_path, 'Y', 'Update');
}

if (!empty($pagination)) {
 $pagination_statement = $pagination->show_pagination($pagination, 'value_groups', $pageno, $query_string);
}
?>

<?php // require_once('options_template.php') ?>
<?php require_once(INC_BASICS . DS . "list_page.inc"); ?>
