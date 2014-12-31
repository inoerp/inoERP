<div id ="form_header"><span class="heading">Delivery Header </span>
 <div id="tabsHeader">
  <ul class="tabMain">
   <li><a href="#tabsHeader-1">Basic Info</a></li>
   <li><a href="#tabsHeader-2">Attachments</a></li>
   <li><a href="#tabsHeader-3">Actions</a></li>
   <li><a href="#tabsHeader-4">Notes</a></li>
  </ul>
  <div class="tabContainer">
   <form action=""  method="post" id="sd_delivery_header"  name="sd_delivery_header">
    <div id="tabsHeader-1" class="tabContent">
     <div class="large_shadow_box"> 
      <ul class="column header_field">
       <li><label><img src="<?php echo HOME_URL; ?>themes/images/serach.png" class="sd_delivery_header_id select_popup clickable">
         Delivery Id</label><?php echo form::text_field_dsr('sd_delivery_header_id'); ?>
        <a name="show" href="form.php?class_name=sd_delivery_header&<?php echo "mode=$mode"; ?>" class="show document_id sd_delivery_header_id"><img src="<?php echo HOME_URL; ?>themes/images/refresh.png"/></a> 
       </li>
       <li><label>Inventory</label><?php echo $f->select_field_from_object('shipping_org_id', org::find_all_inventory(), 'org_id', 'org', $$class->shipping_org_id, '', '', 1, $readonly1); ?>       </li>
       <li><label>Number</label><?php echo $f->text_field('delivery_number', $$class->delivery_number, '8', '', '', '', $readonly1); ?></li>
       <li><label>Status</label><?php echo $f->select_field_from_array('status', sd_delivery_header::$status_a, $$class->status, '', '', 1, 1, 1) ?>       </li>
       <li><label>Date</label><?php echo $f->date_fieldFromToday_mr('delivery_date', ino_date($$class->delivery_date), $readonly); ?></li>
      </ul>
     </div>
    </div>
    <div id="tabsHeader-2" class="tabContent">
     <div> 
      <div id="show_attachment" class="show_attachment">
       <div id="file_upload_form">
        <ul class="inRow asperWidth">
         <li><input type="file" id="attachments" class="attachments" name="attachments[]" multiple/></li>
         <li> <input type="button" value="Attach" form="file_upload" name="attach_submit" id="attach_submit" class="submit button"></li>
         <li class="show_loading_small"><img alt="Loading..." src="<?php echo HOME_URL; ?>themes/images/small_loading.gif"/></li>
        </ul>
       </div>
       <div id="uploaded_file_details"></div>
       <?php echo file::attachment_statement($file); ?>
      </div>
     </div>
    </div>
    <div id="tabsHeader-3" class="tabContent">
     <div> 
      <ul class="column five_column">
       <li><label>Action</label>
        <?php
        $action_readonly = ($$class->status == 'SHIPPED') ? 1 : '';
        echo $f->select_field_from_array('action', sd_delivery_header::$action_a, '', 'action', '', '', $readonly, $action_readonly)
        ?>
       </li>
      </ul>
     </div>
    </div>
   </form>		
   <div id="tabsHeader-4" class="tabContent">
    <div> 
     <div id="comments">
      <div id="comment_list">
       <?php echo!(empty($comments)) ? $comments : ""; ?>
      </div>
      <?php
      $reference_table = 'sd_delivery_header';
      $reference_id = $$class->sd_delivery_header_id;
      include_once HOME_DIR . '/comment.php';
      ?>
      <div id="new_comment">
      </div>
     </div>
    </div>
   </div>
  </div>
 </div>

