<form  method="post" id="supplier_bu"  name="supplier_bu">
 <div id ="form_header"><span class="heading"><?php echo gettext('Supplier Business Unit Association') ?></span>
  <div class="tabContainer no_tab">
   <ul class="column header_field">
    <li><?php $f->l_text_field_dr_withSearch('supplier_bu_id') ?>
     <a name="show" href="form.php?class_name=supplier_bu&<?php echo "mode=$mode"; ?>" class="show document_id supplier_bu_id">
      <i class="fa fa-refresh"></i></a> 
    </li>
    <li><label><?php echo gettext('Supplier Id') ?></label>
     <span class="button"><a href="form.php?class_name=supplier&mode=<?php echo $mode ?>&supplier_id=<?php echo $$class->supplier_id; ?>"><?php echo $$class->supplier_id; ?></a></span>
     <?php echo form::hidden_field('supplier_id', $$class->supplier_id); ?>
    </li>
    <li><?php $f->l_number_field_dr('org_id') ?></li>
    <li><?php $f->l_text_field_d('org'); ?> </li>
    <li><?php $f->l_text_field_d('supplier_number'); ?></li>               
    <li><?php $f->l_text_field_d('supplier_name'); ?></li>
    <li><?php $f->l_status_field_d('status'); ?></li>
   </ul>
  </div>

 </div>
 <div id ="form_line" class="form_line"><span class="heading"><?php echo gettext('Supplier BU Details') ?></span>
  <div id="tabsLine">
   <ul class="tabMain">
    <li><a href="#tabsLine-1"><?php echo gettext('Main') ?></a></li>
    <li><a href="#tabsLine-2"><?php echo gettext('Local Addresses') ?> </a></li>
    <li><a href="#tabsLine-3"><?php echo gettext('Purchasing') ?> </a></li>
    <li><a href="#tabsLine-4"><?php echo gettext('Invoice & Payment') ?> </a></li>
    <li><a href="#tabsLine-5"><?php echo gettext('Attachments') ?></a></li>
   </ul>
   <div class="tabContainer">
    <div id="tabsLine-1" class="tabContent">
     <div class="first_rowset"> 
      <ul class="column header_field">
       <li><?php $f->l_checkBox_field_d('new_pos_cb'); ?></li>
       <li><?php $f->l_checkBox_field_d('all_invoices_cb'); ?></li>
       <li><?php $f->l_checkBox_field_d('unmatched_invoices_cb'); ?></li>
       <li><?php $f->l_checkBox_field_d('unaccounted_invoices_cb'); ?></li>
       <li><?php $f->l_checkBox_field_d('unpaid_invoices_cb'); ?></li>
       <li><?php $f->l_text_field_d('hold_reason'); ?> </li>
       <li><?php $f->l_number_field_dr('po_amount_limit') ?></li>
       <li><?php $f->l_number_field_dr('invoice_amount_limit') ?></li>
       <li><?php $f->l_number_field_dr('payment_amount_limit') ?></li>
      </ul>
     </div>
    </div> 
    <div id="tabsLine-2" class="tabContent">
      <div class="shipto_address"><?php $f->address_field_d('org_shipto_id'); ?></div>
      <div class="billto_address"><?php $f->address_field_d('org_billto_id'); ?></div>
    </div> 
    <div id="tabsLine-3" class="tabContent">
     <div class="first_rowset"> 
      <ul class="column header_field">
       <li><?php $f->l_checkBox_field_d('debit_memo_onreturn_cb'); ?></li>
       <li><?php $f->l_text_field_d('pay_on'); ?> </li>
       <li><?php $f->l_text_field_d('fob'); ?> </li>
       <li><?php $f->l_text_field_d('freight_terms'); ?> </li>
       <li><?php $f->l_text_field_d('transportation'); ?> </li>
       <li><?php $f->l_select_field_from_object('country_of_origin', option_header::countries(), 'option_line_code', 'option_line_value', $$class->country_of_origin, 'country_of_origin'); ?></li> 
       <li><?php $f->l_ac_field_d('liability_account_id', 'copyValue', 'L'); ?></li>
       <li><?php $f->l_ac_field_d('payable_account_id', 'copyValue', 'L'); ?></li>
       <li><?php $f->l_ac_field_d('payment_discount_account_id', 'copyValue', 'X'); ?></li>
       <li><?php $f->l_ac_field_d('pre_payment_account_id', 'copyValue', 'A'); ?></li>
      </ul>
     </div>
    </div>
    <div id="tabsLine-4" class="tabContent">
     <ul class="column header_field">
      <li><?php $f->l_text_field_d('bu_bank_id'); ?> </li>
      <li><?php $f->l_text_field_d('bu_bank_site_id'); ?> </li>
      <li><?php $f->l_text_field_d('invoice_match_document'); ?> </li>
      <li><?php $f->l_text_field_d('payment_group'); ?> </li>
      <li><?php $f->l_text_field_d('invoice_date_basis'); ?> </li>
      <li><?php $f->l_text_field_d('pay_date_basis'); ?> </li>
      <li><?php $f->l_text_field_d('default_payment_method'); ?> </li>
      <li><?php $f->l_text_field_d('remittance_advice_method'); ?> </li>
      <li><?php $f->l_text_field_d('remittance_advice_email'); ?> </li>
      <li><?php $f->l_select_field_from_object('bu_tax_code', mdm_tax_code::find_all_inTax_by_bu_org_id($$class->org_id), 'mdm_tax_code_id', 'tax_code', $$class->bu_tax_code, '', 'input_tax medium'); ?></li> 
      <li><?php $f->l_select_field_from_object('invoice_currency', option_header::currencies(), 'option_line_code', 'option_line_value', $$class->invoice_currency, 'invoice_currency'); ?></li>
      <li><?php $f->l_select_field_from_array('payment_priority', dbObject::$position_array, $$class->payment_priority); ?></li> 
      <li><?php $f->l_select_field_from_object('payment_term_id', payment_term::find_all(), 'payment_term_id', 'payment_term', $$class->payment_term_id, 'payment_term_id'); ?></li> 
     </ul>
    </div>
    <!--end of tab5 (Manufacturing)!! start of planning -->
    <div id="tabsLine-5" class="tabContent">
     <div id="show_attachment" class="show_attachment">
      <div id="file_upload_form">
       <ul class="inRow asperWidth">
        <li><input type="file" id="attachments" class="attachments" name="attachments[]" multiple/></li>
        <li> <input type="button" value="Attach" form="file_upload" name="attach_submit" id="attach_submit" class="submit button"></li>
        <li class="show_loading_small"><img alt="Loading..." src="<?php echo HOME_URL; ?>themes/images/small_loading.gif"/></li>
       </ul>
      </div>
      <div id="uploaded_file_details"></div>
      <?php echo extn_file::attachment_statement($file); ?>
     </div>
    </div>	
   </div>

  </div>
 </div>
</form>
<div id="js_data">
 <ul id="js_saving_data">
  <li class="headerClassName" data-headerClassName="supplier_bu" ></li>
  <li class="savingOnlyHeader" data-savingOnlyHeader="true" ></li>
  <li class="primary_column_id" data-primary_column_id="supplier_bu_id" ></li>
  <li class="form_header_id" data-form_header_id="supplier_bu" ></li>
  <li class="single_line" data-single_line="false" ></li>
 </ul>
 <ul id="js_contextMenu_data">
  <li class="docHedaderId" data-docHedaderId="supplier_bu_id" ></li>
  <li class="btn1DivId" data-btn1DivId="supplier_bu" ></li>
 </ul>
</div>