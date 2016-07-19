<!-- * 
inoERP
 *
 * @copyright   2014 Nishit R. Das
 * @license     https://www.mozilla.org/MPL/2.0/
 * @link        http://inoideas.org
 * @source code https://github.com/inoerp/inoERP
-->

<div id ="form_header"><span class="heading"><?php echo gettext('Timesheet Entry') ?></span>
 <form method="post" id="hr_timesheet_header"  name="hr_timesheet_header">
  <div id="tabsHeader">
   <ul class="tabMain">
    <li><a href="#tabsHeader-1"><?php echo gettext('Basic Info') ?></a></li>
    <li><a href="#tabsHeader-2"><?php echo gettext('Approver') ?></a></li>
    <li><a href="#tabsHeader-3"><?php echo gettext('Notes') ?></a></li>
    <li><a href="#tabsHeader-4"><?php echo gettext('Attachments') ?></a></li>
    <li><a href="#tabsHeader-5"><?php echo gettext('Action') ?></a></li>
   </ul>
   <div class="tabContainer">
    <div id="tabsHeader-1" class="tabContent">
     <div class="large_shadow_box"> 
      <ul class="column header_field">
       <li><?php
        $f->l_text_field_dr_withSearch('hr_timesheet_header_id')
        ?>
        <a name="show" href="form.php?class_name=hr_timesheet_header&<?php echo "mode=$mode"; ?>" class="show document_id hr_timesheet_header_id">
         <i class="fa fa-refresh"></i></a> 
       </li>
       <li><?php $f->l_select_field_from_object('hr_timesheet_period_id', hr_timesheet_period::find_all(), 'hr_timesheet_period_id', 'timesheet_period', $$class->hr_timesheet_period_id, 'hr_timesheet_period_id', 'action'); ?>             </li>
       <li><?php
        echo $f->l_val_field_d('employee_name', 'hr_employee_v', 'employee_name', '', 'vf_select_employee_name employee_name');
        echo $f->hidden_field_withCLass('hr_employee_id', $$class->hr_employee_id, 'hr_employee_id claim_emplyee_id');
        ?><i class="generic g_select_employee_name select_popup clickable fa fa-search" data-class_name="hr_employee_v"></i></li>
       <li><?php $f->l_text_field_dr('identification_id'); ?>  </li>						 
       <li><?php $f->l_date_fieldAnyDay_m('entered_on', $$class->entered_on); ?>             </li>
       <li><?php $f->l_text_field_dr('status'); ?>             </li>
      </ul>
     </div>
    </div>
    <div id="tabsHeader-2" class="tabContent">
     <div> 
      <ul class="column header_field">
       <li><?php
        echo $f->l_val_field_d('approver_employee_name', 'hr_employee_v', 'employee_name', '', 'vf_select_employee_name employee_name');
        echo $f->hidden_field_withCLass('approver_employee_id', $$class->approver_employee_id, 'hr_employee_id');
        ?><i class="generic g_select_employee_name select_popup clickable fa fa-search" data-class_name="hr_employee_v"></i></li>
       <li><?php $f->l_date_fieldAnyDay_r('approved_date', $$class->approved_date, 'always_readonly'); ?>             </li>
      </ul>
     </div>
    </div>
    <div id="tabsHeader-3" class="tabContent">
     <div> 
      <div id="comments">
       <div id="comment_list">
        <?php echo!(empty($comments)) ? $comments : ""; ?>
       </div>
       <div id ="display_comment_form">
        <?php
        $reference_table = 'hr_timesheet_header';
        $reference_id = $$class->hr_timesheet_header_id;
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
    <div id="tabsHeader-5" class="tabContent">
     <ul class="column header_field">
      <li><label>Action</label>
       <?php
       echo $f->select_field_from_array('action', $$class->action_a, '', 'action', '', '', $readonly, $action_readonly)
       ?>
      </li>
     </ul>

    </div>

   </div>
  </div>
 </form>
</div>

