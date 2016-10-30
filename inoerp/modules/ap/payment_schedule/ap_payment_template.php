<!-- * 
inoERP
 *
 * @copyright   2014 Nishit R. Das
 * @license     https://www.mozilla.org/MPL/2.0/
 * @link        http://inoideas.org
 * @source code https://github.com/inoerp/inoERP
-->

<div id ="form_header"><span class="heading"><?php echo gettext('Revenue Schedule') ?></span>
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
      echo $f->hidden_field_withCLass('transaction_status', 'CLOSED', 'popup_value');
      echo $f->hidden_field_withCLass('transaction_class', 'INVOICE', 'popup_value');
      ?>
      <i class="generic g_select_transaction_number select_popup clickable fa fa-search" data-class_name="ar_transaction_header"></i></li>
     <li><?php $f->l_select_field_from_object('org_id', org::find_all_business(), 'org_id', 'org', $$class->org_id, 'org_id', '', 1, $readonly); ?>       </li>
     <li><?php $f->l_date_fieldFromToday_m('transaction_date', ($$class->transaction_date)); ?>       </li>
     <li><?php $f->l_select_field_from_array('adjustment_type', ar_revenue_schedule::$adjustment_type_a, $$class->adjustment_type, 'adjustment_type', 'always_readonly'); ?>       
      <a name="show2" href="form.php?class_name=ar_revenue_schedule&<?php echo "mode=$mode"; ?>" class="show2 document_id ar_revenue_schedule_id">
       <i class="fa fa-refresh"></i></a> 
     </li> 
     <li><?php $f->l_select_field_from_object('ledger_id', gl_ledger::find_all(), 'gl_ledger_id', 'ledger', $$class->ledger_id, 'ledger_id', 'always_readonly', '', 1); ?>             </li>
     <li><?php $f->l_select_field_from_object('trnx_period_id', gl_period::find_all(), 'gl_period_id', 'period_name', $$class->trnx_period_id, 'ledger_id', 'always_readonly', '', 1); ?>             </li>

    </ul>
   </div>
   <div id="tabsHeader-2" class="tabContent">
    <div class="large_shadow_box"> 
     <ul class="column header_field"> 
      <li><?php $f->l_text_field_dr('transaction_type'); ?></li>
      <li><?php $f->l_text_field_dr('transaction_class'); ?></li>
      <li><?php $f->l_text_field_dr('transaction_number'); ?></li>
      <li><?php $f->l_text_field_dr('document_owner'); ?></li>
      <li><?php $f->l_text_field_dr('trnx_description'); ?></li>
      <li><?php $f->l_text_field_dr('currency'); ?></li>
      <li><?php $f->l_text_field_dr('doc_currency'); ?></li>
      <li><?php $f->l_text_field_dr('exchange_rate_type'); ?></li>
      <li><?php $f->l_text_field_dr('trnx_exchange_rate'); ?></li>
      <li><?php $f->l_text_field_dr('transaction_status'); ?></li>
      <li><?php $f->l_text_field_dr('document_date'); ?></li>
      <li><?php $f->l_text_field_dr('document_number'); ?></li>
     </ul>
    </div>
   </div>
  </div>
 </div>
