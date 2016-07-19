<!-- * 
inoERP
 *
 * @copyright   2014 Nishit R. Das
 * @license     https://www.mozilla.org/MPL/2.0/
 * @link        http://inoideas.org
 * @source code https://github.com/inoerp/inoERP
-->

<div id ="form_header"><span class="heading"><?php echo gettext('Project Expenditure') ?></span>
 <form action=""  method="post" id="prj_expenditure_header"  name="prj_expenditure_header">
  <div id="tabsHeader">
   <ul class="tabMain">
    <li><a href="#tabsHeader-1"><?php echo gettext('Basic Info') ?></a></li>
    <li><a href="#tabsHeader-2"><?php echo gettext('References') ?></a></li>
    <li><a href="#tabsHeader-3"><?php echo gettext('Note') ?></a></li>
    <li><a href="#tabsHeader-4"><?php echo gettext('Attachments') ?></a></li>
    <li><a href="#tabsHeader-5"><?php echo gettext('Actions') ?></a></li>
   </ul>
   <div class="tabContainer">
    <div id="tabsHeader-1" class="tabContent">
     <ul class="column header_field">
      <li><?php $f->l_text_field_dr_withSearch('prj_expenditure_header_id') ?>
       <a name="show" href="form.php?class_name=prj_expenditure_header&<?php echo "mode=$mode"; ?>" class="show document_id prj_expenditure_header_id"><i class="fa fa-refresh"></i></a> 
      </li>
      <li><?php $f->l_select_field_from_object('bu_org_id', org::find_all_business(), 'org_id', 'org', $$class->bu_org_id, 'bu_org_id', '', 1, $readonly1); ?>        </li>
      <li><?php $f->l_text_field_d('batch_name'); ?></li>
      <li><?php $f->l_select_field_from_array('expenditure_class', prj_expenditure_header::$expenditure_class_a, $$class->expenditure_class, 'expenditure_class', '', 1,$readonly1); ?>    </li>
      <li><?php $f->l_text_field_d('description'); ?></li>
      <li><?php $f->l_date_fieldAnyDay('effective_to', $$class->effective_to); ?></li>
      <li><?php $f->l_text_field_dr('status'); ?></li>
     </ul>
    </div>
    <div id="tabsHeader-2" class="tabContent">
     <ul class="column header_field">
      <li><?php $f->l_text_field_dr('reference_type'); ?></li>
      <li><?php $f->l_text_field_dr('reference_key_name'); ?></li>
      <li><?php $f->l_text_field_dr('reference_key_value'); ?></li>
      <li><?php $f->l_text_field_dr('submitted_by_user_id'); ?></li>
      <li><?php $f->l_text_field_dr('submitted_on'); ?></li>
     </ul>
    </div>
    <div id="tabsHeader-3" class="tabContent">
     <div> 
      <div id="comments">
       <div id="comment_list">
        <?php echo!(empty($comments)) ? $comments : ""; ?>
       </div>
       <div id ="display_comment_form">
        <?php
        $reference_table = 'prj_expenditure_header';
        $reference_id = $$class->prj_expenditure_header_id;
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
      <li id="document_status"><label><?php echo gettext('Action') ?></label>
       <?php echo $f->select_field_from_array('action', $$class->action_a, '', 'action'); ?>
      </li>
     </ul>
    </div>
   </div>
  </div>
 </form>
</div>

