<div id="po_requisition_divId"><span class="heading"><?php echo gettext('Requisition Header') ?></span>
 <div id ="form_header">
  <form method="post" id="po_requisition_header"  name="po_requisition_header">
   <div id="tabsHeader">
    <ul class="tabMain">
     <li><a href="#tabsHeader-1"><?php echo gettext('Basic Info') ?></a></li>
     <li><a href="#tabsHeader-2"><?php echo gettext('Finance') ?></a></li>
     <li><a href="#tabsHeader-3"><?php echo gettext('Address Details') ?></a></li>
     <li><a href="#tabsHeader-4"><?php echo gettext('Attachments') ?></a></li>
     <li><a href="#tabsHeader-5"><?php echo gettext('Notes') ?></a></li>
     <li><a href="#tabsHeader-6"><?php echo gettext('Actions') ?></a></li>
    </ul>
    <div class="tabContainer">
     <div id="tabsHeader-1" class="tabContent">
      <ul class="column header_field">
       <li><?php $f->l_text_field_dr_withSearch('po_requisition_header_id') ?>
        <a name="show" href="form.php?class_name=po_requisition_header&<?php echo "mode=$mode"; ?>" class="show document_id po_requisition_header_id"><i class="fa fa-refresh"></i></a> 
       </li>
       <li><?php $f->l_text_field_d('po_requisition_number', 'primary_column2'); ?>             </li>
       <li><?php $f->l_select_field_from_object('bu_org_id', org::find_all_business(), 'org_id', 'org', $$class->bu_org_id, 'bu_org_id', '', 1, $readonly1); ?>        </li>
       <li><?php $f->l_select_field_from_array('po_requisition_type', po_requisition_header::$po_requisition_type_a, $$class->po_requisition_type, 'po_requisition_type', '', 1, $readonly1); ?>        </li>
       <li><?php echo $f->hidden_field_withId('supplier_id', $$class->supplier_id); ?>
        <label class="auto_complete"><?php echo gettext('Supplier Name') ?></label> 
        <?php echo $f->text_field_D('supplier_name', 'select_supplier_name'); ?> <i class="supplier_id select_popup clickable fa fa-search"></i></li>
       <li><label class="auto_complete"><?php echo gettext('Supplier Number') ?></label><?php $f->text_field_d('supplier_number'); ?></li>
       <li><label><?php echo gettext('Supplier Site') ?></label><?php
        $supplier_site_obj = !empty($$class->supplier_id) ? supplier_site::find_by_parent_id($$class->supplier_id) : array();
        echo $f->select_field_from_object('supplier_site_id', $supplier_site_obj, 'supplier_site_id', 'supplier_site_name', $$class->supplier_site_id, 'supplier_site_id', '', '', $readonly1);
        ?> </li>
       <li><?php $f->l_select_field_from_object('supply_org_id', org::find_all_inventory(), 'org_id', 'org', $$class->supply_org_id, 'supply_org_id', '', '', $readonly1); ?>        </li>
       <li><label><?php echo gettext('Status') ?></label>                      
        <?php echo $f->select_field_from_object('requisition_status', po_header::po_status(), 'option_line_code', 'option_line_value', $$class->requisition_status, 'requisition_status', 'always_readonly' , ' ',1); ?>
       </li>
      </ul>
     </div>
     <div id="tabsHeader-2" class="tabContent">
      <div> 
       <ul class="column header_field">
               <li><?php $f->l_checkBox_field_d('rev_enabled_cb'); ?></li>
       <li><?php $f->l_text_field_d('buyer'); ?></li>
       <li><?php $f->l_text_field_d('description'); ?></li>
        <li><?php $f->l_text_field_d('rev_number'); ?></li>
        <li><?php $f->l_select_field_from_object('currency', option_header::currencies(), 'option_line_code', 'option_line_code', $$class->currency, 'currency', '', 1, $readonly); ?>        </li>
        <li><?php $f->l_text_field_d('exchange_rate_type'); ?></li>
        <li><?php $f->l_text_field_d('exchange_rate'); ?></li>
        <li><?php $f->l_text_field_d('header_amount'); ?></li>
        <li><?php $f->l_select_field_from_object('payment_term_id', payment_term::find_all(), 'payment_term_id', 'payment_term', $$class->payment_term_id, 'payment_term_id', '', 1, $readonly); ?>        </li>
       </ul>
      </div>
     </div>
     <div id="tabsHeader-3" class="tabContent">
      <div class="shipto_address"><?php $f->address_field_d('ship_to_id'); ?></div>
      <div class="billto_address"><?php $f->address_field_d('bill_to_id'); ?></div>
     </div>
     <div id="tabsHeader-4" class="tabContent">
      <div> 
       <div> <?php echo ino_attachement($file) ?> </div>
      </div>
     </div>
     <div id="tabsHeader-5" class="tabContent">
      <div> 
       <div id="comments">
        <div id="comment_list">
         <?php echo!(empty($comments)) ? $comments : ""; ?>
        </div>
        <div id ="display_comment_form">
         <?php
         $reference_table = 'po_requisition_header';
         $reference_id = $$class->po_requisition_header_id;
         ?>
        </div>
        <div id="new_comment">
        </div>
       </div>
      </div>
     </div>
     <div id="tabsHeader-6" class="tabContent">
      <div> 
       <ul class="column four_column">
        <li><label></label><a  role="button" class="quick_select button btn btn-info" target="_blank" 
                                href="<?php echo HOME_URL ?>form.php?class_name=po_requisition_all_v&amp;router=pdf_print&amp;po_requisition_header_id=<?php echo!(empty($$class->po_requisition_header_id)) ? $$class->po_requisition_header_id : ""; ?>" >
          <?php echo gettext('Print Requisition') ?></a></li>
        <li><label><?php echo gettext('Action') ?></label>
         <?php
         echo $f->select_field_from_array('action', $$class->action_a, '', 'action', '', '', $readonly, $action_readonly)
         ?>
        </li>
       </ul>
      </div>
     </div>
    </div>
   </div>

  </form>
 </div>
 <div id="form_line" class="form_line"><span class="heading"><?php echo gettext('Requisition Lines & Shipments') ?></span>
  <form method="post" id="po_requisition_site"  name="po_requisition_line">
   <div id="tabsLine">
    <ul class="tabMain">
     <li><a href="#tabsLine-1"><?php echo gettext('Basic') ?></a></li>
     <li><a href="#tabsLine-2"><?php echo gettext('Other Info') ?> </a></li>
    </ul>
    <div class="tabContainer">
     <div id="tabsLine-1" class="tabContent">
      <table class="form_line_data_table">
       <thead> 
        <tr>
         <th><?php echo gettext('Action') ?></th>
         <th><?php echo gettext('Line Id') ?></th>
         <th><?php echo gettext('Line') ?>#</th>
         <th><?php echo gettext('Receiving Org') ?></th>
         <th><?php echo gettext('Type') ?></th>
         <th><?php echo gettext('Item Number') ?></th>
         <th><?php echo gettext('Item Description') ?></th>
         <th><?php echo gettext('UOM') ?></th>
         <th><?php echo gettext('Quantity') ?></th>
         <th><?php echo gettext('Shipments') ?></th>
        </tr>
       </thead>
       <tbody class="form_data_line_tbody">
        <?php $f = new inoform();
        $count = 0;
        foreach ($po_requisition_line_object as $po_requisition_line) {
         ?>         
         <tr class="po_requisition_line<?php echo $count ?>">
          <td>
           <?php
           echo ino_inline_action($$class_second->po_requisition_line_id, array('po_requisition_header_id' => $$class->po_requisition_header_id));
           ?>
          </td>
          <td><?php $f->text_field_wid2sr('po_requisition_line_id','always_readonly line_id'); ?></td>
          <td><?php $f->text_field_wid2s('line_number' , 'lines_number'); ?></td>
          <td><?php echo $f->select_field_from_object('receving_org_id', org::find_all_inventory(), 'org_id', 'org', $$class_second->receving_org_id, '', ' ', 1, $readonly); ?></td>
          <td><?php echo $f->select_field_from_object('line_type', po_requisition_line::po_requisition_line_types(), 'option_line_code', 'option_line_value', $$class_second->line_type, ' ' , ' line_type medium ', $readonly); ?></td>
          <td><?php
           $f->val_field_wid2('item_number', 'item', 'item_number', 'receving_org_id' , ' large ');
           echo $f->hidden_field_withCLass('item_id_m', $$class_second->item_id_m, 'dont_copy_r');
           echo $f->hidden_field_withCLass('purchased_cb', '1', 'popup_value');
           echo $f->hidden_field('processing_lt', '');
           ?>
           <i class="generic g_select_item_number select_popup clickable fa fa-search" data-class_name="item"></i></td>
          <td><?php $f->text_field_wid2('item_description' , 'large'); ?></td>
          <td><?php echo $f->select_field_from_object('uom_id', uom::find_all(), 'uom_id', 'uom_name', $$class_second->uom_id, '', ' small uom_id'); ?></td>
          <td><?php echo $f->number_field('line_quantity', $$class_second->line_quantity ); ?></td>

          <td class="add_detail_values"><i class="fa fa-arrow-circle-down add_detail_values_img"></i>
           <!--</td></tr>-->	
           <?php
           $po_requisition_line_id = $po_requisition_line->po_requisition_line_id;
           if (!empty($po_requisition_line_id)) {
            $po_requisition_detail_object = po_requisition_detail::find_by_po_requisition_lineId($po_requisition_line_id);
           } else {
            $po_requisition_detail_object = array();
           }
           if (count($po_requisition_detail_object) == 0) {
            $po_requisition_detail = new po_requisition_detail();
            $po_requisition_detail_object = array();
            array_push($po_requisition_detail_object, $po_requisition_detail);
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
                   <th><?php echo gettext('Shipment Id') ?></th>
                   <th><?php echo gettext('Shipment Number') ?></th>
                   <th><?php echo gettext('Ship To Location') ?></th>
                   <th><?php echo gettext('Quantity') ?></th>
                   <th><?php echo gettext('Need By Date') ?></th>
                  </tr>
                 </thead>
                 <tbody class="form_data_detail_tbody">
                  <?php
                  $detailCount = 0;
                  foreach ($po_requisition_detail_object as $po_requisition_detail) {
                   $class_third = 'po_requisition_detail';
                   $$class_third = &$po_requisition_detail;
                   ?>
                   <tr class="po_requisition_detail<?php echo $count . '-' . $detailCount; ?>">
                    <td>
                     <?php
                     echo ino_inline_action($$class_third->po_requisition_detail_id, array('po_requisition_header_id' => $$class->po_requisition_header_id,
                      'po_requisition_line_id' => $$class_second->po_requisition_line_id), 'add_row_detail_img', 'detail_id_cb');
                     ?>
                    </td>
                    <td><?php form::text_field_wid3sr('po_requisition_detail_id'); ?></td>
                    <td><?php echo $f->number_field('shipment_number', $$class_third->shipment_number, '', '', 'detail_number', 1); ?></td>
                    <td><?php form::text_field_wid3('ship_to_location_id'); ?></td>
                    <td><?php form::number_field_wid3s('quantity'); ?></td>
                    <td><?php echo $f->date_fieldFromToday_m('need_by_date', ($$class_third->need_by_date), false); ?></td>
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
                   <th><?php echo gettext('Order Type') ?></th>
                   <th><?php echo gettext('Order Number') ?></th>
                   <th><?php echo gettext('Subinventory') ?></th>
                   <th><?php echo gettext('Locator') ?></th>
                   <th><?php echo gettext('Requestor') ?></th>
                   <th><?php echo gettext('IR Receipt Status') ?></th>
                  </tr>
                 </thead>
                 <tbody class="form_data_detail_tbody">
                  <?php
                  $detailCount = 0;
                  foreach ($po_requisition_detail_object as $po_requisition_detail) {
                   $class_third = 'po_requisition_detail';
                   $$class_third = &$po_requisition_detail;
                   ?>
                   <tr class="po_requisition_detail<?php echo $count . '-' . $detailCount; ?>">
                    <td><?php $f->text_field_wid3r('order_type'); ?></td>
                    <td><?php $f->text_field_wid3r('order_number'); ?></td>
                    <td>
                     <?php echo $f->select_field_from_object('subinventory_id', subinventory::find_all_of_org_id($$class_second->receving_org_id), 'subinventory_id', 'subinventory', $$class_third->subinventory_id, '', 'subinventory_id copyValue', ''); ?>
                    </td>
                    <td>
                     <?php echo $f->select_field_from_object('locator_id', locator::find_all_of_subinventory($$class_third->subinventory_id), 'locator_id', 'locator', $$class_third->locator_id, '', 'locator_id copyValue', ''); ?>
                    </td>
                    <td><?php $f->text_field_wid3('requestor'); ?></td>
                    <td><?php $f->text_field_wid3('ir_status'); ?></td>
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
                   <th><?php echo gettext('Charge Ac') ?></th>
                   <th><?php echo gettext('Accrual Ac') ?></th>
                   <th><?php echo gettext('Budget Ac') ?></th>
                   <th><?php echo gettext('PPV Ac') ?></th>
                  </tr>
                 </thead>
                 <tbody class="form_data_detail_tbody">
                  <?php
                  $detailCount = 0;
                  foreach ($po_requisition_detail_object as $po_requisition_detail) {
                   $class_third = 'po_requisition_detail';
                   $$class_third = &$po_requisition_detail;
                   ?>
                   <tr class="po_requisition_detail<?php echo $count . '-' . $detailCount; ?>">
                    <td><?php $f->ac_field_wid3m('charge_ac_id', 'copyValue', 'A,X'); ?></td>
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
                  foreach ($po_requisition_detail_object as $po_requisition_detail) {
                   $class_third = 'po_requisition_detail';
                   $$class_third = &$po_requisition_detail;
                   ?>
                   <tr class="po_requisition_detail<?php echo $count . '-' . $detailCount; ?>">
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
         <th><?php echo gettext('Price List') ?></th>
         <th><?php echo gettext('Price Date') ?></th>
         <th><?php echo gettext('Unit Price') ?>#</th>
         <th><?php echo gettext('Line Price') ?>#</th>
         <th><?php echo gettext('Line Description') ?></th>
         <th><?php echo gettext('Ref Doc Type') ?></th>
         <th><?php echo gettext('Ref Number') ?></th>
         <th><?php echo gettext('BPA Number') ?></th>
        </tr>
       </thead>
       <tbody class="form_data_line_tbody">
        <?php
        $count = 0;
        $document_number_a = array(null);
        foreach ($po_requisition_line_object as $po_requisition_line) {
//echo $$class->bu_org_id . ' : '. $$class->supplier_site_id .  ' : ' . $$class_second->item_id_m ;
         if (!empty($$class->bu_org_id) && !empty($$class->supplier_site_id) && !empty($$class_second->item_id_m)) {
          $document_number_obj = po_blanket_v::find_all_active_bpa($$class->bu_org_id, $$class->supplier_site_id, $$class_second->item_id_m);
          $document_number_a = [];
          if ($document_number_obj) {
           foreach ($document_number_obj as $obj) {
            $document_number_a[$obj->po_line_id] = $obj->po_number . ' Line# ' . $obj->po_line_number;
           }
          }
         }
         ?>         
         <tr class="po_requisition_line<?php echo $count ?>">

          <td><?php echo $f->select_field_from_object('price_list_header_id', mdm_price_list_header::find_all_purchasing_pl(), 'mdm_price_list_header_id', 'price_list', $$class_second->price_list_header_id, '', 'medium copyValue'); ?>
          </td>
          <td><?php echo $f->date_fieldAnyDay('price_date', $$class_second->price_date, 'copyValue') ?></td>
          <td><?php echo $f->number_field('unit_price', $$class_second->unit_price); ?></td>
          <td><?php echo $f->number_field('line_price', $$class_second->line_price); ?></td>

          <td><?php form::text_field_wid2('line_description'); ?></td>
          <td><?php form::text_field_wid2('reference_doc_type'); ?></td>
          <td><?php form::text_field_wid2s('reference_doc_number'); ?></td>
          <td><?php echo $f->select_field_from_array('bpa_po_line_id', $document_number_a, $$class_second->bpa_po_line_id); ?></td>
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

</div>
<div id="js_data">
 <ul id="js_saving_data">
  <li class="headerClassName" data-headerClassName="po_requisition_header" ></li>
  <li class="lineClassName" data-lineClassName="po_requisition_line" ></li>
  <li class="detailClassName" data-detailClassName="po_requisition_detail" ></li>
  <li class="savingOnlyHeader" data-savingOnlyHeader="false" ></li>
  <li class="primary_column_id" data-primary_column_id="po_requisition_header_id" ></li>
  <li class="form_header_id" data-form_header_id="po_requisition_header" ></li>
  <li class="line_key_field" data-line_key_field="item_description" ></li>
  <li class="single_line" data-single_line="false" ></li>
  <!--<li class="single_line" data-enable_select="true" ></li>-->
  <li class="form_line_id" data-form_line_id="po_requisition_line" ></li>
 </ul>
 <ul id="js_contextMenu_data">
  <li class="docHedaderId" data-docHedaderId="po_requisition_header_id" ></li>
  <li class="docLineId" data-docLineId="po_requisition_line_id" ></li>
  <li class="docDetailId" data-docDetailId="po_requisition_detail_id" ></li>
  <li class="btn1DivId" data-btn1DivId="po_requisition_header" ></li>
  <li class="btn2DivId" data-btn2DivId="form_line" ></li>
  <li class="trClass" data-docHedaderId="po_requisition_line" ></li>
  <li class="tbodyClass" data-tbodyClass="form_data_line_tbody" ></li>
  <li class="noOfTabbs" data-noOfTabbs="3" ></li>
 </ul>
</div>
