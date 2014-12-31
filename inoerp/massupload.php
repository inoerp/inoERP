<?php
ini_set('display_errors', 1);
ini_set('max_execution_time', 300);
error_reporting(E_ALL);
if (!empty($_GET['class_name'])) {
 $class_names = $_GET['class_name'];
} else {
 $class_names[] = 'path';
 include_once("includes/functions/loader.inc");
 $path = new path();
 $all_search_paths = $path->findAll_massUplodPaths();
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
	 $search_result_statement .='<td>' . $record->module_code . '</td>';
	 $search_result_statement .='<td><a href="' . HOME_URL . $record->path_link . '">' . HOME_URL . $record->path_link . '</a></td>';
	 $search_result_statement .='</tr>';
	}
	$search_result_statement .='</tbody>';
 }
 $search_result_statement .='</table>';
//	 echo '<pre>';
//	 print_r($all_search_paths);
 require_once(INC_BASICS . DS . "search_page.inc");
}
?>
<?php 
if (!empty($class_names)) {
 $class = $class_names;
 include_once("includes/functions/loader.inc");
  if (empty($access_level) || ($access_level < 3 )) {
	access_denied();
	return;
 }
 $$class = new $class();
 $data_headers = $$class->field_a;
 $ignored_fields = ['created_by', 'creation_date', 'last_update_by', 'last_update_date'];
 $few_records = $class::find_few(5);
 $dataArray = [];
 foreach ($few_records as $rows) {
	$datarow = [];
	foreach ($data_headers as $columns) {
	 if (!in_array($columns, $ignored_fields)) {
		$datarow[$columns] = $rows->$columns;
	 }
	}
	array_push($dataArray, $datarow);
 }

 $dl = new downloads();
 $dl->setProperty('_downloaded_data', $dataArray);
  if ($continue) {
  include_once(THEME_DIR . '/header.inc');
 } else {
  $continue = false;
  echo "<h2>Could n't call the header</h2>";
  return;
 }
 require_once('extensions/file/massupload_template.php' );
}
?>
<script type="text/javascript">
 $(document).ready(function () {
  $.getScript("includes/js/erp.js");
  $.getScript("file/file.js");
 });
</script>