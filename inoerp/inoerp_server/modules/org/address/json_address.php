<?php 
require_once __DIR__.'/../../../includes/basics/wloader.inc';
include_once(__DIR__.'/../../../../inoerp_server/includes/basics/basics.inc');


if ((!empty($_GET['address_id'])) && !empty($_GET['find_address_details']) && ($_GET['find_address_details'] == 1)) {
 $data = address::find_by_id($_GET['address_id']);
 if (count($data) == 0) {
  return false;
 } else {
  echo header('Content-Type: application/json');
  echo json_encode($data);
 }
}
?>