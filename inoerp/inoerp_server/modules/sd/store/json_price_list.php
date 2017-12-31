<?php 

require_once __DIR__.'/../../../includes/basics/wloader.inc';
include_once(__DIR__.'/../../../../inoerp_server/includes/basics/basics.inc');

 if ((!empty($_GET['item_id_m'])) && (!empty($_GET['find_price']))) {
  $price_date = !empty($_GET['price_date']) ? ($_GET['price_date']) : current_time(true);
  $price_list_header_id = !empty($_GET['price_list_header_id']) ? ($_GET['price_list_header_id']) : 1;
  $data = mdm_price_list_line::priceBy_headerId_ItemId($_GET['item_id_m'], $price_date, $price_list_header_id);
  if (count($data) == 0) {
   return false;
  } else {
   echo header('Content-Type: application/json');
   echo json_encode($data);
  }
 }
?>