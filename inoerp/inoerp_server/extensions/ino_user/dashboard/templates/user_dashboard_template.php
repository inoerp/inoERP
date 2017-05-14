<!--
1. Find all reports
-->

<?php
$all_reports = user_dashboard_config::findBy_userIdNconfigLevel($ino_user->ino_user_id);
//pa($all_reports);
?>
<link href="<?php echo HOME_URL; ?>css/getsvgimage.css" media="all" rel="stylesheet" type="text/css" />
<div id ="user_dashboard_divId">
 <div id="tabsHeader">
  <form method="post" id="user_header" name="user_header"><span class="heading"><?php echo gettext('User Dashboard') ?> 
    <a href="<?php echo HOME_URL ?>form.php?class_name=user_dashboard_config&mode=9&user_id=<?php echo $user_id ?>" 
       class='fa fa-cog'></a>
   </span>
   <div id="tabsHeader">
    <ul class="tabMain">
     <li><a href="#tabsHeader-1"><?php echo gettext('Navigation') ?></a></li>
     <?php
     foreach ($all_reports as $tab_c => $db_r) {
      $tab_c += 2;
      if ($db_r->report_type == 'report') {
       echo '<li><a href="#tabsHeader-' . $tab_c . '" class="get-report-content" data-report_id="' . $db_r->report_id . '" >' . gettext($db_r->report_label) . '</a></li>';
      } else if ($db_r->report_type == 'view') {
       echo '<li><a href="#tabsHeader-' . $tab_c . '" class="get-view-content" data-view_id="' . $db_r->report_id . '" >' . gettext($db_r->report_label) . '</a></li>';
      } else {
       echo '<li><a href="#tabsHeader-' . $tab_c . '">' . gettext($db_r->report_label) . '</a></li>';
      }
     }
     ?>
    </ul>
    <div class="tabContainer"> 
     <div id="tabsHeader-1" class="tabContent">
      <?php echo!empty($module_icons) ? $module_icons : '' ?>
     </div>
     <?php
     $view_i = new extn_view();
     foreach ($all_reports as $tab_c => $db_r) {
      $tab_c += 2;
      echo '<div id="tabsHeader-' . $tab_c . '" class="tabContent">';
      if ($db_r->report_type == 'report') {
       
      } else if ($db_r->report_type == 'view') {
       $view_i->view_id = $db_r->report_id;
       $view_i->viewResultById();
      } else if ($db_r->report_type == 'block') {
       echo block::show_block_content_by_BlockId($db_r->report_id);
      } else {
       echo 'No Data Found';
      }
      echo '</div>';
     }
     ?>
    </div>

   </div>
  </form>
 </div>
</div>    
