<!-- * 
inoERP
 *
 * @copyright   2014 Nishit R. Das
 * @license     https://www.mozilla.org/MPL/2.0/
 * @link        http://inoideas.org
 * @source code https://github.com/inoerp/inoERP
-->

<div id ="form_header"><span class="heading"><?php echo gettext('Expense Claim') ?></span>
 <form method="post" id="hr_expense_header"  name="hr_expense_header">
  <div id="tabsHeader">
   <ul class="tabMain">
    <li><a href="#tabsHeader-1"><?php echo gettext('Basic Info') ?></a></li>
    <li><a href="#tabsHeader-2"><?php echo gettext('Finance') ?></a></li>
    <li><a href="#tabsHeader-3"><?php echo gettext('Notes') ?></a></li>
    <li><a href="#tabsHeader-4"><?php echo gettext('Attachments') ?></a></li>
    <li><a href="#tabsHeader-5"><?php echo gettext('Action') ?></a></li>
   </ul>
   <div class="tabContainer">
    <div id="tabsHeader-1" class="tabContent">
     <div class="large_shadow_box"> 
      <ul class="column header_field">
       <li><?php    $f->l_text_field_dr_withSearch('hr_expense_header_id')  ?>
        <a name="show" href="form.php?class_name=hr_expense_header&<?php echo "mode=$mode"; ?>" class="show document_id hr_expense_header_id">
         <i class="fa fa-refresh"></i></a> 
       </li>
       <li><?php $f->l_select_field_from_object('bu_org_id', org::find_all_business(), 'org_id', 'org', $$class->bu_org_id, 'bu_org_id', '', 1, $readonly1); ?>        </li>
       <li><?php $f->l_text_field_d('claim_number'); ?>             </li>
       <li><?php
        echo $f->l_val_field_d('employee_name', 'hr_employee_v', 'employee_name', '', 'vf_select_employee_name employee_name');
        echo $f->hidden_field_withCLass('hr_employee_id', $$class->hr_employee_id, 'hr_employee_id claim_emplyee_id');
        ?><i class="generic g_select_employee_name select_popup clickable fa fa-search" data-class_name="hr_employee_v"></i></li>
       <li><?php $f->l_text_field_dr('identification_id'); ?>  </li>						 
       <li><?php $f->l_date_fieldAnyDay_m('claim_date', $$class->claim_date); ?>             </li>
       <li><?php $f->l_select_field_from_object('expense_template_id', hr_expense_tpl_header::find_all(), 'hr_expense_tpl_header_id', 'template_name', $$class->expense_template_id, 'expense_template_id', '', 1); ?>             </li>
       <li><?php $f->l_select_field_from_object('department_id', sys_value_group_line::find_by_parent_id('3'), 'sys_value_group_line_id', array('code', 'description'), $$class->department_id, 'department_id', 'medium', 1); ?> </li>
       <li><?php $f->l_text_field_dr('status'); ?>             </li>
      </ul>
     </div>
    </div>
    <div id="tabsHeader-2" class="tabContent">
     <div> 
      <ul class="column header_field">
       <li><?php $f->l_select_field_from_object('doc_currency', option_header::currencies(), 'option_line_code', 'option_line_code', $$class->doc_currency, 'doc_currency', '', 1, $readonly); ?></li>
       <li><?php $f->l_select_field_from_object('currency', option_header::currencies(), 'option_line_code', 'option_line_code', $$class->currency, 'currency', 'currency always_readonly', 1, 1); ?></li>
       <li><?php $f->l_select_field_from_object('exchange_rate_type', gl_currency_conversion::currency_conversion_type(), 'option_line_code', 'option_line_code', $$class->exchange_rate_type, 'exchange_rate_type', '', 1, $readonly); ?></li>
       <li><?php $f->l_number_field('exchange_rate', $$class->exchange_rate, '', 'exchange_rate', '', 1, $readonly); ?> </li>
       <li><?php $f->l_number_field_dr('header_amount', 'always_readonly'); ?></li>
       <li><?php
        echo $f->l_val_field_d('approver_employee_name', 'hr_employee_v', 'employee_name', '', 'vf_select_employee_name employee_name');
        echo $f->hidden_field_withCLass('approved_by_employee_id', $$class->approved_by_employee_id, 'hr_employee_id');
        ?><i class="generic g_select_employee_name select_popup clickable fa fa-search" data-class_name="hr_employee_v"></i></li>
       <li><?php $f->l_text_field_d('purpose'); ?>             </li>
       <li><?php $f->l_text_field_d('reason'); ?>             </li>
       <li><?php $f->l_date_fieldAnyDay_r('approved_date', $$class->approved_date, 'always_readonly'); ?>             </li>
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
    <div id="tabsHeader-5" class="tabContent">
     <ul class="column header_field">
      <li><label>Action</label>
       <?php
       echo $f->select_field_from_array('action', $$class->action_a, '', 'action', '', '', $readonly, $action_readonly)
       ?>
      </li>
     </ul>

    </div>

   </div>
  </div>
 </form>
</div>

