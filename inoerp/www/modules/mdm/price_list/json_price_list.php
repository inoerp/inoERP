<?php 
require_once __DIR__.'/../../../includes/basics/wloader.inc';
include_once(__DIR__.'/../../../../inoerp_server/includes/basics/basics.inc');

 if ((!empty($_GET['item_id_m'])) && (!empty($_GET['find_price']))) {
  $mdm_pl = new mdm_price_list_line();
  $mdm_pl->item_id_m = ($_GET['item_id_m']);
  $mdm_pl->price_date = !empty($_GET['price_date']) ? ($_GET['price_date']) : current_time(true);
  $mdm_pl->mdm_price_list_header_id = !empty($_GET['price_list_header_id']) ? ($_GET['price_list_header_id']) : 1;
  $mdm_pl->uom_id = !empty($_GET['uom_id']) ? ($_GET['uom_id']) : '';
  $mdm_pl->quantity = !empty($_GET['quantity']) ? ($_GET['quantity']) : '';
  $data = $mdm_pl->priceBy_itemDetails();
  if (count($data) == 0) {
   return false;
  } else {
   echo header('Content-Type: application/json');
   echo json_encode($data);
  }
 }
?>