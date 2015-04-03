<div id ="form_header"><span class="heading"><?php
  $f = new inoform();
  echo gettext('Customer Information')
  ?></span>
 <form action=""  method="post" id="customer_header"  name="customer_header">
  <div id="tabsHeader">
   <ul class="tabMain">
    <li><a href="#tabsHeader-1"><?php echo gettext('Basic Info') ?></a></li>
    <li><a href="#tabsHeader-2"><?php echo gettext('BU Assignment') ?></a></li>
    <li><a href="#tabsHeader-3"><?php echo gettext('Profile') ?></a></li>
    <li><a href="#tabsHeader-4"><?php echo gettext('Address Details') ?></a></li>
   </ul>
   <div class="tabContainer">
    <div id="tabsHeader-1" class="tabContent">
     <ul class="column header_field">
      <li><?php $f->l_text_field_dr_withSearch('ar_customer_id'); ?>
       <a name="show" href="form.php?class_name=ar_customer&<?php echo "mode=$mode"; ?>" class="show document_id ar_customer_id">
        <i class="fa fa-refresh"></i></a> 
      </li>
      <li><?php $f->l_number_field_d('customer_number'); ?>						 </li>               
      <li><label><?php echo gettext('Customer Name') ?><img src="<?php echo HOME_URL; ?>themes/default/images/plus_10.png" class="disable_autocomplete supplier_name clickable"></label>
       <?php echo $f->text_field('customer_name', $$class->customer_name, '20', 'customer_name', 'select_customer_name', 1, $readonly1); ?>
      </li>
      <li><label><?php echo gettext('Customer Type ') ?></label><?php echo form::select_field_from_object('customer_type', ar_customer::customer_types(), 'option_line_code', 'option_line_value', $$class->customer_type, 'customer_type', $readonly, '', ''); ?>       </li>
      <li><?php $f->l_text_field_ds('supplier_id'); ?></li>
      <li><?php $f->l_select_field_from_object('tax_country', option_header::COUNTRIES(), 'option_line_code', 'option_line_value', $$class->tax_country, 'tax_country', '', '', $readonly); ?>       </li>
      <li><?php $f->l_text_field_ds('tax_reg_no'); ?></li>
      <li><?php $f->l_text_field_ds('tax_payer_id'); ?></li>
      <li><?php $f->l_status_field_d('status'); ?></li>
     </ul>
    </div>
    <div id="tabsHeader-2" class="tabContent">
     <div> 
      <?php echo!(empty($assigned_bu_statement)) ? $assigned_bu_statement : ""; ?>
     </div>
    </div>
    <div id="tabsHeader-3" class="tabContent">
     <div> 
      <ul class="column five_column">
       <li><label>Customer Profile : </label>
        <?php echo form::text_field_d('profile_name'); ?>
       </li>
       <li><label>Credit Class : </label>
        <?php echo form::select_field_from_object('customer_credit_class', ar_customer::customer_credit_class(), 'option_line_code', 'option_line_value', $$class->customer_credit_class, 'customer_credit_class', $readonly, '', ''); ?>
       </li>
      </ul>
     </div>
    </div>
    <div id="tabsHeader-4" class="tabContent">
     <div class="header_address"><?php $f->address_field_d('bill_to_id'); ?></div>
     <div class="shipto_address"><?php $f->address_field_d('ship_to_id'); ?></div>
    </div>
   </div>

  </div>
 </form>
