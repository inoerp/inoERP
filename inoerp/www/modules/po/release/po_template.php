<!-- * inoERP
 *
 * @copyright   2014 Nishit R. Das
 * @license     https://www.mozilla.org/MPL/2.0/
 * @link        http://inoideas.org
 * @source code https://github.com/inoerp/inoERP
-->
<div id ="form_header"><span class="heading"><?php echo gettext('Blanket Agreement & Releases') ?></span>
 <form  method="post" id="po_header"  name="po_header">
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
      <li><label><?php echo gettext('PO Header Id') ?></label><?php
       echo $f->text_field_dr('po_header_id');
       echo $f->hidden_field_withCLass('po_type', 'BLANKET', 'popup_value');
       ?>
       <a name="show" href="form.php?class_name=po_release&<?php echo "mode=$mode"; ?>" class="show document_id po_header_id"><i class="fa fa-refresh"></i></a> 
       <i class="select_popup select_popup_default_class clickable fa fa-search" data-default_class="po_header"></i>
      </li>
      <li><?php $f->l_select_field_from_object('bu_org_id', org::find_all_business(), 'org_id', 'org', $$class->bu_org_id, 'bu_org_id', '', 1, $readonly1); ?>        </li>
      <li><?php $f->l_select_field_from_array('po_type', po_release::$po_type_a, $$class->po_type, 'po_type', '', 1, $readonly1, $readonly1); ?>        </li>
      <li><?php $f->l_text_field_d('po_number', 'primary_column2'); ?> </li>
      <li><?php $f->l_select_field_from_array('release_number', $bpa_release_number_a, $$class->release_number, 'release_number', 'primary_column3'); ?>
<?php echo $f->hidden_field_withId('ref_po_header_id', $$class->ref_po_header_id); ?>
       <a name="show" href="form.php?class_name=po_release&<?php echo "mode=$mode"; ?>" class="show2 document_id po_release_id"><i class="fa fa-refresh"></i></a> 
      </li>
      <li><?php $f->l_select_field_from_object('status', po_header::po_status(), 'option_line_code', 'option_line_value', $$class->po_status, 'po_status', 'dont_copy', '', 1); ?></li>
      <li><?php echo $f->hidden_field_withId('ref_po_header_id', $$class->ref_po_header_id); ?>
<?php echo $f->hidden_field_withId('supplier_id', $$class->supplier_id); ?>
       <label><?php echo gettext('Supplier Name') ?></label><?php echo $f->text_field('supplier_name', $$class->supplier_name, '20', 'supplier_name', 'select_supplier_name', 1, $readonly1); ?> 
       <i class="supplier_id select_popup clickable fa fa-search"></i>
      </li>
      <li><?php $f->l_text_field_d('supplier_number'); ?></li>
      <li><label><?php echo gettext('Supplier Site') ?></label><?php
       $supplier_site_obj = !empty($$class->supplier_id) ? supplier_site::find_by_parent_id($$class->supplier_id) : array();
       echo $f->select_field_from_object('supplier_site_id', $supplier_site_obj, 'supplier_site_id', 'supplier_site_name', $$class->supplier_site_id, 'supplier_site_id', '', '', $readonly1);
       ?> </li>
      <li><?php $f->l_text_field_d('rev_number'); ?></li> 
      <li><?php $f->l_checkBox_field_d('multi_bu_cb'); ?></li> 
      <li><?php $f->l_text_field_d('buyer'); ?></li> 
      <li><?php $f->l_text_field_d('description'); ?></li> 
     </ul>
    </div>
    <div id="tabsHeader-2" class="tabContent">
     <div> 
      <ul class="column header_field">
       <li><?php $f->l_date_fieldFromToday('agreement_start_date', $$class->agreement_start_date) ?></li>
       <li><?php $f->l_date_fieldFromToday('agreement_end_date', $$class->agreement_start_date) ?></li>
       <li><?php $f->l_select_field_from_object('doc_currency', option_header::currencies(), 'option_line_code', 'option_line_code', $$class->doc_currency, 'doc_currency', '', 1, $readonly); ?></li>
       <li><?php $f->l_select_field_from_object('currency', option_header::currencies(), 'option_line_code', 'option_line_code', $$class->currency, 'currency', '', 1, 1); ?></li>
       <li><?php $f->l_select_field_from_object('exchange_rate_type', gl_currency_conversion::currency_conversion_type(), 'option_line_code', 'option_line_code', $$class->exchange_rate_type, 'exchange_rate_type', '', 1, $readonly); ?></li>
       <li><?php $f->l_number_field('exchange_rate', $$class->exchange_rate, '', 'exchange_rate'); ?> </li>
       <li><?php $f->l_select_field_from_object('price_list_header_id', mdm_price_list_header::find_all_purchasing_pl(), 'mdm_price_list_header_id', 'price_list', $$class->price_list_header_id); ?></li>
       <li><?php $f->l_number_field('header_amount', $$class->header_amount, '15', 'header_amount'); ?></li>
       <li><?php $f->l_number_field('tax_amount', $$class->tax_amount, '15', 'tax_amount'); ?></li>
       <li><?php $f->l_select_field_from_object('payment_term_id', payment_term::find_all(), 'payment_term_id', 'payment_term', $$class->payment_term_id, 'payment_term_id', '', 1, $readonly1); ?></li>
      </ul>
     </div>
    </div>
    <div id="tabsHeader-3" class="tabContent">
     <div class="left_half shipto address_details">
      <ul class="column four_column">
       <li><label><img src="<?php echo HOME_URL; ?>themes/images/serach.png" class="address_id select_popup clickable">
