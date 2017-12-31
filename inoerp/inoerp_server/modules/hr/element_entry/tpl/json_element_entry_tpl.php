<?php 
require_once __DIR__.'/../../../includes/basics/wloader.inc';
include_once(__DIR__.'/../../../../inoerp_server/includes/basics/basics.inc');


if ((!empty($_GET['find_element_entry_tpl']))) {
$data = hr_element_entry_tpl_header::find_all();
 if (count($data) == 0) {
  return false;
 } else {
  echo header('Content-Type: application/json');
  echo json_encode($data);
 }
}
?>