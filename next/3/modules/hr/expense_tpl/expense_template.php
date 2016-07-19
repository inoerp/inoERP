<!-- * 
inoERP
 *
 * @copyright   2014 Nishit R. Das
 * @license     https://www.mozilla.org/MPL/2.0/
 * @link        http://inoideas.org
 * @source code https://github.com/inoerp/inoERP
-->

<div id ="form_header"><span class="heading"><?php echo gettext('Expense Claim Template') ?></span>
 <form method="post" id="hr_expense_tpl_header"  name="hr_expense_tpl_header">
  <div id="tabsHeader">
   <ul class="tabMain">
    <li><a href="#tabsHeader-1"><?php echo gettext('Basic Info') ?></a></li>
    <li><a href="#tabsHeader-2"><?php echo gettext('Attachments') ?></a></li>
    <li><a href="#tabsHeader-3"><?php echo gettext('Notes') ?></a></li>
   </ul>
   <div class="tabContainer">
    <div id="tabsHeader-1" class="tabContent">
     <ul class="column header_field">
      <li><?php $f->l_text_field_dr_withSearch('hr_expense_tpl_header_id') ?>
       <a name="show" href="form.php?class_name=hr_expense_tpl_header&<?php echo "mode=$mode"; ?>" class="show document_id hr_expense_tpl_header_id">
        <i class="fa fa-refresh"></i></a> 
      </li>
      <li><?php $f->l_select_field_from_object('bu_org_id', org::find_all_business(), 'org_id', 'org', $$class->bu_org_id, 'bu_org_id', '', 1, $readonly1); ?>        </li>
      <li><?php $f->l_text_field_d('template_name'); ?>             </li>
      <li><?php $f->l_text_field_d('description'); ?>             </li>
      <li><?php $f->l_date_fieldAnyDay('inactive_date', $$class->inactive_date); ?>             </li>
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
        $reference_table = 'hr_expense_tpl_header';
        $reference_id = $$class->hr_expense_tpl_header_id;
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

<div id="form_line" class="form_line"><span class="heading"><?php echo gettext('Expense Template Lines') ?></span>
 <form method="post" id="hr_expense_tpl_line"  name="hr_expense_tpl_line">
  <div id="tabsLine">
   <ul class="tabMain">
    <li><a href="#tabsLine-1"><?php echo gettext('Expense Items') ?></a></li>
    <li><a href="#tabsLine-2"><?php echo gettext('Future') ?></a></li>
   </ul>
   <div class="tabContainer">
    <div id="tabsLine-1" class="tabContent">
     <table class="form_line_data_table">
      <thead> 
       <tr>
        <th><?php echo gettext('Action') ?></th>
        <th><?php echo gettext('Expense Item') ?></th>
        <th><?php echo gettext('Category') ?></th>
        <th><?php echo gettext('Tax Code') ?></th>
        <th><?php echo gettext('GL Account') ?></th>
        <th><?php echo gettext('Prj Expenditure Type') ?></th>
        <th><?php echo gettext('Policy') ?></th>
       </tr>
      </thead>
      <tbody class="form_data_line_tbody">
       <?php
        $count = 0;
       foreach ($hr_expense_tpl_line_object as $hr_expense_tpl_line) {
        ?>         
        <tr class="hr_expense_tpl_line<?php echo $count ?>">
         <td>
          <?php
          echo ino_inline_action($$class_second->hr_expense_tpl_line_id, 
           array('hr_expense_tpl_header_id' => $$class->hr_expense_tpl_header_id, 'hr_expense_tpl_line_id' => $$class_second->hr_expense_tpl_line_id));
          ?>
         </td>
         <td><?php $f->text_field_wid2('expense_item'); ?></td>
         <td><?php echo $f->select_field_from_object('expense_category', option_header::find_options_byName('HR_EXPENSE_CATEGORY'), 'option_line_code', 'option_line_value', $$class_second->expense_category, '', 'medium', 1); ?></td>
         <td><?php echo $f->select_field_from_object('tax_code_id', mdm_tax_code::find_all_inTax_by_bu_org_id($$class->bu_org_id), 'mdm_tax_code_id', 'tax_code', $$class_second->tax_code_id, '', 'input_tax medium', '', $readonly, '', '', '', 'percentage') ?></td>
         <td><?php $f->ac_field_wid2('expense_ac_id'); ?></td>
         <td><?php echo $f->select_field_from_object('prj_expenditure_type_header_id', prj_expenditure_type_header::find_all(),'prj_expenditure_type_header_id','expenditure_type', $$class_second->prj_expenditure_type_header_id); ?></td>
         <td><?php $f->text_field_wid2('policy_schedule_id'); ?></td>
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
  <li class="headerClassName" data-headerClassName="hr_expense_tpl_header" ></li>
  <li class="lineClassName" data-lineClassName="hr_expense_tpl_line" ></li>
  <li class="savingOnlyHeader" data-savingOnlyHeader="false" ></li>
  <li class="primary_column_id" data-primary_column_id="hr_expense_tpl_header_id" ></li>
  <li class="form_header_id" data-form_header_id="hr_expense_tpl_header" ></li>
  <li class="line_key_field" data-line_key_field="expense_item" ></li>
  <li class="single_line" data-single_line="true" ></li>
  <li class="form_line_id" data-form_line_id="hr_expense_tpl_line" ></li>
 </ul>
 <ul id="js_contextMenu_data">
  <li class="docHedaderId" data-docHedaderId="hr_expense_tpl_header_id" ></li>
  <li class="docLineId" data-docLineId="hr_expense_tpl_line_id" ></li>
  <li class="btn1DivId" data-btn1DivId="hr_expense_tpl_header" ></li>
  <li class="btn2DivId" data-btn2DivId="form_line" ></li>
  <li class="tbodyClass" data-tbodyClass="form_data_line_tbody" ></li>
  <li class="noOfTabbs" data-noOfTabbs="1" ></li>
 </ul>
</div>