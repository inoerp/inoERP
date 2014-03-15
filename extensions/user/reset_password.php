<?php

$module_info = [
		array(
				"module" => "user",
				"class" => "user",
				"key_field" => "username",
				"primary_column" => "user_id"
		),
		array(
				"module" => "user",
				"class" => "user_role",
				"key_field" => "role_id",
				"primary_column" => "user_role_id"
		),
		array(
				"module" => "user",
				"class" => "user_password_reset",
				"key_field" => "role_id",
				"primary_column" => "user_password_reset_id"
		)
];
$pageTitle = " User - Create & Update all Users ";
$view_path = "user_view";
?>
<?php include_once('../../include/basics/header_public.inc'); ?>
<script type='text/javascript' src="user.js" ></script>
<?php

if ($session->login_status()) {
 redirect_to(HOME_URL);
}
?>
<?php

$class = $class_first = 'user';
$$class = $$class_first = &$user;
$class_second = 'user_role';
$$class_second = &$user_role;
$class_third = 'user_password_reset';
$$class_third = &$user_password_reset;

if (!empty($_GET['user_id']) && ($_GET['code'])) {
 $user_id = trim(mysql_prep($_GET['user_id']));
 $code = trim(mysql_prep($_GET['code']));

 $unused_code = user_password_reset::findUnUsedRecord_by_user_id($user_id);

 if ($unused_code->code == $code) {
	$loggedin_user = user::find_by_id($unused_code->user_id);
	$session->login($loggedin_user);
	$session->assign_role($_SESSION['user_id']);
	
	//update unused record to used record
	$new_password_request = new user_password_reset;
	$new_password_request->user_password_reset_id = $unused_code->user_password_reset_id;
	$new_password_request->status = 1;
	$new_password_request->save();
 }
 If (!empty($loggedin_user)) {
	$session->login($loggedin_user);
	$session->assign_role($_SESSION['user_id']);
	redirect_to(HOME_URL . "extensions/user/user.php?user_id=" . $_SESSION['user_id']);
 } else {
	echo " Invalid link. Reset password again";
	//        echo "Actual password is ".$login_status;
 }//en of if else  
}//end of if post submit
else { //form is not submitted
 echo " Invalid link. Reset password again";
}
?>
<?php

if (!empty($msg)) {
 $show_message = '<div class="error">';
 foreach ($msg as $key => $value) {
	$x = $key + 1;
	$show_message .= 'Message ' . $x . ' : ' . $value . '<br />';
 }
 $show_message .= '</div>';
}
?>
