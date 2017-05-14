<div id ="form_header"><span class="heading"><?php echo gettext('AP Transaction Header') ?></span>
 <form  method="post" id="ap_transaction_header"  name="ap_transaction_header">
  <div id="tabsHeader">
   <ul class="tabMain">
    <li><a href="#tabsHeader-1"><?php echo gettext('Basic Info') ?></a></li>
    <li><a href="#tabsHeader-2"><?php echo gettext('Finance') ?></a></li>
    <li><a href="#tabsHeader-3"><?php echo gettext('Payments') ?></a></li>
    <li><a href="#tabsHeader-4"><?php echo gettext('Notes') ?></a></li>
    <li><a href="#tabsHeader-5"><?php echo gettext('Attachments') ?></a></li>
    <li><a href="#tabsHeader-6"><?php echo gettext('Actions') ?></a></li>
   </ul>
   <div class="tabContainer">
    <div id="tabsHeader-1" class="tabContent">
     <ul class="column header_field">
      <li><?php $f->l_text_field_dr_withSearch('ap_transaction_header_id'); ?>
       <a name="show" href="form.php?class_name=ap_transaction_header&<?php echo "mode=$mode"; ?>" class="show document_id ap_transaction_header_id">
        <i class="fa fa-refresh"></i></a> 
      </li>
      <li><?php $f->l_text_field_d('transaction_number', 'primary_column2'); ?> </li>
      <li><?php $f->l_select_field_from_object('bu_org_id', org::find_all_business(), 'org_id', 'org', $$class->bu_org_id, 'bu_org_id', '', 1, $readonly1); ?>       </li>
      <li><?php $f->l_select_field_from_object('ledger_id', gl_ledger::find_all(), 'gl_ledger_id', 'ledger', $$class->ledger_id, 'ledger_id', 'always_readonly', 1, $readonly1); ?>       </li>
      <li><label><?php echo gettext('Period Name') ?></label><?php
       if (!empty($period_name_stmt)) {
        echo $period_name_stmt;
       } else {
        $f->text_field_d('period_id');
       }
       ?></li>
      <li><?php $f->l_select_field_from_object('transaction_type', ap_transaction_header::transaction_types(), 'option_line_code', 'option_line_value', $ap_transaction_header->transaction_type, 'transaction_type', '', 1, $readonly1); ?>       </li>
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
      <li><?php 
       echo $f->l_val_field_d('document_owner', 'hr_employee_v', 'employee_name', '', 'vf_select_document_owner employee_name');
       echo $f->hidden_field_withId('hr_employee_id', $$class->hr_employee_id);
       ?><i class="generic g_select_document_owner select_popup clickable fa fa-search" data-class_name="hr_employee_v"></i></li>
      <li><?php $f->l_select_field_from_array('transaction_status', ap_transaction_header::$transaction_status_a, $$class->transaction_status, 'transaction_status', 'dont_copy', '', '', $readonly); ?>      </li> 
      <li><?php $f->l_text_field_d('description'); ?>       </li> 
     </ul>
    </div>
    <div id="tabsHeader-2" class="tabContent">
     <div> 
      <ul class="column header_field">
       <li><?php $f->l_select_field_from_object('doc_currency', option_header::currencies(), 'option_line_code', 'option_line_code', $$class->doc_currency, 'doc_currency', '', 1, $readonly); ?></li>
       <li><?php $f->l_select_field_from_object('ledger_currency', option_header::currencies(), 'option_line_code', 'option_line_code', $$class->currency, 'currency', 'currency', 1, 1); ?></li>
       <li><?php $f->l_select_field_from_object('exchange_rate_type', gl_currency_conversion::currency_conversion_type(), 'option_line_code', 'option_line_code', $$class->exchange_rate_type, 'exchange_rate_type', '', 1, $readonly); ?></li>
       <li><?php $f->l_number_field('exchange_rate', $$class->exchange_rate, '', 'exchange_rate'); ?> </li>
       <li><?php $f->l_number_field('header_amount', $$class->header_amount, '15', 'header_amount'); ?></li>
       <li><?php $f->l_number_field('tax_amount', $$class->tax_amount, '15', 'tax_amount'); ?></li>
       <li><?php $f->l_select_field_from_object('payment_term_id', payment_term::find_all(), 'payment_term_id', 'payment_term', $$class->payment_term_id, 'payment_term_id', '', 1, $readonly1); ?></li>
       <li><?php $f->l_date_fieldAnyDay('payment_term_date', $$class->payment_term_date) ?></li>
       <li><?php $f->l_text_field_d('pay_group') ?>              </li>
       <li><?php $f->l_number_field_dr('paid_amount', 'dont_copy'); ?>              </li>
       <li><?php $f->l_select_field_from_array('payment_status', ap_transaction_header::$payment_status_a, $$class->payment_status, 'payment_status', 'dont_copy', '', '', 1); ?>       </li>
       <li><?php $f->l_text_field_dr('gl_journal_header_id', 'dont_copy'); ?> </li>
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
       <li><label><?php echo gettext('Action') ?></label>
        <?php
        echo $f->select_field_from_array('transaction_action', $$class->action_a, '', 'transaction_action', 'action', '', $readonly, $action_readonly)
        ?>
       </li>
       <!--       <li id="document_print"><label><?php //echo gettext('Document Print') ?> : </label>
               <a class="button" target="_blank"
                  href="po_print.php?ap_transaction_header_id=<?php // echo!(empty($$class->ap_transaction_header_id)) ? $$class->ap_transaction_header_id : "";    ?>" ><?php //echo gettext('Transaction') ?></a>
              </li>-->
      </ul>

      <div id="comment" class="shoe_comments">
      </div>
     </div>
    </div>

   </div>

  </div>
 </form>
