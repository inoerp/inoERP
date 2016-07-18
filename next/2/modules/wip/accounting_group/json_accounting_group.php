<?php include_once("../../../includes/basics/basics.inc"); ?>

<?php
if (!empty($_GET['org_id']) && ($_GET['find_all_accounting_group'] = 1)) {
 echo '<div id="json_accounting_group_find_all">';
 $wag = new wip_accounting_group();
 $wag->org_id = $_GET['org_id'];
 $accounting_group_of_org = $wag->findBy_orgId();
 if (empty($accounting_group_of_org)) {
	return false;
 } else {
	foreach ($accounting_group_of_org as $record) {
	 echo '<option value="' . $record->wip_accounting_group_id . '"';
	 echo '>' . $record->wip_accounting_group . '</option>';
	}
 }
 echo '</div>';
}
?>

