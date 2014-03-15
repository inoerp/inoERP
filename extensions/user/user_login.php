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
<?php include_once('../../includes/basics/header_public.inc'); ?>
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

if (!empty($_POST['submitLogin'])) { //form is submitted for login
 $username = trim(mysql_prep($_POST['username']));
 $password = trim(mysql_prep($_POST['password']));

 $loggedin_user = user::authenticate($username, $password);

 If ($loggedin_user) {
	$session->login($loggedin_user);
	$session->assign_role($_SESSION['user_id']);

	if (!empty($session->orginal_page)) {
	 header('Location: http://' . $session->orginal_page);
	 unset($_SESSION['orginal_page']);
	 unset($session->orginal_page);
	} else {
	 redirect_to(HOME_URL . "index.php");
	}
 } else {
	echo "<div class='message error'> Username or password is incorrect <br/> </div>";
	//        echo "Actual password is ".$login_status;
 }//en of if else  
}//end of if post submit

if (!empty($_POST['newUser'])) {
// echo '<pre>';
// print_r($_POST);
 $_POST = user::user_verification_update($_POST);
 
 if(!empty($_POST)){
 $_POST['submit_user'] = 1;
 $$class = Pre_Loading_Function('user', 'user', 'username', 'user_id');
  }
 
  if (!empty($$class->user_id)) {
	 //Assign basic role
	 $user_role = new user_role;
	 $user_role->user_id = $$class->user_id;
	 $user_role->role_id=261;
	 $user_role->save();
	echo '<div class="message error"> Account is sucessfully created!. Please check your mail box. </div>';
 } else {
	echo '<div class="message error"> Account creation failed!. Contact the admin. </div>';
 }
}

if (!empty($_POST['resetPassword'])) {
// echo '<pre>';
// print_r($_POST);
 if (!empty($_POST['username'][0])) {
	$username = $_POST['username'][0];
	$resetUser = user::find_by_username($username);
 } elseif (!empty($_POST['email'][0])) {
	$email = $_POST['email'][0];
	$resetUser = user::find_by_email($email);
 } else {
	echo '<div class="error"> Password reset failed! Enter user name or email id to reset password. </div>';
 }

 if (!empty($resetUser)) {
	$result_msg = user_password_reset::generateResetPassword($resetUser);
	echo '<div class="error">' . $result_msg . ' A new pasword reset link has been set to the registered email address </div>';
 }
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

<?php require_once('user_login_template.php') ?>