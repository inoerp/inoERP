<?php
if (!empty($ino_user->use_personal_db_cb)) {
 include_once __DIR__ . DS . 'templates/user_dashboard_template.php';
 return;
}
?>
<link href="<?php echo HOME_URL; ?>includes/ecss/getsvgimage.css" media="all" rel="stylesheet" type="text/css" />
<div id ="user_dashboard_divId">
 <div id="tabsHeader">
  <form method="post" id="user_header" name="user_header"><span class="heading"><?php echo gettext('User Dashboard ') ?>
    <a href="<?php echo HOME_URL ?>form.php?class_name=user_dashboard_config&mode=9&user_id=<?php echo $user_id ?>" 
       class='fa fa-cog getAjaxForm'></a>
    <a href="<?php echo HOME_URL ?>form.php?class_name=user&mode=9&user_id=<?php echo $user_id ?>#tabsHeader-2" class='getAjaxForm pull-right'>[using  <?php echo $selected_theme; ?> theme]</a>
   </span>
   <div id="tabsHeader">
    <ul class="tabMain">
     <li><a href="#tabsHeader-1"><?php echo gettext('Navigation') ?></a></li>
     <li><a href="#tabsHeader-2"><?php echo gettext('Quick Info ') ?></a></li>
     <li><a href="#tabsHeader-3" class="get-report-content" data-report_id="7"><?php echo gettext('P&L Snapshot') ?></a></li>
     <li><a href="#tabsHeader-4" class="get-report-content" data-report_id="3"><?php echo gettext('On hand') ?></a></li>
     <li><a href="#tabsHeader-5" class="get-report-content" data-report_id="5"><?php echo gettext('Open PO') ?></a></li>
     <li><a href="#tabsHeader-6" class="get-report-content" data-report_id="4"><?php echo gettext('Sales Funnel') ?></a></li>
     <li><a href="#tabsHeader-7"><?php echo gettext('WIP Value') ?></a></li>
     <li><a href="#tabsHeader-8" class="get-report-content" data-report_id="1"><?php echo gettext('Supplier Liability') ?></a></li>
     <li><a href="#tabsHeader-9" class="get-report-content" data-report_id="6"><?php echo gettext('Customer Balance') ?></a></li>
    </ul>
    <div class="tabContainer"> 
     <div id="tabsHeader-1" class="tabContent">
      <?php echo!empty($module_icons) ? $module_icons : '' ?>
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
        <a title='Update Favourite' href="<?php echo HOME_URL ?>form.php?class_name=user_favourite&mode=9"><h2>Favourites 
          <i class="fa fa-edit"> </i></h2></a>
        <?php
        echo $fav->show_currentUser_fav();
        ?>
       </li>
      </ul>
     </div>
     
     <div id="tabsHeader-3" class="tabContent"></div>
     <div id="tabsHeader-4" class="tabContent"></div>
     <div id="tabsHeader-5" class="tabContent"></div>
     <div id="tabsHeader-6" class="tabContent"></div>
     <div id="tabsHeader-7" class="tabContent">
      <div>                
       <?php
       $raw = new ra_wip();
       $legend_w = [];
       $chart_a_w = [];
       $reports_w = $raw->ra_report_set_wip();
       $chart_settings_w = $raw->ra_report_wip_value_byItem_settings;
       foreach ($reports_w as $key => $report_data_w) {
        $key_name_setting = $key . '_settings';
        $svgimage = new getsvgimage();
        $svgimage->setProperty('_settings', $chart_settings_w);
        if (property_exists($raw, $key_name_setting)) {
         $this_chart_settings = $raw->$key_name_setting;
         $svgimage->setProperty('_settings', $this_chart_settings);
        }

        $svgimage->setProperty('_data', $report_data_w);
        $chart = $svgimage->draw_chart();
        array_push($chart_a_w, $chart);
       }

       if (is_array($chart_a_w)) {
        echo "<ul id='charts_in_report'>";
        foreach ($chart_a_w as $key => $chart_image) {
         echo "<li class=\"chart_no_$key\">$chart_image</li>";
        }
        echo '</ul>';
       } else {
        echo $chart_a_w;
       }
       ?>
      </div>
     </div>
     <div id="tabsHeader-8" class="tabContent"></div>
     <div id="tabsHeader-9" class="tabContent"></div>
    </div>

   </div>
  </form>
 </div>
</div>    
