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
  <link href="<?php echo THEME_URL; ?>/public.css" media="all" rel="stylesheet" type="text/css" />
  <link href="<?php echo THEME_URL; ?>/menu.css" media="all" rel="stylesheet" type="text/css" />
  <link href="<?php echo THEME_URL; ?>/jquery.css" media="all" rel="stylesheet" type="text/css" />
  <link href="<?php echo HOME_URL; ?>tparty/bootstrap/css/bootstrap.css" rel="stylesheet">
  <link href="<?php echo HOME_URL; ?>tparty/bootstrap/css/style.css" rel="stylesheet">
  <link href="<?php echo HOME_URL; ?>tparty/font-awesome/css/font-awesome.min.css" rel="stylesheet">
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
  <script src="includes/js/jquery-2.0.3.min.js"></script>
  <script src="includes/js/jquery-ui.min.js"></script>
  <script src="<?php echo HOME_URL; ?>tparty/bootstrap/js/bootstrap.min.js"></script>
  <script src="<?php echo HOME_URL; ?>tparty/bootstrap/js/menu.js"></script>
  <script src="includes/js/custom/tinymce/tinymce.min.js"></script>
  <script src="includes/js/save.js"></script>
  <script src="includes/js/custom_plugins.js"></script>
  <script src="includes/js/basics.js"></script>

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
  <nav class="navbar navbar-inverse navbar-fixed-top">
   <div class="container-fluid">
    <div class="navbar-header">
     <button type="button" class="navbar-toggle collapsed" data-toggle="collapse" data-target="#navbar" aria-expanded="false" aria-controls="navbar">
      <span class="sr-only">Toggle navigation</span>
      <span class="icon-bar"></span>

     </button>
     <img src="<?php
     echo HOME_URL;
     echo!empty($si->logo_path) ? $si->logo_path : 'files/logo.png'
     ?>" class="logo_image" alt="logo"/>
     <a class="navbar-brand" href="<?php echo HOME_URL; ?>"><?php echo!empty($si->site_name) ? $si->site_name : 'inoERP'; ?></a>
    </div>
    <div id="navbar" class="navbar-collapse collapse">
     <ul class="nav navbar-nav navbar-right">
      <li><a href="<?php echo HOME_URL; ?>">Home <div class="arrow-up"></div></a></li>
      <li><a href="http://demo.inoideas.org/extensions/user/user_login.php" >Demo <div class="arrow-up"></div></a></li>
      <li><a href="https://github.com/inoerp/inoERP/fork" >Download <div class="arrow-up"></div></a></li>
      <li><a href="<?php echo HOME_URL; ?>content.php?content_type=documentation&amp;category_id=30">Documentation <div class="arrow-up"></div></a></li><!-- end standard drop down -->
      <li><a href="<?php echo HOME_URL; ?>content.php?content_type=forum&amp;category_id=1">Forum <div class="arrow-up"></div></a></li>
      <li><a href="<?php echo HOME_URL; ?>content.php?mode=2&amp;content_id=197&amp;content_type_id=47">About <div class="arrow-up"></div></a> </li><!-- end drop down -->
      <li>
       <span class="topbar-login ino_right_top">
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
           <li role="presentation"><a role="menuitem"  tabindex="-1" href="<?php echo HOME_URL . 'extensions/user/user_logout.php'; ?>"><i class="fa fa-sign-out"></i> LogOut</a></li>
          </ul>
         </div>

         <?php
        } else {
         include_once 'extensions/user/popup_login/user_popup_login_template.php';
        }
        ?>
       </span>
      </li>
     </ul>
     <?php echo $ss->entry_form($_GET); ?>
     <!--          <form class="navbar-form navbar-right">
                <input type="text" class="form-control" placeholder="Search...">
               </form>-->

    </div>
   </div>
  </nav>

  <?php
  if ($showBlock) {
   echo '<div id="header_bottom"></div>';
  }
  ?>

  <?php
  if ($si->maintenance_cb == 1) {
   echo "<div class='error'>Site is under maintenance mode </div>";
  }

  if (!empty($access_deined)) {
   exit("Access denied ! <br> $msg <input action='action' class='button' type='button' value='Go Back' onclick='history.go(-1);
       ' />");
  }
  ?>

  <div class="container-fluid">
   <div class="row">
    <div class="col-sm-3 col-md-2 sidebar">
     <div id="sys_menu_left_vertical">
      <div class="btn-group-sm" role="group" aria-label="...">
       <button type="button" id='expand_all_nav' class="btn btn-default">Expand All</button>
       <button type="button" id='collapse_all_nav' class="btn btn-default">Collapse All</button>
      </div>
      <?php
      $pat = new path();
      echo ($pat->path_allpaths_block(array('divClass' => 'tree_view')));
      echo $fav->show_currentUser_fav();
      ?>
     </div>
    </div>


    <div id="navigation_bar"   class="col-sm-9 col-sm-offset-3 col-md-10 col-md-offset-2 mainbar">
     <div id="header_top_quick_nav" >
      <ul class="list-group inline_list">
       <li role="presentation"><a  href="<?php echo HOME_URL; ?>"><i class="fa fa-home" title="Home"></i></a></li>
       <li role="presentation"><a  href="#"><i class="fa fa-info" title="Messages"></i></a></li>
       <li role="presentation"><a  href="<?php echo HOME_URL . 'form.php?class_name=user_dashboard_v&amp;mode=2&amp;user_id=' . $_SESSION['user_id']; ?>"><i class="fa fa-dashboard" title="Dashborad"></i></a></li>
       <li>
        <div class="btn-group">
         <button type="button" class="btn btn-xs btn-info"  title="Favourites"><i class="fa fa-star-o" title="Favourites"></i></button>
         <button type="button" title="Favourites" class="btn btn-xs btn-info dropdown-toggle" data-toggle="dropdown" aria-expanded="false">
          <span class="caret"></span>
          <span class="sr-only">Toggle Dropdown</span>
         </button>
         <?php echo $fav->show_currentUser_fav(true); ?>
        </div>
       </li>
      </ul>
     </div>
     <div id="header_top_container">
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
       <!--       <div class="social-icons">
               <span><a class="flaticon-list90 clickable erp_dashborad" href="form.php?class_name=user_dashboard_v&mode=2" title="ERP Dashboard"> ERP Dashboard </a></span>
              </div> end social icons -->
      <?php } ?>
     </div>
    </div>
    <div id="erp_form_area" class="col-sm-9 col-sm-offset-3 col-md-10 col-md-offset-2 mainbar">
     <div id="content">
      <div class="error clickable"></div><div id="loading"></div>
      <div id="structure">
       <?php
       echo (!empty($show_message)) ? $show_message : "";
       if (!empty($template_file_names)) {
        foreach ($template_file_names as $key => $tmpl_file) {
         include_once $tmpl_file;
        }
       }
       ?>
      </div>
      <!--   end of structure-->
     </div>
    </div>


    <div class="col-sm-9 col-sm-offset-3 col-md-10 col-md-offset-2 mainbar">
     <div id="non-visible" class="non-visible">

     </div><!-- end large-7 --> 
    </div>

    <div class="col-sm-9 col-sm-offset-3 col-md-10 col-md-offset-2 mainbar">
     <div class="footer-menu">
      <div id="half_copyrights">
       <?php
       global $si;
       echo nl2br($si->footer_message);
       ?>
       <ul>
        <li><a href="http://inoideas.org/content.php?mode=9&content_type=web_contact">Contact</a></li>
        <li><a href="https://github.com/inoerp/inoERP/releases">Releases</a></li>
        <li><a href="https://www.mozilla.org/MPL/2.0/">MPL 2</a></li>
        <li><a href="#">Cookie Preferences</a></li>
        <li class="active"><a href="#">Terms of Use</a></li>
       </ul>
      </div>
     </div><!-- end large-7 --> 
    </div>

   </div>

  </div>
  <div clas="row">
   <div id="comment_form" class="none">
    <?php
    if (!empty($reference_table) && !empty($reference_id)) {
     include_once __DIR__ . '/../../comment.php';
    }
    ?>
   </div>

  </div>
  <!--footer content-->
  <?php
  global $f;
  echo (!empty($footer_bottom)) ? "<div id=\"footer_bottom\"> $footer_bottom </div>" : "";
  echo $f->hidden_field_withId('home_url', HOME_URL);
  ?>
  <div class="hidden">
   <?php
   echo searching_tips();
   echo ino_filter_form();
   ?>
  </div>
 </body>
</html>
<?php
// 5. Close connection
if (isset($dbc)) {
 $dbc->close_connection();
}
?>