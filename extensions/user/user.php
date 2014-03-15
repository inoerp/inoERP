<?php $show_submit_button = 1; ?>
<?php require_once('user.inc') ?>
<?php
global $path_access;
//check if admin role is avaialable
$isAdmin = in_array('admin', $_SESSION['user_roles']);
if (!$isAdmin) {
 if (($path_access > 0) && (!empty($_GET['user_id']))) {
	$profile_userid = $_GET['user_id'];
	if ($_SESSION['user_id'] == $profile_userid) {
	 $path_access = 1;
	} else {
	 $path_access = -99;
	}
 } else {
	$path_access = -99;
 }
}
if ($path_access < 0) {
 die("You dont have access to this page! :  ");
}
?>
<?php require_once('user_template.php') ?>