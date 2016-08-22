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
  <link href="<?php
//  echo THEME_URL;
//  echo (!empty($content_class)) ? '/content_layout.css' : '/layout.css'
  ?>" media="all" rel="stylesheet" type="text/css" />
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
  <link href="<?php echo HOME_URL; ?>tparty/bootstrap/css/bootstrap.css" rel="stylesheet">
  <!-- Styles -->
  <link href="<?php echo HOME_URL; ?>tparty/bootstrap/css/style.css" rel="stylesheet">
  <!-- Carousel Slider -->
  <link href="<?php echo HOME_URL; ?>tparty/font-awesome/css/font-awesome.min.css" rel="stylesheet">
  <link href='https://fonts.googleapis.com/css?family=PT+Sans:400,400italic,700,700italic' rel='stylesheet' type='text/css'>
  <link href='https://fonts.googleapis.com/css?family=Lato:400,300,400italic,300italic,700,700italic,900' rel='stylesheet' type='text/css'>
  <link href='https://fonts.googleapis.com/css?family=Exo:400,300,600,500,400italic,700italic,800,900' rel='stylesheet' type='text/css'>
  <script src="<?php echo HOME_URL; ?>includes/js/jquery-2.0.3.min.js"></script>
  <script src="<?php echo HOME_URL; ?>includes/js/jquery-ui.min.js"></script>
  <script src="<?php echo HOME_URL; ?>tparty/bootstrap/js/bootstrap.min.js"></script>
  <script src="<?php echo HOME_URL; ?>tparty/bootstrap/js/menu.js"></script>
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
     <div class="row">
      <?php
      if (!empty($showBlock)) {
       echo '<div id = "header_top" class = "clear"></div>';
      }
      ?>
      <div class="col-lg-4 col-md-4 col-sm-4 col-xs-4">
       <?php
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
         <span><a class="fa fa-dashboard clickable erp_dashborad" href="<?php echo HOME_URL ?>form.php?class_name=user_dashboard_v&mode=2" title="ERP Dashboard"> ERP Dashboard </a></span>
        </div><!-- end social icons -->
       <?php } ?>

      </div><!-- end columns -->

      <div class="col-lg-8 col-md-8 col-sm-8 ">
       <div class="topmenu">
        <div class="topbar-login">
         <?php if (!empty($_SESSION['login_status'])) { ?>
          <div class="dropdown">
           <button class="btn btn-default dropdown-toggle" type="button" id="menu1" data-toggle="dropdown"><i class="fa fa-user"> </i><?php echo ' ' . ucfirst($_SESSION['username']); ?>
            <span class="caret"></span></button>
           <ul class="dropdown-menu" role="menu" aria-labelledby="menu1">
            <!--<li role="presentation" class="dropdown-header">Dropdown header 1</li>-->
            <li role="presentation"><a role="menuitem" tabindex="-1" href="<?php echo HOME_URL; ?>"><i class="fa fa-home"></i> Home</a></li>
            <li role="presentation"><a role="menuitem" tabindex="-1" href="<?php echo HOME_URL . 'form.php?class_name=user&mode=9&user_id=' . $_SESSION['user_id']; ?>"> My Details</a></li>
            <li role="presentation"><a role="menuitem" class="pull-right" tabindex="-1" href="<?php echo HOME_URL . 'form.php?class_name=user_activity_v&amp;mode=2&amp;user_id=' . $_SESSION['user_id']; ?>"><i class="fa fa-tasks"></i> Activities</a></li>
            <li role="presentation"><a role="menuitem" class="pull-right" tabindex="-1" href="<?php echo HOME_URL . 'search.php?class_name=sys_notification_user'; ?>"><i class="fa fa-bell-slash-o"></i> Notification</a></li>
            <li role="presentation"><a role="menuitem"  tabindex="-1" href="<?php echo HOME_URL . 'form.php?class_name=user_dashboard_v&amp;mode=2&amp;user_id=' . $_SESSION['user_id']; ?>"><i class="fa fa-dashboard"></i> Dashboard</a></li>
            <li role="presentation"><a role="menuitem"  tabindex="-1" href="<?php echo HOME_URL . 'form.php?class_name=user_dashboard_config&amp;mode=9&amp;user_id=' . $_SESSION['user_id']; ?>"><i class="fa fa-cog"></i> Configure</a></li>
            <li role="presentation" class="divider"></li>
            <li role="presentation"><a role="menuitem"  tabindex="-1" href="<?php echo HOME_URL . 'extensions/ino_user/user_logout.php'; ?>"><i class="fa fa-sign-out"></i> LogOut</a></li>
           </ul>
          </div>

          <?php
         } else {
          if (file_exists(__DIR__ . '/template/user_popup_login_template.php')) {
           require_once(__DIR__ . '/template/user_popup_login_template.php');
          } else {
           require_once('login/user_popup_login_template.php');
          }
         }
         ?>
        </div>

       </div><!-- end top menu -->
       <div class="callus hidden-xs">
        <span class="topbar-email"><i class="fa fa-envelope"></i> <a href="<?php echo HOME_URL . 'content.php?mode=9&content_type=web_contact' ?>"><?php echo!empty($si->email) ? $si->email : 'contact@site.org' ?></a></span>
        <span class="topbar-phone"><i class="fa fa-phone"></i> <a href="#"><?php echo!empty($si->phone_no) ? $si->phone_no : '1-111-1111' ?></a></span>
       </div><!-- end callus -->
      </div><!-- end columns -->
     </div>
    </div><!-- end container -->
   </div><!-- end topbar -->

   <header id="header-style-1">
    <div class="container">
     <nav class="navbar yamm navbar-default ">
      <div class="navbar-header">
       <img src="<?php
       echo HOME_URL;
       echo!empty($si->logo_path) ? $si->logo_path : 'files/logo.png'
       ?>" class="logo_image" alt="logo"/>
       <a href="<?php echo HOME_URL; ?>" class="navbar-brand"><?php echo!empty($si->site_name) ? $si->site_name : 'inoERP'; ?></a>
      </div>
      <div id="navbar-collapse-1" class="navbar-collapse collapse navbar-right">
       <ul class="nav nav-pills">
        <li><a href="http://inoideas.org/content/demo" >Demo <div class="arrow-up"></div></a></li>
        <li><a href="https://github.com/inoerp/inoERP" >Download <div class="arrow-up"></div></a></li>
        <li class="active"><a href="<?php echo HOME_URL; ?>content.php?mode=9&content_type=forum&category_id=7" ><i class="fa fa-comments-o"></i> Ask a Question <div class="arrow-up"></div></a></li>
        <li><a href="<?php echo HOME_URL; ?>content.php?content_type=documentation&amp;category_id=30">Documentation <div class="arrow-up"></div></a></li><!-- end standard drop down -->
        <li><a href="<?php echo HOME_URL; ?>content.php?content_type=forum&amp;category_id=1">Forum <div class="arrow-up"></div></a></li>
        <li role="presentation" class="dropdown">
         <a class="dropdown-toggle" data-toggle="dropdown" href="#" role="button" aria-expanded="false">
          More <span class="caret"></span>
         </a>
         <ul class="dropdown-menu" role="menu">
          <li><a href="<?php echo HOME_URL; ?>">Home <div class="arrow-up"></div></a></li>
          <li><a href="<?php echo HOME_URL; ?>content.php?mode=2&amp;content_id=197&amp;content_type_id=47">About <div class="arrow-up"></div></a> </li><!-- end drop down -->
         </ul>
        </li>
       </ul><!-- end navbar-nav -->
      </div><!-- #navbar-collapse-1 -->			
     </nav>
    </div><!-- end container -->
   </header><!-- end header-style-1 -->
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