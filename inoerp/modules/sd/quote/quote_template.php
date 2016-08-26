<!-- * 
inoERP
 *
 * @copyright   2014 Nishit R. Das
 * @license     https://www.mozilla.org/MPL/2.0/
 * @link        http://inoideas.org
 * @source code https://github.com/inoerp/inoERP
-->
<div id ="form_header">
 <span class="heading"><?php echo gettext('Sales Quote Header') ?></span>
 <form  method="post" id="sd_quote_header"  name="sd_quote_header">
  <div id="tabsHeader">
   <ul class="tabMain">
    <li><a href="#tabsHeader-1"><?php echo gettext('Basic Info') ?></a></li>
    <li><a href="#tabsHeader-2"><?php echo gettext('Finance') ?></a></li>
    <li><a href="#tabsHeader-3"><?php echo gettext('Address Details') ?></a></li>
    <li><a href="#tabsHeader-4"><?php echo gettext('Note') ?></a></li>
    <li><a href="#tabsHeader-5"><?php echo gettext('Attachments') ?></a></li>
    <li><a href="#tabsHeader-6"><?php echo gettext('Actions') ?></a></li>
   </ul>
   <div class="tabContainer">
    <div id="tabsHeader-1" class="tabContent">
     <ul class="column header_field">
      <li><?php $f->l_text_field_dr_withSearch('sd_quote_header_id') ?>
       <a name="show" href="form.php?class_name=sd_quote_header&<?php echo "mode=$mode"; ?>" class="show document_id sd_quote_header_id">
        <i class='fa fa-refresh'></i></a> 
      </li>
      <li><?php $f->l_text_field_d('quote_number', 'primary_column2'); ?></li>
      <li><?php $f->l_text_field_dr('sd_opportunity_id'); ?>						 </li>
      <li><?php
       echo $f->l_val_field_d('customer_name', 'ar_customer', 'customer_name', '', 'customer_name', 'vf_select_customer_name');
       echo $f->hidden_field_withId('ar_customer_id', $$class->ar_customer_id);
       ?><i class="generic g_select_customer_name select_popup clickable fa fa-search" data-class_name="ar_customer"></i></li>
      <li><?php
       echo $f->l_val_field_d('customer_number', 'ar_customer', 'customer_number', '', '', 'vf_select_customer_number');
       ?><i class="generic g_select_customer_number select_popup clickable fa fa-search" data-class_name="ar_customer"></i></li>
      <li><?php $f->l_select_field_from_object('ar_customer_site_id', $customer_site_obj, 'ar_customer_site_id', 'customer_site_name', $$class->ar_customer_site_id, 'ar_customer_site_id', 'ar_customer_site_id'); ?> </li>      
      <li><?php $f->l_text_field_dr('quote_status', 'always_readonly'); ?> </li> 
      <li><?php $f->l_checkBox_field_d('rev_enabled_cb'); ?></li> 
      <li><?php $f->l_text_field_d('rev_number'); ?> </li> 
      <li><?php $f->l_text_field_d('description'); ?></li> 
     </ul>
    </div>
    <div id="tabsHeader-2" class="tabContent">
     <ul class="column header_field">
      <li><?php $f->l_select_field_from_object('doc_currency', option_header::currencies(), 'option_line_code', 'option_line_code', $$class->doc_currency, 'doc_currency', 'currency', 1, $readonly); ?>						 </li>
      <li><?php $f->l_select_field_from_object('payment_term_id', payment_term::find_all(), 'payment_term_id', 'payment_term', $$class->payment_term_id, '', 'payment_term_id', 1, $readonly); ?>						 </li>
      <li><?php
       echo $f->l_val_field_d('sales_person', 'hr_employee_v', 'employee_name', '', 'vf_select_document_owner employee_name');
       echo $f->hidden_field_withId('hr_employee_id', $$class->hr_employee_id);
       ?><i class="generic g_select_document_owner select_popup clickable fa fa-search" data-class_name="hr_employee_v"></i></li>
      <li><?php $f->l_select_field_from_object('price_list_header_id', mdm_price_list_header::find_all(), 'mdm_price_list_header_id', 'price_list', $$class->price_list_header_id); ?>		 </li>
      <li><?php $f->l_text_field_d('exchange_rate_type'); ?></li>
      <li><?php $f->l_number_field_d('exchange_rate'); ?></li>
      <li><?php $f->l_number_field_d('header_amount'); ?></li>
      <li><?php $f->l_number_field_d('tax_amount'); ?></li>
      <li><?php $f->l_text_field_d('new_customer_name'); ?></li> 
      <li><label><?php echo gettext('New Customer Address') ?></label><?php echo $f->text_area('new_customer_address', $$class->new_customer_address); ?></li> 
     </ul>
    </div>
    <div id="tabsHeader-3" class="tabContent">
     <div class="shipto_address"><?php $f->address_field_d('ship_to_id'); ?></div>
     <div class="billto_address"><?php $f->address_field_d('bill_to_id'); ?></div>
    </div>
    <div id="tabsHeader-4" class="tabContent">
     <div> 
      <div id="comments">
       <div id="comment_list">
        <?php echo!(empty($comments)) ? $comments : ""; ?>
       </div>
       <div id ="display_comment_form">
        <?php
        $reference_table = 'sd_quote_header';
        $reference_id = $$class->sd_quote_header_id;
        ?>
       </div>
       <div id="new_comment">
       </div>
      </div>
     </div>
    </div>
    <div id="tabsHeader-5" class="tabContent">
     <div> <?php echo ino_attachement($file) ?> </div>
    </div>

    <div id="tabsHeader-6" class="tabContent">
     <div> 
      <ul class="column five_column">
       <li id="document_print"><label><?php echo gettext('Document Print') ?></label>
        <a class="button" target="_blank"
           href="<?php echo HOME_URL ?>modules/sd/quote/quote_print.php?sd_quote_header_id=<?php echo!(empty($$class->sd_quote_header_id)) ? $$class->sd_quote_header_id : ""; ?>" >Print Quote</a>
       </li>
       <li id="document_status"><label><?php echo gettext('Action') ?></label>
        <?php echo $f->select_field_from_array('action', sd_quote_header::$action_a, $$class->action, 'action'); ?>
       </li>
       <li><label><?php echo gettext('SO BU Name') ?></label><?php echo $f->select_field_from_object('bu_org_id', org::find_all_business(), 'org_id', 'org', $$class->bu_org_id, 'bu_org_id', '', '', 1); ?>						 </li>
      </ul>
     </div>
    </div>
   </div>

  </div>
 </form>
