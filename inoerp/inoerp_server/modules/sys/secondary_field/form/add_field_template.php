<div id="all_contents">
 <div id="content_left"></div>
 <div id="content_right">
  <div id="content_right_left">
   <div id="content_top"></div>
   <div id="content">
    <div id="structure">
     <div id="secondary_fieldId">
      <!--    START OF FORM HEADER-->
      <div id ="form_header">
       <div class="error"></div><div id="loading"></div>
       <div class="show_loading_small"></div>
       <?php echo (!empty($show_message)) ? $show_message : ""; ?> 
       <!--    End of place for showing error messages-->
       <span class="heading"><?php echo gettext('Object/Class Details') ?> </span>
       <div class="large_shadow_box">
        <ul class="column four_column">
         <li>
          <label> <?php echo gettext('Object Name') ?> : </label>
          <?php echo $f->select_field_from_object('obj_class_name', engine::find_all(), 'obj_class_name', 'obj_class_name', $obj_class_name_h); ?>
          <a name="show" href="form.php?class_name=secondary_field&role_code=" class="show role_code">
           <img src="<?php echo HOME_URL; ?>themes/images/refresh.png"/></a> 
         </li>						
         <li><label><?php echo gettext('Description') ?> : </label>
          <?php echo $f->text_field('description', '', '50'); ?>
         </li>
        </ul>
       </div>
      </div>
      <form action=""  method="post" id="secondary_field"  name="secondary_field">
       <!--END OF FORM HEADER-->
       <div id ="form_line" class="secondary_field"><span class="heading"><?php echo gettext('Secondary Details') ?> </span>
        <div id="tabsLine">
         <ul class="tabMain">
          <li><a href="#tabsLine-1"><?php echo gettext('Basic Info') ?> </a></li>
          <li><a href="#tabsLine-2"><?php echo gettext('List Values') ?> </a></li>
         </ul>
         <div class="tabContainer"> 
          <div id="tabsLine-1" class="tabContent">
           <table class="form form_detail_data_table detail">
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
            <tbody class="form_data_detail_tbody_ln">
             <?php
              $detailCount = 0;
              if (!empty($ef_refer_value_i)) {
               $secondary_field_object = [];
               $secondary_field_object = sys_secondary_field_inst::find_by_referenceKeyValue($ef_refer_key, $ef_refer_value_i);
              }
              if (empty($secondary_field_object)) {
               $secondary_field_object = array(new sys_secondary_field_inst());
              }
              foreach ($secondary_field_object as $secondary_field) {
               ?>
               <tr class="sys_secondary_field<?php echo $count . '-' . $detailCount; ?>">
                <td>   
                 <ul class="inline_action">
                  <li class="add_row_detail_img3"><img  src="<?php echo HOME_URL; ?>themes/images/add.png"  alt="<?php echo gettext('add new line') ?>" /></li>
                  <li class="remove_row_img"><img src="<?php echo HOME_URL; ?>themes/images/remove.png" alt="<?php echo gettext('remove this line') ?>" /> </li>
                  <li><input type="checkbox" name="detail_id_cb" value="<?php echo htmlentities($secondary_field->sys_secondary_field_inst_id); ?>">
                  </li>           
                 </ul>
                </td>
                <td><?php $f->seq_field_detail_d($detailCount) ?></td>
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
               $detailCount++;
              }
             ?>
            </tbody>
           </table>
          </div>
          <div id="tabsLine-2" class="tabContent">
           <table class="form form_detail_data_table detail">
            <thead>
             <tr>
              <th><?php echo gettext('Seq') ?>#</th>
              <th><?php echo gettext('Lower Limit') ?></th>
              <th><?php echo gettext('Upper Limit') ?></th>
              <th><?php echo gettext('List Option Type') ?></th>
              <th><?php echo gettext('Field Name') ?></th>
             </tr>
            </thead>
            <tbody class="form_data_detail_tbody_ln">
             <?php
              $detailCount = 0;
              foreach ($secondary_field_object as $secondary_field) {
               ?>
               <tr class="sys_secondary_field<?php echo $count . '-' . $detailCount; ?>">
                <td><?php $f->seq_field_detail_d($detailCount) ?></td>
                <td><?php echo $f->text_field('lower_limit', $secondary_field->lower_limit); ?></td>
                <td><?php echo $f->text_field('upper_limit', $secondary_field->upper_limit); ?></td>
                <td><?php echo $f->select_field_from_object('list_value_option_type', option_header::find_all(), 'option_header_id', 'option_type', $secondary_field->list_value_option_type, '', 'medium'); ?></td>
                <td><?php
                 $list_value = !empty($secondary_field->list_values) ? implode(',', unserialize($secondary_field->list_values)) : null;
                 echo $f->text_area_ap(array('name' => 'list_values', 'value' => $list_value, 'column_size' => '60',
                  'rowsize' => '2', 'place_holder' => 'Enter comma(,) separated values'));
                 ?> </td>
               </tr>
               <?php
               $detailCount++;
              }
             ?>
            </tbody>
           </table>
          </div>
         </div>

        </div>
       </div> 
      </form>
      <div id="pagination" style="clear: both;">
       <?php echo!(empty($pagination_statement)) ? $pagination_statement : "";
       ?>
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
