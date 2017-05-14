<?php 
require_once __DIR__.'/../../../includes/basics/wloader.inc';
include_once(__DIR__.'/../../../../inoerp_server/includes/basics/basics.inc');


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