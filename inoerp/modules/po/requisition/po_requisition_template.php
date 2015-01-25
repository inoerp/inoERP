<div id="po_requisition_divId">

 <div id ="form_header"><span class="heading">Requisition Header </span>
  <form action=""  method="post" id="po_requisition_header"  name="po_requisition_header">
   <div id="tabsHeader">
    <ul class="tabMain">
     <li><a href="#tabsHeader-1">Basic Info</a></li>
     <li><a href="#tabsHeader-2">Finance</a></li>
     <li><a href="#tabsHeader-3">Address Details</a></li>
     <li><a href="#tabsHeader-4">Attachments</a></li>
     <li><a href="#tabsHeader-5">Notes</a></li>
     <li><a href="#tabsHeader-6">Actions</a></li>
    </ul>
    <div class="tabContainer">
     <div id="tabsHeader-1" class="tabContent">
      <div class="large_shadow_box"> 
       <ul class="column header_field">
        <li><label><img src="<?php echo HOME_URL; ?>themes/images/serach.png" class="po_requisition_header_id select_popup clickable">
          Requisition  Id</label>
         <?php echo $f->text_field_dr('po_requisition_header_id') ?>
         <a name="show" href="form.php?class_name=po_requisition_header&<?php echo "mode=$mode"; ?>" class="show document_id po_requisition_header_id"><img src="<?php echo HOME_URL; ?>themes/images/refresh.png"/></a> 
        </li>
        <li><label>Requisition Number</label> <?php echo $f->text_field_d('po_requisition_number', 'primary_column2'); ?>             </li>
        <li><label>BU Name(1)</label>
         <?php echo $f->select_field_from_object('bu_org_id', org::find_all_business(), 'org_id', 'org', $$class->bu_org_id, 'bu_org_id', '', 1, $readonly1); ?>
        </li>
        <li><label>Requisition Type(2)</label>
         <?php echo form::select_field_from_array('po_requisition_type', po_requisition_header::$po_requisition_type_a, $$class->po_requisition_type, 'po_requisition_type', '', 1, $readonly1); ?>
        </li>
        <li><?php echo $f->hidden_field_withId('supplier_id', $$class->supplier_id); ?>
         <label class="auto_complete"><img src="<?php echo HOME_URL; ?>themes/images/serach.png" class="supplier_id select_popup clickable">
          Supplier Name</label> 
         <?php echo $f->text_field_D('supplier_name', 'select_supplier_name'); ?> </li>
        <li><label class="auto_complete">Supplier Number : </label> <?php $f->text_field_d('supplier_number'); ?></li>
        <li><label>Supplier Site</label>
         <?php
         $supplier_site_obj = !empty($$class->supplier_id) ? supplier_site::find_by_parent_id($$class->supplier_id) : array();
         echo $f->select_field_from_object('supplier_site_id', $supplier_site_obj, 'supplier_site_id', 'supplier_site_name', $$class->supplier_site_id, 'supplier_site_id', '', '', $readonly1);
         ?> </li>
        <li><label>Status</label>                      
         <?php echo $f->select_field_from_object('requisition_status', po_header::po_status(), 'option_line_code', 'option_line_value', $$class->requisition_status, 'requisition_status', 'dont_copy', '', 1); ?>
        </li>
        <li><label>Revision</label>
         <?php echo form::checkBox_field('rev_enabled_cb', $$class->rev_enabled_cb, 'rev_enabled_cb', $readonly); ?>
        </li> 
        <li><label>Rev Number</label>  <?php form::text_field_wid('rev_number'); ?>  </li> 
        <li><label>Buyer : </label> <?php form::text_field_wid('buyer'); ?>   </li> 
        <li><label>Description : </label>  <?php form::text_field_wid('description'); ?> </li> 
       </ul>
      </div>
     </div>
     <div id="tabsHeader-2" class="tabContent">
      <div> 
       <ul class="column five_column">
        <li><label>Currency : </label>
         <?php echo $f->select_field_from_object('currency', option_header::currencies(), 'option_line_code', 'option_line_code', $$class->currency, 'currency', '', 1, $readonly); ?>
        </li>
        <li><label>Exchange Rate Type : </label><?php echo form::text_field_d('exchange_rate_type'); ?>              </li>
        <li><label>Exchange Rate : </label>  <?php form::number_field_d('exchange_rate'); ?>              </li>
        <li><label>Header Amount : </label>  <?php form::number_field_d('header_amount'); ?>              </li>
        <li><label>Payment Term : </label>
         <?php echo $f->select_field_from_object('payment_term_id', payment_term::find_all(), 'payment_term_id', 'payment_term', $$class->payment_term_id, 'payment_term_id', '', 1, $readonly); ?>
        </li>
       </ul>
      </div>
     </div>
     <div id="tabsHeader-3" class="tabContent">
      <div> 
       <div class="left_half shipto address_details">
        <ul class="column two_column">
         <li><label><img src="<?php echo HOME_URL; ?>themes/images/serach.png" class="address_popup select_popup clickable">
           Ship To Site Id : </label>
          <?php $f->text_field_d('ship_to_id', 'address_id site_address_id'); ?>
         </li>
         <li><label>Address Name : </label><?php $f->text_field_dr('ship_to_address_name', 'address_name'); ?></li>
         <li><label>Address :</label> <?php $f->text_field_dr('ship_to_address', 'address'); ?></li>
         <li><label>Country  : </label> <?php $f->text_field_dr('ship_to_country', 'country'); ?></li>
         <li><label>Postal Code  : </label><?php echo $f->text_field_dr('ship_to_postal_code', 'postal_code'); ?></li>
        </ul>
       </div> 
       <div class="right_half billto address_details">
        <ul class="column two_column">
         <li><label><img src="<?php echo HOME_URL; ?>themes/images/serach.png" class="address_popup select_popup clickable">
           Bill To Site Id :</label>
          <?php $f->text_field_d('bill_to_id', 'address_id site_address_id'); ?>
         </li>
         <li><label>Address Name :</label><?php $f->text_field_dr('bill_to_address_name', 'address_name'); ?> </li>
         <li><label>Address :</label> <?php $f->text_field_dr('bill_to_address', 'address'); ?></li>
         <li><label>Country  : </label> <?php $f->text_field_dr('bill_to_country', 'country'); ?></li>
         <li><label>Postal Code  : </label><?php echo $f->text_field_dr('bill_to_postal_code', 'postal_code'); ?></li>
        </ul>
       </div> 
      </div>
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
        <li id="document_print"><label>Document Print : </label>
         <a class="button" target="_blank"
            href="po_requisition_print.php?po_requisition_header_id=<?php echo!(empty($$class->po_requisition_header_id)) ? $$class->po_requisition_header_id : ""; ?>" >Print Requisition</a>
        </li>
        <li><label>Action</label>
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
 <div id="form_line" class="form_line"><span class="heading">Requisition Lines & Shipments </span>
  <form action=""  method="po_requisitionst" id="po_requisition_site"  name="po_requisition_line">
   <div id="tabsLine">
    <ul class="tabMain">
     <li><a href="#tabsLine-1">Basic</a></li>
     <li><a href="#tabsLine-2">Other Info</a></li>
     <li><a href="#tabsLine-3">Notes</a></li>
    </ul>
    <div class="tabContainer">
     <div id="tabsLine-1" class="tabContent">
      <table class="form_line_data_table">
       <thead> 
        <tr>
         <th>Action</th>
         <th>Line Id</th>
         <th>Line#</th>
         <th>Receiving Org</th>
         <th>Type</th>
         <th>Item Number</th>
         <th>Item Description</th>
         <th>UOM</th>
         <th>Quantity</th>
         <th>Shipment Details</th>
        </tr>
       </thead>
       <tbody class="form_data_line_tbody">
        <?php
        $count = 0;
        foreach ($po_requisition_line_object as $po_requisition_line) {
         ?>         
         <tr class="po_requisition_line<?php echo $count ?>">
          <td>    
           <ul class="inline_action">
            <li class="add_row_img"><img  src="<?php echo HOME_URL; ?>themes/images/add.png"  alt="add new line" /></li>
            <li class="remove_row_img"><img src="<?php echo HOME_URL; ?>themes/images/remove.png" alt="remove this line" /> </li>
            <li><input type="checkbox" name="line_id_cb" value="<?php echo htmlentities($po_requisition_line->item_description); ?>"></li>           
            <li><?php echo form::hidden_field('po_requisition_header_id', $po_requisition_header->po_requisition_header_id); ?></li>
           </ul>
          </td>
          <td><?php form::text_field_wid2sr('po_requisition_line_id'); ?></td>
          <td><?php echo form::text_field('line_number', $$class_second->line_number, '8', '20', 1, 'Auto no', '', $readonly, 'lines_number'); ?></td>
          <td><?php echo $f->select_field_from_object('receving_org_id', org::find_all_inventory(), 'org_id', 'org', $$class_second->receving_org_id, '', '', 1, $readonly); ?></td>
          <td><?php echo form::select_field_from_object('line_type', po_requisition_line::po_requisition_line_types(), 'option_line_code', 'option_line_value', $$class_second->line_type, 'line_type', $readonly); ?></td>
          <td><?php
           echo $f->hidden_field('item_id_m', $$class_second->item_id_m);
           form::text_field_wid2('item_number', 'select_item_number');
           ?>
           <img src="<?php echo HOME_URL; ?>themes/images/serach.png" class="select_item_number select_popup"></td>
          <td><?php form::text_field_wid2('item_description'); ?></td>
          <td><?php
           echo form::select_field_from_object('uom_id', uom::find_all(), 'uom_id', 'uom_name', $$class_second->uom_id, '', '', 'uom_id');
           ?></td>
          <td><?php form::number_field_wid2s('line_quantity'); ?></td>

          <td class="add_detail_values"><img src="<?php echo HOME_URL; ?>themes/images/page_add_icon_16.png" class="add_detail_values_img" alt="add detail values" />
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
            <fieldset class="form_detail_data_fs"><legend>Detail Data</legend>
             <div class="tabsDetail">
              <ul class="tabMain">
               <li class="tabLink"><a href="#tabsDetail-1-<?php echo $count ?>">Basic</a></li>
               <li class="tabLink"><a href="#tabsDetail-2-<?php echo $count ?>">Delivery</a></li>
               <li class="tabLink"><a href="#tabsDetail-3-<?php echo $count ?>">Finance</a></li>
               <li class="tabLink"><a href="#tabsDetail-4-<?php echo $count ?>">Status</a></li>
              </ul>
              <div class="tabContainer">
               <div id="tabsDetail-1-<?php echo $count ?>" class="tabContent">
                <table class="form form_detail_data_table detail">
                 <thead>
                  <tr>
                   <th>Action</th>
                   <th>Shipment Id</th>
                   <th>Shipment Number</th>
                   <th>Ship To Location</th>
                   <th>Quantity</th>
                   <th>Need By Date</th>
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
                     <ul class="inline_action">
                      <li class="add_row_detail_img"><img  src="<?php echo HOME_URL; ?>themes/images/add.png"  alt="add new line" /></li>
                      <li class="remove_row_img"><img src="<?php echo HOME_URL; ?>themes/images/remove.png" alt="remove this line" /> </li>
                      <li><input type="checkbox" name="detail_id_cb" value="<?php echo htmlentities($po_requisition_detail->po_requisition_detail_id); ?>"></li>           
                      <li><?php echo form::hidden_field('po_requisition_line_id', $po_requisition_line->po_requisition_line_id); ?></li>
                      <li><?php echo form::hidden_field('po_requisition_header_id', $po_requisition_header->po_requisition_header_id); ?></li>

                     </ul>
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
                   <th>Order Number</th>
                   <th>Sub inventory</th>
                   <th>Locator</th>
                   <th>Requestor</th>
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
                    <td><?php form::text_field_wid3('order_number'); ?></td>
                    <td>
                     <?php echo $f->select_field_from_object('subinventory_id', subinventory::find_all_of_org_id($$class_second->receving_org_id), 'subinventory_id', 'subinventory', $$class_third->subinventory_id, '', 'subinventory_id copyValue', ''); ?>
                    </td>
                    <td>
                     <?php echo $f->select_field_from_object('locator_id', locator::find_all_of_subinventory($$class_third->subinventory_id), 'locator_id', 'locator', $$class_third->locator_id, '', 'locator_id copyValue', ''); ?>
                    </td>
                    <td><?php $f->text_field_wid3('requestor'); ?></td>
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
                   <th>Charge Ac</th>
                   <th>Accrual Ac</th>
                   <th>Budget Ac</th>
                   <th>PPV Ac</th>
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
                <table class="form form_detail_data_table detail"><lable>Quantities</lable>
                 <thead>
                  <tr>
                   <th>Received</th>
                   <th>Accepted</th>
                   <th>Delivered</th>
                   <th>Invoiced</th>
                   <th>Paid</th>
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

         <th>Price List</th>
         <th>Pricing Date</th>
         <th>Unit Price</th>
         <th>Line Price</th>
         <th>Line Description</th>
         <th>Ref Doc Type</th>
         <th>Ref Number</th>
         <th>BPA Number</th>
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
          <td><?php form::text_field_wid2('reference_doc_number'); ?></td>
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
     <div id="tabsLine-3" class="tabContent">
      <table class="form_line_data_table">
       <thead> 
        <tr>
         <th>Comments</th>

        </tr>
       </thead>
       <tbody class="form_data_line_tbody">
        <?php
        $count = 0;
        foreach ($po_requisition_line_object as $po_requisition_line) {
         ?>         
         <tr class="po_requisition_line<?php echo $count ?>">
          <td></td>
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

