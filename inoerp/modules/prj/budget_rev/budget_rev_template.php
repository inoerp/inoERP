<!-- * 
inoERP
 *
 * @copyright   2014 Nishit R. Das
 * @license     https://www.mozilla.org/MPL/2.0/
 * @link        http://inoideas.org
 * @source code https://github.com/inoerp/inoERP
-->
<div id ="form_header"><span class="heading"><?php echo gettext('Project Budget Revision') ?></span>
 <form  method="post" id="prj_budget_rev_header"  name="prj_budget_rev_header">
  <div id="tabsHeader">
   <ul class="tabMain">
    <li><a href="#tabsHeader-1"><?php echo gettext('Basic Info') ?></a></li>
    <li><a href="#tabsHeader-2"><?php echo gettext('Basic-2') ?></a></li>
    <li><a href="#tabsHeader-3"><?php echo gettext('Note') ?></a></li>
    <li><a href="#tabsHeader-4"><?php echo gettext('Attachments') ?></a></li>
   </ul>
   <div class="tabContainer">
    <div id="tabsHeader-1" class="tabContent">
     <ul class="column header_field">
      <li><?php $f->l_text_field_dr_withSearch('prj_budget_rev_header_id') ?>
       <a name="show" href="form.php?class_name=prj_budget_rev_header&<?php echo "mode=$mode"; ?>" class="show document_id prj_budget_rev_header_id"><i class="fa fa-refresh"></i></a> 
      </li>
      <li><?php $f->l_text_field_dr('prj_budget_header_id') ?> </li>
      <li><?php $f->l_select_field_from_object('budget_type', option_header::find_options_byName('PRJ_BUDGET_TYPE'), 'option_line_code', 'option_line_value', $$class->budget_type, 'budget_type', '', 1, $readonly1, '', '', '', 'mapper1'); ?></li>
      <li><?php
       echo $f->l_val_field_dm('project_number', 'prj_project_header', 'project_number', '', 'project_number', 'vf_select_project_number');
       echo $f->hidden_field_withId('prj_project_header_id', $$class->prj_project_header_id);
       ?><i class="generic g_select_project_number select_popup clickable fa fa-search" data-class_name="prj_project_header"></i></li>
      <li><?php $f->l_text_field_dr('version_number'); ?></li>
      <li><?php $f->l_text_field_d('version_name'); ?></li>
      <li><?php $f->l_text_field_d('description'); ?></li> 
      <li><?php $f->l_checkBox_field_dr('current_cb'); ?></li> 
      <li><?php $f->l_checkBox_field_dr('original_cb'); ?></li> 
      <li><?php $f->l_checkBox_field_dr('baselined_cb'); ?></li> 
     </ul>
    </div>
    <div id="tabsHeader-2" class="tabContent">
     <ul class="column header_field">
      <li><?php $f->l_text_field_d('raw_cost'); ?></li>
      <li><?php $f->l_text_field_d('burdened_cost'); ?></li>
      <li><?php $f->l_text_field_d('labor_effort'); ?></li> 
      <li><?php $f->l_text_field_d('nlr_effort'); ?></li> 
      <li><?php $f->l_text_field_d('revenue'); ?></li> 
      <li><?php $f->l_text_field_dr('baselined_by'); ?></li> 
      <li><?php $f->l_date_fieldAnyDay('baselined_date', $$class->baselined_date, 'always_readonly'); ?></li> 
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
        $reference_table = 'prj_budget_rev_header';
        $reference_id = $$class->prj_budget_rev_header_id;
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

