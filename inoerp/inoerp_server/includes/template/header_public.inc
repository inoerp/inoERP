<?php require_once __DIR__.'/../basics/basics.inc';
check_browser(); ?>  
<!DOCTYPE html>
<html>
 <head>
  <meta http-equiv="Content-Type" content="text/html; charset=UTF-8">
  <?php
  if (!empty($metaname_description)) {
   echo "<meta name='description' content=\"inoERP - A Open Source PHP based Enterprise Management System\">";
  }
  ?>
  <meta name="keywords" content="ERP,PHP ERP,Open Source ERP ">
  <title><?php echo isset($pageTitle) ? $pageTitle . ' - inoERP!' : ' inoERP! ' ?></title>
  <link href="<?php echo HOME_URL; ?>/themes/default/public.css" media="all" rel="stylesheet" type="text/css" />
  <link href="<?php echo HOME_URL; ?>/themes/default/menu.css" media="all" rel="stylesheet" type="text/css" />
  <link href="<?php echo HOME_URL; ?>/themes/default/jquery.css" media="all" rel="stylesheet" type="text/css" />
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
  <link href='http://fonts.googleapis.com/css?family=PT+Sans:400,400italic,700,700italic' rel='stylesheet' type='text/css'>
  <link href='http://fonts.googleapis.com/css?family=Lato:400,300,400italic,300italic,700,700italic,900' rel='stylesheet' type='text/css'>
  <link href='http://fonts.googleapis.com/css?family=Exo:400,300,600,500,400italic,700italic,800,900' rel='stylesheet' type='text/css'>
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

  <div id="topbar" class="topbar clearfix">
   <div class="container">
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
      $f->form_button_withImage($current_page_path);
      $show_header_links = false;
     }
     ?>
<?php if ($show_header_links) { ?>
        <div class="social-icons">
         <span class="hidden-sm hidden-md hidden-lg"><a class="fa fa-navicon clickable right_navicon" href="#"></a><div id="navbar-collapse-right" class="hidden"><j class="fa fa-close ino-close-right-navbar clickable white-font-link" title="close navigation"></j><?php  echo $menu_line->show_menu_list(1);    ?></div></span>
         <span><a class="fa fa-dashboard clickable erp_dashborad" href="form.php?class_name=user_dashboard_v&mode=2" title="<?php echo gettext('ERP Dashboard') ?>"></a></span>
        </div><!-- end social icons -->
<?php } ?>

    </div><!-- end columns -->
    <div class="col-lg-8 col-md-8 col-sm-8 col-xs-8">
     <div class="topmenu">
      <div class="topbar-login">
       <?php
       if (!empty($_SESSION['login_status'])) {
        echo ' <i class="fa fa-user"></i>
        <ul class="nav navbar-nav">';
        echo '<li class="dropdown"><a aria-expanded="true" role="button" data-toggle="dropdown" class="dropdown-toggle" '
        . 'href="' . HOME_URL . 'form.php?class_name=user&amp;mode=9&amp;user_id=' . $_SESSION['user_id'] . '">';
        echo ucfirst($_SESSION['username']) . '! <span class="caret"></span></a>';
        echo '<ul role="menu" class="dropdown-menu">';
        echo '<li><a  href="' . HOME_URL . '">Home</a> </li>';
        echo '<li><a href="' . HOME_URL . 'form.php?class_name=user&mode=9&user_id=' . $_SESSION['user_id'] . '">User Details</a></li>';
        echo '<li class="child_link"><a href="' . HOME_URL . 'form.php?class_name=user_activity_v&amp;mode=2&amp;user_id=' . $_SESSION['user_id'] . '">Activities</a></li>';
        echo '<li class="child_link"><a href = "' . HOME_URL . 'search.php?class_name=sys_notification_user">' . gettext('All Notifications') . '</a></li>';
        echo '<li data-path_description = "Dashboard">
       <a href = "' . HOME_URL . 'form.php?class_name=user_dashboard_v&amp;mode=2&amp;user_id=' . $_SESSION['user_id'] . '">Dashboard</a>
       </li>
       <li data-path_description = "Dashboard Configuration" class="child_link">
       <a href = "' . HOME_URL . 'form.php?class_name=user_dashboard_config&amp;mode=9&amp;user_id=' . $_SESSION['user_id'] . '">Configure</a>
       </li>';
        echo '<li class = "divider" role = "presentation"></li>';
        echo '<li><a href = "' . HOME_URL . 'extensions/ino_user/user_logout.php"> ' . gettext('LogOut') . '</a></li>';
        echo '</ul>
       </li>
       </ul>
       ';
       } else {
        include_once __DIR__ . '/../../extensions/ino_user/popup_login/user_popup_login_template.php';
       }
       ?>
      </div>

     </div><!-- end top menu -->
     <div class="callus">
      <span class="topbar-email"><i class="fa fa-envelope"></i> <a href="#"><?php echo!empty($si->email) ? $si->email : gettext('contact@site.org'); ?></a></span>
      <span class="topbar-phone"><i class="fa fa-phone"></i> <a href="#"><?php echo!empty($si->phone_no) ? $si->phone_no : '1-111-1111' ?></a></span>
     </div><!-- end callus -->
    </div><!-- end columns -->
   </div><!-- end container -->
  </div><!-- end topbar -->

  <header id="header-style-1">
   <div class="container">
    <nav class="navbar yamm navbar-default">
     <div class="navbar-header">
      <img src="<?php echo HOME_URL;
       echo!empty($si->logo_path) ? $si->logo_path : 'files/logo.png'
       ?>" class="logo_image" alt="logo"/>
      <a href="<?php echo HOME_URL; ?>" class="navbar-brand"><?php echo!empty($si->site_name) ? $si->site_name : 'inoERP'; ?></a>
     </div><!-- end navbar-header -->
     <div id="navbar-collapse-1" class="navbar-collapse collapse navbar-right">
      <ul class="nav navbar-nav">
       <li><a href="<?php echo HOME_URL; ?>">Home <div class="arrow-up"></div></a></li>
       <li class="active"><a href="http://demo.inoideas.org/extensions/ino_user/user_login.php" ><?php echo gettext('Demo') ?> <div class="arrow-up"></div></a></li>
       <li><a href="https://github.com/inoerp/inoERP" ><?php echo gettext('Download') ?> <div class="arrow-up"></div></a></li>
       <li><a href="<?php echo HOME_URL; ?>content.php?content_type=documentation&amp;category_id=30"><?php echo gettext('Documentation') ?> <div class="arrow-up"></div></a></li><!-- end standard drop down -->
       <li><a href="<?php echo HOME_URL; ?>content.php?content_type=forum&amp;category_id=1"><?php echo gettext('Forum') ?> <div class="arrow-up"></div></a></li>
       <li><a href="<?php echo HOME_URL; ?>content.php?mode=2&amp;content_id=197&amp;content_type_id=47"><?php echo gettext('About') ?> <div class="arrow-up"></div></a> </li><!-- end drop down -->
      </ul><!-- end navbar-nav -->
     </div><!-- #navbar-collapse-1 -->			
    </nav><!-- end navbar yamm navbar-default -->
   </div><!-- end container -->
  </header><!-- end header-style-1 -->

  <?php
  if (!empty($showBlock)) {
   echo '<div id="header_bottom"></div>';
  }
  ?>

  <?php
//  if ($si->maintenance_cb == 1) {
//   echo "<div class='error'>Site is under maintenance mode </div>";
//  }

  ?>
