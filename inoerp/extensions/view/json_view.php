<?php include_once("../../includes/basics/basics.inc"); ?>

<?php
 if ((!empty($_GET['query_v'])) && (!empty($_GET['find_result']))) {
  global $dbc;
  $query_v = !empty($_GET['query_v']) ? ($_GET['query_v']) : null;
  $query_v = trim($query_v,'"');
  $display_type = !empty($_GET['display_type']) ? ($_GET['display_type']) : 'table';
  $result = dbObject::find_by_sql($query_v);

  if(!$result){
   return false;
  }
  $return_stmt = '<div id="return_divId">';
  $return_stmt .= '<table class="normal view_result"><thead><tr>';
  foreach($result[0] as $key => $val){
   $return_stmt.='<th>'.$key.'</th>';
  }
  $return_stmt .= '</tr></thead>';
  $return_stmt .= '<tbody>';
  foreach($result as $data){
   $return_stmt.='<tr>';
     foreach($data as $k => $v){
   $return_stmt.='<td>'.$v.'</td>';
  }
  $return_stmt.='</tr>';
  }
  $return_stmt .= '</tbody></table></div>';
  echo $return_stmt;
//  echo header('Content-Type: application/json');
//  echo json_encode(($return_stmt));
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

  $column_names = view::find_columns_of_table($tableName);

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

