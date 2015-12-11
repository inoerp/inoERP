<!-- * 
inoERP
 *
 * @copyright   2014 Nishit R. Das
 * @license     https://www.mozilla.org/MPL/2.0/
 * @link        http://inoideas.org
 * @source code https://github.com/inoerp/inoERP
-->
<div id ="form_header"><span class="heading"><?php   echo gettext('Project Agreements')   ?></span>
 <form method="post" id="prj_agreement_header"  name="prj_agreement_header">
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
      <li><?php $f->l_text_field_dr_withSearch('prj_agreement_header_id') ?>
       <a name="show" href="form.php?class_name=prj_agreement_header&<?php echo "mode=$mode"; ?>" class="show document_id prj_agreement_header_id"><i class="fa fa-refresh"></i></a> 
      </li>
      <li><?php $f->l_text_field_d('agreement_number'); ?></li>
      <li><?php $f->l_text_field_d('agreement_type'); ?></li>
      <li><?php $f->l_select_field_from_object('bu_org_id', org::find_all_business(), 'org_id', 'org', $$class->bu_org_id, 'bu_org_id', $readonly1, '', ''); ?>						 </li>
      <li><label class="auto_complete"><?php echo gettext('Customer Name') ?></label><?php
       echo $f->hidden_field_withId('ar_customer_id', $$class->ar_customer_id);
       echo $f->text_field('customer_name', $$class->customer_name, '20', 'customer_name', 'select_customer_name', '', $readonly1);
       ?>
       <i class="ar_customer_id select_popup clickable fa fa-search"></i></li>
      <li><label class="auto_complete"><?php echo gettext('Customer Number') ?></label><?php $f->text_field_d('customer_number'); ?></li>
      <li><?php $f->l_select_field_from_object('ar_customer_site_id', $customer_site_obj, 'ar_customer_site_id', 'customer_site_name', $$class->ar_customer_site_id, 'ar_customer_site_id', 'ar_customer_site_id', '', $readonly1); ?> </li>
      <li><?php $f->l_number_field_dm('header_amount'); ?></li> 
      <li><label><?php echo gettext('Admin') ?></label><?php $f->text_field_d('admin_employee_name', 'employee_name'); ?>
       <?php echo $f->hidden_field_withId('admin_employee_id', $$class->admin_employee_id); ?>
       <i class="select_employee_name select_popup clickable fa fa-search"></i>
      </li>
      <li><?php $f->l_text_field_d('description'); ?></li> 
      <li><?php $f->l_date_fieldAnyDay('start_date', $$class->start_date); ?></li> 
      <li><?php $f->l_date_fieldAnyDay('end_date', $$class->end_date); ?></li> 
     </ul>
    </div>
    <div id="tabsHeader-2" class="tabContent">
     <ul class="column header_field">
      <li><?php $f->l_select_field_from_object('doc_currency', option_header::currencies(), 'option_line_code', 'option_line_code', $$class->doc_currency, 'doc_currency', '', 1, $readonly); ?></li>
      <li><?php $f->l_select_field_from_object('currency', option_header::currencies(), 'option_line_code', 'option_line_code', $$class->currency, 'currency', '', 1, 1); ?></li>
      <li><?php $f->l_select_field_from_object('exchange_rate_type', gl_currency_conversion::currency_conversion_type(), 'option_line_code', 'option_line_code', $$class->exchange_rate_type, 'exchange_rate_type', '', 1, $readonly); ?></li>
      <li><?php $f->l_number_field('exchange_rate', $$class->exchange_rate, '', 'exchange_rate'); ?> </li>
      <li><?php $f->l_checkBox_field_d('r_hard_limt_cb'); ?></li> 
      <li><?php $f->l_checkBox_field_d('i_hard_limt_cb'); ?></li> 
      <li><?php $f->l_checkBox_field_d('advanced_required_cb'); ?></li> 
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
        $reference_table = 'prj_agreement_header';
        $reference_id = $$class->prj_agreement_header_id;
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

