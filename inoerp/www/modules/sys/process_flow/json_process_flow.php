<?php 
require_once __DIR__.'/../../../includes/basics/wloader.inc';
include_once(__DIR__.'/../../../../inoerp_server/includes/basics/basics.inc');


//primary column 1 is org_id
 global $db;
 $org = new org();
// if the 'term' variable is not sent with the request, exit
if (!isset($_REQUEST['term']) ){
 echo "exit";
	exit;
}else{
$item_number = $_REQUEST['term'];
if(!empty($_GET['primary_column1'])){
$org_id = $_GET['primary_column1'];
}else{
 $master_org = $org->findAll_item_master();
 $org_id = $master_org[0]->org_id;
}
//echo $org_id;
$data = item::find_item_number_by_itemNumber_OrgId($item_number, $org_id);
// jQuery wants JSON data
$json = json_encode($data);
print $json;

//

}

?>