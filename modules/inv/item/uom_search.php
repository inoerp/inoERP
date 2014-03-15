<?php include_once("../../../include/basics/basics.inc"); ?>
<?php
 global $db;
// if the 'term' variable is not sent with the request, exit
if ( !isset($_REQUEST['term']) )
	exit;
$uom = $_REQUEST['term'];
$data = uom::find_uom_by_uom($uom);
 
// jQuery wants JSON data
echo json_encode($data);
flush();
?>