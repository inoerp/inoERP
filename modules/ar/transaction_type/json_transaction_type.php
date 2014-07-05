<?php include_once("../../../includes/basics/basics.inc"); ?>
<?php
if ((!empty($_GET['ar_transaction_type_id'])) && (!empty($_GET['find_document_detail']))) {
 $data = ar_transaction_type::find_by_id($_GET['ar_transaction_type_id']);
 if (count($data) == 0) {
	return false;
 } else {
	echo header('Content-Type: application/json');
	echo json_encode($data);
 }
}
?>