<?php

 $user_id = null;
 $user_dashboard_config_object_admin = [];
 $admin = false;
 if (isset($_SESSION['is_admin']) && ($_SESSION['is_admin'] == true)) {
  $admin = true;
  if (isset($_GET['user_id'])) {
   $user_id = ($_GET['user_id']);
   $user_dashboard_config_object_admin = user_dashboard_config::find_roleAndGlobal_configs();
  }
 } else if (!empty($_SESSION['user_id'])) {
  $user_id = $_SESSION['user_id'];
  $$class->config_level = 'user';
 } else {
  access_denied('Users with admin access can only configure other users dashboard');
 }
 $$class->user_id = $user_id;
 if (!empty($user_id)) {
  $user = user::find_by_id($$class->user_id);
  $user_dashboard_config_object = $$class->findBy_userId();
 } else {
$user = new user();
 }

 if (empty($user_dashboard_config_object)) {
  $user_dashboard_config_object = [];
  $user_dashboard_config = new user_dashboard_config();
  array_push($user_dashboard_config_object, $user_dashboard_config);
 }
if(is_array($user_dashboard_config_object_admin)){
 $user_dashboard_config_object = array_merge($user_dashboard_config_object, $user_dashboard_config_object_admin);
}

$report_a = [];
 if (!empty($$class->repot_type)) {
  switch ($$class->repot_type) {
   case 'block' :
    $block_i = block::find_all();
    foreach ($block_i as $block_data) {
     $obj = new stdClass();
     $block_id = $block_data->block_id;
     $obj->$block_id = $block_data['title'];
     array_push($report_a, $obj);
    }
    break;

   case 'view' :
    $view_i = view::find_all();
    foreach ($view_i as $view_data) {
     $obj = new stdClass();
     $view_id = $view_data->view_id;
     $obj->$view_id = $block_data['name'];
     array_push($report_a, $obj);
    }
    break;
  }
 }
?>
