<!-- * 
inoERP
 *
 * @copyright   2014 Nishit R. Das
 * @license     https://www.mozilla.org/MPL/2.0/
 * @link        http://inoideas.org
 * @source code https://github.com/inoerp/inoERP
-->
<div id ="form_header"><span class="heading"><?php      echo gettext('Specification')   ?></span>
 <form method="post" id="qa_specification_header"  name="qa_specification_header">
  <div id="tabsHeader">
   <ul class="tabMain">
    <li><a href="#tabsHeader-1"><?php echo gettext('Basic Info') ?></a></li>
    <li><a href="#tabsHeader-2"><?php echo gettext('Note') ?></a></li>
    <li><a href="#tabsHeader-3"><?php echo gettext('Attachments') ?></a></li>
   </ul>
   <div class="tabContainer">
    <div id="tabsHeader-1" class="tabContent">
     <ul class="column header_field">
      <li><?php $f->l_text_field_dr_withSearch('qa_specification_header_id') ?>
       <a name="show" href="form.php?class_name=qa_specification_header&<?php echo "mode=$mode"; ?>" class="show document_id qa_specification_header_id"><i class="fa fa-refresh"></i></a> 
      </li>
      <li><?php $f->l_text_field_dr('specification_name'); ?></li>
      <li><?php $f->l_text_field_d('description'); ?></li> 
      <li><?php $f->l_date_fieldAnyDay('effective_from', $$class->effective_from); ?></li> 
      <li><?php $f->l_date_fieldAnyDay('effective_to', $$class->effective_to); ?></li> 
      <li><?php
       echo $f->hidden_field_withId('item_id_m', $$class->item_id_m);
       echo $f->l_val_field_d('item_number', 'item', 'item_number', 'org_id', 'vf_select_item_number');
       ?>
       <i class="generic g_select_item_number select_popup clickable fa fa-search" data-class_name="item"></i>
      </li>
      <li><?php
       echo $f->l_val_field_dm('customer_name', 'ar_customer', 'customer_name', '', 'customer_name', 'vf_select_customer_name');
       echo $f->hidden_field_withId('ar_customer_id', $$class->ar_customer_id);
       ?><i class="generic g_select_customer_name select_popup clickable fa fa-search" data-class_name="ar_customer"></i></li>
      <li><?php
       echo $f->l_val_field_dm('supplier_name', 'supplier', 'supplier_name', '', 'supplier_name', 'vf_select_supplier_name');
       echo $f->hidden_field_withId('supplier_id', $$class->supplier_id);
       ?><i class="generic g_select_supplier_name select_popup clickable fa fa-search" data-class_name="supplier"></i></li>
      <li><?php $f->l_status_field_d('status'); ?></li> 
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
        $reference_table = 'qa_specification_header';
        $reference_id = $$class->qa_specification_header_id;
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

<div id="form_line" class="form_line"><span class="heading"><?php echo gettext('Specification Lines') ?></span>
 <form action=""  method="post" id="qa_specification_line"  name="qa_specification_line">
  <div id="tabsLine">
   <ul class="tabMain">
    <li><a href="#tabsLine-1"><?php echo gettext('Amounts') ?></a></li>
    <li><a href="#tabsLine-2"><?php echo gettext('Targets') ?></a></li>
   </ul>
   <div class="tabContainer">
    <div id="tabsLine-1" class="tabContent">
     <table class="form_line_data_table">
      <thead> 
       <tr>
        <th><?php echo gettext('Action') ?></th>
        <th><?php echo gettext('Sequence') ?></th>
        <th><?php echo gettext('Line Id') ?></th>
        <th><?php echo gettext('uom_id') ?></th>
        <th><?php echo gettext('User Low') ?>#</th>
        <th><?php echo gettext('User High') ?></th>
        <th><?php echo gettext('Spec Low') ?></th>
        <th><?php echo gettext('Spec High') ?></th>
        <th><?php echo gettext('Reasonable Low') ?></th>
        <th><?php echo gettext('Reasonable High') ?></th>

       </tr>
      </thead>
      <tbody class="form_data_line_tbody">
       <?php
       $count = 0;
       foreach ($qa_specification_line_object as $qa_specification_line) {
        $$class_second->task_number = !empty($$class_second->prj_project_line_id) ? prj_project_line::find_by_id($$class_second->prj_project_line_id)->task_number : '';
        ?>         
        <tr class="qa_specification_line<?php echo $count ?>">
         <td>
          <?php
          echo ino_inline_action($qa_specification_line->qa_specification_line_id, array('qa_specification_header_id' => $qa_specification_header->qa_specification_header_id));
          ?>
         </td>
         <td><?php $f->seq_field_d($count); ?></td>
         <td><?php $f->text_field_wid2sr('qa_specification_line_id', 'always_readonly dontCopy line_id'); ?></td>
         <td><?php echo $f->select_field_from_object('uom_id', uom::find_all(), 'uom_id', 'uom_name', $$class_second->uom_id, '', 'small'); ?></td>
         <td><?php $f->text_field_wid2('user_range_low'); ?></td>
         <td><?php $f->text_field_wid2('user_range_high'); ?></td>
         <td><?php $f->text_field_wid2('specification_range_low'); ?></td>
         <td><?php $f->text_field_wid2('specification_range_high'); ?></td>
         <td><?php $f->text_field_wid2('reasonable_range_low'); ?></td>
         <td><?php $f->text_field_wid2('reasonable_range_high'); ?></td>
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
        <th><?php echo gettext('user_target_value') ?></th>
        <th><?php echo gettext('specification_target_value') ?>#</th>
        <th><?php echo gettext('reasonable_target_value') ?></th>
       </tr>
      </thead>
      <tbody class="form_data_line_tbody">
       <?php
       $count = 0;
       foreach ($qa_specification_line_object as $qa_specification_line) {
        $$class_second->task_number = !empty($$class_second->prj_project_line_id) ? prj_project_line::find_by_id($$class_second->prj_project_line_id)->task_number : '';
        ?>         
        <tr class="qa_specification_line<?php echo $count ?>">
         <td><?php $f->seq_field_d($count); ?></td>
         <td><?php $f->text_field_wid2('user_target_value'); ?></td>
         <td><?php $f->text_field_wid2('specification_target_value'); ?></td>
         <td><?php $f->text_field_wid2('reasonable_target_value'); ?></td>
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
  <li class="headerClassName" data-headerClassName="qa_specification_header" ></li>
  <li class="lineClassName" data-lineClassName="qa_specification_line" ></li>
  <li class="savingOnlyHeader" data-savingOnlyHeader="false" ></li>
  <li class="primary_column_id" data-primary_column_id="qa_specification_header_id" ></li>
  <li class="form_header_id" data-form_header_id="qa_specification_header" ></li>
  <li class="line_key_field" data-line_key_field="line_name" ></li>
  <li class="single_line" data-single_line="false" ></li>
  <li class="form_line_id" data-form_line_id="qa_specification_line" ></li>
 </ul>
 <ul id="js_contextMenu_data">
  <li class="docHedaderId" data-docHedaderId="qa_specification_header_id" ></li>
  <li class="docLineId" data-docLineId="qa_specification_line_id" ></li>
  <li class="btn1DivId" data-btn1DivId="qa_specification_header" ></li>
  <li class="btn2DivId" data-btn2DivId="form_line" ></li>
  <li class="tbodyClass" data-tbodyClass="form_data_line_tbody" ></li>
  <li class="noOfTabbs" data-noOfTabbs="2" ></li>
 </ul>
</div>