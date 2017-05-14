<?php include_once("bom_cost_type.inc"); ?>
<script src="bom_cost_type.js"></script>
<div id="json_bom_cost_type_find_all">
  <?php
  if(!empty($_GET['org_id']) && ($_GET['find_all_bom_cost_type'] = 1)){
   $org_id = $_GET['org_id'];
  $bom_cost_type_of_org = bom_cost_type::find_all_of_org_id($org_id) ;
  if (count($bom_cost_type_of_org) == 0) {
    return false;
  } else {
    foreach ($bom_cost_type_of_org as $key => $value) {
      echo '<option value="' . $value->bom_cost_type_id . '"';
      echo '>' . $value->bom_cost_type . '</option>';
    }
  }
  }
  ?>
</div>
<?php include_template('footer.inc') ?>