<div id ="form_header">
 <form  method="post" id="supplier_header"  name="supplier_header">
  <span class="heading"><?php echo gettext('Supplier Master') ?></span>
  <div id="tabsHeader">
   <ul class="tabMain">
    <li><a href="#tabsHeader-1"><?php echo gettext('Basic Info') ?></a></li>
    <li><a href="#tabsHeader-2"><?php echo gettext('BU Assignment') ?></a></li>
    <li><a href="#tabsHeader-3"><?php echo gettext('Address Details') ?></a></li>
   <li><a href="#tabsHeader-4"><?php echo gettext('Notes') ?></a></li>
   </ul>
   <div class="tabContainer">
    <div id="tabsHeader-1" class="tabContent">
     <ul class="column header_field">
      <li><?php $f->l_text_field_dr_withSearch('supplier_id'); ?>
       <a name="show" href="form.php?class_name=supplier&<?php echo "mode=$mode"; ?>" class="show document_id supplier_id">
        <i class="fa fa-refresh"></i></a> 
      </li>
      <li><?php $f->l_text_field_d('supplier_name'); ?></li>
      <li><?php $f->l_number_field_d('supplier_number'); ?></li>
      <li><?php $f->l_select_field_from_object('supplier_type', supplier::supplier_types(), 'option_line_code', 'option_line_value', $$class->supplier_type, 'supplier_type', '', '', $readonly); ?>       </li>
      <li><?php $f->l_select_field_from_object('supplier_category', supplier::supplier_category(), 'option_line_code', 'option_line_value', $$class->supplier_category, 'supplier_category', '', '', $readonly); ?>       </li>
      <li><label><?php echo gettext('Customer Name') ?></label><?php $f->text_field_d('customer_name', 'select_customer_name'); ?>
       <?php echo $f->hidden_field_withId('ar_customer_id', $$class->ar_customer_id); ?>
      </li>
      <li><?php $f->l_select_field_from_object('tax_country', option_header::COUNTRIES(), 'option_line_code', 'option_line_value', $$class->tax_country, 'tax_country', '', '', $readonly); ?>             </li>
      <li><?php $f->l_text_field_d('tax_reg_no'); ?></li>
      <li><?php $f->l_text_field_d('tax_payer_id'); ?></li>
      <li><?php $f->l_status_field_d('status'); ?></li>
      <li><?php $f->l_text_field_d('alt_name'); ?></li> 
     </ul>
    </div>
    <div id="tabsHeader-2" class="tabContent">
     <div class="column header_field"> 
      <?php echo!(empty($assigned_bu_statement)) ? $assigned_bu_statement : ""; ?>
     </div>
    </div>
    <div id="tabsHeader-3" class="tabContent">
     <div class="header_address"><?php $f->address_field_d('address_id', 1, 'suplier_header'); ?></div>
    </div>
    <div id="tabsHeader-4" class="tabContent">
     <div id="comments">
      <div id="comment_list">
       <?php echo!(empty($comments)) ? $comments : ""; ?>
      </div>
      <div id ="display_comment_form">
       <?php
       $reference_table = 'supplier_id';
       $reference_id = $$class->supplier_id;
       ?>
      </div>
      <div id="new_comment">
      </div>
     </div>
    </div>
   </div>

  </div>
 </form>
</div>

