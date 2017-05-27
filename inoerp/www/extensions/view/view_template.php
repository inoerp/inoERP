<div id="view_divId">
 <div id ="form_header"> <span class="heading"> View - Dynamic Query Builder  </span>
  <form  method="post" id="view_header"  name="view_header">
   <div id="tabsHeader">
    <ul class="tabMain">
     <li><a href="#tabsHeader-1">Basic Info</a></li>
     <li><a href="#tabsHeader-2">Path</a></li>
     <li><a href="#tabsHeader-3">Extra Fields</a></li>
     <li><a href="#tabsHeader-4">Display Options</a></li>
    </ul>
    <div class="tabContainer">
     <div id="tabsHeader-1" class="tabContent">
      <ul class="column header_field"> 
       <li><?php $f->l_text_field_dr_withSearch('extn_view_id'); ?>
        <a name="show" href="form.php?class_name=extn_view&<?php echo "mode=$mode"; ?>" class="show document_id view_id"><i class="fa fa-refresh"></i></a> 
       </li>
       <li><label>View Name</label> <?php $f->text_field_dm('view_name'); ?> </li> 
       <li><label>Description</label> <?php $f->text_field_dl('description'); ?> </li> 
       <li class="display_type"><label> Display Type: </label> 
        <?php echo $f->select_field_from_object('display_type', extn_view::view_display_type(), 'option_line_code', 'option_line_value', $$class->display_type, 'display_type'); ?>
       </li>
      </ul> 
     </div>
     <div id="tabsHeader-2" class="tabContent">
      <div> 
       <ul class="column three_column">
        <li><label>Path Id</label> <?php echo $f->text_field_dr('path_id'); ?></li>
        <li><label>Path Value</label><?php echo $f->text_field_dl('path'); ?></li>
        <li><label>View </label><a target='_blank' href="<?php echo HOME_URL . $$class->path; ?>"> Online </a></li>
        <li><label>Update Parent</label> <?php echo $f->checkBox_field('update_parent_id_cb', $$class->update_parent_id_cb); ?></li>
        <li><label>Add to menu with parent</label> 
         <?php echo $f->select_field_from_object('parent_id', path::find_all('name'), 'path_id', array('name', 'module_code'), $$class->parent_id, 'parent_id', '', '', 1) ?>
        </li>

       </ul>
      </div>
     </div>
     <div id="tabsHeader-3" class="tabContent">
      <div> 
       <ul class="column four_column">
        <li><label>Custom Div Class</label> <?php echo $f->text_field_dl('custom_div_class'); ?></li>
        <li><label>Header Text</label><?php echo $f->text_area('header_text', $$class->header_text); ?></li>
        <li><label>Footer Text</label> <?php echo $f->text_area('footer_text', $$class->footer_text); ?></li>
        <li><label>Remove Default Header </label> <?php echo $f->checkBox_field('remove_default_header_cb', $$class->remove_default_header_cb); ?></li>
       </ul>
      </div>
     </div>
     <div id="tabsHeader-4" class="tabContent">
      <div> 
       <ul class="column four_column">
        <li><label>Columns in Grid</label> <?php echo $f->number_field('no_of_grid_columns', $$class->no_of_grid_columns, '', 'no_of_grid_columns', 'large'); ?></li>
        <li><label>Default Per Page</label> <?php echo $f->number_field('default_per_page', $$class->default_per_page, '', 'default_per_page', 'large'); ?></li>
        <li><label>List Type</label> 
         <?php echo $f->select_field_from_array('list_type', dbObject::$list_type_a, $$class->list_type); ?></li>
        <li><label>Create/Update Block : </label><?php echo $f->checkBox_field('create_block_cb', ''); ?></li>
        <li><label>View Block</label>
         <?php
         echo!empty($$class->block_id) ? "<a href='form.php?class_name=block&mode=9&block_id=" . $$class->block_id . "'>Configure Block</a>" : 'No Block';
         echo $f->hidden_field_withId('block_id', $$class->block_id);
         ?>
        </li>
        <li><label>Show only graph in block : </label><?php echo $f->checkBox_field('show_graph_only_cb', $$class->show_graph_only_cb); ?></li>
       </ul>
      </div>
     </div>
    </div>
   </div>
   <div id="form_line" class="form_line"><span class="heading">View Details </span>
    <div id="tabsLine">
     <ul class="tabMain">
      <li><a href="#tabsLine-1">Settings</a></li>
      <li><a href="#tabsLine-2">SQL Query</a></li>
      <li><a href="#tabsLine-3">Live Display</a></li>
      <li><a href="#tabsLine-4">Graph</a></li>
     </ul>
     <div class="tabContainer">
      <div id="tabsLine-1" class="tabContent">
       <div>
        <?php
        if (!empty($view->logical_settings)) {
         echo '<ul id="logical_settings">';
         echo base64_decode($view->logical_settings);
         echo '</ul>';
        } else {
         ?>
         <ul id="logical_settings">
          <li><label>Tables</label> 
           <span class="add_new_table clickable" ><img  src="<?php echo HOME_URL; ?>themes/images/plus_10.png" alt="add new table" />New Table</span>
           <input type="button" value="Save Tables" class="button save_tables" id="save_tables">
           <input type="button" value="Sum" class="btn btn-default" id="func_sum">
           <input type="button" value="Average" class="btn btn-default" id="func_avg">
           <input type="button" value="Maximum" class="btn btn-default" id="func_max">
           <input type="button" value="Mimimum" class="btn btn-default" id="func_min">
           <input type="button" value="Count" class="btn btn-default" id="func_count">
          </li>
          <div id="display_div"> 
           <?php
           $tbl_count = 0;
           if (!empty($table_column_name)) {
            foreach ($table_names as $tbl_k => $tbl_v) {
             ?>
             <ul class="display_records table_object<?php echo $tbl_count; ?>">
              <li id="table_records"><label>Table Names </label>
               <?php echo $f->select_field_from_object('all_table_names', extn_view::find_all_tables_and_views(), 'TABLE_NAME', 'TABLE_NAME', $tbl_k); ?>
              </li>
              <?php
              foreach ($tbl_v as $column_k => $column_v) {
               echo '<li class="field_records record_no0">';
               echo $f->select_field_from_object('column_name', extn_view::find_columns_of_table_obj($tbl_k), 'Field', 'Field', $column_v, '', 'table_fields');
               echo '</li>';
              }
              ?>
             </ul>
             <?php
             $tbl_count++;
            }
           } else {
            ?>
            <ul class="display_records table_object0">
             <li id="table_records"><label>Table Names </label>
              <?php echo $f->select_field_from_object('all_table_names', extn_view::find_all_tables_and_views(), 'TABLE_NAME', 'TABLE_NAME', '', '', 'all_table_names') ?>
             </li>
             <li class="field_records record_no0"><Label>Field</label>
              <select class="table_fields">
               <option value=" " disabled><?php echo gettext('Select Table'); ?></option>
              </select>
             </li>
            </ul>
           <?php }
           ?>
          </div>
          <li id="show_field_li"><label>Show Fields</label>
           <ul id="show_field_buttons">
            <span class="add_new_fields clickable">Available Fields</span>
            <?php echo $show_field_stmt; ?>
           </ul>
          </li>
          <li id="condition_li"><label>Conditions</label>
           <div id="condition_buttons">
            <span class="add_new_conditions clickable" ><img  src="<?php echo HOME_URL; ?>themes/images/plus_10.png" alt="add new conditions" />New Conditions</span>
            <span class='hint'> ( Double click on any field to remove it )</span>
           </div>
           <div id="condition_buttons_info">
           </div>
           <table id="condition_buttons_table">
            <thead>
             <tr>
              <th>Parameter</th>
              <th>Condition</th>
              <th>Value</th>
             </tr>
            </thead>
            <tbody>
             <?php echo!empty($cond_stmt) ? $cond_stmt : ''; ?>
             <tr class="condition_row">
              <td class="condition_row_parameter">      </td>
              <td class="condition_row_condition">
               <ul>
                <li><?php echo $f->select_field_from_array('condition_operator_type', extn_view::$condition_operator_type_a, $$class->condition_operator_type); ?></li>
                <li><?php echo $f->select_field_from_array('condition_operator', dbObject::$db_control_type_a, '', 'condition_operator'); ?>  </li>
               </ul>
              </td>
              <td class="condition_row_value"></td>
             </tr>
            </tbody>
           </table>
          </li> 
          <li id="sort_sqlQuery">
           <ul> 
            <li id="groupBy_li"> <label>Group By</label>
             <span class="add_new_groupBy_criteria clickable" ><img  src="<?php echo HOME_URL; ?>themes/images/plus_10.png" alt="add new group by" />New Group By</span>
             <table id="group_by_table">
              <thead>
               <tr>
                <th>Field Names</th>
               </tr>
              </thead>
              <tbody>
               <?php echo!empty($groupBy_stmt) ? $groupBy_stmt : ''; ?>
               <tr class=group_by_row">
                <td class="group_by_fields">
                </td>
               </tr>
              </tbody>
             </table>
            </li> 
            <li id="sorting_li"> <label>Sorting</label>
             <span class="add_new_sort_criteria clickable" ><img  src="<?php echo HOME_URL; ?>themes/images/plus_10.png" alt="add new conditions" />New Sorting Criteria</span>
             <table id="sort_fields_table">
              <thead>
               <tr>
                <th>Fields</th>
                <th>Sort by</th>
               </tr>
              </thead>
              <tbody>
               <?php echo!empty($orderby_stmt) ? $orderby_stmt : ''; ?>
               <tr class="sort_fields_row">
                <td class="sort_fields_field_value">

                </td>
                <td class="sort_fields_sortBy"> <?php echo $f->select_field_from_array('sort_fields_values', dbObject::$sort_fields_values_a, ''); ?></td>
               </tr>
              </tbody>
             </table>
            </li> 
          </li>
         </ul>
         </li>
         <li id="other_field">
          <ul>
           <li><label>Parameter</label></li> 
           <li><label>Relationships</label></li> 
           <li><label>Callback</label></li> 
         </li>
         </ul>
         </li>
         </ul>
        <?php } ?>
        <input type="hidden" name="logical_settings" id="logical_settings_value">
       </div>
      </div>
      <div id="tabsLine-2" class="tabContent">
       <input type="button" value="Update Query" class="button save_query" id="save_query">

       <div id="view_query"><label>SQL Query</label>
        <textarea name="query_v"  query_v="query" id="query_v" rows="6" cols="118"><?php echo base64_decode($view->query_v); ?></textarea>
        <ul id="sql_query">
         <li class="select">
          <label>SELECT</label>
          <textarea name="select_v"  class="select_v" id="select_v" rows="6" cols="30"><?php echo $view->select_v; ?></textarea>
         </li>
         <li class="select">
          <label>FROM</label>
          <textarea name="from_v"  class="from_v" id="from_v" rows="6" cols="15"><?php echo $view->from_v; ?></textarea>
         </li>
         <li class="select">
          <label>WHERE</label>
          <textarea name="where_v"  class="where_v" id="where_v" rows="6" cols="15"><?php echo $view->where_v; ?></textarea>
         </li>
         <li class="select">
          <label>GROUP BY</label>
          <textarea name="group_by_v"  class="group_by_v" id="group_by_v" rows="6" cols="15"><?php echo $view->group_by_v; ?></textarea>
         </li>
         <li class="select">
          <label>ORDER BY</label>
          <textarea name="order_by"  class="order_by" id="order_by" rows="6" cols="15"><?php echo $view->order_by; ?></textarea>
         </li>
         <li class="select">
          <label>FILTERS</label>
          <textarea name="filters" class="filters" id="filters" rows="6" cols="15"><?php echo $view->filters; ?></textarea>
         </li>
         <li class="select">
          <label>End clause</label>
          <textarea name="query_end" readonly class="query_end" id="query_end" rows="6" cols="10"><?php echo $view->query_end; ?></textarea>
         </li>
        </ul>
       </div> 
      </div>
      <div id="tabsLine-3" class="tabContent">
       <div id="basic_settings"><span class="heading"><input type="button" value="Display Result" class="button display_result" id="display_result"></span>
        <div id="live_display"><label>Live Display</label>
         <div class="live_display_data scrollElement" >
          <?php echo!empty($view_result) ? $view_result : ""; ?>
         </div>
        </div>

       </div>
      </div>
      <div id="tabsLine-4" class="tabContent">
       <div id="basic_settings">

        <div> 
         <ul class="column four_column">
          <li><label>Chart Type : </label> 
           <?php echo $f->select_field_from_array('chart_type', getsvgimage::$chart_type_a, $$class->chart_type, 'chart_type'); ?></li>
          <li><label>Chart Width : </label><?php echo $f->number_field('chart_width', $$class->chart_width, '', 'chart_width'); ?></li>
          <li><label>Chart Height : </label><?php echo $f->number_field('chart_height', $$class->chart_height, '', 'chart_height'); ?></li>
          <li><label>Label Field : </label>
           <?php
           if (!empty($column_list)) {
            echo $f->select_field_from_array('chart_label', $column_list, $$class->chart_label, 'chart_label');
           } else {
            echo $f->text_field_dl('chart_label', $$class->chart_label);
           }
           ?>
          </li>
          <li><label>Value Field : </label>
           <?php
           if (!empty($column_list)) {
            echo $f->select_field_from_array('chart_value', $column_list, $$class->chart_value, 'chart_value');
           } else {
            echo $f->text_field_dl('chart_value', $$class->chart_value);
           }
           ?>
          </li>
          <li><label>Legend : </label>
           <?php
           if (!empty($column_list)) {
            echo $f->select_field_from_array('chart_legend', $column_list, $$class->chart_legend, 'chart_legend');
           } else {
            echo $f->text_field_dl('chart_legend', $$class->chart_legend);
           }
           ?></li>
         </ul>
        </div>
        <div id="draw_chart"><label>Live Chart</label>
         <div id="draw_chart_data" class="scrollElement">
          <span class="heading"><input type="button" value="Draw Chart" class="button display_result" id="draw_svg_image"></span>
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
  <li class="headerClassName" data-headerClassName="extn_view" ></li>
  <li class="savingOnlyHeader" data-savingOnlyHeader="true" ></li>
  <li class="primary_column_id" data-primary_column_id="extn_view_id" ></li>
  <li class="form_header_id" data-form_header_id="view_header" ></li>
 </ul>
 <ul id="js_contextMenu_data">
  <li class="docHedaderId" data-docHedaderId="extn_view_id" ></li>
  <li class="btn1DivId" data-btn1DivId="extn_view_id" ></li>
 </ul>
</div>
