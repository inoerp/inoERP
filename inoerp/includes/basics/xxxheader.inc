<?php require_once 'basics.inc' ?>
<?php
if (!empty($dont_check_login)) {
 
} else {
 $session->redirect_login();
}
?>
<?php $url = $_SERVER['REQUEST_URI']; ?><!DOCTYPE html>
<html>
 <head>
  <meta http-equiv="Content-Type" content="text/html; charset=UTF-8">
	<meta name="robots" content="noindex">
	<meta name="description" content="inoERP - A Open Source PHP/C++ based Enterprise Management System">
	<meta name="keywords" content="ERP,PHP ERP,Open Source ERP ">
  <title><?php echo isset($pageTitle) ? $pageTitle . ' - inoERP!' : ' inoERP! ' ?></title>
  <link href="<?php echo THEME_URL; 
	echo (!empty($content_class))? '/content_layout.css' : '/layout.css' ?>" media="all" rel="stylesheet" type="text/css" />
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
  <script src="<?php echo HOME_URL; ?>includes/js/custom/tinymce/tinymce.min.js"></script>
	<script src="<?php echo HOME_URL; ?>includes/js/save.js"></script>
	<script src="<?php echo HOME_URL; ?>includes/js/custom_plugins.js"></script>
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
	$show_header_links = true;
	 if ((!empty($mode)) && ($mode > 8) && !empty($access_level) && $access_level > 3) {
		if (empty($current_page_path)) {
		 $current_page_path = thisPage_url();
		}
		form::form_button_withImage($current_page_path);
		$show_header_links = false;
	 }
	 ?></div>

	<?php
	if (!empty($showBlock)) {
	 echo '<div id="header_top" class="clear"></div>';
//	 if (!empty($_SESSION['login_status'])) {
//		echo '<div id="header_top" class="clear"></div>';
//	 }
	 ?>
  	<div id="header" class="clear headerBgColor">
  	 <div class="logo"><h2><?php global $si;
		 echo "<a href=\" " . HOME_URL . " \"> " . $si->site_name . "</a>"; ?>!</h2> </div>
 	 <div class="header_right">
		<?php if($show_header_links) { ?>
 		<div class="header_info">
 		 <ul class="inRow asperWidth"> 
 			<li><a href="http://demo.inoideas.org/"><?php echo gettext('Demo') ?></a></li>
			<li><a href="https://github.com/inoerp/inoerp_v1"><?php echo gettext('Download') ?></a></li>
 			<li><a href="<?php echo HOME_URL ?>content.php?content_type=documentation&category_id=30"><?php echo gettext('Documentation') ?></a></li>
 			<li><a href="<?php echo HOME_URL ?>content.php?content_type=forum&category_id=1"><?php echo gettext('Forum') ?></a></li>
 			<li><a href="http://inoideas.org/content.php?mode=2&content_id=197&content_type_id=47"><?php echo gettext('About') ?></a></li>
 		 </ul>
 		</div>
		<?php } ?>
 		<div class="user_info">
			<?php
			if (!empty($_SESSION['login_status'])) {
			 ?>
			 <ul class="inRow asperWidth"><li class="white_link">
				 Hello <a  href="<?php echo HOME_URL; ?>form.php?class_name=user&mode=9&user_id=<?php echo $_SESSION['user_id']; ?>">
					<?php echo $_SESSION['username'] . '!'; ?></a>
				<li><a class="login_button"  href="<?php echo HOME_URL; ?>extensions/ino_user/user_logout.php"><?php echo gettext('LogOut') ?></a> </li>
			 </ul>
			<?php } else { ?>
			 <ul class="inRow asperWidth">
				<li class>
				 <a class="login_button" href="<?php echo HOME_URL; ?>extensions/ino_user/user_login.php#tabsLine-1"><?php echo gettext('Sign In') ?></a>
				<li>
				 <a class="login_button" href="<?php echo HOME_URL; ?>extensions/ino_user/user_login.php#tabsLine-2"><?php echo gettext('Register') ?></a>
				</li>
			 </ul>

			<?php } ?>
 		</div>	
 	 </div>

  	</div>
  	<div id="header_bottom"></div>
	<?php } ?>
