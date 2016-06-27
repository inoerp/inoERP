<!-- * 
inoERP
 *
 * @copyright   2014 Nishit R. Das
 * @license     https://www.mozilla.org/MPL/2.0/
 * @link        http://inoideas.org
 * @source code https://github.com/inoerp/inoERP
-->

<div id ="form_header"><span class="heading"><?php echo gettext('Transaction Adjustment') ?></span>
 <div id="tabsHeader">
  <ul class="tabMain">
   <li><a href="#tabsHeader-1"><?php echo gettext('Basic Info') ?></a></li>
   <li><a href="#tabsHeader-2"><?php echo gettext('Other Details') ?></a></li>
  </ul>
  <div class="tabContainer"> 
   <div id="tabsHeader-1" class="tabContent">
    <ul class="column header_field">
     <li><?php
      $f->l_val_field_dm('transaction_number', 'ar_transaction_header', 'transaction_number', '', 'vf_select_transaction_number');
      echo $f->hidden_field_withId('ar_transaction_header_id', $$class->ar_transaction_header_id);
      echo $f->hidden_field_withCLass('bu_org_id', $$class->org_id, 'popup_value');
//      echo $f->hidden_field_withCLass('status', 'COMPLETED', 'popup_value');
      ?>
      <i class="generic g_select_transaction_number select_popup clickable fa fa-search" data-class_name="ar_transaction_header"></i></li>
     <li><?php $f->l_select_field_from_object('org_id', org::find_all_business(), 'org_id', 'org', $$class->org_id, 'org_id', '', 1, $readonly); ?>       </li>
     <li><?php $f->l_date_fieldFromToday_m('transaction_date', ($$class->transaction_date)); ?>       </li>
     <li><?php $f->l_select_field_from_array('adjustment_type', ar_transaction_adjustment::$adjustment_type_a, $$class->adjustment_type, 'adjustment_type', 'always_readonly'); ?>       
      <a name="show2" href="form.php?class_name=ar_transaction_adjustment&<?php echo "mode=$mode"; ?>" class="show2 document_id ar_transaction_adjustment_id">
       <i class="fa fa-refresh"></i></a> 
     </li> 
    </ul>
   </div>
   <div id="tabsHeader-2" class="tabContent">
    <div class="large_shadow_box"> 
     <ul class="column header_field"> 
      <li><?php $f->l_text_field_dr('item_id_m'); ?></li>
      <li><?php $f->l_text_field_dr('item_number'); ?></li>
      <li><?php $f->l_text_field_dr('item_description'); ?></li>
      <li><?php $f->l_select_field_from_object('uom', uom::find_all(), 'uom_id', 'uom_name', $$class->uom, 'uom_id', '', '', 1); ?> </li>
      <li><?php $f->l_number_field_dr('total_quantity'); ?></li>
      <li><?php $f->l_number_field_dr('completed_quantity'); ?></li>
      <li><?php $f->l_text_field_dr('sales_order_header_id'); ?></li>
      <li><?php $f->l_text_field_dr('sales_order_line_id'); ?></li>
     </ul>
    </div>
   </div>
  </div>
 </div>
