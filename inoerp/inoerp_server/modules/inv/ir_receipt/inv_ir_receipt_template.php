<div id="inv_ir_receipt_formid">

 <div id ="form_header"><span class="heading"><?php echo gettext('Internal Requisition Receipt') ?></span>
  <div id="tabsHeader">
   <ul class="tabMain">
    <li><a href="#tabsHeader-1"><?php echo gettext('Basic Info') ?></a></li>
    <li><a href="#tabsHeader-2"><?php echo gettext('Attachments') ?></a></li>
    <li><a href="#tabsHeader-3"><?php echo gettext('Notes') ?></a></li>
    <li><a href="#tabsHeader-4"><?php echo gettext('Actions') ?></a></li>
   </ul>
   <div class="tabContainer">
    <form action=""  method="post" id="inv_receipt_header"  name="inv_receipt_header">
     <div id="tabsHeader-1" class="tabContent">
      <ul class="column header_field">
       <li>
        <label><?php echo gettext('IR Receipt Id') ?></label>
        <?php
        $f->text_field_dr('inv_receipt_header_id');
        echo $f->hidden_field_withCLass('transaction_type_id', '33', 'popup_value');
        ?>
        <i class="generic g_select_receipt_header select_popup clickable fa fa-search" data-class_name="inv_receipt_header"></i>
        <a name="show" href="form.php?class_name=inv_ir_receipt_header&<?php echo "mode=$mode"; ?>" class="show document_id inv_receipt_header_id"><i class="fa fa-refresh"></i></a> 
       </li>
       <li><label><?php echo gettext('Inventory') ?></label><?php echo $f->select_field_from_object('org_id', org::find_all_inventory(), 'org_id', 'org', $$class->org_id, 'org_id', '', 1, $readonly1); ?>       </li>
       <li><?php echo $f->l_select_field_from_array('transaction_type_id', inv_ir_receipt_header::$transaction_type_id_a, $$class->transaction_type_id, 'transaction_type_id', '', 1, $readonly1); ?>       </li>
       <li><?php echo $f->l_number_field('receipt_number', $$class->receipt_number, '8', '', 'primary_column2', '', $readonly1); ?></li>
       <li><?php echo $f->l_date_fieldFromToday('receipt_date', ino_date($$class->receipt_date), $readonly1); ?></li>      
      </ul>
     </div>
     <div id="tabsHeader-2" class="tabContent">
      <div> <?php echo ino_attachement($file) ?> </div>
     </div>
     <div id="tabsHeader-3" class="tabContent">
      <div id="comments">
       <div id="comment_list">
        <?php echo!(empty($comments)) ? $comments : ""; ?>
       </div>
       <div id ="display_comment_form">
        <?php
        $reference_table = 'inv_receipt_header';
        $reference_id = $$class->inv_receipt_header_id;
        ?>
       </div>
      </div>
     </div>
     <div id="tabsHeader-4" class="tabContent">
      <div> 
       <ul class="column five_column">
        <li><label><?php echo gettext('Action') ?></label>
         <select name="transaction_action[]" class=" select  transaction_action" id="transaction_action" >
          <option value="" ></option>
          <option value="CREATE_ACCOUNT" ><?php echo gettext('Create Accounting') ?></option>
          <option value="ADD_LINES" ><?php echo gettext('Add Receipt Lines') ?></option>
          <option value="PRINT_TRAVELLER" ><?php echo gettext('Receipt Traveller') ?></option>
         </select>
        </li>
       </ul>
      </div>
     </div>
    </form>		

   </div>
  </div>

 </div>
 <div id="form_line" class="form_line"><span class="heading"><?php echo gettext('Internal Requisition Receipt Lines') ?></span>
  <form method="post" id="po_site"  name="inv_receipt_line">
   <div id="tabsLine">
    <ul class="tabMain">
     <li><a href="#tabsLine-1"><?php echo gettext('IR & ISO Details') ?></a></li>
     <li><a href="#tabsLine-2"><?php echo gettext('Receipt') ?> </a></li>
     <li><a href="#tabsLine-3"><?php echo gettext('Lot & Serial') ?> </a></li>
    </ul>
    <div class="tabContainer">
     <div id="tabsLine-1" class="tabContent">
      <table class="form_line_data_table">
       <thead> 
        <tr>
         <th><?php echo gettext('Action') ?></th>
         <th><?php echo gettext('Seq') ?>#</th>
         <th><?php echo gettext('Receipt Line Id') ?></th>
         <th><?php echo gettext('Line Number') ?></th>
         <th><?php echo gettext('ISO') ?> #</th>
         <th><?php echo gettext('ISO Line') ?> #</th>
         <th><?php echo gettext('Header Id') ?></th>
         <th><?php echo gettext('Line Id') ?></th>
         <th><?php echo gettext('IR') ?> #</th>
         <th><?php echo gettext('IR Line') ?> #</th>
         <th><?php echo gettext('Header Id') ?></th>
         <th><?php echo gettext('Line Id') ?></th>
         <th><?php echo gettext('Detail Id') ?></th>

