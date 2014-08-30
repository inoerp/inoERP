<?php include_once("../../../includes/basics/basics.inc"); ?>
<?php
global $db;
// if the 'term' variable is not sent with the request, exit
if (!isset($_REQUEST['term']))
 exit;
$supplier_name = $_REQUEST['term'];
if(!empty($_REQUEST['primary_column1'])){
$primary_column1 = $_REQUEST['primary_column1'];
}
$supplier= new supplier();
//$supplier->bu_org_id = $primary_column1;
$supplier->supplier_name = $supplier_name;
$data = $supplier->searchBy_supplier_name();

// JSON data
echo json_encode($data);
flush();
?>