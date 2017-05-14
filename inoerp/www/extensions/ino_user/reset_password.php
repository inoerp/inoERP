<?php
$pageTitle = " User - Create & Update all Users ";
$view_path = "user_view";
require_once __DIR__.'/../../includes/basics/basics.inc';
?>
<?php
if ($session->login_status()) {
 redirect_to(HOME_URL);
}
?>
<?php
global $dbc;
$upr = new user_password_reset();
$msg = " Invalid link. <a href='" . HOME_URL . "/extensions/ino_user/user_login.php#tabsHeader-3'>Reset password again </a>";

if (!empty($_GET['user_id']) && ($_GET['code'])) {
 $user_id = trim(mysql_prep($_GET['user_id']));
 $code = trim(mysql_prep($_GET['code']));

 $unused_code = $upr->findBy_userId($user_id);

 if ( !empty($unused_code) && $unused_code->code == $code && !empty($unused_code)) {
  $loggedin_user = ino_user::find_by_id($unused_code->user_id);
  $session->login($loggedin_user);
  $session->assign_role($_SESSION['user_id']);

  //update unused record to used record
  $new_password_request = new user_password_reset;
  $new_password_request->user_password_reset_id = $unused_code->user_password_reset_id;
  $new_password_request->status = 1;
  $new_password_request->save();
  $dbc->confirm();
 } else { //form is not submitted
  $message = $msg;
 }

 If (!empty($loggedin_user)) {
  $session->login($loggedin_user);
  set_default_theme($loggedin_user);
  redirect_to(HOME_URL . "form.php?class_name=user_dashboard_v");
//	$session->assign_role($_SESSION['user_id']);
//  if (!empty($_SESSION['orginal_page']) && (strpos($session->orginal_page, 'json_form') == false)) {
//   redirect_to('Location: http://' . $session->orginal_page);
//  } else {
//   redirect_to(HOME_URL . "form.php?class_name=user_dashboard_v");
//  }
 } else {
  $message = $msg;
  //        echo "Actual password is ".$login_status;
 }//en of if else  
}//end of if post submit
else { //form is not submitted
 $message = $msg;
}
?>

<?php include_once(__DIR__.'/../../includes/template/header_public.inc'); ?>
<link href="user.css" media="all" rel="stylesheet" type="text/css" />
<script type='text/javascript' src="user.js" ></script>
<div role="alert" class="alert alert-warning error alert-dismissible"><?php
 if (!empty($message)) {
  echo '<button type="button" class="close" data-dismiss="alert" aria-label="Close"><span aria-hidden="true">&times;</span></button>' . $message;
 }
 ?></div>