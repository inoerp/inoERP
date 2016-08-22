<?php 
$readonly = 1;
$mode = 2;
if(!empty($_GET['user_id'])){
 $$class->user_id = filter_input(INPUT_GET, 'user_id', FILTER_VALIDATE_INT);
 $to_user_i = ino_user::find_by_id($$class->user_id);
 $$class->user_name = $to_user_i->username;
}

$$class->from_user_id = $ino_user->ino_user_id;
$msg_lists = extn_emessage_header::find_msg_listing($ino_user->ino_user_id);

?>