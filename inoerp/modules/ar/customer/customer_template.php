<div id ="form_header"><span class="heading"> Customer Information </span>
 <form action=""  method="post" id="customer_header"  name="customer_header">
  <div id="tabsHeader">
   <ul class="tabMain">
    <li><a href="#tabsHeader-1">Basic Info</a></li>
    <li><a href="#tabsHeader-2">BU Assignment</a></li>
    <li><a href="#tabsHeader-3">Profile</a></li>
    <li><a href="#tabsHeader-4">Address Details</a></li>
   </ul>
   <div class="tabContainer">
    <div id="tabsHeader-1" class="tabContent">
     <div class="large_shadow_box"> 
      <ul class="column header_field">
       <li>
        <label><img class="ar_customer_id select_popup clickable"  src="<?php echo HOME_URL; ?>themes/images/serach.png"/>
         Customer Id</label><?php $f->text_field_dr('ar_customer_id'); ?>
       <a name="show" href="form.php?class_name=ar_customer&<?php echo "mode=$mode"; ?>" class="show document_id ar_customer_id"><img src="<?php echo HOME_URL; ?>themes/images/refresh.png"/></a> 
       </li>
       <li><label>Customer Number</label><?php form::number_field_dm('customer_number'); ?>						 </li>               
       <li><label>Customer Name<img src="<?php echo HOME_URL; ?>themes/default/images/plus_10.png" class="disable_autocomplete supplier_name clickable"></label>
        <?php echo $f->text_field('customer_name', $$class->customer_name, '20', 'customer_name', 'select_customer_name', 1, $readonly1); ?>
       </li>
       <li><label>Customer Type</label><?php echo form::select_field_from_object('customer_type', ar_customer::customer_types(), 'option_line_code', 'option_line_value', $$class->customer_type, 'customer_type', $readonly, '', ''); ?>
       </li>
       <li><label>Supplier Id</label><?php form::number_field_ds('supplier_id'); ?></li>
       <li><label>Tax Country</label>
        <?php echo form::select_field_from_object('tax_country', option_header::COUNTRIES(), 'option_line_code', 'option_line_value', $$class->tax_country, 'tax_country', $readonly, '', ''); ?>
       </li>
       <li><label>Tax Reg No</label><?php echo form::text_field_d('tax_reg_no'); ?></li>
       <li><label>Tax Payer Id</label><?php echo form::text_field_d('tax_payer_id'); ?></li>
       <li><label>Contact Id</label><?php echo form::text_field_d('customer_contact_id'); ?></li>
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
<div id ="form_line" class="form_line"><span class="heading"> Customer Site Details </span>
 <form action=""  method="post" id="customer_site"  name="customer_site">
  <div class="line_before_tab"> 
   <ul class="column five_column inline_list"> 
    <li><label>Site Id : </label> 
     <?php echo $f->select_field_from_array('ar_customer_site_id', ar_customer_site::find_all_sitesOfCustomer_array($$class->ar_customer_id), $$class_second->ar_customer_site_id, 'ar_customer_site_id'); ?>
       <a name="show" href="form.php?class_name=ar_customer&<?php echo "mode=$mode"; ?>" class="show document_id ar_customer_site_id"><img src="<?php echo HOME_URL; ?>themes/images/refresh.png"/></a>      
    </li> 
    <li class="hidden"><?php echo form::hidden_field('ar_customer_id', $$class->ar_customer_id); ?></li>
    <li><label>Site Name : </label>
     <?php // echo form::select_field_from_object('customer_site_name', customer_site::find_all_sitesOfCustomer($$class->ar_customer_id), 'customer_site_name', 'customer_site_name', $$class_second->customer_site_name, 'customer_site_name', $readonly, '', 1); ?>
     <?php echo form::text_field_d2m('customer_site_name'); ?>
    </li>
    <li><label>Site Number : </label>
     <?php form::number_field_d2m('customer_site_number'); ?>
    </li>
   </ul>
  </div>
  <div id="tabsLine">
   <ul class="tabMain">
    <li><a href="#tabsLine-1">Main</a></li>
    <li><a href="#tabsLine-2">Finance</a></li>
    <li><a href="#tabsLine-3">Profile</a></li>
    <li><a href="#tabsLine-4">Sales</a></li>
    <li><a href="#tabsLine-5">Address</a></li>
    <li><a href="#tabsLine-6">Attachments</a></li>
    <li><a href="#tabsLine-7">Contact</a></li>
   </ul>
   <div class="tabContainer">
    <div id="tabsLine-1" class="tabContent">
     <div class="first_rowset"> 
      <ul class="column five_column"> 
       <li><label>Customer Site Type : </label>
        <?php echo form::select_field_from_object('customer_site_type', ar_customer_site::customer_site_types(), 'option_line_code', 'option_line_value', $$class_second->customer_site_type, 'customer_site_type', $readonly, '', ''); ?>
       </li>
       <li><label>Site Reference : </label>
        <?php echo form::text_field_d2('customer_site_ref'); ?>
       </li>
       <li><label>Tax Country : </label>
        <?php echo form::select_field_from_object('site_tax_country', option_header::COUNTRIES(), 'option_line_code', 'option_line_code', $$class_second->site_tax_country, 'tax_country', $readonly, '', ''); ?>
       </li>
       <li><label>Tax Reg No : </label>
        <?php echo form::text_field_d2('site_tax_reg_no'); ?>
       </li>
       <li><label>Tax Payer Id : </label>
        <?php echo form::text_field_d2('site_tax_payer_id'); ?>
       </li>
       <li><label>Tax code : </label>
        <?php echo form::text_field_d2('site_tax_code'); ?>
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
        <?php echo form::select_field_from_object('currency', option_header::currencies(), 'option_line_code', 'option_line_code', $$class_second->currency, 'currency', $readonly, '', ''); ?>
       </li>
       <li><label>Payment Term : </label>
        <?php echo form::select_field_from_object('payment_term_id', payment_term::find_all(), 'payment_term_id', 'payment_term', $$class_second->payment_term_id, 'payment_term_id', $readonly, '', ''); ?>
       </li>
       <li><label>Payment Method : </label> 
        <?php echo form::text_field_d2('payment_method_id'); ?>
       </li> 
       <li><label>Payment Method : </label> 
        <?php echo form::text_field_d2('payment_method_id'); ?>
       </li> 
       <li><label>Bank  : </label> 
        <?php echo form::text_field_d2('bank_id'); ?>
       </li> 
       <li><label>Bank Account : </label> 
        <?php echo form::text_field_d2('bank_account_id'); ?>
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
      <ul class="column five_column"> 
       <li><label>Order Type : </label>
        <?php
        // echo form::select_field_from_object('currency', option_header::currencies(), 'option_line_code', 'option_line_code', $$class_second->currency, 'currency', $readonly, '', ''); 
        echo form::text_field_d2('order_type_id');
        ?>
       </li>
       <li><label>Price List : </label>
        <?php
        // echo form::select_field_from_object('currency', option_header::currencies(), 'option_line_code', 'option_line_code', $$class_second->currency, 'currency', $readonly, '', ''); 
        echo form::text_field_d2('price_list_id');
        ?>
       </li>
       <li><label>Internal Organization : </label>
        <?php
        // echo form::select_field_from_object('currency', option_header::currencies(), 'option_line_code', 'option_line_code', $$class_second->currency, 'currency', $readonly, '', ''); 
        echo form::text_field_d2('internal_org_id');
        ?>
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
        <?php echo form::text_field_d2('country_of_origin'); ?>
       </li> 
      </ul>
     </div>
    </div>
    <!--end of tab2 (purchasing)!!!! start of sales tab-->
    <div id="tabsLine-5" class="tabContent">
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
       <li class='new_object1'><label><img class="extn_contact_id select_popup clickable"  src="<?php echo HOME_URL; ?>themes/images/serach.png"/>
         New Contact : </label>  
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