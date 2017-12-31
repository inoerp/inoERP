<?php 
 require_once __DIR__.'/../../includes/basics/wloader.inc';
include_once(__DIR__ ."/../../../inoerp_server/includes/basics/basics.inc");

if (!empty($_GET['find_result'])) {
 if (!empty($_GET['query_v'])) {
  $report = new extn_report();
  $report->pageno = !empty($_GET['pageno']) ? ($_GET['pageno']) : 1;
  $report->per_page = !empty($_GET['per_page']) ? ($_GET['per_page']) : 20;
  $report->query_v = ($_GET['query_v']);
  $report->display_type = ($_GET['display_type']);
  $report->no_of_grid_columns = !empty($_GET['no_of_grid_columns']) ? ($_GET['no_of_grid_columns']) : 0;
  echo '<div id="return_divId">' . $report->show_reportResult() . '</div>';
 } else if (!empty($_GET['extn_report_id'])) {
  $report = new extn_report();
  $report->pageno = !empty($_GET['pageno']) ? ($_GET['pageno']) : 1;
  $report->per_page = !empty($_GET['per_page']) ? ($_GET['per_page']) : 20;
  $report->extn_report_id = ($_GET['extn_report_id']);
  if (!empty($_GET['filter_data'])) {
   foreach ($_GET['filter_data'] as $filter_data) {
    $report->user_filter[$filter_data['name']] = $filter_data['value'];
   }
  }
  if (!empty($_GET['sort_data'])) {
   foreach ($_GET['sort_data'] as $sort_data) {
    $report->user_sort[$sort_data['name']] = $sort_data['value'];
   }
  }
  echo '<div id="return_divId">' . $report->show_reportResult() . '</div>';
 } else {
  return false;
 }
}
?>


<?php
if (!empty($_GET['viewReportById']) && !empty($_GET['extn_report_id'])) {
 $report_i = new extn_report();
 $report_i->extn_report_id = $_GET['extn_report_id'];
 echo '<div id="return_divId">'; 
  $report_i->reportResultById();
 echo '</div>';
}
?>


<?php

if (!empty($_GET['delete']) && $_GET['delete'] == 1) {
 echo '<div id="json_delete_fileds">';
 $content_name = $_GET['content_name'];
 $field_name = $_GET['field_name'];

 $result = content::drop_column($content_name, $field_name);

 if ($result == 1) {
  echo 'Comment is deleted!';
 } else {
  return false;
 }
 echo '</div>';
}
?>

<?php

if (!empty($_GET['tableName']) && $_GET['get_fieldName'] == 1) {
 echo '<div id="json_filed_names">';
 $tableName = $_GET['tableName'];

 $column_names = extn_report::find_columns_of_table($tableName);

 if (count($column_names) == 0) {
  return false;
 } else {
  foreach ($column_names as $key => $value) {
   echo '<option class="table_fields_options" value="' . $value . '"';
   echo '>' . $value . '</option>';
  }
  echo '<option value="remove" class="remove_option" >Remove Field</option>';
 }
 echo '</div>';
}
?>