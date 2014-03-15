<!DOCTYPE html>
<html>
 <head>
  <meta http-equiv="Content-Type" content="text/html; charset=UTF-8">
	<meta name="robots" content="noindex">
	<meta name="description" content="inoERP - A Open Source PHP/C++ based Enterprise Management System">
	<meta name="keywords" content="ERP,PHP ERP,Open Source ERP ">
  <title><?php echo isset($pageTitle) ? $pageTitle . ' - inoERP!' : ' inoERP! ' ?></title>
  <link href="<?php echo THEME_URL; ?>/layout.css" media="all" rel="stylesheet" type="text/css" />
  <link href="<?php echo THEME_URL; ?>/public.css" media="all" rel="stylesheet" type="text/css" />
  <link href="<?php echo THEME_URL; ?>/menu.css" media="all" rel="stylesheet" type="text/css" />
  <link href="<?php echo THEME_URL; ?>/jquery.css" media="all" rel="stylesheet" type="text/css" />
	<?php
	if (!empty($css_file_paths)) {
	 foreach ($css_file_paths as $key => $css_file) {
		?>
		<link href="<?php echo HOME_URL . $css_file; ?>" media="all" rel="stylesheet" type="text/css" />
		<?php
	 }
	}
	?>
  <script src="<?php echo HOME_URL; ?>includes/js/jquery-2.0.3.min.js"></script>
	<script src="http://code.jquery.com/ui/1.10.3/jquery-ui.js"></script>
  <script src="<?php echo HOME_URL; ?>includes/js/jquery.hotkeys.js"></script>
  <script src="//tinymce.cachefly.net/4.0/tinymce.min.js"></script>
	<script src="<?php echo HOME_URL; ?>includes/js/save.js"></script>
	<script src="<?php echo HOME_URL; ?>includes/js/basics.js"></script>
	<?php
	if (!empty($js_file_paths)) {
	 foreach ($js_file_paths as $key => $js_file) {
		?>
		<script src="<?php echo HOME_URL . $js_file; ?>"></script>
		<?php
	 }
	}
	?>
 </head>
 <body>
  <!--     Check if its a find page
       Exclude the header & left block section-->
	<div id="header_top_container"><?php
	 if ((!empty($mode)) && ($mode > 8)) {
		if (empty($current_page_path)) {
		 $current_page_path = thisPage_url();
		}
		form::form_button_withImage($current_page_path);
	 }
	 ?>
	</div>

	<?php
	if ($showBlock) {
	 if (!empty($_SESSION['login_status'])) {
		echo '<div id="header_top" class="clear"></div>';
	 }
	 ?>
 	<div id="header" class="clear headerBgColor">
 	 <div class="logo"><h2><?php echo "<a href=\" " . HOME_URL . " \"> " . SITE_NAME . "</a>"; ?>!</h2> </div>
 	 <div class="user_info">
		 <?php
		 if (!empty($_SESSION['login_status'])) {
			?>
			<ul><li>
				Hello <a href="<?php echo HOME_URL; ?>extensions/user/user.php?user_id=<?php echo $_SESSION['user_id']; ?>">
				 <?php echo $_SESSION['username'] . '!'; ?></a>
			 <li><a href="<?php echo HOME_URL; ?>extensions/user/user_logout.php">Logout</a> </li>
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
	if ($path_access < 0) {
	 die("<div class='error message'>You dont have access to this page! :  </dv>");
	}
	?>