<?php 
require_once __DIR__.'/../../includes/basics/wloader.inc'; 
include_once __DIR__ . '/../../../inoerp_server/includes/basics/basics.inc'; ?>
<?php
if ($session->login_status()) {
 redirect_to(HOME_URL);
}
?>
<?php

if (!isset($msg)) {
 $msg = '';
}
$class = $class_first = 'ino_user';
$$class = new $class;
$class_second = 'user_role';
$$class_second = new $class_second;
$class_third = 'user_password_reset';
$$class_third = new $class_third;


if (!empty($_POST['submitLogin'])) { //form is submitted for login
 //check use credentials if username & provided 
 if (!empty($_POST['username']) && !empty($_POST['password'])) {
  $username = is_array($_POST['username']) ? trim(mysql_prep($_POST['username'][0])) : trim(mysql_prep($_POST['username']));
  $password = is_array($_POST['password']) ? trim(mysql_prep($_POST['password'][0])) : trim(mysql_prep($_POST['password']));
  
  $loggedin_user = $$class->authenticate($username, $password);

  If ($loggedin_user) {
   $session->login($loggedin_user);
   set_default_theme($loggedin_user);

   if (!empty($_SESSION['orginal_page']) && (strpos($session->orginal_page, 'json_form') == false)) {
//   redirect_to(HOME_URL . "form.php?class_name=user_dashboard_v");
    header('Location: http://' . $session->orginal_page);
   } else {
    redirect_to(HOME_URL . "form.php?class_name=user_dashboard_v");
   }
  } else {
   $msg .= "<div class='message error'> Username or password is incorrect <br/> </div>";
  }//en of if else  
 }
}

If (isset($_REQUEST["provider"])) {
 // the selected provider
 $provider_name = $_REQUEST["provider"];

 try {
  // inlcude HybridAuth library
  // change the following paths if necessary 
  $config = HOME_DIR . '/tparty/extensions/social_login/hybridauth/config.php';
  require_once( HOME_DIR . "/tparty/extensions/social_login/hybridauth/Hybrid/Auth.php" );

  // initialize Hybrid_Auth class with the config file
  $hybridauth = new Hybrid_Auth($config);

  // try to authenticate with the selected provider
  $adapter = $hybridauth->authenticate($provider_name);

  // then grab the user profile 
  $user_profile = $adapter->getUserProfile();
 }

 // something went wrong?
 catch (Exception $e) {
  redirect_to(HOME_URL . "access_denied.php");
 }

 // check if the current user already have authenticated using this provider before 

 
 $$class->auth_provider_name = $provider_name;
 $$class->auth_provider_id = $user_profile->identifier;
 $user_exist = $$class->findBy_providerName_and_provierId();

 // if the used didn't authenticate using the selected provider before 
 if (!empty($user_exist)) {
  $loggedin_user = $user_exist;
 } else {
  $new_user = new ino_user();
  $new_user->username = $user_profile->email;
  $new_user->email = $user_profile->email;
  $new_user->enteredPassword = $new_user->enteredRePassword = $new_user->auth_provider_id = $user_profile->identifier;
  $new_user->auth_provider_name = $provider_name;
  $new_user->first_name = $user_profile->firstName;
  $new_user->last_name = $user_profile->lastName;
  if ($new_user->_before_save() == 1) {
   $new_user->save();
   $new_user->_after_save();
   $dbc->confirm();
  } else {
   $msg .= '<div class="message error"> Account creation failed!. Contact the admin. </div>';
   redirect_to(HOME_URL . "extensions/ino_user/user_login.php?error_message=email_error");
  }

  if (!empty($new_user->ino_user_id)) {
   //Assign basic role
   $user_role = new user_role();
   $user_role->ino_user_id = $new_user->ino_user_id;
   $user_role->role_code = 'BASIC';
   $user_role->save();
   $dbc->confirm();
  }

  // set the user as connected and redirect him
  $loggedin_user = $new_user;
 }
 If (!empty($loggedin_user)) {
  $session->login($loggedin_user);
  if (!empty($_SESSION['orginal_page'])) {
   header('Location: http://' . $session->orginal_page);
  } else {
   redirect_to(HOME_URL . "form.php?class_name=user_dashboard_v");
  }
 }

 //Social login
}//end of if post submit
?>
<?php

 if (!empty($_SESSION['default_theme'])) {
  $selected_theme = $_SESSION['default_theme'];
 } else {
  set_default_theme();
  $selected_theme = $_SESSION['default_theme'];
 }

 defined('THEME_DIR') ? null : define('THEME_DIR', HOME_DIR . DS . 'themes' . DS . $selected_theme);
 defined('THEME_URL') ? null : define("THEME_URL", HOME_URL . 'themes/' . $selected_theme);
//include_once(THEME_DIR . DS. 'header.inc');
?>
<?php

if (!empty($_POST['newUser'])) {
 $new_user = new ino_user();
 $new_user->username = trim($_POST['username'][0]);
 $new_user->enteredPassword = trim($_POST['enteredPassword'][0]);
 $new_user->enteredRePassword = trim($_POST['enteredRePassword'][0]);
 $new_user->first_name = trim($_POST['first_name'][0]);
 $new_user->last_name = trim($_POST['last_name'][0]);
 $new_user->email = trim($_POST['email'][0]);
 if ($new_user->_before_save() == 1) {
  $new_user->save();
  $new_user->_after_save();
  $dbc->confirm();
 }

 if (!empty($new_user->ino_user_id)) {
  //Assign basic role
  $user_role = new user_role();
  $user_role->ino_user_id = $new_user->ino_user_id;
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
 $ru = new ino_user();
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
 if (is_array($msg)) {
  foreach ($msg as $key => $value) {
   $x = $key + 1;
   $show_message .= 'Message ' . $x . ' : ' . $value . '<br />';
  }
 } else {
  $show_message = $msg;
 }
 $show_message .= '</div>';
}
?>
<?php

if (file_exists(THEME_DIR . '/template/user_login_template.php')) {
 require_once(THEME_DIR . '/template/user_login_template.php');
} else {
 require_once('login/user_login_template.php');
}
?>