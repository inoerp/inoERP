<div id ="form_header"><span class="heading"><?php  echo gettext('Purchasing Transaction - Receipt/Return')  ?> </span>

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
      <li><?php $f->l_text_field_dr_withSearch('inv_receipt_header_id') ?>
       <a name="show" href="form.php?class_name=inv_receipt_header&<?php echo "mode=$mode"; ?>" class="show document_id inv_receipt_header_id"><i class="fa fa-refresh"></i></a> 
      </li>
      <li><label><?php echo gettext('Inventory') ?></label><?php echo $f->select_field_from_object('org_id', org::find_all_inventory(), 'org_id', 'org', $$class->org_id, 'org_id', '', 1, $readonly1); ?>       </li>
      <li><?php $f->l_select_field_from_array('transaction_type_id', inv_receipt_header::$transaction_type_id_a, $$class->transaction_type_id, 'transaction_type_id', '', 1, $readonly1); ?>       </li>
      <li><?php echo $f->l_text_field_d('receipt_number'); ?>
      </li><li><?php echo $f->l_date_fieldFromToday('receipt_date', ino_date($$class->receipt_date), $readonly1); ?></li>      
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
       <li><?php echo $f->l_select_field_from_array('action', $$class->action_a, '', 'action') ?></li>
      </ul>
     </div>
    </div>
   </form>		

  </div>
 </div>

