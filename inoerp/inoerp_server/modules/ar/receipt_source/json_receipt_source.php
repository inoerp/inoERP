<?php 
require_once __DIR__.'/../../../includes/basics/wloader.inc';
include_once(__DIR__.'/../../../../inoerp_server/includes/basics/basics.inc');


global $f;
if ((!empty($_GET['bu_org_id'])) && (!empty($_GET['find_receipt_source_details']))) {
 $data = [];
 $bu_org_id = $_GET['bu_org_id'];
 
 $receipt_source = ar_receipt_source::find_by_buOrgId($bu_org_id);
 $receipt_source_stmt = $f->select_field_from_object('ar_receipt_source_id', $receipt_source, 'ar_receipt_source_id', 'receipt_source', '', 'ar_receipt_source_id', '', 1);
 $data['receipt_source_stmt'] = $receipt_source_stmt;
 if (count($data) == 0) {
	return false;
 } else {
	echo header('Content-Type: application/json');
	echo json_encode($data);
 }
}
?>