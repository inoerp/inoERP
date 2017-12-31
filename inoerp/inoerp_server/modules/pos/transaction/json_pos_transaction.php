<?php 
require_once __DIR__.'/../../../includes/basics/wloader.inc';
include_once(__DIR__.'/../../../../inoerp_server/includes/basics/basics.inc');

 if ((!empty($_GET['save_terminal_name'])) && (!empty($_GET['terminal_name']))) {
  $terminal_name = !empty($_GET['terminal_name']) ? ($_GET['terminal_name']) : '';
    try{
   $_SESSION['terminal_name'] = $terminal_name;
   $data = ['result' => 'Terminal name is Successfully Saved'];
  }catch(Exception $e){
   $data = ['result' => 'Action Faield! Terminal name is not saved'];
  }

  if (count($data) == 0) {
   return false;
  } else {
   echo header('Content-Type: application/json');
   echo json_encode($data);
  }
 }
?>