</div>
<div id ="form_line" class="form_line"><span class="heading"><?php echo gettext('Transaction Details') ?></span>
 <div id="tabsLine">
  <ul class="tabMain">
   <li><a href="#tabsLine-1"><?php echo gettext('Adjustment Info') ?></a></li>
   <li><a href="#tabsLine-2"><?php echo gettext('Reference Info') ?></a></li>
  </ul>
  <div class="tabContainer"> 
   <form  method="post" id="pm_material_transaction"  name="pm_material_transaction">
    <div id="tabsLine-1" class="tabContent">
     <table class="form_line_data_table">
      <thead> 
       <tr>
        <th><?php echo gettext('Action') ?></th>
        <th><?php echo gettext('Seq') ?></th>
        <th><?php echo gettext('Line') ?>#</th>
        <th><?php echo gettext('Line Type') ?></th>
        <th><?php echo gettext('Line Description') ?></th>
        <th><?php echo gettext('Item Description') ?></th>
        <th><?php echo gettext('Item Id') ?></th>
        <th><?php echo gettext('Quantity') ?></th>
        <th><?php echo gettext('Line Amount') ?></th>
        <th><?php echo gettext('Adj Quantity') ?></th>
        <th><?php echo gettext('Adj Amount') ?></th>
        <th><?php echo gettext('Trnx. Id') ?></th>
       </tr>
      </thead>
      <tbody class="inv_transaction_values form_data_line_tbody">
       <tr class="ar_transaction_adjustment">
        <td>
         <?php
         $count = 0;
         $f = new inoform();
         echo ino_inline_action($$class->pm_batch_ingredient_id, array('org_id' => $$class->org_id,
          'ar_transaction_header_id' => $$class->ar_transaction_header_id, 'transaction_type' => $$class->transaction_type, 'transaction_date' => $$class->transaction_date));
         ?>
        </td>
        <td><?php $f->seq_field_d($count) ?></td>
        <td><?php echo!empty($transaction_line_stament) ? $transaction_line_stament : form::text_field_wid('line_stmt'); ?></td>
        <td><?php $f->text_field_widsr('line_type'); ?></td>
        <td><?php $f->text_field_widr('line_description', 'always_readonly'); ?></td>
        <td><?php $f->text_field_widr('item_description', 'always_readonly'); ?></td>
        <td><?php $f->text_field_widsr('item_id_m', 'always_readonly'); ?></td>
        <td><?php $f->text_field_widsr('inv_line_quantity', 'always_readonly'); ?></td>
        <td><?php $f->text_field_widsr('inv_line_price', 'always_readonly'); ?></td>
        <td><?php $f->text_field_wids('adjustment_quantity'); ?></td>
        <td><?php $f->text_field_wids('adjustment_amount'); ?></td>
        <td><?php $f->text_field_widr('ar_transaction_adjustment_id', 'always_readonly'); ?></td>
       </tr>
      </tbody>
     </table>
    </div>
    <div id="tabsLine-2" class="tabContent">
     <table class="form_line_data_table">
      <thead> 
       <tr>
        <th><?php echo gettext('Seq') ?></th>
        <th><?php echo gettext('Description') ?></th>
        <th><?php echo gettext('Adjustment Date') ?></th>
        <th><?php echo gettext('Adjustment AC') ?></th>
        <th><?php echo gettext('Reason') ?></th>
        <th><?php echo gettext('Status') ?></th>
        <th><?php echo gettext('Source') ?></th>
        <th><?php echo gettext('Period') ?></th>
       </tr>
      </thead>
      <tbody class="inv_transaction_values form_data_line_tbody">
       <tr class="ar_transaction_adjustment">
        <td><?php $f->seq_field_d($count) ?></td>
        <td><?php $f->text_field_wid('description'); ?></td>
        <td><?php echo $f->date_fieldAnyDay('adjustment_date' , ''); ?></td>
        <td><?php $f->ac_field_widm('adjustment_ac_id'); ?></td>
        <td><?php $f->text_field_wid('reason'); ?></td>
        <td><?php $f->text_field_wid('status'); ?></td>
        <td><?php $f->text_field_wid('line_source'); ?></td>
        <td><?php $f->text_field_wid('period_id'); ?></td>

       </tr>
      </tbody>
     </table>
    </div>
   </form>
  </div>

 </div>
</div>


<div id="js_data">
 <ul id="js_saving_data">
  <li class="headerClassName" data-headerClassName="ar_transaction_adjustment" ></li>
  <li class="lineClassName" data-lineClassName="ar_transaction_adjustment" ></li>
  <li class="line_key_field" data-line_key_field="ar_transaction_line_id" ></li>
  <li class="single_line" data-single_line="false" ></li>
  <li class="form_line_id" data-form_line_id="ar_transaction_adjustment" ></li>
 </ul>
 <ul id="js_contextMenu_data">
  <li class="docLineId" data-docLineId="extn_uprofile" ></li>
  <li class="btn2DivId" data-btn2DivId="form_line" ></li>
  <li class="trClass" data-trclass="ar_transaction_adjustment" ></li>
  <li class="tbodyClass" data-tbodyClass="form_data_line_tbody" ></li>
  <li class="noOfTabbs" data-noOfTabbs="2" ></li>
 </ul>
</div>