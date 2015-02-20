<div id ="form_header"><span class="heading">AP Transaction Header </span>
 <form action=""  method="post" id="ap_transaction_header"  name="ap_transaction_header">
  <div id="tabsHeader">
   <ul class="tabMain">
    <li><a href="#tabsHeader-1">Basic Info</a></li>
    <li><a href="#tabsHeader-2">Finance</a></li>
    <li><a href="#tabsHeader-3">Payments</a></li>
    <li><a href="#tabsHeader-4">Notes</a></li>
    <li><a href="#tabsHeader-5">Attachments</a></li>
    <li><a href="#tabsHeader-6">Actions</a></li>
   </ul>
   <div class="tabContainer">
    <div id="tabsHeader-1" class="tabContent">
     <div class="large_shadow_box"> 
      <ul class="column header_field">
       <li><label><img src="<?php echo HOME_URL; ?>themes/images/serach.png" class="ap_transaction_header_id select_popup">
         Transaction Id</label>
        <?php $f->text_field_ds('ap_transaction_header_id'); ?>
        <a name="show" href="form.php?class_name=ap_transaction_header&<?php echo "mode=$mode"; ?>" class="show document_id ap_transaction_header_id">
         <i class="fa fa-refresh"></i></a> 
       </li>
       <li><label>Transaction No</label>  <?php $f->text_field_d('transaction_number', 'primary_column2'); ?> </li>
       <li><label>BU Name(1)</label>
        <?php echo $f->select_field_from_object('bu_org_id', org::find_all_business(), 'org_id', 'org', $$class->bu_org_id, 'bu_org_id', '', 1, $readonly1); ?>
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
       <li><label>Transaction Type(5)</label>
        <?php echo $f->select_field_from_object('transaction_type', ap_transaction_header::transaction_types(), 'option_line_code', 'option_line_value', $ap_transaction_header->transaction_type, 'transaction_type', '', 1, $readonly1); ?>
       </li>
       <li><label>Document Date</label>  <?php echo $f->date_fieldFromToday_d('document_date', $$class->document_date, 1) ?>              </li>
       <li><label>Document Number</label>   <?php echo $f->text_field_d('document_number') ?>      </li>
       <li><?php echo $f->hidden_field_withId('supplier_id', $$class->supplier_id); ?>
        <label class="auto_complete"><img src="<?php echo HOME_URL; ?>themes/images/serach.png" class="supplier_id select_popup clickable">
         Supplier Name</label> 
        <?php echo $f->text_field('supplier_name', $$class->supplier_name, '20', 'supplier_name', 'select_supplier_name', 1, $readonly1); ?> </li>
       <li><label class="auto_complete">Supplier Number : </label> <?php $f->text_field_d('supplier_number'); ?></li>
       <li><label>Supplier Site</label>
        <?php
        $supplier_site_obj = !empty($$class->supplier_id) ? supplier_site::find_by_parent_id($$class->supplier_id) : array();
        echo $f->select_field_from_object('supplier_site_id', $supplier_site_obj, 'supplier_site_id', 'supplier_site_name', $$class->supplier_site_id, 'supplier_site_id', '', '', $readonly1);
        ?> </li>
       <li><label>Doc Owner</label>   <?php $f->text_field_d('document_owner'); ?>    </li> 
       <li><label>Doc Status</label>
        <?php echo $f->select_field_from_array('transaction_status', ap_transaction_header::$transaction_status_a, $$class->transaction_status, 'transaction_status', 'dont_copy', '', '', $readonly); ?>
       </li> 
       <li><label>Description</label>      <?php $f->text_field_d('description'); ?>       </li> 
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
       <li><label>Pay Group</label>               <?php $f->text_field_d('pay_group') ?>              </li>
       <li><label>Exchange Rate Type</label><?php echo $f->select_field_from_object('exchange_rate_type', gl_currency_conversion::currency_conversion_type(), 'option_line_code', 'option_line_code', $$class->exchange_rate_type, 'exchange_rate_type', '', 1, $readonly); ?></li>
       <li><label>Exchange Rate</label>               <?php $f->text_field_d('exchange_rate'); ?>              </li>
       <li><label>Header Amount</label> <?php echo $f->number_field('header_amount', $$class->header_amount, '15', 'header_amount'); ?> </li>
       <li><label>Tax Amount</label><?php echo $f->number_field('tax_amount', $$class->tax_amount, '15', 'tax_amount'); ?></li>
       <li><label>Paid Amount</label>               <?php echo $f->number_field('paid_amount', $$class->paid_amount, '', 'paid_amount', 'dont_copy', '', 1); ?>              </li>
       <li><label>Payment Status</label>
        <?php echo $f->select_field_from_array('payment_status', ap_transaction_header::$payment_status_a, $$class->payment_status, 'payment_status', 'dont_copy', '', '', 1); ?>
       </li>
       <li><label>Journal Header Id</label>               <?php $f->text_field_dr('gl_journal_header_id', 'dont_copy'); ?>              </li>
       <li><label>Payment Term Date</label>
        <?php echo form::date_fieldAnyDay('payment_term_date', $$class->payment_term_date) ?>
       </li>
       <li><label>Payment Term</label>
        <?php echo $f->select_field_from_object('payment_term_id', payment_term::find_all(), 'payment_term_id', 'payment_term', $$class->payment_term_id, 'payment_term_id', '', 1, $readonly1); ?>
       </li>
      </ul>
     </div>
    </div>
    <div id="tabsHeader-3" class="tabContent">
     <div> 

     </div>
    </div>
    <div id="tabsHeader-4" class="tabContent">
     <div id="comments">
      <div id="comment_list">
       <?php echo!(empty($comments)) ? $comments : ""; ?>
      </div>
      <div id ="display_comment_form">
       <?php
       $reference_table = 'ap_transaction_header';
       $reference_id = $$class->ap_transaction_header_id;
       ?>
      </div>
      <div id="new_comment">
      </div>
     </div>
    </div>
    <div id="tabsHeader-5" class="tabContent">
     <div> <?php echo ino_attachement($file) ?> </div>
    </div>

    <div id="tabsHeader-6" class="tabContent">
     <div> 
      <ul class="column five_column">
       <li><label>Action</label>
        <?php
        echo $f->select_field_from_array('transaction_action', $$class->action_a, '', 'transaction_action', '', '', $readonly, $action_readonly)
        ?>
       </li>
       <li id="document_print"><label>Document Print : </label>
        <a class="button" target="_blank"
           href="po_print.php?ap_transaction_header_id=<?php echo!(empty($$class->ap_transaction_header_id)) ? $$class->ap_transaction_header_id : ""; ?>" >Transaction</a>
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
<div id="form_line" class="form_line"><span class="heading">Transaction Lines & Details </span>
 <form action=""  method="post" id="po_site"  name="ap_transaction_line">
  <div id="tabsLine">
   <ul class="tabMain">
    <li><a href="#tabsLine-1">Basic</a></li>
    <li><a href="#tabsLine-2">Other Info</a></li>
    <li><a href="#tabsLine-3">References</a></li>
    <li><a href="#tabsLine-4">Notes</a></li>
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
        <th>Type</th>
        <th>Item Number</th>
        <th>Item Description</th>
        <th>UOM</th>
        <th>Quantity</th>
        <th>Shipment Details</th>
       </tr>
      </thead>
      <tbody class="form_data_line_tbody">
       <?php
       $count = 0;
       foreach ($ap_transaction_line_object as $ap_transaction_line) {
        $f->readonly2 = !empty($ap_transaction_line->ap_transaction_line_id) ? true : false;
        ?>         
        <tr class="ap_transaction_line<?php echo $count ?>">
         <td>
          <?php
          echo ino_inline_action($$class_second->ap_transaction_line_id, array('ap_transaction_header_id' => $$class->ap_transaction_header_id,
           'tax_code_value' => $$class_second->tax_code_value));
          ?>
         </td>
         <td><?php $f->seq_field_d($count) ?></td>
         <td><?php form::text_field_wid2sr('ap_transaction_line_id'); ?></td>
         <td><?php echo form::text_field('line_number', $$class_second->line_number, '8', '20', 1, 'Auto no', '', $readonly, 'lines_number'); ?></td>
         <td><?php echo $f->select_field_from_object('line_type', ap_transaction_line::ap_transaction_line_types(), 'option_line_code', 'option_line_value', $$class_second->line_type, '', 'line_type', '', $readonly); ?></td>
         <td><?php
          echo $f->hidden_field('item_id_m', $$class_second->item_id_m);
          form::text_field_wid2('item_number', 'select_item_number');
          ?>
          <img src="<?php echo HOME_URL; ?>themes/images/serach.png" class="select_item_number select_popup"></td>
         <td><?php $f->text_field_wid2('item_description'); ?></td>
         <td><?php echo $f->select_field_from_object('uom_id', uom::find_all(), 'uom_id', 'uom_name', $$class_second->uom_id, '', '', '', $readonly); ?></td>
         <td><?php echo $f->number_field('inv_line_quantity', $$class_second->inv_line_quantity); ?></td>
         <td class="add_detail_values"><img src="<?php echo HOME_URL; ?>themes/images/page_add_icon_16.png" class="add_detail_values_img" alt="add detail values" />
          <!--</td></tr>-->	
          <?php
          $ap_transaction_line_id = $ap_transaction_line->ap_transaction_line_id;
          if (!empty($ap_transaction_line_id)) {
           $ap_transaction_detail_object = ap_transaction_detail::find_by_ap_transaction_lineId($ap_transaction_line_id);
          } else {
           $ap_transaction_detail_object = array();
          }
          if (count($ap_transaction_detail_object) == 0) {
           $ap_transaction_detail = new ap_transaction_detail();
           $ap_transaction_detail_object = array();
           array_push($ap_transaction_detail_object, $ap_transaction_detail);
          }
          ?>
                                  <!--						 <tr><td>-->
          <div class="class_detail_form">
           <fieldset class="form_detail_data_fs"><legend>Detail Data</legend>
            <div class="tabsDetail">
             <ul class="tabMain">
              <li class="tabLink"><a href="#tabsDetail-1-<?php echo $count ?>">Basic</a></li>
              <li class="tabLink"><a href="#tabsDetail-2-<?php echo $count ?>">References</a></li>
             </ul>
             <div class="tabContainer">
              <div id="tabsDetail-1-<?php echo $count ?>" class="tabContent">
               <table class="form form_detail_data_table detail">
                <thead>
                 <tr>
                  <th>Action</th>
                  <th>Seq#</th>
                  <th>Detail Id</th>
                  <th>Type</th>
                  <th>Account</th>
                  <th>Period</th>
                  <th>Amount</th>
                  <th>Description</th>
                 </tr>
                </thead>
                <tbody class="form_data_detail_tbody <?php echo $count ?>">
                 <?php
                 $detailCount = 0;
                 foreach ($ap_transaction_detail_object as $ap_transaction_detail) {
                  $class_third = 'ap_transaction_detail';
                  $$class_third = &$ap_transaction_detail;
//												pa($ap_transaction_detail);
                  ?>
                  <tr class="ap_transaction_detail<?php echo $count . '-' . $detailCount; ?>">
                   <td>
                    <?php
                    echo ino_inline_action($$class_third->ap_transaction_detail_id, array('ap_transaction_header_id' => $$class->ap_transaction_header_id,
                     'ap_transaction_line_id' => $$class_second->ap_transaction_line_id), 'add_row_detail_img', 'detail_id_cb');
                    ?>
                   </td>
                   <td><?php $f->seq_field_detail_d($detailCount) ?></td>
                   <td><?php $f->text_field_wid3sr('ap_transaction_detail_id'); ?></td>
                   <td><?php echo $f->select_field_from_object('account_type', gl_journal_line::gl_journal_line_types(), 'option_line_code', 'option_line_value', $$class_third->account_type); ?></td>
                   <td><?php $f->ac_field_wid3m('detail_ac_id'); ?></td>
                   <td><?php $f->text_field_wid3s('period_id') ?></td>
                   <td><?php echo $f->number_field('amount', $$class_third->amount); ?></td>
                   <td><?php $f->text_field_wid3('description'); ?></td>
                  </tr>
                  <?php
                  $detailCount++;
                 }
                 ?>
                </tbody>
               </table>
              </div>
              <div id="tabsDetail-2-<?php echo $count ?>" class="tabContent">
               <table class="form form_detail_data_table detail">
                <thead>
                 <tr>
                  <th>Seq#</th>
                  <th>Ref Key Name</th>
                  <th>Ref Key Value</th>
                  <th>View Ref Doc</th>
                  <th>Status</th>
                 </tr>
                </thead>
                <tbody class="form_data_detail_tbody <?php echo $count ?>">
                 <?php
                 $detailCount = 0;
                 foreach ($ap_transaction_detail_object as $ap_transaction_detail) {
                  $class_third = 'ap_transaction_detail';
                  $$class_third = &$ap_transaction_detail;
                  ?>
                  <tr class="ap_transaction_detail<?php echo $count . '-' . $detailCount; ?> ">
                   <td><?php $f->seq_field_detail_d($detailCount) ?></td>
                   <td><?php $f->text_field_d3('reference_key_name'); ?></td>
                   <td><?php $f->text_field_d3('reference_key_value'); ?></td>
                   <td><?php echo!empty($ref_doc_stmt) ? $ref_doc_stmt : '' ?></td>
                   <td><?php $f->text_field_wid3sr('status'); ?></td>
                  </tr>
                  <?php
                  $detailCount++;
                 }
                 ?>
                </tbody>
               </table>
              </div>
             </div>
            </div>


           </fieldset>

          </div>

         </td></tr>
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
        <th>Unit Price</th>
        <th>Line Amount</th>
        <th>Tax Code</th>
        <th>Tax Amount</th>
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
       foreach ($ap_transaction_line_object as $ap_transaction_line) {
        ?>         
        <tr class="ap_transaction_line<?php echo $count ?>">
         <td><?php $f->seq_field_d($count) ?></td>
         <td><?php echo $f->number_field('inv_unit_price', $$class_second->inv_unit_price); ?></td>
         <td><?php echo $f->number_field('inv_line_price', $$class_second->inv_line_price); ?></td>
         <td><?php echo $f->select_field_from_object('tax_code_id', mdm_tax_code::find_all_inTax_by_bu_org_id($$class->bu_org_id), 'mdm_tax_code_id', 'tax_code', $$class_second->tax_code_id, '', 'input_tax medium') ?></td>
         <td><?php echo $f->number_field('tax_amount', $$class_second->tax_amount); ?></td>
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
    <div id="tabsLine-3" class="scrollElement tabContent">
     <table class="form_line_data_table">
      <thead> 
       <tr>
        <th>Seq#</th>
        <th>PO Header Id</th>
        <th>PO Line Id</th>
        <th>PO Detail Id</th>
        <th>Is Asset</th>
        <th>Asset Category</th>
        <th>Project Header Id</th>
        <th>Project Line Id</th>
        <th>Trnx Header Id</th>
        <th>Trnx Line Id</th>
       </tr>
      </thead>
      <tbody class="form_data_line_tbody">
       <?php
       $count = 0;
       foreach ($ap_transaction_line_object as $ap_transaction_line) {
        ?>         
        <tr class="ap_transaction_line<?php echo $count ?>">
         <td><?php $f->seq_field_d($count) ?></td>
         <td><?php $f->text_field_wid2sr('po_header_id'); ?></td>
         <td><?php $f->text_field_wid2sr('po_line_id'); ?></td>
         <td><?php $f->text_field_wid2sr('po_detail_id'); ?></td>
         <td><?php echo $f->checkBox_field('asset_cb', $$class_second->asset_cb); ?></td>
         <td><?php $f->text_field_wid2sr('fa_asset_category_id'); ?></td>
         <td><?php $f->text_field_wid2sr('prj_project_header_id'); ?></td>
         <td><?php $f->text_field_wid2sr('prj_project_line_id'); ?></td>
         <td><?php $f->text_field_wid2sr('ref_transaction_header_id'); ?></td>
         <td><?php $f->text_field_wid2sr('ref_transaction_line_id'); ?></td>
        </tr>
        <?php
        $count = $count + 1;
       }
       ?>
      </tbody>
      <!--                  Showing a blank form for new entry-->
     </table>
    </div>
    <div id="tabsLine-4" class="tabContent">
     <table class="form_line_data_table">
      <thead> 
       <tr>
        <th>Comments</th>

       </tr>
      </thead>
      <tbody class="form_data_line_tbody">
       <?php
       $count = 0;
       foreach ($ap_transaction_line_object as $ap_transaction_line) {
        ?>         
        <tr class="ap_transaction_line<?php echo $count ?>">
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
  <li class="headerClassName" data-headerClassName="ap_transaction_header" ></li>
  <li class="lineClassName" data-lineClassName="ap_transaction_line" ></li>
  <li class="detailClassName" data-detailClassName="ap_transaction_detail" ></li>
  <li class="savingOnlyHeader" data-savingOnlyHeader="false" ></li>
  <li class="primary_column_id" data-primary_column_id="ap_transaction_header_id" ></li>
  <li class="form_header_id" data-form_header_id="ap_transaction_header" ></li>
  <li class="line_key_field" data-line_key_field="item_description" ></li>
  <li class="single_line" data-single_line="false" ></li>
  <li class="form_line_id" data-form_line_id="ap_transaction_line" ></li>
 </ul>
 <ul id="js_contextMenu_data">
  <li class="docHedaderId" data-docHedaderId="ap_transaction_header_id" ></li>
  <li class="docLineId" data-docLineId="ap_transaction_line_id" ></li>
  <li class="docDetailId" data-docDetailId="ap_transaction_detail_id" ></li>
  <li class="btn1DivId" data-btn1DivId="ap_transaction_header" ></li>
  <li class="btn2DivId" data-btn2DivId="form_line" ></li>
  <li class="tbodyClass" data-tbodyClass="form_data_line_tbody" ></li>
  <li class="noOfTabbs" data-noOfTabbs="3" ></li>
 </ul>
</div>