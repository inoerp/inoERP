<!-- * 
inoERP
 *
 * @copyright   2014 Nishit R. Das
 * @license     https://www.mozilla.org/MPL/2.0/
 * @link        http://inoideas.org
 * @source code https://github.com/inoerp/inoERP
-->
<div id ="form_header"><span class="heading"><?php
  echo gettext('Project & Templates')
  ?></span>
 <form method="post" id="prj_project_header"  name="prj_project_header">
  <div id="tabsHeader">
   <ul class="tabMain">
    <li><a href="#tabsHeader-1"><?php echo gettext('Basic Info') ?></a></li>
    <li><a href="#tabsHeader-2"><?php echo gettext('Basic - 2') ?></a></li>
    <li><a href="#tabsHeader-3"><?php echo gettext('Finance') ?></a></li>
    <li><a href="#tabsHeader-4"><?php echo gettext('References') ?></a></li>
    <li><a href="#tabsHeader-5"><?php echo gettext('Note') ?></a></li>
    <li><a href="#tabsHeader-6"><?php echo gettext('Attachments') ?></a></li>
    <li><a href="#tabsHeader-7"><?php echo gettext('Actions') ?></a></li>
   </ul>
   <div class="tabContainer">
    <div id="tabsHeader-1" class="tabContent">
     <ul class="column header_field">
      <li><?php $f->l_text_field_dr_withSearch('prj_project_header_id') ?>
       <a name="show" href="form.php?class_name=prj_project_header&<?php echo "mode=$mode"; ?>" class="show document_id prj_project_header_id"><i class="fa fa-refresh"></i></a> 
      </li>
      <li><?php $f->l_text_field_d('project_number', 'primary_column2'); ?></li>
      <li><?php $f->l_text_field_d('name'); ?></li>
      <li><?php $f->l_select_field_from_object('bu_org_id', org::find_all_business(), 'org_id', 'org', $$class->bu_org_id, 'bu_org_id', $readonly1, '', ''); ?>						 </li>
      <li><?php $f->l_select_field_from_object('prj_project_type_id', prj_project_type_header::find_all(), 'prj_project_type_header_id', 'project_type', $$class->prj_project_type_id, 'prj_project_type_header_id', 'medium', 1, $readonly1); ?>						 </li>
      <li><label class="auto_complete"><?php echo gettext('Customer Name') ?></label><?php
       echo $f->hidden_field_withId('ar_customer_id', $$class->ar_customer_id);
       echo $f->text_field('customer_name', $$class->customer_name, '20', 'customer_name', 'select_customer_name', '', $readonly1);
       ?>
       <i class="ar_customer_id select_popup clickable fa fa-search"></i></li>
      <li><label class="auto_complete"><?php echo gettext('Customer Number') ?></label><?php $f->text_field_d('customer_number'); ?></li>
      <li><?php $f->l_select_field_from_object('ar_customer_site_id', $customer_site_obj, 'ar_customer_site_id', 'customer_site_name', $$class->ar_customer_site_id, 'ar_customer_site_id', 'ar_customer_site_id', '', $readonly1); ?> </li>
      <li><label><?php echo gettext('Project Manager') ?></label><?php $f->text_field_d('pm_employee_name', 'employee_name'); ?>
       <?php echo $f->hidden_field_withId('pm_employee_id', $$class->pm_employee_id); ?>
       <i class="select_employee_name select_popup clickable fa fa-search"></i>
      </li>
      <li><?php $f->l_text_field_d('description') ?></li>
      <li><?php $f->l_date_fieldAnyDay('start_date', $$class->start_date) ?></li>
      <li><?php $f->l_date_fieldAnyDay('completion_date', $$class->completion_date) ?></li>
      <li><?php $f->l_text_field_d('life_cycle') ?></li>
      <li><?php $f->l_select_field_from_object('current_phase', option_header::find_options_byName('PRJ_PROJECT_PHASE'), 'option_line_code','option_line_value', $$class->current_phase) ?></li>
      <li><?php $f->l_select_field_from_object('accounting_group', option_header::find_options_byName('PRJ_ACCOUNTING_GRP'), 'option_line_code', 'option_line_value', $$class->accounting_group, 'accounting_group', 'action' , 1); ?>   </li>
     </ul> 
    </div>
    <div id="tabsHeader-2" class="tabContent">
     <ul class="column header_field">
      <li><?php $f->l_select_field_from_array('project_status' , prj_project_header::$status_a, $$class->project_status,'project_status','medium'); ?></li>
      <li><?php $f->l_text_field_dr('approval_status'); ?></li>
      <li><?php $f->l_text_field_d('role_list_id'); ?></li> 
      <li><?php $f->l_select_field_from_object('prj_work_type', prj_work_type::find_all(), 'prj_work_type_id', 'work_type', $$class->prj_work_type, 'prj_work_type','',1); ?></li> 
      <li><?php $f->l_text_field_d('probability'); ?></li> 
      <li><?php $f->l_text_field_d('opportunity_value'); ?></li> 
      <li><?php $f->l_date_fieldAnyDay('expected_approval_date', $$class->expected_approval_date) ?></li>
      <li><?php $f->l_select_field_from_object('doc_currency', option_header::currencies(), 'option_line_code', 'option_line_code', $$class->doc_currency, 'doc_currency', '', 1, $readonly); ?></li>
      <li><?php $f->l_select_field_from_object('currency', option_header::currencies(), 'option_line_code', 'option_line_code', $$class->currency, 'currency', '', 1, 1); ?></li>
      <li><?php $f->l_select_field_from_object('exchange_rate_type', gl_currency_conversion::currency_conversion_type(), 'option_line_code', 'option_line_code', $$class->exchange_rate_type, 'exchange_rate_type', '', 1, $readonly); ?></li>
      <li><?php $f->l_number_field('exchange_rate', $$class->exchange_rate, '', 'exchange_rate'); ?> </li>
     </ul>
    </div>
    <div id="tabsHeader-3" class="tabContent">
     <ul class="column header_field">
      <li><?php $f->l_select_field_from_array('billing_method', $$class->billing_method_a, $$class->billing_method, 'billing_method',  1 ,$readonly1 ,$readonly1);  ?></li>
      <li><?php $f->l_text_field_d('billing_cycle'); ?></li>
      <li><?php $f->l_select_field_from_object('prj_burden_list_header_id', prj_burden_list_header::find_all(), 'prj_burden_list_header_id', 'burden_list', $$class->prj_burden_list_header_id, 'prj_burden_list_header_id'); ?></li> 
      <li><?php $f->l_checkBox_field_d('account_burdened_cost_cb'); ?></li> 
      <li><?php $f->l_select_field_from_array('labor_billing_type', prj_project_type_header::$schedule_type_a, $$class->labor_billing_type, 'labor_billing_type'); ?></li> 
      <li class='labor-rate'><?php $f->l_select_field_from_object('employee_schedule_id', prj_rate_schedule_header::find_all_by_rateType(), 'prj_rate_schedule_header_id', 'schedule_name', $$class->employee_schedule_id, 'employee_schedule_id'); ?></li> 
      <li class='labor-rate'><?php $f->l_select_field_from_object('job_schedule_id', prj_rate_schedule_header::find_all_by_rateType('JOB'), 'prj_rate_schedule_header_id', 'schedule_name', $$class->job_schedule_id, 'job_schedule_id'); ?></li> 
      <li class='burden-rate'><?php $f->l_select_field_from_object('l_revenue_burden_id', prj_burden_list_header::find_all(), 'prj_burden_list_header_id', 'burden_list', $$class->l_revenue_burden_id, 'l_revenue_burden_id', 'l_revenue_burden_id'); ?></li> 
      <li class='burden-rate'><?php $f->l_select_field_from_object('l_invoice_burdern_id', prj_burden_list_header::find_all(), 'prj_burden_list_header_id', 'burden_list', $$class->l_invoice_burdern_id, 'l_invoice_burdern_id', 'l_invoice_burdern_id'); ?></li> 
      <li><?php $f->l_select_field_from_array('nlr_billing_type', prj_project_type_header::$schedule_type_a, $$class->nlr_billing_type, 'nlr_billing_type'); ?></li> 
      <li class='labor-rate'><?php $f->l_select_field_from_object('nlr_schedule_id', prj_rate_schedule_header::find_all_by_rateType('NON_LABOR'), 'prj_rate_schedule_header_id', 'schedule_name', $$class->nlr_schedule_id, 'nlr_schedule_id'); ?></li> 
      <li><?php $f->l_select_field_from_object('nrl_revenue_burden_id', prj_burden_list_header::find_all(), 'prj_burden_list_header_id', 'burden_list', $$class->nrl_revenue_burden_id, 'nrl_revenue_burden_id'); ?></li> 
      <li><?php $f->l_select_field_from_object('nlr_invoice_burdern_id', prj_burden_list_header::find_all(), 'prj_burden_list_header_id', 'burden_list', $$class->nlr_invoice_burdern_id, 'nlr_invoice_burdern_id'); ?></li> 
      <li><?php $f->l_text_field_d('billing_cycle_id'); ?></li> 
     </ul>
    </div>
    <div id="tabsHeader-4" class="tabContent">
     <ul class="column header_field">
      <li><?php $f->l_text_field_d('source'); ?></li>
      <li><?php $f->l_text_field_d('reference_type'); ?></li>
      <li><?php $f->l_text_field_d('reference_key_name'); ?></li>
      <li><?php $f->l_checkBox_field_d('direct_labor_cb'); ?></li>
      <li><?php $f->l_checkBox_field_d('is_template_cb'); ?></li>
      <li><?php $f->l_text_field_d('rev_enabled_cb'); ?></li>
      <li><?php $f->l_text_field_d('rev_number'); ?></li>
     </ul>
    </div>
    <div id="tabsHeader-5" class="tabContent">
     <div> 
      <div id="comments">
       <div id="comment_list">
        <?php echo!(empty($comments)) ? $comments : ""; ?>
       </div>
       <div id ="display_comment_form">
        <?php
        $reference_table = 'prj_project_header';
        $reference_id = $$class->prj_project_header_id;
        ?>
       </div>
       <div id="new_comment">
       </div>
      </div>
     </div>
    </div>
    <div id="tabsHeader-6" class="tabContent">
     <div> <?php echo ino_attachement($file) ?> </div>
    </div>

    <div id="tabsHeader-7" class="tabContent">
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

