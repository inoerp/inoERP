<div id ="form_header"><span class="heading">Payment Header </span>
 <form action=""  method="post" id="ap_payment_header"  name="ap_payment_header">
  <div id="tabsHeader">
   <ul class="tabMain">
    <li><a href="#tabsHeader-1">Basic Info</a></li>
    <li><a href="#tabsHeader-2">Finance</a></li>
    <li><a href="#tabsHeader-3">Notes</a></li>
    <li><a href="#tabsHeader-4">Attachments</a></li>
    <li><a href="#tabsHeader-5">Actions</a></li>
   </ul>
   <div class="tabContainer">
    <div id="tabsHeader-1" class="tabContent">
     <div class="large_shadow_box"> 
      <ul class="column header_field">
       <li><label><img src="<?php echo HOME_URL; ?>themes/images/serach.png" class="ap_payment_header_id select_popup">
         Payment Id</label>
        <?php $f->text_field_dsr('ap_payment_header_id'); ?>
        <a name="show" href="form.php?class_name=ap_payment_header&<?php echo "mode=$mode"; ?>" class="show document_id ap_payment_header_id">
         <i class="fa fa-refresh"></i></a> 
       </li>
       <li><label>Payment No</label>
        <?php $f->text_field_d('payment_number', 'primary_column2'); ?>
       </li>
       <li><label>BU Name(1)</label>
        <?php echo $f->select_field_from_object('bu_org_id', org::find_all_business(), 'org_id', 'org', $$class->bu_org_id, 'bu_org_id', '', 1, $readonly1); ?>
        <a name="show" href="form.php?class_name=ap_payment_header" class="show bu_org_id">
         <img src="<?php echo HOME_URL; ?>themes/images/refresh.png"/></a> 
       </li>
       <li><label>Ledger Name(2)</label>
        <?php echo form::select_field_from_object('ledger_id', gl_ledger::find_all(), 'gl_ledger_id', 'ledger', $$class->ledger_id, 'ledger_id', $readonly1, '', '', 1); ?>
       </li>
       <li><label>Period Name(4)</label>
        <?php
        if (!empty($period_name_stmt)) {
         echo $period_name_stmt;
        } else {
         $f->text_field_d('period_id');
        }
        ?>
       </li>
       <li><label>Payment Type(5)</label>
        <?php echo $f->select_field_from_object('payment_type', ap_payment_header::payment_types(), 'option_line_code', 'option_line_value', $ap_payment_header->payment_type, 'payment_type', '', 1, $readonly1); ?>
       </li>
       <li><label>Document Date</label>  <?php echo $f->date_fieldFromToday_d('document_date', $$class->document_date, 1) ?>              </li>
       <li><label>Document Number : </label>
        <?php echo $f->text_field_d('document_number') ?>
       </li>
       <li><?php echo $f->hidden_field_withId('supplier_id', $$class->supplier_id); ?>
        <label class="auto_complete">Supplier Name</label> <?php echo $f->text_field('supplier_name', $$class->supplier_name, '20', 'supplier_name', 'select_supplier_name', 1, $readonly1); ?> </li>
       <li><label class="auto_complete">Supplier Number : </label> <?php $f->text_field_d('supplier_number'); ?></li>
       <li><label>Supplier Site</label>
        <?php
        $supplier_site_obj = !empty($$class->supplier_id) ? supplier_site::find_by_parent_id($$class->supplier_id) : array();
        echo $f->select_field_from_object('supplier_site_id', $supplier_site_obj, 'supplier_site_id', 'supplier_site_name', $$class->supplier_site_id, 'supplier_site_id', '', '', $readonly1);
        ?> </li>
       <li><label>Payment Status</label>
        <?php echo $f->select_field_from_array('payment_status', ap_payment_header::$payment_status_a, $$class->payment_status, '', '', '', '', $readonly); ?>
       </li> 
       <li><label>Description</label>
        <?php $f->text_field_d('description'); ?>
       </li> 
      </ul>
     </div>
    </div>
    <div id="tabsHeader-2" class="tabContent">
     <div> 
      <ul class="column header_field">
       <li><label>Currency</label>
        <?php echo $f->select_field_from_object('currency', option_header::currencies(), 'option_line_code', 'option_line_value', $$class->currency, 'currency', '', 1, 1); ?>
       </li>
       <li><label>Doc Currency</label>
        <?php echo form::select_field_from_object('doc_currency', option_header::currencies(), 'option_line_code', 'option_line_value', $$class->doc_currency, 'doc_currency', $readonly1, '', '', 1); ?>
       </li>
       <li><label>Pay Group</label><?php $f->text_field_d('pay_group') ?></li>
       <li><label>Exchange Rate Type</label><?php echo $f->select_field_from_object('exchange_rate_type', gl_currency_conversion::currency_conversion_type(), 'option_line_code', 'option_line_code', $$class->exchange_rate_type, 'exchange_rate_type', '', 1, $readonly); ?></li>
       <li><label>Exchange Rate</label><?php $f->text_field_d('exchange_rate'); ?></li>
       <li><label>Header Amount</label><?php echo $f->number_field('header_amount', $$class->header_amount, '', 'header_amount'); ?>
       </li>
       <li><label>Journal Header Id</label><?php $f->text_field_dsr('gl_journal_header_id', 'dont_copy'); ?>
       </li>
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
       <li><label>Action</label>
        <?php
        echo $f->select_field_from_array('payment_action', $$class->action_a, '', 'payment_action', '', '', $readonly, $readonly)
        ?>
       </li>
       <li id="copy_header"><label>Copy Document : </label>
        <input type="button" class="button" id="copy_docHeader" value="Header">
       </li>
       <li id="copy_line"><label></label>
        <input type="button" class="button" id="copy_docLine" value="Lines">
       </li>
      </ul>
     </div>
    </div>

   </div>

  </div>
 </form>
