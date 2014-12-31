<form action=""  method="post" id="supplier_bu"  name="supplier_bu">
 <div id ="form_header"><span class="heading"> Supplier Business Unit Association </span>
  <div class="tabContainer no_tab"> 
   <ul class="column header_field">
    <li><label><img src="<?php echo HOME_URL; ?>themes/images/serach.png" class="supplier_bu_id select_popup">
      Supplier BU Id</label><?php $f->text_field_dsr('supplier_bu_id') ?>
     <a name="show" href="form.php?class_name=supplier_bu&<?php echo "mode=$mode"; ?>" class="show document_id supplier_bu_id">
      <img src="<?php echo HOME_URL; ?>themes/images/refresh.png"/></a> 
    </li>
    <li>
     <label>Supplier Id</label>
     <span class="button"><a href="form.php?class_name=supplier&mode=<?php echo $mode ?>&supplier_id=<?php echo $$class->supplier_id; ?>"><?php echo $$class->supplier_id; ?></a></span>
      <?php echo form::hidden_field('supplier_id', $$class->supplier_id); ?>
    </li>
    <li>
     <label>Org Id</label><?php form::number_field_drsm('org_id') ?></li>
    <li><label>Org</label><?php echo form::text_field_dr('org'); ?> </li>
    <li><label>Supplier Number</label><?php form::number_field_drs('supplier_number'); ?></li>               
    <li><label>Supplier Name</label><?php echo form::text_field_dr('supplier_name'); ?></li>
    <li><label>Status</label><?php echo form::status_field($$class->status, $readonly); ?></li>
    <li><label>Revision</label><?php echo form::checkBox_field('rev_enabled_cb', $supplier_bu->rev_enabled_cb, 'rev_enabled_cb', $readonly); ?></li> 
    <li><label>Rev Number</label><?php form::text_field_wid('rev_number'); ?></li> 
   </ul>
  </div>

 </div>
 <div id ="form_line" class="form_line"><span class="heading"> Supplier BU Details </span>
  <div id="tabsLine">
   <ul class="tabMain">
    <li><a href="#tabsLine-1">Main</a></li>
    <li><a href="#tabsLine-2">Local Addresses</a></li>
    <li><a href="#tabsLine-3">Purchasing</a></li>
    <li><a href="#tabsLine-4">Invoice & Payment</a></li>
    <li><a href="#tabsLine-5">Attachments</a></li>
   </ul>
   <div class="tabContainer">
    <div id="tabsLine-1" class="tabContent">
     <div class="first_rowset"> 
      <ul class="column five_column"> 
       <li><label>Hold New POs : </label> 
        <?php echo form::checkBox_field('new_pos_cb', $$class->new_pos_cb, 'new_pos_cb', $readonly); ?>
       </li> 
       <li><label>Hold All Invoices : </label> 
        <?php echo form::checkBox_field('all_invoices_cb', $$class->all_invoices_cb, 'all_invoices_cb', $readonly); ?>
       </li> 
       <li><label>Unmatched Invoices : </label> 
        <?php echo form::checkBox_field('unmatched_invoices_cb', $$class->unmatched_invoices_cb, 'unmatched_invoices_cb', $readonly); ?>
       </li> 
       <li><label>Unaccounted Invoices : </label> 
        <?php echo form::checkBox_field('unaccounted_invoices_cb', $$class->unaccounted_invoices_cb, 'unaccounted_invoices_cb', $readonly); ?>
       </li> 
       <li><label>Unpaid Invoices : </label> 
        <?php echo form::checkBox_field('unpaid_invoices_cb', $$class->unpaid_invoices_cb, 'unpaid_invoices_cb', $readonly); ?>
       </li> 
       <li><label>Hold Reason : </label> 
        <?php echo form::text_field_d('hold_reason'); ?>
       </li> 
       <li><label>PO Amount Limit : </label> 
        <?php echo form::number_field_d('po_amount_limit'); ?>
       </li> 
       <li><label>Invoice Amount Limit : </label> 
        <?php echo form::number_field_d('invoice_amount_limit'); ?>
       </li> 
       <li><label>Payment Amount : </label> 
        <?php echo form::number_field_d('payment_amount_limit'); ?>
       </li> 
      </ul>
     </div>
     <div class="second_rowset">

     </div>
     <!--end of tab1 div three_column-->
    </div> 
    <div id="tabsLine-2" class="tabContent">
     <div class="left_half shipto address_details">
      <ul class="column four_column">
       <li><label><img src="<?php echo HOME_URL; ?>themes/images/serach.png" class="address_popup select_popup clickable">
         Ship To Site Id : </label><?php $f->text_field_d('org_shipto_id', 'address_id site_address_id'); ?>
       </li>
       <li><label>Address Name : </label><?php $f->text_field_dr('ship_to_address_name', 'address_name'); ?></li>
       <li><label>Address :</label> <?php $f->text_field_dr('ship_to_address', 'address'); ?></li>
       <li><label>Country  : </label> <?php $f->text_field_dr('ship_to_country', 'country'); ?></li>
       <li><label>Postal Code  : </label><?php echo $f->text_field_dr('ship_to_postal_code', 'postal_code'); ?></li>
      </ul>
     </div> 
     <div class="right_half billto address_details">
      <ul class="column four_column">
       <li><label><img src="<?php echo HOME_URL; ?>themes/images/serach.png" class="address_popup select_popup clickable">
         Bill To Site Id :</label>
        <?php $f->text_field_d('org_billto_id', 'address_id site_address_id'); ?>
       </li>
       <li><label>Address Name :</label><?php $f->text_field_dr('bill_to_address_name', 'address_name'); ?> </li>
       <li><label>Address :</label> <?php $f->text_field_dr('bill_to_address', 'address'); ?></li>
       <li><label>Country  : </label> <?php $f->text_field_dr('bill_to_country', 'country'); ?></li>
       <li><label>Postal Code  : </label><?php echo $f->text_field_dr('bill_to_postal_code', 'postal_code'); ?></li>
      </ul>
     </div> 
    </div> 
    <!--end of tab1-->
    <div id="tabsLine-3" class="tabContent">
     <div class="first_rowset"> 
      <ul class="column header_field">
       <li><label>DM onReturn</label><?php echo form::checkBox_field('debit_memo_onreturn_cb', $$class->debit_memo_onreturn_cb, 'debit_memo_onreturn_cb', $readonly); ?>   </li> 
       <li><label>Pay On</label><?php echo form::text_field_d('pay_on'); ?></li> 
       <li><label>FOB</label><?php echo form::text_field_d('fob'); ?></li> 
       <li><label>Freight Terms</label><?php echo form::text_field_d('freight_terms'); ?></li> 
       <li><label>Transportation</label><?php echo form::text_field_d('transportation'); ?></li> 
       <li><label>Country Of Origin</label><?php echo $f->select_field_from_object('country_of_origin',  option_header::countries(),'option_line_code','option_line_value',$$class->country_of_origin,'country_of_origin'); ?></li> 
       <li><label>Liability</label><?php $f->ac_field_d('liability_account_id', 'copyValue'); ?></li>
       <li><label>Payable</label><?php $f->ac_field_d('payable_account_id', 'copyValue'); ?></li>
       <li><label>Payment Discount</label> <?php $f->ac_field_d('payment_discount_account_id', 'copyValue'); ?></li>
       <li><label>Pre Payment</label> <?php $f->ac_field_d('pre_payment_account_id', 'copyValue'); ?></li>
      </ul>
     </div>
    </div>
    <!--end of tab3 (purchasing)!!!! start of sales tab-->

    <div id="tabsLine-4" class="tabContent">
     <ul class="column header_field">
      <li><label>BU Bank AC</label><?php  $f->text_field_d('bu_bank_id'); ?></li> 
      <li><label>BU Bank Site</label><?php  $f->text_field_d('bu_bank_site_id'); ?></li> 
      <li><label>Tax Code</label><?php echo $f->select_field_from_object('bu_tax_code', mdm_tax_code::find_all_inTax_by_bu_org_id($$class->org_id), 'mdm_tax_code_id', 'tax_code', $$class->bu_tax_code, '', 'input_tax medium'); ?></li> 
      <li><label>Invoice Match Doc</label><?php $f->text_field_d('invoice_match_document'); ?></li> 
      <li><label>Invoice Currency</label><?php echo $f->select_field_from_object('invoice_currency', option_header::currencies(), 'option_line_code', 'option_line_value', $$class->invoice_currency, 'invoice_currency');?></li>
      <li><label>Payment Priority</label><?php echo $f->select_field_from_array('payment_priority', dbObject::$position_array, $$class->payment_priority); ?></li> 
      <li><label>Payment Group</label><?php echo $f->text_field_d('payment_group'); ?></li> 
      <li><label>Payment Terms</label><?php echo $f->select_field_from_object('payment_term_id', payment_term::find_all(), 'payment_term_id', 'payment_term', $$class->payment_term_id, 'payment_term_id');?></li> 
      <li><label>Invoice Date Basis</label><?php $f->text_field_d('invoice_date_basis'); ?></li> 
      <li><label>Payment Date Basis</label><?php $f->text_field_d('pay_date_basis'); ?></li> 
      <li><label>Payment Method</label><?php $f->text_field_d('default_payment_method'); ?></li> 
      <li><label>Remittance Method</label><?php $f->text_field_d('remittance_advice_method'); ?></li> 
      <li><label>Remittance Email</label><?php $f->text_field_d('remittance_advice_email'); ?></li> 
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
      <?php echo file::attachment_statement($file); ?>
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