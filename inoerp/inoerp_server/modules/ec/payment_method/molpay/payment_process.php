<?php

include_once __DIR__ . '/../../../../includes/basics/basics.inc';
include_once __DIR__ . '/class_ec_payment_method_paypal.php';

if ($_POST) {
 $payment_method_id = $_POST['ec_payment_method_id'][0];
 $_SESSION['confirm_order']['sp_ec_payment_method_id'] = $payment_method_id;

 $_SESSION['confirm_order']['ship_to_id'] = $_POST['ship_to_id'][0];
 $_SESSION['confirm_order']['bill_to_id'] = $_POST['bill_to_id'][0];

 $pm_details = ec_payment_method::find_by_id($payment_method_id);
 $PayPalMode = $pm_details->mode;
 $PayPalApiUsername = $pm_details->username;
 $PayPalApiPassword = $pm_details->password;
 $PayPalApiSignature = $pm_details->signature;
 $paypalmode_d = ($PayPalMode == 'sandbox') ? '.sandbox' : '';

 $total_amount = $_POST['total_amount'][0];
 $_SESSION['confirm_order']['sp_total_amount'] = $total_amount;
 $PayPalCurrencyCode = $_POST['doc_currency'][0];
 $_SESSION['confirm_order']['sp_currency_code'] = $PayPalCurrencyCode;
 $PayPalReturnURL = HOME_URL . $pm_details->return_url;
 $PayPalCancelURL = HOME_URL . $pm_details->cancel_url;
 $site_logo_url = HOME_URL . $si->logo_path;


 //Parameters for SetExpressCheckout, which will be sent to PayPal
 $padata = '&METHOD=SetExpressCheckout' .
  '&RETURNURL=' . urlencode($PayPalReturnURL) .
  '&CANCELURL=' . urlencode($PayPalCancelURL) .
  '&PAYMENTREQUEST_0_PAYMENTACTION=' . urlencode("SALE") .
  /*
    '&L_PAYMENTREQUEST_0_NAME0='.urlencode($ItemName).
    '&L_PAYMENTREQUEST_0_NUMBER0='.urlencode($ItemNumber).
    '&L_PAYMENTREQUEST_0_DESC0='.urlencode($ItemDesc).
    '&L_PAYMENTREQUEST_0_AMT0='.urlencode($ItemPrice).
    '&L_PAYMENTREQUEST_0_QTY0='. urlencode($ItemQty).
   */

  /*
    //Additional products (L_PAYMENTREQUEST_0_NAME0 becomes L_PAYMENTREQUEST_0_NAME1 and so on)
    '&L_PAYMENTREQUEST_0_NAME1='.urlencode($ItemName2).
    '&L_PAYMENTREQUEST_0_NUMBER1='.urlencode($ItemNumber2).
    '&L_PAYMENTREQUEST_0_DESC1='.urlencode($ItemDesc2).
    '&L_PAYMENTREQUEST_0_AMT1='.urlencode($ItemPrice2).
    '&L_PAYMENTREQUEST_0_QTY1='. urlencode($ItemQty2).
   */

  /*
    //Override the buyer's shipping address stored on PayPal, The buyer cannot edit the overridden address.
    '&ADDROVERRIDE=1'.
    '&PAYMENTREQUEST_0_SHIPTONAME=J Smith'.
    '&PAYMENTREQUEST_0_SHIPTOSTREET=1 Main St'.
    '&PAYMENTREQUEST_0_SHIPTOCITY=San Jose'.
    '&PAYMENTREQUEST_0_SHIPTOSTATE=CA'.
    '&PAYMENTREQUEST_0_SHIPTOCOUNTRYCODE=US'.
    '&PAYMENTREQUEST_0_SHIPTOZIP=95131'.
    '&PAYMENTREQUEST_0_SHIPTOPHONENUM=408-967-4444'.
   */

  '&NOSHIPPING=0' . //set 1 to hide buyer's shipping address, in-case products that does not require shipping
//  '&PAYMENTREQUEST_0_ITEMAMT=' . urlencode($ItemTotalPrice) .
//  '&PAYMENTREQUEST_0_TAXAMT=' . urlencode($TotalTaxAmount) .
//  '&PAYMENTREQUEST_0_SHIPPINGAMT=' . urlencode($ShippinCost) .
//  '&PAYMENTREQUEST_0_HANDLINGAMT=' . urlencode($HandalingCost) .
//  '&PAYMENTREQUEST_0_SHIPDISCAMT=' . urlencode($ShippinDiscount) .
//  '&PAYMENTREQUEST_0_INSURANCEAMT=' . urlencode($InsuranceCost) .
  '&PAYMENTREQUEST_0_AMT=' . urlencode($total_amount) .
  '&PAYMENTREQUEST_0_CURRENCYCODE=' . urlencode($PayPalCurrencyCode) .
  '&LOCALECODE=US' . //PayPal pages to match the language on your website.
  '&LOGOIMG=' . $site_logo_url . //site logo
  '&CARTBORDERCOLOR=FFFFFF' . //border color of cart
  '&ALLOWNOTE=1';

 //We need to execute the "SetExpressCheckOut" method to obtain paypal token
 $paypal = new ec_payment_method_paypal();
 $httpParsedResponseAr = $paypal->PPHttpPost('SetExpressCheckout', $padata, $PayPalApiUsername, $PayPalApiPassword, $PayPalApiSignature, $PayPalMode);

 //Respond according to message we receive from Paypal
 if ("SUCCESS" == strtoupper($httpParsedResponseAr["ACK"]) || "SUCCESSWITHWARNING" == strtoupper($httpParsedResponseAr["ACK"])) {

  //Redirect user to PayPal store with Token received.
  $paypalurl = 'https://www' . $paypalmode_d . '.paypal.com/cgi-bin/webscr?cmd=_express-checkout&token=' . $httpParsedResponseAr["TOKEN"] . '';
  header('Location: ' . $paypalurl);
 } else {
  //Show error message
  echo '<div style="color:red"><b>Error : </b>' . urldecode($httpParsedResponseAr["L_LONGMESSAGE0"]) . '</div>';
  echo '<pre>';
  print_r($httpParsedResponseAr);
  echo '</pre>';
 }
}

