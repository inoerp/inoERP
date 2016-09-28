<!-- * 
inoERP
 *
 * @copyright   2014 Nishit R. Das
 * @license     https://www.mozilla.org/MPL/2.0/
 * @link        http://inoideas.org
 * @source code https://github.com/inoerp/inoERP
-->
<div id ="form_header"><span class="heading"><?php echo gettext('Membership Application') ?></span>
 <form  method="post" id="hd_subscription_header"  name="hd_subscription_header">
  <div id="tabsHeader">
   <ul class="tabMain">
    <li><a href="#tabsHeader-1"><?php echo gettext('Basic Info') ?></a></li>
    <li><a href="#tabsHeader-2"><?php echo gettext('Basic - 2') ?></a></li>
    <li><a href="#tabsHeader-3"><?php echo gettext('Finance') ?></a></li>
    <li><a href="#tabsHeader-4"><?php echo gettext('Address Details') ?></a></li>
    <li><a href="#tabsHeader-5"><?php echo gettext('Note') ?></a></li>
    <li><a href="#tabsHeader-6"><?php echo gettext('Attachments') ?></a></li>
    <li><a href="#tabsHeader-7"><?php echo gettext('Actions') ?></a></li>
   </ul>
   <div class="tabContainer">
    <div id="tabsHeader-1" class="tabContent">
     <ul class="column header_field">
      <li><?php $f->l_text_field_dr_withSearch('hd_subscription_header_id') ?>
       <a name="show" href="form.php?class_name=hd_subscription_header&<?php echo "mode=$mode"; ?>" class="show document_id hd_subscription_header_id"><i class="fa fa-refresh"></i></a> 
      </li>
      <li><?php $f->l_text_field_d('number', 'primary_column2'); ?></li>
      <li><?php $f->l_text_field_d('number', 'primary_column2'); ?></li>
      <li><?php $f->l_select_field_from_object('bu_org_id', org::find_all_business(), 'org_id', 'org', $hd_subscription_header->bu_org_id, 'bu_org_id', $readonly1, '', ''); ?>						 </li>
      <li><?php $f->l_select_field_from_object('document_type', sd_document_type::find_all_header_levels(), 'sd_document_type_id', 'document_type_name', $hd_subscription_header->document_type, 'document_type', 'medium', 1, $readonly1); ?>						 </li>
      <li><?php
       echo $f->l_val_field_dm('customer_name', 'ar_customer', 'customer_name', '', 'customer_name', 'vf_select_customer_name');
       echo $f->hidden_field_withId('ar_customer_id', $$class->ar_customer_id);
       ?><i class="generic g_select_customer_name select_popup clickable fa fa-search" data-class_name="ar_customer"></i></li>
      <li><?php
       echo $f->l_val_field_d('customer_number', 'ar_customer', 'customer_number', '', '', 'vf_select_customer_number');
       ?><i class="generic g_select_customer_number select_popup clickable fa fa-search" data-class_name="ar_customer"></i></li>
      <li><?php $f->l_select_field_from_object('ar_customer_site_id', $customer_site_obj, 'ar_customer_site_id', 'customer_site_name', $$class->ar_customer_site_id, 'ar_customer_site_id', 'ar_customer_site_id', '', $readonly1); ?> </li>
      <li><?php $f->l_text_field_dr('so_status') ?></li>
      <li><?php $f->l_select_field_from_array('order_source_type', hd_subscription_header::$order_source_type_a, $$class->order_source_type, 'order_source_type', '', 1, 1); ?> </li> 
     </ul>
    </div>
    <div id="tabsHeader-2" class="tabContent">
     <ul class="column header_field">
      <li><?php $f->l_checkBox_field_d('rev_enabled_cb'); ?></li> 
      <li><?php $f->l_text_field_d('rev_number'); ?> </li> 
      <li><?php
       echo $f->l_val_field_d('sales_person', 'hr_employee_v', 'employee_name', '', 'vf_select_document_owner employee_name');
       echo $f->hidden_field_withId('hr_employee_id', $$class->hr_employee_id);
       ?><i class="generic g_select_document_owner select_popup clickable fa fa-search" data-class_name="hr_employee_v"></i></li>
      <li><?php $f->l_text_field_d('description'); ?></li> 
      <li><?php $f->l_text_field_dr('order_reference_id'); ?> </li> 
      <li><?php $f->l_text_field_dr('order_reference_table'); ?></li> 
     </ul>
    </div>
    <div id="tabsHeader-3" class="tabContent">
     <ul class="column header_field">
      <li><?php $f->l_select_field_from_object('payment_term_id', payment_term::find_all(), 'payment_term_id', 'payment_term', $$class->payment_term_id, '', 'payment_term_id', 1, $readonly1); ?>						 </li>
      <li><?php $f->l_date_fieldAnyDay('payment_term_date', $$class->payment_term_date) ?></li>
      <li><?php $f->l_select_field_from_object('doc_currency', option_header::currencies(), 'option_line_code', 'option_line_code', $$class->doc_currency, 'doc_currency', '', 1, $readonly); ?></li>
      <li><?php $f->l_select_field_from_object('ledger_currency', option_header::currencies(), 'option_line_code', 'option_line_code', $$class->currency, 'currency', 'currency', 1, 1); ?></li>
      <li><?php $f->l_date_fieldFromToday('agreement_start_date', $$class->agreement_start_date) ?></li>
      <li><?php $f->l_date_fieldFromToday('agreement_end_date', $$class->agreement_start_date) ?></li>
      <li><?php $f->l_select_field_from_object('exchange_rate_type', gl_currency_conversion::currency_conversion_type(), 'option_line_code', 'option_line_code', $$class->exchange_rate_type, 'exchange_rate_type', '', 1, $readonly); ?></li>
      <li><?php $f->l_number_field('exchange_rate', $$class->exchange_rate, '', 'exchange_rate'); ?> </li>
      <li><?php $f->l_select_field_from_object('price_list_header_id', mdm_price_list_header::find_all_sales_pl(), 'mdm_price_list_header_id', 'price_list', $$class->price_list_header_id); ?></li>
      <li><?php $f->l_number_field('header_amount', $$class->header_amount, '15', 'header_amount'); ?></li>
      <li><?php $f->l_number_field('tax_amount', $$class->tax_amount, '15', 'tax_amount'); ?></li>
      <li><?php $f->l_number_field('prepaid_amount', $$class->prepaid_amount, '15', 'prepaid_amount'); ?></li>
      <li><?php $f->l_text_field_d('prepaid_status'); ?></li>
     </ul>
    </div>
    <div id="tabsHeader-4" class="tabContent">
     <div class="shipto_address"><?php $f->address_field_d('ship_to_id'); ?></div>
     <div class="billto_address"><?php $f->address_field_d('bill_to_id'); ?></div>
    </div>
    <div id="tabsHeader-5" class="tabContent">
     <div> 
      <div id="comments">
       <div id="comment_list">
        <?php echo!(empty($comments)) ? $comments : ""; ?>
       </div>
       <div id ="display_comment_form">
        <?php
        $reference_table = 'hd_subscription_header';
        $reference_id = $$class->hd_subscription_header_id;
        ?>
       </div>
       <div id="new_comment">
       </div>
      </div>
     </div>
    </div>
    <div id="tabsHeader-6" class="tabContent">
     <div> <?php echo ino_attachement($file) ?> </div>
    </div>

    <div id="tabsHeader-7" class="tabContent">
     <div> 
      <ul class="column header_field">
       <li id="document_status"><label><?php echo gettext('Action') ?></label>
        <?php echo $f->select_field_from_object('action', hd_subscription_header::so_status(), 'option_line_code', 'option_line_value', '', 'action'); ?>
       </li>
      </ul>

      <div id="comment" class="shoe_comments">
      </div>
     </div>
    </div>
   </div>

  </div>
 </form>
