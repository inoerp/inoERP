<div id="page_print">
  <div id="print_content">
 <div id="print_header">
  <div class="half_page left logo">
   <div class="logo">
    <img src="<?php echo HOME_URL . $si->logo_path ?>" class="logo_image" /></div>
   <h2><?php echo $si->site_name; ?> <?php echo gettext('Invoice') ?></h2> 
  </div>
  <div class="half_page right bu_details"><?php echo!(empty($$class->bu_org_id)) ? org::print_orgDetails_inLine($$class->bu_org_id) : ""; ?> </div>
 </div>
 <div id="print_body">
  <div class="full_page">
   <div class="half_page left header_info">
    <ul class="column header_field">
     <li><label><?php echo gettext('Transaction Number') ?> : </label><?php echo $$class->transaction_number; ?> </li>
     <li><label><?php echo gettext('Type') ?> : </label><?php echo $$class->transaction_class; ?> </li>
     <li><label><?php echo gettext('Description') ?> : </label><?php echo $$class->description; ?> </li>
     <li><label><?php echo gettext('Currency') ?> : </label><?php echo $$class->doc_currency; ?> </li>
     <li><label><?php echo gettext('Header Amount') ?> : </label><?php echo $$class->header_amount; ?> </li>
     <li><label><?php echo gettext('Tax Amount') ?> : </label><?php echo $$class->tax_amount; ?> </li>
    </ul>
   </div>
   <div class="half_page right external_entiry_info">
    <ul class="column header_field">
     <li><label><?php echo gettext('Customer') ?> : </label><?php echo $$class->customer_name; ?> </li>
     <li><label><?php echo gettext('Customer Number') ?>: </label><?php echo $$class->customer_number; ?> </li>
     <li><label><?php echo gettext('Site Name') ?> : </label><?php echo $$class->customer_site_name; ?> </li>
     <li><label><?php echo gettext('Site Number') ?></label><?php echo $$class->customer_site_number; ?> </li>
     <li><label><?php echo gettext('Payment Term') ?> : </label><?php echo $$class->payment_term; ?> </li>
     <li><?php echo $$class->payment_term_description; ?> </li>
    </ul>
   </div>
  </div>
  <div class="full_page">
   <div class="half_page left header_info"><span class="heading"><?php echo gettext('Shipping Address') ?></span>
    <ul class="column header_field">
     <li><label><?php echo gettext('Address') ?> : </label><?php echo $$class->address; ?> </li>
     <li><label><?php echo gettext('Country') ?>: </label><?php echo $$class->country; ?> </li>
     <li><label><?php echo gettext('Postal Code') ?> : </label><?php echo $$class->postal_code; ?> </li>
     <li><label><?php echo gettext('Phone') ?></label><?php echo $$class->phone; ?> </li>
     <li><label><?php echo gettext('Email') ?> : </label><?php echo $$class->email; ?> </li>
     <li><label><?php echo gettext('Website') ?> : </label><?php echo $$class->website; ?> </li>
    </ul>
   </div>
   <div class="half_page right external_entiry_info"><span class="heading"><?php echo gettext('Billing Address') ?></span>
    <ul class="column header_field">
     <li><label><?php echo gettext('Address') ?> : </label><?php echo $$class->address_b; ?> </li>
     <li><label><?php echo gettext('Country') ?>: </label><?php echo $$class->country_b; ?> </li>
     <li><label><?php echo gettext('Postal Code') ?> : </label><?php echo $$class->postal_code_b; ?> </li>
     <li><label><?php echo gettext('Phone') ?></label><?php echo $$class->phone_b; ?> </li>
     <li><label><?php echo gettext('Email') ?> : </label><?php echo $$class->email_b; ?> </li>
     <li><label><?php echo gettext('Website') ?> : </label><?php echo $$class->website_b; ?> </li>
    </ul>
   </div>
  </div>
  <div class="full_page"></div>
  <div class="full_page">
    <!--<span class="heading"><?php //echo gettext('PO Lines & Shipments') ?> </span>-->
   <table class="form_line_data_table">
    <thead> 
     <tr class="line_header">
      <th><?php echo gettext('Line') ?> #</th>
      <th><?php echo gettext('Item Number') ?></th>
      <th><?php echo gettext('Description') ?></th>
      <th><?php echo gettext('Unit Price') ?></th>
      <th><?php echo gettext('Line Quantity') ?></th>
      <th><?php echo gettext('Line Price') ?></th>
      <th><?php echo gettext('Line Description') ?></th>
      <th><?php echo gettext('SO') ?> #</th>
      <th><?php echo gettext('SO Line') ?>#</th>
     </tr>
    </thead>
    <tbody>
     <?php
     $count = 0;
     if (!empty($$line_obj)) {
      foreach ($$line_obj as $req_line) {
       ?>
       <tr class="line_rows">
        <td><?php echo $req_line->line_number; ?></td>
         <td><?php echo $req_line->item_number; ?></td>
        <td><?php echo $req_line->item_description; ?></td>
        <td><?php echo $req_line->inv_unit_price; ?></td>
        <td><?php echo $req_line->inv_line_quantity; ?></td>
        <td><?php echo $req_line->inv_line_price; ?></td>
        <td><?php echo $req_line->line_description; ?></td>
        <td><?php echo !empty($req_line->so_number) ? $req_line->so_number : ''; ?></td>
        <td><?php echo $req_line->so_line_number; ?></td>
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
 </div>
