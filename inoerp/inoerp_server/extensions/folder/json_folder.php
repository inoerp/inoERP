<?php include_once("../../includes/basics/basics.inc"); ?>
<?php

if ((!empty($_GET['extn_folder_id']))) {
 
 $extn_folder_id = $_GET['extn_folder_id'];

//echo $org_id;
  $data = extn_folder_all_v::find_by_ColumnNameVal( 'extn_folder_id' , $extn_folder_id);
	
// jQuery wants JSON data
  $json = json_encode($data);
  echo header('Content-Type: application/json');
  echo json_encode(($data));
 
}
?>