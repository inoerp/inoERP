<?php include_once("../../../include/basics/basics.inc"); ?>
<?php

global $db;
// if the 'term' variable is not sent with the request, exit
if (!isset($_REQUEST['term'])) {
 echo "exit";
 exit;
} else {
 $payment_term = $_REQUEST['term'];


 $data = payment_term::find_by_paymentTerm($payment_term);
// jQuery wants JSON data
 $json = json_encode($data);
 print $json;

//
}
?>