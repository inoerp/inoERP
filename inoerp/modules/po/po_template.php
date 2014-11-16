<div id="all_contents">
 <div id="content_left"></div>
 <div id="content_right">
  <div id="content_right_left">
   <div id="content_top"></div>
   <div id="content">
    <div id="structure">
     <div id="po_divId">
      <!--    START OF FORM HEADER-->
      <div class="error"></div><div id="loading"></div>
      <?php echo (!empty($show_message)) ? $show_message : ""; ?> 
      <!--    End of place for showing error messages-->

      <div id ="form_header"><span class="heading">Purchase Order </span>
       <form action=""  method="post" id="po_header"  name="po_header">
        <div id="tabsHeader">
         <ul class="tabMain">
          <li><a href="#tabsHeader-1">Basic Info</a></li>
          <li><a href="#tabsHeader-2">Finance</a></li>
          <li><a href="#tabsHeader-3">Address Details</a></li>
          <li><a href="#tabsHeader-4">Notes</a></li>
          <li><a href="#tabsHeader-5">Attachments</a></li>
          <li><a href="#tabsHeader-6">Actions</a></li>
         </ul>
         <div class="tabContainer">
          <div id="tabsHeader-1" class="tabContent">
           <div class="large_shadow_box"> 
            <ul class="column five_column">
             <li><label><img src="<?php echo HOME_URL; ?>themes/images/serach.png" class="po_header_id select_popup clickable">
               PO Header Id : </label>
              <?php $f->text_field_dsr('po_header_id') ?>
              <a name="show" href="form.php?class_name=po_header" class="show po_header_id"><img src="<?php echo HOME_URL; ?>themes/images/refresh.png"/></a> 
             </li>
             <li><label>BU Name(1) : </label>
              <?php echo $f->select_field_from_object('bu_org_id', org::find_all_business(), 'org_id', 'org', $$class->bu_org_id, 'bu_org_id', '', 1, $readonly1); ?>
             </li>
             <li><label>PO Type(2) : </label>
              <?php echo $f->select_field_from_array('po_type', po_header::$po_type_a, $$class->po_type, 'po_type', '', 1, $readonly1, $readonly1); ?>
             </li>
             <li><label>PO Number : </label> <?php $f->text_field_d('po_number', 'primary_column2'); ?> </li>
             <li><label>Rel# : </label> <?php $f->text_field_dsr('release_number'); ?>
             <li><label>Status : </label>                      
              <?php echo $f->select_field_from_object('status', po_header::po_status(), 'option_line_code', 'option_line_value', $$class->po_status, 'po_status', 'dont_copy', '', 1); ?>
             </li>
             <?php echo $f->hidden_field_withId('ref_po_header_id', $$class->ref_po_header_id); ?>
             <li><?php echo $f->hidden_field_withId('supplier_id', $$class->supplier_id); ?>
              <label class="auto_complete"><img src="<?php echo HOME_URL; ?>themes/images/serach.png" class="supplier_id select_popup clickable">
               Supplier Name : </label> 
              <?php echo $f->text_field('supplier_name', $$class->supplier_name, '20', 'supplier_name', 'select_supplier_name', 1, $readonly1); ?> </li>
             <li><label class="auto_complete">Supplier Number : </label> <?php $f->text_field_d('supplier_number'); ?></li>
             <li><label>Supplier Site : </label>
              <?php
               $supplier_site_obj = !empty($$class->supplier_id) ? supplier_site::find_by_parent_id($$class->supplier_id) : array();
               echo $f->select_field_from_object('supplier_site_id', $supplier_site_obj, 'supplier_site_id', 'supplier_site_name', $$class->supplier_site_id, 'supplier_site_id', '', '', $readonly1);
              ?> </li>
             <li><label>Rev Number : </label>   <?php $f->text_field_d('rev_number'); ?></li> 
             <li><label>Multi BU : </label>
              <?php echo $f->checkBox_field('multi_bu_cb', $$class->multi_bu_cb, 'multi_bu_cb', '', $readonly1); ?>
             </li> 
             <li><label>Buyer : </label><?php form::text_field_wid('buyer'); ?></li> 
             <li><label>Description : </label><?php $f->text_field_dl('description'); ?></li> 
            </ul>
           </div>
          </div>
          <div id="tabsHeader-2" class="tabContent">
           <div> 
            <ul class="column five_column">
             <li><label>Agreement Start Date : </label>
              <?php echo $f->date_fieldFromToday('agreement_start_date', $$class->agreement_start_date) ?>
             </li>
             <li><label>Agreement End Date : </label>
              <?php echo $f->date_fieldFromToday('agreement_end_date', $$class->agreement_start_date) ?>
             </li>
             <li><label>Doc Currency : </label>
              <?php echo $f->select_field_from_object('doc_currency', option_header::currencies(), 'option_line_code', 'option_line_code', $$class->doc_currency, 'doc_currency', '', 1, $readonly); ?>
             </li>
             <li><label>Ledger Currency : </label>
              <?php echo $f->select_field_from_object('currency', option_header::currencies(), 'option_line_code', 'option_line_code', $$class->currency, 'currency', '', 1, 1); ?>
             </li>
             <li><label>Exchange Rate Type : </label>
              <?php echo $f->select_field_from_object('exchange_rate_type', gl_currency_conversion::currency_conversion_type(), 'option_line_code', 'option_line_code', $$class->exchange_rate_type, 'exchange_rate_type', '', 1, $readonly); ?>
             </li>
             <li><label>Exchange Rate : </label>
              <?php form::number_field_d('exchange_rate'); ?>
             </li>
             <li><label>Price List : </label>
              <?php echo$f->select_field_from_object('price_list_header_id', mdm_price_list_header::find_all_purchasing_pl(), 'mdm_price_list_header_id', 'price_list', $$class->price_list_header_id); ?>
             </li>
             <li><label>Header Amount : </label><?php echo $f->number_field('header_amount', $$class->header_amount, '15', 'header_amount', '', 1); ?></li>
             <li><label>Tax Amount : </label><?php echo $f->number_field('tax_amount', $$class->tax_amount, '15', 'tax_amount'); ?></li>
             <li><label>Payment Term : </label>
              <?php echo $f->select_field_from_object('payment_term_id', payment_term::find_all(), 'payment_term_id', 'payment_term', $$class->payment_term_id, 'payment_term_id', '', 1, $readonly1); ?>
             </li>
            </ul>
           </div>
          </div>
          <div id="tabsHeader-3" class="tabContent">
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
          <div id="tabsHeader-4" class="tabContent">
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
          <div id="tabsHeader-5" class="tabContent">
           <div> <?php echo ino_attachement($file) ?> </div>
          </div>
          <div id="tabsHeader-6" class="tabContent">
           <div> 
            <ul class="column four_column">
             <li id="document_print"><label>Document Print : </label>
              <a class="button" target="_blank"
                 href="<?php echo HOME_URL ?>modules/po/po_print.php?po_header_id=<?php echo!(empty($$class->po_header_id)) ? $$class->po_header_id : ""; ?>" >Print PO</a>
             </li>
             <li><label>Action</label>
              <?php
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
      <?php
       if ($$class->po_type == 'CONTRACT') {
        echo '</div></div>  </div>     <div id="content_bottom"></div>   </div>   <div id="content_right_right"></div>  </div> </div>';
        include_template('footer.inc');
        return;
       }
      ?>
      <div id="form_line" class="form_line"><span class="heading">PO Lines & Shipments </span>
       <form action=""  method="post" id="po_line"  name="po_line">
        <div id="tabsLine">
         <ul class="tabMain">
          <li><a href="#tabsLine-1">Basic</a></li>
          <li><a href="#tabsLine-2">Other Info</a></li>
          <li><a href="#tabsLine-3">Agreement Details</a></li>
         </ul>
         <div class="tabContainer">
          <div id="tabsLine-1" class="tabContent">
           <table class="form_line_data_table">
            <thead> 
             <tr>
              <th>Action</th>
              <th>Seq#</th>
              <th>Line Id</th>
              <th>Line#</th>
              <th>Receiving Org</th>
              <th>Type</th>
              <th>Item Number</th>
              <th>Revision Number</th>
              <th>Item Description</th>
              <th>Quantity</th>
              <th>UOM</th>
              <th>Shipment Details</th>
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
                <td><?php $f->seq_field_d($count) ?></td>
                <td><?php form::text_field_wid2sr('po_line_id'); ?></td>
                <td><?php echo form::text_field('line_number', $$class_second->line_number, '8', '20', 1, 'Auto no', '', $readonly, 'lines_number'); ?></td>
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
                 echo $f->select_field_from_object('revision_name', $revision_name_a, 'revision_name','revision_name', $$class_second->revision_name, '', 'small');
                 ?></td>
                <td><?php form::text_field_wid2('item_description'); ?></td>
                <td><?php echo $f->number_field('line_quantity', $$class_second->line_quantity,'','','allow_change'); ?></td>
                <td><?php
                 echo form::select_field_from_object('uom_id', uom::find_all(), 'uom_id', 'uom_name', $$class_second->uom_id, '', '', 'uom_id');
                 ?></td>
                <td class="add_detail_values"><img src="<?php echo HOME_URL; ?>themes/images/page_add_icon_16.png" class="add_detail_values_img" alt="add detail values" />
                 <?php include 'detail/po_detail_template.php'; ?>
                </td>
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
              <th>Seq#</th>
              <th>Price List</th>
              <th>Pricing Date</th>
              <th>Unit Price</th>
              <th>Line Price</th>
              <th>Tax Code</th>
              <th>Tax Amount</th>
              <th>Line Description</th>
              <th>Ref Doc Type</th>
              <th>Ref Number</th>
              <th>On Hold</th>
              <th>Hold Details</th>
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
                <td><?php echo $f->select_field_from_object('tax_code_id', mdm_tax_code::find_all_inTax_by_bu_org_id($$class->bu_org_id), 'mdm_tax_code_id', 'tax_code', $$class_second->tax_code_id, '', 'input_tax medium') ?></td>
                <td><?php form::number_field_wid2('tax_amount'); ?></td>
                <td><?php form::text_field_wid2('line_description'); ?></td>
                <td><?php form::text_field_wid2('reference_doc_type'); ?></td>
                <td><?php form::text_field_wid2('reference_doc_number'); ?></td>
                <td><?php $f->checkBox_field_wid2('hold_cb'); ?></td>
                <td><?php $f->text_field_wid2sr('po_line_id'); ?></td>
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
              <th>Seq#</th>
              <th>Agreed Quantity</th>
              <th>Released Quantity</th>
              <th>Agreed Amount </th>
              <th>Released Amount</th>
             </tr>
            </thead>
            <tbody class="form_data_line_tbody">
             <?php
              $count = 0;
              foreach ($po_line_object as $po_line) {
               if (($$class->po_type == 'BLANKET') && !empty($$class_second->po_line_id)) {
                $agrrement_details = po_line::find_agreement_details_by_lineId($$class_second->po_line_id);
                if ($agrrement_details) {
                 $$class_second->agreed_quantity = $agrrement_details->agreed_quantity;
                 $$class_second->agreed_amount = $agrrement_details->agreed_amount;
                 $$class_second->released_quantity = $agrrement_details->released_quantity;
                 $$class_second->released_amount = $agrrement_details->released_amount;
                } else {
                 $$class_second->agreed_quantity = $$class_second->agreed_amount = $$class_second->released_quantity = $$class_second->released_amount = null;
                }
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
  <!--<li class="single_line" data-enable_select="true" ></li>-->
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

<?php include_template('footer.inc') ?>