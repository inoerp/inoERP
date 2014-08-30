<?php include_once("../../../includes/basics/basics.inc"); ?>
<?php

global $db;
// if the 'term' variable is not sent with the request, exit
if (!isset($_REQUEST['term']))
 exit;
$coa_combination = $_REQUEST['term'];
if(!empty($_REQUEST['primary_column1'])){
$primary_column1 = $_REQUEST['primary_column1'];
}else{
 $primary_column1 = 1;
}
$cc = new coa_combination();
$cc->coa_id = $primary_column1;
$cc->combination = $coa_combination;
$data = $cc->searchBy_coaId_combination();

// jQuery wants JSON data
echo json_encode($data);
flush();
?>