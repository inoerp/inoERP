<div id ="form_header"><span class="heading"><?php echo gettext('Receipt Header') ?></span>
 <form  method="post" id="ar_receipt_header"  name="ar_receipt_header">
  <div id="tabsHeader">
   <ul class="tabMain">
    <li><a href="#tabsHeader-1"><?php echo gettext('Basic Info') ?></a></li>
    <li><a href="#tabsHeader-2"><?php echo gettext('Finance') ?></a></li>
    <li><a href="#tabsHeader-3"><?php echo gettext('Notes') ?></a></li>
    <li><a href="#tabsHeader-4"><?php echo gettext('Attachments') ?></a></li>
    <li><a href="#tabsHeader-5"><?php echo gettext('Actions') ?></a></li>
   </ul>
   <div class="tabContainer">
    <div id="tabsHeader-1" class="tabContent">
     <ul class="column header_field">
      <li><?php $f->l_text_field_dr_withSearch('ar_receipt_header_id'); ?>
       <a name="show" href="form.php?class_name=ar_receipt_header&<?php echo "mode=$mode"; ?>" class="show document_id ar_receipt_header_id"><i class="fa fa-refresh"></i></a> 
      </li>
      <li><?php $f->l_text_field_d('receipt_number'); ?></li>
      <li><?php $f->l_select_field_from_array('receipt_type', ar_receipt_header::$receipt_type_a, $$class->receipt_type, 'receipt_type'); ?></li>
      <li><?php $f->l_select_field_from_object('bu_org_id', org::find_all_business(), 'org_id', 'org', $$class->bu_org_id, 'bu_org_id', '', 1, $readonly1); ?></li>
      <li><?php $f->l_select_field_from_object('ledger_id', gl_ledger::find_all(), 'gl_ledger_id', 'ledger', $$class->ledger_id, 'ledger_id', '', '', $readonly1, 1); ?></li>
      <li><label><?php echo gettext('Period Name') ?></label><?php
       if (!empty($period_name_stmt)) {
        echo $period_name_stmt;
       } else {
        $f->text_field_d('period_id');
       }
       ?>
      </li>
      <li><?php $f->l_select_field_from_object('ar_receipt_source_id', ar_receipt_source::find_all(), 'ar_receipt_source_id', 'receipt_source', $$class->ar_receipt_source_id, 'ar_receipt_source_id', '', 1, $readonly); ?>			 </li>
      <li><?php $f->l_date_fieldFromToday_m('document_date', $$class->document_date, 1) ?></li>
      <li><?php $f->l_text_field_d('document_number') ?></li>
      <li><?php
       echo $f->l_val_field_dm('customer_name', 'ar_customer', 'customer_name', '', 'customer_name', 'vf_select_customer_name');
       echo $f->hidden_field_withId('ar_customer_id', $$class->ar_customer_id);
       ?><i class="generic g_select_customer_name select_popup clickable fa fa-search" data-class_name="ar_customer"></i></li>
      <li><?php
       echo $f->l_val_field_d('customer_number', 'ar_customer', 'customer_number', '', '', 'vf_select_customer_number');
       ?><i class="generic g_select_customer_number select_popup clickable fa fa-search" data-class_name="ar_customer"></i></li>
      <li><?php $f->l_select_field_from_object('ar_customer_site_id', $customer_site_obj, 'ar_customer_site_id', 'customer_site_name', $$class->ar_customer_site_id, 'ar_customer_site_id', 'ar_customer_site_id', '', $readonly1); ?> </li>
      <li><?php $f->l_select_field_from_array('receipt_status', ar_receipt_header::$receipt_status_a, $$class->receipt_status, '', '', '', '', $readonly); ?>			 </li> 
      <li><?php $f->l_text_field_d('description'); ?></li> 
     </ul>
    </div>
    <div id="tabsHeader-2" class="tabContent">
     <div> 
      <ul class="column header_field">
       <li><?php $f->l_select_field_from_object('doc_currency', option_header::currencies(), 'option_line_code', 'option_line_code', $$class->doc_currency, 'doc_currency', '', 1, $readonly); ?></li>
       <li><?php $f->l_select_field_from_object('ledger_currency', option_header::currencies(), 'option_line_code', 'option_line_code', $$class->currency, 'currency', '', 1, 1); ?></li>
       <li><?php $f->l_select_field_from_object('exchange_rate_type', gl_currency_conversion::currency_conversion_type(), 'option_line_code', 'option_line_code', $$class->exchange_rate_type, 'exchange_rate_type', '', 1, $readonly); ?></li>
       <li><?php $f->l_number_field('exchange_rate', $$class->exchange_rate, '', 'exchange_rate'); ?> </li>
       <li><?php $f->l_number_field('header_amount', $$class->header_amount, '15', 'header_amount'); ?></li>
       <li><?php $f->l_text_field_dr('gl_journal_header_id') ?></li>
      </ul>
     </div>
    </div>
    <div id="tabsHeader-3" class="tabContent">
     <div id="comments">
      <div id="comment_list">
       <?php echo!(empty($comments)) ? $comments : ""; ?>
      </div>
      <div id ="display_comment_form">
       <?php
       $reference_table = 'ar_receipt_header';
       $reference_id = $$class->ar_receipt_header_id;
       ?>
      </div>
      <div id="new_comment">
      </div>
     </div>
    </div>
    <div id="tabsHeader-4" class="tabContent">
     <div> <?php echo ino_attachement($file) ?> </div>
    </div>

    <div id="tabsHeader-5" class="tabContent">
     <div> 
      <ul class="column header_field">
       <li><?php $f->l_select_field_from_array('action', $$class->receipt_action_a, '', 'action'); ?>       </li>
      </ul>

      <div id="comment" class="show_comments">
      </div>
     </div>
    </div>

   </div>

  </div>
 </form>
