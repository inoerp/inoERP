<?php include_once("../../../include/basics/header.inc"); ?>
<script src="subinventory.js"></script>

<div id="json_save_header"> <?php json_save('org', 'subinventory', 'subinventory', 'subinventory_id'); ?></div>
<div id="json_delete_line"> <?php  json_delete('subinventory'); ?> </div>
<div id="json_subinventory_find_all">
  <?php
  if(!empty($_GET['org_id']) && ($_GET['find_all_subinventory'] = 1)){
   $org_id = $_GET['org_id'];
  $subinventory_of_org = subinventory::find_all_of_org_id($org_id) ;
  if (count($subinventory_of_org) == 0) {
    return false;
  } else {
    foreach ($subinventory_of_org as $key => $value) {
      echo '<option value="' . $value->subinventory_id . '"';
      echo '>' . $value->subinventory . '</option>';
    }
  }
  }
  ?>

</div>



<?php include_template('footer.inc') ?>