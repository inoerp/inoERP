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

<?php
if ((!empty($_GET['org_type']))&& ($_GET['org_type']=='business_org')) {
 $org = new org;
 $business_orgs = $org->findAll_business();
 if (count($business_orgs) == 0) {
	return false;
 } else {
	echo header('Content-Type: application/json');
	echo json_encode($business_orgs);
 }
}
?>


<?php
if ((!empty($_GET['org_type']))&& ($_GET['org_type']=='inventory_org')) {
  $org = new org;
 $inventory_orgs = $org->findAll_inventory();
 if (count($inventory_orgs) == 0) {
	return false;
 } else {
	echo json_encode($inventory_orgs);
 }
 }
?>

<?php
if ((!empty($_GET['org_type']))&& ($_GET['org_type']=='legal_org')) {
  $org = new org;
 $legal_orgs = $org->findAll_legal();
 if (count($legal_orgs) == 0) {
	return false;
 } else {
	echo json_encode($legal_orgs);
 }
 }
?>