</div>

<div id="form_line" class="form_line"><span class="heading"><?php echo gettext('Receipt Lines') ?></span>
 <form method="post" id="ar_receipt_line"  name="ar_receipt_line">
  <div id="tabsLine">
   <ul class="tabMain">
    <li><a href="#tabsLine-1"><?php echo gettext('Basic') ?></a></li>
    <li><a href="#tabsLine-2"><?php echo gettext('References') ?> </a></li>
    <li><a href="#tabsLine-3"><?php echo gettext('Notes') ?> </a></li>
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
        <th><?php echo gettext('Line Type') ?></th>
        <th><?php echo gettext('Trnx Number') ?></th>
        <th><?php echo gettext('Activity') ?></th>
        <th><?php echo gettext('Receipt Amount') ?></th>
        <th><?php echo gettext('Exchange Rate') ?></th>
        <th><?php echo gettext('GL Amount') ?></th>
        <th><?php echo gettext('Total Amount') ?></th>
        <th><?php echo gettext('Cum. Receipt') ?></th>
        <th><?php echo gettext('Remaining') ?></th>
       </tr>
      </thead>
      <tbody class="form_data_line_tbody">
       <?php
       $count = 0; $f = new inoform();
       foreach ($ar_receipt_line_object as $ar_receipt_line) {
        $f->readonly2 = !empty($ar_receipt_line->ar_receipt_line_id) ? true : false;
        if(empty($ar_receipt_line->line_type)){
         $ar_receipt_line->line_type = 'INVOICE';
        }
        ?>         
        <tr class="ar_receipt_line<?php echo $count ?>">
         <td>
          <?php
          echo ino_inline_action($$class_second->ar_receipt_line_id, array('ar_receipt_header_id' => $$class->ar_receipt_header_id));
          ?>
         </td>
         <td><?php $f->seq_field_d($count); ?></td>
         <td><?php form::text_field_wid2sr('ar_receipt_line_id'); ?></td>
         <td><?php echo form::text_field('line_number', $$class_second->line_number, '8', '20', 1, 'Auto no', '', $readonly, 'lines_number'); ?></td>
         <td><?php echo $f->select_field_from_array('line_type', ar_receipt_line::$line_type_a, $$class_second->line_type, '' ,'medium'); ?></td>
         <td><?php
          $f->val_field_wid2('transaction_number', 'ar_transaction_header', 'transaction_number', 'ar_customer_id');
          echo $f->hidden_field('ar_transaction_header_id', $$class_second->ar_transaction_header_id);
          echo $f->hidden_field_withCLass('ar_customer_id', $$class->ar_customer_id, 'popup_value ar_customer_id');
          ?>
          <i class="generic g_select_ar_transaction_number select_popup clickable fa fa-search" data-class_name="ar_transaction_header"></i></td>
         <td><?php echo $f->select_field_from_object('ar_receivable_activity_id', ar_receivable_activity::find_all(), 'ar_receivable_activity_id' , 'activity_name' ,$$class_second->ar_receivable_activity_id, '' ,'medium' ,'','','','','','activity_type'); ?></td>
         <td><?php !empty($$class_second->ar_receipt_line_id) ? $f->text_field_wid2r('amount') : $f->text_field_wid2('amount'); ?></td>
         <td><?php !empty($$class_second->ar_receipt_line_id) ? $f->text_field_wid2r('exchange_rate') : $f->text_field_wid2('exchange_rate'); ?></td>
         <td><?php !empty($$class_second->ar_receipt_line_id) ? $f->text_field_wid2r('gl_amount') : $f->text_field_wid2s('gl_amount'); ?></td>
         <td><?php $f->text_field_wid2sr('invoice_amount' ,'header_amount'); ?></td>
         <td><?php $f->text_field_wid2sr('receipt_amount'); ?></td>
         <td><?php $f->text_field_wid2sr('remaining_amount'); ?></td>
        </tr>
        <?php
        $count = $count + 1;
       }
       ?>
      </tbody>
     </table>
    </div>
    <div id="tabsLine-2" class="scrollElement tabContent">
     <table class="form_line_data_table">
      <thead> 
       <tr>
        <th><?php echo gettext('Seq') ?>#</th>
        <th><?php echo gettext('Line Description') ?></th>
        <th><?php echo gettext('Ref Key Name') ?>#</th>
        <th><?php echo gettext('Ref Key Value') ?></th>
        <th><?php echo gettext('View Ref Doc') ?></th>
        <th><?php echo gettext('Status') ?></th>
       </tr>
      </thead>
      <tbody class="form_data_line_tbody">
       <?php
       $count = 0;
       foreach ($ar_receipt_line_object as $ar_receipt_line) {
        ?>         
        <tr class="ar_receipt_line<?php echo $count ?>">
         <td><?php $f->seq_field_d($count); ?></td>
         <td><?php $f->text_field_wid2('line_description'); ?></td>
         <td><?php $f->text_field_d2('reference_key_name'); ?></td>
         <td><?php $f->text_field_d2('reference_key_value'); ?></td>
         <td><?php echo!empty($ref_doc_stmt) ? $ref_doc_stmt : '' ?></td>
         <td><?php $f->text_field_wid2sr('status' , 'always_readonly'); ?></td>
        </tr>
        <?php
        $count = $count + 1;
       }
       ?>
      </tbody>
      <!--                  Showing a blank form for new entry-->
     </table>
    </div>
    <div id="tabsLine-3" class="tabContent">
     <table class="form_line_data_table">
      <thead> 
       <tr>
        <th>Comments</th>

       </tr>
      </thead>
      <tbody class="form_data_line_tbody">
       <?php
       $count = 0;
       foreach ($ar_receipt_line_object as $ar_receipt_line) {
        ?>         
        <tr class="ar_receipt_line<?php echo $count ?>">
         <td></td>
        </tr>
        <?php
        $count = $count + 1;
       }
       ?>
      </tbody>
      <!--                  Showing a blank form for new entry-->

     </table>
    </div>
   </div>
  </div>
 </form>

