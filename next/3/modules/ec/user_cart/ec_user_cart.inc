<?php
//pa($_SESSION['ec_product_id']);
if (!empty($_GET['ec_product_id'])) {
 $data_val = $_GET['ec_product_id'];
 if (!empty($_SESSION['ec_product_id'])) {
  if (!in_array($data_val, $_SESSION['ec_product_id'])) {
   array_push($_SESSION['ec_product_id'], $data_val);
  }
 } else {
  $_SESSION['ec_product_id'] = array($data_val);
 }
}

if (!empty($_SESSION['ec_product_id']) && is_array($_SESSION['ec_product_id'])) {
 $cart_object = [];
 foreach ($_SESSION['ec_product_id'] as $key => $ec_prd_id) {
  $ec_prd_details = ec_product::find_by_id($ec_prd_id);
  $ec_user_cart = new ec_user_cart();
  if($ec_prd_details){
     foreach($ec_prd_details as $file_k => $field_v){
   if(property_exists($ec_user_cart, $file_k)){
    $ec_user_cart->$file_k = $field_v;
   }
  }
  }else{
   unset($_SESSION['ec_product_id'][$key]);
  }

  array_push($cart_object, $ec_user_cart);
 }
}else{
// unset($_SESSION['ec_product_id']);
}


if (empty($cart_object)) {
 $cart_object = [new ec_user_cart()];
}

if (!empty($_GET['user_id'])) {
 $user_id_h = $_GET['user_id'];
 $existing_cart_object = ec_cart::find_all_by_userId($user_id_h);
 if ($existing_cart_object) {
  $cart_object = array_merge($cart_object, $existing_cart_object);
 }
} else {
 $user_id_h = null;
}

$pageno = !empty($_GET['pageno']) ? $_GET['pageno'] : 1;
$per_page = !empty($_GET['per_page']) ? $_GET['per_page'] : 10;
$total_count = count($cart_object);
$pagination = new pagination($pageno, $per_page, $total_count);
$pagination->setProperty('_path', 'form');
$position = ($pageno - 1) * $per_page;

$post_link_val = $prl->find_default_profile('ec_cart_forward_page') ;
$post_link = !empty($post_link_val) ? $post_link_val->level_value : '?dtype=product&class_name=ec_confirm_order';
?>