<?php // ob_end_clean();            ?>
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
  <link href="<?php
   echo THEME_URL;
   echo (!empty($content_class)) ? '/content_layout.css' : '/layout.css'
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
  <script src="<?php echo HOME_URL; ?>includes/js/jquery-2.0.3.min.js"></script>
  <script src="<?php echo HOME_URL; ?>includes/js/jquery-ui.min.js"></script>
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
       Exclude the header &amp; left block section-->
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
  </div>

  <?php
   if ($showBlock) {
    echo '<div id="header_top" class="clear"></div>';
//	 if (!empty($_SESSION['login_status'])) {
//		echo '<div id="header_top" class="clear"></div>';
//	 }
    ?>

    <div id="header" class="clear headerBgColor">
     <div class="logo">
      <img src="<?php
      echo HOME_URL;
      echo!empty($si->logo_path) ? $si->logo_path : 'files/logo.png'
      ?>" class="logo_image" alt="logo"/>
      <h2><?php
       echo "<a href=\" " . HOME_URL . "\"> ";
       echo!empty($si->site_name) ? $si->site_name : 'inoERP';
       echo "</a>";
       ?>!</h2> </div>
     <div class="header_right">
      <?php if ($show_header_links) { ?>
       <div class="header_info">
        <ul class="inRow asperWidth"> 
         <li><a href="http://demo.inoideas.org/extensions/user/user_login.php">Demo</a></li>
         <li><a href="https://github.com/inoerp/inoerp_v1">Download</a></li>
         <li><a href="<?php echo HOME_URL; ?>content.php?content_type=documentation&amp;category_id=30">Documentation</a></li>
         <li><a href="<?php echo HOME_URL; ?>content.php?content_type=forum&amp;category_id=1">Forum</a></li>
         <li><a href="<?php echo HOME_URL; ?>content.php?mode=2&amp;content_id=197&amp;content_type_id=47">About</a></li>
        </ul>
       </div>

      <?php } ?>

      <?php
      if (!empty($_SESSION['login_status'])) {
       ?><div id="user_info">
        <div class="ino_drop_down_menu">
         <ul class="block_menu">
          <li class="parent_menu expandable " data-path_description="Administrator">
           <a  href="<?php echo HOME_URL; ?>form.php?class_name=user&amp;mode=9&amp;user_id=<?php echo $_SESSION['user_id']; ?>">
            <?php echo 'Hello ' . ucfirst($_SESSION['username']) . '!'; ?></a>
           <ul class="child_menu">
            <li class="expandable" data-path_description="Home Page">
             <a  href="<?php echo HOME_URL; ?>">Home</a> 
            </li>
            <li class="expandable" data-path_description="User Details">
             <a href="<?php echo HOME_URL; ?>form.php?class_name=user&amp;mode=9&amp;user_id=<?php echo $_SESSION['user_id']; ?>">User Details</a>
             <ul>
              <li class="expandable" data-path_description="User Activities">
               <a href="<?php echo HOME_URL; ?>form.php?class_name=user_activity_v&amp;mode=2&amp;user_id=<?php echo $_SESSION['user_id']; ?>">Activities</a>
              </li>
              <li class="expandable" data-use_notification="User Notifications">
               <a href="<?php echo HOME_URL; ?>search.php?class_name=sys_notification_user">All Notifications</a>
              </li>
             </ul>
            </li>
            <li class="expandable" data-path_description="Dashborad">
             <a href="<?php echo HOME_URL; ?>form.php?class_name=user_dashboard_v&amp;mode=2&amp;user_id=<?php echo $_SESSION['user_id']; ?>">Dashboard</a>
             <ul>
              <li class="expandable" data-path_description="Dashborad Configuration">
               <a href="<?php echo HOME_URL; ?>form.php?class_name=user_dashboard_config&amp;mode=9&amp;user_id=<?php echo $_SESSION['user_id']; ?>">Configure</a>
              </li>
             </ul>
            </li>
            <li class="expandable" data-path_description="Logout">
             <a  href="<?php echo HOME_URL; ?>extensions/user/user_logout.php">Logout</a> 
            </li>
           </ul>
          </li>
         </ul>
        </div>
       </div>
      <?php } else { ?>
       <div id="registration_info">
        <ul class="inRow asperWidth">
         <li class>
          <a class="login_button" href="<?php echo HOME_URL; ?>extensions/user/user_login.php">Sign In</a>
         <li>
          <a class="login_button" href="<?php echo HOME_URL; ?>extensions/user/user_login.php#tabsLine-2">Register</a>
         </li>
        </ul>
       </div>	
      <?php } ?>

     </div>

    </div>
    <div id="header_bottom"></div>
   <?php } ?>

  <?php
   if ($si->maintenance_cb == 1) {
    echo "<div class='error'>Site is under maintenance mode </div>";
   }

   if (!empty($access_deined)) {
    exit("Access denied ! <br> $msg <input action='action' class='button' type='button' value='Go Back' onclick='history.go(-1);' />");
   }
  ?>