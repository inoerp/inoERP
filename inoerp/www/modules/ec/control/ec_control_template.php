<form action=""  method="post" id="ec_control"  name="ec_control">
 <span class="heading"><?php echo gettext('eCommerce Controls') ?></span>
 <div id ="form_header">
  <div id="tabsHeader">
   <ul class="tabMain">
    <li><a href="#tabsHeader-1"><?php echo gettext('Basic Info') ?></a></li>
   </ul>
   <div class="tabContainer"> 
    <div id="tabsHeader-1" class="tabContent">
     <ul class="column header_field"> 
      <li><?php $f->l_text_field_d('site_name'); ?> </li> 
      <li><?php $f->l_text_field_d('price_round'); ?> </li>
      <li><?php $f->l_select_field_from_object('bu_org_id', org::find_all_business(), 'org_id', 'org', $$class->bu_org_id, 'bu_org_id', $readonly1, '', ''); ?>						 </li>
      <li><?php $f->l_select_field_from_object('shipping_org_id', org::find_all_inventory(), 'org_id', 'org', $$class->shipping_org_id, '', '', 1, $readonly); ?></li>
      <li><?php $f->l_select_field_from_object('exchange_rate_type', gl_currency_conversion::currency_conversion_type(), 'option_line_code', 'option_line_code', $$class->exchange_rate_type, 'exchange_rate_type', '', 1, $readonly); ?></li>
      <li><?php $f->l_select_field_from_object('payment_term_id', payment_term::find_all(), 'payment_term_id', 'payment_term', $$class->payment_term_id, '', 'payment_term_id', '', $readonly1); ?>						 </li>
      <li><?php $f->l_select_field_from_object('sales_document_type', sd_document_type::find_all_header_levels(), 'sd_document_type_id', 'document_type_name', $$class->sales_document_type, 'sales_document_type', '', 1, $readonly1); ?>						 </li>
      <li><?php $f->l_select_field_from_array('order_source_type', sd_so_header::$order_source_type_a, $$class->order_source_type, 'order_source_type', '', 1, 1); ?> </li> 
      <li><?php $f->l_select_field_from_object('tax_code_id', mdm_tax_code::find_all_outTax_by_inv_org_id($$class->shipping_org_id), 'mdm_tax_code_id', 'tax_code', $$class->tax_code_id, '', 'output_tax medium') ?></li>
      <li><?php $f->l_select_field_from_object('line_type', sd_document_type::find_all_line_levels(), 'sd_document_type_id', 'document_type_name', $$class->line_type, '', 'medium', 1, $readonly); ?></li>
     </ul> 
     <div class="small-left-padding"><label><?php echo gettext('Home Page') ?> </label>
      <?php echo HOME_URL . $f->text_field('default_home_page', $$class->default_home_page, '20'); ?>   </div>
    </div>
   </div>

  </div>
 </div>
 <div id ="form_line" class="form_line"><span class="heading">Other Details </span>
  <div id="tabsLine">
   <ul class="tabMain">
    <li><a href="#tabsLine-1"><?php echo gettext('Conformation eMail') ?></a></li>
   </ul>
   <div class="tabContainer"> 
    <div id="tabsLine-1" class="tabContent">
     <div class="first_rowset"> 
      <ul class="column header_field"> 
       <li><label><?php echo gettext('Send Conformation eMail') ?></label> <?php $f->checkBox_field_d('send_email_cb') ?></li>
       <li><?php $f->l_text_field_d('email_cc'); ?> </li>

      </ul>
      <ul class="inRow asperWidth"> 
       <li><label><?php echo gettext('eMail Template') ?></label> 
        <textarea name="maintenance_msg" class="plaintext" rows="8" cols="100"><?php echo htmlentities($$class->email_template); ?> </textarea>
       </li> 
      </ul>
     </div>
    </div> 
   </div>
  </div>
 </div> 
</form>

<div id="js_data">
 <ul id="js_saving_data">
  <li class="headerClassName" data-headerClassName="ec_control" ></li>
  <li class="savingOnlyHeader" data-savingOnlyHeader="true" ></li>
  <li class="form_header_id" data-form_header_id="ec_control" ></li>
 </ul>
</div>