<script src="<?php echo HOME_URL; ?>includes/js/report.js"></script>
<link href="<?php echo HOME_URL; ?>includes/ecss/getsvgimage.css" media="all" rel="stylesheet" type="text/css" />
<div id="all_contents">
 <div id="content_left"></div>
 <div id="content_right">
  <div id="content_right_left">
   <div id="content_top"></div>
   <div id="content">
    <div id="structure">
     <div id="userDashBoard">
      <!--    START OF FORM HEADER-->
      <div class="error"></div><div id="loading"></div>
      <?php echo (!empty($show_message)) ? $show_message : ""; ?> 
      <!--    End of place for showing error messages-->
      <div id ="form_header">
       <div id="tabsHeader">
        <form action="" method="post" id="user_header" name="user_header"><span class="heading">User Dashboard </span>
         <div id ="form_header">
          <div id="tabsHeader">
           <ul class="tabMain">
            <li><a href="#tabsHeader-1">Access</a></li>
            <li><a href="#tabsHeader-2">Purchasing</a></li>
            <li><a href="#tabsHeader-3">On hand</a></li>
            <li><a href="#tabsHeader-4">WIP Value</a></li>
           </ul>
           <div class="tabContainer"> 
            <div id="tabsHeader-1" class="tabContent">
             <ul class="column three_column">
              <li>
               <span class="expand_collapse_all button clickable">Expand / Collapse All</span>
               <?php
                $pat = new path();
                echo ($pat->path_allpaths_block('', '', 'tree_view'));
               ?>
              </li>               <li>
               <span class="button"><a href="<?php echo HOME_URL ?>form.php?class_name=user_favourite&mode=9">Favourites 
                 <img src="<?php echo HOME_URL; ?>themes/images/edit.png" alt="update favourite" />
                </a></span>
               <?php
                echo $fav->show_currentUser_fav();
               ?>
              </li>               
             </ul>
            </div>
            <div id="tabsHeader-2" class="tabContent">
               <?php
                $poa = new po_all_v();
                $legend_p = [];
                $chart_a_p = [];
                $reports_p = $poa->ra_report_set_purchasing_analysis();
                $chart_settings_p = $poa->ra_report_set_purchasing_analysis_settings;
                foreach ($reports_p as $key => $report_data_p) {
                 $key_name_setting = $key . '_settings';
                 $svgimage = new getsvgimage();
                 $svgimage->setProperty('_settings', $chart_settings_p);
                 if (property_exists($poa, $key_name_setting)) {
                  $this_chart_settings = $poa->$key_name_setting;
                  $svgimage->setProperty('_settings', $this_chart_settings);
                 }

                 $svgimage->setProperty('_data', $report_data_p);
                 $chart = $svgimage->draw_chart();
                 array_push($chart_a_p, $chart);
                }

                if (is_array($chart_a_p)) {
                 echo "<ul id='charts_in_report'>";
                 foreach ($chart_a_p as $key => $chart_image) {
                  echo "<li class=\"chart_no_$key\">$chart_image</li>";
                 }
                 echo '</ul>';
                } else {
                 echo $chart_a_p;
                }
               ?>
            </div>
            <div id="tabsHeader-3" class="tabContent">
             <?php
              $ov = new onhand_v;
              $legend = [];
              $chart_a = [];
              $reports = $ov->ra_report_set_onhand_by_subinventoryType();
              $report_name = 'ra_report_set_onhand_by_subinventoryType';
              $chart_settings = $ov->ra_report_set_onhand_by_subinventoryType_settings;
              $count = 0;
              foreach ($reports as $key => $report_data) {
               $key_name_setting = $key . '_settings';
               $svgimage = new getsvgimage();
               $svgimage->setProperty('_settings', $chart_settings);
               if (property_exists($ov, $key_name_setting)) {
                $this_chart_settings = $ov->$key_name_setting;
                $svgimage->setProperty('_settings', $this_chart_settings);
               }

               $svgimage->setProperty('_data', $report_data);
               $chart = $svgimage->draw_chart();
               array_push($chart_a, $chart);
               $count++;
              }

              if (is_array($chart_a)) {
               echo "<ul id='charts_in_report'>";
               foreach ($chart_a as $key => $chart_image) {
                echo "<li class=\"chart_no_$key\">$chart_image</li>";
               }
               echo '</ul>';
              } else {
               echo $chart_a;
              }
             ?>
            </div>
            <div id="tabsHeader-4" class="tabContent">
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
           </div>

          </div>
         </div>
        </form>
       </div>
      </div>    
     </div>
    </div>
    <!--   end of structure-->
   </div>
   <div id="content_bottom"></div>
  </div>
  <div id="content_right_right"></div>
 </div>

</div>

<?php include_template('footer.inc') ?>

<script type="text/javascript">
 $(document).ready(function() {
  treeView();
 });</script>
