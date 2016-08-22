<?php include_once("../../includes/basics/basics.inc"); ?>
<?php

if (!empty($_GET['find_result'])) {
 if (!empty($_GET['query_v'])) {
  $view = new extn_view();
  $view->pageno = !empty($_GET['pageno']) ? ($_GET['pageno']) : 1;
  $view->per_page = !empty($_GET['per_page']) ? ($_GET['per_page']) : 20;
  $view->query_v = ($_GET['query_v']);
  $view->display_type = ($_GET['display_type']);
  $view->no_of_grid_columns = !empty($_GET['no_of_grid_columns']) ? ($_GET['no_of_grid_columns']) : 0;
  echo '<div id="return_divId">' . $view->show_viewResult() . '</div>';
 } else if (!empty($_GET['view_id'])) {
  $view = new extn_view();
  $view->pageno = !empty($_GET['pageno']) ? ($_GET['pageno']) : 1;
  $view->per_page = !empty($_GET['per_page']) ? ($_GET['per_page']) : 20;
  $view->view_id = ($_GET['view_id']);
  if (!empty($_GET['filter_data'])) {
   foreach ($_GET['filter_data'] as $filter_data) {
    $view->user_filter[$filter_data['name']] = $filter_data['value'];
   }
  }
  if (!empty($_GET['sort_data'])) {
   foreach ($_GET['sort_data'] as $sort_data) {
    $view->user_sort[$sort_data['name']] = $sort_data['value'];
   }
  }
  echo '<div id="return_divId">' . $view->show_viewResult() . '</div>';
 } else {
  return false;
 }
}
?>


<?php
if (!empty($_GET['viewResultById']) && !empty($_GET['view_id'])) {
 $view_i = new extn_view();
 $view_i->view_id = $_GET['view_id'];
 echo '<div id="return_divId">'; 
  $view_i->viewResultById();
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

 $column_names = extn_view::find_columns_of_table($tableName);

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