</div>
<div id="form_line" class="form_line"><span class="heading"><?php echo gettext('Transaction Lines & Details') ?></span>
 <form  method="post" id="ap_transaction_line"  name="ap_transaction_line">
  <div id="tabsLine">
   <ul class="tabMain">
    <li><a href="#tabsLine-1"><?php echo gettext('Basic') ?></a></li>
    <li><a href="#tabsLine-2"><?php echo gettext('Finance') ?> </a></li>
    <li><a href="#tabsLine-3"><?php echo gettext('References') ?> </a></li>
    <li><a href="#tabsLine-4"><?php echo gettext('Actions') ?> </a></li>
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
        <th><?php echo gettext('Type') ?></th>
        <th><?php echo gettext('Item Number') ?></th>
        <th><?php echo gettext('Item Description') ?></th>
        <th><?php echo gettext('UOM') ?></th>
        <th><?php echo gettext('Quantity') ?></th>
        <th><?php echo gettext('Accounting Details') ?></th>
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
         <td><?php echo $f->select_field_from_object('line_type', ap_transaction_line::ap_transaction_line_types(), 'option_line_code', 'option_line_value', $$class_second->line_type, '', 'line_type', '', $f->readonly2, $f->readonly2); ?></td>
         <td><?php
          $f->val_field_wid2('item_number', 'item', 'item_number', 'receving_org_id');
          echo $f->hidden_field_withCLass('item_id_m', $$class_second->item_id_m,'dont_copy_r');
          echo $f->hidden_field_withCLass('invoiceable_cb', '1', 'popup_value');
          ?>
          <i class="generic g_select_item_number select_popup clickable fa fa-search" data-class_name="item"></i></td>
         <td><?php $f->text_field_wid2('item_description'); ?></td>
         <td><?php echo $f->select_field_from_object('uom_id', uom::find_all(), 'uom_id', 'uom_name', $$class_second->uom_id, '', '', '', $readonly); ?></td>
         <td><?php echo $f->number_field('inv_line_quantity', $$class_second->inv_line_quantity, '', '', 'small', '', $readonly1); ?></td>
         <td class="add_detail_values"><i class="fa fa-arrow-circle-down add_detail_values_img"></i>
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
           <fieldset class="form_detail_data_fs">
            <div class="tabsDetail">
             <ul class="tabMain">
              <li class="tabLink"><a href="#tabsDetail-1-<?php echo $count ?>"><?php echo gettext('Basic') ?></a></li>
              <li class="tabLink"><a href="#tabsDetail-2-<?php echo $count ?>"><?php echo gettext('References') ?></a></li>
             </ul>
             <div class="tabContainer">
              <div id="tabsDetail-1-<?php echo $count ?>" class="tabContent">
               <table class="form form_detail_data_table detail">
                <thead>
                 <tr>
                  <th><?php echo gettext('Action') ?></th>
                  <th><?php echo gettext('Seq') ?>#</th>
                  <th><?php echo gettext('Detail Id') ?></th>
                  <th><?php echo gettext('Type') ?></th>
                  <th><?php echo gettext('Account') ?></th>
                  <th><?php echo gettext('Period') ?></th>
                  <th><?php echo gettext('Amount') ?></th>
                  <th><?php echo gettext('GL Amount') ?></th>
                  <th><?php echo gettext('Description') ?></th>
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
                   <td><?php echo $f->number_field('gl_amount', $$class_third->gl_amount); ?></td>
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
                  <th><?php echo gettext('Seq') ?>#</th>
                  <th><?php echo gettext('Ref Key Name') ?></th>
                  <th><?php echo gettext('Ref Key Value') ?></th>
                  <th><?php echo gettext('View Ref Doc') ?></th>
                  <th><?php echo gettext('Status') ?>#</th>
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
        <th><?php echo gettext('Seq') ?>#</th>
        <th><?php echo gettext('Unit Price') ?></th>
        <th><?php echo gettext('Line Amount') ?>#</th>
        <th><?php echo gettext('Tax Code') ?></th>
        <th><?php echo gettext('Tax Amount') ?></th>
        <th><?php echo gettext('GL Line Price') ?></th>
        <th><?php echo gettext('GL Tax Amount') ?></th>
        <th><?php echo gettext('Line Description') ?></th>
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
         <td><?php echo $f->select_field_from_object('tax_code_id', mdm_tax_code::find_all_inTax_by_bu_org_id($$class->bu_org_id), 'mdm_tax_code_id', 'tax_code', $$class_second->tax_code_id, '', 'input_tax medium', '', $readonly, '', '', '', 'percentage') ?></td>
         <td><?php echo $f->number_field('tax_amount', $$class_second->tax_amount); ?></td>
         <td><?php form::number_field_wid2('gl_inv_line_price'); ?></td>
         <td><?php form::number_field_wid2('gl_tax_amount'); ?></td>
         <td><?php $f->text_field_wid2('line_description'); ?></td>

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
        <th><?php echo gettext('Seq') ?>#</th>
        <th><?php echo gettext('PO Header Id') ?></th>
        <th><?php echo gettext('PO Line Id') ?></th>
        <th><?php echo gettext('PO Detail Id') ?>#</th>
        <th><?php echo gettext('Is Asset') ?></th>
        <th><?php echo gettext('Asset Category') ?></th>
        <th><?php echo gettext('Project Header Id') ?></th>
        <th><?php echo gettext('Project Line Id') ?></th>
        <th><?php echo gettext('Trnx Header Id') ?></th>
        <th><?php echo gettext('Trnx Line Id') ?></th>
        <th><?php echo gettext('Ref Key Name') ?></th>
        <th><?php echo gettext('Ref Key Value') ?></th>
        <th><?php echo gettext('View Ref Doc') ?></th>
        <th><?php echo gettext('Status') ?></th>
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
    <div id="tabsLine-4" class="scrollElement tabContent">
     <table class="form_line_data_table">
      <thead> 
       <tr>
        <th><?php echo gettext('Seq') ?>#</th>
        <th><?php echo gettext('Cancel Line') ?></th>
        <th><?php echo gettext('Un match Only') ?></th>
        <th><?php echo gettext('Change Quantity') ?>#</th>
       </tr>
      </thead>
      <tbody class="form_data_line_tbody">
       <?php
       $count = 0;
       foreach ($ap_transaction_line_object as $ap_transaction_line) {
        ?>         
        <tr class="ap_transaction_line<?php echo $count ?>">
         <td><?php $f->seq_field_d($count) ?></td>
         <td><?php echo $f->checkBox_field('cancel_line_cb', '', '', '', 1); ?></td>
         <td><?php echo $f->checkBox_field('unmatch_only_cb', '', '', '', 1); ?></td>
         <td><?php echo $f->number_field('change_quantity', '', '', '', '', '', 1); ?></td>
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
  <li class="noOfTabbs" data-noOfTabbs="4" ></li>
 </ul>
</div>