<!--<th><?php echo gettext('Order Details') ?></th>-->
        </tr>
       </thead>
       <tbody class="form_data_line_tbody">
        <?php
        $count = 0;
        foreach ($inv_receipt_line_object as &$inv_receipt_line) {
         $f->readonly2 = !empty($inv_receipt_line->inv_receipt_line_id) ? true : false;
         if (!empty($inv_receipt_line->inv_receipt_line_id)) {
          $inv_ir_transfer_line_i = po_receive_requisition_v::find_by_po_requisitionDetailId($inv_receipt_line->po_requisition_detail_id);
          if (!empty($inv_ir_transfer_line_i)) {
           $inv_receipt_line->so_number = $inv_ir_transfer_line_i->so_number;
           $inv_receipt_line->so_line_number = $inv_ir_transfer_line_i->so_line_number;
           $inv_receipt_line->item_number = $inv_ir_transfer_line_i->item_number;
           
          } else {
           $inv_receipt_line->so_number = $inv_receipt_line->so_line_number = $inv_receipt_line->io_order_number = $inv_receipt_line->io_line_number = $inv_receipt_line->item_number = $inv_receipt_line->quantity = null;
          }
         } else {
          $inv_receipt_line->so_number = $inv_receipt_line->so_line_number = $inv_receipt_line->io_order_number = $inv_receipt_line->io_line_number = $inv_receipt_line->item_number = $inv_receipt_line->quantity = null;
         }
         ?>         
         <tr class="inv_receipt_line<?php echo $count ?>">
          <td>
           <?php
           echo ino_inline_action($$class_second->inv_receipt_line_id, array('org_id' => $$class->org_id,
            'transaction_type_id' => $$class->transaction_type_id, 'inv_receipt_header_id' => $$class->inv_receipt_header_id));
           ?>
          </td>
          <td><?php $f->seq_field_d($count) ?></td>
          <td><?php form::text_field_wid2sr('inv_receipt_line_id'); ?></td>
          <td><?php echo form::text_field('line_number', $$class_second->line_number, '8', '20', 1, 'Auto no', '', $readonly, 'lines_number'); ?></td>
          <td><?php
           $f->val_field_wid2m('so_number', 'po_receive_requisition_v', 'order_number', '', 'select');
//          echo $f->hidden_field_withCLass('so_status', 'SHIPPED', 'popup_value');
           echo $f->hidden_field_withCLass('receving_org_id', '', 'popup_value to_org_id org_id');
           ?><i class="generic select_io_order_number select_popup clickable fa fa-search" data-class_name="po_receive_requisition_v"></i></td>
          <td><?php $f->text_field_wid2sr('so_line_number' ,'always_readonly'); ?></td>
          <td><?php $f->text_field_wid2sr('sd_so_header_id', 'always_readonly'); ?></td>
          <td><?php $f->text_field_wid2sr('sd_so_line_id', 'always_readonly'); ?></td>
          <td><?php $f->text_field_wid2r('po_requisition_number','always_readonly'); ?></td>
          <td><?php $f->text_field_wid2r('req_line_number','always_readonly'); ?></td>
          <td><?php $f->text_field_wid2sr('po_requisition_header_id','always_readonly'); ?></td>
          <td><?php $f->text_field_wid2sr('po_requisition_line_id','always_readonly'); ?></td>
          <td><?php $f->text_field_wid2sr('po_requisition_detail_id','always_readonly'); ?></td>

              <!--<td><a target="_blank" href="form.php?class_name=inv_intorg_transfer_header&amp;inv_intorg_transfer_header_id=<?php // echo $$class_second->inv_intorg_transfer_header_id;      ?>&amp;mode=2">View Doc</a></td>-->
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
         <th><?php echo gettext('Item Id') ?></th>
         <th><?php echo gettext('Item Number') ?></th>
         <th><?php echo gettext('Revision') ?></th>
         <th><?php echo gettext('Item Description') ?></th>
         <th><?php echo gettext('Req Qty') ?></th>
         <th><?php echo gettext('ISO Qty') ?></th>
         <th><?php echo gettext('Shipped Qty') ?></th>
         <th><?php echo gettext('UOM') ?></th>
         <th><?php echo gettext('Line Qty') ?></th>
         <th><?php echo gettext('New Quantity') ?></th>
         <th><?php echo gettext('Subinventory') ?></th>
         <th><?php echo gettext('Locator') ?></th>
        </tr>
       </thead>
       <tbody class="form_data_line_tbody">
        <?php
        $count = 0;
        foreach ($inv_receipt_line_object as $inv_receipt_line) {
         if (!empty($inv_receipt_line->inv_receipt_line_id)) {
          $inv_ir_transfer_line_i = po_receive_requisition_v::find_by_po_requisitionDetailId($inv_receipt_line->po_requisition_detail_id);
          if (!empty($inv_ir_transfer_line_i)) {
           $inv_receipt_line->req_quantity = $inv_ir_transfer_line_i->req_quantity;
           $inv_receipt_line->iso_line_quantity = $inv_ir_transfer_line_i->iso_line_quantity;
           $inv_receipt_line->iso_shipped_quantity = $inv_ir_transfer_line_i->iso_shipped_quantity;
           $inv_receipt_line->quantity = $$class_second->transaction_quantity;
          } else {
           $inv_receipt_line->req_quantity = $inv_receipt_line->iso_line_quantity = $inv_receipt_line->iso_shipped_quantity = null;
          }
         } else {
          $inv_receipt_line->req_quantity = $inv_receipt_line->iso_line_quantity = $inv_receipt_line->iso_shipped_quantity = null;
         }
         ?>         
         <tr class="inv_receipt_line<?php echo $count ?>">
          <td><?php $f->seq_field_d($count) ?></td>
          <td><?php $f->text_field_wid2sr('item_id_m','always_readonly'); ?></td>
          <td><?php $f->text_field_d2('item_number', 'always_readonly'); ?></td>
          <td><?php $f->text_field_wid2sr('revision_name', 'always_readonly'); ?></td>
          <td><?php $f->text_field_d2('item_description', 'always_readonly'); ?></td>
          <td><?php $f->text_field_wid2sr('req_quantity', 'always_readonly'); ?></td>
          <td><?php $f->text_field_wid2sr('iso_line_quantity', 'always_readonly'); ?></td>
          <td><?php $f->text_field_wid2sr('iso_shipped_quantity' , 'always_readonly'); ?></td>
          <td><?php echo $f->select_field_from_object('uom_id', uom::find_all(), 'uom_id', 'uom_name', $inv_receipt_line->uom_id, '', '', '', $readonly1); ?></td>
          <td><?php
           echo $f->number_field('quantity', $inv_receipt_line->quantity, '12', '', 'medium', '', 1);
           echo $f->hidden_field('received_quantity', '');
           ?></td>
          <td><?php echo $f->number_field('transaction_quantity', $$class_second->transaction_quantity, '8', '', '', 1, $readonly1); ?></td>
          <td><?php echo $f->select_field_from_object('subinventory_id', subinventory::find_all_of_org_id($$class->org_id), 'subinventory_id', 'subinventory', $$class_second->subinventory_id, '', 'subinventory_id enable_update', 1, $readonly1); ?></td>
          <td><?php echo $f->select_field_from_object('locator_id', locator::find_all_of_subinventory($$class_second->subinventory_id), 'locator_id', 'locator', $$class_second->locator_id, '', 'locator_id enable_update', '', $readonly1); ?></td>
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
      <?php
      $ls_trclass = 'inv_receipt_line';
      $line_object_ls = $inv_receipt_line_object;
      $each_line_ls = $inv_receipt_line;
      $line_class_name_sl = &$class_second;
      $ref_key_name = 'inv_receipt_line';
      $ref_key_val = 'inv_receipt_line_id';
      include_once HOME_DIR . '/includes/template/lot_serial_template.inc'
      ?>
     </div>

    </div>
   </div>
  </form>

 </div>
</div>


<div id="js_data">
 <ul id="js_saving_data">
  <li class="headerClassName" data-headerClassName="inv_ir_receipt_header" ></li>
  <li class="lineClassName" data-lineClassName="inv_receipt_line" ></li>
  <li class="savingOnlyHeader" data-savingOnlyHeader="false" ></li>
  <li class="primary_column_id" data-primary_column_id="inv_receipt_header_id" ></li>
  <li class="form_header_id" data-form_header_id="inv_receipt_header" ></li>
  <li class="line_key_field" data-line_key_field="item_description" ></li>
  <li class="single_line" data-single_line="false" ></li>
  <li class="form_line_id" data-form_line_id="inv_receipt_line" ></li>
 </ul>
 <ul id="js_contextMenu_data">
  <li class="docHedaderId" data-docHedaderId="inv_receipt_header_id" ></li>
  <li class="docLineId" data-docLineId="inv_receipt_line_id" ></li>
  <li class="btn1DivId" data-btn1DivId="inv_receipt_header" ></li>
  <li class="btn2DivId" data-btn2DivId="form_line" ></li>
  <li class="tbodyClass" data-tbodyClass="form_data_line_tbody" ></li>
  <li class="noOfTabbs" data-noOfTabbs="3" ></li>
 </ul>
</div>
