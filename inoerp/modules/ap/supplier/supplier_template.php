<div id ="form_header"> <?php $f = new inoform(); ?>
 <form action=""  method="post" id="supplier_header"  name="supplier_header"><span class="heading"> Supplier </span>
  <div id="tabsHeader">
   <ul class="tabMain">
    <li><a href="#tabsHeader-1">Basic Info</a></li>
    <li><a href="#tabsHeader-2">BU Assignment</a></li>
    <li><a href="#tabsHeader-3">Address Details</a></li>
   </ul>
   <div class="tabContainer">
    <div id="tabsHeader-1" class="tabContent">
     <div class="large_shadow_box"> 
      <ul class="column header_field">
       <li>
        <label><img class="supplier_id_popup select_popup clickable"  src="<?php echo HOME_URL; ?>themes/images/serach.png"/>
         Supplier Id</label><?php $f->text_field_dsr('supplier_id');
?><a name="show" href="form.php?class_name=supplier&<?php echo "mode=$mode"; ?>" class="show document_id supplier_id">
         <img src="<?php echo HOME_URL; ?>themes/images/refresh.png"/></a> 
       </li>
       <li><label>Supplier Number</label><?php form::number_field_d('supplier_number'); ?></li>               
       <li><label>Supplier Name</label><?php echo $f->text_field('supplier_name', $$class->supplier_name, '20', 'supplier_name', 'select_supplier_name', 1, $readonly); ?>
        <img src="<?php echo HOME_URL; ?>themes/default/images/plus_10.png" class="disable_autocomplete supplier_name clickable">
       </li>
       <li><label>Supplier Type</label><?php echo form::select_field_from_object('supplier_type', supplier::supplier_types(), 'option_line_code', 'option_line_code', $$class->supplier_type, 'supplier_type', $readonly, '', ''); ?>
       </li>
       <li><label>Customer</label><?php form::number_field_ds('customer_id'); ?></li>
       <li><label>Tax Country</label><?php echo form::select_field_from_object('tax_country', option_header::COUNTRIES(), 'option_line_code', 'option_line_code', $$class->tax_country, 'tax_country', $readonly, '', ''); ?>             </li>
       <li><label>Tax Reg No</label><?php echo form::text_field_d('tax_reg_no'); ?></li>
       <li><label>Tax Payer Id</label><?php echo form::text_field_d('tax_payer_id'); ?></li>
       <li><label>Contact Id</label><?php echo form::text_field_d('supplier_contact_id'); ?></li>
       <li><label>Status</label><?php echo form::status_field($$class->status, $readonly); ?></li>
       <li><label>Revision</label><?php echo form::checkBox_field('rev_enabled_cb', $$class->rev_enabled_cb, 'rev_enabled_cb', $readonly); ?>             </li> 
       <li><label>Rev Number</label><?php form::text_field_wid('rev_number'); ?></li> 
      </ul>
     </div>
    </div>
    <div id="tabsHeader-2" class="tabContent">
     <div class="three_column right_border"> 
      <?php echo!(empty($assigned_bu_statement)) ? $assigned_bu_statement : ""; ?>
     </div>
    </div>
    <div id="tabsHeader-3" class="tabContent">
     <div class="header_address"> 
      <ul class="column two_column">
       <li><label><img src="<?php echo HOME_URL; ?>themes/images/serach.png" class="address_popup select_popup clickable">
         Corporate Address Id : </label>
        <?php $f->text_field_d('address_id'); ?>
       </li>
       <li><label>Address Name : </label><?php $f->text_field_dr('header_address_name', 'address_name'); ?></li>
       <li><label>Address :</label> <?php $f->text_field_dr('header_address', 'address'); ?></li>
       <li><label>Country  : </label> <?php $f->text_field_dr('header_country', 'country'); ?></li>
       <li><label>Postal Code  : </label><?php echo $f->text_field_dr('header_postal_code', 'postal_code'); ?></li>
      </ul>
     </div>
    </div>

   </div>

  </div>
 </form>