</div>

<div id="form_line" class="form_line"><span class="heading"><?php echo gettext('SO / RMA Lines & Shipments') ?></span>
 <form action=""  method="post" id="so_site"  name="hd_subscription_line">
  <div id="tabsLine">
   <ul class="tabMain">
    <li><a href="#tabsLine-1"><?php echo gettext('Basic') ?></a></li>
    <li><a href="#tabsLine-2"><?php echo gettext('Price') ?> </a></li>
    <li><a href="#tabsLine-3"><?php echo gettext('Dates') ?> </a></li>
    <li><a href="#tabsLine-4"><?php echo gettext('Configuration') ?> </a></li>
    <li><a href="#tabsLine-5"><?php echo gettext('References') ?> </a></li>
    <li><a href="#tabsLine-6"><?php echo gettext('References-2') ?> </a></li>
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
        <th><?php echo gettext('Org') ?></th>
        <th><?php echo gettext('Item Number') ?></th>
        <th><?php echo gettext('Description') ?></th>
        <th><?php echo gettext('UOM') ?></th>
        <th><?php echo gettext('Quantity') ?></th>
        <th><?php echo gettext('Line Status') ?></th>
       </tr>
      </thead>
      <tbody class="form_data_line_tbody">
       <?php
       $count = 0;
       foreach ($hd_subscription_line_object as $hd_subscription_line) {
        ?>         
        <tr class="hd_subscription_line<?php echo $count ?>">
         <td>
          <?php
          echo ino_inline_action($hd_subscription_line->hd_subscription_line_id, array('hd_subscription_header_id' => $hd_subscription_header->hd_subscription_header_id,
           'tax_code_value' => $$class_second->tax_code_value));
          ?>
         </td>
         <td><?php $f->seq_field_d($count) ?></td>
         <td><?php form::text_field_wid2sr('hd_subscription_line_id', 'line_id'); ?></td>
         <td><?php echo form::text_field('line_number', $$class_second->line_number, '8', '20', 1, 'Auto no', '', $readonly, 'lines_number'); ?></td>
         <td><?php echo $f->select_field_from_object('line_type', sd_document_type::find_all_line_levels(), 'sd_document_type_id', 'document_type_name', $$class_second->line_type, '', 'medium', 1, $readonly, '', '', '', 'process_flow_id'); ?></td>
         <td><?php echo $f->select_field_from_object('shipping_org_id', org::find_all_inventory(), 'org_id', 'org', $$class_second->shipping_org_id, '', '', 1, $readonly); ?></td>
         <td><?php
          $f->val_field_wid2('item_number', 'item', 'item_number', 'shipping_org_id');
          echo $f->hidden_field_withCLass('item_id_m', $$class_second->item_id_m,'dont_copy_r');
          echo $f->hidden_field_withCLass('customer_ordered_cb', '1', 'popup_value');
          ?>
          <i class="generic g_select_item_number select_popup clickable fa fa-search" data-class_name="item"></i></td>
         <td><?php form::text_field_wid2s('item_description'); ?></td>
         <td><?php echo $f->select_field_from_object('uom_id', uom::find_all(), 'uom_id', 'uom_name', $$class_second->uom_id, '', 'small'); ?></td>

         <td><?php form::number_field_wid2s('line_quantity'); ?></td>
         <td><?php $f->text_field_wid2r('line_status'); ?></td>
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
        <th><?php echo gettext('GL Line Price') ?></th>
        <th><?php echo gettext('GL Tax Amount') ?></th>
       </tr>
      </thead>
      <tbody class="form_data_line_tbody">
       <?php
       $count = 0;
       foreach ($hd_subscription_line_object as $hd_subscription_line) {
        if ((empty($hd_subscription_line->price_list_header_id)) && !empty($document_type_i->price_list_header_id)) {
         $hd_subscription_line->price_list_header_id = $document_type_i->price_list_header_id;
         $hd_subscription_line->price_date = empty($hd_subscription_line->price_date) ? current_time(true) : $hd_subscription_line->price_date;
        }
        ?>         
        <tr class="hd_subscription_line<?php echo $count ?>">
         <td><?php $f->seq_field_d($count) ?></td>
         <td><?php echo $f->select_field_from_object('price_list_header_id', mdm_price_list_header::find_all_sales_pl(), 'mdm_price_list_header_id', 'price_list', $$class_second->price_list_header_id, '', 'medium copyValue'); ?>
         </td>
         <td><?php echo $f->date_fieldAnyDay('price_date', $$class_second->price_date) ?></td>
         <td><?php form::number_field_wid2('unit_price'); ?></td>
         <td><?php form::number_field_wid2('line_price'); ?></td>
         <td><?php echo $f->select_field_from_object('tax_code_id', mdm_tax_code::find_all_outTax_by_inv_org_id($$class_second->shipping_org_id), 'mdm_tax_code_id', 'tax_code', $$class_second->tax_code_id, '', 'output_tax medium') ?></td>
         <td><?php form::number_field_wid2('tax_amount'); ?></td>
         <td><?php form::number_field_wid2sr('gl_line_price'); ?></td>
         <td><?php form::number_field_wid2sr('gl_tax_amount'); ?></td>
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
        <th><?php echo gettext('Schedule Ship / Receipt Date') ?>#</th>
        <th><?php echo gettext('Actual Ship / Receipt Date') ?>#</th>
       </tr>
      </thead>
      <tbody class="form_data_line_tbody">
       <?php 
       $count = 0;
       foreach ($hd_subscription_line_object as $hd_subscription_line) {
        ?>         
        <tr class="hd_subscription_line<?php echo $count ?>">
         <td><?php $f->seq_field_d($count) ?></td>
         <td><?php echo $f->date_field('requested_date', ($$class_second->requested_date), '', '', 'dateFromToday copyValue'); ?></td>
         <td><?php echo $f->date_fieldFromToday('promise_date', $$class_second->promise_date) ?></td>
         <td><?php echo $f->date_field('schedule_ship_date', ($$class_second->schedule_ship_date), '', '', 'dateFromToday copyValue'); ?></td>
         <td><?php echo $f->date_fieldFromToday('actual_ship_date', $$class_second->actual_ship_date, 'always_readonly') ?></td>
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
      <th><?php echo gettext('Seq') ?>#</th>
      <th><?php echo gettext('Kit Item') ?>#</th>
      <th><?php echo gettext('Configured') ?>?</th>
      <th><?php echo gettext('Config Id') ?>?</th>
      <th><?php echo gettext('WO Header Id') ?></th>
      <th><?php echo gettext('Config Details') ?></th>
      </tr>
      </thead>
      <tbody class="form_data_line_tbody">
       <?php
       $count = 0;
       foreach ($hd_subscription_line_object as $hd_subscription_line) {
        $hd_subscription_line->ar_transaction_number = null;
        ?>         
        <tr class="hd_subscription_line<?php echo $count ?>">
         <td><?php $f->seq_field_d($count) ?></td>
         <td><?php echo $f->checkBox_field('kit_cb', $$class_second->kit_cb, '', 'dontCopy'); ?></td>
         <td><?php echo $f->checkBox_field('kit_configured_cb', $$class_second->kit_configured_cb, '', 'dontCopy'); ?></td>
         <td><?php $f->text_field_wid2r('bom_config_header_id'); ?></td>
         <td><?php $f->text_field_wid2r('wip_wo_header_id'); ?></td>
         <td> <a class="popup popup-form view-item-config medium" href="form.php?class_name=bom_config_header&mode=9&window_type=popup"> <i class="fa fa-edit"></i></a></td>
        </tr>
        <?php
        $count = $count + 1;
       }
       ?>
      </tbody>
      <!--                  Showing a blank form for new entry-->
     </table>
    </div>
    <div id="tabsLine-5" class="scrollElement tabContent">
     <table class="form_line_data_table">
      <thead> 
       <tr>
        <th><?php echo gettext('Seq') ?>#</th>
        <th><?php echo gettext('Line Description') ?></th>
        <th><?php echo gettext('Supply Source') ?></th>
        <th><?php echo gettext('Destination Typet') ?>#</th>
        <th><?php echo gettext('Picked Quantity') ?>#</th>
        <th><?php echo gettext('Shipped /Received Quantity') ?>#</th>
        <th><?php echo gettext('Ref Doc Type') ?></th>
        <th><?php echo gettext('Ref Number') ?></th>

       </tr>
      </thead>
      <tbody class="form_data_line_tbody">
       <?php
       $count = 0;
       foreach ($hd_subscription_line_object as $hd_subscription_line) {
        if ((empty($hd_subscription_line->supply_source)) && !empty($document_type_i->supply_source)) {
         $hd_subscription_line->supply_source = $document_type_i->supply_source;
        }
        if ((empty($hd_subscription_line->destination_type)) && !empty($document_type_i->destination_type)) {
         $hd_subscription_line->destination_type = $document_type_i->destination_type;
        }
        ?>         
        <tr class="hd_subscription_line<?php echo $count ?>">
         <td><?php $f->seq_field_d($count) ?></td>
         <td><?php form::text_field_wid2('line_description'); ?></td>
         <td><?php echo $f->select_field_from_array('supply_source', sd_document_type::$supply_source_a, $$class_second->supply_source, '', 'copyValue'); ?>	</td>
         <td> <?php echo $f->select_field_from_array('destination_type', sd_document_type::$destination_type_a, $$class_second->destination_type, '', 'copyValue'); ?></td>
         <td><?php form::number_field_wid2sr('picked_quantity'); ?></td>
         <td><?php form::number_field_wid2sr('shipped_quantity'); ?></td>
         <td><?php form::text_field_wid2('reference_doc_type'); ?></td>
         <td><?php form::text_field_wid2('reference_doc_number'); ?></td>

        </tr>
        <?php
        $count = $count + 1;
       }
       ?>
      </tbody>
      <!--                  Showing a blank form for new entry-->
     </table>
    </div>
    <div id="tabsLine-6" class="scrollElement tabContent">
     <table class="form_line_data_table">
      <thead> 
       <tr><th>Seq#</th>
        <th>Invoiced Qty</th>
        <th>ar_transaction_header_id </th>
        <th>ar_transaction_line_id</th>
        <th>Invoice/CM # </th>
        <th>Process Id </th>
        <th>View Process</th>
        <th>Action</th>
        <th>Reservation</th>
       </tr>
      </thead>
      <tbody class="form_data_line_tbody">
       <?php
       $count = 0;
       foreach ($hd_subscription_line_object as $hd_subscription_line) {
        $hd_subscription_line->ar_transaction_number = null;
        ?>         
        <tr class="hd_subscription_line<?php echo $count ?>">
         <td><?php $f->seq_field_d($count) ?></td>
         <td><?php form::number_field_wid2sr('invoiced_quantity'); ?></td>
         <td><?php form::text_field_wid2r('ar_transaction_header_id'); ?></td>
         <td><?php form::text_field_wid2r('ar_transaction_line_id'); ?></td>
         <td><?php form::text_field_wid2r('ar_transaction_number'); ?></td>
         <td><?php $f->text_field_wid2r('sys_spd_header_id', 'dont_copy'); ?></td>
         <td><a role="button" target="_blank" class="btn btn-sm btn-default dont_copy" href="form.php?class_name=sys_spd_header&sys_spd_header_id=<?php echo $$class_second->sys_spd_header_id; ?>"><?php echo $$class_second->sys_spd_header_id; ?></a></td>
         <td><?php echo $f->select_field_from_array('line_action', hd_subscription_line::$line_action_a, ''); ?></td>
         <td><a role="button" target="_blank" class="btn btn-sm btn-default dont_copy" href="multi_select.php?search_class_name=inv_reservation&amp;class_name=inv_reservation&amp;mode=9&amp;show_block=1&amp;hd_subscription_line_id=<?php echo $$class_second->hd_subscription_line_id; ?>"><?php echo gettext('View / Update') ?></a></td>
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
  <li class="headerClassName" data-headerClassName="hd_subscription_header" ></li>
  <li class="lineClassName" data-lineClassName="hd_subscription_line" ></li>
  <li class="savingOnlyHeader" data-savingOnlyHeader="false" ></li>
  <li class="primary_column_id" data-primary_column_id="hd_subscription_header_id" ></li>
  <li class="form_header_id" data-form_header_id="hd_subscription_header" ></li>
  <li class="line_key_field" data-line_key_field="item_description" ></li>
  <li class="single_line" data-single_line="false" ></li>
  <li class="form_line_id" data-form_line_id="hd_subscription_line" ></li>
 </ul>
 <ul id="js_contextMenu_data">
  <li class="docHedaderId" data-docHedaderId="hd_subscription_header_id" ></li>
  <li class="docLineId" data-docLineId="hd_subscription_line_id" ></li>
  <li class="btn1DivId" data-btn1DivId="hd_subscription_header" ></li>
  <li class="btn2DivId" data-btn2DivId="form_line" ></li>
  <li class="tbodyClass" data-tbodyClass="form_data_line_tbody" ></li>
  <li class="noOfTabbs" data-noOfTabbs="6" ></li>
 </ul>
</div>