<div id="form_line" class="form_line"><span class="heading"><?php echo gettext('Budget Revision Lines') ?></span>
 <form method="post" id="prj_budget_rev_line"  name="prj_budget_rev_line">
  <div id="tabsLine">
   <ul class="tabMain">
    <li><a href="#tabsLine-1"><?php echo gettext('Amounts') ?></a></li>
    <li><a href="#tabsLine-2"><?php echo gettext('Future') ?></a></li>
   </ul>
   <div class="tabContainer">
    <div id="tabsLine-1" class="tabContent">
     <table class="form_line_data_table">
      <thead> 
       <tr>
        <th><?php echo gettext('Action') ?></th>
        <th><?php echo gettext('Sequence') ?></th>
        <th><?php echo gettext('Line Id') ?></th>
        <th><?php echo gettext('Task') ?>#</th>
        <th><?php echo gettext('Resource') ?></th>
        <th><?php echo gettext('Description') ?></th>
        <th><?php echo gettext('Cost Qty') ?></th>
        <th><?php echo gettext('Raw Amount') ?></th>
        <th><?php echo gettext('Burden') ?></th>
        <th><?php echo gettext('Rev Qty') ?></th>
        <th><?php echo gettext('Rev Amount') ?></th>
       </tr>
      </thead>
      <tbody class="form_data_line_tbody">
       <?php
       $count = 0;
       foreach ($prj_budget_rev_line_object as $prj_budget_rev_line) {
        $$class_second->task_number = !empty($$class_second->prj_project_line_id) ? prj_project_line::find_by_id($$class_second->prj_project_line_id)->task_number : '';
        ?>         
        <tr class="prj_budget_rev_line<?php echo $count ?>">
         <td>
          <?php echo ino_inline_action($prj_budget_rev_line->prj_budget_rev_line_id, array('prj_budget_rev_header_id' => $$class->prj_budget_rev_header_id));          ?>
         </td>
         <td><?php $f->seq_field_d($count); ?></td>
         <td><?php $f->text_field_wid2sr('prj_budget_rev_line_id', 'always_readonly dontCopy'); ?></td>
         <td><?php
          $f->val_field_wid2m('task_number', 'prj_project_all_v', 'task_number', '', 'select project_task_number');
          echo $f->hidden_field_withCLass('prj_project_line_id', $$class_second->prj_project_line_id, 'dontCopy');
          echo $f->hidden_field_withCLass('prj_project_header_id', $$class->prj_project_header_id, 'prj_project_header_id popup_value');
          ?><i class="generic select_project_task_number select_popup clickable fa fa-search" data-class_name="prj_project_all_v"></i></td>
         <td><?php $f->text_field_wid2('prj_resource_line_id'); ?></td>
         <td><?php $f->text_field_wid2('description'); ?></td>
         <td><?php $f->text_field_wid2('quantity'); ?></td>
         <td><?php $f->text_field_wid2('raw_cost'); ?></td>
         <td><?php $f->text_field_wid2('burden_cost'); ?></td>
         <td><?php $f->text_field_wid2('revenue_quantity'); ?></td>
         <td><?php $f->text_field_wid2('revenue_amount'); ?></td>
        </tr>
        <?php
        $count = $count + 1;
       }
       ?>
      </tbody>
     </table>
    </div>
    <div id="tabsLine-2" class="tabContent">

    </div>
   </div>
  </div>
 </form>
</div>

<div id="js_data">
  <ul id="js_saving_data">
  <li class="headerClassName" data-headerClassName="prj_budget_rev_header" ></li>
  <li class="lineClassName" data-lineClassName="prj_budget_rev_line" ></li>
  <li class="savingOnlyHeader" data-savingOnlyHeader="false" ></li>
  <li class="primary_column_id" data-primary_column_id="prj_budget_rev_header_id" ></li>
  <li class="form_header_id" data-form_header_id="prj_budget_rev_header" ></li>
  <li class="line_key_field" data-line_key_field="line_name" ></li>
  <li class="single_line" data-single_line="false" ></li>
  <li class="form_line_id" data-form_line_id="prj_budget_rev_line" ></li>
 </ul>
 <ul id="js_contextMenu_data">
  <li class="docHedaderId" data-docHedaderId="prj_budget_rev_header_id" ></li>
  <li class="docLineId" data-docLineId="prj_budget_rev_line_id" ></li>
  <li class="btn1DivId" data-btn1DivId="prj_budget_rev_header" ></li>
  <li class="btn2DivId" data-btn2DivId="form_line" ></li>
  <li class="tbodyClass" data-tbodyClass="form_data_line_tbody" ></li>
  <li class="noOfTabbs" data-noOfTabbs="2" ></li>
 </ul>
</div>