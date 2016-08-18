<div id ="form_header">
 <form method="post" id="bc_label_format_header"  name="bc_label_format_header">
  <span class="heading"><?php echo gettext('Barcode Label Format') ?></span>
  <div id="tabsHeader">
   <ul class="tabMain">
    <li><a href="#tabsHeader-1"><?php echo gettext('Basic Info') ?></a></li>
    <li><a href="#tabsHeader-2"><?php echo gettext('Data Object') ?></a></li>
   </ul>
   <div class="tabContainer">
    <div id="tabsHeader-1" class="tabContent">
     <ul class="column header_field">
      <li><?php $f->l_text_field_dr_withSearch('bc_label_format_header_id') ?>
       <a name="show" href="form.php?class_name=bc_label_format_header&<?php echo "mode=$mode"; ?>" class="show document_id bc_label_format_header_id">
        <i class="fa fa-refresh"></i></a> 
      </li>
      <li><?php $f->l_text_field_d('format_name'); ?></li>
      <li><?php $f->l_select_field_from_object('label_type', bc_label_format_header::label_type(), 'option_line_code', 'option_line_value', $$class->label_type); ?></li>
      <li><?php $f->l_date_fieldFromToday('disable_date', $$class->disable_date); ?></li>
      <li><?php $f->l_text_field_d('description'); ?></li>
      <li><?php $f->l_checkBox_field_d('default_cb'); ?></li>
     </ul>
    </div>
    <div id="tabsHeader-2" class="tabContent">
     <div class="large_shadow_box"> 
      <ul class="column one_column">
       <li><?php $f->l_text_field_d('generator_class_name'); ?></li>
       <li><?php $f->l_text_field_d('generator_function_name'); ?></li>
      </ul>
     </div>
    </div>
   </div>
  </div>
 </form>
</div>

<div id="form_line" class="form_line"><span class="heading"><?php echo gettext('Template Fields') ?></span>
 <form method="post" id="bc_label_format_line"  name="bc_label_format_line">
  <div id="tabsLine">
   <ul class="tabMain">
    <li><a href="#tabsLine-1"><?php echo gettext('Basic Info') ?></a></li>
   </ul>
   <div class="tabContainer">
    <div id="tabsLine-1" class="tabContent">
     <table class="form_line_data_table">
      <thead> 
       <tr>
        <th><?php echo gettext('Action') ?></th>
        <th><?php echo gettext('Seq') ?>#</th>
        <th><?php echo gettext('Line Id') ?></th>
        <th><?php echo gettext('Object/Table Name') ?></th>
        <th><?php echo gettext('Sys Field Name') ?></th>
        <th><?php echo gettext('Field Name') ?></th>
        <th><?php echo gettext('Field Description') ?></th>
       </tr>
      </thead>
      <tbody class="form_data_line_tbody">
       <?php
       $count = 0;
       foreach ($bc_label_format_line_object as $bc_label_format_line) {
        if (!empty($$class_second->object_name)) {
         $sys_field_name_a = get_dbColumns_valIndex($$class_second->object_name);
        } else {
         $sys_field_name_a = [];
        }
        ?>         
        <tr class="bc_label_format_line<?php echo $count ?>">
         <td><?php
          echo ino_inline_action($$class_second->bc_label_format_line_id, array('bc_label_format_header_id' => $bc_label_format_header->bc_label_format_header_id));
          ?>        
         </td>
         <td><?php $f->seq_field_d($count) ?></td>
         <td><?php echo $f->text_field_wid2sr('bc_label_format_line_id'); ?></td>
         <td><?php echo $f->select_field_from_object('object_name', extn_view::find_all_tables_and_views(), 'TABLE_NAME', 'TABLE_NAME', $$class_second->object_name, '', 'medium', 1); ?> </td>
         <td><?php echo $f->select_field_from_array('sys_field_name', $sys_field_name_a, $$class_second->sys_field_name, '', 'medium', 1); ?> </td>
         <td><?php echo $f->text_field_wid2l('field_name'); ?></td>
         <td><?php echo $f->text_field_wid2l('description'); ?></td>
        </tr>
        <?php
        $count = $count + 1;
       }
       ?>
      </tbody>
     </table>
    </div>
   </div>
  </div>
 </form>
</div>

<div id="js_data">
 <ul id="js_saving_data">
  <li class="headerClassName" data-headerClassName="bc_label_format_header" ></li>
  <li class="lineClassName" data-lineClassName="bc_label_format_line" ></li>
  <li class="savingOnlyHeader" data-savingOnlyHeader="false" ></li>
  <li class="primary_column_id" data-primary_column_id="bc_label_format_header_id" ></li>
  <li class="form_header_id" data-form_header_id="bc_label_format_header" ></li>
  <li class="line_key_field" data-line_key_field="position_id" ></li>
  <li class="single_line" data-single_line="true" ></li>
  <li class="form_line_id" data-form_line_id="bc_label_format_line" ></li>
 </ul>
 <ul id="js_contextMenu_data">
  <li class="docHedaderId" data-docHedaderId="bc_label_format_header_id" ></li>
  <li class="btn1DivId" data-btn1DivId="bc_label_format_header" ></li>
  <li class="btn2DivId" data-btn2DivId="form_line" ></li>
 </ul>
</div>