<div id ="form_header">
 <form action=""  method="post" id="cc_co_template_header"  name="cc_co_template_header"><span class="heading">Change Control Template </span>
  <div id="tabsHeader">
   <ul class="tabMain">
    <li><a href="#tabsHeader-1">Basic Info</a></li>
   </ul>
   <div class="tabContainer">
    <div id="tabsHeader-1" class="tabContent">
     <div class="large_shadow_box"> 
      <ul class="column header_field">
       <li><label><img src="<?php echo HOME_URL; ?>themes/images/serach.png" class="cc_co_template_header_id select_popup clickable">
         Header Id</label><?php $f->text_field_dsr('cc_co_template_header_id') ?>
        <a name="show" href="form.php?class_name=cc_co_template_header&<?php echo "mode=$mode"; ?>" class="show document_id cc_co_template_header_id"><img src="<?php echo HOME_URL; ?>themes/images/refresh.png"/></a> 
       </li>
       <li><label>Template Name</label><?php $f->text_field_d('template_name'); ?></li>
       <li><label>Inventory Org</label><?php echo $f->select_field_from_object('org_id', org::find_all_inventory(), 'org_id', 'org', $$class->org_id, 'org_id'); ?>       </li>
       <li><label>Status</label><?php echo form::status_field($$class->status, $readonly); ?></li>
       <li><label>Description</label><?php $f->text_field_dl('description'); ?></li>
      </ul>
     </div>
    </div>
   </div>
  </div>
 </form>
</div>

