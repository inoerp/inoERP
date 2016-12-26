<div id ="form_all"><span class="heading"><?php   echo gettext('On Hand Reservation')   ?></span>
 <form  method="post" id="inv_reservation"  name="inv_reservation">
  <div id ="form_header">
   <div id="tabsHeader">
    <ul class="tabMain">
     <li><a href="#tabsHeader-1"><?php echo gettext('Basic Info') ?></a></li>
     <li><a href="#tabsHeader-2"><?php echo gettext('Attachments') ?></a></li>
     <li><a href="#tabsHeader-3"><?php echo gettext('Notes') ?></a></li>
    </ul>
    <div class="tabContainer"> 
     <div id="tabsHeader-1" class="tabContent">
      <ul class="column header_field"> 
       <li><?php $f->l_text_field_dr_withSearch('inv_reservation_id'); ?>
        <a name="show" href="form.php?class_name=inv_reservation&<?php echo "mode=$mode"; ?>" class="show document_id inv_reservation_id"><i class='fa fa-refresh'></i></a> 
       </li>
       <li><?php $f->l_select_field_from_object('org_id', org::find_all_inventory(), 'org_id', 'org', $$class->org_id, 'org_id', '', '', $readonly); ?>       </li>
       <li><?php
        $f->l_val_field_d('item_number', 'item', 'item_number', 'org_id');
        echo $f->hidden_field_withId('item_id_m', $$class->item_id_m);
        echo $f->hidden_field_withCLass('reservable_cb', '1', 'popup_value');
        ?></li>
       <li><?php $f->l_text_field_d('item_description'); ?></li>
       <li><?php $f->l_select_field_from_object('uom_id', uom::find_all(), 'uom_id', 'uom_name', $$class->uom_id, 'uom_id', 'uom_id', '', $readonly1); ?>         </li>
       <li><?php $f->l_date_fieldFromToday_m('need_by_date', $$class->need_by_date, 1) ?></li>
       <li><?php $f->l_number_field_dm('demand_quantity'); ?></li>
       <li><?php $f->l_text_field_d('reason'); ?></li>

      </ul>
     </div>
     <div id="tabsHeader-2" class="tabContent">
      <div> <?php echo ino_attachement($file) ?> </div>
     </div>
     <div id="tabsHeader-3" class="tabContent">
      <div> 
       <div id="comments">
        <div id="comment_list">
         <?php echo!(empty($comments)) ? $comments : ""; ?>
        </div>
        <div id ="display_comment_form">
         <?php
         $reference_table = 'inv_reservation';
         $reference_id = $$class->inv_reservation_id;
         ?>
        </div>
        <div id="new_comment">
        </div>
       </div>
      </div>
     </div>
    </div>

   </div>
  </div>

  <div id ="form_line" class="form_line"><span class="heading"><?php echo gettext('Demand & Supply') ?></span>
   <div id="tabsLine">
    <ul class="tabMain">
     <li><a href="#tabsLine-1"><?php echo gettext('Demand') ?></a></li>
     <li><a href="#tabsLine-2"><?php echo gettext('Supply') ?></a></li>
    </ul>
    <div class="tabContainer"> 
     <div id="tabsLine-1" class="tabContent">
      <div> 
       <ul class="column header_field"> 
        <li><?php $f->l_select_field_from_array('demand_type', inv_reservation::$demand_type_a, $$class->demand_type, 'demand_type'); ?></li>
        <li><?php
         $f->l_val_field_d('so_number', 'sd_so_all_v', 'so_number', '', 'select so_number');
         echo $f->hidden_field_withId('sd_so_header_id', $$class->sd_so_header_id);
         echo $f->hidden_field_withCLass('shipping_org_id', '', 'popup_value org_id');
         echo $f->hidden_field_withCLass('sd_so_header_id', '', 'popup_value sd_so_header_id_popup');
         echo $f->hidden_field_withCLass('item_id_m', '', 'popup_value item_id_m');
         ?><i class="select_so_number generic select_popup clickable fa fa-search" data-class_name="sd_so_all_v"></i></li>
        <li><?php
         $f->l_val_field_d('so_line_number', 'sd_so_all_v', 'line_number', 'sd_so_line_id', 'select so_line_number line_number');
         echo $f->hidden_field_withId('sd_so_line_id', $$class->sd_so_line_id);
         echo $f->hidden_field_withCLass('shipping_org_id', '', 'popup_value org_id');
         echo $f->hidden_field_withCLass('sd_so_header_id', '', 'popup_value sd_so_header_id_popup');
         echo $f->hidden_field_withCLass('item_id_m', '', 'popup_value item_id_m');
         ?><i class="select_so_line_number generic select_popup clickable fa fa-search" data-class_name="sd_so_all_v"></i></li> 
        <li><?php $f->l_text_field_d('demand_comment'); ?></li>
        <li><?php $f->l_text_field_dr('d_reference_key_name'); ?></li>
        <li><?php $f->l_text_field_dr('d_reference_key_value'); ?></li>
       </ul>
      </div>
     </div> 
     <!--end of tab1-->
     <div id="tabsLine-2" class="tabContent">
      <div> 
       <ul class="column header_field"> 
        <li><?php $f->l_select_field_from_array('supply_type', inv_reservation::$supply_type_a, $$class->supply_type, 'supply_type'); ?></li>
        <li><?php $f->l_select_field_from_object('subinventory_id', subinventory::find_all_of_org_id($$class->org_id), 'subinventory_id', 'subinventory', $$class->subinventory_id, 'subinventory_id', 'subinventory_id', '', $readonly); ?>         </li>
        <li><?php $f->l_select_field_from_object('locator_id', locator::find_all_of_subinventory($$class->subinventory_id), 'locator_id', 'locator', $$class->locator_id, 'locator_id', 'locator_id', '', $readonly); ?>         </li>
        <li><?php $f->l_text_field_d('supply_comment'); ?></li>
        <li><?php $f->l_text_field_dr('s_reference_key_name'); ?></li>
        <li><?php $f->l_text_field_dr('s_reference_key_value'); ?></li>
        <li><?php
         $f->l_val_field_d('serial_number', 'inv_serial_number', 'serial_number', 'item_id_m');
         echo $f->hidden_field_withId('inv_serial_number_id', $$class->inv_serial_number_id);
         echo $f->hidden_field_withCLass('org_id', '', 'popup_value');
         echo $f->hidden_field_withCLass('item_id_m', '', 'popup_value item_id_m');
         echo $f->hidden_field_withCLass('current_subinventory_id', '', 'popup_value current_subinventory_id');
         echo $f->hidden_field_withCLass('current_locator_id', '', 'popup_value current_locator_id');
         ?><i class="select_serial_number_id generic select_popup clickable fa fa-search" data-class_name="inv_serial_number"></i></li> 
        <li><?php
         $f->l_val_field_d('lot_number', 'inv_lot_onhand_v', 'lot_number', 'item_id_m');
         echo $f->hidden_field_withId('inv_lot_number_id', $$class->inv_lot_number_id);
         echo $f->hidden_field_withCLass('org_id', '', 'popup_value');
         echo $f->hidden_field_withCLass('item_id_m', '', 'popup_value item_id_m');
         echo $f->hidden_field_withCLass('subinventory_id', '', 'popup_value current_subinventory_id');
         echo $f->hidden_field_withCLass('locator_id', '', 'popup_value current_locator_id');
         ?><i class="select_lot_number_id generic select_popup clickable fa fa-search" data-class_name="inv_lot_onhand_v"></i></li> 
        <li><?php $f->l_text_field_dr('onhand'); ?></li>
        <li><?php $f->l_text_field_dr('reservable_onhand'); ?></li>
        <li><?php $f->l_text_field_dr('onhand_id'); ?></li>
       </ul>
      </div>
     </div>
     <!--end of tab2 (purchasing)!!!! start of sales tab-->
    </div>
   </div>
  </div> 
 </form>
</div>


<div id="js_data">
 <ul id="js_saving_data">
  <li class="headerClassName" data-headerClassName="inv_reservation" ></li>
  <li class="savingOnlyHeader" data-savingOnlyHeader="true" ></li>
  <li class="primary_column_id" data-primary_column_id="inv_reservation_id" ></li>
  <li class="form_header_id" data-form_header_id="inv_reservation" ></li>
  <li class="before_save_function" data-before_save_function="beforeSave" ></li>
 </ul>
 <ul id="js_contextMenu_data">
  <li class="docHedaderId" data-docHedaderId="inv_reservation_id" ></li>
  <li class="btn1DivId" data-btn1DivId="inv_reservation"></li>
 </ul>
</div>