<div id="form_line" class="form_line"><span class="heading"><?php echo gettext('Timesheet Lines') ?></span>
 <form method="post" id="hr_timesheet_line"  name="hr_timesheet_line">
  <div id="tabsLine">
   <ul class="tabMain">
    <li><a href="#tabsLine-1"><?php echo gettext('Project & Activities') ?></a></li>
    <li><a href="#tabsLine-2"><?php echo gettext('Comments') ?></a></li>
   </ul>
   <div class="tabContainer">
    <div id="tabsLine-1" class="tabContent">
     <table class="form_line_data_table">
      <thead> 
       <tr>
        <th><?php echo gettext('Action') ?></th>
        <th><?php echo gettext('Seq') ?> #</th>
        <th><?php echo gettext('Line Id') ?></th>
        <th><?php echo gettext('Project') ?> #</th>
        <th><?php echo gettext('Task') ?> #</th>
        <th><?php echo!empty($day1) ? gettext($day1) : gettext('Day 1') ?></th>
        <th><?php echo!empty($day2) ? gettext($day2) : gettext('Day 2') ?></th>
        <th><?php echo!empty($day3) ? gettext($day3) : gettext('Day 3') ?></th>
        <th><?php echo!empty($day4) ? gettext($day4) : gettext('Day 4') ?></th>
        <th><?php echo!empty($day5) ? gettext($day5) : gettext('Day 5') ?></th>
        <th><?php echo!empty($day6) ? gettext($day6) : gettext('Day 6') ?></th>
        <th><?php echo!empty($day7) ? gettext($day7) : gettext('Day 7') ?></th>

       </tr>
      </thead>
      <tbody class="form_data_line_tbody">
       <?php
       $count = 0;
       foreach ($hr_timesheet_line_object as $hr_timesheet_line) {
        if (!empty($_GET['copydoc']) && $_GET['copydoc'] == 1) {
         $hr_timesheet_line->hr_timesheet_line_id = null;
        }
        $$class_second->project_number = !empty($$class_second->prj_project_header_id) ? prj_project_header::find_by_id($$class_second->prj_project_header_id)->project_number : '';
        $$class_second->task_number = !empty($$class_second->prj_project_line_id) ? prj_project_line::find_by_id($$class_second->prj_project_line_id)->task_number : '';
        ?>         
        <tr class="hr_timesheet_line<?php echo $count ?>">
         <td>
          <?php
          echo ino_inline_action($$class_second->hr_timesheet_line_id, array('hr_timesheet_header_id' => $$class->hr_timesheet_header_id));
          ?>
         </td>
         <td><?php $f->seq_field_d($count); ?></td>
         <td><?php $f->text_field_wid2s('hr_timesheet_line_id', 'always_readonly dontCopy'); ?></td>
         <td><?php
          $f->val_field_wid2m('project_number', 'prj_project_header', 'project_number', '', 'select project_number');
          echo $f->hidden_field('prj_project_header_id', $$class_second->prj_project_header_id);
          ?><i class="generic select_project_number select_popup clickable fa fa-search" data-class_name="prj_project_header"></i></td>
         <td><?php
          $f->val_field_wid2('task_number', 'prj_project_all_v', 'task_number', 'prj_project_header_id', 'select project_task_number');
          echo $f->hidden_field('prj_project_line_id', $$class_second->prj_project_line_id);
          ?><i class="generic select_project_task_number select_popup clickable fa fa-search" data-class_name="prj_project_all_v"></i></td>
         <td><?php echo $f->number_field('day1', $$class_second->day1, '', '', 'small'); ?></td>
         <td><?php echo $f->number_field('day2', $$class_second->day2, '', '', 'small'); ?></td>
         <td><?php echo $f->number_field('day3', $$class_second->day3, '', '', 'small'); ?></td>
         <td><?php echo $f->number_field('day4', $$class_second->day4, '', '', 'small'); ?></td>
         <td><?php echo $f->number_field('day5', $$class_second->day5, '', '', 'small'); ?></td>
         <td><?php echo $f->number_field('day6', $$class_second->day6, '', '', 'small'); ?></td>
         <td><?php echo $f->number_field('day7', $$class_second->day7, '', '', 'small'); ?></td>
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
        <th><?php echo gettext('Seq') ?>#</th>
        <th><?php echo gettext('Work Type') ?></th>
        <th><?php echo gettext('Purpose') ?></th>
        <th><?php echo gettext('Description') ?></th>
        <th><?php echo gettext('Status') ?></th>
       </tr>
      </thead>
      <tbody class="form_data_line_tbody">
       <?php
       $count = 0;
       foreach ($hr_timesheet_line_object as $hr_timesheet_line) {
        ?>         
        <tr class="hr_timesheet_line<?php echo $count ?>">
         <td><?php $f->seq_field_d($count); ?></td>
         <td><?php echo $f->select_field_from_object('prj_work_type_id', prj_work_type::find_all(), 'prj_work_type_id', 'work_type', $$class_second->prj_work_type_id, 'prj_work_type_id'); ?></td>
         <td><?php $f->text_field_wid2('purpose'); ?></td>
         <td><?php $f->text_field_wid2l('description'); ?></td>
         <td><?php $f->text_field_wid2('status'); ?></td>
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
  <li class="headerClassName" data-headerClassName="hr_timesheet_header" ></li>
  <li class="lineClassName" data-lineClassName="hr_timesheet_line" ></li>
  <li class="savingOnlyHeader" data-savingOnlyHeader="false" ></li>
  <li class="primary_column_id" data-primary_column_id="hr_timesheet_header_id" ></li>
  <li class="form_header_id" data-form_header_id="hr_timesheet_header" ></li>
  <li class="line_key_field" data-line_key_field="line_number" ></li>
  <li class="single_line" data-single_line="true" ></li>
  <li class="form_line_id" data-form_line_id="hr_timesheet_line" ></li>
 </ul>
 <ul id="js_contextMenu_data">
  <li class="docHedaderId" data-docHedaderId="hr_timesheet_header_id" ></li>
  <li class="docLineId" data-docLineId="hr_timesheet_line_id" ></li>
  <li class="btn1DivId" data-btn1DivId="hr_timesheet_header" ></li>
  <li class="btn2DivId" data-btn2DivId="form_line" ></li>
  <li class="tbodyClass" data-tbodyClass="form_data_line_tbody" ></li>
  <li class="noOfTabbs" data-noOfTabbs="2" ></li>
  <li class="beforeCopy" data-beforeCopy="beforeCopyFun" ></li>
 </ul>
</div>