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
       <?php echo (!empty($show_message)) ? $show_message : ""; $f = new inoform(); ?> 
       <!--    End of place for showing error messages-->
       <span class="heading">Secondary Field for Objects </span>
       <div class="large_shadow_box">
        <ul class="column two_column">
         <li>
          <label> Object Name : </label>
          <?php echo $f->select_field_from_object('obj_class_name', view::find_all_tables(), 'TABLE_NAME', 'TABLE_NAME', $obj_class_name_h,'obj_class_name'); ?>
          <a name="show" href="form.php?class_name=secondary_field&obj_class_name=" class="show obj_class_name">
           <img src="<?php echo HOME_URL; ?>themes/images/refresh.png"/></a> 
         </li>						
        </ul>
       </div>
      </div>
      <form action=""  method="post" id="secondary_field"  name="secondary_field">
       <!--END OF FORM HEADER-->
       <div id ="form_line" class="secondary_field"><span class="heading">Field Details </span>
        <div id="tabsLine">
         <ul class="tabMain">
          <li><a href="#tabsLine-1">Basic Info </a></li>
          <li><a href="#tabsLine-2">List Values </a></li>
         </ul>
         <div class="tabContainer"> 
          <div id="tabsLine-1" class="tabContent">
           <table class="form form_line_data_table line">
            <thead>
             <tr>
              <th>Action</th>
              <th>Seq#</th>
              <th>Instance Id</th>
              <th>Field Name</th>
              <th>Label</th>
              <th>Type</th>
              <th>Control Type</th>
              <th>Control Value</th>
              <th>Control UOM</th>
              <th>Display Weight</th>
              <th>Active</th>
             </tr>
            </thead>
            <tbody class="form_data_line_tbody">
             <?php
              $count = 0;
              foreach ($secondary_field_object as $secondary_field) {
               ?>
               <tr class="sys_secondary_field<?php echo $count; ?>">
                <td>   
                 <ul class="inline_action">
                  <li class="add_row_img clickable"><img  src="<?php echo HOME_URL; ?>themes/images/add.png"  alt="add new line" /></li>
                  <li class="remove_row_img"><img src="<?php echo HOME_URL; ?>themes/images/remove.png" alt="remove this line" /> </li>
                  <li><input type="checkbox" name="line_id_cb" value="<?php echo ($secondary_field->sys_secondary_field_instance_id); ?>">
                     <?php echo form::hidden_field('reference_key_name', $obj_class_name_h); ?>
                  </li>           
                 </ul>
                </td>
                <td><?php $f->seq_field_d($count) ?></td>
                <td><?php echo $f->text_field('sys_secondary_field_instance_id', $secondary_field->sys_secondary_field_instance_id, '8', '', '', '', 1); ?></td>
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
              <th>Seq#</th>
              <th>Lower Limit</th>
              <th>Upper Limit</th>
              <th>List Option Type</th>
              <th>Field Name</th>
             </tr>
            </thead>
            <tbody class="form_data_line_tbody">
             <?php
              $count = 0;
              foreach ($secondary_field_object as $secondary_field) {
               ?>
               <tr class="sys_secondary_field<?php echo $count; ?>">
                <td><?php $f->seq_field_d($count) ?></td>
                <td><?php echo $f->text_field('lower_limit', $secondary_field->lower_limit); ?></td>
                <td><?php echo $f->text_field('upper_limit', $secondary_field->upper_limit); ?></td>
                <td><?php echo $f->select_field_from_object('list_value_option_type', option_header::find_all(), 'option_header_id', 'option_type', $secondary_field->list_value_option_type, '', 'medium'); ?></td>
                <td><?php
                 $list_value = !empty($secondary_field->list_values) ?  unserialize($secondary_field->list_values) : null;
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
    </div>
    <!--   end of structure-->
   </div>
   <div id="content_bottom"></div>
  </div>
  <div id="content_right_right"></div>
 </div>

</div>

<div id="js_data">
 <ul id="js_saving_data">
  <li class="headerClassName" data-headerClassName="sys_secondary_field_instance" ></li>
  <li class="lineClassName" data-lineClassName="sys_secondary_field_instance" ></li>
  <li class="savingOnlyHeader" data-savingOnlyHeader="false" ></li>
  <li class="line_key_field" data-line_key_field="sys_secondary_field_id" ></li>
  <li class="single_line" data-single_line="false" ></li>
  <li class="before_save_function" data-before_save_function="beforeSave" ></li>
 </ul>
 <ul id="js_contextMenu_data">
  <li class="docLineId" data-docLineId="sys_secondary_field_instance_id" ></li>
  <li class="btn2DivId" data-btn2DivId="form_line" ></li>
  <li class="tbodyClass" data-tbodyClass="form_data_line_tbody" ></li>
  <li class="noOfTabbs" data-noOfTabbs="2" ></li>
 </ul>
</div>

<?php include_template('footer.inc') ?>