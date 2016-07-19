<!-- * 
inoERP
 *
 * @copyright   2014 Nishit R. Das
 * @license     https://www.mozilla.org/MPL/2.0/
 * @link        http://inoideas.org
 * @source code https://github.com/inoerp/inoERP
-->
<div id ="form_header"><span class="heading"><?php
  echo gettext('Project Type')
  ?></span>
 <form method="post" id="prj_project_type_header"  name="prj_project_type_header">
  <div id="tabsHeader">
   <ul class="tabMain">
    <li><a href="#tabsHeader-1"><?php echo gettext('Basic Info') ?></a></li>
    <li><a href="#tabsHeader-2"><?php echo gettext('Costing') ?></a></li>
    <li><a href="#tabsHeader-3"><?php echo gettext('Budget') ?></a></li>
    <li><a href="#tabsHeader-4"><?php echo gettext('Billing') ?></a></li>
    <li><a href="#tabsHeader-5"><?php echo gettext('Invoice Rules') ?></a></li>
    <li><a href="#tabsHeader-6"><?php echo gettext('Note') ?></a></li>
    <li><a href="#tabsHeader-7"><?php echo gettext('Attachments') ?></a></li>
   </ul>
   <div class="tabContainer">
    <div id="tabsHeader-1" class="tabContent">
     <ul class="column header_field">
      <li><?php $f->l_text_field_dr_withSearch('prj_project_type_header_id') ?>
       <a name="show" href="form.php?class_name=prj_project_type_header&<?php echo "mode=$mode"; ?>" class="show document_id prj_project_type_header_id"><i class="fa fa-refresh"></i></a> 
      </li>
      <li><?php $f->l_select_field_from_object('bu_org_id', org::find_all_business(), 'org_id', 'org', $$class->bu_org_id, 'bu_org_id', $readonly1, '', ''); ?>						 </li>
      <li><?php $f->l_text_field_d('project_type'); ?></li>
      <li><?php $f->l_select_field_from_array('project_class', prj_project_type_header::$project_class_a, $$class->project_class, 'project_class'); ?></li>
      <li><?php $f->l_select_field_from_object('service_type', option_header::find_options_byName('CE_SERVICE TYPE'), 'option_line_code', 'option_line_value', $$class->service_type, 'service_type'); ?></li>
      <!--<li><?php // $f->l_text_field_d('role_list_id');    ?></li>-->
      <li><?php $f->l_select_field_from_object('prj_work_type_id', prj_work_type::find_all(), 'prj_work_type_id', 'work_type', $$class->prj_work_type_id, 'prj_work_type_id'); ?></li>
      <li><?php $f->l_text_field_d('description'); ?></li> 
      <li><?php $f->l_date_fieldAnyDay('effective_from', $$class->effective_from); ?></li> 
      <li><?php $f->l_date_fieldAnyDay('effective_to', $$class->effective_to); ?></li> 
     </ul> 
    </div>
    <div id="tabsHeader-2" class="tabContent">
     <ul class="column header_field">
      <li><?php $f->l_checkBox_field_d('sponsored_cb'); ?></li>
      <li><?php $f->l_checkBox_field_d('cost_burdened_cb'); ?></li>
      <li><?php $f->l_select_field_from_object('prj_burden_list_header_id',  prj_burden_list_header::find_all(),'prj_burden_list_header_id','burden_list', $$class->prj_burden_list_header_id,'prj_burden_list_header_id'); ?></li> 
      <li><?php $f->l_checkBox_field_d('account_burdened_cost_cb'); ?></li> 
      <li><?php $f->l_text_field_d('cip_cost_type'); ?></li> 
      <li><?php $f->l_text_field_d('asset_cost_allocation_method'); ?></li> 
      <li><?php $f->l_text_field_d('event_processing_method'); ?></li> 
      <li><?php $f->l_text_field_d('grouping_method'); ?></li> 
     </ul>
    </div>
    <div id="tabsHeader-3" class="tabContent">
     <ul class="column header_field">
      <li><?php $f->l_select_field_from_object('cost_budget_method', option_header::find_options_byName('PRJ_BUDGET_ENTRY_METHOD'), 'option_line_code', 'option_line_value', $$class->cost_budget_method); ?></li> 
      <li><?php $f->l_select_field_from_object('revenue_budget_method', option_header::find_options_byName('PRJ_BUDGET_ENTRY_METHOD'), 'option_line_code', 'option_line_value', $$class->revenue_budget_method); ?></li> 
      <li><?php $f->l_text_field_d('resource_list_id'); ?></li> 
     </ul>
    </div>
    <div id="tabsHeader-4" class="tabContent">
     <ul class="column header_field">
      <li><?php $f->l_select_field_from_array('labor_billing_type', prj_project_type_header::$schedule_type_a, $$class->labor_billing_type, 'labor_billing_type'); ?></li> 
      <li class='labor-rate'><?php $f->l_select_field_from_object('employee_schedule_id', prj_rate_schedule_header::find_all_by_rateType(), 'prj_rate_schedule_header_id', 'schedule_name', $$class->employee_schedule_id, 'employee_schedule_id'); ?></li> 
      <li class='labor-rate'><?php $f->l_select_field_from_object('job_schedule_id', prj_rate_schedule_header::find_all_by_rateType('JOB'), 'prj_rate_schedule_header_id', 'schedule_name', $$class->job_schedule_id, 'job_schedule_id'); ?></li> 
      <li class='burden-rate'><?php $f->l_select_field_from_object('l_revenue_burden_id',  prj_burden_list_header::find_all(),'prj_burden_list_header_id','burden_list', $$class->l_revenue_burden_id,'l_revenue_burden_id','l_revenue_burden_id'); ?></li> 
      <li class='burden-rate'><?php $f->l_select_field_from_object('l_invoice_burdern_id',  prj_burden_list_header::find_all(),'prj_burden_list_header_id','burden_list', $$class->l_invoice_burdern_id,'l_invoice_burdern_id','l_invoice_burdern_id'); ?></li> 
      <li><?php $f->l_select_field_from_array('nlr_billing_type', prj_project_type_header::$schedule_type_a, $$class->nlr_billing_type, 'nlr_billing_type'); ?></li> 
      <li><?php $f->l_text_field_d('nlr_schedule_id'); ?></li> 
      <li><?php $f->l_select_field_from_object('nrl_revenue_burden_id',  prj_burden_list_header::find_all(),'prj_burden_list_header_id','burden_list', $$class->nrl_revenue_burden_id,'nrl_revenue_burden_id'); ?></li> 
      <li><?php $f->l_select_field_from_object('nlr_invoice_burdern_id',  prj_burden_list_header::find_all(),'prj_burden_list_header_id','burden_list', $$class->nlr_invoice_burdern_id,'nlr_invoice_burdern_id'); ?></li> 
      <li><?php $f->l_text_field_d('billing_cycle_id'); ?></li> 
     </ul>
    </div>
    <div id="tabsHeader-5" class="tabContent">
     <ul class="column header_field">
      <li><?php $f->l_checkBox_field_d('cost_cost_cb'); ?></li>
      <li><?php $f->l_checkBox_field_d('cost_event_cb'); ?></li> 
      <li><?php $f->l_checkBox_field_d('cost_work_cb'); ?></li> 
      <li><?php $f->l_checkBox_field_d('event_event_cb'); ?></li> 
      <li><?php $f->l_checkBox_field_d('event_work_cb'); ?></li> 
      <li><?php $f->l_checkBox_field_d('work_event_cb'); ?></li> 
      <li><?php $f->l_checkBox_field_d('work_work_cb'); ?></li> 
     </ul>
    </div>
    <div id="tabsHeader-6" class="tabContent">
     <div> 
      <div id="comments">
       <div id="comment_list">
        <?php echo!(empty($comments)) ? $comments : ""; ?>
       </div>
       <div id ="display_comment_form">
        <?php
        $reference_table = 'prj_project_type_header';
        $reference_id = $$class->prj_project_type_header_id;
        ?>
       </div>
       <div id="new_comment">
       </div>
      </div>
     </div>
    </div>
    <div id="tabsHeader-7" class="tabContent">
     <div> <?php echo ino_attachement($file) ?> </div>
    </div>
   </div>

  </div>
 </form>
