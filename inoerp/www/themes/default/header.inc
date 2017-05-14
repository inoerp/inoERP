<!DOCTYPE html>
<html>
 <head>
  <meta http-equiv="Content-Type" content="text/html; charset=UTF-8">
  <meta name="viewport" content="width=device-width, initial-scale=1">
	<?php
	if (!empty($metaname_description)) {
	 echo "<meta name='description' content=\"inoERP - A Open Source PHP based Enterprise Management System\">";
	}
	?>
  <meta name="keywords" content="ERP,PHP ERP,Open Source ERP ">
  <title><?php echo isset($pageTitle) ? $pageTitle . ' - inoERP!' : ' inoERP! ' ?></title>
  <link rel="shortcut icon" type="image/x-icon" href="files/favicon.ico">
  <link href="<?php echo THEME_URL; ?>/public.css" media="all" rel="stylesheet" type="text/css" />
  <link href="<?php echo THEME_URL; ?>/menu.css" media="all" rel="stylesheet" type="text/css" />
  <link href="<?php echo THEME_URL; ?>/jquery.css" media="all" rel="stylesheet" type="text/css" />
  <link href="<?php echo HOME_URL; ?>vendor/bootstrap/css/bootstrap.css" rel="stylesheet">
  <link href="<?php echo HOME_URL; ?>vendor/bootstrap/css/style.css" rel="stylesheet">
  <link href="<?php echo HOME_URL; ?>vendor/font-awesome/css/font-awesome.min.css" rel="stylesheet">
  <link href='https://fonts.googleapis.com/css?family=PT+Sans:400,400italic,700,700italic' rel='stylesheet' type='text/css'>
  <link href='https://fonts.googleapis.com/css?family=Lato:400,300,400italic,300italic,700,700italic,900' rel='stylesheet' type='text/css'>
  <link href='https://fonts.googleapis.com/css?family=Exo:400,300,600,500,400italic,700italic,800,900' rel='stylesheet' type='text/css'>
	<?php
	if (!empty($css_file_paths)) {
	 foreach ($css_file_paths as $key => $css_file) {
		?>
		<link href="<?php echo HOME_URL . $css_file; ?>" media="all" rel="stylesheet" type="text/css" />
		<?php
	 }
	}
	?>
	<script src="<?php echo HOME_URL; ?>js/jquery-2.0.3.min.js"></script>
	<script src="<?php echo HOME_URL; ?>js/jquery-ui.min.js"></script>
	<script src="<?php echo HOME_URL; ?>vendor/bootstrap/js/bootstrap.min.js"></script>
	<script src="<?php echo HOME_URL; ?>vendor/bootstrap/js/menu.js"></script>
	<script src="<?php echo HOME_URL; ?>js/custom/tinymce/tinymce.min.js"></script>
	<script type="text/javascript" src="<?php echo HOME_URL; ?>includes/basics/js_control.php"></script>
	<script src="<?php echo HOME_URL; ?>js/save.js"></script>
	<script src="<?php echo HOME_URL; ?>js/custom_plugins.js"></script>
	<script src="<?php echo HOME_URL; ?>js/basics.js"></script>
	<script src="<?php echo HOME_URL; ?>themes/default/js/theme.js"></script>
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
  <div id="fb-root"></div>
  <script>(function (d, s, id) {
    var js, fjs = d.getElementsByTagName(s)[0];
    if (d.getElementById(id))
     return;
    js = d.createElement(s);
    js.id = id;
    js.src = "//connect.facebook.net/en_GB/sdk.js#xfbml=1&version=v2.0";
    fjs.parentNode.insertBefore(js, fjs);
   }(document, 'script', 'facebook-jssdk'));</script>
  <nav class="navbar navbar-default navbar-fixed-top">
   <div id="topbar" class="topbar clearfix ">
    <div class="container">
     <div class="row ">
      <div class="dashborad_l col-lg-4 col-md-4 col-sm-4 col-xs-6 ">
					<?php
					$f = new inoform();
					$show_header_links = true;
					if ((!empty($mode)) && ($mode > 8) && !empty($access_level) && $access_level > 3) {
					 if (empty($current_page_path)) {
						$current_page_path = thisPage_url();
					 }
					 $f->form_button_withImage_minimum($current_page_path);
					 $show_header_links = false;
					}
					?>
					<?php if ($show_header_links) { ?>
 			 <div class="social-icons">
 				<span class="hidden-sm hidden-md hidden-lg"><a class="fa fa-navicon clickable right_navicon" href="#"></a><div id="navbar-collapse-right" class="hidden"><j class="fa fa-close ino-close-right-navbar clickable white-font-link" title="close navigation"></j><?php echo $menu_line->show_menu_list(1); ?></div></span>
 				<span><a class="fa fa-dashboard clickable erp_dashborad" href="<?php echo HOME_URL; ?>form.php?class_name=user_dashboard_v&mode=2" title="<?php echo gettext('ERP Dashboard') ?>"></a></span>
 			 </div><!-- end social icons -->
			 <?php } ?>

      </div><!-- end columns -->


      <div class="callus col-lg-6 col-md-6 col-sm-6 hidden-xs">
       <span class="topbar-email"><i class="fa fa-envelope"></i> <a href="<?php echo HOME_URL . 'content.php?mode=9&content_type=web_contact' ?>"><?php echo!empty($si->email) ? $si->email : gettext('contact@site.org'); ?></a></span>
       <span class="topbar-phone"><i class="fa fa-phone"></i> <a href="#"><?php echo!empty($si->phone_no) ? $si->phone_no : '1-111-1111' ?></a></span>
      </div><!-- end callus -->
      <div class="topbar-login col-lg-2 col-md-2 col-sm-2 col-xs-6 "><?php ino_topbar_login(); ?></div><!-- end top menu -->

     </div>
    </div><!-- end container -->
   </div>

   <header id="header-style-1">
    <div class="container ino-top-nav">
     <div class="navbar-header">
      <img src="<?php
			echo HOME_URL;
			echo!empty($si->logo_path) ? $si->logo_path : 'files/logo.png'
			?>" class="logo_image" alt="logo"/>
      <a href="<?php echo HOME_URL; ?>" class="navbar-brand"><?php echo!empty($si->site_name) ? $si->site_name : 'inoERP'; ?></a>
     </div>
     <div id="navbar-collapse-1" class="navbar-collapse collapse navbar-right"> <?php echo $menu_line->show_menu_list(1); ?></div>
    </div>
   </header>
  </nav>


	<?php
	if (!empty($showBlock)) {
	 echo '<div id="header_bottom"></div>';
	}
	?>
  <div class='content-top-padding'></div>
	<?php
//  if ($si->maintenance_cb == 1) {
//   echo "<div class='error'>Site is under maintenance mode </div>";
//  }
	?>
