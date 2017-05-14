<!-- * 
inoERP
 *
 * @copyright   2014 Nishit R. Das
 * @license     https://www.mozilla.org/MPL/2.0/
 * @link        http://inoideas.org
 * @source code https://github.com/inoerp/inoERP
-->
<div id ="form_header"><span class="heading"><?php echo gettext('Resource List') ?></span>
 <form method="post" id="prj_resource_list_header"  name="prj_resource_list_header">
  <div id="tabsHeader">
   <ul class="tabMain">
    <li><a href="#tabsHeader-1"><?php echo gettext('Basic Info') ?></a></li>
    <li><a href="#tabsHeader-2"><?php echo gettext('Note') ?></a></li>
    <li><a href="#tabsHeader-3"><?php echo gettext('Attachments') ?></a></li>
   </ul>
   <div class="tabContainer">
    <div id="tabsHeader-1" class="tabContent">
     <ul class="column header_field">
      <li><?php $f->l_text_field_dr_withSearch('prj_resource_list_header_id') ?>
       <a name="show" href="form.php?class_name=prj_resource_list_header&<?php echo "mode=$mode"; ?>" class="show document_id prj_resource_list_header_id"><i class="fa fa-refresh"></i></a> 
      </li>
      <li><?php $f->l_text_field_d('list_name'); ?></li>
      <li><?php $f->l_text_field_d('description'); ?></li> 
      <li><?php $f->l_date_fieldAnyDay('effective_from', $$class->effective_from); ?></li> 
      <li><?php $f->l_date_fieldAnyDay('effective_to', $$class->effective_to); ?></li> 
     </ul>
    </div>
    <div id="tabsHeader-2" class="tabContent">
     <div> 
      <div id="comments">
       <div id="comment_list">
        <?php echo!(empty($comments)) ? $comments : ""; ?>
       </div>
       <div id ="display_comment_form">
        <?php
        $reference_table = 'prj_resource_list_header';
        $reference_id = $$class->prj_resource_list_header_id;
        ?>
       </div>
       <div id="new_comment">
       </div>
      </div>
     </div>
    </div>
    <div id="tabsHeader-3" class="tabContent">
     <div> <?php echo ino_attachement($file) ?> </div>
    </div>
   </div>
  </div>
 </form>
</div>

