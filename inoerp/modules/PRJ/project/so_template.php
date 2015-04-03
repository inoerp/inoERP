<div id ="form_header"><span class="heading">Sales Order Header</span>
 <form action=""  method="post" id="sd_so_header"  name="sd_so_header">
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
      <ul class="column header_field">
       <li><label><img src="<?php echo HOME_URL; ?>themes/images/serach.png" class="sd_so_header_id select_popup">
         SO Header Id</label><?php echo $f->text_field_dr('sd_so_header_id') ?>
        <a name="show" href="form.php?class_name=sd_so_header&<?php echo "mode=$mode"; ?>" class="show document_id sd_so_header_id"><img src="<?php echo HOME_URL; ?>themes/images/refresh.png"/></a> 
       </li>
       <li><label>SO Number</label><?php echo $f->text_field_d('so_number', 'primary_column2'); ?></li>
       <li><label>BU Name(1)</label><?php echo form::select_field_from_object('bu_org_id', org::find_all_business(), 'org_id', 'org', $sd_so_header->bu_org_id, 'bu_org_id', $readonly1, '', ''); ?>						 </li>
       <li><label>Document Type(2)</label><?php echo $f->select_field_from_object('document_type', sd_document_type::find_all_header_levels(), 'sd_document_type_id', 'document_type_name', $sd_so_header->document_type, 'document_type', 'medium', 1, $readonly1); ?>						 </li>
       <li><?php echo $f->hidden_field_withId('ar_customer_id', $$class->ar_customer_id); ?><label class="auto_complete"><img src="<?php echo HOME_URL; ?>themes/images/serach.png" class="ar_customer_id select_popup clickable">
         Customer Name</label><?php echo $f->text_field('customer_name', $$class->customer_name, '20', 'customer_name', 'select_customer_name', '', $readonly1); ?></li>
       <li><label class="auto_complete">Customer Number</label><?php $f->text_field_d('customer_number'); ?></li>
       <li><label>Customer Site</label><?php echo $f->select_field_from_object('ar_customer_site_id', $customer_site_obj, 'ar_customer_site_id', 'customer_site_name', $$class->ar_customer_site_id, 'ar_customer_site_id', 'ar_customer_site_id', '', $readonly1); ?> </li>
       <li><label>Status</label><?php $f->text_field_dr('so_status') ?></li>
       <li><label>Revision</label><?php echo form::checkBox_field('rev_enabled_cb', $$class->rev_enabled_cb, 'rev_enabled_cb', $readonly); ?></li> 
       <li><label>Rev Number</label><?php form::text_field_wid('rev_number'); ?> </li> 
       <li><label>Sales Person</label><?php form::text_field_wid('sales_person'); ?></li> 
       <li><label>Description</label><?php form::text_field_wid('description'); ?></li> 
      </ul>
     </div>
    </div>
    <div id="tabsHeader-2" class="tabContent">
     <div class="large_shadow_box"> 
      <ul class="column header_field">
       <li><label>Doc Currency</label><?php echo $f->select_field_from_object('document_currency', option_header::currencies(), 'option_line_code', 'option_line_code', $$class->document_currency, 'document_currency', 'currency', 1, $readonly); ?>						 </li>
       <li><label>Payment Term</label><?php echo $f->select_field_from_object('payment_term_id', payment_term::find_all(), 'payment_term_id', 'payment_term', $$class->payment_term_id, '', 'payment_term_id', 1, $readonly1); ?>						 </li>
       <li><label>Payment Term Date</label><?php echo form::date_fieldAnyDay('payment_term_date', $$class->payment_term_date) ?> </li>
       <li><label>Sales Person</label><?php $f->text_field_d('sales_person') ?></li>
       <li><label>Agreement Start Date</label><?php echo form::date_field('agreement_start_date', $$class->agreement_start_date) ?></li>
       <li><label>Agreement End Date</label><?php echo form::date_field('agreement_end_date', $$class->agreement_start_date) ?></li>
       <li><label>Price List</label><?php echo$f->select_field_from_object('price_list_header_id', mdm_price_list_header::find_all(), 'mdm_price_list_header_id', 'price_list', $$class->price_list_header_id); ?>		 </li>
       <li><label>Exchange Rate Type</label><?php echo form::text_field_d('exchange_rate_type'); ?></li>
       <li><label>Exchange Rate</label><?php form::number_field_d('exchange_rate'); ?></li>
       <li><label>Header Amount</label><?php form::number_field_d('header_amount'); ?></li>
       <li><label>Tax Amount</label><?php form::number_field_d('tax_amount'); ?></li>
      </ul>
     </div>
    </div>
    <div id="tabsHeader-3" class="tabContent">
     <div class="left_half shipto address_details">
      <ul class="column four_column">
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
      <ul class="column four_column">
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
     <div> 
      <div id="comments">
       <div id="comment_list">
        <?php echo!(empty($comments)) ? $comments : ""; ?>
       </div>
       <div id ="display_comment_form">
        <?php
        $reference_table = 'sd_so_header';
        $reference_id = $$class->sd_so_header_id;
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
       <li id="document_status"><label>Action : </label>
        <?php echo $f->select_field_from_object('action', sd_so_header::so_status(), 'option_line_code', 'option_line_value', '', 'action'); ?>
       </li>
       <li id="copy_header"><label>Copy Document : </label>
        <input type="button" class="button" id="copy_docHeader" value="Header">
       </li>
       <li id="copy_line"><label></label>
        <input type="button" class="button" id="copy_docLine" value="Lines">
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

