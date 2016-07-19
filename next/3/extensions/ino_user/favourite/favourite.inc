<?php

 $$class->user_id = $_SESSION['user_id'];

 $user = user::find_by_id($$class->user_id);
 $user_favourite_object = $$class->findBy_userId();

 if (empty($user_favourite_object)) {
  $user_favourite_object = [];
  $user_favourite = new user_favourite();
  array_push($user_favourite_object, $user_favourite);
 }
?>
