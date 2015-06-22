<?php include_once("../../includes/basics/basics.inc"); ?>
<?php
if ((!empty($_GET['org_type']))&& ($_GET['org_type']=='enterprise_org')) {
  $org = new org;
 $enterprises = $org->findAll_enterprise();
 if (count($enterprises) == 0) {
	return false;
 } else {
	echo header('Content-Type: application/json');
	echo json_encode($enterprises);
 }
}
?>