<div id="form_line" class="form_line"><span class="heading"><?php echo gettext('Expense Lines') ?></span>
 <form method="post" id="hr_expense_line"  name="hr_expense_line">
  <div id="tabsLine">
   <ul class="tabMain">
    <li><a href="#tabsLine-1"><?php echo gettext('Receipt') ?></a></li>
    <li><a href="#tabsLine-2"><?php echo gettext('Per Diem & Mileage') ?></a></li>
   </ul>
   <div class="tabContainer">
    <div id="tabsLine-1" class="tabContent">
     <table class="form_line_data_table">
      <thead> 
       <tr>
        <th><?php echo gettext('Action') ?></th>
        <th><?php echo gettext('Seq') ?>#</th>
        <th><?php echo gettext('Line Id') ?></th>
        <th><?php echo gettext('Line') ?>#</th>
        <th><?php echo gettext('Expense Type') ?></th>
        <th><?php echo gettext('Date') ?></th>
        <th><?php echo gettext('Currency') ?></th>
        <th><?php echo gettext('Receipt Amount') ?></th>
        <th><?php echo gettext('Purpose') ?></th>
        <th><?php echo gettext('Exchange') ?></th>
        <th><?php echo gettext('Vendor') ?></th>
        <!--<th><?php // echo gettext('Vendor Details')      ?></th>-->

       </tr>
      </thead>
      <tbody class="form_data_line_tbody">
       <?php
       $count = 0;
       foreach ($hr_expense_line_object as $hr_expense_line) {
        if (!empty($_GET['copydoc']) && $_GET['copydoc'] == 1) {
         $hr_expense_line->hr_expense_line_id = null;
        }
        ?>         
        <tr class="hr_expense_line<?php echo $count ?>">
         <td>
          <?php
          echo ino_inline_action($$class_second->hr_expense_line_id, array('hr_expense_header_id' => $$class->hr_expense_header_id));
          ?>
         </td>
         <td><?php $f->seq_field_d($count); ?></td>
         <td><?php $f->text_field_wid2s('hr_expense_line_id', 'always_readonly dontCopy'); ?></td>
         <td><?php $f->text_field_wid2s('line_number', 'lines_number'); ?></td>
         <td><?php echo $f->select_field_from_object('expense_type', hr_expense_tpl_line::find_by_parent_id($$class->expense_template_id), 'hr_expense_tpl_line_id', 'expense_item', $$class_second->expense_type, '', '', 1, '', '', '', '', 'expense_category'); ?></td>
         <td><?php echo $f->date_fieldAnyDay('claim_date', $$class_second->claim_date); ?></td>
         <td><?php echo $f->select_field_from_object('receipt_currency', option_header::currencies(), 'option_line_code', 'option_line_code', $$class->currency); ?></td>
         <td><?php form::number_field_wid2s('receipt_amount'); ?></td>
         <td><?php $f->text_field_wid2('purpose'); ?></td>
         <td><?php form::number_field_wid2s('exchange_rate'); ?></td>
         <td><?php form::text_field_wid2('vendor_name'); ?></td>
         <!--<td><?php // form::text_field_wid2('vendor_details');      ?></td>-->

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
        <th><?php echo gettext('Location') ?></th>
        <th><?php echo gettext('Daily Rate') ?></th>
        <th><?php echo gettext('No Of Days') ?></th>
        <th><?php echo gettext('Mileage UOM') ?></th>
        <th><?php echo gettext('Distance') ?></th>
        <th><?php echo gettext('Mileage Rate') ?></th>
        <th><?php echo gettext('Receipt Missing') ?></th>
        <th><?php echo gettext('Status') ?></th>
       </tr>
      </thead>
      <tbody class="form_data_line_tbody">
       <?php
       $count = 0;
       foreach ($hr_expense_line_object as $hr_expense_line) {
        ?>         
        <tr class="hr_expense_line<?php echo $count ?>">
         <td><?php $f->seq_field_d($count); ?></td>
         <td><?php echo $f->select_field_from_object('expense_location', hr_location::find_all(), 'hr_location_id', 'combination', $$class_second->expense_location); ?></td>
         <td><?php echo $f->number_field('per_diem_rate', $$class_second->per_diem_rate, '', '', 'rate'); ?></td>
         <td><?php echo $f->number_field('per_diem_days', $$class_second->per_diem_days); ?></td>
         <td><?php echo $f->select_field_from_object('mileage_uom_id', uom::find_all(), 'uom_id', 'uom_name', $$class_second->mileage_uom_id, '', '', 'uom_id'); ?></td>
         <td><?php echo $f->number_field('mileage_distace', $$class_second->mileage_distace); ?></td>
         <td><?php echo $f->number_field('mileage_rate', $$class_second->mileage_rate); ?></td>
         <td><?php $f->checkBox_field_wid2('original_receipt_missing_cb'); ?></td>
         <td><?php $f->text_field_wid2r('status', 'always_readonly'); ?></td>
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
  <li class="noOfTabbs" data-noOfTabbs="2" ></li>
  <li class="beforeCopy" data-beforeCopy="beforeCopy" ></li>
 </ul>
</div>
