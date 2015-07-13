<?php include_once __DIR__.'/../../includes/basics/basics.inc'; ?>
<?php
if ($session->login_status()) {
 redirect_to(HOME_URL);
}
?>
<?php

global $dbc;
global $session;
if (!isset($msg)) {
 $msg = '';
}
$class = $class_first = 'user';
$$class = new $class;
$class_second = 'user_role';
$$class_second = new $class_second;
$class_third = 'user_password_reset';
$$class_third = new $class_third;


if (!empty($_POST['submitLogin'])) { //form is submitted for login
 $username = trim(mysql_prep($_POST['username']));
 $password = trim(mysql_prep($_POST['password']));

 $loggedin_user = $$class->authenticate($username, $password);

 If ($loggedin_user) {
	$session->login($loggedin_user);
//	$session->assign_role($_SESSION['user_id']);
	if (!empty($_SESSION['orginal_page'])) {
   redirect_to(HOME_URL . "form.php?class_name=user_dashboard_v");
//	 header('Location: http://' . $session->orginal_page);
//	 unset($_SESSION['orginal_page']);
//	 unset($session->orginal_page);
	} else {
	 redirect_to(HOME_URL . "form.php?class_name=user_dashboard_v");
	}
 } else {
	$msg .= "<div class='message error'> Username or password is incorrect <br/> </div>";
	//        echo "Actual password is ".$login_status;
 }//en of if else  
}//end of if post submit
?>
<?php include_once('../../includes/basics/header_public.inc'); ?>
<script type='text/javascript' src="user.js" ></script>
<?php

if (!empty($_POST['newUser'])) {
 $new_user = new user();
 $new_user->username = trim($_POST['username'][0]);
 $new_user->enteredPassword = trim($_POST['enteredPassword'][0]);
 $new_user->enteredRePassword = trim($_POST['enteredRePassword'][0]);
 $new_user->first_name = trim($_POST['first_name'][0]);
 $new_user->last_name = trim($_POST['last_name'][0]);
 $new_user->email = trim($_POST['email'][0]);
 if ($new_user->_before_save() == 1) {
	$new_user->audit_trial();
	$new_user->save();
	$new_user->_after_save();
	$dbc->confirm();
 }

 if (!empty($new_user->user_id)) {
	//Assign basic role
	$user_role = new user_role();
	$user_role->user_id = $new_user->user_id;
	$user_role->role_code = 'BASIC';
	$user_role->save();
	$dbc->confirm();
	$msg .= '<div class="message error"> Account is Successfully created!. Please check your mail box for further details. </div>';
 } else {
	$msg .= '<div class="message error"> Account creation failed!. Contact the admin. </div>';
 }
}

if (!empty($_POST['resetPassword'])) {
 $pr = new user_password_reset();
 $ru = new user();
 if (!empty($_POST['username'][0])) {
	$username = $_POST['username'][0];
	$resetUser = $ru->findBy_userName($username);
 } elseif (!empty($_POST['email'][0])) {
	$email = $_POST['email'][0];
	$resetUser = $ru->findBy_eMail($email);
 } else {
	$msg .='<div class="error"> No record found! Check the entered user name or email. </div>';
 }

 if (!empty($resetUser)) {
	$result_msg = $pr->generateResetPassword($resetUser);
	$msg .= '<div class="error">' . $result_msg . ' A new pasword reset link has been set to the registered email address </div>';
 }
}
?>

<?php

if (!empty($msg)) {
 $show_message = '<div class="error">';
 if(is_array($msg)){
 foreach ($msg as $key => $value) {
	$x = $key + 1;
	$show_message .= 'Message ' . $x . ' : ' . $value . '<br />';
 }
	}else{
	 $show_message = $msg;
	}
 $show_message .= '</div>';
}
?>

<?php require_once('login/user_login_template.php') ?>