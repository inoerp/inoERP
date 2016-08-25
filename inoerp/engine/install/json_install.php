<?php include_once("../../includes/basics/basics.inc"); ?>
<?php

 $table_count = extn_view::count_all_tables();
 $progress_percentage = array('progress' => $_SESSION['progress_percentage']);
 if (count($table_count) == 0) {
  return false;
 } else {
  echo header('Content-Type: application/json');
  echo json_encode($table_count);
 }
?>