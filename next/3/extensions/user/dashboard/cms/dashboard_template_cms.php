<link href="<?php echo HOME_URL; ?>includes/ecss/getsvgimage.css" media="all" rel="stylesheet" type="text/css" />
<div id ="form_header">
 <div id="tabsHeader">
  <form action="" method="post" id="user_header" name="user_header"><span class="heading">User Dashboard 
    <a href="<?php echo HOME_URL ?>form.php?class_name=user_dashboard_config&mode=9&user_id=<?php echo $user_id ?>" 
       class='fa fa-cog'></a>
   </span>
   <div id ="form_header">
    <div id="tabsHeader">
     <ul class="tabMain">
      <li><a href="#tabsHeader-1">Navigation</a></li>
      <li><a href="#tabsHeader-2">Quick Info</a></li>
     </ul>
     <div class="tabContainer"> 
      <div id="tabsHeader-1" class="tabContent">
       <ul id='dashborad_menu'>
        <li><a href="form.php?class_name=user_activity_v"><i class="fa fa-tasks"></i>User Activities</a></li>
        <li><a href="search.php?class_name=sys_notification_user"><i class="fa fa-bell-slash-o"></i>Notifications</a></li>
        <li><a href="form.php?class_name=user&mode=9&user_id=<?php echo $_SESSION['user_id'] ?>"><i class="fa fa-user"></i>User Details</a></li>
        <li><a href="extensions/user/user_logout.php"><i class="fa fa-sign-out"></i> Sign Out</a></li>
       </ul>

      </div>
      <div id="tabsHeader-2" class="tabContent">
       <ul class="column three_column">
        <li>
         <h2>Notifications</h2>
         <?php
         echo block::show_block_content_by_BlockId('55');
         ?>
        </li>
        <li>
         <h2>Recent Comments</h2>
         <?php
         echo block::show_block_content_by_BlockId('52');
//                include_once HOME_URL.'report.php?class_name=ra_item&report_name=ra_report_set_item_leadtime';
         ?>
        </li>
        <li>
         <span class="button"><a href="<?php echo HOME_URL ?>form.php?class_name=user_favourite&mode=9">Favourites 
           <img src="<?php echo THEME_URL; ?>/images/edit.png" alt=" update favourite" title='Update Favourite'/>
          </a></span>
        </li>               
       </ul>
      </div>
     </div>

    </div>
   </div>
  </form>
 </div>
</div>    
