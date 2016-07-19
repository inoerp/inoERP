<?php

include_once __DIR__ . '/../../../../includes/basics/basics.inc';
include_once __DIR__ . '/class_ec_payment_method_cod.php';

if ($_POST) {
 $payment_method_id = $_POST['ec_payment_method_id'][0];
 $_SESSION['confirm_order']['sp_ec_payment_method_id'] = $payment_method_id;

 $_SESSION['confirm_order']['ship_to_id'] = $_POST['ship_to_id'][0];
 $_SESSION['confirm_order']['bill_to_id'] = $_POST['bill_to_id'][0];

 $pm_details = ec_payment_method::find_by_id($payment_method_id);


 $total_amount = $_POST['total_amount'][0];
 $_SESSION['confirm_order']['sp_total_amount'] = $total_amount;
 $codCurrencyCode = $_POST['doc_currency'][0];
 $_SESSION['confirm_order']['sp_currency_code'] = $codCurrencyCode;

 $paid_order = new ec_paid_order();
 $paid_order->payment_method_id = $_SESSION['confirm_order']['sp_ec_payment_method_id'];
 $paid_order->doc_currency = $_SESSION['confirm_order']['sp_currency_code'];
 $paid_order->total_amount = $_SESSION['confirm_order']['sp_total_amount'];
 $paid_order->service_provider = 'cod';
 $paid_order->sp_transaction_id = $_SESSION['user_id'].'-'.current_time();
 $paid_order->user_id = $_SESSION['user_id'];
 $paid_order->email = $ino_user->email;
 $paid_order->status = 'ENTERED';
 $paid_order->confirm_order_details = json_encode($_SESSION['confirm_order']);
 $paid_order->save();
 $_SESSION['ec_paid_order_id'] = $paid_order->ec_paid_order_id;
 $dbc->confirm();
 if(!empty($paid_order->ec_paid_order_id)){
  redirect_to(HOME_URL . "?dtype=product&class_name=ec_order_success");
 }else{
  echo "Error in creating order";
  pa($paid_order);
 }
 
}
?>