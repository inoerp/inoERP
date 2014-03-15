<?php include_once("../../../include/basics/header.inc"); ?>
<script src="bom_resource.js"></script>

<div id="json_save_header"> <?php json_save('bom', 'bom_resource', 'resource', 'bom_resource_id'); ?></div>
<div id="json_delete_line"> <?php  json_delete('bom_resource'); ?> </div>
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



<?php include_template('footer.inc') ?>