</div>
<span class="heading"> Supplier Site Details </span>
<div id ="form_line" class="form_line">
 <form action=""  method="post" id="supplier_site"  name="supplier_site">
  <div id='line_before_tab' class="line_before_tab"> 
   <ul class="column five_column inline_list"> 
    <li><label>Site Id : </label> 
     <?php // echo form::text_field('supplier_site_id', $supplier_site->supplier_site_id, '15', '25', '', 'System Number', 'supplier_site_id', $readonly) ?>
     <?php echo $f->select_field_from_array('supplier_site_id', supplier_site::find_all_sitesOfSupplier_array($supplier->supplier_id), $supplier_site->supplier_site_id, 'supplier_site_id'); ?>
     <a name="show" href="form.php?class_name=supplier&<?php echo "mode=$mode"; ?>" class="show document_id supplier_site_id">
      <img src="<?php echo HOME_URL; ?>themes/images/refresh.png"/></a> 
    </li> 
    <li class="hidden"><?php echo form::hidden_field('supplier_id', $$class->supplier_id); ?></li>
    <li><label>Site Name : </label>
     <?php // echo form::select_field_from_object('supplier_site_name', supplier_site::find_all_sitesOfSupplier($supplier->supplier_id), 'supplier_site_name', 'supplier_site_name', $supplier_site->supplier_site_name, 'supplier_site_name', $readonly, '', 1); ?>
     <?php echo form::text_field_d2m('supplier_site_name'); ?>
    </li>
    <li><label>Site Number : </label>
     <?php form::number_field_d2m('supplier_site_number'); ?>
    </li>
   </ul>
  </div>
  <div id="tabsLine">
   <ul class="tabMain">
    <li><a href="#tabsLine-1">Main</a></li>
    <li><a href="#tabsLine-2">Purchasing</a></li>
    <li><a href="#tabsLine-3">Receiving</a></li>
    <li><a href="#tabsLine-4">Site Address</a></li>
    <li><a href="#tabsLine-5">Attachments</a></li>
    <li><a href="#tabsLine-6">Contact</a></li>
    <li><a href="#tabsLine-7">Notes</a></li>
   </ul>
   <div class="tabContainer">
    <div id="tabsLine-1" class="tabContent">
     <div class="first_rowset"> 
      <ul class="column five_column"> 
       <li><label>Supplier Site Type : </label>
        <?php echo form::select_field_from_object('supplier_site_type', supplier_site::supplier_site_types(), 'option_line_code', 'option_line_code', $supplier_site->supplier_site_type, 'supplier_site_type', $readonly, '', ''); ?>
       </li>
       <li><label>Tax Country : </label>
        <?php echo form::select_field_from_object('site_tax_country', option_header::COUNTRIES(), 'option_line_code', 'option_line_code', $supplier_site->site_tax_country, 'tax_country', $readonly, '', ''); ?>
       </li>
       <li><label>Tax Reg No : </label>
        <?php echo form::text_field_d2('site_tax_reg_no'); ?>
       </li>
       <li><label>Tax Payer Id : </label>
        <?php echo form::text_field_d2('site_tax_payer_id'); ?>
       </li>
       <li><label>Supplier Site Bank : </label>
        <?php echo form::text_field_d2('bank_id'); ?>
       </li>
       <li><label>Bank Site : </label>
        <?php echo form::text_field_d2('bank_account_id'); ?>
       </li>

      </ul>
     </div>
     <div class="second_rowset">

     </div>
     <!--end of tab1 div three_column-->
    </div> 
    <!--end of tab1-->
    <div id="tabsLine-2" class="tabContent">
     <div class="first_rowset"> 
      <ul class="column five_column"> 
       <li><label>Currency : </label>
        <?php echo form::select_field_from_object('currency', option_header::currencies(), 'option_line_code', 'option_line_code', $supplier_site->currency, 'currency', $readonly, '', ''); ?>
       </li>
       <li><label>Payment Term : </label>
        <?php echo form::select_field_from_object('payment_term_id', payment_term::find_all(), 'payment_term_id', 'payment_term', $supplier_site->payment_term_id, 'payment_term_id', $readonly, '', ''); ?>
       </li>
       <li><label>Debit Memo onReturn : </label> 
        <?php echo form::checkBox_field('debit_memo_onreturn_cb', $$class_second->debit_memo_onreturn_cb, 'debit_memo_onreturn_cb', $readonly); ?>
       </li> 
       <li><label>Pay On : </label> 
        <?php echo form::text_field_d2('pay_on'); ?>
       </li> 
       <li><label>FOB : </label> 
        <?php echo form::text_field_d2('fob'); ?>
       </li> 
       <li><label>Freight Terms : </label> 
        <?php echo form::text_field_d2('freight_terms'); ?>
       </li> 
       <li><label>Transportation : </label> 
        <?php echo form::text_field_d2('transportation'); ?>
       </li> 
       <li><label>Country Of Origin : </label>
        <?php echo$f->select_field_from_object('country_of_origin', option_header::COUNTRIES(), 'option_line_code', 'option_line_value', $supplier_site->country_of_origin, 'country_of_origin'); ?>
       </li> 
      </ul>
     </div>
     <div class="second_rowset">

     </div>
     <!--end of tab1 div three_column-->
    </div> 
    <div id="tabsLine-3" class="tabContent">
     <div class="first_rowset"> 
      <ul class="column five_column">
       <li><label>Allow substitute receipts: </label>
        <?php echo form::checkBox_field('allow_substitute_receipts_cb', $supplier_site->allow_substitute_receipts_cb, '', $readonly); ?>
       </li> 
       <li><label>Allow unordered receipts: </label>
        <?php echo form::checkBox_field('allow_unordered_receipts_cb', $supplier_site->allow_unordered_receipts_cb, '', $readonly); ?>
       </li>
       <li><label>Invoice Match level: </label>
        <?php echo form::select_field_from_object('ap_invoice_match_level', supplier::ap_invoice_match_level(), 'option_line_code', 'option_line_code', $supplier_site->ap_invoice_match_level, 'ap_invoice_match_level', $readonly, '', ''); ?>
       </li>
       <li><label>Receipt Routing: </label>
        <?php echo form::select_field_from_object('receipt_routing', supplier::po_receipt_routing(), 'option_line_code', 'option_line_code', $supplier_site->receipt_routing, 'receipt_routing', $readonly, '', ''); ?>
       </li>
       <li><label>Ship_To Location Variance: </label>
        <?php echo form::select_field_from_object('ship_to_location_variance', option_header::exception_actions(), 'option_line_code', 'option_line_code', $supplier_site->ship_to_location_variance, 'ship_to_location_variance', $readonly, '', ''); ?>
       </li>
      </ul>
     </div>
     <div class="second_rowset">
      <ul class="small_box quantity_tolerance"><box_heading>Quantity Tolerance </box_heading> 
       <li><label>Positive Quantity Tolerance %: </label>
        <?php echo form::number_field('positive_qty_tolerance', $supplier_site->positive_qty_tolerance, 1, 99999, '', 'only +ve', 'positive_qty_tolerance', $readonly); ?>
       </li>
       <li><label>Negative Quantity Tolerance %: </label>
        <?php echo form::number_field('negative_qty_tolerance', $supplier_site->negative_qty_tolerance, -99999, -1, '', 'only -ve', 'negative_qty_tolerance', $readonly); ?>
       </li>
       <li><label>Quantity Variance Action: </label>
        <?php echo form::select_field_from_object('qty_variance', option_header::exception_actions(), 'option_line_code', 'option_line_code', $supplier_site->qty_variance, 'qty_variance', $readonly, '', ''); ?>
       </li>
      </ul> 

      <ul class="small_box days_tolerance"><box_heading>Receipt Days Tolerance </box_heading> 
       <li><label>Positive Receipt Days Tolerance: </label>
        <?php echo form::number_field('positive_receipt_days_tolerance', $supplier_site->positive_receipt_days_tolerance, 1, 99999, '', 'only +ve', 'positive_receipt_days_tolerance', $readonly); ?>
       </li>
       <li><label>Negative Receipt Days Tolerance : </label>
        <?php echo form::number_field('negative_receipt_days_tolerance', $supplier_site->negative_receipt_days_tolerance, -99999, -1, '', 'only -ve', 'negative_receipt_days_tolerance', $readonly); ?>
       </li>
       <li><label>Quantity Variance Action: </label>
        <?php echo form::select_field_from_object('receipt_days_variance', option_header::exception_actions(), 'option_line_code', 'option_line_code', $supplier_site->receipt_days_variance, 'receipt_days_variance', $readonly, '', ''); ?>
       </li>
      </ul> 
     </div> 

     <!--                end of tab2 div three_column-->
    </div>
    <!--end of tab2 (purchasing)!!!! start of sales tab-->
    <div id="tabsLine-4" class="tabContent">
     <div class="site_address"> 
      <ul class="column two_column">
       <li><label><img src="<?php echo HOME_URL; ?>themes/images/serach.png" class="address_popup select_popup clickable">
         Site Address Id : </label>
        <?php $f->text_field_d2('site_address_id', 'address_id'); ?>
       </li>
       <li><label>Address Name : </label><?php $f->text_field_d2r('site_address_name', 'address_name'); ?></li>
       <li><label>Address :</label> <?php $f->text_field_d2r('site_address', 'address'); ?></li>
       <li><label>Country  : </label> <?php $f->text_field_d2r('site_country', 'country'); ?></li>
       <li><label>Postal Code  : </label><?php echo $f->text_field_d2r('site_postal_code', 'postal_code'); ?></li>
      </ul>
     </div>
    </div> 
    <!--                end of tab3 div three_column-->
    <!--end of tab3 (sales)!!!!start of purchasing tab-->
    <div id="tabsLine-5" class="tabContent">
     <div> <?php echo ino_attachement($file) ?> </div>
    </div>
    <!--end of tab4(purchasing)!!! start of MFG tab-->
    <div id="tabsLine-6" class="tabContent">
     <?php
     if (!empty($all_contacts)) {
      include_once HOME_DIR . '/extensions/contact/view/contact_view_template.php';
     }
     ?>
     <div>
      <ul id="new_contact_reference">
       <li class='new_object1'><label><img class="extn_contact_id select_popup clickable"  src="<?php echo HOME_URL; ?>themes/images/serach.png"/>
         Associate Contact : </label>  
        <?php
        echo $f->hidden_field('extn_contact_id_new', '');
        echo $f->text_field('contact_name_new', '', '20', '', 'select_contact');
        ?>  </li>
       <li class='clickable' id='add_new_contact' title='New contact reference field'><i class="fa fa-plus-circle"></i></li>
      </ul>
     </div>
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