</div>

<div id="js_data">
 <ul id="js_saving_data">
  <li class="headerClassName" data-headerClassName="ar_receipt_header" ></li>
  <li class="lineClassName" data-lineClassName="ar_receipt_line" ></li>
  <li class="savingOnlyHeader" data-savingOnlyHeader="false" ></li>
  <li class="primary_column_id" data-primary_column_id="ar_receipt_header_id" ></li>
  <li class="form_header_id" data-form_header_id="ar_receipt_header" ></li>
  <li class="line_key_field" data-line_key_field="transaction_number" ></li>
  <li class="single_line" data-single_line="false" ></li>
  <li class="form_line_id" data-form_line_id="ar_receipt_line" ></li>
 </ul>
 <ul id="js_contextMenu_data">
  <li class="docHedaderId" data-docHedaderId="ar_receipt_header_id" ></li>
  <li class="docLineId" data-docLineId="ar_receipt_line_id" ></li>
  <li class="btn1DivId" data-btn1DivId="ar_receipt_header" ></li>
  <li class="btn2DivId" data-btn2DivId="form_line" ></li>
  <li class="trClass" data-docHedaderId="ar_receipt_line" ></li>
  <li class="tbodyClass" data-tbodyClass="form_data_line_tbody" ></li>
  <li class="noOfTabbs" data-noOfTabbs="3" ></li>
 </ul>
</div>