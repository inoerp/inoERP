<?php
$module_info = [
		array(
				"module" => "gl",
				"class" => "gl_ledger",
				"key_field" => "ledger",
				"primary_column" => "gl_ledger_id"
		)
];
$pageTitle = " Ledger - Find All Ledgers "; //page Title
$view_path = "ledger_view"; //view path 
$option_list = [
		'calendar_option_line_code' => 'GL_CALENDAR_NAME',
		'currency_code' => 'CURRENCY'
]; //list of search fields which have options
$path = 'ledger'; //Path shown on serach list page to update
?>
<?php include_once("../../../include/function/loader.inc"); ?>
<!--<script src="ledger.js"></script>-->
<?php
$search_form = search::search_form('gl_ledger', 'ledgers', 'ledger_search', $option_list);
if (empty($search_result_statement)) {
 $search_result_statement .= "<table class=\"normal\"><thead><tr>";
 foreach ($column_array as $key => $value) {
	$search_result_statement .= '<th>' . $value . '</th>';
 }
 $search_result_statement .= '<th>Action</th>';
 $search_result_statement .='</tr></thead>';
 $search_result_statement .='</table>';
}

?>
<?php require_once(INC_BASICS . DS . "list_page.inc"); ?>
