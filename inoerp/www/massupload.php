<?php
ini_set('display_errors', 1);
ini_set('max_execution_time', 300);
error_reporting(E_ALL);
if (!empty($_GET['class_name'])) {
 $class_names = $_GET['class_name'];
} else {
 $class_names[] = 'path';
 require_once __DIR__.'/includes/basics/wloader.inc';
include_once(__DIR__.'/../inoerp_server/includes/functions/loader.inc');
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
 require_once(THEME_DIR . DS . "search_page.inc");
 return;
}
?>
<?php
if (!empty($class_names)) {
 $class = $class_names;
 require_once __DIR__.'/includes/basics/wloader.inc';
include_once(__DIR__.'/../inoerp_server/includes/functions/loader.inc');
 if (empty($access_level) || ($access_level < 3 )) {
  access_denied();
  return;
 }
 $$class = new $class;
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


 if ($continue) {
  if (!empty($$class) && property_exists($$class, 'mass_upload_template_path')) {
   $template_file_names = $class::$mass_upload_template_path;
  } else if (!empty($$class)) {
   $template_file_names = ['extensions/file/massupload_template.php'];
  }
  include_once(THEME_DIR . '/main_template.inc');
 } else {
  $continue = false;
  echo "<h2>Could n't call the header</h2>";
  return;
 }
}
?>
<script type="text/javascript">
 $(document).ready(function () {
  $.getScript("includes/js/erp.js");
  $.getScript("extensions/file/file.js");
 });
</script>