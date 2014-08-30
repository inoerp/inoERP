<?php 
 
 if(empty($_SESSION['user_id'])){
  $msg = "<br> You dont have access to this notification";
  $access_deined = 1;
  return;
 }
 
 if((!empty($$class->sys_notification_id))&& ($$class->to_user_id != $_SESSION['user_id'])){
  $msg = "<br> You dont have access to this notification";
  $access_deined = 1; 
  return;
 }

 ?>