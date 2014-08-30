<?php

 class sys_notification_user extends sys_notification {

  public function search_pre_populate() {
   return array('to_user_id' => $_SESSION['user_id']);
  }

 }

//end of sys_notification class
?>