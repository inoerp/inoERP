<?php

if (!empty($_GET['user_id'])) {
 $user_id_h = $_GET['user_id'];
 $cart_object = ec_cart::find_all_by_userId($user_id_h);
} else {
 $user_id_h = null;
}


if (empty($cart_object)) {
 $cart_object = [new ec_cart()];
}

$pageno = !empty($_GET['pageno']) ? $_GET['pageno'] : 1;
$per_page = !empty($_GET['per_page']) ? $_GET['per_page'] : 10;
$total_count = count($cart_object);
$pagination = new pagination($pageno, $per_page, $total_count);
$pagination->setProperty('_path', 'form');
$position = ($pageno - 1) * $per_page;
?>