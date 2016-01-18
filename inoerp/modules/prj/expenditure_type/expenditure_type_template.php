<!-- * 
inoERP
 *
 * @copyright   2014 Nishit R. Das
 * @license     https://www.mozilla.org/MPL/2.0/
 * @link        http://inoideas.org
 * @source code https://github.com/inoerp/inoERP
-->

<div id ="form_header"><span class="heading"><?php echo gettext('Expenditure Type') ?></span>
 <form action=""  method="post" id="prj_expenditure_type_header"  name="prj_expenditure_type_header">
  <div id="tabsHeader">
   <ul class="tabMain">
    <li><a href="#tabsHeader-1"><?php echo gettext('Basic Info') ?></a></li>
    <li><a href="#tabsHeader-2"><?php echo gettext('Class Controls') ?></a></li>
    <li><a href="#tabsHeader-3"><?php echo gettext('Note') ?></a></li>
    <li><a href="#tabsHeader-4"><?php echo gettext('Attachments') ?></a></li>
   </ul>
   <div class="tabContainer">
    <div id="tabsHeader-1" class="tabContent">
     <ul class="column header_field">
      <li><?php $f->l_text_field_dr_withSearch('prj_expenditure_type_header_id') ?>
       <a name="show" href="form.php?class_name=prj_expenditure_type_header&<?php echo "mode=$mode"; ?>" class="show document_id prj_expenditure_type_header_id"><i class="fa fa-refresh"></i></a> 
      </li>
      <li><?php $f->l_text_field_d('expenditure_type'); ?></li>
      <li><?php $f->l_select_field_from_object('expenditure_category', prj_expenditure_type_header::prj_expenditure_category(), 'option_line_code', 'option_line_value', $$class->expenditure_category, 'expenditure_category', '', '', $readonly1); ?>    </li>
      <li><?php $f->l_select_field_from_object('revenue_category', prj_expenditure_type_header::prj_revenue_category(), 'option_line_code', 'option_line_value', $$class->revenue_category, 'revenue_category', '', '', $readonly1); ?>    </li>
      <li><?php $f->l_text_field_d('description'); ?></li>
      <li><?php $f->l_date_fieldAnyDay('effective_from', $$class->effective_from); ?></li>
      <li><?php $f->l_date_fieldAnyDay('effective_to', $$class->effective_to); ?></li>
      <li><?php $f->l_select_field_from_object('uom_id', uom::find_all(), 'uom_id', 'uom_name', $$class->uom_id, 'uom_id', 'uom_id', '', $readonly1); ?>         </li>
     </ul>
    </div>
    <div id="tabsHeader-2" class="tabContent">
     <div class='col-md-3'>
      <span class='heading bg-primary text-muted'><?php echo gettext('Labor Expenditures') ?></span>
      <ul class="column header_field"> 
       <li><?php $f->l_checkBox_field_d('direct_labor_cb'); ?></li> 
       <li><?php $f->l_checkBox_field_d('over_time_cb'); ?></li> 
      </ul>
     </div>
     <div class='col-md-9'>
      <span class='heading bg-primary'><?php echo gettext('Non-Labor Expenditures') ?></span>
      <ul class="column header_field"> 
       <li><?php $f->l_checkBox_field_d('inventory_cb'); ?></li> 
       <li><?php $f->l_checkBox_field_d('burden_cb'); ?></li> 
       <li><?php $f->l_checkBox_field_d('expense_reports_cb'); ?></li> 
       <li><?php $f->l_checkBox_field_d('misc_transaction_cb'); ?></li> 
       <li><?php $f->l_checkBox_field_d('invoice_cb'); ?></li> 
       <li><?php $f->l_checkBox_field_d('usages_cb'); ?></li> 
       <li><?php $f->l_checkBox_field_d('wip_cb'); ?></li> 
      </ul> 
     </div> 
    </div>
    <div id="tabsHeader-3" class="tabContent">
     <div> 
      <div id="comments">
       <div id="comment_list">
        <?php echo!(empty($comments)) ? $comments : ""; ?>
       </div>
       <div id ="display_comment_form comment">
        <?php
        $reference_table = 'prj_expenditure_type_header';
        $reference_id = $$class->prj_expenditure_type_header_id;
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

<div id="form_line" class="form_line"><span class="heading"><?php echo gettext('Cost Rates') ?></span>
 <form action=""  method="post" id="prj_expenditure_type_line"  name="prj_expenditure_type_line">
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
        <th><?php echo gettext('Org Id') ?></th>
        <th><?php echo gettext('Description') ?></th>
        <th><?php echo gettext('From Date') ?></th>
        <th><?php echo gettext('To Date') ?></th>
        <th><?php echo gettext('Currency') ?></th>
        <th><?php echo gettext('UOM') ?></th>
        <th><?php echo gettext('Rate') ?></th>
       </tr>
      </thead>
      <tbody class="form_data_line_tbody">
       <?php
       $count = 0;
       foreach ($prj_expenditure_type_line_object as $prj_expenditure_type_line) {
        ?>         
        <tr class="prj_expenditure_type_line<?php echo $count ?>">
         <td>
          <?php
          echo ino_inline_action($prj_expenditure_type_line->prj_expenditure_type_line_id, array('prj_expenditure_type_header_id' => $prj_expenditure_type_header->prj_expenditure_type_header_id));
          ?>
         </td>
         <td><?php $f->text_field_d2sr('prj_expenditure_type_line_id'); ?></td>
         <td><?php echo $f->select_field_from_object('bu_org_id', org::find_all_business(), 'org_id', 'org', $$class_second->bu_org_id); ?>						 </td>
         <td><?php $f->text_field_d2('description'); ?></td>
         <td><?php echo $f->date_fieldAnyDay('effective_from', $$class_second->effective_from); ?></td>
         <td><?php echo $f->date_fieldAnyDay('effective_to', $$class_second->effective_to); ?></td>
         <td><?php echo $f->select_field_from_object('currency', option_header::currencies(), 'option_line_code', 'option_line_value', $$class_second->currency); ?></td>
         <td><?php echo $f->select_field_from_object('uom_id', uom::find_all(), 'uom_id', 'uom_name', $$class_second->uom_id, '', 'small'); ?></td>
         <td><?php $f->text_field_d2('rate'); ?></td>
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
  <li class="headerClassName" data-headerClassName="prj_expenditure_type_header" ></li>
  <li class="lineClassName" data-lineClassName="prj_expenditure_type_line" ></li>
  <li class="savingOnlyHeader" data-savingOnlyHeader="false" ></li>
  <li class="primary_column_id" data-primary_column_id="prj_expenditure_type_header_id" ></li>
  <li class="form_header_id" data-form_header_id="prj_expenditure_type_header" ></li>
  <li class="line_key_field" data-line_key_field="line_name" ></li>
  <li class="single_line" data-single_line="false" ></li>
  <li class="form_line_id" data-form_line_id="prj_expenditure_type_line" ></li>
 </ul>
 <ul id="js_contextMenu_data">
  <li class="docHedaderId" data-docHedaderId="prj_expenditure_type_header_id" ></li>
  <li class="docLineId" data-docLineId="prj_expenditure_type_line_id" ></li>
  <li class="btn1DivId" data-btn1DivId="prj_expenditure_type_header" ></li>
  <li class="btn2DivId" data-btn2DivId="form_line" ></li>
  <li class="tbodyClass" data-tbodyClass="form_data_line_tbody" ></li>
  <li class="noOfTabbs" data-noOfTabbs="1" ></li>
 </ul>
</div>