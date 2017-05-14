<div id ="form_header"><span class="heading"><?php echo gettext('Receivable Transaction Header') ?></span>
 <form  method="post" id="ar_transaction_header"  name="ar_transaction_header">
  <div id="tabsHeader">
   <ul class="tabMain">
    <li><a href="#tabsHeader-1"><?php echo gettext('Basic Info') ?></a></li>
    <li><a href="#tabsHeader-2"><?php echo gettext('Basic-2') ?></a></li>
    <li><a href="#tabsHeader-3"><?php echo gettext('Address') ?></a></li>
    <li><a href="#tabsHeader-4"><?php echo gettext('Finance') ?></a></li>
    <li><a href="#tabsHeader-5"><?php echo gettext('Summary') ?></a></li>
    <li><a href="#tabsHeader-6"><?php echo gettext('Receipts') ?></a></li>
    <li><a href="#tabsHeader-7"><?php echo gettext('Notes') ?></a></li>
    <li><a href="#tabsHeader-8"><?php echo gettext('Attachments') ?></a></li>
    <li><a href="#tabsHeader-9"><?php echo gettext('Actions') ?></a></li>
   </ul>
   <div class="tabContainer">
    <div id="tabsHeader-1" class="tabContent">
     <ul class="column header_field">
      <li><?php $f->l_text_field_dr_withSearch('ar_transaction_header_id'); ?>
       <a name="show" href="form.php?class_name=ar_transaction_header&<?php echo "mode=$mode"; ?>" class="show document_id ar_transaction_header_id">
        <i class="fa fa-refresh"></i></a> 
      </li>
      <li><?php $f->l_text_field_d('transaction_number', 'primary_column2'); ?></li>
      <li><?php $f->l_select_field_from_object('bu_org_id', org::find_all_business(), 'org_id', 'org', $$class->bu_org_id, 'bu_org_id', '', 1, $readonly1); ?>             </li>
      <li><?php $f->l_select_field_from_object('transaction_type', ar_transaction_type::find_all(), 'ar_transaction_type_id', ['ar_transaction_type', 'bu_org_id'], $$class->transaction_type, 'transaction_type', '', 1, $readonly1, '', '', '', 'bu_org_id'); ?>             </li>
      <li><?php $f->l_select_field_from_object('ledger_id', gl_ledger::find_all(), 'gl_ledger_id', 'ledger', $$class->ledger_id, 'ledger_id', '', '', $readonly1, 1); ?>             </li>
      <li><label><?php echo gettext('Period Name') ?></label><?php
       if (!empty($period_name_stmt)) {
        echo $period_name_stmt;
       } else {
        $f->text_field_d('period_id');
       }
       ?>
      </li>
      <li><?php $f->l_text_field_dr('transaction_class'); ?></li>
      <li><?php $f->l_date_fieldFromToday_d('document_date', $$class->document_date) ?></li>
      <li><?php $f->l_text_field_d('document_number') ?></li>
      <li><?php $f->l_select_field_from_array('transaction_status', ar_transaction_header::$transaction_status_a, $$class->transaction_status, 'transaction_status', 'always_readonly', '', 1); ?>         </li> 
     </ul>
    </div>
    <div id="tabsHeader-2" class="tabContent">
     <ul class="column header_field">
      <li><?php
       echo $f->l_val_field_dm('customer_name', 'ar_customer', 'customer_name', '', 'customer_name', 'vf_select_customer_name');
       echo $f->hidden_field_withId('ar_customer_id', $$class->ar_customer_id);
       ?><i class="generic g_select_customer_name select_popup clickable fa fa-search" data-class_name="ar_customer"></i></li>
      <li><?php
       echo $f->l_val_field_d('customer_number', 'ar_customer', 'customer_number', '', '', 'vf_select_customer_number');
       ?><i class="generic g_select_customer_number select_popup clickable fa fa-search" data-class_name="ar_customer"></i></li>
      <li><?php $f->l_select_field_from_object('ar_customer_site_id', $customer_site_obj, 'ar_customer_site_id', 'customer_site_name', $$class->ar_customer_site_id, 'ar_customer_site_id', 'ar_customer_site_id', '', $readonly1); ?> </li>
      <li><?php $f->l_text_field_dr('sd_so_number'); ?></li>
      <li><?php $f->l_text_field_d('document_owner'); ?></li> 
      <li><label><?php echo gettext('Approval Status') ?></label><span class="button"><?php echo!empty($$class->approval_status) ? $$class->approval_status : " No Status "; ?></span></li>
      <li><?php $f->l_text_field_d('description'); ?></li> 
      <li><?php $f->l_text_field_d('sales_person') ?></li>
     </ul>					 
    </div>
    <div id="tabsHeader-3" class="tabContent">
     <div class="shipto_address"><?php $f->address_field_d('ship_to_id'); ?></div>
     <div class="billto_address"><?php $f->address_field_d('bill_to_id'); ?></div>
    </div>

    <div id="tabsHeader-4" class="tabContent">
     <div>
      <ul class="column header_field">
       <li><?php $f->l_select_field_from_object('doc_currency', option_header::currencies(), 'option_line_code', 'option_line_code', $$class->doc_currency, 'doc_currency', '', 1, $readonly); ?></li>
       <li><?php $f->l_select_field_from_object('currency', option_header::currencies(), 'option_line_code', 'option_line_code', $$class->currency, 'currency', 'currency', 1, 1); ?></li>
       <li><?php $f->l_select_field_from_object('payment_term_id', payment_term::find_all(), 'payment_term_id', 'payment_term', $$class->payment_term_id, '', 'payment_term_id', 1, $readonly1); ?>						 </li></li>
       <li><?php $f->l_date_fieldAnyDay('payment_term_date', $$class->payment_term_date) ?></li>
       <li><?php $f->l_select_field_from_object('exchange_rate_type', gl_currency_conversion::currency_conversion_type(), 'option_line_code', 'option_line_code', $$class->exchange_rate_type, 'exchange_rate_type', '', 1, $readonly); ?></li>
       <li><?php $f->l_number_field('exchange_rate', $$class->exchange_rate, '', 'exchange_rate'); ?> </li>
       <li><?php $f->l_number_field('header_amount', $$class->header_amount, '15', 'header_amount'); ?></li>
       <li><?php $f->l_number_field('tax_amount', $$class->tax_amount, '15', 'tax_amount'); ?></li>
       <li><?php $f->l_text_field_dr('gl_journal_header_id') ?></li>
       <li><?php $f->l_ac_field_dm('receivable_ac_id'); ?></li>
       <li><?php $f->l_select_field_from_object('ar_revenue_rule_header_id', ar_revenue_rule_header::find_all(), 'ar_revenue_rule_header_id', 'rule_name', $$class->ar_revenue_rule_header_id, 'ar_revenue_rule_header_id'); ?>        </li>
       <li><?php $f->l_select_field_from_array('receivable_rule', ar_transaction_header::$receivable_rule_a, $$class->receivable_rule, 'receivable_rule'); ?>        </li>

      </ul>
     </div>
    </div>
    <div id="tabsHeader-5" class="tabContent">
     <div> 
      <ul class="column header_field">
       <li><?php $f->l_text_field_dr('receipt_status'); ?></li>
       <li><?php $f->l_text_field_dr('receipt_amount'); ?></li>
       <li><label><?php echo gettext('Adjustment Amount'); ?></label><?php echo ar_transaction_adjustment::total_adjustmentAmount_by_transactionHeaderId($$class->ar_transaction_header_id); ?></li>
       <li><label></label><a href="form.php?class_name=ar_transaction_adjustment&mode=2&ar_transaction_header_id=<?php echo $$class->ar_transaction_header_id ?>" class="btn btn-default" role="button">
         <?php echo gettext('View Adjustments') ?></a> 
       </li>
      </ul>
     </div>
    </div>
    <div id="tabsHeader-6" class="tabContent">
     <div> 

     </div>
    </div>
    <div id="tabsHeader-7" class="tabContent">
     <div id="comments">
      <div id="comment_list">
       <?php echo!(empty($comments)) ? $comments : ""; ?>
      </div>
      <div id ="display_comment_form">
       <?php
       $reference_table = 'ar_transaction_header';
       $reference_id = $$class->ar_transaction_header_id;
       ?>
      </div>
      <div id="new_comment">
      </div>
     </div>
    </div>

    <div id="tabsHeader-8" class="tabContent">
     <div> <?php echo ino_attachement($file) ?> </div>
    </div>

    <div id="tabsHeader-9" class="tabContent">
     <div> 
      <ul class="column header_field">
       <li><?php $f->l_select_field_from_array('action', $$class->action_a, '', 'action', '', '', $readonly); ?>       </li>
       <li><label></label><a  role="button" class="quick_select button btn btn-info" target="_blank" 
                               href="<?php echo HOME_URL ?>form.php?class_name=ar_transaction_all_v&amp;router=pdf_print&amp;ar_transaction_header_id=<?php echo!(empty($$class->ar_transaction_header_id)) ? $$class->ar_transaction_header_id : ""; ?>" >
         <?php echo gettext('Print Transaction') ?></a></li>
       <li id="document_status"><label><?php echo gettext('Change Status') ?></label>
        <?php echo form::select_field_from_object('approval_status', ar_transaction_header::ar_approval_status(), 'option_line_code', 'option_line_value', $ar_transaction_header->approval_status, 'set_approval_status', $readonly, '', ''); ?>
       </li>
      </ul>

      <div id="comment" class="show_comments">
      </div>
     </div>
    </div>

   </div>

  </div>
 </form>
