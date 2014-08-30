<?php
if(!empty($_GET['sql'])){
 $sql = $_GET['sql'];
}
$module_info = [
		array(
				"module" => "option",
				"class" => "option_header",
				"key_field" => "option_type",
				"primary_column" => "option_header_id"
		),
//		array(
//				"module" => "option",
//				"class" => "option_line",
//				"key_field" => "option_line_code",
//				"primary_column" => "option_line_id"
//		),
//		array(
//				"module" => "option",
//				"class" => "option_detail",
//				"key_field" => "option_detail_value",
//				"primary_column" => "option_detail_id"
//		)
];
$pageTitle = " Option - Create & Update all Options ";
$view_path = "option_view";

?>
<?php include_once("../../../include/basics/header.inc"); ?>
<script src="option.js"></script>
<?php
$search_form = search::search_form('option_header', 'options', 'option_search');

	if (!empty($search_result)) {
 	 		 $search_result_statement = search::search_result('option', $column_array, $search_result, $primary_column, $view_path, 'Y', 'Update Option');
	}
	
if(!empty($pagination)){
$pagination_statement = $pagination->show_pagination($pagination, 'options', $pageno, $query_string );
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

<?php // require_once('options_template.php') ?>
<?php  require_once(INC_BASICS . DS ."list_page.inc"); ?>
