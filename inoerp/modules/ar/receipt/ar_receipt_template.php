<div id ="form_header"><span class="heading">Receipt Header </span>
 <form action=""  method="post" id="ar_receipt_header"  name="ar_receipt_header">
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
       <li><label><img src="<?php echo HOME_URL; ?>themes/images/serach.png" class="ar_receipt_header_id select_popup clickable">
         Receipt Id</label><?php $f->text_field_dsr('ar_receipt_header_id'); ?>
        <a name="show" href="form.php?class_name=ar_receipt_header&<?php echo "mode=$mode"; ?>" class="show document_id ar_receipt_header_id"><i class="fa fa-refresh"></i></a> 
       </li>
       <li><label>Receipt No</label><?php $f->text_field_d('receipt_number'); ?></li>
       <li><label>Type</label><?php echo $f->select_field_from_array('receipt_type', ar_receipt_header::$receipt_type_a, $$class->receipt_type,'receipt_type'); ?></li>
       <li><label>BU Name(1)</label><?php echo $f->select_field_from_object('bu_org_id', org::find_all_business(), 'org_id', 'org', $$class->bu_org_id, 'bu_org_id', '', 1, $readonly1); ?></li>
       <li><label>Ledger Name(2)</label><?php echo form::select_field_from_object('ledger_id', gl_ledger::find_all(), 'gl_ledger_id', 'ledger', $$class->ledger_id, 'ledger_id', $readonly1, '', '', 1); ?></li>
       <li><label>Period Name(4)</label><?php
        if (!empty($period_name_stmt)) {
         echo $period_name_stmt;
        } else {
         $f->text_field_d('period_id');
        }
        ?>
       </li>
       <li><label>Receipt Source(5)</label><?php echo $f->select_field_from_object('ar_receipt_source_id', ar_receipt_source::find_all(), 'ar_receipt_source_id', 'receipt_source', $$class->ar_receipt_source_id, 'ar_receipt_source_id', '', 1, $readonly); ?>			 </li>
       <li><label>Document Date</label><?php echo $f->date_fieldFromToday_d('document_date', $$class->document_date, 1) ?></li>
       <li><label>Document Number</label><?php echo $f->text_field_d('document_number') ?></li>
       <li><?php echo $f->hidden_field_withId('ar_customer_id', $$class->ar_customer_id); ?><label class="auto_complete"><img src="<?php echo HOME_URL; ?>themes/images/serach.png" class="ar_customer_id select_popup clickable">
         Customer Name</label><?php echo $f->text_field('customer_name', $$class->customer_name, '20', 'customer_name', 'select_customer_name', '', $readonly1); ?></li>
       <li><label class="auto_complete">Customer Number</label><?php $f->text_field_d('customer_number'); ?></li>
       <li><label>Customer Site</label><?php echo $f->select_field_from_object('ar_customer_site_id', $customer_site_obj, 'ar_customer_site_id', 'customer_site_name', $$class->ar_customer_site_id, 'ar_customer_site_id', 'ar_customer_site_id', '', $readonly1); ?> </li>
       <li><label>Doc Status</label><?php echo $f->select_field_from_array('receipt_status', ar_receipt_header::$receipt_status_a, $$class->receipt_status, '', '', '', '', $readonly); ?>			 </li> 
       <li><label>Description</label><?php $f->text_field_d('description'); ?></li> 
      </ul>
     </div>
    </div>
    <div id="tabsHeader-2" class="tabContent">
     <div> 
      <ul class="column header_field">
       <li><label>Currency</label><?php echo form::select_field_from_object('currency', option_header::currencies(), 'option_line_code', 'option_line_value', $$class->currency, 'doc_currency', $readonly1, '', '', 1); ?></li>
       <li><label>Doc Currency</label><?php echo form::select_field_from_object('doc_currency', option_header::currencies(), 'option_line_code', 'option_line_value', $$class->doc_currency, 'doc_currency', '', '', '', 1); ?>						 </li>
       <li><label>Exchange Rate Type</label><?php echo $f->select_field_from_object('exchange_rate_type', gl_currency_conversion::currency_conversion_type(), 'option_line_code', 'option_line_code', $$class->exchange_rate_type, 'exchange_rate_type', '', 1, $readonly); ?></li>
       <li><label>Exchange Rate</label><?php $f->text_field_d('exchange_rate'); ?>              </li>
       <li><label>Header Amount</label><?php form::number_field_d('header_amount'); ?></li>
       <li><label>Journal Header Id</label><?php $f->text_field_dr('gl_journal_header_id'); ?></li>
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
      <ul class="column five_column">
       <li><label>Action</label>
        <?php echo $f->select_field_from_array('receipt_action', $$class->receipt_action_a, '', 'receipt_action'); ?>
       </li>
       <li id="document_print"><label>Document Print : </label>
        <a class="button" target="_blank"
           href="po_print.php?ar_receipt_header_id=<?php echo!(empty($$class->ar_receipt_header_id)) ? $$class->ar_receipt_header_id : ""; ?>" >Receipt</a>
       </li>
       <li id="copy_header"><label>Copy Document : </label>
        <input type="button" class="button" id="copy_docHeader" value="Header">
       </li>
       <li id="copy_line"><label></label>
        <input type="button" class="button" id="copy_docLine" value="Lines">
       </li>
      </ul>

      <div id="comment" class="shoe_comments">
      </div>
     </div>
    </div>

   </div>

  </div>
 </form>
