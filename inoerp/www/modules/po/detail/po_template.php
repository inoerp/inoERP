<div id="all_contents">
 <div id="content_left"></div>
 <div id="content_right">
  <div id="content_right_left">
   <div id="content_top"></div>
   <div id="content">
    <div id="structure">
     <div id="po_divId">
      <?php echo (!empty($show_message)) ? $show_message : ""; ?> 
      <!--    End of place for showing error messages-->

      <div id ="form_header"><span class="heading"><?php echo gettext('Purchase Order') ?> </span>
       <form action=""  method="post" id="po_header"  name="po_header">
        <div id="tabsHeader">
         <ul class="tabMain">
          <li><a href="#tabsHeader-1"><?php echo gettext('Basic Info') ?></a></li>
          <li><a href="#tabsHeader-2"><?php echo gettext('Finance') ?></a></li>
          <li><a href="#tabsHeader-3"><?php echo gettext('Address Details') ?></a></li>
          <li><a href="#tabsHeader-4"><?php echo gettext('Notes') ?></a></li>
          <li><a href="#tabsHeader-5"><?php echo gettext('Attachments') ?></a></li>
          <li><a href="#tabsHeader-6"><?php echo gettext('Actions') ?></a></li>
         </ul>
         <div class="tabContainer">
          <div id="tabsHeader-1" class="tabContent">
           <div class="large_shadow_box"> 
            <ul class="column five_column">
             <li><label><img src="<?php echo HOME_URL; ?>themes/images/serach.png" class="po_header_id select_popup clickable">
               <?php echo gettext('PO Header Id') ?> : </label>
              <?php $f->text_field_dsr('po_header_id') ?>
              <a name="show" href="po.php?po_header_id=" class="show po_header_id"><img src="<?php echo HOME_URL; ?>themes/images/refresh.png"/></a> 
             </li>
             <li><label><?php echo gettext('BU Name') ?>(1) : </label>
              <?php echo $f->select_field_from_object('bu_org_id', org::find_all_business(), 'org_id', 'org', $$class->bu_org_id, 'bu_org_id', '', 1, $readonly1); ?>
             </li>
             <li><label><?php echo gettext('PO Type') ?>(2) : </label>
              <?php echo $f->select_field_from_array('po_type', po_header::$po_type_a, $$class->po_type, 'po_type', '', 1); ?>
             </li>
             <li><label><?php echo gettext('PO Number') ?> : </label> <?php $f->text_field_d('po_number', 'primary_column2'); ?> </li>
             <li><label><?php echo gettext('Rel') ?># : </label> <?php $f->text_field_dsr('release_number'); ?>
             <li><label><?php echo gettext('Status') ?> : </label>                      
              <?php echo $f->select_field_from_object('po_status', po_header::po_status(), 'option_line_code', 'option_line_value', $$class->po_status, 'po_status', 'dont_copy', '', 1); ?>
             </li>
             <?php echo $f->hidden_field_withId('ref_po_header_id', $$class->ref_po_header_id); ?></li>
             <li><?php echo $f->hidden_field_withId('supplier_id', $$class->supplier_id); ?>
              <label class="auto_complete"><img src="<?php echo HOME_URL; ?>themes/images/serach.png" class="supplier_id select_popup clickable">
               <?php echo gettext('Supplier Name') ?> : </label> 
              <?php echo $f->text_field('supplier_name', $$class->supplier_name, '20', 'supplier_name', 'select_supplier_name', 1, $readonly1); ?> </li>
             <li><label class="auto_complete"><?php echo gettext('Supplier Number') ?> : </label> <?php $f->text_field_d('supplier_number'); ?></li>
             <li><label><?php echo gettext('Supplier Site') ?> : </label>
              <?php
              $supplier_site_obj = !empty($$class->supplier_id) ? supplier_site::find_by_parent_id($$class->supplier_id) : array();
              echo $f->select_field_from_object('supplier_site_id', $supplier_site_obj, 'supplier_site_id', 'supplier_site_name', $$class->supplier_site_id, 'supplier_site_id', '', '', $readonly1);
              ?> </li>
             <li><label><?php echo gettext('Revision') ?> : </label>
              <?php echo form::checkBox_field('rev_enabled_cb', $$class->rev_enabled_cb, 'rev_enabled_cb', $readonly); ?>
             </li> 
             <li><label><?php echo gettext('Rev Number') ?> : </label>
              <?php form::text_field_wid('rev_number'); ?>
             </li> 
             <li><label><?php echo gettext('Buyer') ?> : </label><?php form::text_field_wid('buyer'); ?></li> 
             <li><label><?php echo gettext('Description') ?> : </label><?php $f->text_field_dl('description'); ?></li> 
            </ul>
           </div>
          </div>
          <div id="tabsHeader-2" class="tabContent">
           <div> 
            <ul class="column five_column">
             <li><label><?php echo gettext('Agreement Start Date') ?> : </label>
              <?php echo $f->date_fieldFromToday('agreement_start_date', $$class->agreement_start_date) ?>
             </li>
             <li><label><?php echo gettext('Agreement End Date') ?> : </label>
              <?php echo $f->date_fieldFromToday('agreement_end_date', $$class->agreement_start_date) ?>
             </li>
             <li><label><?php echo gettext('Doc Currency') ?> : </label>
              <?php echo $f->select_field_from_object('doc_currency', option_header::currencies(), 'option_line_code', 'option_line_code', $$class->doc_currency, 'doc_currency', '', 1, $readonly); ?>
             </li>
             <li><label><?php echo gettext('Ledger Currency') ?> : </label>
              <?php echo $f->select_field_from_object('currency', option_header::currencies(), 'option_line_code', 'option_line_code', $$class->currency, 'currency', '', 1, 1); ?>
             </li>
             <li><label><?php echo gettext('Exchange Rate Type') ?> : </label>
              <?php echo $f->select_field_from_object('exchange_rate_type', gl_currency_conversion::currency_conversion_type(), 'option_line_code', 'option_line_code', $$class->exchange_rate_type, 'exchange_rate_type', '', 1, $readonly); ?>
             </li>
             <li><label><?php echo gettext('Exchange Rate') ?> : </label>
              <?php form::number_field_d('exchange_rate'); ?>
             </li>
             <li><label><?php echo gettext('Price List') ?> : </label>
              <?php echo$f->select_field_from_object('price_list_header_id', mdm_price_list_header::find_all_purchasing_pl(), 'mdm_price_list_header_id', 'price_list', $$class->price_list_header_id); ?>
             </li>
             <li><label><?php echo gettext('Header Amount') ?> : </label><?php echo $f->number_field('header_amount', $$class->header_amount, '15', 'header_amount', '', 1); ?></li>
             <li><label><?php echo gettext('Released Amount') ?> : </label> <?php form::number_field_d('released_amount'); ?> </li>
             <li><label><?php echo gettext('Payment Term') ?> : </label>
              <?php echo $f->select_field_from_object('payment_term_id', payment_term::find_all(), 'payment_term_id', 'payment_term', $$class->payment_term_id, 'payment_term_id', '', 1, $readonly1); ?>
             </li>
            </ul>
           </div>
          </div>
          <div id="tabsHeader-3" class="tabContent">
           <div class="left_half shipto address_details">
            <ul class="column two_column">
             <li><label><img src="<?php echo HOME_URL; ?>themes/images/serach.png" class="address_popup select_popup clickable">
               <?php echo gettext('Ship To Site Id') ?> : </label>
              <?php $f->text_field_d('ship_to_id', 'address_id site_address_id'); ?>
             </li>
             <li><label><?php echo gettext('Address Name') ?> : </label><?php $f->text_field_dr('ship_to_address_name', 'address_name'); ?></li>
             <li><label><?php echo gettext('Address') ?> :</label> <?php $f->text_field_dr('ship_to_address', 'address'); ?></li>
             <li><label><?php echo gettext('Country') ?>  : </label> <?php $f->text_field_dr('ship_to_country', 'country'); ?></li>
             <li><label><?php echo gettext('Postal Code') ?>  : </label><?php echo $f->text_field_dr('ship_to_postal_code', 'postal_code'); ?></li>
            </ul>
           </div> 
           <div class="right_half billto address_details">
            <ul class="column two_column">
             <li><label><img src="<?php echo HOME_URL; ?>themes/images/serach.png" class="address_popup select_popup clickable">
               <?php echo gettext('Bill To Site Id') ?> :</label>
              <?php $f->text_field_d('bill_to_id', 'address_id site_address_id'); ?>
             </li>
             <li><label><?php echo gettext('Address Name') ?> :</label><?php $f->text_field_dr('bill_to_address_name', 'address_name'); ?> </li>
             <li><label><?php echo gettext('Address') ?> :</label> <?php $f->text_field_dr('bill_to_address', 'address'); ?></li>
             <li><label><?php echo gettext('Country') ?>  : </label> <?php $f->text_field_dr('bill_to_country', 'country'); ?></li>
             <li><label><?php echo gettext('Postal Code') ?>  : </label><?php echo $f->text_field_dr('bill_to_postal_code', 'postal_code'); ?></li>
            </ul>
           </div> 
          </div>
          <div id="tabsHeader-4" class="tabContent">
           <div> 
            <div id="comments">
             <div id="comment_list">
              <?php echo!(empty($comments)) ? $comments : ""; ?>
             </div>
             <?php
             $reference_table = 'po_header';
             $reference_id = $$class->po_header_id;
             include_once HOME_DIR . '/comment.php';
             ?>
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
                 href="<?php echo HOME_URL ?>modules/po/po_print.php?po_header_id=<?php echo!(empty($$class->po_header_id)) ? $$class->po_header_id : ""; ?>" >Print PO</a>
             </li>
             <li><label><?php echo gettext('Action') ?></label>
              <?php
              $action_readonly = ($$class->po_status == 'CLOSED') ? 1 : '';
              echo $f->select_field_from_array('action', po_header::$action_a, '', 'action', '', '', $readonly, $action_readonly)
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

      <div id="form_line" class="form_line"><span class="heading"><?php echo gettext('PO Lines & Shipments') ?> </span>
       <form action=""  method="post" id="po_site"  name="po_line">
        <div id="tabsLine">
         <ul class="tabMain">
          <li><a href="#tabsLine-1"><?php echo gettext('Basic') ?></a></li>
          <li><a href="#tabsLine-2"><?php echo gettext('Other Info') ?></a></li>
          <li><a href="#tabsLine-3"><?php echo gettext('Notes') ?></a></li>
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
              <th><?php echo gettext('Quantity') ?></th>
              <th><?php echo gettext('UOM') ?></th>
              <th><?php echo gettext('Shipment Details') ?></th>
             </tr>
            </thead>
            <tbody class="form_data_line_tbody">
             <?php
             $count = 0;
             foreach ($po_line_object as $po_line) {
              ?>         
              <tr class="po_line<?php echo $count ?>">
               <td>    
                <ul class="inline_action">
                 <li class="add_row_img"><img  src="<?php echo HOME_URL; ?>themes/images/add.png"  alt="add new line" /></li>
                 <li class="remove_row_img"><img src="<?php echo HOME_URL; ?>themes/images/remove.png" alt="remove this line" /> </li>
                 <li><input type="checkbox" name="line_id_cb" value="<?php echo htmlentities($po_line->item_description); ?>"></li>           
                 <li><?php echo form::hidden_field('po_header_id', $po_header->po_header_id); ?></li>
                </ul>
               </td>
               <td><?php form::text_field_wid2sr('po_line_id'); ?></td>
               <td><?php echo form::text_field('line_number', $$class_second->line_number, '8', '20', 1, 'Auto no', '', $readonly, 'lines_number'); ?></td>
               <td><?php echo $f->select_field_from_object('receving_org_id', org::find_all_inventory(), 'org_id', 'org', $$class_second->receving_org_id, '', 'copyValue', 1, $readonly); ?></td>
               <td><?php echo $f->select_field_from_object('line_type', po_line::po_line_types(), 'option_line_code', 'option_line_value', $$class_second->line_type, '', 'copyValue', 1, $readonly); ?></td>
               <td><?php
             echo $f->hidden_field('item_id_m', $$class_second->item_id_m);
             form::text_field_wid2('item_number', 'select_item_number');
              ?>
                <i class="select_item_number select_popup clickable fa fa-search"></i></td>
               <td><?php form::text_field_wid2('item_description'); ?></td>
               <td><?php echo $f->number_field('line_quantity', $$class_second->line_quantity); ?></td>
               <td><?php
               echo form::select_field_from_object('uom_id', uom::find_all(), 'uom_id', 'uom_name', $$class_second->uom_id, '', '', 'uom_id');
              ?></td>
               <td class="add_detail_values"><img src="<?php echo HOME_URL; ?>themes/images/page_add_icon_16.png" class="add_detail_values_img" alt="<?php echo gettext('add detail values') ?>" />
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
                 <fieldset class="form_detail_data_fs"><legend><?php echo gettext('Detail Data') ?></legend>
                  <div class="tabsDetail">
                   <ul class="tabMain">
                    <li class="tabLink"><a href="#tabsDetail-1-1"><?php echo gettext('Basic') ?></a></li>
                    <li class="tabLink"><a href="#tabsDetail-2-1"><?php echo gettext('Delivery') ?></a></li>
                    <li class="tabLink"><a href="#tabsDetail-3-1"><?php echo gettext('Finance') ?></a></li>
                    <li class="tabLink"><a href="#tabsDetail-4-1"><?php echo gettext('Status Quantities') ?> </a></li>
                   </ul>
                   <div class="tabContainer">
                    <div id="tabsDetail-1-1" class="tabContent">
                     <table class="form form_detail_data_table detail">
                      <thead>
                       <tr>
                        <th><?php echo gettext('Action') ?></th>
                        <th><?php echo gettext('Shipment Id') ?></th>
                        <th><?php echo gettext('Shipment Number') ?></th>
                        <!--<th><?php //echo gettext('Inventory') ?></th>-->
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
                        <tr class="po_detail<?php echo $count . '-' . $detailCount; ?><?php echo $detailCount != 0 ? ' new_object' : '' ?>">
                         <td>   
                          <ul class="inline_action">
                           <li class="add_row_detail_img"><img  src="<?php echo HOME_URL; ?>themes/images/add.png"  alt="<?php echo gettext('add new line') ?>" /></li>
                           <li class="remove_row_img"><img src="<?php echo HOME_URL; ?>themes/images/remove.png" alt="<?php echo gettext('remove this line') ?>" /> </li>
                           <li><input type="checkbox" name="detail_id_cb" value="<?php echo htmlentities($po_detail->po_detail_id); ?>"></li>           
                           <li><?php echo form::hidden_field('po_line_id', $po_line->po_line_id); ?></li>
                           <li><?php echo form::hidden_field('po_header_id', $po_header->po_header_id); ?></li>

                          </ul>
                         </td>
                         <td><?php form::text_field_wid3sr('po_detail_id'); ?></td>
                         <td><?php echo $f->number_field('shipment_number', $$class_third->shipment_number, '', '', 'detail_number', 1); ?></td>
                         <td><?php $f->text_field_wid3('ship_to_location_id'); ?></td>
                         <td><?php form::number_field_wid3s('quantity'); ?></td>
                         <td><?php echo $f->date_fieldFromToday('need_by_date', ($$class_third->need_by_date)); ?></td>
                         <td><?php echo $f->date_fieldFromToday('promise_date', ($$class_third->promise_date)); ?></td>

                        </tr>
                        <?php
                        $detailCount++;
                       }
                       ?>
                      </tbody>
                     </table>
                    </div>
                    <div id="tabsDetail-2-1" class="tabContent">
                     <table class="form form_detail_data_table detail">
                      <thead>
                       <tr>
                        <th><?php echo gettext('Subinventory') ?></th>
                        <th><?php echo gettext('Locator') ?></th>
                        <th><?php echo gettext('Requestor') ?></th>
                       </tr>
                      </thead>
                      <tbody class="form_data_detail_tbody">
                       <?php
                       $detailCount = 0;
                       foreach ($po_detail_object as $po_detail) {
                        $class_third = 'po_detail';
                        $$class_third = &$po_detail;
                        ?>
                        <tr class="po_detail<?php echo $count . '-' . $detailCount; ?> <?php echo $detailCount != 0 ? ' new_object' : '' ?>">
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
                    <div id="tabsDetail-3-1" class="tabContent">
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
                       foreach ($po_detail_object as $po_detail) {
                        $class_third = 'po_detail';
                        $$class_third = &$po_detail;
                        ?>
                        <tr class="po_detail<?php echo $count . '-' . $detailCount; ?><?php echo $detailCount != 0 ? ' new_object' : '' ?>">
                         <td><?php $f->ac_field_wid3m('charge_ac_id', 'copyValue'); ?></td>
                         <td><?php $f->ac_field_wid3m('accrual_ac_id', 'copyValue'); ?></td>
                         <td><?php $f->ac_field_wid3('budget_ac_id', 'copyValue'); ?></td>
                         <td><?php $f->ac_field_wid3m('ppv_ac_id', 'copyValue'); ?></td>
                        </tr>
                        <?php
                        $detailCount++;
                       }
                       ?>
                      </tbody>
                     </table>
                    </div>
                    <div id="tabsDetail-4-1" class="tabContent">
                     <table class="form form_detail_data_table detail">
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
                       foreach ($po_detail_object as $po_detail) {
                        $class_third = 'po_detail';
                        $$class_third = &$po_detail;
                        ?>
                        <tr class="po_detail<?php echo $count . '-' . $detailCount; ?> <?php echo $detailCount != 0 ? ' new_object' : '' ?>">
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
              <th><?php echo gettext('Pricing Date') ?></th>
              <th><?php echo gettext('Unit Price') ?></th>
              <th><?php echo gettext('Line Price') ?></th>
              <th><?php echo gettext('Line Description') ?></th>
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

               <td><?php echo $f->select_field_from_object('price_list_header_id', mdm_price_list_header::find_all_purchasing_pl(), 'mdm_price_list_header_id', 'price_list', $$class_second->price_list_header_id, '', 'medium copyValue'); ?>
               </td>
               <td><?php echo $f->date_fieldAnyDay('price_date', $$class_second->price_date, 'copyValue') ?></td>
               <td><?php echo $f->number_field('unit_price', $$class_second->unit_price); ?></td>
               <td><?php echo $f->number_field('line_price', $$class_second->line_price); ?></td>
               <td><?php form::text_field_wid2('line_description'); ?></td>
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
          <div id="tabsLine-3" class="tabContent">
           <table class="form_line_data_table">
            <thead> 
             <tr>
              <th><?php echo gettext('Comments') ?></th>

             </tr>
            </thead>
            <tbody class="form_data_line_tbody">
             <?php
             $count = 0;
             foreach ($po_line_object as $po_line) {
              ?>         
              <tr class="po_line<?php echo $count ?>">
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

      <!--END OF FORM HEADER-->
     </div>
    </div>
    <!--   end of structure-->
   </div>
   <div id="content_bottom"></div>
  </div>
  <div id="content_right_right"></div>
 </div>

</div>

<?php include_template('footer.inc') ?>
