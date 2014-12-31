<?php include_once("../../../includes/basics/basics.inc"); ?>
<?php
 if ((!empty($_GET['find_coa_structure'])) && (!empty($_GET['coa_structure_id']))) {
  $data = option_line::find_by_parent_id($_GET['coa_structure_id']);
  if (count($data) > 0) {
   echo header('Content-Type: application/json');
   echo json_encode($data);
  }
 }
?>