<div id ="form_header"><span class="heading">Sales Quote Header</span>
 <form action=""  method="post" id="sd_quote_header"  name="sd_quote_header">
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
       <li><label><img src="<?php echo HOME_URL; ?>themes/images/serach.png" class="sd_quote_header_id select_popup">
         Header Id</label><?php echo $f->text_field_dr('sd_quote_header_id') ?>
        <a name="show" href="form.php?class_name=sd_quote_header&<?php echo "mode=$mode"; ?>" class="show document_id sd_quote_header_id"><img src="<?php echo HOME_URL; ?>themes/images/refresh.png"/></a> 
       </li>
       <li><label>Quote Number</label><?php echo $f->text_field_d('quote_number', 'primary_column2'); ?></li>
       <li><label>Opportunity Id</label><?php echo $f->text_field_dr('sd_opportunity_id'); ?>						 </li>
       <li><?php echo $f->hidden_field_withId('ar_customer_id', $$class->ar_customer_id); ?><label class="auto_complete"><img src="<?php echo HOME_URL; ?>themes/images/serach.png" class="ar_customer_id select_popup clickable">
         Customer Name</label><?php echo $f->text_field('customer_name', $$class->customer_name, '20', 'customer_name', 'select_customer_name', '', $readonly1); ?></li>
       <li><label class="auto_complete">Customer Number</label><?php $f->text_field_d('customer_number'); ?></li>
       <li><label>Customer Site</label><?php echo $f->select_field_from_object('ar_customer_site_id', $customer_site_obj, 'ar_customer_site_id', 'customer_site_name', $$class->ar_customer_site_id, 'ar_customer_site_id', 'ar_customer_site_id', '', $readonly1); ?> </li>
       <li><label>Status</label><span class="button"><?php echo!empty($$class->quote_status) ? $$class->quote_status : ""; ?></span></li>
       <li><label>Revision</label><?php echo form::checkBox_field('rev_enabled_cb', $$class->rev_enabled_cb, 'rev_enabled_cb', $readonly); ?></li> 
       <li><label>Rev Number</label><?php form::text_field_wid('rev_number'); ?> </li> 
       <li><label>Description</label><?php form::text_field_wid('description'); ?></li> 
      </ul>
     </div>
    </div>
    <div id="tabsHeader-2" class="tabContent">
     <div class="large_shadow_box"> 
      <ul class="column header_field">
       <li><label>Doc Currency</label><?php echo $f->select_field_from_object('doc_currency', option_header::currencies(), 'option_line_code', 'option_line_code', $$class->doc_currency, 'doc_currency', 'currency', 1, $readonly); ?>						 </li>
       <li><label>Payment Term</label><?php echo $f->select_field_from_object('payment_term_id', payment_term::find_all(), 'payment_term_id', 'payment_term', $$class->payment_term_id, '', 'payment_term_id', 1, $readonly1); ?>						 </li>
       <li><label><img src="<?php echo HOME_URL; ?>themes/images/serach.png" class="select_employee_name select_popup clickable">
         Sales Person</label><?php $f->text_field_d('sales_person_employee_name'); ?>
        <?php echo $f->hidden_field_withId('sales_person_employee_id', $$class->sales_person_employee_id); ?>
       </li>
       <li><label>Price List</label><?php echo$f->select_field_from_object('price_list_header_id', mdm_price_list_header::find_all(), 'mdm_price_list_header_id', 'price_list', $$class->price_list_header_id); ?>		 </li>
       <li><label>Exchange Rate Type</label><?php echo form::text_field_d('exchange_rate_type'); ?></li>
       <li><label>Exchange Rate</label><?php form::number_field_d('exchange_rate'); ?></li>
       <li><label>Header Amount</label><?php form::number_field_d('header_amount'); ?></li>
       <li><label>Tax Amount</label><?php form::number_field_d('tax_amount'); ?></li>
       <li><label>New Customer</label><?php $f->text_field_d('new_customer_name'); ?></li> 
       <li><label>New Customer Address</label><?php echo $f->text_area('new_customer_address', $$class->new_customer_address); ?></li> 
      </ul>
     </div>
    </div>
    <div id="tabsHeader-3" class="tabContent">
     <div class="left_half shipto address_details">
      <ul class="column four_column">
       <li><label><img src="<?php echo HOME_URL; ?>themes/images/serach.png" class="address_popup select_popup clickable">
         Ship To Site Id : </label><?php $f->text_field_d('ship_to_id', 'address_id site_address_id'); ?>
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
         Bill To Site Id :</label><?php $f->text_field_d('bill_to_id', 'address_id site_address_id'); ?>
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
       <li id="document_print"><label>Document Print : </label>
        <a class="button" target="_blank"
           href="<?php echo HOME_URL ?>modules/sd/quote/quote_print.php?sd_quote_header_id=<?php echo!(empty($$class->sd_quote_header_id)) ? $$class->sd_quote_header_id : ""; ?>" >Print Quote</a>
       </li>
       <li id="document_status"><label>Action: </label>
        <?php echo $f->select_field_from_array('action', sd_quote_header::$action_a, $$class->action, 'action'); ?>
       </li>
       <li><label>SO BU Name</label><?php echo $f->select_field_from_object('bu_org_id', org::find_all_business(), 'org_id', 'org', $$class->bu_org_id, 'bu_org_id', '', '', 1); ?>						 </li>
      </ul>
     </div>
    </div>
   </div>

  </div>
 </form>
