<?php
switch ($access_level) {
 case 2:
	$read_access = true;
	$mode = 2;
	break;

 case 3:
	$read_access = true;
	$write_access = true;
	break;

 case 4:
	$read_access = true;
	$write_access = true;
	$update_access = (!empty($$class) && ($$class->created_by == $_SESSION['username'])) ? true : false;
	break;

 case 5:
 case 9:
	$read_access = true;
	$write_access = true;
	$update_access = true;
	break;

 default:
	break;
}

//for user class - allow user to change their own settings
if($class_first == 'user'){
 if($_SESSION['user_id'] == $$class_first->user_id){
	$update_access = true;
 }else{
	$access_level = null;
	$update_access = false;
 }
}

?>