<?php 
 
 if(empty($_SESSION['user_id'])){
  $access_denied_msg = "<br> You dont have access to this notification";
  return;
 }
 
 if((!empty($$class->sys_notification_id))&& ($$class->to_user_id != $_SESSION['user_id'])){
  $access_denied_msg = "<br> You dont have access to this notification";
  return;
 }

 if($$class->status == 'CLOSED'){
  $readonly = 1; $mode = 2;
 }
 
 
 ?>