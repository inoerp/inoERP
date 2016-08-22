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
  <meta name="viewport" content="width=device-width, initial-scale=1, maximum-scale=1, user-scalable=no">
  <title><?php echo isset($pageTitle) ? $pageTitle . ' - inoERP!' : ' inoERP! ' ?></title>
  <link rel="shortcut icon" type="image/x-icon" href="files/favicon.ico">
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
 </head>
 <body>
  <nav class="navbar navbar-inverse navbar-fixed-top">
   <div class="container-fluid">
    <div class="navbar-header col-md-6">
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
    <div id="navbar" class="navbar-collapse collapse col-md-6 navbar-right">
     <ul class="nav navbar-nav navbar-right">
      <li>
       <div class="topbar-login ino_right_top">
        <?php if (!empty($_SESSION['login_status'])) { ?>
         <div class="dropdown">
          <button class="btn btn-default dropdown-toggle" type="button" id="menu1" data-toggle="dropdown"><i class="fa fa-user"> </i><?php echo ' ' . ucfirst($_SESSION['username']); ?>
           <span class="caret"></span></button>
          <ul class="dropdown-menu" role="menu" aria-labelledby="menu1">
           <!--<li role="presentation" class="dropdown-header">Dropdown header 1</li>-->
           <li role="presentation"><a role="menuitem" tabindex="-1" href="<?php echo HOME_URL; ?>"><i class="fa fa-home"></i> Home</a></li>
           <li role="presentation"><a role="menuitem" tabindex="-1" href="<?php echo HOME_URL . 'form.php?class_name=user&amp;mode=9&amp;user_id=' . $_SESSION['user_id']; ?>"> My Details</a></li>
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
      </li>
     </ul>
     <ul class='nav navbar-nav hidden-xs'><li>
       <?php echo $ss->entry_form($_GET); ?>
      </li>
     </ul>
     <ul class='nav navbar-nav visible-sm visible-xs navbar-right' id="top-path-menu-ul"><li>
       <div class="dropdown">
        <button class="btn btn-default dropdown-toggle" type="button" id="top-path-menu" data-toggle="dropdown">
         <i class="fa fa-navicon"> </i><span class="caret"></span></button>
        <ul class="dropdown-menu" role="menu" aria-labelledby="top-path-menu">
         <li role="presentation">
          <?php
          $pat = new path();
          $menu_path = $pat->path_allpaths_block(array('divClass' => 'tree_view'));
          echo $menu_path;
          ?>          
         </li>
        </ul>
       </div>
      </li>
     </ul>
    </div>
   </div>

  </nav>
  <div class="ino navbar-form">
   <div id="navigation_bar"   class="col-sm-12 col-xs-12 col-md-10 col-md-offset-2 mainbar">
    <div id="header_top_quick_nav" class='hidden-xs' >
     <ul class="list-group inline_list">
      <li role="presentation"><i class="fa fa-toggle-left clickable right_bar_navigation_menu" title="Toggle Navigation Menu"></i></li>
      <li role="presentation"><a  href="<?php echo HOME_URL; ?>"><i class="fa fa-home" title="Home"></i></a></li>
      <li role="presentation"><a  class="getAjaxForm" href="<?php echo HOME_URL . 'form.php?class_name=extn_emessage_header&mode=9' ?>"><i class="fa fa-info" title="Messages"></i></a></li>
      <li role="presentation"><a  href="<?php echo HOME_URL . 'form.php?class_name=user_dashboard_v&amp;mode=2&amp;user_id=' . $_SESSION['user_id']; ?>"><i class="fa fa-dashboard" title="Dashborad"></i></a></li>
      <!--<li role="presentation"><i class="fa fa-gears right-click-menu clickable" title="Actions"></i></li>-->
      <li role="presentation"><a  class="erp-links search-list-page" href="<?php echo HOME_URL; ?>"><i class="fa fa-search" title="Search & List Page"></i></a></li>
      <li role="presentation"><a  class="erp-links form-page" href="<?php echo HOME_URL; ?>"><i class="fa fa-list-alt" title="Form Page"></i></a></li>
      <li id="unsaved_fields" data-no_of_fields="0"></li>
      <li class="show_loading_small"><img src="<?php echo HOME_URL ?>/themes/images/form/small_loading_bar.gif"></li>
     </ul>
    </div>
    <div id="header_top_container" >
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
  </div>

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

  <div class="container-fluid">
   <div class="row">
    <div class="hidden-sm hidden-xs col-md-2 sidebar">
     <div id="accordion">
      <h3 class="clickable nav-panel"><i class="fa fa-warning"></i> <?php echo gettext('Transaction Alerts') ?></h3>
      <div>
       <div id="sys_msg_box">
        <div class="error"></div><div id="loading"></div>
       </div>
      </div>
      <h3 class="clickable nav-panel"><i class="fa fa-navicon"></i> <?php echo gettext('Navigation Menu') ?></h3>
      <div>
       <div id="sys_menu_left_vertical">
        <div class="btn-group-sm" role="group" aria-label="...">
         <button type="button" id='expand_all_nav' class="btn btn-default"><?php echo gettext('Expand All') ?></button>
         <button type="button" id='collapse_all_nav' class="btn btn-default"><?php echo gettext('Collapse All') ?></button>
        </div>
        <?php
        echo $menu_path;
        ?>
       </div>
      </div>
      <h3 class="clickable nav-panel clipboard-data"><i class="fa fa-clipboard"></i> <?php echo gettext('Clipboard') ?></h3>
      <div id="left-clipboard">
       <div id="left-clipboard-icons">
        <i class="fa fa-save save-clipboard clickable"></i>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;
        <i class="fa fa-eraser clear-clipboard clickable"></i> 
       </div>
       <div id="left-clipboard-data">
       </div>
      </div>
      <h3 class="clickable nav-panel minform-data"><i class="fa fa-file-text"></i> <?php echo gettext('Minimized Forms') ?></h3>
      <div id="left-minform">
       <div id="left-minform-data"><ul id="minform-list" class="list-group"></ul>
       </div>
      </div>
      <h3 class="clickable nav-panel event-cal-h"><i class="fa fa-calendar"></i> <?php echo gettext('Event Calendar') ?></h3>
      <div id="left-event-cal">
       <div id="event-datepicker"></div>
      </div>
      <h3 class="clickable nav-panel favourites-h" title="Favourites"><i class="fa fa-star-o"></i> <?php echo gettext('Favourites') ?></h3>
      <div id="left-favourites">
       <div id="favourites-links"><?php echo $fav->show_currentUser_fav(false, 'class="btn-group-vertical" role="group" aria-label="..."', 'list-group-item'); ?></div>
      </div>
      <h3 class="clickable nav-panel recent-visits"><i class="fa fa-history"></i> <?php echo gettext('Recent Visits') ?></h3>
      <div>
       <div id="recent-visits">
        <?php echo ino_recent_visits(); ?>
       </div>
      </div>
     </div>
    </div>
   </div>

   <div id="divider-bar" class="col-m-1 hidden-sm hidden-xs"><i class="fa fa-toggle-left clickable"></i></div>
   <div class="clearfix"></div>
   <div id="erp_form_area" class="col-md-10 col-md-offset-2 mainbar" >
    <div class='visible-xs visible-sm'>
     <div class="error"></div><div id="loading"></div>
    </div>
    <div id="content">
     <div id="structure">
      <div id='form-modal'>
<!--       <button type="button" class="close close-modal">Close <span aria-hidden="true">&times;</span></button>-->
       <div id='mod-header_top_container'> </div>
       <div id='mod-structure'> </div>

      </div>
      <?php
      if (!isset($all_contacts)) {
       $all_contacts = null;
      }

      if (!empty($show_message)) {
       echo '<div class="alert alert-warning alert-dismissible" role="alert"><button type="button" class="close" data-dismiss="alert" aria-label="Close"><span aria-hidden="true">&times;</span></button>' .
       $show_message .
       '</div>';
      }
      if (!empty($access_denied_msg)) {
       echo ino_access_denied($access_denied_msg);
      } else if (!empty($template_file_names)) {
       echo getBreadCrumb($class_first);
       foreach ($template_file_names as $key => $tmpl_file) {
        include_once $tmpl_file;
       }
      }
      ?>
     </div>
     <!--   end of structure-->
    </div>
    <div id='overlay' data-actionmsg='Loading..'></div>
   </div>
   <!--   Dont Change Anything Below This Row-->
   <div class="col-sm-12 col-md-10 col-md-offset-2 mainbar">
    <div class="hidden" id="document_history"></div>
    <div class="footer-menu">
     <div id="half_copyrights">
      <?php
      global $si;
      echo nl2br($si->footer_message);
      ?>
      <ul>
       <li><a href="http://inoideas.org/content.php?mode=9&content_type=web_contact">Contact</a></li>
       <li><a href="http://inoerp.org/extensions/ino_user/user_login.php">Demo</a></li>
       <li><a href="https://github.com/inoerp/inoERP">Download</a></li>
       <li><a href="http://localhost/inoerp/content.php?content_type=documentation&category_id=30">Documentation</a></li>
       <li><a href="http://localhost/inoerp/content.php?content_type=forum&category_id=1">Forum</a></li>
       <li><a href="https://www.mozilla.org/MPL/2.0/">MPL 2</a></li>
       <li><a href="#">Cookie</a></li>
       <li class="active"><a href="#">TOU</a></li>
      </ul>
     </div>
    </div><!-- end large-7 --> 
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
  <?php
  global $f;
  echo (!empty($footer_bottom)) ? "<div id=\"footer_bottom\"> $footer_bottom </div>" : "";
  echo $f->hidden_field_withId('home_url', HOME_URL);
  echo $f->hidden_field_withId('theme_url', THEME_URL);
  ?>
  <div class="hidden">
   <?php
   echo searching_tips();
   echo ino_filter_form();
   echo '<div id="shortcut_keys_divId" class="hidden shortcut_keys">' . ino_shortcut_keys() . '</div>';
   ?>
   <div id="hidden-div" class="hidden"><div id="hidden-div-content"></div></div>
  </div>
  <!--  Load JavaScrips-->
  <script src="includes/js/jquery-2.0.3.min.js"></script>
  <script src="includes/js/jquery-ui.min.js"></script>
  <script src="<?php echo HOME_URL; ?>tparty/bootstrap/js/bootstrap.min.js"></script>
  <script src="<?php echo HOME_URL; ?>tparty/bootstrap/js/menu.js"></script>
  <script src="includes/js/custom/tinymce/tinymce.min.js"></script>
  <script type="text/javascript" src="includes/basics/js_control.php"></script>
  <script src="includes/js/save.js"></script>
  <script src="includes/js/custom_plugins.js"></script>
  <script src="includes/js/basics.js"></script>
  <script src="<?php echo THEME_URL; ?>/js/theme.js"></script>
  <?php
  if (!empty($js_file_paths)) {
   foreach ($js_file_paths as $key => $js_file) {
    ?>
    <script src="<?php echo HOME_URL . $js_file; ?>"></script>
    <?php
   }
//  echo "<h1>Memory </h1>" . memory_get_peak_usage(true) / 1000000 . " mb";
//   echo "<h1>Time </h1>" . execution_time(true);
  }
  ?>
 </body>
</html>
<?php
// 5. Close connection
if (isset($dbc)) {
 $dbc->close_connection();
}
?>