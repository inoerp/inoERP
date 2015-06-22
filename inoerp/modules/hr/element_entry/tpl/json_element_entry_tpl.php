<?php include_once("../../../../includes/basics/basics.inc"); ?>
<?php
if ((!empty($_GET['find_element_entry_tpl']))) {
$data = hr_element_entry_tpl_header::find_all();
 if (count($data) == 0) {
  return false;
 } else {
  echo header('Content-Type: application/json');
  echo json_encode($data);
 }
}
?>