</div>
<div id="form_line" class="form_line"><span class="heading">Payment Lines</span>
 <form action=""  method="post" id="po_site"  name="ap_payment_line">
  <div id="tabsLine">
   <ul class="tabMain">
    <li><a href="#tabsLine-1">Basic</a></li>
    <li><a href="#tabsLine-2">References</a></li>
    <li><a href="#tabsLine-3">Notes</a></li>
   </ul>
   <div class="tabContainer">
    <div id="tabsLine-1" class="tabContent">
     <table class="form_line_data_table">
      <thead> 
       <tr>
        <th>Action</th>
        <th>Seq#</th>
        <th>Line Id</th>
        <th>Line#</th>
        <th>Trnx Id</th>
        <th>Trnx Number</th>
        <th>Payment Amount</th>
        <th>Rate</th>
        <th>GL Amount</th>
        <th>Total Amount</th>
        <th>Paid</th>
        <th>Remaining</th>
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
         <td><?php $f->text_field_wid2sr('ap_transaction_header_id'); ?></td>
         <td><?php $f->text_field_wid2('transaction_number', 'select_transaction_number'); ?>
          <img src="<?php echo HOME_URL; ?>themes/images/serach.png" class="select_ap_transaction_number select_popup"></td>
         <td><?php !empty($$class_second->ap_payment_line_id) ? form::number_field_wid2sr('amount') : form::number_field_wid2s('amount'); ?></td>
         <td><?php !empty($$class_second->ap_payment_line_id) ? form::number_field_wid2sr('exchange_rate') : form::number_field_wid2s('exchange_rate'); ?></td>
         <td><?php !empty($$class_second->ap_payment_line_id) ? form::number_field_wid2sr('gl_amount') : form::number_field_wid2s('gl_amount'); ?></td>
         <td><?php $f->text_field_wid2r('invoice_amount'); ?></td>
         <td><?php $f->text_field_wid2sr('paid_amount'); ?></td>
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
        <th>Seq#</th>
        <th>Line Description</th>
        <th>Ref Key Name</th>
        <th>Ref Key Value</th>
        <th>View Ref Doc</th>
        <th>Status</th>
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
         <td><?php $f->text_field_wid2sr('status'); ?></td>
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