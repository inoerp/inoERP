<?php include_once __DIR__ . DS . 'inv_reservation_ma.inc'; ?>
<ul id="js_files" class="none">
 <li class="hidden">modules/inv/reservation/multi_action/ma_reservation.js</li>
</ul>
<div id="inv_reservation_divId">
 <div class="row" id="multi_select">
  <div id="searchForm" ><div class='hideDiv_input fa fa-minus-circle clickable'></div>
   <div class='hideDiv_input_element'><?php echo!(empty($search_form)) ? $search_form : ""; ?></div></div>
  <div id ="searchResult">
   <form  method="post" id="inv_reservation"  name="inv_reservation">
    <div id ="form_line" class="form_line"><span class="heading"><?php echo gettext('On Hand Reservation') ?></span>
     <div id="tabsLine">
      <ul class="tabMain">
       <li><a href="#tabsLine-1"><?php echo gettext('Basics') ?></a></li>
       <li><a href="#tabsLine-2"><?php echo gettext('Demand') ?></a></li>
       <li><a href="#tabsLine-3"><?php echo gettext('Supply') ?></a></li>
      </ul>
      <div class="tabContainer">
       <div id="tabsLine-1" class="tabContent">
        <table class="form_table">
         <thead> 
          <tr>
           <th><?php echo gettext('Action') ?></th>
           <th><?php echo gettext('Seq') ?> #</th>
           <th><?php echo gettext('Reservation Id') ?></th>
           <th><?php echo gettext('Org') ?></th>
           <th><?php echo gettext('Item Number') ?></th>
           <th><?php echo gettext('Description') ?></th>
           <th><?php echo gettext('UOM') ?></th>
           <th><?php echo gettext('Date') ?></th>
           <th><?php echo gettext('Demand Qty') ?></th>
           <th><?php echo gettext('Reason') ?></th>
          </tr>
         </thead>
         <tbody class="form_data_line_tbody">
          <?php
          $count = 0;
          if (!empty($search_result)) {
           foreach ($search_result as $inv_reservation) {
            if (!empty($$class->item_id_m)) {
             $item_i = item::find_by_item_id_m($$class->item_id_m);
             $$class->item_number = $item_i->item_number;
             $$class->item_description = $item_i->item_description;
            }
            ?>         
            <tr class="inv_reservation_line<?php echo $count ?>">
             <td>    
              <ul class="inline_action">
               <li class="add_row_img"><i class="fa fa-plus-circle"></i></li>
               <li class="remove_row_img"><i class="fa fa-minus-circle"></i></li>
               <li><input type="checkbox" name="line_id_cb" value="<?php echo ($inv_reservation->inv_reservation_id); ?>"></li>           
              </ul>
             </td>
             <td><?php $f->seq_field_d($count); ?></td>
             <td><?php $f->text_field_dr('inv_reservation_id', 'always_readonly'); ?></td>
             <td><?php echo $f->select_field_from_object('org_id', org::find_all_inventory(), 'org_id', 'org', $$class->org_id, '', 'org_id_primary'); ?>       </td>
             <td><?php
              $f->val_field_wid('item_number', 'item', 'item_number', 'org_id');
              echo $f->hidden_field_withCLass('item_id_m', $$class->item_id_m, 'dontCopy');
              echo $f->hidden_field_withCLass('reservable_cb', '1', 'popup_value');
              ?></td>
             <td><?php $f->text_field_wid('item_description'); ?></td>
             <td><?php echo $f->select_field_from_object('uom_id', uom::find_all(), 'uom_id', 'uom_name', $$class->uom_id, '', 'always_readonly'); ?>         </td>
             <td><?php echo $f->date_fieldFromToday_m('need_by_date', $$class->need_by_date, 1) ?></td>
             <td><?php echo $f->number_field('demand_quantity', $$class->demand_quantity, '', '', 'demand_quantity'); ?></td>
             <td><?php $f->text_field_wid('reason'); ?></td>            </tr>
            <?php
            $count = $count + 1;
           }
          }
          ?>
         </tbody>
        </table>
       </div>
       <div id="tabsLine-2" class="tabContent">
        <table class="form_table">
         <thead> 
          <tr>
           <th><?php echo gettext('Seq') ?> #</th>
           <th><?php echo gettext('Demand Type') ?></th>
           <th><?php echo gettext('SO') ?> #</th>
           <th><?php echo gettext('SO Line') ?> #</th>
           <th><?php echo gettext('Demand Comment') ?></th>
           <th><?php echo gettext('Ref Key') ?></th>
           <th><?php echo gettext('Ref Value') ?></th>
           <th><?php echo gettext('Supply Comment') ?></th>
          </tr>
         </thead>
         <tbody class="form_data_line_tbody">
          <?php
          $count = 0;
          if (!empty($search_result)) {
           foreach ($search_result as $inv_reservation) {
            if (!empty($$class->sd_so_line_id)) {
             $so_details = sd_so_all_v::find_by_soLineId($$class->sd_so_line_id);
             $$class->so_number = $so_details->so_number;
             $$class->so_line_number = $so_details->line_number;
            }
            ?>         
            <tr class="inv_reservation_line<?php echo $count ?>">
             <td><?php $f->seq_field_d($count); ?></td>
             <td><?php echo $f->select_field_from_array('demand_type', inv_reservation::$demand_type_a, $$class->demand_type); ?></td>
             <td><?php
              echo $f->val_field_wid('so_number', 'sd_so_all_v', 'so_number', '', 'select so_number');
              echo $f->hidden_field_withCLass('sd_so_header_id', $$class->sd_so_header_id, 'dontCopy');
              echo $f->hidden_field_withCLass('shipping_org_id', $$class->org_id, 'popup_value org_id');
              echo $f->hidden_field_withCLass('sd_so_header_id', $$class->sd_so_header_id, 'popup_value sd_so_header_id_popup dontCopy');
              echo $f->hidden_field_withCLass('item_id_m', $$class->item_id_m, 'popup_value item_id_m');
              ?><i class="select_so_number generic select_popup clickable fa fa-search" data-class_name="sd_so_all_v"></i></td>
             <td><?php
              echo $f->val_field_wid('so_line_number', 'sd_so_all_v', 'line_number', 'sd_so_line_id', 'select so_line_number line_number');
              echo $f->hidden_field('sd_so_line_id', $$class->sd_so_line_id);
              echo $f->hidden_field_withCLass('shipping_org_id', '', 'popup_value org_id');
              echo $f->hidden_field_withCLass('sd_so_header_id', '', 'popup_value sd_so_header_id_popup dontCopy');
              echo $f->hidden_field_withCLass('item_id_m', '', 'popup_value item_id_m');
              ?><i class="select_so_line_number generic select_popup clickable fa fa-search" data-class_name="sd_so_all_v"></i></td> 
             <td><?php $f->text_field_wid('demand_comment'); ?></td>
             <td><?php $f->text_field_widr('d_reference_key_name', 'always_readonly'); ?></td>
             <td><?php $f->text_field_widr('d_reference_key_value', 'always_readonly'); ?></td>    
             <td><?php echo $f->text_field_widr('supply_comment'); ?></td>
            </tr>
            <?php
            $count = $count + 1;
           }
          }
          ?>
         </tbody>
        </table>
       </div>
       <div id="tabsLine-3" class="tabContent">
        <table class="form_table">
         <thead> 
          <tr>
           <th><?php echo gettext('Seq') ?> #</th>
           <th><?php echo gettext('Supply Type') ?></th>
           <th><?php echo gettext('Subinventory') ?></th>
           <th><?php echo gettext('Locator') ?></th>
           <th><?php echo gettext('Serial') ?> #</th>
           <th><?php echo gettext('Lot') ?> #</th>
           <th><?php echo gettext('On Hand') ?></th>
           <th><?php echo gettext('Res. On Hand') ?></th>
           <th><?php echo gettext('On Hand Id') ?></th>

           <th><?php echo gettext('Key Name') ?></th>
           <th><?php echo gettext('Key Value') ?></th>
          </tr>
         </thead>
         <tbody class="form_data_line_tbody">
          <?php
          $count = 0;
          if (!empty($search_result)) {
           foreach ($search_result as $inv_reservation) {
            if (!empty($$class->onhand_id)) {
             $onhand_i = onhand_v::find_by_id($$class->onhand_id);
             $$class->onhand = $onhand_i->onhand;
             $$class->reservable_onhand = $onhand_i->reservable_onhand;
            } else {
             $$class->onhand = $$class->reservable_onhand = null;
            }
            if (!empty($$class->inv_serial_number_id)) {
             $inv_serial_number_i = inv_serial_number::find_by_id($$class->inv_serial_number_id);
             $$class->serial_number = $inv_serial_number_i->serial_number;
            } else {
             $$class->serial_number = null;
            }
            if (!empty($$class->inv_lot_number_id)) {
             $inv_lot_number_i = inv_lot_number::find_by_id($$class->inv_lot_number_id);
             $$class->lot_number = $inv_lot_number_i->lot_number;
            } else {
             $$class->lot_number = null;
            }
            ?>         
            <tr class="inv_reservation_line<?php echo $count ?>">
             <td><?php $f->seq_field_d($count); ?></td>
             <td><?php echo $f->select_field_from_array('supply_type', inv_reservation::$supply_type_a, $$class->supply_type); ?></td>
             <td><?php echo $f->select_field_from_object('subinventory_id', subinventory::find_all_of_org_id($$class->org_id), 'subinventory_id', 'subinventory', $$class->subinventory_id, '', 'subinventory_id subinventory'); ?>         </td>
             <td><?php echo $f->select_field_from_object('locator_id', locator::find_all_of_subinventory($$class->subinventory_id), 'locator_id', 'locator', $$class->locator_id, '', 'locator_id locator'); ?>         </td>
             <td><?php
              echo $f->val_field_wid('serial_number', 'inv_serial_number', 'serial_number', 'item_id_m');
              echo $f->hidden_field_withCLass('inv_serial_number_id', $$class->inv_serial_number_id, 'dontCopy');
              echo $f->hidden_field_withCLass('org_id', $$class->org_id, 'popup_value');
              echo $f->hidden_field_withCLass('item_id_m', $$class->item_id_m, 'popup_value item_id_m');
              echo $f->hidden_field_withCLass('current_subinventory_id', '', 'popup_value current_subinventory_id');
              echo $f->hidden_field_withCLass('current_locator_id', '', 'popup_value current_locator_id');
              ?><i class="select_serial_number_id generic select_popup clickable fa fa-search" data-class_name="inv_serial_number"></i></td> 
             <td><?php
              echo $f->val_field_wid('lot_number', 'inv_lot_onhand_v', 'lot_number', 'item_id_m');
              echo $f->hidden_field_withCLass('inv_lot_number_id', $$class->inv_lot_number_id, 'dontCopy');
              echo $f->hidden_field_withCLass('org_id', $$class->org_id, 'popup_value');
              echo $f->hidden_field_withCLass('item_id_m', $$class->item_id_m, 'popup_value item_id_m');
              echo $f->hidden_field_withCLass('subinventory_id', '', 'popup_value subinventory_id');
              echo $f->hidden_field_withCLass('locator_id', '', 'popup_value locator_id');
              ?><i class="select_inv_lot_number_id generic select_popup clickable fa fa-search" data-class_name="inv_lot_onhand_v"></i></td> 

             <td><?php echo $f->text_field_widr('onhand', 'always_readonly'); ?></td>
             <td><?php echo $f->text_field_widr('reservable_onhand', 'always_readonly'); ?></td>
             <td><?php echo $f->text_field_widr('onhand_id', 'always_readonly'); ?></td>
             <td><?php echo $f->text_field_widr('s_reference_key_name', 'always_readonly'); ?></td>
             <td><?php echo $f->text_field_widr('s_reference_key_value', 'always_readonly'); ?></td>
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
   </form>
  </div>
 </div>
 <!--END OF FORM HEADER-->
 <div class="row small-top-margin">
  <div id="pagination" style="clear: both;">
   <?php echo!(empty($pagination_statement)) ? $pagination_statement : "";
   ?>
  </div>
 </div>

</div>
<div id="js_data">
 <ul id="js_saving_data">
  <li class="lineClassName" data-lineClassName="inv_reservation" ></li>
  <li class="savingOnlyHeader" data-savingOnlyHeader="false" ></li>
  <li class="form_header_id" data-form_header_id="inv_reservation" ></li>
 </ul>
 <ul id="js_contextMenu_data">
  <li class="btn1DivId" data-btn1DivId="inv_reservation"></li>
  <li class="noOfTabbs" data-noOfTabbs="3" ></li>
 </ul>
</div>
