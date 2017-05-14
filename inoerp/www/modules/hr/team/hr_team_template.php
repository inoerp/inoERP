<div id ="form_header">
 <form   method="post" id="hr_team_header"  name="hr_team_header">
  <span class="heading"><?php echo gettext('HR Team') ?></span>
  <div id="tabsHeader">
   <ul class="tabMain">
    <li><a href="#tabsHeader-1"><?php echo gettext('Basic Info') ?></a></li>
    <li><a href="#tabsHeader-2"><?php echo gettext('Objective') ?></a></li>
    <li><a href="#tabsHeader-3"><?php echo gettext('Note') ?></a></li>
    <li><a href="#tabsHeader-4"><?php echo gettext('Attachments') ?></a></li>
   </ul>
   <div class="tabContainer">
    <div id="tabsHeader-1" class="tabContent">
     <ul class="column header_field">
      <li><?php $f->l_text_field_dr_withSearch('hr_team_header_id') ?>
       <a name="show" href="form.php?class_name=hr_team_header&<?php echo "mode=$mode"; ?>" class="show document_id hr_team_header_id">
        <i class="fa fa-refresh"></i></a> 
      </li>
      <li><?php $f->l_select_field_from_object('type', hr_team_header::team_type(), 'option_line_code', 'option_line_value', $$class->type, 'type'); ?> </li>
      <li><?php $f->l_text_field_d('team_name'); ?> </li>
      <li><?php
       echo $f->l_val_field_d('lead_employee_name', 'hr_employee_v', 'employee_name', '', 'vf_select_lead_employee_name employee_name');
       echo $f->hidden_field_withId('team_lead_employee_id', $$class->team_lead_employee_id);
       ?><i class="generic g_select_lead_employee_name select_popup clickable fa fa-search" data-class_name="hr_employee_v"></i></li>
      <li><?php $f->l_select_field_from_object('region', hr_team_header::team_region(), 'option_line_code', 'option_line_value', $$class->region, 'region'); ?> </li>
      <li><?php $f->l_text_field_d('email'); ?> </li>
      <li><?php $f->l_status_field_d('status'); ?> </li>
      <li><?php $f->l_date_fieldAnyDay('start_date', $$class->end_date); ?></li>
      <li><?php $f->l_date_fieldFromToday('end_date', $$class->end_date); ?></li>
     </ul>
    </div>
    <div id="tabsHeader-2" class="tabContent">
     <div><?php
      echo $f->text_area_ap(array('name' => 'objective', 'value' => $$class->objective,
       'row_size' => '10', 'column_size' => '90'));
      ?></div>
    </div>
    <div id="tabsHeader-3" class="tabContent">
     <div> 
      <div id="comments">
       <div id="comment_list">
        <?php echo!(empty($comments)) ? $comments : ""; ?>
       </div>
       <div id ="display_comment_form">
        <?php
        $reference_table = 'hr_team_header';
        $reference_id = $$class->hr_team_header_id;
        ?>
       </div>
       <div id="new_comment">
       </div>
      </div>
     </div>
    </div>
    <div id="tabsHeader-4" class="tabContent">
     <div> <?php echo ino_attachement($file) ?> </div>
    </div>
   </div>
  </div>
 </form>
</div>

<div id="form_line" class="form_line"><span class="heading"><?php echo gettext('Team Members') ?></span>
 <form method="post" id="hr_team_line"  name="hr_team_line">
  <div id="tabsLine">
   <ul class="tabMain">
    <li><a href="#tabsLine-1"><?php echo gettext('Main') ?></a></li>
   </ul>
   <div class="tabContainer">
    <div id="tabsLine-1" class="tabContent">
     <table class="form_line_data_table">
      <thead> 
       <tr>
        <th><?php echo gettext('Action') ?></th>
        <th><?php echo gettext('Line Id') ?>#</th>
        <th><?php echo gettext('Member Name') ?></th>
        <th><?php echo gettext('Region') ?>#</th>
        <th><?php echo gettext('Role') ?></th>
        <th><?php echo gettext('Responsibility') ?></th>
        <th><?php echo gettext('Start Date') ?></th>
        <th><?php echo gettext('End Date') ?></th>
        <th><?php echo gettext('Objective') ?></th>
       </tr>
      </thead>
      <tbody class="form_data_line_tbody">
       <?php
       $count = 0;
       foreach ($hr_team_line_object as $hr_team_line) {
        if (!empty($hr_team_line->member_employee_id)) {
         $emp_details_l = hr_employee::find_by_id($hr_team_line->member_employee_id);
         $hr_team_line->member_employee_name = $emp_details_l->first_name . ' ' . $emp_details_l->last_name;
        }
        ?>         
        <tr class="hr_team_line<?php echo $count ?>">
         <td><?php
          echo ino_inline_action($$class_second->hr_team_line_id, array('option_line_code' => $hr_team_header->hr_team_header_id));
          ?>
         </td>
         <td><?php $f->text_field_wid2sr('hr_team_line_id'); ?></td>
         <td><?php
          echo $f->val_field('member_employee_name', $$class_second->member_employee_name, '', '', 'vf_select_member_employee_name employee_name', '', '', 'hr_employee_v', 'employee_name');
          echo $f->hidden_field_withCLass('member_employee_id', $$class_second->member_employee_id, 'employee_id');
          ?><i class="generic g_select_employee_name select_popup clickable fa fa-search" data-class_name="hr_employee_v"></i></td>
         <td><?php echo $f->select_field_from_object('region', sys_value_group_line::find_by_parent_id($team_reg_vg_id), 'sys_value_group_line_id', 'code_value', $$class_second->region); ?></td>
         <td><?php echo $f->select_field_from_object('role', hr_team_header::hr_role(), 'option_line_code', 'option_line_value', $$class_second->role); ?></td>
         <td><?php echo $f->select_field_from_array('responsibility', hr_team_line::$responsibility_a, $$class_second->responsibility); ?></td>
         <td><?php echo $f->date_fieldFromToday('start_date', $$class_second->start_date); ?></td>
         <td><?php echo $f->date_fieldFromToday('end_date', $$class_second->end_date); ?></td>
         <td><?php $f->text_field_wid2l('objective'); ?></td>
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
  <li class="headerClassName" data-headerClassName="hr_team_header" ></li>
  <li class="lineClassName" data-lineClassName="hr_team_line" ></li>
  <li class="savingOnlyHeader" data-savingOnlyHeader="false" ></li>
  <li class="primary_column_id" data-primary_column_id="hr_team_header_id" ></li>
  <li class="form_header_id" data-form_header_id="hr_team_header" ></li>
  <li class="line_key_field" data-line_key_field="position_id" ></li>
  <li class="single_line" data-single_line="true" ></li>
  <li class="form_line_id" data-form_line_id="hr_team_line" ></li>
 </ul>
 <ul id="js_contextMenu_data">
  <li class="docHedaderId" data-docHedaderId="hr_team_header_id" ></li>
  <li class="btn1DivId" data-btn1DivId="hr_team_header" ></li>
  <li class="btn2DivId" data-btn2DivId="form_line" ></li>
 </ul>
</div>