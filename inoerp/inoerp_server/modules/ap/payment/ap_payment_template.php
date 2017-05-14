<div id ="form_header"><span class="heading"><?php echo gettext('Payment Header') ?></span>
 <form  method="post" id="ap_payment_header"  name="ap_payment_header">
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
      <li><?php $f->l_text_field_dr_withSearch('ap_payment_header_id'); ?>
       <a name="show" href="form.php?class_name=ap_payment_header&<?php echo "mode=$mode"; ?>" class="show document_id ap_payment_header_id">
        <i class="fa fa-refresh"></i></a> 
      </li>
      <li><?php $f->l_text_field_d('payment_number', 'primary_column2'); ?> </li>
      <li><?php $f->l_select_field_from_object('bu_org_id', org::find_all_business(), 'org_id', 'org', $$class->bu_org_id, 'bu_org_id', '', 1, $readonly1); ?>       </li>
      <li><?php echo $f->l_select_field_from_object('payment_type', ap_payment_header::payment_types(), 'option_line_code', 'option_line_value', $ap_payment_header->payment_type, 'payment_type', '', 1, $readonly1); ?> </li>
      <li><?php $f->l_date_fieldFromToday_d('document_date', $$class->document_date) ?>              </li>
      <li><?php $f->l_text_field_d('document_number') ?>      </li>
      <li><?php
       echo $f->l_val_field_dm('supplier_name', 'supplier', 'supplier_name', '', 'supplier_name', 'vf_select_supplier_name');
       echo $f->hidden_field_withId('supplier_id', $$class->supplier_id);
       ?><i class="generic g_select_supplier_name select_popup clickable fa fa-search" data-class_name="supplier"></i></li>
      <li><?php
       echo $f->l_val_field_d('supplier_number', 'supplier', 'supplier_number', '', '', 'vf_select_supplier_number');
       ?><i class="generic g_select_supplier_number select_popup clickable fa fa-search" data-class_name="supplier"></i></li>
      <li><label>Supplier Site</label><?php
       $supplier_site_obj = !empty($$class->supplier_id) ? supplier_site::find_by_parent_id($$class->supplier_id) : array();
       echo $f->select_field_from_object('supplier_site_id', $supplier_site_obj, 'supplier_site_id', 'supplier_site_name', $$class->supplier_site_id, 'supplier_site_id', '', '', $readonly1);
       ?> </li>
      <li><?php echo $f->l_select_field_from_array('payment_status', ap_payment_header::$payment_status_a, $$class->payment_status, '', 'always_readonly', '', '', $readonly); ?>     </li> 
      <li><?php $f->l_select_field_from_object('processing_method', ap_payment_process::find_all(), 'ap_payment_process_id', 'payment_process', $$class->processing_method, 'ap_payment_process_id' ,'', 1); ?>       </li> 
      <li><?php $f->l_text_field_d('description'); ?>       </li> 
     </ul>
    </div>
    <div id="tabsHeader-2" class="tabContent">
     <div> 
      <ul class="column header_field ">
       <li><?php $f->l_select_field_from_object('ledger_id', gl_ledger::find_all(), 'gl_ledger_id', 'ledger', $$class->ledger_id, 'ledger_id', 'always_readonly', 1, $readonly1); ?>       </li>
       <li><label><?php echo gettext('Period Name') ?></label><?php
        if (!empty($period_name_stmt)) {
         echo $period_name_stmt;
        } else {
         $f->text_field_d('period_id');
        }
        ?></li>
       <li><?php $f->l_select_field_from_object('ledger_currency', option_header::currencies(), 'option_line_code', 'option_line_code', $$class->currency, 'currency', '', 1, 1); ?></li>
       <li><?php $f->l_text_field_d('pay_group') ?>  
       <li><?php $f->l_number_field('header_amount', $$class->header_amount, '15', 'header_amount'); ?></li>
       <li><?php $f->l_text_field_dr('gl_journal_header_id', 'dont_copy'); ?> </li>
       <li><?php echo $f->hidden_field_withCLass('doc_currency', $$class->doc_currency, 'doc_currency always_readonly'); ?></li>
       <li><?php // $f->l_select_field_from_object('exchange_rate_type', gl_currency_conversion::currency_conversion_type(), 'option_line_code', 'option_line_code', $$class->exchange_rate_type, 'exchange_rate_type', '', 1, $readonly);     ?></li>
       <li><?php // $f->l_number_field('exchange_rate', $$class->exchange_rate, '', 'exchange_rate');     ?> </li>
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
       $reference_table = 'ap_payment_header';
       $reference_id = $$class->ap_payment_header_id;
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
      <ul class="column five_column">
       <li><label><?php echo gettext('Action') ?></label>
        <?php
        echo $f->select_field_from_array('payment_action', $$class->action_a, '', 'payment_action', '', '', $readonly, $readonly)
        ?>
       </li>
      </ul>
     </div>
    </div>

   </div>

  </div>
 </form>
