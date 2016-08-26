<?php include_once("../../../include/basics/header.inc"); ?>
<script src="bom_standard_operation.js"></script>

<div id="json_save_header"> <?php json_save('bom', 'bom_standard_operation', 'standard_operation', 'bom_standard_operation_id'); ?></div>
<div id="json_save_line"><?php json_saveLineData('bom', 'bom_stnd_op_res_assignment', 'resource_sequence', 'bom_stnd_op_res_assignment_id'); ?></div>
<div id="json_delete_line"> <?php  json_delete('bom_standard_operation'); ?> </div>
<div id="json_bom_standard_operation_find_all">
  <?php
  if(!empty($_GET['org_id']) && ($_GET['find_all_bom_standard_operation'] = 1)){
   $org_id = $_GET['org_id'];
  $bom_standard_operation_of_org = bom_standard_operation::find_all_of_org_id($org_id) ;
  if (count($bom_standard_operation_of_org) == 0) {
    return false;
  } else {
    foreach ($bom_standard_operation_of_org as $key => $value) {
      echo '<option value="' . $value->bom_standard_operation_id . '"';
      echo '>' . $value->bom_standard_operation . '</option>';
    }
  }
  }
  ?>

</div>



<?php include_template('footer.inc') ?>