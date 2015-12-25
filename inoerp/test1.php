<div id ="form_header"><span class="heading"><?php echo gettext('Expense Claim') ?></span>
 <form action=""  method="post" id="so_header"  name="so_header">
  <div id="tabsHeader">
   <ul class="tabMain">
    <li><a href="#tabsHeader-1"><?php echo gettext('Basic Info') ?></a></li>
    <li><a href="#tabsHeader-2"><?php echo gettext('Approval') ?></a></li>
    <li><a href="#tabsHeader-3"><?php echo gettext('Attachments') ?></a></li>
    <li><a href="#tabsHeader-4"><?php echo gettext('Notes') ?></a></li>
   </ul>
   <div class="tabContainer">
    <div id="tabsHeader-1" class="tabContent">
     <div class="large_shadow_box"> 
      <ul class="column header_field">
       <li><?php $f->l_text_field_dr_withSearch('hr_expense_header_id') ?>
        <a name="show" href="form.php?class_name=hr_expense_header&<?php echo "mode=$mode"; ?>" class="show document_id hr_expense_header_id">
         <i class="fa fa-refresh"></i></a> 
       </li>
       <li><?php
        echo $f->l_val_field_d('employee_name', 'hr_employee_v', 'employee_name', '', 'vf_select_employee_name employee_name');
        echo $f->hidden_field_withId('employee_id', $$class->employee_id);
        ?><i class="generic g_select_employee_name select_popup clickable fa fa-search" data-class_name="hr_employee_v"></i></li>
       <li><?php $f->l_text_field_dr('identification_id'); ?>  </li>						 
       <li><?php $f->l_date_fieldAnyDay_m('claim_date', $$class->claim_date); ?>             </li>
       <li><?php echo $f->text_field_d('expense_template_id'); ?>             </li>
       <li><?php $f->l_select_field_from_object('doc_currency', option_header::currencies(), 'option_line_code', 'option_line_code', $$class->doc_currency, 'doc_currency', '', 1, $readonly); ?></li>
       <li><?php $f->l_select_field_from_object('department_id', sys_value_group_line::find_by_parent_id('3'), 'sys_value_group_line_id', array('code', 'description'), $$class->department_id, 'department_id', 'medium'); ?> </li>
       <li><?php echo $f->text_field_dr('status'); ?>             </li>
      </ul>
     </div>
    </div>
    <div id="tabsHeader-2" class="tabContent">
     <div> 
      <ul class="column header_field">
       <li><?php
        echo $f->l_val_field_d('employee_name', 'hr_employee_v', 'employee_name', '', 'vf_select_employee_name employee_name');
        echo $f->hidden_field_withCLass('approved_by_employee_id', $$class->approved_by_employee_id, 'employee_id');
        ?><i class="generic g_select_employee_name select_popup clickable fa fa-search" data-class_name="hr_employee_v"></i></li>
       <li><?php echo $f->text_field_d('purpose'); ?>             </li>
       <li><?php echo $f->text_field_d('reason'); ?>             </li>
       <li><?php $f->l_date_fieldAnyDay_m('approved_date', $$class->approved_date, 'always_readonly'); ?>             </li>
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
        $reference_table = 'hr_expense_header';
        $reference_id = $$class->hr_expense_header_id;
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

