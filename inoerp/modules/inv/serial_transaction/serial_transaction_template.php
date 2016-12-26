<div id ="form_header">
 <span class="heading"><?php echo gettext('Serial Number Details') ?> </span>
 <div id="tabsHeader">
  <ul class="tabMain">
   <li><a href="#tabsHeader-1"><?php echo gettext('Basic Info') ?></a></li>
   <li><a href="#tabsHeader-2"><?php echo gettext('Serial Details') ?></a></li>
  </ul>
  <div class="tabContainer">
   <div id="tabsHeader-1" class="tabContent">
    <div class="large_shadow_box"> 
     <ul class="column header_field">
      <li><label><i class="inv_serial_transaction_header_id select_popup clickable fa fa-search "></i>
        <?php echo gettext('Serial Number Id') ?></label> <?php echo $f->text_field('inv_serial_number_id', $inv_serial_number_id_h, '', 'inv_serial_number_id') ?>
       <a name="show" href="form.php?class_name=inv_serial_transaction_v&<?php echo "mode=$mode"; ?>" class="show document_id inv_serial_transaction_id">
        <i class='fa fa-refresh'></i></a> 
      </li>
      <li><label><?php echo gettext('Serial Number') ?></label><?php echo $f->text_field('serial_number', $serial_number_h, '', 'serial_number') ?></li>
      <li><label><?php echo gettext('Generation') ?></label> <?php echo $f->text_field_dr('generation'); ?></li>
      <li><label><?php echo gettext('Origination') ?></label> <?php echo $f->text_field_dr('origination_type'); ?></li>
      <li><label><?php echo gettext('Origination Date') ?></label> <?php echo $f->text_field_dr('origination_date'); ?></li>
      <li><label><?php echo gettext('Activation Date') ?></label> <?php echo $f->text_field_dr('activation_date'); ?></li>
     </ul>
    </div>
   </div>
   <div id="tabsHeader-2" class="tabContent">
    <div class="large_shadow_box"> 
     <ul class="column five_column">
      <li><label><?php echo gettext('Current Org Id') ?> : </label> <?php echo $f->text_field_dr('current_org_id'); ?></li>
      <li><label><?php echo gettext('Current Subinventory Id') ?> : </label> <?php echo $f->text_field_dr('current_org_id'); ?></li>
      <li><label><?php echo gettext('Current Locator Id') ?> : </label> <?php echo $f->text_field_dr('current_org_id'); ?></li>
     </ul>
    </div>
   </div>
  </div>
 </div>

</div>