//Paypal redirects back to this page using ReturnURL, We should receive TOKEN and Payer ID
if (isset($_GET["token"]) && isset($_GET["PayerID"])) {
 //we will be using these two variables to execute the "DoExpressCheckoutPayment"
 //Note: we haven't received any payment yet.

 $token = $_GET["token"];
 $payer_id = $_GET["PayerID"];
 $total_amount = $_SESSION['confirm_order']['sp_total_amount'];
 $PayPalCurrencyCode = $_SESSION['confirm_order']['sp_currency_code'];

 $payment_method_id = $_SESSION['confirm_order']['sp_ec_payment_method_id'];
 $pm_details = ec_payment_method::find_by_id($payment_method_id);
 $PayPalMode = $pm_details->mode;
 $PayPalApiUsername = $pm_details->username;
 $PayPalApiPassword = $pm_details->password;
 $PayPalApiSignature = $pm_details->signature;
 $paypalmode_d = ($PayPalMode == 'sandbox') ? '.sandbox' : '';

 $padata = '&TOKEN=' . urlencode($token) .
  '&PAYERID=' . urlencode($payer_id) .
  '&PAYMENTREQUEST_0_PAYMENTACTION=' . urlencode("SALE") .
  //set item info here, otherwise we won't see product details later	
//  '&L_PAYMENTREQUEST_0_NAME0=' . urlencode($ItemName) .
//  '&L_PAYMENTREQUEST_0_NUMBER0=' . urlencode($ItemNumber) .
//  '&L_PAYMENTREQUEST_0_DESC0=' . urlencode($ItemDesc) .
//  '&L_PAYMENTREQUEST_0_AMT0=' . urlencode($ItemPrice) .
//  '&L_PAYMENTREQUEST_0_QTY0=' . urlencode($ItemQty) .
  /*
    //Additional products (L_PAYMENTREQUEST_0_NAME0 becomes L_PAYMENTREQUEST_0_NAME1 and so on)
    '&L_PAYMENTREQUEST_0_NAME1='.urlencode($ItemName2).
    '&L_PAYMENTREQUEST_0_NUMBER1='.urlencode($ItemNumber2).
    '&L_PAYMENTREQUEST_0_DESC1=Description text'.
    '&L_PAYMENTREQUEST_0_AMT1='.urlencode($ItemPrice2).
    '&L_PAYMENTREQUEST_0_QTY1='. urlencode($ItemQty2).
   */

//  '&PAYMENTREQUEST_0_ITEMAMT=' . urlencode($ItemTotalPrice) .
//  '&PAYMENTREQUEST_0_TAXAMT=' . urlencode($TotalTaxAmount) .
//  '&PAYMENTREQUEST_0_SHIPPINGAMT=' . urlencode($ShippinCost) .
//  '&PAYMENTREQUEST_0_HANDLINGAMT=' . urlencode($HandalingCost) .
//  '&PAYMENTREQUEST_0_SHIPDISCAMT=' . urlencode($ShippinDiscount) .
//  '&PAYMENTREQUEST_0_INSURANCEAMT=' . urlencode($InsuranceCost) .
  '&PAYMENTREQUEST_0_AMT=' . urlencode($total_amount) .
  '&PAYMENTREQUEST_0_CURRENCYCODE=' . urlencode($PayPalCurrencyCode);
 //We need to execute the "DoExpressCheckoutPayment" at this point to Receive payment from user.
 $paypal = new ec_payment_method_paypal();
 $httpParsedResponseAr = $paypal->PPHttpPost('DoExpressCheckoutPayment', $padata, $PayPalApiUsername, $PayPalApiPassword, $PayPalApiSignature, $PayPalMode);

 //Check if everything went ok..
 if ("SUCCESS" == strtoupper($httpParsedResponseAr["ACK"]) || "SUCCESSWITHWARNING" == strtoupper($httpParsedResponseAr["ACK"])) {

  echo '<h2>Success</h2>';
  echo 'Your Transaction ID : ' . urldecode($httpParsedResponseAr["PAYMENTINFO_0_TRANSACTIONID"]);

  /*
    //Sometimes Payment are kept pending even when transaction is complete.
    //hence we need to notify user about it and ask him manually approve the transiction
   */

  if ('Completed' == $httpParsedResponseAr["PAYMENTINFO_0_PAYMENTSTATUS"]) {
   echo '<div style="color:green">Payment Received! Your product will be sent to you very soon!</div>';
  } elseif ('Pending' == $httpParsedResponseAr["PAYMENTINFO_0_PAYMENTSTATUS"]) {
   echo '<div style="color:red">Transaction Complete, but payment is still pending! ' .
   'You need to manually authorize this payment in your <a target="_new" href="http://www.paypal.com">Paypal Account</a></div>';
  }

  // we can retrive transection details using either GetTransactionDetails or GetExpressCheckoutDetails
  // GetTransactionDetails requires a Transaction ID, and GetExpressCheckoutDetails requires Token returned by SetExpressCheckOut
  $padata = '&TOKEN=' . urlencode($token);
  $paypal = new ec_payment_method_paypal();
  $httpParsedResponseAr = $paypal->PPHttpPost('GetExpressCheckoutDetails', $padata, $PayPalApiUsername, $PayPalApiPassword, $PayPalApiSignature, $PayPalMode);

  if ("SUCCESS" == strtoupper($httpParsedResponseAr["ACK"]) || "SUCCESSWITHWARNING" == strtoupper($httpParsedResponseAr["ACK"])) {
   $paid_order = new ec_paid_order();
   $paid_order->payment_method_id = $_SESSION['confirm_order']['sp_ec_payment_method_id'];
   $paid_order->doc_currency = $_SESSION['confirm_order']['sp_currency_code'];
   $paid_order->total_amount = $_SESSION['confirm_order']['sp_total_amount'];
   $paid_order->service_provider = 'PAYPAL';
   $paid_order->sp_transaction_id = $httpParsedResponseAr['PAYMENTREQUEST_0_TRANSACTIONID'];
   $paid_order->user_id = $_SESSION['user_id'];
   $paid_order->email = $ino_user->email;
   $paid_order->status = 'ENTERED';
   $paid_order->confirm_order_details = json_encode($_SESSION['confirm_order']);
   $paid_order->sp_return_data = json_encode($httpParsedResponseAr);
   $paid_order->save();
   $_SESSION['ec_paid_order_id'] = $paid_order->ec_paid_order_id;
   $dbc->confirm();
   redirect_to(HOME_URL . "?dtype=product&class_name=ec_order_success");
  } else {
   echo '<div style="color:red"><b>GetTransactionDetails failed:</b>' . urldecode($httpParsedResponseAr["L_LONGMESSAGE0"]) . '</div>';
   echo '<pre>';
   print_r($httpParsedResponseAr);
   echo '</pre>';
  }
 } else {
  echo '<div style="color:red"><b>Error : </b>' . urldecode($httpParsedResponseAr["L_LONGMESSAGE0"]) . '</div>';
  echo '<pre>';
  print_r($httpParsedResponseAr);
  echo '</pre>';
 }
}
?>