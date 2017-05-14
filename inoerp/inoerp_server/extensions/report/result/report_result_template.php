<link href="<?php echo HOME_URL; ?>css/getsvgimage.css" media="all" rel="stylesheet" type="text/css" />
<div class ="extn_report_content">
 <span class="heading">
  <?php echo!empty($$class->report_name) ? ucwords(str_replace('_', ' ', $$class->report_name)) : ''; ?></span>
 <div id="tabsDetailA">
  <ul class="tabMain">
   <?php
   if (!empty($$class->chart_type)) {
    echo '<li><a href="#tabsDetailA-1">Result Graph</a></li>';
   }
   ?>
   <li><a href="#tabsDetailA-2">Result Data</a></li>
  </ul>
  <div class="tabContainer">
   <?php
   if (!empty($$class->chart_type)) {
    include_once __DIR__ . '/chart_template/chart_template.php';
   }
   ?>
   <div id="tabsDetailA-2" class="tabContent">
    <?php echo $f->hidden_field('extn_report_id', $$class->extn_report_id); ?>
    <div class="extn_report_filters">
    </div>
    <div class ="live_display_data scrollElement" >
     <?php
     echo $f->hidden_field_withId('extn_report_id', $$class->extn_report_id);
     echo!empty($$class->extn_report_id) ? $$class->show_reportResult($$class->extn_report_id) : "";
     ?>
    </div>
   </div>
  </div>
 </div>
</div>