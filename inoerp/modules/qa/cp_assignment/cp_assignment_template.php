<!-- * 
inoERP
 *
 * @copyright   2014 Nishit R. Das
 * @license     https://www.mozilla.org/MPL/2.0/
 * @link        http://inoideas.org
 * @source code https://github.com/inoerp/inoERP
-->
<div id ="form_header"><span class="heading"><?php echo gettext('Collection Plan Assignment') ?></span>
 <form method="post" id="qa_cp_assignment_header"  name="qa_cp_assignment_header">
  <div id="tabsHeader">
   <ul class="tabMain">
    <li><a href="#tabsHeader-1"><?php echo gettext('Basic Info') ?></a></li>
    <li><a href="#tabsHeader-2"><?php echo gettext('Note') ?></a></li>
    <li><a href="#tabsHeader-3"><?php echo gettext('Attachments') ?></a></li>
   </ul>
   <div class="tabContainer">
    <div id="tabsHeader-1" class="tabContent">
     <ul class="column header_field">
      <li><?php $f->l_text_field_dr_withSearch('qa_cp_assignment_header_id') ?>
       <a name="show" href="form.php?class_name=qa_cp_assignment_header&<?php echo "mode=$mode"; ?>" class="show document_id qa_cp_assignment_header_id"><i class="fa fa-refresh"></i></a> 
      </li>
      <li><?php $f->l_select_field_from_object('qa_cp_header_id', qa_cp_header::find_all(), 'qa_cp_header_id', 'plan_name', $$class->qa_cp_header_id, 'qa_cp_header_id'); ?></li> 
      <li><?php $f->l_select_field_from_object('inv_transaction_id', transaction_type::find_all(), 'transaction_type_id', 'transaction_type', $$class->inv_transaction_id, 'inv_transaction_id'); ?></li> 
      <li><?php $f->l_text_field_d('description'); ?></li> 
      <li><?php $f->l_date_fieldAnyDay('effective_from', $$class->effective_from); ?></li> 
      <li><?php $f->l_date_fieldAnyDay('effective_to', $$class->effective_to); ?></li> 
      <li><?php $f->l_checkBox_field_d('enabled_cb'); ?></li> 
      <li><?php $f->l_checkBox_field_d('mandatory_cb'); ?></li> 
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
        $reference_table = 'qa_cp_assignment_header';
        $reference_id = $$class->qa_cp_assignment_header_id;
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

<div id="form_line" class="form_line"><span class="heading"><?php echo gettext('Transaction Triggers') ?></span>
 <form  method="post" id="qa_cp_assignment_line"  name="qa_cp_assignment_line">
  <div id="tabsLine">
   <ul class="tabMain">
    <li><a href="#tabsLine-1"><?php echo gettext('Amounts') ?></a></li>
   </ul>
   <div class="tabContainer">
    <div id="tabsLine-1" class="tabContent">
     <table class="form_line_data_table">
      <thead> 
       <tr>
        <th><?php echo gettext('Action') ?></th>
        <th><?php echo gettext('Line Id') ?></th>
        <th><?php echo gettext('Trigger Name') ?></th>
        <th><?php echo gettext('Condition') ?></th>
        <th><?php echo gettext('From') ?></th>
        <th><?php echo gettext('To') ?></th>
       </tr>
      </thead>
      <tbody class="form_data_line_tbody">
       <?php
       $count = 0;
       foreach ($qa_cp_assignment_line_object as $qa_cp_assignment_line) {
        ?>         
        <tr class="qa_cp_assignment_line<?php echo $count ?>">
         <td>
          <?php
          echo ino_inline_action($qa_cp_assignment_line->qa_cp_assignment_line_id, array('qa_cp_assignment_header_id' => $qa_cp_assignment_header->qa_cp_assignment_header_id,
           'qa_cp_header_id' => $qa_cp_assignment_header->qa_cp_header_id));
          ?>
         </td>
         <td><?php $f->text_field_wid2sr('qa_cp_assignment_line_id', 'always_readonly dontCopy line_id'); ?></td>
         <td><?php echo $f->select_field_from_object('trigger_name', option_header::find_options_byName('QA_COLLECTION_TRIGGER'), 'option_line_code', 'option_line_value', $$class_second->trigger_name, '', '', 1); ?></td> 
         <td><?php echo $f->select_field_from_array('trigger_condition', dbObject::$control_type_a, $$class_second->trigger_condition, 1); ?></td>
         <td><?php $f->text_field_wid2('value_from'); ?></td>
         <td><?php $f->text_field_wid2('value_to'); ?></td>

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
  <li class="headerClassName" data-headerClassName="qa_cp_assignment_header" ></li>
  <li class="lineClassName" data-lineClassName="qa_cp_assignment_line" ></li>
  <li class="savingOnlyHeader" data-savingOnlyHeader="false" ></li>
  <li class="primary_column_id" data-primary_column_id="qa_cp_assignment_header_id" ></li>
  <li class="form_header_id" data-form_header_id="qa_cp_assignment_header" ></li>
  <li class="line_key_field" data-line_key_field="line_name" ></li>
  <li class="single_line" data-single_line="false" ></li>
  <li class="form_line_id" data-form_line_id="qa_cp_assignment_line" ></li>
 </ul>
 <ul id="js_contextMenu_data">
  <li class="docHedaderId" data-docHedaderId="qa_cp_assignment_header_id" ></li>
  <li class="docLineId" data-docLineId="qa_cp_assignment_line_id" ></li>
  <li class="btn1DivId" data-btn1DivId="qa_cp_assignment_header" ></li>
  <li class="btn2DivId" data-btn2DivId="form_line" ></li>
  <li class="tbodyClass" data-tbodyClass="form_data_line_tbody" ></li>
  <li class="noOfTabbs" data-noOfTabbs="1" ></li>
 </ul>
</div>