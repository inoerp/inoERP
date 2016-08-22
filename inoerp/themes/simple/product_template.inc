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
  <link rel="shortcut icon" type="image/x-icon" href="files/favicon.ico">
  <link href="<?php
//  echo THEME_URL;
//  echo (!empty($content_class)) ? '/content_layout.css' : '/layout.css'
  ?>" media="all" rel="stylesheet" type="text/css" />
  <link href="<?php echo THEME_URL; ?>/public.css" media="all" rel="stylesheet" type="text/css" />
  <link href="<?php echo THEME_URL; ?>/css/product.css" media="all" rel="stylesheet" type="text/css" />
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
  <script src="<?php echo HOME_URL; ?>includes/js/custom/tinymce/tinymce.min.js"></script>
  <script src="<?php echo HOME_URL; ?>includes/js/save.js"></script>
  <script src="<?php echo HOME_URL; ?>includes/js/custom_plugins.js"></script>
  <script src="<?php echo HOME_URL; ?>includes/js/basics.js"></script>
  <script src="themes/default/js/theme.js"></script>
  <?php
  if (!empty($js_file_paths)) {
   foreach ($js_file_paths as $key => $js_file) {
    ?>
    <script src="<?php echo HOME_URL . $js_file; ?>"></script>
    <?php
   }
  }
  ?>
  <style>
   .hf-nav {float:left; position:relative;  padding: 5px 5px; z-index:999}
   #hf-nav-1 .hf-menu {padding:0; margin:0; list-style:none; clear:left; float:left; text-align:left;}
   #hf-nav-1 .hf-menu li 
   {
    /*background: none repeat scroll 0% 0% rgba(3, 52, 84, 0.5);*/
    margin: 5px -10px;
    /*overflow: hidden*/
   }

   .hf-menu > li 
   {
    background: #eee;

   }

   .hf-menu li a 
   {
    display: block;
    width: 180px;
    float: left;
    font-weight: bold;
    color: #333;
    text-decoration: none;
    padding: 10px;
    font-size: 1.1em;
   }

   li.top-li a{
    width: 220px;
   }

 
   .hf-menu ul {padding:5px 0 0 20px; margin:0  ; list-style:none; z-index:999}
   .hf-menu ul li.sub {width:250px; float:left; }
   #hf-nav-1 .hf-menu ul li h4 {
    padding:0 0 0 10px; 
    margin:0;
    text-align:center;
    font-weight: bold;
    color: #082A57;
    border-bottom: 1px solid #fff;
    width: 250px;
    display: block;
    font-weight: bold;
   }
   #hf-nav-1 .hf-menu ul li a { 
    padding:5px 10px;
    width:200px; 
    font-size:15px; 
    font-weight:bold; 
    float:left;
    text-align:left;
   }

   .hf-menu li.close {display:none; position:absolute;}

   .hf-menu ul.sub {
    position:absolute; 
    left:-9999px; 
    background: #eee;
    margin-left: 45px;
    top:-5px;  
    border:5px solid #eee; 
    border-width: 15px 15px 15px 0;
    width: 750px;
    height: 265px;
   }

   .hf-menu li.top-li:hover {direction:ltr;}
   .hf-menu li.top-li:hover ul.sub {left:149px; display:block}
   .hf-menu li.top-li ul.sub li.sub { float:left}

   .hf-menu ul li.bottomLine {clear:left; width:100%; background:#333; height:40px;}
   #hf-nav-1 .hf-menu ul li.bottomLine p {padding:0 10px; margin:0; line-height:20px; color:#fff; font-size:12px;}
   #hf-nav-1 .hf-menu ul li.bottomLine p a {display:inline; width:auto; float:none; padding:0; margin:0; background:none; color:#6cf;line-height:11px; }
   #hf-nav-1 .hf-menu ul li.bottomLine p a:hover {background:#000;}

   .clear {clear:left;}

   /* for IE6 */
   .hf-menu table {border-collapse:collapse; margin-bottom:-1px;}
   .hf-menu li.top-li a:hover {direction:ltr;}
   .hf-menu li.top-li a:hover ul.sub {left:149px; background-color:#555;}
   .hf-menu li.top-li a:hover ul li {float:left; margin-left: 150px}
   #hf-nav-1 .hf-menu li.top-li a:hover ul li a {font-weight:normal; float:left; line-height:11px;}
   #hf-nav-1 .hf-menu li.top-li a:hover ul li.bottomLine p {font-weight:normal;}
   #hf-nav-1 .hf-menu li.top-li a:hover ul li.bottomLine p a {float:none;}
  </style>
 </head>
 <body>
  <div id="topbar" class="product-topbar clearfix">
   <div class="container">
    <?php
    if ($showBlock) {
     echo '<div id = "header_top" class = "clear"></div>';
    }
    ?>
    <div class="col-md-8">
      <div class="dropdown">
       <button class="btn btn-default dropdown-toggle" type="button" id="dropdownMenu1" data-toggle="dropdown" aria-expanded="true">
        <i class='fa fa-th'></i> Browse By Category
       </button>
       <ul class="dropdown-menu" role="menu" aria-labelledby="dropdownMenu1">
        <li role="presentation"><?php echo ec_product::category_menu(); ?></li>
       </ul>
      </div>

    </div><!-- end columns --><!-- end columns -->
    <div class="col-md-2"><a title="View Cart" href="<?php echo HOME_URL ?>?dtype=product&class_name=ec_user_cart">
      <i class="fa fa-white fa-2x fa-shopping-cart clickable"></i><span id="no-of-cart-items" class="badge"> <?php echo ino_noOfItems_inCart(); ?> </span> </a></div>
    <div class="col-md-2">
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
        include_once 'extensions/ino_user/popup_login/user_popup_login_template.php';
       }
       ?>
      </div>

     </div><!--
     <div class="callus">
      <span class="topbar-email"><i class="fa fa-envelope"></i> <a href="#"><?php echo!empty($si->email) ? $si->email : 'contact@site.org' ?></a></span>
      <span class="topbar-phone"><i class="fa fa-phone"></i> <a href="#"><?php echo!empty($si->phone_no) ? $si->phone_no : '1-111-1111' ?></a></span>
     </div><!-- end callus -->
    </div><!-- end columns -->
   </div><!-- end container -->
  </div><!-- end topbar -->
  <header id="header-style-1">
   <div class="container">
    <nav class="navbar yamm navbar-default">
     <div class="navbar-header">
      <img src="<?php
      echo HOME_URL;
      echo!empty($si->logo_path) ? $si->logo_path : 'files/logo.png'
      ?>" class="logo_image" alt="logo"/>
      <a href="<?php echo HOME_URL; ?>" class="navbar-brand"><?php echo!empty($si->site_name) ? $si->site_name : 'inoERP'; ?></a>
     </div><!-- end navbar-header -->
     <div id="navbar-collapse-1" class="navbar-collapse collapse navbar-right">
      <ul class="nav nav-pills">
       <li><a href="<?php echo HOME_URL; ?>">Home <div class="arrow-up"></div></a></li>
       <li><a href="http://inoideas.org/content/demo" >DEMO <div class="arrow-up"></div></a></li>
       <li><a href="https://github.com/inoerp/inoERP" >Download <div class="arrow-up"></div></a></li>
       <li class="active"><a href="<?php echo HOME_URL; ?>content.php?mode=9&content_type=forum&category_id=7" ><i class="fa fa-comments-o"></i> Ask a Question <div class="arrow-up"></div></a></li>
       <li><a href="<?php echo HOME_URL; ?>content.php?content_type=documentation&amp;category_id=30">Documentation <div class="arrow-up"></div></a></li><!-- end standard drop down -->
       <li><a href="<?php echo HOME_URL; ?>content.php?content_type=forum&amp;category_id=1">Forum <div class="arrow-up"></div></a></li>
       <li><a href="<?php echo HOME_URL; ?>content.php?mode=2&amp;content_id=197&amp;content_type_id=47">About <div class="arrow-up"></div></a> </li><!-- end drop down -->
      </ul><!-- end navbar-nav -->
     </div><!-- #navbar-collapse-1 -->			
    </nav><!-- end navbar yamm navbar-default -->
   </div><!-- end container -->
  </header>


  <div class="container">
   <?php
   if ($showBlock) {
    echo '<div id="header_bottom"></div>';
   }
   ?>

   <?php
   if ($si->maintenance_cb == 1) {
    echo ino_access_denied('Site is under maintenance mode');
    return;
   }
   ?>
   <div class="row">
    <div id="product_area">
     <div id="content">
      <div id="structure">
       <?php
       if (!empty($show_message)) {
        echo '<div class="alert alert-warning alert-dismissible" role="alert"><button type="button" class="close" data-dismiss="alert" aria-label="Close"><span aria-hidden="true">&times;</span></button>' .
        $show_message .
        '</div>';
       }
       if (!empty($access_denied_msg)) {
        echo ino_access_denied($access_denied_msg);
       } else if (!empty($template_file_names)) {
        foreach ($template_file_names as $key => $tmpl_file) {
         include_once $tmpl_file;
        }
       }
       ?>
      </div>
      <!--   end of structure-->
     </div>
     <div id='overlay'></div>
    </div>
   </div>

  </div>


  <div class="row">
   <div id="comment_form" class="none">
    <?php
    if (!empty($reference_table) && !empty($reference_id)) {
     include_once __DIR__ . '/../../comment.php';
    }
    ?>
   </div>

  </div>
  <!--footer content-->
  <div id="comment_form" class="none">
   <?php
   if (!empty($reference_table) && !empty($reference_id)) {
    include_once HOME_DIR . '/comment.php';
   }
   ?>
  </div>

  <div class="make-bg-full">
   <div class="calloutbox-full-mini nocontainer">
    <div class="long-twitter">
     <p class="lead"><i class="fa fa-star"></i>
      All inoERP code is Copyright by the Original Authors as mentioned on COPYRIGHT.txt file.
      <br>inoERP is an open Source software; you can redistribute it and/or modify
      it under the terms of the Mozilla Public License Version 2.0 </p>
    </div>
   </div><!-- end calloutbox -->
  </div><!-- make bg -->

  <div id="footer-style-1">
   <div class="container">
    <div id="footer_top"></div>
   </div>
  </div>
  <div id="copyrights">
   <div class="container">
    <div class="col-lg-5 col-md-6 col-sm-12">
     <div class="copyright-text">
      <p>
       <?php
       global $si;
       echo nl2br($si->footer_message);
       ?>
      </p>
     </div><!-- end copyright-text -->
    </div><!-- end widget -->
    <div class="col-lg-7 col-md-6 col-sm-12 clearfix">
     <div class="footer-menu">
      <ul class="menu">
       <li class="active"><a href="#">Terms of Use</a></li>
       <li><a href="#">Site Maps</a></li>
       <li><a href="https://github.com/inoerp/inoERP/releases">Releases</a></li>
       <li><a href="https://www.mozilla.org/MPL/2.0/">MPL 2</a></li>
       <li><a href="#">Cookie Preferences</a></li>

      </ul>
     </div>
    </div><!-- end large-7 --> 
   </div><!-- end container -->
  </div><!-- end copyrights -->

  <?php
  global $f;
  echo (!empty($footer_bottom)) ? "<div id=\"footer_bottom\"> $footer_bottom </div>" : "";
  echo $f->hidden_field_withId('home_url', HOME_URL);
  echo $si->analytics_code;
  ?>
  <script type="text/javascript">
   $(document).ready(function () {
    //summar list
    var maxListCount = 4;
    var shownListCount = 0;
    $('ul.summary_list').on('click', '.move-left,.move-right', function () {
     console.log($('li.summary:visible').last().nextAll().length);
     if ($('li.summary:visible').last().nextAll().length <= maxListCount) {
      console.log($('li.summary:visible').last().nextAll().length);
      maxListCount = 4;
      shownListCount = 0;
      update_summary_list(maxListCount, shownListCount);
     } else {
      if ($(this).hasClass('move-left')) {
       $(this).next(':first').toggle();
      } else if ($(this).hasClass('move-right')) {
       $(this).prev(':first').toggle();
      }
      shownListCount++;
      maxListCount++;
      update_summary_list(maxListCount, shownListCount);
     }
    });
    update_summary_list(maxListCount, shownListCount);

   });
  </script>
 </body>
</html>
<?php
// 5. Close connection
if (isset($dbc)) {
 $dbc->close_connection();
}
?>