<div id ="form_line" class="form_line"><span class="heading"><?php echo gettext('Serial Transaction') ?> </span>
 <div id="tabsLine">
  <ul class="tabMain">
   <li><a href="#tabsLine-1"><?php echo gettext('Info-1') ?> </a></li>
   <li><a href="#tabsLine-2"><?php echo gettext('Info-2') ?> </a></li>
  </ul>
  <div class="tabContainer"> 
   <form method="post" id="inv_serial_transaction_entries_line"  name="inv_serial_transaction_entries_line">
    <div id="tabsLine-1" class="tabContent">
     <table class="form_table">
      <thead> 
       <tr>
        <th><?php echo gettext('Serial Number') ?></th>
        <th><?php echo gettext('Item Number') ?></th>
        <th><?php echo gettext('Item Description') ?></th>
        <th><?php echo gettext('Org Id') ?></th>
        <th><?php echo gettext('Transaction Type') ?></th>
        <th><?php echo gettext('From Subinventory') ?> </th>
        <th><?php echo gettext('From Locator') ?> </th>
        <th><?php echo gettext('Item Id M') ?> </th>
       </tr>
      </thead>
      <tbody class="form_data_line_tbody inv_serial_transaction_entries_values" >
       <?php
       $count = 0;
       $inv_serial_transaction_object_ai = new ArrayIterator($inv_serial_transaction_object);
       $inv_serial_transaction_object_ai->seek($position);
       while ($inv_serial_transaction_object_ai->valid()) {
        $inv_serial_transaction_v = $inv_serial_transaction_object_ai->current();
        ?>         
        <tr class="inv_serial_transaction_entries<?php echo $count ?>">
         <td><?php $f->text_field_widr('serial_number'); ?></td>
         <td><?php $f->text_field_widr('item_number'); ?></td>
         <td><?php $f->text_field_widr('item_description'); ?></td>
         <td><?php $f->text_field_widsr('org_id'); ?></td>
         <td><?php $f->text_field_widr('transaction_type'); ?></td>
         <td><?php $f->text_field_widr('from_subinventory'); ?></td>
         <td><?php $f->text_field_widr('from_locator'); ?></td>
         <td><?php $f->text_field_widr('item_id_m'); ?></td>
        </tr>
        <?php
        $inv_serial_transaction_object_ai->next();
        if ($inv_serial_transaction_object_ai->key() == $position + $per_page) {
         break;
        }
        $count = $count + 1;
       }
       ?>
      </tbody>
     </table>
    </div>
    <div id="tabsLine-2" class="tabContent">
     <table class="form_table">
      <thead> 
       <tr>
        <th><?php echo gettext('To Subinventory') ?> </th>
        <th><?php echo gettext('To Locator') ?> </th>
        <th><?php echo gettext('Transaction Id') ?></th>
        <th><?php echo gettext('Transaction Type Id') ?></th>
        <th><?php echo gettext('From Subinventory Id') ?></th>
        <th><?php echo gettext('From Locator Id') ?></th>
        <th><?php echo gettext('To Subinventory Id') ?></th>
        <th><?php echo gettext('To Locator Id') ?></th>
       </tr>
      </thead>
      <tbody class="form_data_line_tbody inv_serial_transaction_entries_values" >
       <?php
       $count = 0;
       $inv_serial_transaction_object_ai = new ArrayIterator($inv_serial_transaction_object);
       $inv_serial_transaction_object_ai->seek($position);
       while ($inv_serial_transaction_object_ai->valid()) {
        $inv_serial_transaction_v = $inv_serial_transaction_object_ai->current();
        ?>         
        <tr class="inv_serial_transaction_entries<?php echo $count ?>">
         <td><?php $f->text_field_widr('to_subinventory'); ?></td>
         <td><?php $f->text_field_widr('to_locator'); ?></td>
         <td><?php $f->text_field_widsr('inv_transaction_id'); ?></td>
         <td><?php $f->text_field_widsr('transaction_type_id'); ?></td>

         <td><?php $f->text_field_widr('from_subinventory_id'); ?></td>
         <td><?php $f->text_field_widr('from_locator_id'); ?></td>
         <td><?php $f->text_field_widr('to_subinventory_id'); ?></td>
         <td><?php $f->text_field_widr('to_locator_id'); ?></td>
        </tr>
        <?php
        $count = $count + 1;
        $inv_serial_transaction_object_ai->next();
        if ($inv_serial_transaction_object_ai->key() == $position + $per_page) {
         break;
        }
       }
       ?>
      </tbody>
     </table>
    </div>
   </form>
  </div>

 </div>
</div> 

<div id="pagination" style="clear: both;">
 <?php echo $pagination->show_pagination(); ?>
</div>

<div id="js_data">
 <ul id="js_contextMenu_data">
  <li class="docHedaderId" data-docHedaderId="inv_serial_transaction_id" ></li>
  <li class="btn1DivId" data-btn1DivId="inv_serial_transaction" ></li>
  <li class="btn2DivId" data-btn2DivId="form_line" ></li>
  <li class="tbodyClass" data-tbodyClass="form_data_line_tbody" ></li>
  <li class="noOfTabbs" data-noOfTabbs="3" ></li>
 </ul>
</div>
