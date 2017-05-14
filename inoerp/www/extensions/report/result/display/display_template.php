<link href="<?php echo HOME_URL; ?>css/getsvgimage.css" media="all" rel="stylesheet" type="text/css" />
<link href="<?php echo HOME_URL; ?>extensions/report/result/report_result.css" media="all" rel="stylesheet" type="text/css" />
<script>
 $(document).ready(function () {
  var scriptLink1 = "<?php echo HOME_URL; ?>extensions/report/result/report_result.js";
  var scriptLink2 = "<?php echo HOME_URL; ?>includes/js/reload.js";
  include_once(scriptLink1);
  include_once(scriptLink2);
 });</script>



<div class ="extn_report_content"><span class="heading">
  <?php echo!empty($$class->extn_report_name) ? "Custom Report : " . ucwords(str_replace('_', ' ', $$class->extn_report_name)) : ''; ?></span>
 <div id="tabsDetailA">
  <ul class="tabMain">
   <li><a href="#tabsDetailA-1"><?php echo gettext('Result Graph') ?></a></li>
   <li><a href="#tabsDetailA-2"><?php echo gettext('Result Data') ?></a></li>
   
  </ul>
  <div class="tabContainer">
   <div id="tabsDetailA-1" class="tabContent">
    <div class="draw_chart">
     <div class="draw_chart_data" class="scrollElement">
      <div class="svg_image">
       <?php echo!empty($svg_chart) ? $svg_chart : ""; ?>
      </div>
     </div>
     <ul class="column header_field_small tabContainer">
      <li><label><?php echo gettext('Chart Type') ?></label> 
       <?php echo $f->select_field_from_array('chart_type', getsvgimage::$chart_type_a, $$class->chart_type, 'chart_type'); ?></li>
      <li><label><?php echo gettext('Chart Width') ?></label><?php echo $f->number_field('chart_width', $$class->chart_width, '', 'chart_width'); ?></li>
      <li><label><?php echo gettext('Chart Height') ?></label><?php echo $f->number_field('chart_height', $$class->chart_height, '', 'chart_height'); ?></li>
      <li><label><?php echo gettext('Label Field') ?></label>
       <?php
       if (!empty($column_list)) {
        echo $f->select_field_from_array('chart_label', $column_list, $$class->chart_label, 'chart_label', 'medium');
       } else {
        echo $f->text_field('chart_label', $$class->chart_label);
       }
       ?>
      </li>
      <li><label><?php echo gettext('Value Field') ?></label>
       <?php
       if (!empty($column_list)) {
        echo $f->select_field_from_array('chart_value', $column_list, $$class->chart_value, 'chart_value', 'parameter medium');
       } else {
        echo $f->text_field('chart_value', $$class->chart_value);
       }
       ?>
      </li>
      <li><label><?php echo gettext('Legend') ?></label>
       <?php
       if (!empty($column_list)) {
        echo $f->select_field_from_array('chart_legend', $column_list, $$class->chart_legend, 'chart_legend', 'medium');
       } else {
        echo $f->text_field('chart_legend', $$class->chart_legend);
       }
       ?></li>
                  <li><label>Legend 2</label>
       <?php
//       pa($$class);
       if (!empty($column_list)) {
        echo $f->select_field_from_array('chart_legend2', $column_list, $$class->chart_legend2, 'chart_legend2', 'medium');
        
       } else {
        echo $f->text_field_dl('chart_legend2', '');
       }
       ?></li>
      <li><label></label><input type="button" role="button" value="Draw Chart" class="btn btn-sm btn-success display_result draw_svg_image" ></li>
     </ul>

    </div>
   </div>
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
