<?php include_once("../../../include/basics/basics.inc"); ?>
<?php
 global $db;
// if the 'term' variable is not sent with the request, exit
if (!isset($_REQUEST['term']) ){
 echo "exit";
	exit;
}else{
$customer_name = $_REQUEST['term'];
if(!empty($_GET['bu_org_id'])){
$org_id = $_GET['bu_org_id'];
}
//echo $org_id;
$data = customer::find_customer_by_customerName($customer_name);
// jQuery wants JSON data
$json = json_encode($data);
print $json;

//

}

?>