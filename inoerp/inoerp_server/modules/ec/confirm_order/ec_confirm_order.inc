<?php
//pa($_POST);
if (!empty($_POST['ec_product_id'][0]) && !empty($_POST['total_amount'][0])) {
 $_SESSION['confirm_order'] = $_POST;
 
 //update session
 $is->session_data = serialize($_SESSION);
 $is->save();
 $dbc->confirm();
}

if (empty($_SESSION['confirm_order'])) {
 ino_access_denied();
 return;
}


if (!empty($_SESSION['confirm_order']['ec_product_id'])) {
 $cart_object = [];
 foreach ($_SESSION['confirm_order']['ec_product_id'] as $key => $ec_prd_id) {
  $ec_user_cart = new ec_user_cart();
  $ec_user_cart->ec_product_id = $ec_prd_id;
  $ec_user_cart->currency = $_SESSION['confirm_order']['currency'][$key];
  $ec_user_cart->product_name = $_SESSION['confirm_order']['product_name'][$key];
  $ec_user_cart->tax_code = $_SESSION['confirm_order']['tax_code'][$key];
  $ec_user_cart->sales_price = $_SESSION['confirm_order']['sales_price'][$key];
  $ec_user_cart->quantity = $_SESSION['confirm_order']['quantity'][$key];
  array_push($cart_object, $ec_user_cart);
 }
 $tax_amount = $_SESSION['confirm_order']['tax_amount'][0];
 $total_amount = $_SESSION['confirm_order']['total_amount'][0];
}

if (empty($cart_object)) {
 $cart_object = [new ec_user_cart()];
}

$pm_all = ec_payment_method::find_all();

$pageno = !empty($_GET['pageno']) ? $_GET['pageno'] : 1;
$per_page = !empty($_GET['per_page']) ? $_GET['per_page'] : 10;
$total_count = count($cart_object);
$pagination = new pagination($pageno, $per_page, $total_count);
$pagination->setProperty('_path', 'form');
$position = ($pageno - 1) * $per_page;

//pa($_SESSION);
?>