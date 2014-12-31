<script src="<?php echo HOME_URL; ?>includes/js/report.js"></script>
<link href="<?php echo HOME_URL; ?>includes/ecss/getsvgimage.css" media="all" rel="stylesheet" type="text/css" />
      <div id ="form_header">
       <div id="tabsHeader">
        <form action="" method="post" id="user_header" name="user_header"><span class="heading">User Dashboard 
         <a href="<?php echo HOME_URL ?>form.php?class_name=user_dashboard_config&mode=9&user_id=<?php echo $_GET['user_id'] ?>">
          <img src="<?php echo THEME_URL ; ?>/images/config_16.png" alt=" update favourite" title='Confiure Dashboard'/>
                </a>
         </span>
         <div id ="form_header">
          <div id="tabsHeader">
           <ul class="tabMain">
            <li><a href="#tabsHeader-1">Access</a></li>
            <li><a href="#tabsHeader-2">On hand</a></li>
            <li><a href="#tabsHeader-3">Purchasing</a></li>
            <li><a href="#tabsHeader-4">WIP Value</a></li>
           </ul>
           <div class="tabContainer"> 
            <div id="tabsHeader-1" class="tabContent">
             <ul class="column three_column">
              <li>
               <span class="expand_collapse_all button clickable">Expand / Collapse All</span>
               <?php
                $pat = new path();
                echo ($pat->path_allpaths_block(array('divClass' => 'tree_view')));
               ?>
              </li>
              <li>
               <span class="button"><a href="<?php echo HOME_URL ?>form.php?class_name=user_favourite&mode=9">Favourites 
                 <img src="<?php echo THEME_URL ; ?>/images/edit.png" alt=" update favourite" title='Update Favourite'/>
                </a></span>
               <?php
                echo $fav->show_currentUser_fav();
                echo block::show_block_content_by_BlockId('57');
               ?>
              </li>               
             </ul>
            </div>
            <div id="tabsHeader-2" class="tabContent">
             <?php
              $view_i = new view();
              $view_i->view_id = 11;
              $view_i->viewResultById();
             ?>
            </div>
            <div id="tabsHeader-3" class="tabContent">
             <?php
              $view_i->view_id = 12;
              $view_i->viewResultById();
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
