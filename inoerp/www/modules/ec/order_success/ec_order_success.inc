<?php

if (!empty($_SESSION['ec_product_id'])) {
 $cart_object = [];
 foreach ($_SESSION['confirm_order']['ec_product_id'] as $key => $ec_prd_id) {
  $ec_prd_details = ec_product::find_by_id($ec_prd_id);
  $ec_user_cart = new ec_user_cart();
  if($ec_prd_details){
     foreach($ec_prd_details as $file_k => $field_v){
   if(property_exists($ec_user_cart, $file_k)){
    $ec_user_cart->$file_k = $field_v;
   }
  }
  }
$ec_user_cart->quantity = $_SESSION['confirm_order']['quantity'][$key];
  array_push($cart_object, $ec_user_cart);
 }
}


if (empty($cart_object)) {
 $cart_object = [new ec_user_cart()];
}

$pageno = !empty($_GET['pageno']) ? $_GET['pageno'] : 1;
$per_page = !empty($_GET['per_page']) ? $_GET['per_page'] : 10;
$total_count = count($cart_object);
$pagination = new pagination($pageno, $per_page, $total_count);
$pagination->setProperty('_path', 'form');
$position = ($pageno - 1) * $per_page;
//pa($_SESSION);

$total_amount = $_SESSION['confirm_order']['total_amount'][0];
$tax_amount = $_SESSION['confirm_order']['tax_amount'][0];

unset($_SESSION['confirm_order']);
unset($_SESSION['ec_product_id']);

 //update session
 $is->session_data = serialize($_SESSION);
 $is->save();
 $dbc->confirm();

?>