<div id="form_line" class="form_line"><span class="heading"><?php echo gettext('Expenditure Lines') ?></span>
 <form action=""  method="post" id="prj_expenditure_line"  name="prj_expenditure_line">
  <div id="tabsLine">
   <ul class="tabMain">
    <li><a href="#tabsLine-1"><?php echo gettext('Basic') ?></a></li>
    <li><a href="#tabsLine-2"><?php echo gettext('Finance') ?></a></li>
    <li><a href="#tabsLine-3"><?php echo gettext('Finance-2') ?></a></li>
   </ul>
   <div class="tabContainer">
    <div id="tabsLine-1" class="tabContent">
     <table class="form_line_data_table">
      <thead> 
       <tr>
        <th><?php echo gettext('Action') ?></th>
        <th><?php echo gettext('Line Id') ?></th>
        <th><?php echo gettext('Type') ?></th>
        <th><?php echo gettext('Org') ?></th>
        <th><?php echo gettext('Employee') ?></th>
        <th><?php echo gettext('Job') ?></th>
        <th><?php echo gettext('Description') ?></th>
        <th><?php echo gettext('Date') ?></th>
        <th><?php echo gettext('Project') ?></th>
        <th><?php echo gettext('Task') ?></th>
        <th><?php echo gettext('UOM') ?></th>
        <th><?php echo gettext('Quantity') ?></th>
        <th><?php echo gettext('Rate') ?></th>
       </tr>
      </thead>
      <tbody class="form_data_line_tbody">
       <?php
       $count = 0;
       foreach ($prj_expenditure_line_object as $prj_expenditure_line) {
        $$class_second->employee_name = !empty($$class_second->hr_employee_id) ? hr_employee_v::find_by_id($$class_second->hr_employee_id)->employee_name : '';
        $$class_second->project_number = !empty($$class_second->prj_project_header_id) ? prj_project_header::find_by_id($$class_second->prj_project_header_id)->project_number : '';
        $$class_second->task_number = !empty($$class_second->prj_project_line_id) ? prj_project_line::find_by_id($$class_second->prj_project_line_id)->task_number : '';
        ?>         
        <tr class="prj_expenditure_line<?php echo $count ?>">
         <td>
          <?php
          echo ino_inline_action($prj_expenditure_line->prj_expenditure_line_id, array('prj_expenditure_header_id' => $prj_expenditure_header->prj_expenditure_header_id));
          ?>
         </td>
         <td><?php $f->text_field_d2sr('prj_expenditure_line_id' ,'line_id always_readonly'); ?></td>
         <td><?php echo $f->select_field_from_object('prj_expenditure_type_header_id', prj_expenditure_type_header::find_all(), 'prj_expenditure_type_header_id', 'expenditure_type', $$class_second->prj_expenditure_type_header_id , '' , '' , 1); ?>						 </td>
         <td><?php echo $f->select_field_from_object('org_id', org::find_all(), 'org_id', 'org', $$class_second->org_id); ?>						 </td>
         <td><?php
          $f->val_field_wid2('employee_name', 'hr_employee_v', 'employee_name', '' ,'select employee resource_type_control');
          echo $f->hidden_field_withCLass('hr_employee_id', $$class_second->hr_employee_id, 'resource_type_control employee hr_employee_id');
          ?><i class="select_employee_name select_popup clickable fa fa-search"></i></td>
         <td><?php echo $f->select_field_from_object('job_id', hr_job::find_all(), 'hr_job_id', 'job_name', $$class_second->job_id); ?></td>
         <td><?php $f->text_field_d2('description'); ?></td>
         <td><?php echo $f->date_fieldAnyDay('expenditure_date', $$class_second->expenditure_date); ?></td>
         <td><?php 
          $f->val_field_wid2m('project_number', 'prj_project_header', 'project_number', '', 'select project_number');
          echo $f->hidden_field_withCLass('prj_project_header_id', $$class_second->prj_project_header_id ,'popup_value');
          echo $f->hidden_field_withCLass('approval_status', 'APPROVED', 'popup_value');
          ?><i class="generic select_project_number select_popup clickable fa fa-search" data-class_name="prj_project_header"></i></td>
         <td><?php
          $f->val_field_wid2m('task_number', 'prj_project_all_lowesttask_v', 'task_number', 'prj_project_header_id', 'select project_task_number');
          echo $f->hidden_field('prj_project_line_id', $$class_second->prj_project_line_id);
          echo $f->hidden_field_withCLass('approval_status', 'APPROVED', 'popup_value');
          ?><i class="generic select_project_task_number select_popup clickable fa fa-search" data-class_name="prj_project_all_lowesttask_v"></i></td>
         <td><?php echo $f->select_field_from_object('uom_id', uom::find_all(), 'uom_id', 'uom_name', $$class_second->uom_id, '', 'small' , 1); ?></td>
         <td><?php $f->text_field_wid2s('quantity'); ?></td>
         <td><?php $f->text_field_wid2s('rate'); ?></td>
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
        <th><?php echo gettext('Line Id') ?></th>
        <th><?php echo gettext('Line Amount') ?></th>
        <th><?php echo gettext('Status') ?></th>
        <th><?php echo gettext('Debit Account') ?></th>
        <th><?php echo gettext('Credit Account') ?></th>
        <th><?php echo gettext('Burden Amount') ?></th>
        <th><?php echo gettext('Burden Details') ?></th>
       </tr>
      </thead>
      <tbody class="form_data_line_tbody">
       <?php
       $count = 0; 
       foreach ($prj_expenditure_line_object as $prj_expenditure_line) {
        ?>         
        <tr class="prj_expenditure_line<?php echo $count ?>">
         <td><?php echo $$class_second->prj_expenditure_line_id ?></td>
         <td><?php $f->text_field_wid2sr('line_amount'); ?></td>
         <td><?php echo $f->select_field_from_array('status2', prj_expenditure_line::$status_a, $$class_second->status, '', 'medium', '', 1, 1); ?>						 </td>
         <td><?php $f->ac_field_wid2('debit_ac_id'); ?></td>
         <td><?php $f->ac_field_wid2('credit_ac_id'); ?></td>
         <td><?php $f->text_field_wid2r('burden_amount'); ?></td>
         <td><a role="button" target="_blank" class="btn btn-sm btn-default dont_copy" href="search.php?class_name=prj_burden_expenditure_v&amp;show_block=1&amp;prj_expenditure_line_id=<?php echo $$class_second->prj_expenditure_line_id; ?>"><?php echo gettext('View') ?></a></td>
        </tr>
        <?php
        $count = $count + 1;
       }
       ?>
      </tbody>
     </table>
    </div>
    <div id="tabsLine-3" class="tabContent">
     <table class="form_line_data_table">
      <thead> 
       <tr>
        <th><?php echo gettext('Line Id') ?></th>
        <th><?php echo gettext('Journal Header Id') ?></th>
        <th><?php echo gettext('Journal Interface Id') ?></th>
        <th><?php echo gettext('Revene Calculated') ?></th>
        <th><?php echo gettext('Invoiced') ?></th>
       </tr>
      </thead>
      <tbody class="form_data_line_tbody">
       <?php
       $count = 0; 
       foreach ($prj_expenditure_line_object as $prj_expenditure_line) {
        ?>         
        <tr class="prj_expenditure_line<?php echo $count ?>">
         <td><?php echo $$class_second->prj_expenditure_line_id ?></td>
         <td><?php $f->text_field_wid2r('gl_journal_header_id'); ?></td>
         <td><?php echo $f->checkBox_field('gl_journal_interface_cb', $$class_second->gl_journal_interface_cb, '' ,'always_readonly' , 1); ?></td>
         <td><?php echo $f->checkBox_field('revene_calculated_cb', $$class_second->revene_calculated_cb, '' ,'always_readonly' , 1); ?></td>
         <td><?php echo $f->checkBox_field('invoiced_cb', $$class_second->invoiced_cb, '' ,'always_readonly' , 1); ?></td>
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
  <li class="headerClassName" data-headerClassName="prj_expenditure_header" ></li>
  <li class="lineClassName" data-lineClassName="prj_expenditure_line" ></li>
  <li class="savingOnlyHeader" data-savingOnlyHeader="false" ></li>
  <li class="primary_column_id" data-primary_column_id="prj_expenditure_header_id" ></li>
  <li class="form_header_id" data-form_header_id="prj_expenditure_header" ></li>
  <li class="line_key_field" data-line_key_field="line_name" ></li>
  <li class="single_line" data-single_line="false" ></li>
  <li class="form_line_id" data-form_line_id="prj_expenditure_line" ></li>
 </ul>
 <ul id="js_contextMenu_data">
  <li class="docHedaderId" data-docHedaderId="prj_expenditure_header_id" ></li>
  <li class="docLineId" data-docLineId="prj_expenditure_line_id" ></li>
  <li class="btn1DivId" data-btn1DivId="prj_expenditure_header" ></li>
  <li class="btn2DivId" data-btn2DivId="form_line" ></li>
  <li class="tbodyClass" data-tbodyClass="form_data_line_tbody" ></li>
  <li class="noOfTabbs" data-noOfTabbs="2" ></li>
 </ul>
</div>