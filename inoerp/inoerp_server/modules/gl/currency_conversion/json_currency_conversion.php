<?php 
require_once __DIR__.'/../../../includes/basics/wloader.inc';
include_once(__DIR__.'/../../../../inoerp_server/includes/basics/basics.inc');


 if ((!empty($_GET['from_currency'])) && (!empty($_GET['to_currency'])) && !empty($_GET['find_exchange_rate'])) {
  $from_currency = $_GET['from_currency'];
  $to_currency = $_GET['to_currency'];
  $rate_type = !empty($_GET['rate_type']) ? $_GET['rate_type'] : null;
  $result = gl_currency_conversion::find_rate($from_currency, $to_currency, $rate_type);
  if (count($result) == 0) {
   $data['rate'] = 0;
  }else{
   $data['rate'] = $result;
  }
  echo header('Content-Type: application/json');
  echo json_encode($data);
 }
?>