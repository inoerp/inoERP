<?php include_once("../../../include/basics/header.inc"); ?>
<script src="wip_wo.js"></script>

<div id="json_save_header"> <?php json_save('wip', 'wip_wo_header', 'item_id', 'wip_wo_header_id','wo_number'); ?></div>
<div id="json_save_line2"><?php json_saveLineData2('wip', 'wip_wo_bom', 'bom_sequence', 'wip_wo_bom_id'); ?></div>
<div id="json_save_line"><?php json_saveLineDetail('wip', 'wip_wo_routing_line', 'routing_sequence', 'wip_wo_routing_line_id','wip_wo_routing_detail', 'resource_sequence', 'wip_wo_routing_detail_id'); ?></div>
<div id="json_delete_line"> <?php  json_delete('wip_wo'); ?> </div>
<div id="json_wip_wo_find_all">
  <?php
  if(!empty($_GET['org_id']) && ($_GET['find_all_wip_wo'] = 1)){
   $org_id = $_GET['org_id'];
  $wip_wo_of_org = wip_wo::find_all_of_org_id($org_id) ;
  if (count($wip_wo_of_org) == 0) {
    return false;
  } else {
    foreach ($wip_wo_of_org as $key => $value) {
      echo '<option value="' . $value->wip_wo_id . '"';
      echo '>' . $value->wip_wo . '</option>';
    }
  }
  }
  ?>

</div>



<?php include_template('footer.inc') ?>