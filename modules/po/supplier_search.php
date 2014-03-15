<?php include_once("../../../include/basics/basics.inc"); ?>
<?php
 global $db;
// if the 'term' variable is not sent with the request, exit
if (!isset($_REQUEST['term']) ){
 echo "exit";
	exit;
}else{
$supplier_number = $_REQUEST['term'];
if(!empty($_GET['org_id'])){
$org_id = $_GET['org_id'];
}else{
 $master_org = org::find_all_supplier_master();
 $org_id = $master_org[0]->org_id;
}
//echo $org_id;
$data = supplier::find_supplier_number_by_supplierNumber_OrgId($supplier_number, $org_id);
// jQuery wants JSON data
$json = json_encode($data);
print $json;

//

}

?>