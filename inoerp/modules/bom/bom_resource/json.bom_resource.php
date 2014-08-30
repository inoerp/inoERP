<?php include_once("../../../include/basics/basic.inc"); ?>
<div id="json_bom_resource_find_all">
  <?php
  if(!empty($_GET['org_id']) && ($_GET['find_all_bom_resource'] = 1)){
   $org_id = $_GET['org_id'];
  $bom_resource_of_org = bom_resource::find_all_of_org_id($org_id) ;
  if (count($bom_resource_of_org) == 0) {
    return false;
  } else {
    foreach ($bom_resource_of_org as $key => $value) {
      echo '<option value="' . $value->bom_resource_id . '"';
      echo '>' . $value->bom_resource . '</option>';
    }
  }
  }
  ?>

</div>