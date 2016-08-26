<div id="secondary_fieldId">
 <!--    START OF FORM HEADER-->
 <div id ="form_header">
  <span class="heading"><?php echo gettext('Secondary Field For Objects') ?></span>
     <div id="form_serach_header" class="tabContainer">
    <label><?php echo gettext('Object Name') ?></label></label>
    <?php echo $f->select_field_from_object('obj_class_name', extn_view::find_all_tables(), 'TABLE_NAME', 'TABLE_NAME', $obj_class_name_h, 'obj_class_name'); ?>
    <a name="show" href="form.php?class_name=sys_secondary_field_inst&<?php echo "mode=$mode"; ?>" class="show document_id sys_secondary_field_id">
     <i class="fa fa-refresh"></i></a> 
   </div>
 </div>
 <form  method="post" id="secondary_field"  name="secondary_field">
  <!--END OF FORM HEADER-->
  <div id ="form_line" class="secondary_field"><span class="heading">Field Details </span>
   <div id="tabsLine">
    <ul class="tabMain">
     <li><a href="#tabsLine-1"><?php echo gettext('Basic Info') ?> </a></li>
     <li><a href="#tabsLine-2"><?php echo gettext('List Values') ?> </a></li>
    </ul>
    <div class="tabContainer"> 
     <div id="tabsLine-1" class="tabContent">
      <table class="form form_line_data_table line">
       <thead>
        <tr>
         <th><?php echo gettext('Action') ?></th>
         <th><?php echo gettext('Seq') ?>#</th>
         <th><?php echo gettext('Instance Id') ?></th>
         <th><?php echo gettext('Field Name') ?></th>
         <th><?php echo gettext('Label') ?></th>
         <th><?php echo gettext('Type') ?></th>
         <th><?php echo gettext('Control Type') ?></th>
         <th><?php echo gettext('Control Value') ?></th>
         <th><?php echo gettext('Control UOM') ?></th>
         <th><?php echo gettext('Display Weight') ?></th>
         <th><?php echo gettext('Active') ?></th>
        </tr>
       </thead>
       <tbody class="form_data_line_tbody">
        <?php
        $count = 0;
        foreach ($secondary_field_object as $secondary_field) {
         ?>
         <tr class="sys_secondary_field_inst<?php echo $count; ?>">
          <td>   
           <ul class="inline_action">
            <li class="add_row_img clickable"><i class="fa fa-plus-circle"></i></li>
            <li class="remove_row_img"><i class="fa fa-minus-circle"></i></li>
            <li><input type="checkbox" name="line_id_cb" value="<?php echo ($secondary_field->sys_secondary_field_inst_id); ?>">
             <?php echo form::hidden_field('reference_key_name', $obj_class_name_h); ?>
            </li>           
           </ul>
          </td>
          <td><?php $f->seq_field_d($count) ?></td>
          <td><?php echo $f->text_field('sys_secondary_field_inst_id', $secondary_field->sys_secondary_field_inst_id, '8', '', '', '', 1); ?></td>
          <td><?php echo $f->select_field_from_object('sys_secondary_field_id', sys_secondary_field::find_all(), 'sys_secondary_field_id', 'field_name', $secondary_field->sys_secondary_field_id, '', 'medium', '', '', '', '', '', 'field_type'); ?> </td>
          <td><?php echo $f->text_field('label', $secondary_field->label); ?></td>
          <td><?php echo $f->text_field_ap(array('name' => 'field_type', 'value' => $secondary_field->field_type, 'readonly' => true)); ?></td>
          <td><?php echo $f->select_field_from_array('control_type', dbObject::$control_type_a, $secondary_field->control_type); ?></td>
          <td><?php echo $f->text_field('control_value', $secondary_field->control_value); ?></td>
          <td><?php echo $f->select_field_from_object('control_uom', uom::find_all(), 'uom_id', 'uom_name', $secondary_field->control_uom, '', 'uom_id small'); ?></td>
          <td><?php echo $f->select_field_from_array('display_weight', dbObject::$position_array, $secondary_field->display_weight); ?></td>
          <td><?php echo $f->checkBox_field('active_cb', $secondary_field->active_cb); ?></td>
         </tr>
         <?php
         $count++;
        }
        ?>
       </tbody>
      </table>
     </div>
     <div id="tabsLine-2" class="tabContent">
      <table class="form form_line_data_table line">
       <thead>
        <tr>
         <th><?php echo gettext('Seq') ?>#</th>
         <th><?php echo gettext('Lower Limit') ?></th>
         <th><?php echo gettext('Upper Limit') ?></th>
         <th><?php echo gettext('List Option Type') ?></th>
         <th><?php echo gettext('Field Name') ?></th>
        </tr>
       </thead>
       <tbody class="form_data_line_tbody">
        <?php
        $count = 0;
        foreach ($secondary_field_object as $secondary_field) {
         ?>
         <tr class="sys_secondary_field_inst<?php echo $count; ?>">
          <td><?php $f->seq_field_d($count) ?></td>
          <td><?php echo $f->text_field('lower_limit', $secondary_field->lower_limit); ?></td>
          <td><?php echo $f->text_field('upper_limit', $secondary_field->upper_limit); ?></td>
          <td><?php echo $f->select_field_from_object('list_value_option_type', option_header::find_all(), 'option_header_id', 'option_type', $secondary_field->list_value_option_type, '', 'medium'); ?></td>
          <td><?php
           $list_value = !empty($secondary_field->list_values) ? unserialize($secondary_field->list_values) : null;
           echo $f->text_area_ap(array('name' => 'list_values', 'value' => $list_value, 'column_size' => '60',
            'rowsize' => '2', 'place_holder' => 'Enter comma(,) separated values'));
           ?> </td>
         </tr>
         <?php
         $count++;
        }
        ?>
       </tbody>
      </table>
     </div>
    </div>

   </div>
  </div> 
 </form>
</div>

<div id="js_data">
 <ul id="js_saving_data">
  <li class="primary_column_id" data-primary_column_id="obj_class_name" ></li>
  <li class="headerClassName" data-headerClassName="sys_secondary_field_inst" ></li>
  <li class="lineClassName" data-lineClassName="sys_secondary_field_inst" ></li>
  <li class="savingOnlyHeader" data-savingOnlyHeader="false" ></li>
  <li class="line_key_field" data-line_key_field="sys_secondary_field_id" ></li>
  <li class="single_line" data-single_line="false" ></li>
  <li class="before_save_function" data-before_save_function="beforeSave" ></li>
 </ul>
 <ul id="js_contextMenu_data">
  <li class="docLineId" data-docLineId="sys_secondary_field_inst_id" ></li>
  <li class="btn2DivId" data-btn2DivId="form_line" ></li>
  <li class="tbodyClass" data-tbodyClass="form_data_line_tbody" ></li>
  <li class="noOfTabbs" data-noOfTabbs="2" ></li>
 </ul>
</div>