</div>
<div id="form_line" class="form_line"><span class="heading"><?php echo gettext('Payment Lines') ?></span>
 <form method="post" id="po_site"  name="ap_payment_line">
  <div id="tabsLine">
   <ul class="tabMain">
    <li><a href="#tabsLine-1"><?php echo gettext('Basic') ?></a></li>
    <li><a href="#tabsLine-2"><?php echo gettext('References') ?> </a></li>
    <li><a href="#tabsLine-3"><?php echo gettext('Actions') ?> </a></li>
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
        <th><?php echo gettext('Trnx Number') ?></th>
        <th><?php echo gettext('Payment Amount') ?></th>
        <th><?php echo gettext('Rate') ?></th>
        <th><?php echo gettext('GL Amount') ?></th>
        <th><?php echo gettext('Total Amount') ?></th>
        <th><?php echo gettext('Paid') ?></th>
        <th><?php echo gettext('Remaining') ?></th>
       </tr>
      </thead>
      <tbody class="form_data_line_tbody">
       <?php
       $count = 0;
       foreach ($ap_payment_line_object as $ap_payment_line) {
        $f->readonly2 = !empty($ap_payment_line->ap_payment_line_id) ? true : false;
        ?>         
        <tr class="ap_payment_line<?php echo $count ?>">

         <td>  
          <?php
          echo ino_inline_action($$class_second->ap_payment_line_id, array('ap_payment_header_id' => $$class->ap_payment_header_id));
          ?>
         </td>
         <td><?php $f->seq_field_d($count) ?></td>
         <td><?php form::text_field_wid2sr('ap_payment_line_id'); ?></td>
         <td><?php echo form::text_field('line_number', $$class_second->line_number, '8', '20', 1, 'Auto no', '', $readonly, 'lines_number'); ?></td>
         <td><?php
          $f->val_field_wid2('transaction_number', 'ap_transaction_header', 'transaction_number', 'supplier_id');
          echo $f->hidden_field_withCLass('ap_transaction_header_id', $$class_second->ap_transaction_header_id, 'dont_copy_r');
          echo $f->hidden_field_withCLass('supplier_id', $$class->supplier_id, 'popup_value supplier_id');
          ?>
          <i class="generic g_select_ap_transaction_number select_popup clickable fa fa-search" data-class_name="ap_transaction_header"></i></td>
         <td><?php !empty($$class_second->ap_payment_line_id) ? form::number_field_wid2sr('amount') : form::number_field_wid2s('amount'); ?></td>
         <td><?php !empty($$class_second->ap_payment_line_id) ? form::number_field_wid2sr('exchange_rate') : form::number_field_wid2s('exchange_rate'); ?></td>
         <td><?php !empty($$class_second->ap_payment_line_id) ? form::number_field_wid2sr('gl_amount') : form::number_field_wid2s('gl_amount'); ?></td>
         <td><?php $f->text_field_wid2r('invoice_amount', 'header_amount dont_copy_r'); ?></td>
         <td><?php $f->text_field_wid2sr('paid_amount', 'dont_copy_r'); ?></td>
         <td><?php $f->text_field_wid2sr('remaining_amount', 'dont_copy_r'); ?></td>
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
        <th><?php echo gettext('Ref Key Name') ?></th>
        <th><?php echo gettext('Ref Key Value') ?></th>
        <th><?php echo gettext('View Ref Doc') ?></th>
        <th><?php echo gettext('Status') ?></th>
       </tr>
      </thead>
      <tbody class="form_data_line_tbody">
       <?php
       $count = 0;
       foreach ($ap_payment_line_object as $ap_payment_line) {
        ?>         
        <tr class="ap_payment_line<?php echo $count ?>">
         <td><?php $f->seq_field_d($count) ?></td>
         <td><?php $f->text_field_wid2('line_description'); ?></td>
         <td><?php $f->text_field_d2('reference_key_name'); ?></td>
         <td><?php $f->text_field_d2('reference_key_value'); ?></td>
         <td><?php echo!empty($ref_doc_stmt) ? $ref_doc_stmt : '' ?></td>
				 <td><?php echo $$class_second->line_status ?></td>
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
       foreach ($ap_payment_line_object as $ap_payment_line) {
        ?>         
        <tr class="ap_payment_line<?php echo $count ?>">
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
  <li class="headerClassName" data-headerClassName="ap_payment_header" ></li>
  <li class="lineClassName" data-lineClassName="ap_payment_line" ></li>
  <li class="savingOnlyHeader" data-savingOnlyHeader="false" ></li>
  <li class="primary_column_id" data-primary_column_id="ap_payment_header_id" ></li>
  <li class="form_header_id" data-form_header_id="ap_payment_header" ></li>
  <li class="line_key_field" data-line_key_field="amount" ></li>
  <li class="single_line" data-single_line="false" ></li>
  <li class="form_line_id" data-form_line_id="ap_payment_line" ></li>
 </ul>
 <ul id="js_contextMenu_data">
  <li class="docHedaderId" data-docHedaderId="ap_payment_header_id" ></li>
  <li class="docLineId" data-docLineId="ap_payment_line_id" ></li>
  <li class="btn1DivId" data-btn1DivId="ap_payment_header" ></li>
  <li class="btn2DivId" data-btn2DivId="form_line" ></li>
  <li class="trClass" data-docHedaderId="ap_payment_line" ></li>
  <li class="tbodyClass" data-tbodyClass="form_data_line_tbody" ></li>
  <li class="noOfTabbs" data-noOfTabbs="3" ></li>
 </ul>
</div>