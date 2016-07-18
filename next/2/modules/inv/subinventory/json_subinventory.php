<?php include_once("../../../includes/basics/basics.inc"); ?>

<?php

if (!empty($_GET['org_id']) && ($_GET['find_all_subinventory'] = 1)) {
 echo '<div id="json_subinventory_find_all">';
 $subinv = new subinventory();
 $subinv->org_id = $_GET['org_id'];
 $subinventory_of_org = $subinv->findAll_ofOrgid();
 if (empty($subinventory_of_org)) {
	return false;
 } else {
	echo '<option value=""></option>';
	foreach ($subinventory_of_org as $key => $value) {
	 echo '<option value="' . $value->subinventory_id . '"';
	 echo '>' . $value->subinventory . '</option>';
	}
 }
 echo '</div>';
}
?>

