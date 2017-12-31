<div id ="form_header">
 <form method="post" id="hr_leave_entitlement_header"  name="hr_leave_entitlement_header">
  <span class="heading"><?php echo gettext('Leave Entitlement') ?></span>
  <div id="tabsHeader">
   <ul class="tabMain">
    <li><a href="#tabsHeader-1"><?php echo gettext('Basic Info') ?></a></li>
    <li><a href="#tabsHeader-2"><?php echo gettext('Criteria') ?></a></li>
   </ul>
   <div class="tabContainer">
    <div id="tabsHeader-1" class="tabContent">
     <div class="large_shadow_box"> 
      <ul class="column header_field">
       <li><?php $f->l_text_field_dr_withSearch('hr_leave_entitlement_header_id') ?>
        <a name="show" href="form.php?class_name=hr_leave_entitlement_header&<?php echo "mode=$mode"; ?>" 
           class="show document_id hr_leave_entitlement_header_id"><i class="fa fa-refresh"></i></a> 
       </li>
       <li><?php $f->l_text_field_d('entitlement_name'); ?></li>
       <li><?php echo $f->l_status_field_d('status'); ?></li>
       <li><?php $f->l_text_field_d('description'); ?></li>
      </ul>
     </div>
    </div>
    <div id="tabsHeader-2" class="tabContent">
     <div class="large_shadow_box"> 
      <ul class="column header_field">
       <li><?php $f->l_select_field_from_object('job_id', hr_job::find_all(), 'hr_job_id', 'job_name', $$class->job_id, 'job_id'); ?> 					</li>
       <li><?php $f->l_select_field_from_object('position_id', hr_position::find_all(), 'hr_position_id', 'position_name', $$class->position_id, 'position_id'); ?>  </li>
       <li><?php $f->l_text_field_d('leave_group'); ?></li>
       <li><?php $f->l_text_field_d('employee_id'); ?></li>
      </ul>
     </div>
    </div>
   </div>
  </div>
 </form>
</div>

<div id="form_line" class="form_line"><span class="heading"><?php echo gettext('Entitlement Details') ?></span>
 <form  method="post" id="hr_leave_entitlement_line"  name="hr_leave_entitlement_line">
  <div id="tabsLine">
   <ul class="tabMain">
    <li><a href="#tabsLine-1"><?php echo gettext('Main') ?></a></li>
   </ul>
   <div class="tabContainer">
    <div id="tabsLine-1" class="tabContent">
     <table class="form_table">
      <thead> 
       <tr>
        <th><?php echo gettext('Action') ?></th>
        <th><?php echo gettext('Line Id') ?></th>
        <th><?php echo gettext('Type') ?>#</th>
        <th><?php echo gettext('Period') ?></th>
        <th><?php echo gettext('Leave/Period') ?></th>
        <th><?php echo gettext('Default No Of Period') ?></th>
       </tr>
      </thead>
      <tbody class="form_data_line_tbody leave_entitlement_values" >
       <?php
       $count = 0;
       foreach ($hr_leave_entitlement_line_object as $hr_leave_entitlement_line) {
        ?>         
        <tr class="hr_leave_entitlement_line<?php echo $count ?>">
         <td><?php
          echo ino_inline_action($$class_second->hr_leave_entitlement_line_id, array('hr_leave_entitlement_header_id' => $$class->hr_leave_entitlement_header_id));
          ?>       
         </td>
         <td><?php $f->text_field_wid2sr('hr_leave_entitlement_line_id') ?></td>
         <td><?php echo $f->select_field_from_object('leave_type', hr_leave_type::find_all(), 'hr_leave_type_id', 'leave_type', $$class_second->leave_type, '', 'leave_type', 1, $readonly); ?></td>
         <td><?php echo $f->select_field_from_object('period', option_header::period_types(), 'option_line_code', 'option_line_value', $$class_second->period, '', 'period', 1, $readonly); ?></td>
         <td><?php echo $f->number_field('leave_per_period', $$class_second->leave_per_period); ?></td>
         <td><?php echo $f->number_field('default_no_of_period', $$class_second->default_no_of_period); ?></td>

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
  <li class="headerClassName" data-headerClassName="hr_leave_entitlement_header" ></li>
  <li class="lineClassName" data-lineClassName="hr_leave_entitlement_line" ></li>
  <li class="savingOnlyHeader" data-savingOnlyHeader="false" ></li>
  <li class="primary_column_id" data-primary_column_id="hr_leave_entitlement_header_id" ></li>
  <li class="form_header_id" data-form_header_id="hr_leave_entitlement_header" ></li>
  <li class="line_key_field" data-line_key_field="position_id" ></li>
  <li class="single_line" data-single_line="true" ></li>
  <li class="form_line_id" data-form_line_id="hr_leave_entitlement_line" ></li>
 </ul>
 <ul id="js_contextMenu_data">
  <li class="docHedaderId" data-docHedaderId="hr_leave_entitlement_header_id" ></li>
  <li class="btn1DivId" data-btn1DivId="hr_leave_entitlement_header" ></li>
  <li class="btn2DivId" data-btn2DivId="form_line" ></li>
 </ul>
</div>