<div id="form_line" class="form_line"><span class="heading">Template Fields </span>
 <form action=""  method="post" id="cc_co_template_line"  name="cc_co_template_line">
  <div id="tabsLine">
   <ul class="tabMain">
    <li><a href="#tabsLine-1">Basic Info </a></li>
    <li><a href="#tabsLine-2">List Values </a></li>
   </ul>
   <div class="tabContainer">
    <div id="tabsLine-1" class="tabContent">
     <table class="form_line_data_table">
      <thead> 
       <tr>
        <th>Action</th>
        <th>Seq#</th>
        <th>Line Id</th>
        <th>Field Name</th>
        <th>Label</th>
        <th>Value Type</th>
        <th>Mandatory Field ?</th>
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
       foreach ($cc_co_template_line_object as $cc_co_template_line) {
        if (!empty($$class_second->limit_object)) {
         $appr_obj = hr_approval_object::find_by_keyColumn($$class_second->limit_object);
         $appr_obj_val = $appr_obj->object_value;
         $value_result = ($appr_obj->value_type == 'DYNAMIC') ? dbObject::find_by_sql_array($appr_obj_val) : null;
//                pa($value_result);
        }
        ?>         
        <tr class="cc_co_template_line<?php echo $count ?>">
         <td>    
          <ul class="inline_action">
           <li class="add_row_img clickable"><img  src="<?php echo HOME_URL; ?>themes/images/add.png"  alt="add new line" /></li>
           <li class="remove_row_img"><img src="<?php echo HOME_URL; ?>themes/images/remove.png" alt="remove this line" /> </li>
           <li><input type="checkbox" name="line_id_cb" value="<?php echo htmlentities($$class_second->cc_co_template_line_id); ?>"></li>           
           <li><?php echo form::hidden_field('cc_co_template_header_id', $cc_co_template_header->cc_co_template_header_id); ?></li>
          </ul>
         </td>
         <td><?php $f->seq_field_d($count) ?></td>
         <td><?php echo $f->text_field('cc_co_template_line_id', $$class_second->cc_co_template_line_id, '8'); ?></td>
         <td><?php
          if (!empty($$class_second->field_name) && !in_array($$class_second->field_name, get_dbColumns_valIndex('item'))) {
           echo $f->text_field('field_name', $$class_second->field_name, '20');
          } else {
           echo $f->select_field_from_array('field_name', get_dbColumns_valIndex('item'), $$class_second->field_name, '', 'medium', 1, '', '', 1);
          }
          ?> </td>
         <td><?php echo $f->text_field('label', $$class_second->label); ?></td>
         <td><?php echo $f->select_field_from_array('value_type', cc_co_template_line::$value_type_a, $$class_second->value_type); ?></td>
         <td><?php echo $f->checkBox_field('required_cb', $$class_second->required_cb); ?></td>
         <td><?php echo $f->select_field_from_array('control_type', dbObject::$control_type_a, $$class_second->control_type); ?></td>
         <td><?php echo $f->text_field('control_value', $$class_second->control_value); ?></td>
         <td><?php echo $f->select_field_from_object('control_uom', uom::find_all(), 'uom_id', 'uom_name', $$class_second->control_uom, '', 'uom_id small'); ?></td>
         <td><?php echo $f->select_field_from_array('display_weight', dbObject::$position_array, $$class_second->display_weight); ?></td>
         <td><?php echo $f->checkBox_field('active_cb', $$class_second->active_cb); ?></td>

        </tr>
        <?php
        $count = $count + 1;
       }
       ?>
      </tbody>
     </table>
    </div>
    <div id="tabsLine-2" class="tabContent">
     <table class="form_line_data_table">
      <thead> 
       <tr>
        <th>Seq#</th>
        <th>Lower Limit</th>
        <th>Upper Limit</th>
        <th>List Option Type</th>
        <th>List Values</th>
       </tr>
      </thead>
      <tbody class="form_data_line_tbody">
       <?php
       $count = 0;
       foreach ($cc_co_template_line_object as $cc_co_template_line) {
        if (!empty($$class_second->limit_object)) {
         $appr_obj = hr_approval_object::find_by_keyColumn($$class_second->limit_object);
         $appr_obj_val = $appr_obj->object_value;
         $value_result = ($appr_obj->value_type == 'DYNAMIC') ? dbObject::find_by_sql_array($appr_obj_val) : null;
        }
        ?>         
        <tr class="cc_co_template_line<?php echo $count; ?>">
         <td><?php $f->seq_field_d($count) ?></td>
         <td><?php echo $f->text_field('lower_limit', $$class_second->lower_limit); ?></td>
         <td><?php echo $f->text_field('upper_limit', $$class_second->upper_limit); ?></td>
         <td><?php echo $f->select_field_from_object('list_value_option_type', option_header::find_all(), 'option_header_id', 'option_type', $$class_second->list_value_option_type, '', 'medium'); ?></td>
         <td><?php
          $list_value = !empty($$class_second->list_values) ? unserialize($$class_second->list_values) : null;
          echo $f->text_area_ap(array('name' => 'list_values', 'value' => $list_value, 'column_size' => '60',
           'rowsize' => '2', 'place_holder' => 'Enter comma(,) separated values'));
          ?> </td>
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
  <li class="headerClassName" data-headerClassName="cc_co_template_header" ></li>
  <li class="lineClassName" data-lineClassName="cc_co_template_line" ></li>
  <li class="savingOnlyHeader" data-savingOnlyHeader="false" ></li>
  <li class="primary_column_id" data-primary_column_id="cc_co_template_header_id" ></li>
  <li class="form_header_id" data-form_header_id="cc_co_template_header" ></li>
  <li class="line_key_field" data-line_key_field="field_name" ></li>
  <li class="single_line" data-single_line="true" ></li>
  <li class="form_line_id" data-form_line_id="cc_co_template_line" ></li>
 </ul>
 <ul id="js_contextMenu_data">
  <li class="docHedaderId" data-docHedaderId="cc_co_template_header_id" ></li>
  <li class="docLineId" data-docLineId="cc_co_template_line_id" ></li>
  <li class="btn1DivId" data-btn1DivId="cc_co_template_header" ></li>
  <li class="btn2DivId" data-btn2DivId="form_line" ></li>
  <li class="trClass" data-docHedaderId="cc_co_template_line" ></li>
  <li class="tbodyClass" data-tbodyClass="form_data_line_tbody" ></li>
  <li class="noOfTabbs" data-noOfTabbs="2" ></li>
 </ul>
</div>