<?php gettext('Ship To Site Id'); ?></label><?php $f->text_field_d('ship_to_id', 'address_id site_address_id'); ?>
       </li>
       <li><?php $f->l_text_field_dr('ship_to_address_name', 'address_name'); ?></li>
       <li><?php $f->l_text_field_dr('ship_to_address', 'address'); ?></li>
       <li><?php $f->l_text_field_dr('ship_to_country', 'country'); ?></li>
       <li><?php echo $f->l_text_field_dr('ship_to_postal_code', 'postal_code'); ?></li>
      </ul>
     </div> 
     <div class="right_half billto address_details">
      <ul class="column four_column">
       <li><label><img src="<?php echo HOME_URL; ?>themes/images/serach.png" class="address_id select_popup clickable">
        <?php gettext('Bill To Site Id'); ?></label>
<?php $f->text_field_d('bill_to_id', 'address_id  site_address_id'); ?>
       </li>
       <li><?php $f->l_text_field_dr('bill_to_address_name', 'address_name'); ?></li>
       <li><?php $f->l_text_field_dr('bill_to_address', 'address'); ?></li>
       <li><?php $f->l_text_field_dr('bill_to_country', 'country'); ?></li>
       <li><?php echo $f->l_text_field_dr('bill_to_postal_code', 'postal_code'); ?></li>
      </ul>
     </div> 
    </div>
    <div id="tabsHeader-4" class="tabContent">
     <div> 
      <div id="comments">
       <div id="comment_list">
<?php echo!(empty($comments)) ? $comments : ""; ?>
       </div>
       <div id ="display_comment_form">
        <?php
        $reference_table = 'po_header';
        $reference_id = $$class->po_header_id;
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
      <ul class="column four_column">
       <li id="document_print"><label><?php echo gettext('Document Print') ?> : </label>
        <a class="button" target="_blank"
           href="<?php echo HOME_URL ?>modules/po/po_print.php?po_header_id=<?php echo!(empty($$class->po_header_id)) ? $$class->po_header_id : ""; ?>" ><?php echo gettext('Print PO') ?></a>
       </li>
       <li><label><?php echo gettext('Action') ?></label>
        <?php
        $action_readonly = ($$class->po_status == 'CLOSED') ? 1 : '';
        echo $f->select_field_from_array('action', $$class->action_a, '', 'action', '', '', $readonly, $action_readonly)
        ?>
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

