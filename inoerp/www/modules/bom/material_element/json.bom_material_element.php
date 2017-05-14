<?php include_once("../../../include/basics/header.inc"); ?>
<script src="bom_material_element.js"></script>

<div id="json_save_header"> <?php json_save('bom', 'bom_material_element', 'material_element', 'bom_material_element_id'); ?></div>
<div id="json_delete_line"> <?php  json_delete('bom_material_element'); ?> </div>
<div id="json_bom_material_element_find_all">
  <?php
  if(!empty($_GET['org_id']) && ($_GET['find_all_bom_material_element'] = 1)){
   $org_id = $_GET['org_id'];
  $bom_material_element_of_org = bom_material_element::find_all_of_org_id($org_id) ;
  if (count($bom_material_element_of_org) == 0) {
    return false;
  } else {
    foreach ($bom_material_element_of_org as $key => $value) {
      echo '<option value="' . $value->bom_material_element_id . '"';
      echo '>' . $value->bom_material_element . '</option>';
    }
  }
  }
  ?>

</div>



<?php include_template('footer.inc') ?>