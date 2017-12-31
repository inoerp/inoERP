<?php
if (!empty($_SESSION['user_id']) && empty($$class->user_id)) {
 $$class->user_id = filter_var($_SESSION['user_id'], FILTER_SANITIZE_NUMBER_INT);
}

if (!empty($$class->user_id)) {
 $user_details = ino_user::find_by_id($$class->user_id);
 $$class->username = $user_details->username;
 $$class->first_name = $user_details->first_name;
 $$class->last_name = $user_details->last_name;
}else{
 $$class->username =  $$class->first_name =  $$class->last_name = null;
}

?>