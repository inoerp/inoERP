<link href="<?php echo HOME_URL; ?>css/getsvgimage.css" media="all" rel="stylesheet" type="text/css" />
<div id ="form_header">
 <div id="tabsHeader">
  <form action="" method="post" id="user_header" name="user_header"><span class="heading"><?php echo gettext('User Dashboard') ?> 
    <a href="<?php echo HOME_URL ?>form.php?class_name=user_dashboard_config&mode=9&user_id=<?php echo $user_id ?>" 
       class='fa fa-cog'></a>
   </span>
   <div id ="form_header">
    <div id="tabsHeader">
     <ul class="tabMain">
      <li><a href="#tabsHeader-1"><?php echo gettext('Navigation') ?></a></li>
      <li><a href="#tabsHeader-2"><?php echo gettext('Quick Info') ?></a></li>
      <li><a href="#tabsHeader-3"><?php echo gettext('On Hand') ?></a></li>
      <li><a href="#tabsHeader-4"><?php echo gettext('Purchasing') ?></a></li>
      <li><a href="#tabsHeader-5"><?php echo gettext('WIP Value') ?></a></li>
     </ul>
     <div class="tabContainer"> 
      <div id="tabsHeader-1" class="tabContent">
       <ul id='dashborad_menu'>
        <li><a href="form.php?module_code=inv"><i class="fa fa-bank"></i> <?php echo gettext('Inventory') ; ?></a></li>
        <li><a href="form.php?module_code=sd"><i class="fa fa-truck"></i> <?php echo gettext('Sales & Distribution') ; ?> </a></li>
        <li><a href="form.php?module_code=sys"><i class="fa fa-file-text-o"></i> <?php echo gettext('Purchasing') ; ?></a></li>
        <li><a href="form.php?module_code=bom"><i class="fa fa-sitemap"></i> <?php echo gettext('Bills Of Material') ; ?></a></li>
        <li><a href="form.php?module_code=cst"><i class="fa fa-cubes"></i> <?php echo gettext('Cost Management') ; ?> </a></li>
        <li><a href="form.php?module_code=wip"><i class="fa fa-tasks"></i> <?php echo gettext('WIP & MES') ; ?> </a></li>
        <li><a href="form.php?module_code=fp"><i class="fa fa-th-large"></i> <?php echo gettext('Forecast & Planning') ; ?> </a></li>
        <li class="Point Of Sale"><a href="form.php?module_code=pos"><i class="fa fa-shopping-cart"></i> <?php echo gettext('Point Of Sale') ; ?> </a></li>
        <li><a href="form.php?module_code=gl"><i class="fa fa-money"></i> <?php echo gettext('General Ledger') ; ?></a></li>
        <li><a href="form.php?module_code=sys"><span class='inline'><j class="fa fa-dollar"></j><i class="fa fa-arrow-circle-right"></i></span> <?php echo gettext('Accounts Payable') ; ?> </a></li>
        <li><a href="form.php?module_code=sys"><span class='inline'><j class="fa fa-dollar"></j><i class="fa fa-arrow-circle-left"></i></span> <?php echo gettext('Accounts Receivable') ; ?></a></li>
        <li><a href="form.php?module_code=fa"><i class="fa fa-building"></i> <?php echo gettext('Fixed Asset') ; ?> </a></li>
        <li><a href="form.php?module_code=hr"><i class="fa fa-users"></i> <?php echo gettext('Human Resource') ; ?> </a></li>
        <li><a href="form.php?module_code=sys"><i class="fa fa-database"></i> <?php echo gettext('Admin') ; ?></a></li>
        <li><a href="form.php?module_code=sys"><i class="fa fa-cogs"></i> <?php echo gettext('Global Setup') ; ?></a></li>
        <li><a href="form.php?module_code=sys"><i class="fa fa-book"></i> <?php echo gettext('Document & Analysis') ; ?> </a></li>
       </ul>

      </div>
      <div id="tabsHeader-2" class="tabContent">
       <ul class="column three_column">
        <li>
         <h2><?php echo gettext('Notifications') ?></h2>
         <?php
         echo block::show_block_content_by_BlockId('55');
         ?>
        </li>
        <li>
         <h2><?php echo gettext('Recent Comments') ?></h2>
         <?php
         echo block::show_block_content_by_BlockId('52');
//                include_once HOME_URL.'report.php?class_name=ra_item&report_name=ra_report_set_item_leadtime';
         ?>
        </li>
        <li>
         <span class="button"><a href="<?php echo HOME_URL ?>form.php?class_name=user_favourite&mode=9"><?php echo gettext('Favourites') ?> 
           <img src="<?php echo THEME_URL; ?>/images/edit.png" alt=" update favourite" title='<?php echo gettext('Update Favourite') ?>'/>
          </a></span>
         <?php
         echo $fav->show_currentUser_fav();
         echo block::show_block_content_by_BlockId('57');
         ?>
        </li>               
       </ul>
      </div>
      <div id="tabsHeader-3" class="tabContent">
       <?php
       $view_i = new extn_view();
       $view_i->view_id = 11;
       $view_i->viewResultById();
       ?>
      </div>
      <div id="tabsHeader-4" class="tabContent">
       <?php
       $view_i->view_id = 12;
       $view_i->viewResultById();
       ?>
      </div>

      <div id="tabsHeader-5" class="tabContent">
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