</div>

<div id="form_line" class="form_line"><span class="heading">Receipt Lines</span>
 <form action=""  method="post" id="ar_receipt_line"  name="ar_receipt_line">
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
        <th>Line Id</th>
        <th>Line#</th>
        <th>Trnx Id</th>
        <th>Trnx Number</th>
        <th>Receipt Amount</th>
        <th>Exchange Rate</th>
        <th>GL Amount</th>
        <th>Total Amount</th>
        <th>Cumulative Receipt</th>
        <th>Remaining</th>
       </tr>
      </thead>
      <tbody class="form_data_line_tbody">
       <?php
       $count = 0;
       foreach ($ar_receipt_line_object as $ar_receipt_line) {
        $f->readonly2 = !empty($ar_receipt_line->ar_receipt_line_id) ? true : false;
        ?>         
        <tr class="ar_receipt_line<?php echo $count ?>">
         <td>
          <?php
          echo ino_inline_action($$class_second->ar_receipt_line_id, array('ar_receipt_header_id' => $$class->ar_receipt_header_id));
          ?>
         </td>
         <td><?php form::text_field_wid2sr('ar_receipt_line_id'); ?></td>
         <td><?php echo form::text_field('line_number', $$class_second->line_number, '8', '20', 1, 'Auto no', '', $readonly, 'lines_number'); ?></td>
         <td><?php $f->text_field_wid2sr('ar_transaction_header_id'); ?></td>
         <td><?php $f->text_field_wid2('transaction_number', 'select_transaction_number'); ?>
          <img src="<?php echo HOME_URL; ?>themes/images/serach.png" class="select_transaction_number select_popup clickable"></td>
         <td><?php !empty($$class_second->ar_receipt_line_id) ? form::number_field_wid2sr('amount') : $f->text_field_wid2s('amount'); ?></td>
         <td><?php !empty($$class_second->ar_receipt_line_id) ? form::number_field_wid2sr('exchange_rate') : $f->text_field_wid2s('exchange_rate'); ?></td>
          <td><?php !empty($$class_second->ar_receipt_line_id) ? form::number_field_wid2sr('gl_amount') : $f->text_field_wid2s('gl_amount'); ?></td>
         <td><?php $f->text_field_wid2sr('invoice_amount'); ?></td>
         <td><?php $f->text_field_wid2sr('receipt_amount'); ?></td>
         <td><?php $f->text_field_wid2r('remaining_amount'); ?></td>
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
       foreach ($ar_receipt_line_object as $ar_receipt_line) {
        ?>         
        <tr class="ar_receipt_line<?php echo $count ?>">
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