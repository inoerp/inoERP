<?php include_once("bom_department.inc"); ?>
<script src="bom_department.js"></script>
<div id="json_delete_line"> <?php json_delete('bom_department'); ?> </div>
<div id="json_bom_department_find_all">
 <?php
 if (!empty($_GET['org_id']) && ($_GET['find_all_bom_department'] = 1)) {
	$org_id = $_GET['org_id'];
	$bom_department_of_org = bom_department::find_all_of_org_id($org_id);
	if (count($bom_department_of_org) == 0) {
	 return false;
	} else {
	 foreach ($bom_department_of_org as $key => $value) {
		echo '<option value="' . $value->bom_department_id . '"';
		echo '>' . $value->bom_department . '</option>';
	 }
	}
 }
 ?>

</div>
<?php include_template('footer.inc') ?>