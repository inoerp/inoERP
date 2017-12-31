<?php include_once("../../../include/basics/header.inc"); ?>
<script src="bom_overhead.js"></script>

<div id="json_save_header"> <?php json_save('bom', 'bom_overhead', 'overhead', 'bom_overhead_id'); ?></div>
<div id="json_save_line"><?php json_saveLineData('bom', 'bom_oh_res_assignment', 'resource_id', 'bom_oh_res_assignment_id'); ?></div>
<div id="json_save_line2"><?php json_saveLineData2('bom', 'bom_oh_rate_assignment', 'department_id', 'bom_oh_rate_assignment_id'); ?></div>
<div id="json_delete_line"> <?php  json_delete('bom_overhead'); ?> </div>
<div id="json_bom_overhead_find_all">
  <?php
  if(!empty($_GET['org_id']) && ($_GET['find_all_bom_overhead'] = 1)){
   $org_id = $_GET['org_id'];
  $bom_overhead_of_org = bom_overhead::find_all_of_org_id($org_id) ;
  if (count($bom_overhead_of_org) == 0) {
    return false;
  } else {
    foreach ($bom_overhead_of_org as $key => $value) {
      echo '<option value="' . $value->bom_overhead_id . '"';
      echo '>' . $value->bom_overhead . '</option>';
    }
  }
  }
  ?>

</div>



<?php include_template('footer.inc') ?>