<div id="form_line" class="form_line"><span class="heading"><?php echo gettext('Resource Details') ?></span>
 <form method="post" id="prj_resource_list_line"  name="prj_resource_list_line">
  <div id="tabsLine">
   <ul class="tabMain">
    <li><a href="#tabsLine-1"><?php echo gettext('Resources') ?></a></li>
    <li><a href="#tabsLine-2"><?php echo gettext('Resources-2') ?></a></li>
   </ul>
   <div class="tabContainer">
    <div id="tabsLine-1" class="tabContent">
     <table class="form_line_data_table">
      <thead> 
       <tr>
        <th><?php echo gettext('Action') ?></th>
        <th><?php echo gettext('Sequence') ?></th>
        <th><?php echo gettext('Line Id') ?></th>
        <th><?php echo gettext('Resource Type') ?></th>
        <th><?php echo gettext('Description') ?></th>
        <th><?php echo gettext('From Date') ?></th>
        <th><?php echo gettext('To Date') ?></th>
        <th><?php echo gettext('Org Id') ?></th>
        <th><?php echo gettext('Employee') ?></th>
       </tr>
      </thead>
      <tbody class="form_data_line_tbody">
       <?php
       $count = 0; 
       foreach ($prj_resource_list_line_object as $prj_resource_list_line) {
        ?>         
        <tr class="prj_resource_list_line<?php echo $count ?>">
         <td>
          <?php
          echo ino_inline_action($prj_resource_list_line->prj_resource_list_line_id, array('prj_resource_list_header_id' => $prj_resource_list_header->prj_resource_list_header_id));
          ?>
         </td>
         <td><?php $f->seq_field_d($count); ?></td>
         <td><?php $f->text_field_wid2sr('prj_resource_list_line_id' ,'always_readonly'); ?></td>
         <td><?php echo $f->select_field_from_array('resource_type', prj_resource_list_line::$resource_type_a, $$class_second->resource_type); ?></td>
         <td><?php $f->text_field_d2('description'); ?></td>
         <td><?php echo $f->date_fieldAnyDay('effective_from', $$class_second->effective_from); ?></td>
         <td><?php echo $f->date_fieldAnyDay('effective_to', $$class_second->effective_to); ?></td>
         <td><?php echo $f->select_field_from_object('bu_org_id', org::find_all_business(), 'org_id', 'org', $$class_second->org_id,'','resource_type_control'); ?>						 </td>
         <td><?php
          $f->text_field_wid2('employee_name', 'select employee resource_type_control');
          echo $f->hidden_field_withCLass('hr_employee_id', $$class_second->hr_employee_id, 'resource_type_control employee');
          ?><i class="select_employee_name select_popup clickable fa fa-search"></i></td>
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
        <th><?php echo gettext('Sequence') ?></th>
        <th><?php echo gettext('Line Id') ?></th>
        <th><?php echo gettext('Job') ?></th>
        <th><?php echo gettext('Expenditure Type') ?></th>
        <th><?php echo gettext('Expenditure Category') ?></th>
        <th><?php echo gettext('Revenue Category') ?></th>
       </tr>
      </thead>
      <tbody class="form_data_line_tbody">
       <?php
       $count = 0;
       foreach ($prj_resource_list_line_object as $prj_resource_list_line) {
        ?>         
        <tr class="prj_resource_list_line<?php echo $count ?>">
         <td><?php $f->seq_field_d($count); ?></td>
         <td><?php $f->text_field_d2sr('prj_resource_list_line_id'); ?></td>
         <td><?php echo $f->select_field_from_object('job_id', hr_job::find_all(), 'hr_job_id', 'job_name', $$class_second->hr_job_id ,'' ,'resource_type_control'); ?>						 </td>
         <td><?php echo $f->select_field_from_object('prj_expenditure_type_id', prj_expenditure_type_header::find_all(), 'prj_expenditure_type_header_id', 'expenditure_type', $$class_second->prj_expenditure_type_id, '' ,'resource_type_control'); ?>						 </td>
         <td><?php echo $f->select_field_from_object('expenditure_category', prj_expenditure_type_header::prj_expenditure_category(), 'option_line_code', 'option_line_value', $$class_second->expenditure_category, '', 'resource_type_control'); ?>    </td>
         <td><?php echo $f->select_field_from_object('revenue_category', prj_expenditure_type_header::prj_revenue_category(), 'option_line_code', 'option_line_value', $$class_second->revenue_category, '', 'resource_type_control'); ?>    </td>
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
  <li class="headerClassName" data-headerClassName="prj_resource_list_header" ></li>
  <li class="lineClassName" data-lineClassName="prj_resource_list_line" ></li>
  <li class="savingOnlyHeader" data-savingOnlyHeader="false" ></li>
  <li class="primary_column_id" data-primary_column_id="prj_resource_list_header_id" ></li>
  <li class="form_header_id" data-form_header_id="prj_resource_list_header" ></li>
  <li class="line_key_field" data-line_key_field="line_name" ></li>
  <li class="single_line" data-single_line="false" ></li>
  <li class="form_line_id" data-form_line_id="prj_resource_list_line" ></li>
 </ul>
 <ul id="js_contextMenu_data">
  <li class="docHedaderId" data-docHedaderId="prj_resource_list_header_id" ></li>
  <li class="docLineId" data-docLineId="prj_resource_list_line_id" ></li>
  <li class="btn1DivId" data-btn1DivId="prj_resource_list_header" ></li>
  <li class="btn2DivId" data-btn2DivId="form_line" ></li>
  <li class="tbodyClass" data-tbodyClass="form_data_line_tbody" ></li>
  <li class="noOfTabbs" data-noOfTabbs="2" ></li>
 </ul>
</div>