<span class="heading"><?php echo gettext('Project Details') ?></span>

<div id="tabsLine">
 <ul class="tabMain">
  <li><a href="#tabsLine-1"><?php echo gettext('Tasks') ?></a></li>
  <li><a href="#tabsLine-2"><?php echo gettext('Tasks-2') ?></a></li>
  <li><a href="#tabsLine-3"><?php echo gettext('Members') ?> </a></li>
  <li><a href="#tabsLine-4"><?php echo gettext('Controls') ?> </a></li>
 </ul>
 <div class="tabContainer">
  <form method="post" id="prj_project_line"  name="prj_project_line" class="m-margin-top-20">
   <div id="form_line" class="form_line">
    <div id="tabsLine-1" class="tabContent">
     <table class="form_line_data_table">
      <thead> 
       <tr>
        <th><?php echo gettext('Action') ?></th>
        <th><?php echo gettext('Line Id') ?></th>
        <th><?php echo gettext('Seq') ?>#</th>
        <th><?php echo gettext('Task') ?>#</th>
        <th><?php echo gettext('Add Child') ?></th>
        <th><?php echo gettext('Parent') ?></th>
        <th><?php echo gettext('Task Name') ?></th>
        <th><?php echo gettext('Description') ?></th>
        <th><?php echo gettext('Start Date') ?></th>
        <th><?php echo gettext('End Date') ?></th>
       </tr>
      </thead>
      <tbody class="form_data_line_tbody">
       <?php
       $count = 0;
       $prj_project_line_object_ai = new ArrayIterator($prj_project_line_object);
       $prj_project_line_object_ai->seek($position);
       while ($prj_project_line_object_ai->valid()) {
        $prj_project_line = $prj_project_line_object_ai->current();
        ?>         
        <tr class="prj_project_line<?php echo $count ?>">
         <td>
          <?php
          echo ino_inline_action($prj_project_line->prj_project_line_id, array('prj_project_header_id' => $prj_project_header->prj_project_header_id));
          ?>
         </td>
         <td><?php $f->text_field_wid2sr('prj_project_line_id' , 'line_id'); ?></td>
         <td><?php $f->seq_field_d($count) ?></td>
         <!--<td><?php // $f->text_field_wid2r('task_seq_number','medium');      ?></td>-->
         <td><?php $f->text_field_wid2s('task_number', 'lines_number'); ?></td>
         <td>
          <ul class="extra_inline_action">
           <li class="add_child clickable text-center" data-heighest_child="0"><i class="fa fa-plus-square-o"></i></li>
          </ul>
         </td>
         <td><?php $f->text_field_wid2s('parent_prj_task_num'); ?></td>
         <td><?php $f->text_field_wid2('task_name'); ?></td>
         <td><?php $f->text_field_wid2('line_description'); ?></td>
         <td><?php echo $f->date_fieldAnyDay('start_date', $$class_second->start_date, 'copy'); ?></td>
         <td><?php echo $f->date_fieldAnyDay('end_date', $$class_second->end_date); ?></td>

        </tr>
        <?php
        $prj_project_line_object_ai->next();
        if ($prj_project_line_object_ai->key() == $position + $per_page) {
         break;
        }
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
        <th><?php echo gettext('Task Seq') ?>#</th>
        <th><?php echo gettext('Task') ?>#</th>
        <th><?php echo gettext('Level Weight') ?>#</th>
        <th><?php echo gettext('Service Type') ?></th>
        <th><?php echo gettext('Work Type') ?></th>
        <th><?php echo gettext('Allow Charges') ?></th>
        <th><?php echo gettext('Capitalizable') ?></th>
        <th><?php echo gettext('Milestone ?') ?></th>
        <th><?php echo gettext('Task Status') ?></th>
        <th><?php echo gettext('CIP Asset') ?></th>
       </tr>
      </thead>
      <tbody class="form_data_line_tbody">
       <?php
       $count = 0;
       $prj_project_line_object_ai = new ArrayIterator($prj_project_line_object);
       $prj_project_line_object_ai->seek($position);
       while ($prj_project_line_object_ai->valid()) {
        $prj_project_line = $prj_project_line_object_ai->current();
        ?>         
        <tr class="prj_project_line<?php echo $count ?>">
         <td><?php $f->seq_field_d($count) ?></td>
         <td><?php echo $f->text_field('task_number2', $$class_second->task_number, '', '', 'task_number'); ?></td>
         <td><?php $f->text_field_wid2s('task_level_weight'); ?></td>
         <td><?php $f->text_field_wid2s('service_type'); ?></td>
         <td><?php echo $f->select_field_from_object('work_type', prj_work_type::find_all(), 'prj_work_type_id', 'work_type', $$class_second->work_type, '' ,'', 1); ?></td>
         <td><?php $f->checkBox_field_wid2('allow_charges_cb'); ?></td>    
         <td><?php $f->checkBox_field_wid2('capitalizable_cb'); ?></td>   
         <td><?php $f->checkBox_field_wid2('milestone_cb'); ?></td>   
         <td><?php $f->text_field_wid2('task_status'); ?></td>
         <td><?php $f->text_field_wid2('cip_asset_id'); ?></td>
        </tr>
        <?php
        $prj_project_line_object_ai->next();
        if ($prj_project_line_object_ai->key() == $position + $per_page) {
         break;
        }
        $count = $count + 1;
       }
       ?>
      </tbody>
     </table>
    </div>
   </div>
  </form>
  <div id ="form_line2" class="form_line2">
   <form  method="post" id="prj_project_member"  name="prj_project_member">
    <div id="tabsLine-3" class="tabContent">
     <table class="form_line_data_table">
      <thead> 
       <tr>
        <th><?php echo gettext('Action') ?></th>
        <th><?php echo gettext('Member Id') ?></th>
        <th><?php echo gettext('User Name') ?></th>
        <th><?php echo gettext('Role') ?></th>
        <th><?php echo gettext('Description') ?></th>
        <th><?php echo gettext('Start Date') ?></th>
        <th><?php echo gettext('End Date') ?></th>
       </tr>
      </thead>
      <tbody class="form_data_line_tbody2 wip_wo_bom_values" >
       <?php
       $count = 0;
       foreach ($prj_project_member_object as $prj_project_member) {
        if (!empty($prj_project_member->user_id)) {
         $mem_user_i = ino_user::find_by_id($prj_project_member->user_id);
         $$class_third->member_username = $mem_user_i->username;
        }
        ?>         
        <tr class="prj_project_member<?php echo $count ?>">
         <td>    
          <ul class="inline_action">
           <li class="add_row_img"><i class="fa fa-plus-circle"></i></li>
           <li class="remove_row_img"><i class="fa fa-minus-circle"></i></li>
           <li><input type="checkbox" name="line_id_cb" value="<?php echo htmlentities($prj_project_member->prj_project_member_id); ?>"></li>           
           <li><?php echo form::hidden_field('prj_project_header_id', $$class->prj_project_header_id); ?></li>
          </ul>
         </td>
         <td><?php form::text_field_wid3sr('prj_project_member_id'); ?></td>
         <td><?php
          $f->val_field_wid3('member_username',  'ino_user' ,  'username' , '', 'select user username');
          echo $f->hidden_field('user_id', $$class_third->user_id);
          ?><i class="select_username select_popup clickable fa fa-search"></i></td>
         <td><?php echo $f->select_field_from_object('prj_role_id', prj_role::find_all(), 'prj_role_id', 'role_name', $$class_third->prj_role_id, '', 'medium'); ?></td>
         <td><?php $f->text_field_wid3('description'); ?></td>
         <td><?php echo $f->date_fieldAnyDay('start_date', $$class_third->start_date); ?></td>
         <td><?php echo $f->date_fieldAnyDay('end_date', $$class_third->end_date); ?></td>        
        </tr>
        <?php
        $count = $count + 1;
       }
       ?>
      </tbody>
     </table>
    </div>
   </form>
  </div>
  <div id ="form_line3" class="form_line3">
   <div id="tabsLine-4" class="tabContent">
    <form  method="post" id="prj_project_control"  name="prj_project_control">
     <table class="form_line_data_table3">
      <thead> 
       <tr>
        <th><?php echo gettext('Action') ?></th>
        <th><?php echo gettext('Control Id') ?></th>
        <th><?php echo gettext('Expenditure Type') ?></th>
        <th><?php echo gettext('Expenditure Category') ?></th>
        <th><?php echo gettext('Description') ?></th>
        <th><?php echo gettext('Job') ?></th>
        <th><?php echo gettext('Start Date') ?></th>
        <th><?php echo gettext('End Date') ?></th>
        <th><?php echo gettext('Chargeable') ?></th>
        <th><?php echo gettext('Billable') ?></th>
       </tr>
      </thead>
      <tbody class="form_data_line_tbody3 wip_wo_bom_values" >
       <?php
       $count = 0;
       foreach ($prj_project_control_object as $prj_project_control) {
        ?>         
        <tr class="prj_project_control<?php echo $count ?>">
         <td>    
          <ul class="inline_action">
           <li class="add_row_img"><i class="fa fa-plus-circle"></i></li>
           <li class="remove_row_img"><i class="fa fa-minus-circle"></i></li>
           <li><input type="checkbox" name="line_id_cb" value="<?php echo htmlentities($prj_project_control->prj_project_control_id); ?>"></li>           
           <li><?php echo form::hidden_field('prj_project_header_id', $$class->prj_project_header_id); ?></li>
          </ul>
         </td>
         <td><?php form::text_field_wid4sr('prj_project_control_id'); ?></td>
         <td><?php echo $f->select_field_from_object('prj_expenditure_type_id', prj_expenditure_type_header::find_all(), 'prj_expenditure_type_header_id', 'expenditure_type', $$class_fourth->prj_expenditure_type_id, '', 'medium'); ?></td>
         <td><?php echo $f->select_field_from_object('prj_expenditure_category_code', option_header::find_by_name('PRJ_EXPENDITURE_CATEGORY'), 'option_line_code', 'option_line_value', $$class_fourth->prj_expenditure_category_code, '', 'medium'); ?></td>
         <td><?php $f->text_field_wid4('description'); ?></td>
         <td><?php echo $f->select_field_from_object('hr_job_id', hr_job::find_all(), 'hr_job_id', 'job_name', $$class_fourth->hr_job_id); ?></td>
         <td><?php echo $f->date_fieldAnyDay('start_date', $$class_fourth->start_date); ?></td>
         <td><?php echo $f->date_fieldAnyDay('end_date', $$class_fourth->end_date); ?></td> 
         <td><?php echo $f->checkBox_field('chargeable_cb', $$class_fourth->chargeable_cb); ?></td>
         <td><?php echo $f->checkBox_field('billable_cb', $$class_fourth->billable_cb); ?></td>
        </tr>
        <?php
        $count = $count + 1;
       }
       ?>
      </tbody>
     </table>
    </form>
   </div>
  </div>
 </div>
</div>

<div class="row small-top-margin">
 <div id="pagination" style="clear: both;">
  <?php echo $pagination->show_pagination(); ?>
 </div>
</div>


<div id="js_data">
 <ul id="js_saving_data">
  <li class="headerClassName" data-headerClassName="prj_project_header" ></li>
  <li class="lineClassName" data-lineClassName="prj_project_line" ></li>
  <li class="lineClassName2" data-lineClassName2="prj_project_member" ></li>
  <li class="lineClassName3" data-lineClassName3="prj_project_control" ></li>
  <li class="savingOnlyHeader" data-savingOnlyHeader="false" ></li>
  <li class="primary_column_id" data-primary_column_id="prj_project_header_id" ></li>
  <li class="form_header_id" data-form_header_id="prj_project_header" ></li>
  <li class="line_key_field" data-line_key_field="item_description" ></li>
  <li class="single_line" data-single_line="false" ></li>
  <li class="form_line_id" data-form_line_id="prj_project_line" ></li>
 </ul>
 <ul id="js_contextMenu_data">
  <li class="docHedaderId" data-docHedaderId="prj_project_header_id" ></li>
  <li class="docLineId" data-docLineId="prj_project_line_id" ></li>
  <li class="btn1DivId" data-btn1DivId="prj_project_header" ></li>
  <li class="btn2DivId" data-btn2DivId="form_line" ></li>
  <li class="tbodyClass" data-tbodyClass="form_data_line_tbody" ></li>
  <li class="noOfTabbs" data-noOfTabbs="6" ></li>
 </ul>
</div>