<?php 
require_once __DIR__.'/../../../includes/basics/wloader.inc';
include_once(__DIR__.'/../../../../inoerp_server/includes/basics/basics.inc');

if ((!empty($_GET['sd_document_type_id'])) && (!empty($_GET['find_document_detail']))) {
 $data = sd_document_type::find_by_id($_GET['sd_document_type_id']);
 if (count($data) == 0) {
	return false;
 } else {
	echo header('Content-Type: application/json');
	echo json_encode($data);
 }
}
?>