</div>
<div id="form_line" class="form_line"><span class="heading">Delivery Lines</span>
 <form action=""  method="post" id="po_site"  name="sd_delivery_line">
  <div id="tabsLine">
   <ul class="tabMain">
    <li><a href="#tabsLine-1">SO Info</a></li>
    <li><a href="#tabsLine-2">Delivery</a></li>
    <li><a href="#tabsLine-3">Customer</a></li>
    <li><a href="#tabsLine-4">Reference</a></li>
   </ul>
   <div class="tabContainer">
    <div id="tabsLine-1" class="tabContent">
     <table class="form_line_data_table">
      <thead> 
       <tr>
        <th>Action</th>
        <th>Delivery Line Id</th>
        <th>SO Id</th>
        <th>Line Id</th>
        <th>SO #</th>
        <th>SO Line #</th>
        <th>Shipment Qty</th>
        <th>Shipped Qty</th>
        <th>Delivery Status</th>
        <th>Line Action</th>
       </tr>
      </thead>
      <tbody class="form_data_line_tbody">
       <?php
       $count = 0;
       foreach ($sd_delivery_line_object as $sd_delivery_line) {
        $f->readonly2 = !empty($sd_delivery_line->sd_delivery_line_id) ? true : false;
        ?>         
        <tr class="sd_delivery_line<?php echo $count ?>">
         <td>    
          <ul class="inline_action">
           <li class="add_row_img"><img  src="<?php echo HOME_URL; ?>themes/images/add.png"  alt="add" /></li>
           <li class="remove_row_img"><img src="<?php echo HOME_URL; ?>themes/images/remove.png" alt="remove" /> </li>
           <li><input type="checkbox" name="line_id_cb" class="line_id_cb" value="<?php echo htmlentities($sd_delivery_line->sd_delivery_line_id); ?>"></li>           
           <?php echo form::hidden_field('sd_delivery_header_id', $$class->sd_delivery_header_id); ?>
           <?php echo form::hidden_field('shipping_org_id', $$class->shipping_org_id); ?>
           <?php echo form::hidden_field('transaction_type_id', $$class->transaction_type_id); ?>
          </ul>
         </td>
         <td><?php form::text_field_wid2sr('sd_delivery_line_id'); ?>
          <img src="<?php echo HOME_URL; ?>themes/images/serach.png" class="select_delivery_line select_popup clickable"></td>
         <td><?php $f->text_field_wid2sr('sd_so_header_id'); ?></td>
         <td><?php $f->text_field_wid2s('sd_so_line_id'); ?></td>
         <td><?php $f->text_field_wid2s('so_number', 'select_so_number'); ?></td>
         <td><?php $f->text_field_wid2sr('so_line_number'); ?></td>
         <td><?php echo $f->number_field('quantity', $sd_delivery_line->quantity, '8', '', '', '', 1); ?></td>
         <td><?php echo $f->number_field('shipped_quantity', $sd_delivery_line->shipped_quantity, '8', '', '', '', 1); ?></td>
         <td><?php $f->text_field_wid2r('delivery_status'); ?></td>
         <td><?php $f->text_field_wid2r('action'); ?></td>
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
        <th>Item id</th>
        <th>Item Number</th>
        <th>Item Description</th>
        <th>UOM</th>
        <th>Shipment Qty</th>
        <th>Sub inventory</th>
        <th>Locator</th>
       </tr>
      </thead>
      <tbody class="form_data_line_tbody">
       <?php
       $count = 0;
       foreach ($sd_delivery_line_object as $sd_delivery_line) {
        ?>         
        <tr class="sd_delivery_line<?php echo $count ?>">
         <td><?php $f->text_field_wid2sr('item_id_m'); ?></td>
         <td><?php $f->text_field_d2s('item_number'); ?></td>
         <td><?php $f->text_field_d2('item_description'); ?></td>
         <td><?php echo $f->select_field_from_object('line_uom_id', uom::find_all(), 'uom_id', 'uom_name', $sd_delivery_line->line_uom_id, '', '', '', $readonly1); ?></td>
         <td><?php echo $f->number_field('quantity', $$class_second->quantity, '8', '', '', 1, $readonly1); ?></td>
         <td><?php echo $f->select_field_from_object('staging_subinventory_id', subinventory::find_all_of_org_id($$class->shipping_org_id), 'subinventory_id', 'subinventory', $$class_second->staging_subinventory_id, '', 'subinventory_id', '', $readonly1); ?></td>
         <td><?php echo $f->select_field_from_object('staging_locator_id', locator::find_all_of_subinventory($$class_second->staging_subinventory_id), 'locator_id', 'locator', $$class_second->staging_locator_id, '', 'locator_id', '', $readonly1); ?></td>
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
        <th>Customer Id</th>
        <th>Customer #</th>
        <th>Customer</th>
        <th>Site Id</th>
        <th>Site #</th>
        <th>Site </th>
       </tr>
      </thead>
      <tbody class="form_data_line_tbody">
       <?php
       $count = 0;
       foreach ($sd_delivery_line_object as $sd_delivery_line) {
        ?>         
        <tr class="sd_delivery_line<?php echo $count ?>">
         <td><?php form::text_field_wid2r('ar_customer_id'); ?></td>
         <td><?php form::text_field_wid2r('ar_customer_number'); ?></td>
         <td><?php form::text_field_wid2r('ar_customer_name'); ?></td>
         <td><?php form::text_field_wid2r('ar_customer_site_id'); ?></td>
         <td><?php form::text_field_wid2r('ar_customer_site_number'); ?></td>
         <td><?php form::text_field_wid2r('ar_customer_site_name'); ?></td>
        </tr>
        <?php
        $count = $count + 1;
       }
       ?>
      </tbody>
      <!--                  Showing a blank form for new entry-->

     </table>
    </div>

    <div id="tabsLine-4" class="form_data_line_tbody">

    </div>
   </div>
  </div>
 </form>

</div>

<div id="js_data">
 <ul id="js_saving_data">
  <li class="headerClassName" data-headerClassName="sd_delivery_header" ></li>
  <li class="lineClassName" data-lineClassName="sd_delivery_line" ></li>
  <li class="savingOnlyHeader" data-savingOnlyHeader="false" ></li>
  <li class="primary_column_id" data-primary_column_id="sd_delivery_header_id" ></li>
  <li class="form_header_id" data-form_header_id="sd_delivery_header" ></li>
  <li class="line_key_field" data-line_key_field="sd_so_line_id" ></li>
  <li class="single_line" data-single_line="false" ></li>
  <li class="form_line_id" data-form_line_id="sd_delivery_line" ></li>
 </ul>
 <ul id="js_contextMenu_data">
  <li class="docHedaderId" data-docHedaderId="sd_delivery_header_id" ></li>
  <li class="docLineId" data-docLineId="sd_delivery_line_id" ></li>
  <li class="btn1DivId" data-btn1DivId="sd_delivery_header" ></li>
  <li class="btn2DivId" data-btn2DivId="form_line" ></li>
  <li class="tbodyClass" data-tbodyClass="form_data_line_tbody" ></li>
  <li class="noOfTabbs" data-noOfTabbs="4" ></li>
 </ul>
</div>