</div>

<div id="form_line" class="form_line"><span class="heading"><?php echo gettext('Transaction Lines & Details') ?></span>
 <form  method="post" id="ar_transaction_line"  name="ar_transaction_line">
  <div id="tabsLine">
   <ul class="tabMain">
    <li><a href="#tabsLine-1"><?php echo gettext('Basic') ?></a></li>
    <li><a href="#tabsLine-2"><?php echo gettext('Finance') ?> </a></li>
    <li><a href="#tabsLine-3"><?php echo gettext('References') ?> </a></li>
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
        <th><?php echo gettext('Trnx Account') ?></th>
       </tr>
      </thead>
      <tbody class="form_data_line_tbody">
       <?php
       $count = 0;
       foreach ($ar_transaction_line_object as $ar_transaction_line) {
//							$f->readonly2 = !empty($ar_transaction_line->ar_transaction_line_id) ? true : false;
        ?>         
        <tr class="ar_transaction_line<?php echo $count ?>">
         <td>
          <?php
          echo ino_inline_action($$class_second->ar_transaction_line_id, array('ar_transaction_header_id' => $$class->ar_transaction_header_id,
           'transaction_type' => $$class->transaction_type, 'revenue_ac_id' => $$class_second->revenue_ac_id));
          ?>
         </td>
         <td><?php $f->seq_field_d($count) ?></td>
         <td><?php form::text_field_wid2sr('ar_transaction_line_id'); ?></td>
         <td><?php echo form::text_field('line_number', $$class_second->line_number, '8', '20', 1, 'Auto no', '', $readonly, 'lines_number'); ?></td>
         <td><?php echo $f->select_field_from_object('line_type', ar_transaction_line::ar_transaction_line_types(), 'option_line_code', 'option_line_value', $$class_second->line_type, '', 'line_type medium', '', $readonly1); ?></td>
         <td><?php
          $f->val_field_wid2('item_number', 'item', 'item_number', '', 'xlarge');
          echo $f->hidden_field_withCLass('item_id_m', $$class_second->item_id_m, 'dont_copy_r');
          echo $f->hidden_field_withCLass('customer_ordered_cb', '1', 'popup_value');
          echo $f->hidden_field_withCLass('invoiceable_cb', '1', 'popup_value');
          ?>
          <i class="generic g_select_item_number select_popup clickable fa fa-search" data-class_name="item"></i></td>
         <td><?php $f->text_field_wid2m('item_description', 'xxlarge required'); ?></td>
         <td><?php echo $f->select_field_from_object('uom_id', uom::find_all(), 'uom_id', 'uom_name', $ar_transaction_line->uom_id); ?></td>
         <td><?php form::number_field_wid2sm('inv_line_quantity'); ?></td>
         <td class="add_detail_values"><i class="fa fa-arrow-circle-down add_detail_values_img"></i>
          <!--</td></tr>-->	
          <?php
          $ar_transaction_line_id = $ar_transaction_line->ar_transaction_line_id;
          if (!empty($ar_transaction_line_id)) {
           $ar_transaction_detail_object = ar_transaction_detail::find_by_ar_transaction_lineId($ar_transaction_line_id);
          } else {
           $ar_transaction_detail_object = array();
          }
          if (count($ar_transaction_detail_object) == 0) {
           $ar_transaction_detail = new ar_transaction_detail();
           $ar_transaction_detail_object = array();
           array_push($ar_transaction_detail_object, $ar_transaction_detail);
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
                  <th><?php echo gettext('Detail') ?>#</th>
                  <th><?php echo gettext('Type') ?></th>
                  <th><?php echo gettext('Account') ?></th>
                  <th><?php echo gettext('Amount') ?></th>
                  <th><?php echo gettext('GL-Amount') ?></th>
                  <th><?php echo gettext('Description') ?></th>
                 </tr>
                </thead>
                <tbody class="form_data_detail_tbody">
                 <?php
                 $detailCount = 0;
                 foreach ($ar_transaction_detail_object as $ar_transaction_detail) {
                  $class_third = 'ar_transaction_detail';
                  $$class_third = &$ar_transaction_detail;
//												pa($ar_transaction_detail);
                  ?>
                  <tr class="ar_transaction_detail<?php echo $count . '-' . $detailCount; ?>">
                   <td>
                    <?php
                    echo ino_inline_action($$class_third->ar_transaction_detail_id, array('ar_transaction_header_id' => $$class->ar_transaction_header_id,
                     'ar_transaction_line_id' => $$class_second->ar_transaction_line_id), 'add_row_detail_img', 'detail_id_cb');
                    ?>
                   </td>
                   <td><?php $f->seq_field_detail_d($detailCount) ?></td>
                   <td><?php $f->text_field_wid3sr('ar_transaction_detail_id'); ?></td>
                   <td><?php $f->text_field_wid3s('detail_number'); ?></td>
                   <td><?php echo $f->select_field_from_object('account_type', gl_journal_line::gl_journal_line_types(), 'option_line_code', 'option_line_value', $$class_third->account_type, '', 'account_type'); ?></td>
                   <td><?php $f->ac_field_d3('detail_ac_id'); ?></td>
                   <td><?php $f->text_field_wid3s('amount'); ?></td>
                   <td><?php $f->text_field_wid3s('gl_amount'); ?></td>
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
                  <th><?php echo gettext('Seq') ?></th>
                  <th><?php echo gettext('Period') ?>#</th>
                  <th><?php echo gettext('Ref Key Name') ?></th>
                  <th><?php echo gettext('Ref Key Value') ?>#</th>
                  <th><?php echo gettext('View Ref Doc') ?></th>
                  <th><?php echo gettext('Status') ?></th>
                  <th><?php echo gettext('Journal_Created?') ?></th>

                 </tr>
                </thead>
                <tbody class="form_data_detail_tbody">
                 <?php
                 $detailCount = 0;
                 foreach ($ar_transaction_detail_object as $ar_transaction_detail) {
                  $class_third = 'ar_transaction_detail';
                  $$class_third = &$ar_transaction_detail;
                  ?>
                  <tr class="ar_transaction_detail<?php echo $count . '-' . $detailCount; ?> ">
                   <td><?php $f->seq_field_detail_d($detailCount) ?></td>
                   <td><?php $f->text_field_wid3s('period_id') ?></td>
                   <td><?php $f->text_field_d3('reference_key_name'); ?></td>
                   <td><?php $f->text_field_d3('reference_key_value'); ?></td>
                   <td><?php echo!empty($ref_doc_stmt) ? $ref_doc_stmt : '' ?></td>
                   <td><?php $f->text_field_wid3sr('status'); ?></td>
                   <td><?php echo $f->checkBox_field('journal_created_cb', $$class_third->journal_created_cb, '', '', 1); ?></td>
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
        <th><?php echo gettext('Seq') ?></th>
        <th><?php echo gettext('Unit Price') ?>#</th>
        <th><?php echo gettext('Line Price') ?></th>
        <th><?php echo gettext('Tax Code') ?>#</th>
        <th><?php echo gettext('Tax Amount') ?></th>
        <th><?php echo gettext('GL Line Price') ?></th>
        <th><?php echo gettext('GL Tax Amount') ?></th>
        <th><?php echo gettext('Line Description') ?></th>
        <th><?php echo gettext('Status') ?></th>
       </tr>
      </thead>
      <tbody class="form_data_line_tbody">
       <?php
       $count = 0;
       foreach ($ar_transaction_line_object as $ar_transaction_line) {
        ?>         
        <tr class="ar_transaction_line<?php echo $count ?>">
         <td><?php $f->seq_field_d($count) ?></td>
         <td><?php form::number_field_wid2m('inv_unit_price'); ?></td>
         <td><?php form::text_field_wid2m('inv_line_price'); ?></td>
         <td><?php echo $f->select_field_from_object('tax_code_id', mdm_tax_code::find_all_outTax_by_bu_org_id($$class->bu_org_id), 'mdm_tax_code_id', 'tax_code', $$class_second->tax_code_id, '', 'output_tax medium', '', $readonly, '', '', '', 'percentage') ?></td>
         <td><?php form::number_field_wid2('tax_amount'); ?></td>
         <td><?php form::number_field_wid2sr('gl_inv_line_price'); ?></td>
         <td><?php form::number_field_wid2sr('gl_tax_amount'); ?></td>
         <td><?php $f->text_field_wid2('line_description'); ?></td>
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
        <th><?php echo gettext('Seq') ?></th>
        <th><?php echo gettext('SO Header Id') ?>#</th>
        <th><?php echo gettext('SO Line Id') ?></th>
        <th><?php echo gettext('Is Asset') ?>#</th>
        <th><?php echo gettext('Asset Category') ?></th>
        <th><?php echo gettext('Project Header Id') ?></th>
        <th><?php echo gettext('Project Line Id') ?></th>
        <th><?php echo gettext('Ref Key Name') ?></th>
        <th><?php echo gettext('Ref Key Value') ?></th>
        <th><?php echo gettext('View Ref Doc') ?></th>
       </tr>
      </thead>
      <tbody class="form_data_line_tbody">
       <?php
       $count = 0;
       foreach ($ar_transaction_line_object as $ar_transaction_line) {
        ?>         
        <tr class="ar_transaction_line<?php echo $count ?>">
         <td><?php $f->seq_field_d($count) ?></td>
         <td><?php $f->text_field_wid2sr('sd_so_header_id'); ?></td>
         <td><?php $f->text_field_wid2sr('sd_so_line_id'); ?></td>
         <td><?php form::checkBox_field('asset_cb', $$class_second->asset_cb); ?></td>
         <td><?php $f->text_field_wid2sr('fa_asset_category_id'); ?></td>
         <td><?php $f->text_field_wid2sr('prj_project_header_id'); ?></td>
         <td><?php $f->text_field_wid2sr('prj_project_line_id'); ?></td>
         <td><?php $f->text_field_d2('reference_key_name'); ?></td>
         <td><?php $f->text_field_d2('reference_key_value'); ?></td>
         <td><?php echo!empty($ref_doc_stmt) ? $ref_doc_stmt : '' ?></td>

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
  <li class="headerClassName" data-headerClassName="ar_transaction_header" ></li>
  <li class="lineClassName" data-lineClassName="ar_transaction_line" ></li>
  <li class="detailClassName" data-detailClassName="ar_transaction_detail" ></li>
  <li class="savingOnlyHeader" data-savingOnlyHeader="false" ></li>
  <li class="primary_column_id" data-primary_column_id="ar_transaction_header_id" ></li>
  <li class="form_header_id" data-form_header_id="ar_transaction_header" ></li>
  <li class="line_key_field" data-line_key_field="item_description" ></li>
  <li class="single_line" data-single_line="false" ></li>
  <li class="form_line_id" data-form_line_id="ar_transaction_line" ></li>
 </ul>
 <ul id="js_contextMenu_data">
  <li class="docHedaderId" data-docHedaderId="ar_transaction_header_id" ></li>
  <li class="docLineId" data-docLineId="ar_transaction_line_id" ></li>
  <li class="docDetailId" data-docDetailId="ar_transaction_detail_id" ></li>
  <li class="btn1DivId" data-btn1DivId="ar_transaction_header" ></li>
  <li class="btn2DivId" data-btn2DivId="form_line" ></li>
  <li class="trClass" data-docHedaderId="ar_transaction_line" ></li>
  <li class="tbodyClass" data-tbodyClass="form_data_line_tbody" ></li>
  <li class="noOfTabbs" data-noOfTabbs="4" ></li>
 </ul>
</div>
