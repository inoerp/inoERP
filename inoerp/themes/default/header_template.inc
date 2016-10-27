<div id="header_top" class="clear"></div>
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
     <li><a href="http://demo.inoideas.org/extensions/user/user_login.php"><?php echo gettext('Demo'); ?></a></li>
     <li><a href="https://github.com/inoerp/inoerp_v1"><?php echo gettext('Download'); ?></a></li>
     <li><a href="<?php echo HOME_URL; ?>content.php?content_type=documentation&amp;category_id=30"><?php echo gettext('Documentation'); ?></a></li>
     <li><a href="<?php echo HOME_URL; ?>content.php?content_type=forum&amp;category_id=1"><?php echo gettext('Forum'); ?></a></li>
     <li><a href="<?php echo HOME_URL; ?>content.php?mode=2&amp;content_id=197&amp;content_type_id=47"><?php echo gettext('About'); ?></a></li>
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
         <a  href="<?php echo HOME_URL; ?>"><?php echo gettext('Home'); ?></a> 
        </li>
        <li class="expandable" data-path_description="User Details">
         <a href="<?php echo HOME_URL; ?>form.php?class_name=user&amp;mode=9&amp;user_id=<?php echo $_SESSION['user_id']; ?>"><?php echo gettext('User Details'); ?></a>
         <ul>
          <li class="expandable" data-path_description="User Activities">
           <a href="<?php echo HOME_URL; ?>form.php?class_name=user_activity_v&amp;mode=2&amp;user_id=<?php echo $_SESSION['user_id']; ?>"><?php echo gettext('Activities'); ?></a>
          </li>
          <li class="expandable" data-use_notification="User Notifications">
           <a href="<?php echo HOME_URL; ?>search.php?class_name=sys_notification_user"><?php echo gettext('All Notifications'); ?></a>
          </li>
         </ul>
        </li>
        <li class="expandable" data-path_description="Dashboard">
         <a href="<?php echo HOME_URL; ?>form.php?class_name=user_dashboard_v&amp;mode=2&amp;user_id=<?php echo $_SESSION['user_id']; ?>"><?php echo gettext('Dashboard'); ?></a>
         <ul>
          <li class="expandable" data-path_description="Dashboard Configuration">
           <a href="<?php echo HOME_URL; ?>form.php?class_name=user_dashboard_config&amp;mode=9&amp;user_id=<?php echo $_SESSION['user_id']; ?>"><?php echo gettext('Configure'); ?></a>
          </li>
         </ul>
        </li>
        <li class="expandable" data-path_description="Logout">
         <a  href="<?php echo HOME_URL; ?>extensions/user/user_logout.php"><?php echo gettext('LogOut'); ?></a> 
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
      <a class="login_button" href="<?php echo HOME_URL; ?>extensions/user/user_login.php"><?php echo gettext('Sign In'); ?></a>
     <li>
      <a class="login_button" href="<?php echo HOME_URL; ?>extensions/user/user_login.php#tabsLine-2"><?php echo gettext('Register'); ?></a>
     </li>
    </ul>
   </div>	
  <?php } ?>

 </div>

</div>
<div id="header_bottom"></div>