<div id="form_line" class="form_line"><span class="heading"><?php echo gettext('Funding Details') ?></span>
 <form   method="post" id="prj_agreement_line"  name="prj_agreement_line">
  <div id="tabsLine">
   <ul class="tabMain">
    <li><a href="#tabsLine-1"><?php echo gettext('Basic') ?></a></li>
   </ul>
   <div class="tabContainer">
    <div id="tabsLine-1" class="tabContent">
     <table class="form_line_data_table">
      <thead> 
       <tr>
        <th><?php echo gettext('Action') ?></th>
        <th><?php echo gettext('Line Id') ?></th>
        <th><?php echo gettext('Project') ?></th>
        <!--<th><?php // echo gettext('Task') ?></th>-->
        <th><?php echo gettext('Allocation Date') ?></th>
        <th><?php echo gettext('Amount') ?></th>
        <th><?php echo gettext('Description') ?></th>
        <th><?php echo gettext('Classification') ?></th>
       </tr>
      </thead>
      <tbody class="form_data_line_tbody">
       <?php
       $count = 0;
       foreach ($prj_agreement_line_object as $prj_agreement_line) {
        $$class_second->project_number = !empty($$class_second->prj_project_header_id) ? prj_project_header::find_by_id($$class_second->prj_project_header_id)->project_number : '';
        ?>         
        <tr class="prj_agreement_line<?php echo $count ?>">
         <td>
          <?php
          echo ino_inline_action($prj_agreement_line->prj_agreement_line_id, array('prj_agreement_header_id' => $prj_agreement_header->prj_agreement_header_id));
          ?>
         </td>
         <td><?php $f->text_field_d2sr('prj_agreement_line_id'); ?></td>
         <td><?php
          $f->val_field_wid2m('project_number', 'prj_project_header' , 'project_number' ,  '','select project_number');
          echo $f->hidden_field('prj_project_header_id', $$class_second->prj_project_header_id);
          ?><i class="generic select_project_number select_popup clickable fa fa-search" data-class_name="prj_project_header"></i></td>
<!--         <td><?php
//          $f->text_field_wid2('task_number', 'select project_number');
//          echo $f->hidden_field('prj_project_line_id', $$class_second->prj_project_line_id);
          ?><i class="select_project_number select_popup clickable fa fa-search"></i></td>-->
         <td><?php echo $f->date_fieldAnyDay('allocation_date', $$class_second->allocation_date); ?></td>
         <td><?php $f->text_field_d2('allocation_amount'); ?></td>
         <td><?php $f->text_field_d2('classification'); ?></td>
         <td><?php $f->text_field_d2('description'); ?></td>
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
  <li class="headerClassName" data-headerClassName="prj_agreement_header" ></li>
  <li class="lineClassName" data-lineClassName="prj_agreement_line" ></li>
  <li class="savingOnlyHeader" data-savingOnlyHeader="false" ></li>
  <li class="primary_column_id" data-primary_column_id="prj_agreement_header_id" ></li>
  <li class="form_header_id" data-form_header_id="prj_agreement_header" ></li>
  <li class="line_key_field" data-line_key_field="line_name" ></li>
  <li class="single_line" data-single_line="false" ></li>
  <li class="form_line_id" data-form_line_id="prj_agreement_line" ></li>
 </ul>
 <ul id="js_contextMenu_data">
  <li class="docHedaderId" data-docHedaderId="prj_agreement_header_id" ></li>
  <li class="docLineId" data-docLineId="prj_agreement_line_id" ></li>
  <li class="btn1DivId" data-btn1DivId="prj_agreement_header" ></li>
  <li class="btn2DivId" data-btn2DivId="form_line" ></li>
  <li class="tbodyClass" data-tbodyClass="form_data_line_tbody" ></li>
  <li class="noOfTabbs" data-noOfTabbs="1" ></li>
 </ul>
</div>