<div id="form_line" class="form_line"><span class="heading">SO Lines & Shipments </span>
 <form action=""  method="post" id="so_site"  name="sd_so_line">
  <div id="tabsLine">
   <ul class="tabMain">
    <li><a href="#tabsLine-1">Basic</a></li>
    <li><a href="#tabsLine-2">Price</a></li>
    <li><a href="#tabsLine-3">Dates</a></li>
    <li><a href="#tabsLine-4">References</a></li>
    <li><a href="#tabsLine-5">References-2</a></li>
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
        <th>Type</th>
        <th>Shipping Org</th>
        <th>Item Number</th>
        <th>Item Description</th>
        <th>UOM</th>
        <th>Line Status</th>
        <th>Quantity</th>
       </tr>
      </thead>
      <tbody class="form_data_line_tbody">
       <?php
       $count = 0;
       foreach ($sd_so_line_object as $sd_so_line) {
        ?>         
        <tr class="sd_so_line<?php echo $count ?>">
         <td>    
          <ul class="inline_action">
           <li class="add_row_img"><img  src="<?php echo HOME_URL; ?>themes/images/add.png"  alt="add new line" /></li>
           <li class="remove_row_img"><img src="<?php echo HOME_URL; ?>themes/images/remove.png" alt="remove this line" /> </li>
           <li><input type="checkbox" name="line_id_cb" value="<?php echo htmlentities($sd_so_line->item_description); ?>"></li>           
           <li><?php echo form::hidden_field('sd_so_header_id', $sd_so_header->sd_so_header_id); ?></li>
           <li><?php echo form::hidden_field('tax_code_value', $$class_second->tax_code_value); ?></li>
          </ul>
         </td>
         <td><?php $f->seq_field_d($count) ?></td>
         <td><?php form::text_field_wid2sr('sd_so_line_id'); ?></td>
         <td><?php echo form::text_field('line_number', $$class_second->line_number, '8', '20', 1, 'Auto no', '', $readonly, 'lines_number'); ?></td>
         <td><?php echo $f->select_field_from_object('line_type', sd_document_type::find_all_line_levels(), 'sd_document_type_id', 'document_type_name', $$class_second->line_type, '', 'medium', 1, $readonly); ?></td>
         <td><?php echo $f->select_field_from_object('shipping_org_id', org::find_all_inventory(), 'org_id', 'org', $$class_second->shipping_org_id, '', 'small', 1, $readonly); ?></td>
         <td><?php
          echo $f->hidden_field('item_id_m', $$class_second->item_id_m);
          form::text_field_wid2('item_number', 'select_item_number');
          ?>
          <i class="select_item_number select_popup clickable fa fa-search"></i></td>
         <td><?php form::text_field_wid2('item_description'); ?></td>
         <td><?php echo $f->select_field_from_object('uom_id', uom::find_all(), 'uom_id', 'uom_name', $$class_second->uom_id, '', 'small'); ?></td>
         <td><?php $f->text_field_wid2r('line_status'); ?></td>
         <td><?php form::number_field_wid2s('line_quantity'); ?></td>
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
       </tr>
      </thead>
      <tbody class="form_data_line_tbody">
       <?php
       $count = 0;
       foreach ($sd_so_line_object as $sd_so_line) {
        if ((empty($sd_so_line->price_list_header_id)) && !empty($document_type_i->price_list_header_id)) {
         $sd_so_line->price_list_header_id = $document_type_i->price_list_header_id;
         $sd_so_line->price_date = empty($sd_so_line->price_date) ? current_time(true) : $sd_so_line->price_date;
        }
        ?>         
        <tr class="sd_so_line<?php echo $count ?>">
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
        <th>Seq#</th>
        <th>Requested Date</th>
        <th>Promise Date </th>
        <th>Schedule Ship Date</th>
        <th>Actual Ship Date</th>
       </tr>
      </thead>
      <tbody class="form_data_line_tbody">
       <?php
       $count = 0;
       foreach ($sd_so_line_object as $sd_so_line) {
        ?>         
        <tr class="sd_so_line<?php echo $count ?>">
         <td><?php $f->seq_field_d($count) ?></td>
         <td><?php echo $f->date_fieldFromToday_d('requested_date', $$class_second->requested_date) ?></td>
         <td><?php echo $f->date_fieldFromToday('promise_date', $$class_second->promise_date) ?></td>
         <td><?php echo $f->date_fieldFromToday('schedule_ship_date', $$class_second->schedule_ship_date) ?></td>
         <td><?php echo $f->date_fieldFromToday_r('actual_ship_date', $$class_second->actual_ship_date, 1) ?></td>
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
       <tr><th>Seq#</th>
        <th>Line Description</th>
        <th>Supply Source </th>
        <th>Destination Type </th>
        <th>Picked Quantity </th>
        <th>Shipped Quantity</th>
        <th>Ref Doc Type</th>
        <th>Ref Number</th>
       </tr>
      </thead>
      <tbody class="form_data_line_tbody">
       <?php
       $count = 0;
       foreach ($sd_so_line_object as $sd_so_line) {
        if ((empty($sd_so_line->supply_source)) && !empty($document_type_i->supply_source)) {
         $sd_so_line->supply_source = $document_type_i->supply_source;
        }
        if ((empty($sd_so_line->destination_type)) && !empty($document_type_i->destination_type)) {
         $sd_so_line->destination_type = $document_type_i->destination_type;
        }
        ?>         
        <tr class="sd_so_line<?php echo $count ?>">
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
    <div id="tabsLine-5" class="scrollElement tabContent">
     <table class="form_line_data_table">
      <thead> 
       <tr><th>Seq#</th>
        <th>Invoiced Qty</th>
        <th>ar_transaction_header_id </th>
        <th>ar_transaction_line_id</th>
        <th>Invoice/CM # </th>
       </tr>
      </thead>
      <tbody class="form_data_line_tbody">
       <?php
       $count = 0;
       foreach ($sd_so_line_object as $sd_so_line) {
        $sd_so_line->ar_transaction_number = null;
        ?>         
        <tr class="sd_so_line<?php echo $count ?>">
         <td><?php $f->seq_field_d($count) ?></td>
         <td><?php form::number_field_wid2sr('invoiced_quantity'); ?></td>
         <td><?php form::text_field_wid2r('ar_transaction_header_id'); ?></td>
         <td><?php form::text_field_wid2r('ar_transaction_line_id'); ?></td>
         <td><?php form::text_field_wid2r('ar_transaction_number'); ?></td>
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
  <li class="headerClassName" data-headerClassName="sd_so_header" ></li>
  <li class="lineClassName" data-lineClassName="sd_so_line" ></li>
  <li class="savingOnlyHeader" data-savingOnlyHeader="false" ></li>
  <li class="primary_column_id" data-primary_column_id="sd_so_header_id" ></li>
  <li class="form_header_id" data-form_header_id="sd_so_header" ></li>
  <li class="line_key_field" data-line_key_field="item_description" ></li>
  <li class="single_line" data-single_line="false" ></li>
  <li class="form_line_id" data-form_line_id="sd_so_line" ></li>
 </ul>
 <ul id="js_contextMenu_data">
  <li class="docHedaderId" data-docHedaderId="sd_so_header_id" ></li>
  <li class="docLineId" data-docLineId="sd_so_line_id" ></li>
  <li class="btn1DivId" data-btn1DivId="sd_so_header" ></li>
  <li class="btn2DivId" data-btn2DivId="form_line" ></li>
  <li class="tbodyClass" data-tbodyClass="form_data_line_tbody" ></li>
  <li class="noOfTabbs" data-noOfTabbs="5" ></li>
 </ul>
</div>