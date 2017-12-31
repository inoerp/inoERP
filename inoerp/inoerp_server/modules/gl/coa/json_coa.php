<?php 

require_once __DIR__.'/../../../includes/basics/wloader.inc';
include_once(__DIR__.'/../../../../inoerp_server/includes/basics/basics.inc');

 if ((!empty($_GET['find_coa_structure'])) && (!empty($_GET['coa_structure_id']))) {
  $data = option_line::find_by_parent_id($_GET['coa_structure_id']);
  if (count($data) > 0) {
   echo header('Content-Type: application/json');
   echo json_encode($data);
  }
 }
?>