<?php
if ($$class->po_type != 'STANDARD') {
 return;
}
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
<div class="class_detail_form">
 <fieldset class="form_detail_data_fs">
  <div class="tabsDetail">
   <ul class="tabMain">
    <li class="tabLink"><a href="#tabsDetail-1-<?php echo $count ?>"><?php echo gettext('Basic') ?></a></li>
    <li class="tabLink"><a href="#tabsDetail-2-<?php echo $count ?>"><?php echo gettext('Delivery') ?></a></li>
    <li class="tabLink"><a href="#tabsDetail-3-<?php echo $count ?>"><?php echo gettext('Finance') ?></a></li>
    <li class="tabLink"><a href="#tabsDetail-4-<?php echo $count ?>"><?php echo gettext('Status & Quantities') ?></a></li>
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
          echo ino_inline_action($$class_third->po_detail_id, array('po_header_id' => $$class->po_header_id,
           'po_line_id' => $$class_second->po_line_id), 'add_row_detail_img', 'detail_id_cb');
          ?>
         </td>
         <td><?php $f->seq_field_detail_d($detailCount) ?></td>
         <td><?php form::text_field_wid3sr('po_detail_id'); ?></td>
         <td><?php echo $f->number_field('shipment_number', $$class_third->shipment_number, '', '', 'detail_number', 1); ?></td>
         <td><?php $f->text_field_wid3('ship_to_location_id'); ?></td>
         <td><?php echo $f->number_field('quantity', $$class_third->quantity, '', '', 'allow_change'); ?></td>
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
         <td>
          <?php echo $f->select_field_from_object('subinventory_id', subinventory::find_all_of_org_id($$class_second->receving_org_id), 'subinventory_id', 'subinventory', $$class_third->subinventory_id, '', 'subinventory_id copyValue medium', ''); ?>
         </td>
         <td>
          <?php echo $f->select_field_from_object('locator_id', locator::find_all_of_subinventory($$class_third->subinventory_id), 'locator_id', 'locator', $$class_third->locator_id, '', 'locator_id copyValue medium', ''); ?>
         </td>
         <td><?php $f->text_field_wid3('requestor' ,'medium'); ?></td>
         <td><?php echo $f->select_field_from_array('invoice_match_type', po_detail::$invoice_match_type_a, $$class_third->invoice_match_type , '' ,'medium'); ?></td>
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
     <table class="form form_detail_data_table detail">
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
