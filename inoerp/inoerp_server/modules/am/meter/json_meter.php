<?php 

require_once __DIR__.'/../../../includes/basics/wloader.inc';
include_once(__DIR__.'/../../../../inoerp_server/includes/basics/basics.inc');


if (!empty($_GET['org_id']) && ($_GET['find_all_am_meter'] = 1)) {
 echo '<div id="json_am_meter_find_all">';
 $am = new am_meter();
 $am->org_id = $_GET['org_id'];
 $am_meter_of_org = $subinv->findAll_ofOrgid();
 if (empty($am_meter_of_org)) {
	return false;
 } else {
	echo '<option value=""></option>';
	foreach ($am_meter_of_org as $key => $value) {
	 echo '<option value="' . $value->am_meter_id . '"';
	 echo '>' . $value->am_meter . '</option>';
	}
 }
 echo '</div>';
}
?>