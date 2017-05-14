<?php
ini_set('display_errors', 1);
ini_set('max_execution_time', 300);
error_reporting(E_ALL);
if (!empty($_GET['class_name'])) {
 $class_names = $_GET['class_name'];
} else {
 $class_names[] = 'path';
 include_once("../../includes/functions/loader.inc");
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
 include_once("../../includes/functions/loader.inc");
 $$class = new $class();
 $data_headers = $$class->field_a;
 $ignored_fields = ['created_by', 'creation_date', 'last_update_by', 'last_update_date'];
 $few_records = $class::find_few(5);
 $dataArray = [];
 if (!empty($few_records)) {
  foreach ($few_records as $rows) {
   $datarow = [];
   foreach ($data_headers as $columns) {
    if (!in_array($columns, $ignored_fields)) {
     $datarow[$columns] = $rows->$columns;
    }
   }
   array_push($dataArray, $datarow);
  }
 } else {
  $data_headers = get_dbColumns($class);
  if(empty($data_headers)){
   die('No Database Structure Found. Check the class /table name');
  }
  $datarow = [];
  foreach ($data_headers as $k => $columns) {
   if (!in_array($columns, $ignored_fields)) {
    $datarow[$columns] = $rows->$columns;
   }
  }
  array_push($dataArray, $datarow);
 }

 $dl = new downloads();
 $dl->setProperty('_downloaded_data', $dataArray);
 require_once('massupload_template.php' );
}
?>
