<div id="extn_report_divId">
 <div id ="form_header"> <span class="heading"><?php echo gettext('Custom Report Builder'); ?>  </span>
  <form method="post" id="extn_report_header"  name="extn_report_header">
   <div id="tabsHeader">
    <ul class="tabMain">
     <li><a href="#tabsHeader-1"><?php echo gettext('Basic Info')?></a></li>
     <li><a href="#tabsHeader-2"><?php echo gettext('Path')?></a></li>
     <li><a href="#tabsHeader-3"><?php echo gettext('Extra Fields')?></a></li>
     <li><a href="#tabsHeader-4"><?php echo gettext('Display Options')?></a></li>
    </ul>
    <div class="tabContainer">
     <div id="tabsHeader-1" class="tabContent">
      <ul class="column header_field"> 
       <li><?php $f->l_text_field_dr_withSearch('extn_report_id'); ?>
        <a name="show" href="form.php?class_name=extn_report&<?php echo "mode=$mode"; ?>" class="show document_id extn_report_id"><i class="fa fa-refresh"></i></a> 
       </li>
       <li><label><?php echo gettext('Report Name')?></label> <?php $f->text_field_dm('report_name'); ?> </li>
       <li><label><?php echo gettext('Description')?></label> <?php $f->text_field_dl('description'); ?> </li>
       <li class="display_type"><label><?php echo gettext('Display Type') . ':'; ?> </label>
        <?php echo $f->select_field_from_object('display_type', extn_report::extn_report_display_type(), 'option_line_code', 'option_line_value', $$class->display_type, 'display_type'); ?>
       </li>
       <li><?php $f->l_select_field_from_object('module_code', option_header::modules(), 'option_line_code', 'option_line_value', $$class->module_code, 'module_code') ?>				</li>
      </ul> 
     </div>
     <div id="tabsHeader-2" class="tabContent">
      <div> 
       <ul class="column header_field">
        <li><label><?php echo gettext('Path Id')?></label> <?php echo $f->text_field_dr('path_id'); ?></li>
        <li><label><?php echo gettext('Path Value')?></label><?php echo $f->text_field_dl('path'); ?></li>
        <li><label><?php echo gettext('View Report')?></label><a target='_blank' href="<?php echo HOME_URL . $$class->path; ?>"> <?php echo gettext('Online')?> </a></li>
        <li><label><?php echo gettext('Update Parent')?></label> <?php echo $f->checkBox_field('update_parent_id_cb', $$class->update_parent_id_cb); ?></li>
        <li><label><?php echo gettext('Add to menu with parent')?></label>
         <?php echo $f->select_field_from_object('parent_id', path::find_all('name'), 'path_id', array('name', 'module_code'), $$class->parent_id, 'parent_id', '', '', 1) ?>
        </li>

       </ul>
      </div>
     </div>
     <div id="tabsHeader-3" class="tabContent">
      <div> 
       <ul class="column four_column">
        <li><label><?php echo gettext('Custom Div Class')?></label> <?php echo $f->text_field_dl('custom_div_class'); ?></li>
        <li><label><?php echo gettext('Header Text')?></label><?php echo $f->text_area('header_text', $$class->header_text); ?></li>
        <li><label><?php echo gettext('Footer Text')?></label> <?php echo $f->text_area('footer_text', $$class->footer_text); ?></li>
        <li><label><?php echo gettext('Remove Default Header')?></label> <?php echo $f->checkBox_field('remove_default_header_cb', $$class->remove_default_header_cb); ?></li>
       </ul>
      </div>
     </div>
     <div id="tabsHeader-4" class="tabContent">
      <div> 
       <ul class="column header_field">
        <li><label><?php echo gettext('Columns in Grid')?></label> <?php echo $f->number_field('no_of_grid_columns', $$class->no_of_grid_columns, '', 'no_of_grid_columns', 'large'); ?></li>
        <li><label><?php echo gettext('Default Per Page')?></label> <?php echo $f->number_field('default_per_page', $$class->default_per_page, '', 'default_per_page', 'large'); ?></li>
        <li><label><?php echo gettext('List Type')?></label>
         <?php echo $f->select_field_from_array('list_type', dbObject::$list_type_a, $$class->list_type); ?></li>
        <li><label><?php echo gettext('Create/Update Block')?></label><?php echo $f->checkBox_field('create_block_cb', ''); ?></li>
        <li><label><?php echo gettext('Show only graph in block')?></label><?php echo $f->checkBox_field('show_graph_only_cb', $$class->show_graph_only_cb); ?></li>
        <li><label><?php echo gettext('Dont show graph')?></label><?php echo $f->checkBox_field('dont_show_graph_cb', $$class->dont_show_graph_cb); ?></li>
        <li><label><?php echo gettext('View Block')?></label>
         <?php
         echo!empty($$class->block_id) ? "<a href='form.php?class_name=block&mode=9&block_id=" . $$class->block_id . "'>Configure Block</a>" : 'No Block';
         echo $f->hidden_field_withId('block_id', $$class->block_id);
         ?>
        </li>
       </ul>
      </div>
     </div>
    </div>
   </div>
   <div id="form_line" class="form_line"><span class="heading">Report Details </span>
    <div id="tabsLine">
     <ul class="tabMain">
      <li><a href="#tabsLine-1"><?php echo gettext('SQL Query')?></a></li>
      <li><a href="#tabsLine-2"><?php echo gettext('Live Display')?></a></li>
      <li><a href="#tabsLine-3"><?php echo gettext('Graph')?></a></li>
     </ul>
     <div class="tabContainer">
      <div id="tabsLine-1" class="tabContent">
       <div id="extn_report_query">
        <textarea name="query_v"  query_v="query" id="query_v" rows="12" cols="150" placeholder="Write SQL Query Here"><?php echo base64_decode($extn_report->query_v); ?></textarea>
       </div> 
      </div>
      <div id="tabsLine-2" class="tabContent">
       <div id="basic_settings"><span class="heading"><input type="button" value="Display Result" class="button display_result" id="display_report_result"></span>
        <div id="live_display"><label><?php echo gettext('Live Display')?></label>
         <div class="live_display_data scrollElement" >
          <?php echo!empty($extn_report_result) ? $extn_report_result : ""; ?>
         </div>
        </div>

       </div>
      </div>
      <div id="tabsLine-3" class="tabContent">
       <div id="basic_settings">

        <div> 
         <ul class="column header_field form_header_l">
          <li><label>Chart Type</label> 
           <?php echo $f->select_field_from_array('chart_type', getsvgimage::$chart_type_a, $$class->chart_type, 'chart_type'); ?></li>
          <li><label><?php echo gettext('Chart Width')?></label><?php echo $f->number_field('chart_width', $$class->chart_width, '', 'chart_width'); ?></li>
          <li><label><?php echo gettext('Chart Height')?></label><?php echo $f->number_field('chart_height', $$class->chart_height, '', 'chart_height'); ?></li>
          <li><label><?php echo gettext('Label Field')?></label>
           <?php
           if (!empty($column_list)) {
            echo $f->select_field_from_array('chart_label', $column_list, $$class->chart_label, 'chart_label');
           } else {
            echo $f->text_field_dl('chart_label', $$class->chart_label);
           }
           ?>
          </li>
          <li><label><?php echo gettext('Value Field')?></label>
           <?php
           if (!empty($column_list)) {
            echo $f->select_field_from_array('chart_value', $column_list, $$class->chart_value, 'chart_value');
           } else {
            echo $f->text_field_dl('chart_value', $$class->chart_value);
           }
           ?>
          </li>
          <li><label><?php echo gettext('Legend')?></label>
           <?php
           if (!empty($column_list)) {
            echo $f->select_field_from_array('chart_legend', $column_list, $$class->chart_legend, 'chart_legend');
           } else {
            echo $f->text_field_dl('chart_legend', $$class->chart_legend);
           }
           ?></li>
          <li><label><?php echo gettext('Legend 2')?></label>
           <?php
           if (!empty($column_list)) {
            echo $f->select_field_from_array('chart_legend2', $column_list, $$class->chart_legend2, 'chart_legend2');
           } else {
            echo $f->text_field_dl('chart_legend2', $$class->chart_legend2);
           }
           ?></li>
         </ul>
        </div>
        <div id="draw_chart"><label><?php echo gettext('Live Chart')?></label>
         <div id="draw_chart_data" class="scrollElement">
          <span class="heading"><input type="button" value="<?php echo gettext('Draw Chart')?>" class="button display_result" id="draw_svg_image"></span>
          <div class="svg_image">
          </div>
         </div>
        </div>

       </div>
      </div>
     </div>
    </div>

   </div>


  </form>   
 </div>
</div>
<div id="js_data">
 <ul id="js_saving_data">
  <li class="headerClassName" data-headerClassName="extn_report" ></li>
  <li class="savingOnlyHeader" data-savingOnlyHeader="true" ></li>
  <li class="primary_column_id" data-primary_column_id="extn_report_id" ></li>
  <li class="form_header_id" data-form_header_id="extn_report_header" ></li>
 </ul>
 <ul id="js_contextMenu_data">
  <li class="docHedaderId" data-docHedaderId="extn_report_id" ></li>
  <li class="btn1DivId" data-btn1DivId="extn_report_id" ></li>
 </ul>
</div>