</div>

<span class="heading"><?php echo gettext('Project Type Details') ?></span>

<div id="tabsLine">
 <ul class="tabMain">
  <li><a href="#tabsLine-1"><?php echo gettext('Classifications') ?></a></li>
  <li><a href="#tabsLine-2"><?php echo gettext('Billing Processes') ?></a></li>
 </ul>
 <div class="tabContainer">
  <form method="post" id="prj_project_type_line"  name="prj_project_type_line" class="m-margin-top-20">
   <div id="form_line" class="form_line">
    <div id="tabsLine-1" class="tabContent">
     <table class="form_line_data_table">
      <thead> 
       <tr>
        <th><?php echo gettext('Action') ?></th>
        <th><?php echo gettext('Line Id') ?></th>
        <th><?php echo gettext('Category') ?>#</th>
        <th><?php echo gettext('Description') ?></th>
        <th><?php echo gettext('Required') ?>?</th>
       </tr>
      </thead>
      <tbody class="form_data_line_tbody">
       <?php
       $count = 0;
       foreach ($prj_project_type_line_object as $prj_project_type_line) {
        if(!empty($$class_second->prj_category_header_id)){
         $$class_second->category_description = prj_category_header::find_by_id($$class_second->prj_category_header_id)->description;
        }
        ?>         
        <tr class="prj_project_type_line<?php echo $count ?>">
         <td>
          <?php
          echo ino_inline_action($prj_project_type_line->prj_project_type_line_id, array('prj_project_type_header_id' => $prj_project_type_header->prj_project_type_header_id));
          ?>
         </td>

         <td><?php form::text_field_wid2sr('prj_project_type_line_id'); ?></td>
         <td><?php echo $f->select_field_from_object('prj_category_header_id', prj_category_header::find_all(), 'prj_category_header_id', 'category', $$class_second->prj_category_header_id, '', 'large', 1, $readonly); ?></td>
         <td><?php form::text_field_wid2r('category_description'); ?></td>
         <td><?php echo $f->checkBox_field_wid2('required_cb'); ?></td> 
        </tr>
        <?php
        $count = $count + 1;
       }
       ?>
      </tbody>
     </table>
    </div>
   </div>
  </form>
  <div id ="form_line2" class="form_line2">
   <form action=""  method="post" id="prj_project_type_billing"  name="prj_project_type_billing">
    <div id="tabsLine-2" class="tabContent">
     <table class="form_line_data_table">
      <thead> 
       <tr>
        <th><?php echo gettext('Action') ?></th>
        <th><?php echo gettext('Billing Id') ?></th>
        <th><?php echo gettext('Extension') ?></th>
        <th><?php echo gettext('Currency') ?></th>
        <th><?php echo gettext('Amount') ?></th>
        <th><?php echo gettext('Percentage') ?></th>
        <th><?php echo gettext('Active') ?></th>
       </tr>
      </thead>
      <tbody class="form_data_line_tbody2 wip_wo_bom_values" >
       <?php
       $count = 0;
       foreach ($prj_project_type_billing_object as $prj_project_type_billing) {
        ?>         
        <tr class="prj_project_type_billing<?php echo $count ?>">
         <td>    
          <ul class="inline_action">
           <li class="add_row_img"><i class="fa fa-plus-circle"></i></li>
           <li class="remove_row_img"><i class="fa fa-minus-circle"></i></li>
           <li><input type="checkbox" name="line_id_cb" value="<?php echo htmlentities($prj_project_type_billing->prj_project_type_billing_id); ?>"></li>           
           <li><?php echo form::hidden_field('prj_project_type_header_id', $$class->prj_project_type_header_id); ?></li>
          </ul>
         </td>
         <td><?php form::text_field_wid3sr('prj_project_type_billing_id'); ?></td>
         <td><?php echo $f->text_field('prj_billing_extn_id', $$class_third->prj_billing_extn_id, '20', '', 'item_description', '', $readonly); ?></td>
         <td><?php echo $f->select_field_from_object('currency', option_header::currencies(), 'option_line_code', 'option_line_value', $$class_third->currency); ?></td>
         <td><?php echo $f->text_field_wid3('amount'); ?></td>
         <td><?php echo $f->text_field_wid3('percentage'); ?></td>
         <td><?php $f->checkBox_field('active_cb', $$class_third->active_cb) ?></td>
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
 </div>
</div>

<div id="js_data">
 <ul id="js_saving_data">
  <li class="headerClassName" data-headerClassName="prj_project_type_header" ></li>
  <li class="lineClassName" data-lineClassName="prj_project_type_line" ></li>
  <li class="lineClassName2" data-lineClassName2="prj_project_type_billing" ></li>
  <li class="savingOnlyHeader" data-savingOnlyHeader="false" ></li>
  <li class="primary_column_id" data-primary_column_id="prj_project_type_header_id" ></li>
  <li class="form_header_id" data-form_header_id="prj_project_type_header" ></li>
  <li class="line_key_field" data-line_key_field="item_description" ></li>
  <li class="single_line" data-single_line="false" ></li>
  <li class="form_line_id" data-form_line_id="prj_project_type_line" ></li>
 </ul>
 <ul id="js_contextMenu_data">
  <li class="docHedaderId" data-docHedaderId="prj_project_type_header_id" ></li>
  <li class="docLineId" data-docLineId="prj_project_type_line_id" ></li>
  <li class="btn1DivId" data-btn1DivId="prj_project_type_header" ></li>
  <li class="btn2DivId" data-btn2DivId="form_line" ></li>
  <li class="tbodyClass" data-tbodyClass="form_data_line_tbody" ></li>
  <li class="noOfTabbs" data-noOfTabbs="1" ></li>
 </ul>
</div>