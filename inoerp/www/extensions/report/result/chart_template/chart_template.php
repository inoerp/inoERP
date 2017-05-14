 <div id="tabsDetailA-1" class="tabContent">
    <div class="draw_chart">
     <div class="draw_chart_data" class="scrollElement">
      <div class="svg_image">
       <?php echo!empty($svg_chart) ? $svg_chart : ""; ?>
      </div>
     </div>
     <ul class="column header_field_small tabContainer">
      <li><label>Chart Type</label> 
       <?php echo $f->select_field_from_array('chart_type', getsvgimage::$chart_type_a, $$class->chart_type, 'chart_type'); ?></li>
      <li><label>Chart Width</label><?php echo $f->number_field('chart_width', $$class->chart_width, '', 'chart_width'); ?></li>
      <li><label>Chart Height</label><?php echo $f->number_field('chart_height', $$class->chart_height, '', 'chart_height'); ?></li>
      <li><label>Label Field</label>
       <?php
       if (!empty($column_list)) {
        echo $f->select_field_from_array('chart_label', $column_list, $$class->chart_label, 'chart_label', 'medium');
       } else {
        echo $f->text_field_dl('chart_label', $$class->chart_label);
       }
       ?>
      </li>
      <li><label>Value Field</label>
       <?php
       if (!empty($column_list)) {
        echo $f->select_field_from_array('chart_value', $column_list, $$class->chart_value, 'chart_value', 'parameter medium');
       } else {
        echo $f->text_field_dl('chart_value', $$class->chart_value);
       }
       ?>
      </li>
      <li><label>Legend</label>
       <?php
       if (!empty($column_list)) {
        echo $f->select_field_from_array('chart_legend', $column_list, $$class->chart_legend, 'chart_legend', 'medium');
       } else {
        echo $f->text_field_dl('chart_legend', $$class->chart_legend);
       }
       ?></li>
            <li><label>Legend 2</label>
       <?php
       if (!empty($column_list)) {
        echo $f->select_field_from_array('chart_legend2', $column_list, $$class->chart_legend2, 'chart_legend2', 'medium');
       } else {
        echo $f->text_field_dl('chart_legend2', $$class->chart_legend2);
       }
       ?></li>
      <li><label></label><input type="button" role="button" value="Draw Chart" class="btn btn-sm btn-success display_result draw_svg_image" ></li>
     </ul>
    </div>
   </div>