</div>
<div id="form_line" class="form_line"><span class="heading"><?php echo gettext('Quote Lines & Shipments') ?></span>
 <form  method="post" id="quote_site"  name="sd_quote_line">
  <div id="tabsLine">
   <ul class="tabMain">
    <li><a href="#tabsLine-1"><?php echo gettext('Basic') ?></a></li>
    <li><a href="#tabsLine-2"><?php echo gettext('Price') ?> </a></li>
    <li><a href="#tabsLine-3"><?php echo gettext('Dates') ?> </a></li>
    <li><a href="#tabsLine-4"><?php echo gettext('References') ?> </a></li>
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
        <th><?php echo gettext('Shipping Org') ?></th>
        <th><?php echo gettext('Item Number') ?></th>
        <th><?php echo gettext('Item Description') ?></th>
        <th><?php echo gettext('UOM') ?></th>
        <th><?php echo gettext('Line Status') ?></th>
        <th><?php echo gettext('Quantity') ?></th>
       </tr>
      </thead>
      <tbody class="form_data_line_tbody">
       <?php
       $count = 0;
       foreach ($sd_quote_line_object as $sd_quote_line) {
        ?>         
        <tr class="sd_quote_line<?php echo $count ?>">
         <td><?php
          echo ino_inline_action($$class_second->sd_quote_line_id, array('sd_quote_header_id' => $$class->sd_quote_header_id,
           'tax_code_value' => $$class_second->tax_code_value));
          ?>    
         </td>
         <td><?php $f->seq_field_d($count) ?></td>
         <td><?php $f->text_field_wid2sr('sd_quote_line_id', 'always_readonly'); ?></td>
         <td><?php echo form::text_field('line_number', $$class_second->line_number, '8', '20', 1, 'Auto no', '', $readonly, 'lines_number'); ?></td>
         <td><?php echo $f->select_field_from_object('shipping_org_id', org::find_all_inventory(), 'org_id', 'org', $$class_second->shipping_org_id, '', 'medium', 1, $readonly); ?></td>
         <td><?php
          $f->val_field_wid2('item_number', 'item', 'item_number', 'shipping_org_id');
          echo $f->hidden_field_withCLass('item_id_m', $$class_second->item_id_m, 'dont_copy_r');
          echo $f->hidden_field_withCLass('customer_ordered_cb', '1', 'popup_value');
          ?>
          <i class="generic g_select_item_number select_popup clickable fa fa-search" data-class_name="item"></i></td>
         <td><?php form::text_field_wid2('item_description'); ?></td>
         <td><?php echo $f->select_field_from_object('uom_id', uom::find_all(), 'uom_id', 'uom_name', $$class_second->uom_id, '', 'small'); ?></td>
         <td><?php $f->text_field_wid2r('line_status', 'always_readonly'); ?></td>
         <td><?php echo $f->number_field('line_quantity', $$class_second->line_quantity); ?></td>
        </tr>
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
        <th><?php echo gettext('Price List') ?></th>
        <th><?php echo gettext('Price Date') ?></th>
        <th><?php echo gettext('Unit Price') ?>#</th>
        <th><?php echo gettext('Line Price') ?>#</th>
        <th><?php echo gettext('Tax Code') ?></th>
        <th><?php echo gettext('Tax Amount') ?></th>
       </tr>
      </thead>
      <tbody class="form_data_line_tbody">
       <?php
       $count = 0;
       foreach ($sd_quote_line_object as $sd_quote_line) {
        if ((empty($sd_quote_line->price_list_header_id)) && !empty($document_type_i->price_list_header_id)) {
         $sd_quote_line->price_list_header_id = $document_type_i->price_list_header_id;
         $sd_quote_line->price_date = empty($sd_quote_line->price_date) ? current_time(true) : $sd_quote_line->price_date;
        }
        ?>         
        <tr class="sd_quote_line<?php echo $count ?>">
         <td><?php $f->seq_field_d($count) ?></td>
         <td><?php echo $f->select_field_from_object('price_list_header_id', mdm_price_list_header::find_all_sales_pl(), 'mdm_price_list_header_id', 'price_list', $$class_second->price_list_header_id, '', 'medium copyValue'); ?>
         </td>
         <td><?php echo $f->date_fieldAnyDay('price_date', $$class_second->price_date) ?></td>
         <td><?php form::number_field_wid2('unit_price'); ?></td>
         <td><?php form::number_field_wid2('line_price'); ?></td>
         <td><?php echo $f->select_field_from_object('tax_code_id', mdm_tax_code::find_all_outTax_by_inv_org_id($$class_second->shipping_org_id), 'mdm_tax_code_id', 'tax_code', $$class_second->tax_code_id, '', 'output_tax medium') ?></td>
         <td><?php form::number_field_wid2('tax_amount'); ?></td>
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
        <th><?php echo gettext('Requested Date') ?></th>
        <th><?php echo gettext('Promise Date') ?></th>
       </tr>
      </thead>
      <tbody class="form_data_line_tbody">
       <?php
       $count = 0;
       foreach ($sd_quote_line_object as $sd_quote_line) {
        ?>         
        <tr class="sd_quote_line<?php echo $count ?>">
         <td><?php $f->seq_field_d($count) ?></td>
         <td><?php echo $f->date_fieldFromToday_d('requested_date', $$class_second->requested_date) ?></td>
         <td><?php echo $f->date_fieldFromToday('promise_date', $$class_second->promise_date) ?></td>
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
        <th><?php echo gettext('Ref Doc Type') ?></th>
        <th><?php echo gettext('Ref Number') ?></th>
        <th><?php echo gettext('Order Header Id') ?>#</th>
        <th><?php echo gettext('Order Line Id') ?></th>

       </tr>
      </thead>
      <tbody class="form_data_line_tbody">
       <?php
       $count = 0;
       foreach ($sd_quote_line_object as $sd_quote_line) {
        ?>         
        <tr class="sd_quote_line<?php echo $count ?>">
         <td><?php $f->seq_field_d($count) ?></td>
         <td><?php $f->text_field_wid2('reference_doc_type'); ?></td>
         <td><?php $f->text_field_wid2('reference_doc_number'); ?></td>
         <td><?php $f->text_field_wid2r('sd_so_header_id'); ?></td>
         <td><?php $f->text_field_wid2r('sd_so_line_id'); ?></td>
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
  <li class="headerClassName" data-headerClassName="sd_quote_header" ></li>
  <li class="lineClassName" data-lineClassName="sd_quote_line" ></li>
  <li class="savingOnlyHeader" data-savingOnlyHeader="false" ></li>
  <li class="primary_column_id" data-primary_column_id="sd_quote_header_id" ></li>
  <li class="form_header_id" data-form_header_id="sd_quote_header" ></li>
  <li class="line_key_field" data-line_key_field="item_description" ></li>
  <li class="single_line" data-single_line="false" ></li>
  <li class="form_line_id" data-form_line_id="sd_quote_line" ></li>
 </ul>
 <ul id="js_contextMenu_data">
  <li class="docHedaderId" data-docHedaderId="sd_quote_header_id" ></li>
  <li class="docLineId" data-docLineId="sd_quote_line_id" ></li>
  <li class="btn1DivId" data-btn1DivId="sd_quote_header" ></li>
  <li class="btn2DivId" data-btn2DivId="form_line" ></li>
  <li class="tbodyClass" data-tbodyClass="form_data_line_tbody" ></li>
  <li class="noOfTabbs" data-noOfTabbs="4" ></li>
 </ul>
</div>