<?php include_once("../../../include/basics/header.inc"); ?>
<script src="locator.js"></script>

<div id="json_save_header"> <?php json_save('org', 'locator', 'locator', 'locator_id'); ?></div>
<div id="json_delete_line"> <?php  json_delete('locator'); ?> </div>
<div id="json_locator_find_all">
  <?php
  if(!empty($_GET['subinventory_id'])&& ($_GET['find_all_locator'] = 1)){
   $subinventory_id = $_GET['subinventory_id'];
	 echo "<br/><br/><br/> sub inventory id id : $subinventory_id ";
  $locator_of_org = locator::find_all_of_subinventory($subinventory_id) ;
  if (count($locator_of_org) == 0) {
    return false;
  } else {
    foreach ($locator_of_org as $key => $value) {
      echo '<option value="' . $value->locator_id . '"';
      echo '>' . $value->locator . '</option>';
    }
  }
  }
  ?>
</div>

<?php include_template('footer.inc') ?>