</div>
<div id="form_line" class="form_line"><span class="heading"><?php echo gettext('Receipt Lines') ?></span>
 <form method="post" id="inv_receipt_line"  name="inv_receipt_line">
  <div id="tabsLine">
   <ul class="tabMain">
    <li><a href="#tabsLine-1"><?php echo gettext('PO Info') ?></a></li>
    <li><a href="#tabsLine-2"><?php echo gettext('Receipt') ?> </a></li>
    <li><a href="#tabsLine-3"><?php echo gettext('Lot & Serial') ?> </a></li>
    <li><a href="#tabsLine-4"><?php echo gettext('Supplier') ?></a></li>
    <li><a href="#tabsLine-5"><?php echo gettext('Finance') ?></a></li>

   </ul>
   <div class="tabContainer">
    <div id="tabsLine-1" class="tabContent">
     <table class="form_line_data_table">
      <thead> 
       <tr>
        <th><?php echo gettext('Action') ?></th>
        <th><?php echo gettext('Seq') ?>#</th>
        <th><?php echo gettext('Line Id') ?></th>
        <th><?php echo gettext('Line #') ?></th>
        <th><?php echo gettext('Header Id') ?></th>
        <th><?php echo gettext('PO #') ?></th>
        <th><?php echo gettext('PO Line #') ?></th>
        <th><?php echo gettext('PO Line Id') ?></th>
        <th><?php echo gettext('Shipment #') ?></th>
        <th><?php echo gettext('Detail Id') ?></th>
        <th><?php echo gettext('Shipment Qty') ?></th>
        <th><?php echo gettext('Received Qty') ?></th>
       </tr>
      </thead>
      <tbody class="form_data_line_tbody">
       <?php
       $count = 0;
       foreach ($inv_receipt_line_object as $inv_receipt_line) {
        $f->readonly2 = !empty($inv_receipt_line->inv_receipt_line_id) ? true : false;
        ?>         
        <tr class="inv_receipt_line<?php echo $count ?>">
         <td>
          <?php
          echo ino_inline_action($$class_second->inv_receipt_line_id, array('org_id' => $$class->org_id,
           'inv_receipt_header_id' => $$class->inv_receipt_header_id, 'transaction_type_id' => $$class->transaction_type_id));
          ?>
         </td>
         <td><?php $f->seq_field_d($count) ?></td>
         <td><?php form::text_field_wid2sr('inv_receipt_line_id'); ?></td>
         <td><?php echo form::text_field('line_number', $$class_second->line_number, '8', '20', 1, 'Auto no', '', $readonly, 'lines_number'); ?></td>
         <td><?php $f->text_field_wid2sr('po_header_id'); ?></td>
         <td><?php 
          $f->val_field_wid2m('po_number', 'po_all_v', 'po_number', '', $readonly1_class . ' enable_update');
          echo $f->hidden_field_withCLass('po_status', 'approved', 'popup_value');
          echo $f->hidden_field_withCLass('receving_org_id', '', 'popup_value receving_org_id org_id');
          ?><i class="generic select_po_number select_popup clickable fa fa-search enable_update <?php echo $readonly1_class ?>" data-class_name="po_all_v"></i></td>
         <td><?php $f->text_field_wid2sr('po_line_number', 'medium'); ?></td>
         <td><?php $f->text_field_wid2s('po_line_id'); ?></td>
         <td><?php $f->text_field_wid2sr('shipment_number', 'medium'); ?></td>
         <td><?php $f->text_field_wid2s('po_detail_id'); ?></td>
         <td><?php echo $f->number_field('quantity', $inv_receipt_line->quantity, '8', '', 'medium', '', 1); ?></td>
         <td><?php echo $f->number_field('received_quantity', $inv_receipt_line->received_quantity, '8', '', 'medium', '', 1); ?></td>
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
        <th><?php echo gettext('UOM') ?></th>
        <th><?php echo gettext('Kit Item') ?></th>
        <th><?php echo gettext('New Received Qty') ?></th>
        <th><?php echo gettext('Subinventory') ?></th>
        <th><?php echo gettext('Locator') ?></th>
        <th><?php echo gettext('Kit Config') ?></th>
        <th><?php echo gettext('Quality Details') ?></th>
       </tr>
      </thead>
      <tbody class="form_data_line_tbody">
       <?php
       $count = 0;
       foreach ($inv_receipt_line_object as $inv_receipt_line) {
        $qa_cp_header_id_stmt = null;
        if (!empty($$class->inv_receipt_header_id) && ($$class->transaction_type_id == 4)) {
         $qa_cp_header_ids_a = [];
         $item_categories = item::find_itemCategory_byItemIdm_and_orgId($$class_second->item_id_m, $$class->org_id);
         if ($item_categories) {
          foreach ($item_categories as $item_category) {
           $cp_al = new qa_cp_assignment_line();
           $cp_al->category = $item_category->category;
           $qa_cp_header_ids = $cp_al->findAssignments_byTrigger();
           if ($qa_cp_header_ids) {
            foreach ($qa_cp_header_ids as $obj_k => $obj_v) {
             if (!in_array($obj_v, $qa_cp_header_ids_a)) {
              array_push($qa_cp_header_ids_a, $obj_v);
             }
            }
           }
          }
         }
         if (!empty($qa_cp_header_ids_a)) {
          foreach ($qa_cp_header_ids_a as $k => $v) {
           $qa_cp_header_id_stmt .= '&qa_cp_header_ids[]=' . $v;
          }
         }
        }
        $qa_link = 'form.php?class_name=qa_quality_result&reference_key_name=inv_receipt_line_id&mode=9&window_type=popup&reference_key_value=' .
         $$class_second->inv_receipt_line_id . $qa_cp_header_id_stmt;
        ?>         
        <tr class="inv_receipt_line<?php echo $count ?>">
         <td><?php $f->seq_field_d($count) ?></td>
         <td><?php $f->text_field_wid2sr('item_id_m'); ?></td>
         <td><?php $f->text_field_d2('item_number', 'select_item_number'); ?></td>
         <td><?php $f->text_field_wid2sr('revision_name'); ?></td>
         <td><?php $f->text_field_d2('item_description'); ?></td>
         <td><?php echo $f->select_field_from_object('uom_id', uom::find_all(), 'uom_id', 'uom_name', $inv_receipt_line->uom_id, '', '', '', $readonly1); ?></td>
         <td><?php echo $f->checkBox_field('kit_cb', $$class_second->kit_cb, '', 'dontCopy'); ?></td>
         <td><?php echo $f->number_field('transaction_quantity', $$class_second->transaction_quantity, '8', '', '', 1, $readonly1); ?></td>
         <td><?php echo $f->select_field_from_object('subinventory_id', subinventory::find_all_of_org_id($$class->org_id), 'subinventory_id', 'subinventory', $$class_second->subinventory_id, '', 'subinventory_id', 1, $readonly); ?></td>
         <td><?php echo $f->select_field_from_object('locator_id', locator::find_all_of_subinventory($$class_second->subinventory_id), 'locator_id', 'locator', $$class_second->locator_id, '', 'locator_id', '', $readonly); ?></td>
         <td><a class="popup popup-form view-item-config medium" href="form.php?class_name=bom_config_header&mode=9&window_type=popup"> <i class="fa fa-edit"></i></a></td>
         <td><a class="popup popup-form view-quality-form medium" href="<?php echo $qa_link ?>"><i class="fa fa-edit"></i></a></td>
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

    <div id="tabsLine-4" class="tabContent">
     <table class="form_line_data_table">
      <thead> 
       <tr>
        <th><?php echo gettext('Seq') ?>#</th>
        <th><?php echo gettext('Supplier Id') ?></th>
        <th><?php echo gettext('Supplier #') ?></th>
        <th><?php echo gettext('Supplier') ?></th>
        <th><?php echo gettext('Site Id') ?></th>
        <th><?php echo gettext('Site #') ?></th>
        <th><?php echo gettext('Site') ?></th>
       </tr>
      </thead>
      <tbody class="form_data_line_tbody">
       <?php
       $count = 0;
       foreach ($inv_receipt_line_object as $inv_receipt_line) {
        ?>         
        <tr class="inv_receipt_line<?php echo $count ?>">
         <td><?php $f->seq_field_d($count) ?></td>
         <td><?php form::text_field_wid2r('supplier_id'); ?></td>
         <td><?php form::text_field_wid2r('supplier_number'); ?></td>
         <td><?php form::text_field_wid2r('supplier_name'); ?></td>
         <td><?php form::text_field_wid2r('supplier_site_id'); ?></td>
         <td><?php form::text_field_wid2r('supplier_site_number'); ?></td>
         <td><?php form::text_field_wid2r('supplier_site_name'); ?></td>
        </tr>
        <?php
        $count = $count + 1;
       }
       ?>
      </tbody>
      <!--                  Showing a blank form for new entry-->

     </table>
    </div>

    <div id="tabsLine-5" class="form_data_line_tbody">
     <table class="form_line_data_table">
      <thead> 
       <tr>
        <th><?php echo gettext('Seq') ?>#</th>
        <th><?php echo gettext('Currency') ?></th>
        <th><?php echo gettext('Document Currency') ?></th>
        <th><?php echo gettext('Exchange Rate Type') ?></th>
        <th><?php echo gettext('Exchange Rate') ?></th>
       </tr>
      </thead>
      <tbody class="form_data_line_tbody">
       <?php
       $count = 0;
       foreach ($inv_receipt_line_object as $inv_receipt_line) {
        ?>         
        <tr class="inv_receipt_line<?php echo $count ?>">
         <td><?php $f->seq_field_d($count) ?></td>
         <td><?php form::text_field_wid2r('currency'); ?></td>
         <td><?php form::text_field_wid2r('doc_currency'); ?></td>
         <td><?php form::text_field_wid2r('exchange_rate_type'); ?></td>
         <td><?php form::text_field_wid2r('exchange_rate'); ?></td>
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
  <li class="headerClassName" data-headerClassName="inv_receipt_header" ></li>
  <li class="lineClassName" data-lineClassName="inv_receipt_line" ></li>
  <li class="savingOnlyHeader" data-savingOnlyHeader="false" ></li>
  <li class="primary_column_id" data-primary_column_id="inv_receipt_header_id" ></li>
  <li class="form_header_id" data-form_header_id="inv_receipt_header" ></li>
  <li class="line_key_field" data-line_key_field="item_description" ></li>
  <li class="single_line" data-single_line="false" ></li>
  <li class="form_line_id" data-form_line_id="inv_receipt_line" ></li>
  <li class="before_save_function" data-before_save_function="beforeSave" ></li>
 </ul>
 <ul id="js_contextMenu_data">
  <li class="docHedaderId" data-docHedaderId="inv_receipt_header_id" ></li>
  <li class="docLineId" data-docLineId="inv_receipt_line_id" ></li>
  <li class="btn1DivId" data-btn1DivId="inv_receipt_header" ></li>
  <li class="btn2DivId" data-btn2DivId="form_line" ></li>
  <li class="tbodyClass" data-tbodyClass="form_data_line_tbody" ></li>
  <li class="noOfTabbs" data-noOfTabbs="5" ></li>
 </ul>
</div>