</div>
<div id="form_line" class="form_line"><span class="heading">Quote Lines & Shipments </span>
 <form action=""  method="post" id="quote_site"  name="sd_quote_line">
  <div id="tabsLine">
   <ul class="tabMain">
    <li><a href="#tabsLine-1">Basic</a></li>
    <li><a href="#tabsLine-2">Price</a></li>
    <li><a href="#tabsLine-3">Dates</a></li>
    <li><a href="#tabsLine-4">References</a></li>
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
       foreach ($sd_quote_line_object as $sd_quote_line) {
        ?>         
        <tr class="sd_quote_line<?php echo $count ?>">
         <td>    
          <ul class="inline_action">
           <li class="add_row_img"><img  src="<?php echo HOME_URL; ?>themes/images/add.png"  alt="add new line" /></li>
           <li class="remove_row_img"><img src="<?php echo HOME_URL; ?>themes/images/remove.png" alt="remove this line" /> </li>
           <li><input type="checkbox" name="line_id_cb" value="<?php echo htmlentities($sd_quote_line->item_description); ?>"></li>           
           <li><?php echo form::hidden_field('sd_quote_header_id', $sd_quote_header->sd_quote_header_id); ?></li>
           <li><?php echo form::hidden_field('tax_code_value', $$class_second->tax_code_value); ?></li>
          </ul>
         </td>
         <td><?php $f->seq_field_d($count) ?></td>
         <td><?php form::text_field_wid2sr('sd_quote_line_id'); ?></td>
         <td><?php echo form::text_field('line_number', $$class_second->line_number, '8', '20', 1, 'Auto no', '', $readonly, 'lines_number'); ?></td>
         <td><?php echo $f->select_field_from_object('shipping_org_id', org::find_all_inventory(), 'org_id', 'org', $$class_second->shipping_org_id, '', 'medium', 1, $readonly); ?></td>
         <td><?php
          echo $f->hidden_field('item_id_m', $$class_second->item_id_m);
          form::text_field_wid2('item_number', 'select_item_number');
          ?>
          <img src="<?php echo HOME_URL; ?>themes/images/serach.png" class="select_item_number select_popup"></td>
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
        <th>Seq#</th>
        <th>Requested Date</th>
        <th>Promise Date </th>
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
       <tr><th>Seq#</th>
        <th>Ref Doc Type</th>
        <th>Ref Number</th>
        <th>Order Header Id </th>
        <th>Order Line Id </th>
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