<div id="form_line" class="form_line"><span class="heading"><?php echo gettext('PO Lines & Shipments') ?></span>
 <form  method="post" id="po_site"  name="po_line">
  <div id="tabsLine">
   <ul class="tabMain">
    <li><a href="#tabsLine-1"><?php echo gettext('Basic') ?></a></li>
    <li><a href="#tabsLine-2"><?php echo gettext('Finance') ?> </a></li>
    <li><a href="#tabsLine-3"><?php echo gettext('Agreement Details') ?> </a></li>
    <li><a href="#tabsLine-4"><?php echo gettext('Other Info') ?> </a></li>
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
        <th><?php echo gettext('BPA Line') ?>#</th>
        <th><?php echo gettext('Receiving Org') ?></th>
        <th><?php echo gettext('Type') ?></th>
        <th><?php echo gettext('Item Number') ?></th>
        <th><?php echo gettext('Revision') ?></th>
        <th><?php echo gettext('Item Description') ?></th>
        <th><?php echo gettext('Quantity') ?></th>
        <th><?php echo gettext('UOM') ?></th>
        <th><?php echo gettext('Shipments') ?></th>
       </tr>
      </thead>
      <tbody class="form_data_line_tbody">
       <?php
       $count = 0;
       foreach ($po_line_object as $po_line) {
        ?>         
        <tr class="po_line<?php echo $count ?>">
         <td><?php  echo ino_inline_action($$class_second->po_line_id, array('po_header_id' => $$class->po_header_id));     ?>  </td>
         <td><?php $f->seq_field_d($count) ?></td>
         <td><?php form::text_field_wid2sr('po_line_id'); ?></td>
         <td><?php echo form::text_field('line_number', $$class_second->line_number, '8', '20', 1, 'Auto no', '', $readonly, 'lines_number'); ?></td>
         <td><?php echo $f->select_field_from_array('bpa_line_id', $bpa_line_id_a, $$class_second->bpa_line_id); ?></td>
         <td><?php echo $f->select_field_from_object('receving_org_id', org::find_all_inventory(), 'org_id', 'org', $$class_second->receving_org_id, '', 'copyValue', 1, $readonly); ?></td>
         <td><?php echo $f->select_field_from_object('line_type', po_line::po_line_types(), 'option_line_code', 'option_line_value', $$class_second->line_type, '', 'copyValue', 1, $readonly); ?></td>
         <td><?php
          echo $f->hidden_field('item_id_m', $$class_second->item_id_m);
          form::text_field_wid2('item_number', 'select_item_number');
          ?>
          <img src="<?php echo HOME_URL; ?>themes/images/serach.png" class="select_item_number select_popup"></td>
         <td><?php
          if (!empty($$class_second->item_id_m) && !empty($$class_second->receving_org_id)) {
           $revision_name_a = inv_item_revision::find_by_itemIdM_orgId($$class_second->item_id_m, $$class_second->receving_org_id);
          } else {
           $revision_name_a = array();
          }
          echo $f->select_field_from_object('revision_name', $revision_name_a, 'revision_name', 'revision_name', $$class_second->revision_name, '', 'small');
          ?></td>
         <td><?php form::text_field_wid2('item_description'); ?></td>
         <td><?php echo $f->number_field('line_quantity', $$class_second->line_quantity, '', '', 'allow_change small'); ?></td>
         <td><?php
          echo form::select_field_from_object('uom_id', uom::find_all(), 'uom_id', 'uom_name', $$class_second->uom_id, '', '', 'uom_id');
          ?></td>
         <td class="add_detail_values"><i class="fa fa-arrow-circle-down add_detail_values_img"></i>
          <!--</td></tr>-->	
          <?php
          $po_line_id = $po_line->po_line_id;
          if (!empty($po_line_id)) {
           $po_detail_object = po_detail::find_by_po_lineId($po_line_id);
          } else {
           $po_detail_object = array();
          }
          if (count($po_detail_object) == 0) {
           $po_detail = new po_detail();
           $po_detail_object = array();
           array_push($po_detail_object, $po_detail);
          }
          ?>
    <!--						 <tr><td>-->
          <div class="class_detail_form">
           <fieldset class="form_detail_data_fs">
            <div class="tabsDetail">
             <ul class="tabMain">
              <li class="tabLink"><a href="#tabsDetail-1-<?php echo $count ?>"><?php echo gettext('Basic') ?></a></li>
              <li class="tabLink"><a href="#tabsDetail-2-<?php echo $count ?>"><?php echo gettext('Delivery') ?></a></li>
              <li class="tabLink"><a href="#tabsDetail-3-<?php echo $count ?>"><?php echo gettext('Finance') ?></a></li>
              <li class="tabLink"><a href="#tabsDetail-4-<?php echo $count ?>"><?php echo gettext('Status') ?></a></li>
             </ul>
             <div class="tabContainer">
              <div id="tabsDetail-1-<?php echo $count ?>" class="tabContent">
               <table class="form form_detail_data_table detail">
                <thead>
                 <tr>
                  <th><?php echo gettext('Action') ?></th>
                  <th><?php echo gettext('Seq') ?></th>
                  <th><?php echo gettext('Shipment Id') ?></th>
                  <th><?php echo gettext('Shipment Number') ?></th>
                  <th><?php echo gettext('Ship To Location') ?></th>
                  <th><?php echo gettext('Quantity') ?></th>
                  <th><?php echo gettext('Need By Date') ?></th>
                  <th><?php echo gettext('Promise Date') ?></th>
                 </tr>
                </thead>
                <tbody class="form_data_detail_tbody">
                 <?php
                 $detailCount = 0;
                 foreach ($po_detail_object as $po_detail) {
                  $class_third = 'po_detail';
                  $$class_third = &$po_detail;
                  ?>
                  <tr class="po_detail<?php echo $count . '-' . $detailCount; ?>">
                   <td>   
                    <?php
                    echo ino_inline_action($$class_second->po_line_id, array('po_header_id' => $$class->po_header_id,
                     'po_line_id' => $$class_second->po_line_id), 'add_row_detail_img', 'detail_id_cb');
                    ?>
                   </td>
                   <td><?php $f->seq_field_detail_d($detailCount) ?></td>
                   <td><?php form::text_field_wid3sr('po_detail_id'); ?></td>
                   <td><?php echo $f->number_field('shipment_number', $$class_third->shipment_number, '', '', 'detail_number', 1); ?></td>
                   <td><?php $f->text_field_wid3('ship_to_location_id'); ?></td>
                   <td><?php form::number_field_wid3s('quantity'); ?></td>
                   <td><?php echo $f->date_fieldFromToday_m('need_by_date', ($$class_third->need_by_date), false); ?></td>
                   <td><?php echo $f->date_fieldFromToday('promise_date', ($$class_third->promise_date)); ?></td>

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
                  <th><?php echo gettext('Seq') ?>#</th>
                  <th><?php echo gettext('Subinventory') ?></th>
                  <th><?php echo gettext('Locator') ?></th>
                  <th><?php echo gettext('Requestor') ?></th>
                  <th><?php echo gettext('Invoice Match Type') ?></th>
                 </tr>
                </thead>
                <tbody class="form_data_detail_tbody">
                 <?php
                 $detailCount = 0;
                 foreach ($po_detail_object as $po_detail) {
                  $class_third = 'po_detail';
                  $$class_third = &$po_detail;
                  ?>
                  <tr class="po_detail<?php echo $count . '-' . $detailCount; ?> ">
									 <td><?php $f->seq_field_detail_d($detailCount) ?></td>
                   <td><?php echo $f->select_field_from_object('subinventory_id', subinventory::find_all_of_org_id($$class_second->receving_org_id), 'subinventory_id', 'subinventory', $$class_third->subinventory_id, '', 'subinventory_id copyValue', ''); ?>                   </td>
                   <td><?php echo $f->select_field_from_object('locator_id', locator::find_all_of_subinventory($$class_third->subinventory_id), 'locator_id', 'locator', $$class_third->locator_id, '', 'locator_id copyValue', ''); ?>                   </td>
                   <td><?php $f->text_field_wid3('requestor'); ?></td>
                   <td><?php echo $f->select_field_from_array('invoice_match_type', po_detail::$invoice_match_type_a, $$class_third->invoice_match_type); ?></td>
                  </tr>
                  <?php
                  $detailCount++;
                 }
                 ?>
                </tbody>
               </table>
              </div>
              <div id="tabsDetail-3-<?php echo $count ?>" class="tabContent">
               <table class="form form_detail_data_table detail">
                <thead>
                 <tr>
                  <th><?php echo gettext('Seq') ?>#</th>
                  <th><?php echo gettext('Charge Ac') ?></th>
                  <th><?php echo gettext('Accrual Ac') ?></th>
                  <th><?php echo gettext('Budget Ac') ?></th>
                  <th><?php echo gettext('PPV Ac') ?></th>
                 </tr>
                </thead>
                <tbody class="form_data_detail_tbody">
                 <?php
                 $detailCount = 0;
                 foreach ($po_detail_object as $po_detail) {
                  $class_third = 'po_detail';
                  $$class_third = &$po_detail;
                  ?>
                  <tr class="po_detail<?php echo $count . '-' . $detailCount; ?>">
                   <td><?php $f->seq_field_detail_d($detailCount) ?></td>
                   <td><?php $f->ac_field_wid3m('charge_ac_id', 'copyValue', 'X,A'); ?></td>
                   <td><?php $f->ac_field_wid3m('accrual_ac_id', 'copyValue', 'L'); ?></td>
                   <td><?php $f->ac_field_wid3('budget_ac_id', 'copyValue'); ?></td>
                   <td><?php $f->ac_field_wid3m('ppv_ac_id', 'copyValue', 'X'); ?></td>
                  </tr>
                  <?php
                  $detailCount++;
                 }
                 ?>
                </tbody>
               </table>
              </div>
              <div id="tabsDetail-4-<?php echo $count ?>" class="tabContent">
               <table class="form form_detail_data_table detail"><label><?php echo gettext('Quantities') ?></label>
                <thead>
                 <tr>
                  <th><?php echo gettext('Seq') ?>#</th>
                  <th><?php echo gettext('Received') ?></th>
                  <th><?php echo gettext('Accepted') ?></th>
                  <th><?php echo gettext('Delivered') ?></th>
                  <th><?php echo gettext('Invoiced') ?></th>
                  <th><?php echo gettext('Paid') ?></th>
                 </tr>
                </thead>
                <tbody class="form_data_detail_tbody">
                 <?php
                 $detailCount = 0;
                 foreach ($po_detail_object as $po_detail) {
                  $class_third = 'po_detail';
                  $$class_third = &$po_detail;
                  ?>
                  <tr class="po_detail<?php echo $count . '-' . $detailCount; ?> ">
                   <td><?php $f->seq_field_detail_d($detailCount) ?></td>
                   <td><?php form::number_field_wid3sr('received_quantity'); ?></td>
                   <td><?php form::number_field_wid3sr('accepted_quantity'); ?></td>
                   <td><?php form::number_field_wid3sr('delivered_quantity'); ?></td>
                   <td><?php form::number_field_wid3sr('invoiced_quantity'); ?></td>
                   <td><?php form::number_field_wid3sr('paid_quantity'); ?></td>
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
        <th><?php echo gettext('Seq') ?>#</th>
        <th><?php echo gettext('Price List') ?></th>
        <th><?php echo gettext('Price Date') ?></th>
        <th><?php echo gettext('Unit Price') ?>#</th>
        <th><?php echo gettext('Line Price') ?>#</th>
        <th><?php echo gettext('Tax Code') ?></th>
        <th><?php echo gettext('Tax Amount') ?></th>
        <th><?php echo gettext('GL Line Price') ?></th>
        <th><?php echo gettext('GL Tax Amount') ?></th>
        <th><?php echo gettext('Line Description') ?></th>
       </tr>
      </thead>
      <tbody class="form_data_line_tbody">
       <?php
       $count = 0;
       foreach ($po_line_object as $po_line) {
        ?>         
        <tr class="po_line<?php echo $count ?>">
         <td><?php $f->seq_field_d($count) ?></td>
         <td><?php echo $f->select_field_from_object('price_list_header_id', mdm_price_list_header::find_all_purchasing_pl(), 'mdm_price_list_header_id', 'price_list', $$class_second->price_list_header_id, '', 'medium copyValue'); ?>
         </td>
         <td><?php echo $f->date_fieldAnyDay('price_date', $$class_second->price_date, 'copyValue') ?></td>
         <td><?php echo $f->number_field('unit_price', $$class_second->unit_price); ?></td>
         <td><?php echo $f->number_field('line_price', $$class_second->line_price); ?></td>
         <td><?php echo $f->select_field_from_object('tax_code_id', mdm_tax_code::find_all_inTax_by_bu_org_id($$class->bu_org_id), 'mdm_tax_code_id', 'tax_code', $$class_second->tax_code_id, '', 'input_tax medium', '', $readonly, '', '', '', 'percentage') ?></td>
         <td><?php form::number_field_wid2('tax_amount'); ?></td>
         <td><?php form::number_field_wid2('gl_line_price'); ?></td>
         <td><?php form::number_field_wid2('gl_tax_amount'); ?></td>
         <td><?php form::text_field_wid2('line_description'); ?></td>
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
        <th><?php echo gettext('Agreed Quantity') ?></th>
        <th><?php echo gettext('Released Quantity') ?></th>
        <th><?php echo gettext('Agreed Amount') ?>#</th>
        <th><?php echo gettext('Released Amount') ?>#</th>
       </tr>
      </thead>
      <tbody class="form_data_line_tbody">
       <?php
       $count = 0;
       foreach ($po_line_object as $po_line) {

        if (!empty($$class_second->bpa_line_id)) {
         $agrrement_details = po_line::find_agreement_details_by_lineId($$class_second->bpa_line_id);
//                pa($agrrement_details);
         $$class_second->agreed_quantity = $agrrement_details->agreed_quantity;
         $$class_second->agreed_amount = $agrrement_details->agreed_amount;
         $$class_second->released_quantity = $agrrement_details->released_quantity;
         $$class_second->released_amount = $agrrement_details->released_amount;
        } else {
         $$class_second->agreed_quantity = $$class_second->agreed_amount = $$class_second->released_quantity = $$class_second->released_amount = null;
        }
        ?>         
        <tr class="po_line<?php echo $count ?>">
         <td><?php $f->seq_field_d($count) ?></td>
         <td><?php $f->text_field_wid2r('agreed_quantity'); ?></td>
         <td><?php $f->text_field_wid2r('agreed_amount'); ?></td>
         <td><?php $f->text_field_wid2r('released_quantity'); ?></td>
         <td><?php $f->text_field_wid2r('released_amount'); ?></td>
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
        <th><?php echo gettext('On Hold') ?></th>
        <th><?php echo gettext('Hold Details') ?></th>
        <th><?php echo gettext('Kit Item') ?>#</th>
        <th><?php echo gettext('Configured') ?>?</th>
        <th><?php echo gettext('Item Configuration') ?></th>
        <th><?php echo gettext('Ref Doc Type') ?></th>
        <th><?php echo gettext('Ref Number') ?></th>
       </tr>
      </thead>
      <tbody class="form_data_line_tbody">
       <?php
       $count = 0;
       foreach ($po_line_object as $po_line) {
        ?>         
        <tr class="po_line<?php echo $count ?>">
         <td><?php $f->seq_field_d($count) ?></td>
         <td><?php $f->checkBox_field_wid2('hold_cb'); ?></td>
         <td><?php $f->text_field_wid2r('po_line_id'); ?></td>
         <td><?php echo $f->checkBox_field('kit_cb', $$class_second->kit_cb, '', 'dontCopy'); ?></td>
         <td><?php echo $f->checkBox_field('kit_configured_cb', $$class_second->kit_configured_cb, '', 'dontCopy'); ?></td>
         <td> <a class="popup popup-form view-item-config medium" href="form.php?class_name=bom_config_header&mode=9&window_type=popup"> <i class="fa fa-edit"></i></a></td>
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
   </div>
  </div>
 </form>

</div>

<div id="js_data">
 <ul id="js_saving_data">
  <li class="headerClassName" data-headerClassName="po_header" ></li>
  <li class="lineClassName" data-lineClassName="po_line" ></li>
  <li class="detailClassName" data-detailClassName="po_detail" ></li>
  <li class="savingOnlyHeader" data-savingOnlyHeader="false" ></li>
  <li class="primary_column_id" data-primary_column_id="po_header_id" ></li>
  <li class="form_header_id" data-form_header_id="po_header" ></li>
  <li class="line_key_field" data-line_key_field="item_description" ></li>
  <li class="single_line" data-single_line="false" ></li>
  <!--  <li class="single_line" data-enable_select="true" ></li>-->
  <li class="form_line_id" data-form_line_id="po_line" ></li>
 </ul>
 <ul id="js_contextMenu_data">
  <li class="docHedaderId" data-docHedaderId="po_header_id" ></li>
  <li class="docLineId" data-docLineId="po_line_id" ></li>
  <li class="docDetailId" data-docDetailId="po_detail_id" ></li>
  <li class="btn1DivId" data-btn1DivId="po_header" ></li>
  <li class="btn2DivId" data-btn2DivId="form_line" ></li>
  <li class="trClass" data-docHedaderId="po_line" ></li>
  <li class="tbodyClass" data-tbodyClass="form_data_line_tbody" ></li>
  <li class="noOfTabbs" data-noOfTabbs="3" ></li>
 </ul>
</div>
