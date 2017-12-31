<?php 
require_once __DIR__.'/../../../includes/basics/wloader.inc';
include_once(__DIR__.'/../../../../inoerp_server/includes/basics/basics.inc');


if ((!empty($_GET['ar_transaction_type_id'])) && (!empty($_GET['find_ar_transaction_type_detail']))) {
 $data = [];
 $transaction_type_details = ar_transaction_type::find_by_id($_GET['ar_transaction_type_id']);
 foreach($transaction_type_details as $key => $val){
	$data[$key] = $val;
 }
 $rece_ac = coa_combination::find_by_id($data['receivable_ac_id'])->combination ;
 $data['receivable_ac'] = $rece_ac;
 if (count($data) == 0) {
	return false;
 } else {
	echo header('Content-Type: application/json');
	echo json_encode($data);
 }
}
?>