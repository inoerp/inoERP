<?php require_once 'basics.inc' ?>
<?php
if (!empty($dont_check_login)) {
 
} else {
 $session->redirect_login();
}
?>
<?php $url = $_SERVER['REQUEST_URI']; ?>
<!--inoEMS - The First Enterprise Management System!-->
<!DOCTYPE html>
<html>
 <head>
  <meta http-equiv="Content-Type" content="text/html; charset=UTF-8">
	<meta name="robots" content="noindex">
	<meta name="description" content="inoERP - A Open Source PHP/C++ based Enterprise Management System">
	<meta name="keywords" content="ERP,PHP ERP,Open Source ERP ">
  <title><?php echo isset($pageTitle) ? $pageTitle . ' - inoERP!' : ' inoERP! ' ?></title>
  <link href="<?php echo HOME_URL; ?>themes/layout.css" media="all" rel="stylesheet" type="text/css" />
  <link href="<?php echo HOME_URL; ?>themes/public.css" media="all" rel="stylesheet" type="text/css" />
  <link href="<?php echo HOME_URL; ?>themes/menu.css" media="all" rel="stylesheet" type="text/css" />
  <link href="<?php echo HOME_URL; ?>themes/jquery.css" media="all" rel="stylesheet" type="text/css" />
  <script src="<?php echo HOME_URL; ?>includes/js/jquery-2.0.3.min.js"></script>
  <script src="http://code.jquery.com/ui/1.10.3/jquery-ui.js"></script>
  <script src="<?php echo HOME_URL; ?>includes/js/jquery.hotkeys.js"></script>
  <script src="//tinymce.cachefly.net/4.0/tinymce.min.js"></script>
	<script src="<?php echo HOME_URL; ?>includes/js/save.js"></script>
	<script src="<?php echo HOME_URL; ?>includes/js/basics.js"></script>
 </head>
 <body>
  <!--     Check if its a find page
       Exclude the header & left block section-->
	<?php
	$is_find_page = 0;
	$r_url = trim($_SERVER['REQUEST_URI']);
	$r_url_expl = explode("/", $r_url);
	$pattern = '/^select/';
	foreach ($r_url_expl as $key => $value) {
	 $is_find_page = $is_find_page || preg_match($pattern, $value);
	}

	if (!$is_find_page) {
	 if (!empty($_SESSION['login_status'])) {
		echo '<div id="header_top"></div>';
	 }
	 ?>
  	<div id="header" class="headerBgColor">
  	 <div class="logo"><h2><?php echo "<a href=\" " . HOME_URL . " \"> " . SITE_NAME . "</a>"; ?>!</h1> </div>
  	 <div class="header_info"><?php
		 if ((!empty($mode)) && ($mode > 8)) {
			if (empty($current_page_path)) {
			 $current_page_path = thisPage_url();
			}
			form::form_button_withImage($current_page_path);
			$readonly = null;
		 } else {
			$readonly = 1;
		 }
		 ?></div>
  	 <div class="user_info">
		 <?php
		 if (!empty($_SESSION['login_status'])) {
			?>
			<ul>
			 <li>
				Hello <a href="<?php echo HOME_URL; ?>extensions/user/user.php?user_id=<?php echo $_SESSION['user_id']; ?>">
				 <?php echo $_SESSION['username'] . '!'; ?></a>
			 <li>
				<a href="<?php echo HOME_URL; ?>extensions/user/user_logout.php">Logout</a>
			 </li>
			</ul>
		 <?php } else { ?>
			<ul class="inRow asperWidth">
			 <li>
				<a class="button" href="<?php echo HOME_URL; ?>extensions/user/user_login.php#tabsLine-1">Sign In</a>
			 <li>
				<a class="button" href="<?php echo HOME_URL; ?>extensions/user/user_login.php#tabsLine-2">Create Account</a>
			 </li>
			</ul>

		 <?php } ?>
  	 </div>
  	</div>
  	<div id="header_bottom"></div>
	 <?php // echo (!empty($header_bottom)) ? "<div id=\"header_bottom\"> $header_bottom </div>" : "" ;   ?>
	<?php } ?>
	<?php
	global $path_access;
//	echo '<br/>path_access is '. $path_access;
	if ((($path_access < 0))) {
	 die("<div class='error message'>You dont have access to this page! :  </dv>");
	}

	if (!empty($msg)) {
	 $show_message = '<div class="error">';
	 foreach ($msg as $key => $value) {
		$x = $key + 1;
		$show_message .= 'Message ' . $x . ' : ' . $value . '<br />';
	 }
	 $show_message .= '</div>';
	}

	if (!empty($ie->page_exception)) {
	 $show_message = '<div class="error">';
	 pa($ie->page_exception);
	 $show_message .= '</div>';
	}
	?>