</div>
<div id ="form_line" class="form_line"><span class="heading"><?php echo gettext('Customer Site Details') ?></span>
 <form action=""  method="post" id="customer_site"  name="customer_site">
  <div class="line_before_tab"> 
   <ul class="column five_column inline_list"> 
    <li><?php $f->l_select_field_from_array('ar_customer_site_id', ar_customer_site::find_all_sitesOfCustomer_array($$class->ar_customer_id), $$class_second->ar_customer_site_id, 'ar_customer_site_id'); ?>
     <a name="show" href="form.php?class_name=ar_customer&<?php echo "mode=$mode"; ?>" class="show document_id ar_customer_site_id" data-search_field='ar_customer_site_id'>
      <i class="fa fa-refresh"></i></a>      
    </li> 
    <li class="hidden"><?php echo form::hidden_field('ar_customer_id', $$class->ar_customer_id); ?></li>
    <li><?php $f->l_text_field('customer_site_name', $$class_second->customer_site_name); ?></li>
    <li><?php $f->l_text_field('customer_site_number', $$class_second->customer_site_number); ?></li>
   </ul>
  </div>
  <div id="tabsLine">
   <ul class="tabMain">
    <li><a href="#tabsLine-1"><?php echo gettext('Main') ?></a></li>
    <li><a href="#tabsLine-2"><?php echo gettext('Finance') ?> </a></li>
    <li><a href="#tabsLine-3"><?php echo gettext('Profile') ?> </a></li>
    <li><a href="#tabsLine-4"><?php echo gettext('Sales') ?> </a></li>
    <li><a href="#tabsLine-5"><?php echo gettext('Address') ?> </a></li>
    <li><a href="#tabsLine-6"><?php echo gettext('Attachments') ?></a></li>
    <li><a href="#tabsLine-7"><?php echo gettext('Contact') ?> </a></li>
   </ul>
   <div class="tabContainer">
    <div id="tabsLine-1" class="tabContent">
     <div class="first_rowset"> 
      <ul class="column header_field"> 
       <li><?php $f->l_select_field_from_object('customer_site_type', ar_customer_site::customer_site_types(), 'option_line_code', 'option_line_value', $$class_second->customer_site_type, 'customer_site_type', '', '', $readonly); ?>       </li>
       <li><?php $f->l_text_field('customer_site_ref', $$class_second->customer_site_ref); ?>  </li>
       <li><?php $f->l_select_field_from_object('site_tax_country', option_header::COUNTRIES(), 'option_line_code', 'option_line_code', $$class_second->site_tax_country, '', '', '', $readonly); ?>       </li>
       <li><?php $f->l_select_field_from_object('ar_sales_region_id', ar_sales_region::find_all(), 'ar_sales_region_id', 'sales_region_name', $$class_second->ar_sales_region_id, '', 'medium', '', $readonly); ?>       </li>
       <li><?php $f->l_text_field('site_tax_reg_no', $$class_second->site_tax_reg_no); ?></li>
       <li><?php $f->l_text_field('site_tax_payer_id', $$class_second->site_tax_payer_id); ?></li>
       <li><?php $f->l_text_field('site_tax_code', $$class_second->site_tax_code); ?></li>
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
       <li><?php $f->l_select_field_from_object('currency', option_header::currencies(), 'option_line_code', 'option_line_code', $$class_second->currency, 'currency', '', '', $readonly); ?>       </li>
       <li><?php $f->l_select_field_from_object('payment_term_id', payment_term::find_all(), 'payment_term_id', 'payment_term', $$class_second->payment_term_id, 'payment_term_id', '', '', $readonly); ?>       </li>
       <li><?php $f->l_text_field('payment_method_id', $$class_second->payment_method_id); ?></li> 
       <li><?php $f->l_text_field('bank_id', $$class_second->bank_id); ?></li> 
       <li><?php $f->l_text_field('bank_account_id', $$class_second->bank_account_id); ?></li> 
      </ul>
     </div>
     <div class="second_rowset">

     </div>
     <!--end of tab1 div three_column-->
    </div> 
    <div id="tabsLine-3" class="tabContent">
     <div class="first_rowset"> 
      <ul class="column five_column"> 
       <li><label>Status : </label>                      
        <?php echo form::status_field($$class_second->status); ?>
       </li>
       <li><label>Profile : </label> 
        <?php echo form::text_field_d2('profile_id'); ?>
       </li> 
      </ul>
     </div>
    </div>
    <div id="tabsLine-4" class="tabContent">
     <div class="first_rowset"> 
      <ul class="column header_field">
       <li><?php $f->l_text_field('order_type_id', $$class_second->order_type_id); ?></li> 
       <li><?php $f->l_text_field('price_list_id', $$class_second->price_list_id); ?></li> 
       <li><?php $f->l_text_field('internal_org_id', $$class_second->internal_org_id); ?></li> 
       <li><?php $f->l_text_field('fob', $$class_second->fob); ?></li> 
       <li><?php $f->l_text_field('freight_terms', $$class_second->freight_terms); ?></li> 
       <li><?php $f->l_text_field('transportation', $$class_second->transportation); ?></li> 
       <li><?php $f->l_text_field('country_of_origin', $$class_second->country_of_origin); ?></li> 
      </ul>
     </div>
    </div>
    <!--end of tab2 (purchasing)!!!! start of sales tab-->
    <div id="tabsLine-5" class="tabContent">
     <div class="site_address"><?php $f->address_field_d2('ship_to_id'); ?></div>
     <div class="site_address"><?php $f->address_field_d2('bill_to_id'); ?></div>
    </div> 
    <!--                end of tab3 div three_column-->
    <!--end of tab3 (sales)!!!!start of purchasing tab-->
    <div id="tabsLine-6" class="tabContent">
     <div> <?php echo ino_attachement($file) ?> </div>
    </div>
    <!--end of tab4(purchasing)!!! start of MFG tab-->
    <div id="tabsLine-7" class="tabContent">
     <?php
     if (!empty($all_contacts)) {
      include_once HOME_DIR . '/extensions/contact/view/contact_view_template.php';
     }
     ?>
     <div>
      <ul id="new_contact_reference">
       <li class='new_object1'><label><i class="fa fa-search extn_contact_id select_popup clickable" ></i>
         <?php echo gettext('New Contact') ?></label>  
        <?php
        echo $f->hidden_field('extn_contact_id_new', '');
        echo $f->text_field('contact_name_new', '', '20', '', 'select_contact');
        ?>  </li>
       <li class='clickable' id='add_new_contact' title='New contact reference field'><i class="fa fa-plus-circle"></i></li>
      </ul>
     </div>
    </div>
    <!--end of tab5 (Manufacturing)!! start of planning -->
   </div>


  </div>
 </form>
</div>

<div id="js_data">
 <ul id="js_saving_data">
  <li class="headerClassName" data-headerClassName="ar_customer" ></li>
  <li class="lineClassName" data-lineClassName="ar_customer_site" ></li>
  <li class="savingOnlyHeader" data-savingOnlyHeader="false" ></li>
  <li class="primary_column_id" data-primary_column_id="ar_customer_id" ></li>
  <li class="form_header_id" data-form_header_id="customer_header" ></li>
  <li class="line_key_field" data-line_key_field="customer_site_name" ></li>
  <li class="single_line" data-single_line="true" ></li>
  <li class="form_line_id" data-form_line_id="customer_site" ></li>
 </ul>

 <ul id="js_contextMenu_data">
  <li class="docHedaderId" data-docHedaderId="ar_customer_id" ></li>
  <li class="docLineId" data-docLineId="ar_customer_site_id" ></li>
  <li class="btn1DivId" data-btn1DivId="ar_customer" ></li>
  <li class="btn2DivId" data-btn2DivId="form_line" ></li>
  <li class="trClass" data-docHedaderId="ar_customer_site" ></li>
  <li class="tbodyClass" data-tbodyClass="form_data_line_tbody" ></li>
 </ul>
</div>