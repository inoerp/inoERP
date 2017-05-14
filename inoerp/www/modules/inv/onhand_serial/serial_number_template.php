      <div id ="form_line" class="form_line">
       <div id="tabsDetail">
        <ul class="tabMain">
         <li><a href="#tabsDetail-1"><?php echo gettext('Info-1') ?> </a></li>
         <li><a href="#tabsDetail-2"><?php echo gettext('Info-2') ?> </a></li>
        </ul>
        <div class="tabContainer"> 
         <form method="post" id="inv_serial_transaction_entries_line"  name="inv_serial_transaction_entries_line">
          <div id="tabsDetail-1" class="tabContent">
           <table class="form_table">
            <thead> 
             <tr>
              <th><?php echo gettext('Serial Number') ?></th>
              <th><?php echo gettext('Origination Type') ?></th>
              <th><?php echo gettext('Origination Date') ?></th>
              <th><?php echo gettext('Activation Date') ?> </th>
              <th><?php echo gettext('Current Inventory') ?></th>
              <th><?php echo gettext('Subinventory') ?></th>
              <th><?php echo gettext('Locator') ?></th>
              <th><?php echo gettext('Inventory L/N') ?> </th>
              <th><?php echo gettext('COO') ?></th>
             </tr>
            </thead>
            <tbody class="form_data_line_tbody inv_serial_transaction_entries_values" >
             <?php
              $count = 0;
              foreach ($inv_onhand_serial_object as $inv_onhand_serial) {
                ?>         
               <tr class="inv_serial_transaction_entries<?php echo $count ?>">
                <td><?php $f->text_field_widr('serial_number'); ?></td>
                <td><?php echo $f->select_field_from_array('origination_type', inv_serial_number::$origination_type_a, $$class->origination_type, 'origination_type', '', 1, 1, 1); ?>             </td>
                <td><?php echo $f->date_fieldAnyDay_r('origination_date', $$class->origination_date, 1); ?> </td>
                <td><?php echo $f->date_fieldAnyDay_r('activation_date', $$class->activation_date, 1); ?> </td>
                <td><?php echo $f->select_field_from_object('current_org_id', org::find_all_inventory(), 'org_id', 'org', $$class->current_org_id, 'current_org_id', '', '', 1); ?></td>
                <td><?php echo $f->select_field_from_object('current_subinventory_id', subinventory::find_all_of_org_id($$class->current_org_id), 'subinventory_id', 'subinventory', $$class->current_subinventory_id, 'current_subinventory_id', 'subinventory_id', '', 1); ?>			</td>
                <td><?php echo $f->select_field_from_object('current_locator_id', locator::find_all_of_subinventory($$class->current_subinventory_id), 'locator_id', 'locator', $$class->current_locator_id, '', 'locator_id', '', 1); ?></td>
                <td><?php $f->text_field_d('inv_lot_number_id'); ?>             </td>
                <td><?php $f->text_field_d('country_of_origin'); ?>             </td>
               </tr>
               <?php
               $count = $count + 1;
              }
             ?>
            </tbody>
           </table>
          </div>
          <div id="tabsDetail-2" class="tabContent">
           <table class="form_table">
            <thead> 
             <tr>
              <th><?php echo gettext('Supplier Site Id') ?> </th>
              <th><?php echo gettext('PO Header Id') ?> </th>
              <th><?php echo gettext('Supplier S/N') ?> </th>
              <th><?php echo gettext('Supplier L/N') ?></th>
              <th><?php echo gettext('First Trnx Id') ?></th>
              <th><?php echo gettext('Last Trnx Id') ?></th>
              <th><?php echo gettext('Customer Site Id') ?></th>
              <th><?php echo gettext('Serial Details') ?></th>
             </tr>
            </thead>
            <tbody class="form_data_line_tbody inv_serial_transaction_entries_values" >
             <?php
              $count = 0;
              foreach ($inv_onhand_serial_object as $inv_onhand_serial) {
               $class_second = 'inv_serial_transaction_v';
               ?>         
               <tr class="inv_serial_transaction_entries<?php echo $count ?>">
                <td> <?php $f->text_field_dr('supplier_site_id'); ?>             </td>
                <td> <?php $f->text_field_dr('po_header_id'); ?>             </td>
                <td><?php $f->text_field_dr('supplier_sn'); ?>             </td>
                <td><?php $f->text_field_dr('supplier_ln'); ?>             </td>
                <td><?php $f->text_field_dr('first_inv_transaction_id'); ?>             </td>
                <td><?php $f->text_field_dr('last_inv_transaction_id'); ?>             </td>
                <td><?php $f->text_field_dr('ar_customer_site_id'); ?>             </td>
                <td><a class="button" href="form.php?class_name=inv_serial_number&mode=9&inv_serial_number_id=<?php echo $$class->inv_serial_number_id; ?>"><?php echo gettext('View') ?></a></td>
               </tr>
               <?php
               $count = $count + 1;
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
       <?php echo!(empty($pagination_statement)) ? $pagination_statement : "";
       ?>
      </div>
<div id="js_data">
 <ul id="js_saving_data">
  <li class="headerClassName" data-headerClassName="inv_serial_number" ></li>
  <li class="savingOnlyHeader" data-savingOnlyHeader="true" ></li>
  <li class="primary_column_id" data-primary_column_id="inv_serial_number_id" ></li>
  <li class="form_header_id" data-form_header_id="inv_serial_number" ></li>
 </ul>
 <ul id="js_contextMenu_data">
  <li class="docHedaderId" data-docHedaderId="inv_serial_number_id" ></li>
  <li class="btn1DivId" data-btn1DivId="inv_serial_number_id" ></li>
 </ul>
</div>