<div id="form_line" class="form_line"><span class="heading"><?php echo gettext('Expense Lines') ?></span>
 <form method="post" id="hr_expense_line"  name="hr_expense_line">
  <div id="accordion0" class="accordion">
   <h3><i class="fa fa-minus-circle"></i> <?php echo gettext('Receipt Expense') ?></h3>
   <div>
    <table class="form_line_data_table">
     <thead> 
      <tr>
       <th><?php echo gettext('Action') ?></th>
       <th><?php echo gettext('Line') ?>#</th>
       <th><?php echo gettext('Expense Type') ?></th>
       <th><?php echo gettext('Date') ?></th>
       <th><?php echo gettext('Amount') ?></th>
       <th><?php echo gettext('Purpose') ?></th>
       <th><?php echo gettext('Exchange') ?></th>
       <th><?php echo gettext('Vendor') ?></th>
       <th><?php echo gettext('Vendor Details') ?></th>
      </tr>
     </thead>
     <tbody class="form_data_line_tbody">
      <?php
      $count = 0;
      foreach ($hr_expense_line_object as $hr_expense_line) {
       ?>         
       <tr class="hr_expense_line<?php echo $count ?>">
        <td>
         <?php
         echo ino_inline_action($$class_second->hr_expense_line_id, array('hr_expense_header_id' => $$class->hr_expense_header_id));
         ?>
        </td>
        <td><?php echo form::text_field('line_number', $$class_second->line_number, '8', '20', 1, 'Auto no', '', $readonly, 'lines_number'); ?></td>
        <td><?php form::text_field_wid2s('expense_type'); ?></td>
        <td><?php echo $f->date_fieldAnyDay('expense_date', $$class_second->expense_date); ?></td>
        <td><?php form::number_field_wid2s('receipt_amount'); ?></td>
        <td><?php $f->text_field_wid2('purpose'); ?></td>
        <td><?php form::number_field_wid2s('exchange_rate'); ?></td>
        <td><?php form::text_field_wid2('vendor_name'); ?></td>
        <td><?php form::text_field_wid2('vendor_details'); ?></td>
       </tr>
       <?php
       $count = $count + 1;
      }
      ?>
     </tbody>
    </table>
   </div>

   <h3><i class="fa fa-minus-circle"></i> <?php echo gettext('Per Diem') ?></h3>
   <div>
    <table class="form_line_data_table">
     <thead> 
      <tr>
       <th><?php echo gettext('Action') ?></th>
       <th><?php echo gettext('Line') ?>#</th>
       <th><?php echo gettext('Expense Type') ?></th>
       <th><?php echo gettext('Date') ?></th>
       <th><?php echo gettext('Receipt Amount') ?></th>
       <th><?php echo gettext('Purpose') ?></th>
       <th><?php echo gettext('Exchange') ?></th>
       <th><?php echo gettext('Vendor') ?></th>
       <th><?php echo gettext('Vendor Details') ?></th>
      </tr>
     </thead>
     <tbody class="form_data_line_tbody2">
      <?php
      foreach ($hr_expense_line_object as $hr_expense_line) {
       ?>         
       <tr class="hr_expense_line<?php echo $count ?>">
        <td>
         <?php
         echo ino_inline_action($$class_second->hr_expense_line_id, array('hr_expense_header_id' => $$class->hr_expense_header_id));
         ?>
        </td>
        <td><?php echo form::text_field('line_number', $$class_second->line_number, '8', '20', 1, 'Auto no', '', $readonly, 'lines_number'); ?></td>
        <td><?php form::text_field_wid2('expense_type'); ?></td>
        <td><?php echo $f->date_fieldAnyDay('expense_date', $$class_second->expense_date); ?></td>
        <td><?php form::number_field_wid2('receipt_amount'); ?></td>
        <td><?php $f->text_field_wid2('purpose'); ?></td>
        <td><?php form::number_field_wid2('exchange_rate'); ?></td>
        <td><?php form::text_field_wid2('vendor_name'); ?></td>
        <td><?php form::text_field_wid2('vendor_details'); ?></td>
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
</div>
<div id="js_data">
 <ul id="js_saving_data">
  <li class="headerClassName" data-headerClassName="hr_expense_header" ></li>
  <li class="lineClassName" data-lineClassName="hr_expense_line" ></li>
  <li class="savingOnlyHeader" data-savingOnlyHeader="false" ></li>
  <li class="primary_column_id" data-primary_column_id="hr_expense_header_id" ></li>
  <li class="form_header_id" data-form_header_id="hr_expense_header" ></li>
  <li class="line_key_field" data-line_key_field="line_number" ></li>
  <li class="single_line" data-single_line="true" ></li>
  <li class="form_line_id" data-form_line_id="hr_expense_line" ></li>
 </ul>
 <ul id="js_contextMenu_data">
  <li class="docHedaderId" data-docHedaderId="hr_expense_header_id" ></li>
  <li class="docLineId" data-docLineId="hr_expense_line_id" ></li>
  <li class="btn1DivId" data-btn1DivId="hr_expense_header" ></li>
  <li class="btn2DivId" data-btn2DivId="form_line" ></li>
  <li class="tbodyClass" data-tbodyClass="form_data_line_tbody" ></li>
  <li class="noOfTabbs" data-noOfTabbs="1" ></li>
 </ul>
</div>
