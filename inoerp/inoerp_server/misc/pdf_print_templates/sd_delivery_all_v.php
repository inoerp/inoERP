<?php
$so_header_ids = [];
$deli_objs = [];
foreach ($$line_obj as $line_e) {
 if (!in_array($line_e->sd_so_header_id, $so_header_ids)) {
  array_push($so_header_ids, $line_e->sd_so_header_id);
  $deli_objs[$line_e->sd_so_header_id] = [];
  array_push($deli_objs[$line_e->sd_so_header_id], $line_e);
 } else {
  array_push($deli_objs[$line_e->sd_so_header_id], $line_e);
 }
}
$page_count = 0;
foreach ($deli_objs as $page_c => $deli_arr) {
 $$class = $deli_arr[0];
 $page_count++;
 if($page_count > 1){
  echo "<pagebreak />";
 }
 ?>
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
      <li><label><?php echo gettext('Delivery Number') ?> : </label><?php echo $$class->delivery_number; ?> </li>
      <li><label><?php echo gettext('Carrier') ?> : </label><?php echo $$class->carrier; ?> </li>
      <li><label><?php echo gettext('Vehicle Number') ?> : </label><?php echo $$class->vehicle_number; ?> </li>
      <li><label><?php echo gettext('Instruction') ?> : </label><?php echo $$class->handling_instruction; ?> </li>
      <li><label><?php echo gettext('Status') ?> : </label><?php echo $$class->delivery_status; ?> </li>
     </ul>
    </div>
    <div class="half_page right external_entiry_info">
     <ul class="column header_field">
      <li><label><?php echo gettext('Currency') ?> : </label><?php echo $$class->doc_currency; ?> </li>
      <li><label><?php echo gettext('Amount') ?>: </label><?php echo $$class->header_amount; ?> </li>
      <li><label><?php echo gettext('Customer Name') ?> : </label><?php echo $$class->customer_name; ?> </li>
      <li><label><?php echo gettext('Customer Site') ?></label><?php echo $$class->customer_site_name; ?> </li>
      <li><label><?php echo gettext('Customer Number') ?> : </label><?php echo $$class->customer_number; ?> </li>
      <li><label><?php echo gettext('Sales Order') ?> : </label><?php echo $$class->so_number; ?> </li>
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
     <!--<span class="heading">PO Lines & Shipments </span>-->
    <table class="form_line_data_table">
     <thead> 
      <tr class="line_header">
       <th><?php echo gettext('Line') ?> #</th>
       <th><?php echo gettext('Type') ?></th>
       <th><?php echo gettext('Item Number') ?></th>
       <th><?php echo gettext('Description') ?></th>
       <th><?php echo gettext('Unit Price') ?></th>
       <th><?php echo gettext('Shipped Quantity') ?></th>
       <th><?php echo gettext('Request Date') ?></th>
       <th><?php echo gettext('Promise Date') ?></th>
       <th><?php echo gettext('Line Description') ?></th>
       
      </tr>
     </thead>
     <tbody>
      <?php
      $count = 0;
      if (!empty($deli_arr)) {
       foreach ($deli_arr as $line_details) {
        ?>
        <tr class="line_rows">
         <td><?php echo $line_details->line_number ; ?></td>
         <td><?php echo $line_details->item_number; ?></td>
         <td><?php echo $line_details->item_description; ?></td>
         <td><?php echo $line_details->item_description; ?></td>
         <td><?php echo $line_details->unit_price; ?></td>
         <td><?php echo $line_details->delivery_shipped_quantity; ?></td>
         <td><?php echo $line_details->requested_date; ?></td>
         <td><?php echo $line_details->promise_date; ?></td>
         <td><?php echo $line_details->line_description; ?></td>
         
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

 <?php
// $mpdf->AddPage();
}
?>
