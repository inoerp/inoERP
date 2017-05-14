<!-- * 
inoERP
 *
 * @copyright   2014 Nishit R. Das
 * @license     https://www.mozilla.org/MPL/2.0/
 * @link        http://inoideas.org
 * @source code https://github.com/inoerp/inoERP
-->
<div id ="form_header"><span class="heading"><?php echo gettext('Project Event') ?></span>
 <form action=""  method="post" id="prj_event_header"  name="prj_event_header">
  <div id="tabsHeader">
   <ul class="tabMain">
    <li><a href="#tabsHeader-1"><?php echo gettext('Basic Info') ?></a></li>
    <li><a href="#tabsHeader-2"><?php echo gettext('Note') ?></a></li>
    <li><a href="#tabsHeader-3"><?php echo gettext('Attachments') ?></a></li>
   </ul>
   <div class="tabContainer">
    <div id="tabsHeader-1" class="tabContent">
     <ul class="column header_field">
      <li><?php $f->l_text_field_dr_withSearch('prj_event_header_id') ?>
       <a name="show" href="form.php?class_name=prj_event_header&<?php echo "mode=$mode"; ?>" class="show document_id prj_event_header_id"><i class="fa fa-refresh"></i></a> 
      </li>
      <li><?php 
       $f->l_val_field_d('project_number', 'prj_project_header', 'project_number', '' ,'select project_number');
       echo $f->hidden_field_withId('prj_project_header_id', $$class->prj_project_header_id);
       ?><i class="generic select_project_number select_popup clickable fa fa-search" data-class_name="prj_project_header"></i></li>
      <li><?php $f->l_text_field_dm('event_name'); ?></li>
      <li><?php $f->l_text_field_d('event_number'); ?></li>
      <li><?php $f->l_text_field_d('description'); ?></li> 
      <li><?php $f->l_text_field_d('billing_amount'); ?></li> 
      <li><?php $f->l_text_field_d('revenue_amount'); ?></li> 
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
        $reference_table = 'prj_event_header';
        $reference_id = $$class->prj_event_header_id;
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

<div id="form_line" class="form_line"><span class="heading"><?php echo gettext('Event Lines') ?></span>
 <form action=""  method="post" id="prj_event_line"  name="prj_event_line">
  <div id="tabsLine">
   <ul class="tabMain">
    <li><a href="#tabsLine-1"><?php echo gettext('Amounts') ?></a></li>
    <li><a href="#tabsLine-2"><?php echo gettext('References') ?></a></li>
   </ul>
   <div class="tabContainer">
    <div id="tabsLine-1" class="tabContent">
     <table class="form_line_data_table">
      <thead> 
       <tr>
        <th><?php echo gettext('Action') ?></th>
        <th><?php echo gettext('Line Id') ?></th>
        <th><?php echo gettext('Seq') ?>#</th>
        <th><?php echo gettext('Line No') ?></th>
        <th><?php echo gettext('Task') ?>#</th>
        <th><?php echo gettext('Event Type') ?></th>
        <th><?php echo gettext('Date') ?></th>
        <th><?php echo gettext('Currency') ?></th>
        <th><?php echo gettext('Billing Amount') ?></th>
        <th><?php echo gettext('Revenue Amount') ?></th>
       </tr>
      </thead>
      <tbody class="form_data_line_tbody">
       <?php
       $count = 0;
       foreach ($prj_event_line_object as $prj_event_line) {
        $$class_second->task_number = !empty($$class_second->prj_project_line_id) ? prj_project_line::find_by_id($$class_second->prj_project_line_id)->task_number : '';
        ?>         
        <tr class="prj_event_line<?php echo $count ?>">
         <td>
          <?php
          echo ino_inline_action($prj_event_line->prj_event_line_id, array('prj_event_header_id' => $prj_event_header->prj_event_header_id));
          ?>
         </td>
         <td><?php $f->seq_field_d($count) ?></td>
         <td><?php $f->text_field_wid2sr('prj_event_line_id', 'always_readonly'); ?></td>
         <td><?php $f->text_field_d2s('event_number', 'lines_number'); ?></td>
         <td><?php
          $f->val_field_wid2m('task_number', 'prj_project_all_v', 'task_number', '', 'select project_task_number');
          echo $f->hidden_field('prj_project_line_id', $$class_second->prj_project_line_id);
          echo $f->hidden_field_withCLass('prj_project_header_id', $$class->prj_project_header_id , 'popup_value');
          
          ?><i class="generic select_project_task_number select_popup clickable fa fa-search" data-class_name="prj_project_all_v"></i></td>
         <td><?php echo $f->select_field_from_object('event_type_id', prj_event_type::find_all(), 'prj_event_type_id', 'event_type', $$class_second->event_type_id, '', '', 1); ?></td>
         <td><?php echo $f->date_fieldAnyDay('event_date', $$class_second->event_date); ?></td>
         <td><?php echo $f->select_field_from_object('currency', option_header::currencies(), 'option_line_code', 'option_line_value', $$class_second->currency, '', '', 1); ?></td>
         <td><?php $f->text_field_d2('billing_amount'); ?></td>
         <td><?php $f->text_field_d2('revenue_amount'); ?></td>
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
        <th><?php echo gettext('Description') ?></th>
        <th><?php echo gettext('Is Billed ?')  ?></th>
        <th><?php echo gettext('Revenue Distributed ?') ?></th>
        <th><?php echo gettext('Reference Name') ?></th>
        <th><?php echo gettext('Reference Value') ?></th>
       </tr>
      </thead>
      <tbody class="form_data_line_tbody">
       <?php 
       $count = 0;
       foreach ($prj_event_line_object as $prj_event_line) {
        $$class_second->task_number = !empty($$class_second->prj_project_line_id) ? prj_project_line::find_by_id($$class_second->prj_project_line_id)->task_number : '';
        ?>         
        <tr class="prj_event_line<?php echo $count ?>">
         <td><?php $f->seq_field_d($count) ?></td>
         <td><?php $f->text_field_d2('description'); ?></td>
         <td><?php echo $f->checkBox_field('billed_cb', $$class_second->billed_cb,'','', 1) ?></td>
         <td><?php echo $f->checkBox_field('revenue_distributed_cb', $$class_second->revenue_distributed_cb,'','', 1) ?></td>
         <td><?php $f->text_field_wid2r('reference_key_name', 'always_readonly'); ?></td>
         <td><?php $f->text_field_wid2r('reference_key_value', 'always_readonly'); ?></td>
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
  <li class="headerClassName" data-headerClassName="prj_event_header" ></li>
  <li class="lineClassName" data-lineClassName="prj_event_line" ></li>
  <li class="savingOnlyHeader" data-savingOnlyHeader="false" ></li>
  <li class="primary_column_id" data-primary_column_id="prj_event_header_id" ></li>
  <li class="form_header_id" data-form_header_id="prj_event_header" ></li>
  <li class="line_key_field" data-line_key_field="line_name" ></li>
  <li class="single_line" data-single_line="false" ></li>
  <li class="form_line_id" data-form_line_id="prj_event_line" ></li>
 </ul>
 <ul id="js_contextMenu_data">
  <li class="docHedaderId" data-docHedaderId="prj_event_header_id" ></li>
  <li class="docLineId" data-docLineId="prj_event_line_id" ></li>
  <li class="btn1DivId" data-btn1DivId="prj_event_header" ></li>
  <li class="btn2DivId" data-btn2DivId="form_line" ></li>
  <li class="tbodyClass" data-tbodyClass="form_data_line_tbody" ></li>
  <li class="noOfTabbs" data-noOfTabbs="2" ></li>
 </ul>
</div>