<div id ="form_line" class="form_line form_header_l"><span class="heading"><?php echo gettext('Supplier Site Details') ?></span>
 <form  method="post" id="supplier_site"  name="supplier_site">
  <div id='line_before_tab' class="ino-well"> 
   <ul class="column header_field "> 
    <li>
     <?php // echo form::text_field('supplier_site_id', $supplier_site->supplier_site_id, '15', '25', '', 'System Number', 'supplier_site_id', $readonly) ?>
     <?php echo $f->l_select_field_from_array('supplier_site_id', supplier_site::find_all_sitesOfSupplier_array($supplier->supplier_id), $supplier_site->supplier_site_id, 'supplier_site_id', 'action medium'); ?>
     <a name="show1" href="form.php?class_name=supplier&<?php echo "mode=$mode"; ?>" class="show1 document_id supplier_site_id" data-search_field='supplier_site_id'>
      <i class="fa fa-refresh"></i> </a> 
    </li> 
    <li class="hidden"><?php echo form::hidden_field('supplier_id', $$class->supplier_id); ?></li>
    <li><?php $f->l_text_field('supplier_site_name', $$class_second->supplier_site_name); ?>    </li>
    <li><?php $f->l_text_field('supplier_site_number', $$class_second->supplier_site_number); ?>    </li>
   </ul>
  </div>
  <div id="tabsLine">
   <ul class="tabMain">
    <li><a href="#tabsLine-1"><?php echo gettext('Main') ?></a></li>
    <li><a href="#tabsLine-2"><?php echo gettext('Purchasing') ?> </a></li>
    <li><a href="#tabsLine-3"><?php echo gettext('Receiving') ?> </a></li>
    <li><a href="#tabsLine-4"><?php echo gettext('Site Address') ?> </a></li>
    <li><a href="#tabsLine-5"><?php echo gettext('Attachments') ?></a></li>
    <li><a href="#tabsLine-6"><?php echo gettext('Contact') ?> </a></li>
    <li><a href="#tabsLine-7"><?php echo gettext('Notes') ?> </a></li>
    <li><a href="#tabsLine-8"><?php echo gettext('Secondary') ?></a></li>
   </ul>
   <div class="tabContainer">
    <div id="tabsLine-1" class="tabContent">
     <div class="first_rowset"> 
      <ul class="column header_field"> 
       <li><?php $f->l_select_field_from_object('supplier_site_type', supplier_site::supplier_site_types(), 'option_line_code', 'option_line_code', $supplier_site->supplier_site_type, 'supplier_site_type', '', '', $readonly); ?>       </li>
       <li><?php $f->l_select_field_from_object('site_tax_country', option_header::COUNTRIES(), 'option_line_code', 'option_line_code', $supplier_site->site_tax_country, 'tax_country', '', '', $readonly); ?>       </li>
       <li><?php $f->l_text_field('site_tax_reg_no', $$class_second->site_tax_reg_no); ?></li>
       <li><?php $f->l_text_field('site_tax_payer_id', $$class_second->site_tax_payer_id); ?></li>
       <li><?php $f->l_text_field('site_tax_reg_no', $$class_second->site_tax_reg_no); ?></li>
       <li><?php $f->l_text_field('bank_id', $$class_second->bank_id); ?></li>
       <li><?php $f->l_text_field('bank_account_id', $$class_second->bank_account_id); ?></li>
       <li><?php $f->l_checkBox_field_d_ws('primary_cb', $$class_second->primary_cb); ?></li>
      </ul>
     </div>
     <div class="second_rowset">

     </div>
     <!--end of tab1 div three_column-->
    </div> 
    <!--end of tab1-->
    <div id="tabsLine-2" class="tabContent">
     <div class="first_rowset"> 
      <ul class="column header_field"> 
       <li><?php $f->l_select_field_from_object('currency', option_header::currencies(), 'option_line_code', 'option_line_code', $supplier_site->currency, 'currency', '', '', $readonly); ?>       </li>
       <li><?php $f->l_select_field_from_object('payment_term_id', payment_term::find_all(), 'payment_term_id', 'payment_term', $supplier_site->payment_term_id, 'payment_term_id', $readonly, '', ''); ?>       </li>
       <li><?php $f->l_checkBox_field_d_ws('debit_memo_onreturn_cb', $$class_second->debit_memo_onreturn_cb); ?>       </li> 
       <li><?php $f->l_text_field('pay_on', $$class_second->pay_on); ?></li>
       <li><?php $f->l_text_field('fob', $$class_second->fob); ?></li>
       <li><?php $f->l_text_field('freight_terms', $$class_second->freight_terms); ?></li>
       <li><?php $f->l_text_field('transportation', $$class_second->transportation); ?></li>
       <li><?php $f->l_select_field_from_object('country_of_origin', option_header::COUNTRIES(), 'option_line_code', 'option_line_value', $supplier_site->country_of_origin, 'country_of_origin'); ?>       </li> 
      </ul>
     </div>
     <div class="second_rowset">

     </div>
     <!--end of tab1 div three_column-->
    </div> 
    <div id="tabsLine-3" class="tabContent">
     <div class="first_rowset"> 
      <ul class="column header_field">
       <li><?php $f->l_checkBox_field_d_ws('allow_substitute_receipts_cb', $$class_second->allow_substitute_receipts_cb); ?>       </li> 
       <li><?php $f->l_checkBox_field_d_ws('allow_unordered_receipts_cb', $$class_second->allow_unordered_receipts_cb); ?>       </li> 
       <li><?php $f->l_select_field_from_object('ap_invoice_match_level', supplier::ap_invoice_match_level(), 'option_line_code', 'option_line_code', $supplier_site->ap_invoice_match_level, 'ap_invoice_match_level', '', '', $readonly); ?>       </li>
       <li><?php $f->l_select_field_from_object('receipt_routing', supplier::po_receipt_routing(), 'option_line_code', 'option_line_code', $supplier_site->receipt_routing, 'receipt_routing', '', '', $readonly); ?>       </li>
       <li><?php $f->l_select_field_from_object('ship_to_location_variance', option_header::exception_actions(), 'option_line_code', 'option_line_code', $supplier_site->ship_to_location_variance, 'ship_to_location_variance', $readonly, '', ''); ?>       </li>
      </ul>
     </div>
     <div class="second_rowset">
      <div class="panel panel-collapse panel-ino-classy small_box">
       <div class="panel-heading"><div class="panel-title"><?php echo gettext('Quantity Tolerance') ?></div></div>
       <div class="panel-body">
        <ul class="column line_field">
         <li><?php $f->l_number_field('positive_qty_tolerance', $$class_second->positive_qty_tolerance); ?></li>
         <li><?php $f->l_number_field('negative_qty_tolerance', $$class_second->negative_qty_tolerance); ?></li> 
         <li><?php $f->l_number_field('qty_variance', $$class_second->qty_variance); ?></li> 
        </ul>
       </div>
      </div>
      <div class="panel panel-collapse panel-ino-classy small_box">
       <div class="panel-heading"><div class="panel-title"><?php echo gettext('Receipt Days Tolerance') ?></div></div>
       <div class="panel-body">
        <ul class="column line_field">
         <li><?php $f->l_number_field('positive_receipt_days_tolerance', $$class_second->positive_receipt_days_tolerance); ?></li>
         <li><?php $f->l_number_field('negative_receipt_days_tolerance', $$class_second->negative_receipt_days_tolerance); ?></li> 
         <li><?php $f->l_number_field('receipt_days_variance', $$class_second->receipt_days_variance); ?></li> 
        </ul>
       </div>
      </div>
     </div> 
    </div>
    <!--end of tab2 (purchasing)!!!! start of sales tab-->
    <div id="tabsLine-4" class="tabContent">
     <div class="site_address"><?php $f->address_field_d('address_id', 1, 'site_address'); ?></div>
    </div> 
    <!--                end of tab3 div three_column-->
    <!--end of tab3 (sales)!!!!start of purchasing tab-->
    <div id="tabsLine-5" class="tabContent">
     <div> <?php echo ino_attachement($file) ?> </div>
    </div>
    <!--end of tab4(purchasing)!!! start of MFG tab-->
    <div id="tabsLine-6" class="tabContent">
     <?php echo $f->contact_field('supplier_site', $$class_second->supplier_site_id, $all_contacts); ?>
    </div>

    <div id="tabsLine-7" class="tabContent">
     <div id="comments">
      <div id="comment_list">
       <?php echo!(empty($comments)) ? $comments : ""; ?>
      </div>
      <div id ="display_comment_form">
       <?php
       $reference_table = 'supplier_site';
       $reference_id = $$class_second->supplier_site_id;
       ?>
      </div>
      <div id="new_comment">
      </div>
     </div>
    </div>
    <div id="tabsLine-8" class="tabContent">
     <?php echo!empty($secondary_field_stmt) ? $secondary_field_stmt : null; ?>
    </div>
    <!--end of tab5 (Manufacturing)!! start of planning -->
   </div>


  </div>
 </form>
</div>
<div id="js_data">
 <ul id="js_saving_data">
  <li class="headerClassName" data-headerClassName="supplier" ></li>
  <li class="lineClassName" data-lineClassName="supplier_site" ></li>
  <li class="savingOnlyHeader" data-savingOnlyHeader="false" ></li>
  <li class="primary_column_id" data-primary_column_id="supplier_id" ></li>
  <li class="form_header_id" data-form_header_id="supplier_header" ></li>
  <li class="line_key_field" data-line_key_field="supplier_site_name" ></li>
  <li class="single_line" data-single_line="true" ></li>
  <li class="form_line_id" data-form_line_id="supplier_site" ></li>
 </ul>

 <ul id="js_contextMenu_data">
  <li class="docHedaderId" data-docHedaderId="supplier_header_id" ></li>
  <li class="docLineId" data-docLineId="supplier_site_id" ></li>
  <li class="btn1DivId" data-btn1DivId="supplier_header" ></li>
  <li class="btn2DivId" data-btn2DivId="form_line" ></li>
  <li class="trClass" data-docHedaderId="supplier_site" ></li>
  <li class="tbodyClass" data-tbodyClass="form_data_line_tbody" ></li>
 </ul>
</div>