</div>
<div id ="form_line" class="form_line"><span class="heading"><?php echo gettext('Accounting Details') ?></span>
 <div id="tabsLine">
  <ul class="tabMain">
   <li><a href="#tabsLine-1"><?php echo gettext('Line Info') ?></a></li>
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
        <th><?php echo gettext('Account Class') ?></th>
        <th><?php echo gettext('Line Desc.') ?></th>
        <th><?php echo gettext('Item Desc') ?></th>
        <th><?php echo gettext('GL Date') ?></th>
        <th><?php echo gettext('Amount') ?></th>
        <th><?php echo gettext('Percentage') ?></th>
        <th><?php echo gettext('Account') ?></th>
        <th><?php echo gettext('Status') ?></th>
       </tr>
      </thead>
      <tbody class="inv_transaction_values form_data_line_tbody">
       <?php
       $count = 0;
       if (!empty($adjustment_line_object)) {
        $position = 0;
        $adjustment_line_ai = new ArrayIterator($adjustment_line_object);
        $adjustment_line_ai->seek($position);
        while ($adjustment_line_ai->valid()) {
         $adjustment_line_i = $adjustment_line_ai->current();
         $ar_trnx_line_i = ar_transaction_line::find_by_id($adjustment_line_i->ar_transaction_line_id);
         ?>         
         <tr class="ar_revenue_schedule<?php echo $count ?>">
          <td>      </td>
          <td><?php $f->seq_field_d($count) ?></td>
          <td><?php $f->text_field_widr('ar_transaction_line_id', 'always_readonly'); ?></td>
          <td><?php echo $f->select_field_from_object('ar_receivable_activity_id', ar_receivable_activity::find_all(), 'ar_receivable_activity_id', 'activity_name', $adjustment_line_i->ar_receivable_activity_id, '', 'always_readonly', 1, '', '', '', '', 'activity_ac_id'); ?></td>
          <td><?php echo $f->text_field('account_class', $ar_trnx_line_i->account_class, '', '', 'always_readonly'); ?></td>
          <td><?php echo $f->text_field('line_description', $ar_trnx_line_i->line_description, '', '', 'always_readonly'); ?></td>
          <td><?php echo $f->text_field('item_description', $ar_trnx_line_i->item_description, '', '', 'always_readonly'); ?></td>
          <td><?php echo $f->date_fieldAnyDay_r('gl_date', $ar_trnx_line_i->gl_date, 1); ?></td>
          <td><?php echo $f->text_field('amount', $ar_trnx_line_i->amount, '', '', 'always_readonly'); ?></td>
          <td><?php echo $f->text_field('percentage', $ar_trnx_line_i->percentage, '', '', 'always_readonly'); ?></td>
          <td><?php $f->ac_field_wid('gl_ac_id'); ?></td>
          <td><?php echo $f->text_field('status', $adjustment_line_i->status, '', '', 'always_readonly'); ?></td>
         </tr>
         <?php
         $adjustment_line_ai->next();
         if ($adjustment_line_ai->key() == $position + $per_page) {
          break;
         }
         $count = $count + 1;
        }
       }
       ?>
       <tr class="ar_revenue_schedule">
        <td>
         <?php
         echo ino_inline_action($$class->ar_revenue_schedule_id, array('org_id' => $$class->org_id,
          'ar_transaction_header_id' => $$class->ar_transaction_header_id, 'transaction_type' => $$class->transaction_type));
         ?>
        </td>
        <td><?php $f->seq_field_d($count) ?></td>
        <td><?php $f->text_field_widr('line_type'); ?></td>
        <td><?php $f->text_field_widr('line_description', 'always_readonly'); ?></td>
        <td><?php $f->text_field_widr('item_description', 'always_readonly'); ?></td>
        <td><?php $f->text_field_widr('inv_line_quantity', 'always_readonly'); ?></td>
        <td><?php $f->text_field_widr('inv_unit_price', 'always_readonly'); ?></td>
        <td><?php $f->text_field_widr('inv_line_price', 'always_readonly'); ?></td>
        <td><?php $f->text_field_wid('adjustment_quantity'); ?></td>
        <td><?php $f->text_field_wid('adjustment_amount'); ?></td>

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
        <th><?php echo gettext('Reason') ?></th>
        <th><?php echo gettext('Status') ?></th>
        <th><?php echo gettext('Source') ?></th>
        <th><?php echo gettext('Rate') ?></th>
        <th><?php echo gettext('Trnx Id') ?></th>
        <th><?php echo gettext('Journal') ?></th>
       </tr>
      </thead>
      <tbody class="inv_transaction_values form_data_line_tbody">
       <?php
       $count = 0;
       $f = new inoform();
       if (!empty($adjustment_line_object)) {
        $position = 0;
        $adjustment_line_ai = new ArrayIterator($adjustment_line_object);
        $adjustment_line_ai->seek($position);
        while ($adjustment_line_ai->valid()) {
         $adjustment_line_i = $adjustment_line_ai->current();
         $ar_trnx_line_i = ar_transaction_line::find_by_id($adjustment_line_i->ar_receivable_activity_id);
         ?>         
         <tr class="ar_revenue_schedule<?php echo $count ?>">
          <td><?php $f->seq_field_d($count) ?></td>
          <td><?php echo $f->text_field('description', $adjustment_line_i->description, '', '', 'always_readonly'); ?></td>
          <td><?php echo $f->text_field('adjustment_date', $adjustment_line_i->adjustment_date, '', '', 'always_readonly'); ?></td>
          <td><?php echo $f->account_field('adjustment_ac_id', $adjustment_line_i->adjustment_ac_id); ?></td>
          <td><?php echo $f->text_field('reason', $adjustment_line_i->reason, '', '', 'always_readonly'); ?></td>
          <td><?php echo $f->text_field('status', $adjustment_line_i->status, '', '', 'always_readonly'); ?></td>
          <td><?php echo $f->text_field('line_source', $adjustment_line_i->line_source, '', '', 'always_readonly'); ?></td>
          <td><?php echo $f->text_field('exchange_rate', $adjustment_line_i->exchange_rate, '', '', 'always_readonly'); ?></td>
          <td><?php echo $f->text_field('gl_adjustment_amount', $adjustment_line_i->gl_adjustment_amount, '', '', 'always_readonly'); ?></td>
          <td><?php echo $f->gl_period_field('period_id', $$class->ledger_id, '', 'medium', 1); ?></td>
          <td><?php echo $f->text_field('ar_revenue_schedule_id', $adjustment_line_i->ar_revenue_schedule_id, '', '' , 'small always_readonly', '' , 1); ?></td>
          <td><a role="button" class="btn btn-sm btn-default"  href="form.php?class_name=gl_journal_header&gl_journal_header_id=<?php echo $adjustment_line_i->gl_journal_header_id; ?>"><?php echo $adjustment_line_i->gl_journal_header_id; ?></a></td>
         </tr>
         <?php
         $adjustment_line_ai->next();
         if ($adjustment_line_ai->key() == $position + $per_page) {
          break;
         }
         $count = $count + 1;
        }
       }
       ?>
       <tr class="ar_revenue_schedule">
        <td><?php $f->seq_field_d($count) ?></td>
        <td><?php $f->text_field_wid('description'); ?></td>
        <td><?php $f->text_field_wid('reason'); ?></td>
        <td><?php $f->text_field_wid('status'); ?></td>
        <td><?php $f->text_field_wid('line_source'); ?></td>
        <td><?php $f->text_field_wid('exchange_rate'); ?></td>
        <td><?php echo $f->gl_period_field('period_id', $$class->ledger_id, '', 'medium'); ?></td>
        <td><?php $f->text_field_widsr('ar_revenue_schedule_id', 'always_readonly'); ?></td>
        <td></td>
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
  <li class="headerClassName" data-headerClassName="ar_revenue_schedule" ></li>
  <li class="lineClassName" data-lineClassName="ar_revenue_schedule" ></li>
  <li class="line_key_field" data-line_key_field="ar_transaction_line_id" ></li>
  <li class="single_line" data-single_line="false" ></li>
  <li class="form_line_id" data-form_line_id="ar_revenue_schedule" ></li>
 </ul>
 <ul id="js_contextMenu_data">
  <li class="docLineId" data-docLineId="extn_uprofile" ></li>
  <li class="btn2DivId" data-btn2DivId="form_line" ></li>
  <li class="trClass" data-trclass="ar_revenue_schedule" ></li>
  <li class="tbodyClass" data-tbodyClass="form_data_line_tbody" ></li>
  <li class="noOfTabbs" data-noOfTabbs="2" ></li>
 </ul>
</div>
