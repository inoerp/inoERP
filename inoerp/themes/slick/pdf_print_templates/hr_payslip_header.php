<div id="page_print">
 <div id="print_header">
  <div class="half_page left logo">
   <div class="logo">
    <img src="<?php echo HOME_URL . $si->logo_path ?>" class="logo_image" /></div>
   <h2><?php echo $si->site_name; ?></h2> 
  </div>
  <div class="half_page right bu_details"><?php echo!(empty($$class->bu_org_id)) ? org::print_orgDetails_inLine($$class->bu_org_id) : ""; ?> </div>
 </div>
 <div id="print_body">
  <div class="full_page">
   <div class="half_page left header_info">
    <ul class="column header_field">
     <li><label><?php echo gettext('Requisition Number') ?> : </label><?php echo $$class->po_requisition_number; ?> </li>
     <li><label><?php echo gettext('Requisition Type') ?> : </label><?php echo $$class->po_requisition_type; ?> </li>
     <li><label><?php echo gettext('Supplier Name') ?> : </label><?php echo $$class->supplier_name; ?> </li>
     <li><label><?php echo gettext('Supplier Site') ?> : </label><?php echo $$class->supplier_site_name; ?> </li>
     <li><label><?php echo gettext('Status') ?> : </label><?php echo $$class->requisition_status; ?> </li>
     <li><label><?php echo gettext('Buyer') ?> : </label><?php echo $$class->buyer; ?> </li>
    </ul>
   </div>
   <div class="half_page right external_entiry_info">
    <ul class="column header_field">
     <li><label><?php echo gettext('Currency') ?> : </label><?php echo $$class->currency; ?> </li>
     <li><label><?php echo gettext('Header Amount') ?>: </label><?php echo $$class->header_amount; ?> </li>
     <li><label><?php echo gettext('Payment Term') ?> : </label><?php echo $$class->payment_term; ?> </li>
     <li><label></label><?php echo $$class->payment_term_description; ?> </li>
     <li><label><?php echo gettext('Rev Number') ?> : </label><?php echo $$class->rev_number; ?> </li>
     <li><label><?php echo gettext('Description') ?> : </label><?php echo $$class->description; ?> </li>
    </ul>
   </div>
  </div>
  <div class="full_page"></div>
  <div class="full_page">
    <!--<span class="heading"><?php //echo gettext('PO Lines & Shipments') ?> </span>-->
   <table class="form_line_data_table">
    <thead> 
     <tr class="line_header">
      <th><?php echo gettext('L-S') ?> #</th>
      <th><?php echo gettext('Type') ?></th>
      <th><?php echo gettext('Item Number') ?></th>
      <th><?php echo gettext('Description') ?></th>
      <th><?php echo gettext('Unit Price') ?></th>
      <th><?php echo gettext('Line Quantity') ?></th>
      <th><?php echo gettext('Ship To Inv') ?></th>
      <th><?php echo gettext('Line Description') ?></th>
      <th><?php echo gettext('Need By Date') ?></th>
     </tr>
    </thead>
    <tbody>
     <?php
     $count = 0;
     if(!empty($$line_obj)){
     foreach ($$line_obj as $req_line) {
      ?>
      <tr class="line_rows">
       <td><?php echo $req_line->po_requisition_line_number . '-' . $req_line->shipment_number; ?></td>
       <td><?php echo $req_line->line_type; ?></td>
       <td><?php echo $req_line->item_number; ?></td>
       <td><?php echo $req_line->item_description; ?></td>
       <td><?php echo $req_line->unit_price; ?></td>
       <td><?php echo $req_line->quantity; ?></td>
       <td><?php echo $req_line->ship_to_inventory; ?></td>
       <td><?php echo $req_line->line_description; ?></td>
       <td><?php echo $req_line->need_by_date; ?></td>
      </tr>
      <?php
      $count = $count + 1;
     }
     }
     ?>
    </tbody>
   </table>
  </div>
 </div>
</div>
