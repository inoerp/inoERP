<form  method="post" id="item"  name="item">
 <span class="heading"><?php echo gettext('View Maintenance Activity')?> </span>
 <div id ="form_header">
  <div id="tabsHeader">
   <ul class="tabMain">
    <li><a href="#tabsHeader-1"><?php echo gettext('Basic Info')  ?></a></li>
    <li><a href="#tabsHeader-2"><?php echo gettext('Inv Assignment') ?></a></li>
    <li><a href="#tabsHeader-3"><?php echo gettext('Revisions') ?></a></li>
    <li><a href="#tabsHeader-4"><?php echo gettext('Attachments') ?></a></li>
    <li><a href="#tabsHeader-5"><?php echo gettext('Note') ?></a></li>
    <li><a href="#tabsHeader-6"><?php echo gettext('Actions') ?></a></li>
   </ul>
   <div class="tabContainer"> 
    <div id="tabsHeader-1" class="tabContent">
     <ul class="column header_field">
      <li><?php
       if (!empty($$class->org_id)) {
        $f->l_select_field_from_object('org_id', $org->findAll_inventory(), 'org_id', 'org', $$class->org_id, 'org_id', '', 1, $readonly);
       } else {
        $f->l_select_field_from_object('org_id', $org->findAll_item_master(), 'org_id', 'org', $$class->org_id, 'org_id', '', 1, $readonly);
       }
       ?> 
      </li>
      <li><label><?php echo gettext('Item Id') ?></label><?php $f->text_field_dsr('item_id') ;
          echo $f->hidden_field_withCLass('am_asset_type', 'ASSET_ACTIVITY', 'popup_value');
         ?>
       <i class="select_item_number select_popup clickable fa fa-search"></i>
       <a name="show" href="form.php?class_name=am_asset_activity&<?php echo "mode=$mode"; ?>" class="show document_id item_id"><i class="fa fa-refresh"></i></a> 
      </li>
      <li><label><?php echo gettext('Item Number') ?></label>
       <?php echo $f->text_field('item_number', $$class->item_number, '15', 'item_number', 'select_item_number_am_asset_activity', 1, $readonly_mas); ?>
       <a name="show" href="form.php?class_name=am_asset_activity&<?php echo "mode=$mode"; ?>" class="show2 document_id findBy_item_number"><i class="fa fa-refresh"></i></a> 
      </li>
      <li><?php $f->l_text_field('item_description', $$class->item_description, '20', 'item_description', '', 1, $readonly_mas); ?></li>
      <li><?php $f->l_select_field_from_object('product_line', item::product_line(), 'option_line_code', 'option_line_value', $$class->product_line, 'product_line', '', '', $readonly_mas); ?></li>
     </ul>
    </div>
    <div id="tabsHeader-2" class="tabContent">
     <div class="large_shadow_box"> 
      <ul class="column five_column">
       <li><?php echo $f->l_text_field_dr('item_id_m'); ?> </li>
      </ul>
      <?php echo!(empty($assigned_inventory_statement)) ? $assigned_inventory_statement : ""; ?>
     </div>
    </div>
    <div id="tabsHeader-3" class="tabContent">
     <div><ul class='column header_field'><li><?php $f = new inoform(); $f->l_checkBox_field_d('update_revision_cb') ?></li></ul>
      <div id="tabsDetail">
       <div>
        <div id="tabsDetail-1" class="tabContent">
         <table class="form_line_data_table">
          <thead> 
           <tr>
            <th><?php echo gettext('Action') ?></th>
            <th><?php echo gettext('Seq') ?>#</th>
            <th><?php echo gettext('Line Id') ?></th>
            <th><?php echo gettext('Revision') ?></th>
            <th><?php echo gettext('Description') ?></th>
            <th><?php echo gettext('Reason') ?></th>
            <th><?php echo gettext('ECO') ?></th>
            <th class='two_lines'><?php echo gettext('Eff. Start Date') ?></th>
            <th class='two_lines'><?php echo gettext('End Date') ?></th>
            <th class='two_lines'><?php echo gettext('Implementation Date') ?></th>
            <th class='two_lines'><?php echo gettext('Origination Date') ?></th>
           </tr>
          </thead>
          <tbody class="form_data_line_tbody">
           <?php
           $count = 0;
           $inv_item_revision_object = inv_item_revision::find_by_itemIdM_orgId($$class->item_id_m, $$class->org_id);
           if (empty($inv_item_revision_object)) {
            $inv_item_revision_object = array(new inv_item_revision());
           }
           foreach ($inv_item_revision_object as $inv_item_revision) {
            $reaonly_ir = !empty($inv_item_revision->inv_item_revision_id) ? true : false;
            ?>         
            <tr class="inv_item_revision<?php echo $count ?>">
             <td>
              <?php
              echo ino_inline_action($inv_item_revision->inv_item_revision_id, '');
              ?>
             </td>
             <td><?php $f->seq_field_d($count) ?></td>
             <td><?php $f->text_field_wid2sr('inv_item_revision_id'); ?></td>
             <td><?php echo $f->text_field_ap(array('name' => 'revision_name', 'value' => $$class_second->revision_name, 'readonly' => $reaonly_ir, 'class_name' => 'small')); ?></td>
             <td><?php $f->text_field_wid2('description'); ?></td>
             <td><?php $f->text_field_wid2('reason'); ?></td>
             <td><?php
              if ($reaonly_ir) {
               $f->text_field_wid2sr('eco_number');
              } else {
               $f->text_field_wid2s('eco_number');
              }
              ?></td>
             <td><?php echo ($reaonly_ir == true) ? $f->date_fieldAnyDay_r('effective_start_date', $$class_second->effective_start_date, 1) : $f->date_fieldAnyDay('effective_start_date', $$class_second->effective_start_date); ?></td>
             <td><?php echo ($reaonly_ir == true) ? $f->date_fieldAnyDay('effective_end_date', $$class_second->effective_end_date, 1) : $f->date_fieldAnyDay('effective_end_date', $$class_second->effective_end_date); ?></td>
             <td><?php echo ($reaonly_ir == true) ? $f->date_fieldAnyDay_r('implementation_date', $$class_second->implementation_date, 1) : $f->date_fieldAnyDay('implementation_date', $$class_second->implementation_date); ?></td>
             <td><?php echo ($reaonly_ir == true) ? $f->date_fieldAnyDay_r('origination_date', $$class_second->origination_date, 1) : $f->date_fieldAnyDay('origination_date', $$class_second->origination_date); ?></td>
            </tr>
            <?php
            $count = $count + 1;
           }
           ?>
          </tbody>
         </table>
        </div>
       </div>
      </div>
     </div>
    </div>
    <div id="tabsHeader-4" class="tabContent">
     <div> <?php echo ino_attachement($file) ?> </div>
    </div>
    <div id="tabsHeader-5" class="tabContent">
     <div id="comments">
      <div id="comment_list">
       <?php echo!(empty($comments)) ? $comments : ""; ?>
      </div>
      <div id ="display_comment_form">
       <?php
       $reference_table = 'item';
       $reference_id = $$class->item_id;
       ?>
      </div>
      <div id="new_comment">
      </div>
     </div>
     <div> 
     </div>
    </div>
    <div id="tabsHeader-6" class="tabContent">
     <div> 
      <ul class="column four_column">
       <li><label><img src="<?php echo HOME_URL; ?>themes/images/serach.png" class="select_item_template select_popup clickable">
         <?php echo gettext('Item/Template') ?>: </label><input type="text" class="text_field select_item_template item_template" id="item_template">
        <button class="button non_clickable apply_item_template " id="apply_item_template">Apply</button>
       </li>
      </ul>
     </div>
    </div>
   </div>

  </div>
 </div>
 <div id ="form_line" class="form_line"><span class="heading"><?php echo gettext('Item Details') ?></span>
  <div id="tabsLine">
   <ul class="tabMain">
    <li><a href="#tabsLine-1"><?php echo gettext('Main') ?></a></li>
    <li><a href="#tabsLine-2"><?php echo gettext('Inventory') ?></a></li>
    <li><a href="#tabsLine-3"><?php echo gettext('Sales') ?></a></li>
    <li><a href="#tabsLine-4"><?php echo gettext('Purchasing') ?></a></li>
    <li><a href="#tabsLine-5"><?php echo gettext('Manufacturing') ?></a></li>
    <li><a href="#tabsLine-6"><?php echo gettext('Planning') ?></a></li>
    <li><a href="#tabsLine-7"><?php echo gettext('Control') ?></a></li>
    <li><a href="#tabsLine-8"><?php echo gettext('Financial') ?></a></li>
    <li><a href="#tabsLine-9"><?php echo gettext('Secondary') ?></a></li>
   </ul>
   <div class="tabContainer"> 
    <div id="tabsLine-1" class="tabContent">
     <div class="first_rowset"> 
      <ul class="column header_field form_header_l"> 
       <li><?php $f->l_select_field_from_object('item_type', item::item_types(), 'option_line_code', 'option_line_value', $$class->item_type, 'item_type', '', 1, $readonly); ?>       </li> 
       <li><?php echo $f->l_select_field_from_object('uom_id', uom::find_all(), 'uom_id', 'uom_name', $$class->uom_id, 'uom_id', '', 1, $readonly); ?>       </li>
       <li><?php echo $f->l_number_field('product_line_percentage', $$class->product_line_percentage, '8'); ?></li>
       <li><?php echo $f->l_select_field_from_object('item_status', item::item_status(), 'option_line_id', 'option_line_code', $$class->item_status, 'item_status', '', '', $readonly); ?>       </li>
      </ul>
     </div>

     <div class="second_rowset">
      <div class="panel panel-collapse panel-ino-classy medium_box">
       <div class="panel-heading"><div class="panel-title"><?php echo gettext('Long Description') ?></div></div>
       <div class="panel-body">
        <ul class="column line_field">
         <li><?php echo form::text_area('long_description', $$class->long_description, '5', '30', ''); ?></li>
        </ul>
       </div>
      </div>
      <div class="panel panel-collapse panel-ino-classy large_box">
       <div class="panel-heading"><div class="panel-title"><?php echo gettext('Lead Time Information') ?></div></div>
       <div class="panel-body">
        <ul class="column line_field">
         <li><?php $f->l_text_field_d('pre_processing_lt'); ?></li>
         <li><?php $f->l_text_field_d('processing_lt'); ?></li> 
         <li><?php $f->l_text_field_d('post_processing_lt'); ?></li> 
         <li><?php $f->l_text_field_d('cumulative_mfg_lt'); ?></li>
         <li><?php $f->l_text_field_d('cumulative_total_lt'); ?></li>
         <li><?php $f->l_text_field_d('lt_lot_size'); ?></li>
        </ul>
       </div>
      </div>
     </div>
     <!--end of tab1 div three_column-->
    </div> 
    <!--end of tab1-->
    <div id="tabsLine-2" class="tabContent">
     <div class="first_rowset"> 
      <ul class="column header_field"> 
       <li><?php $f->l_checkBox_field_d('inventory_item_cb'); ?></li>
       <li><?php $f->l_checkBox_field_d('stockable_cb'); ?></li>
       <li><?php $f->l_checkBox_field_d('transactable_cb'); ?></li>
       <li><?php $f->l_checkBox_field_d('reservable_cb'); ?></li>
       <li><?php $f->l_checkBox_field_d('cycle_count_enabled_cb'); ?></li>
       <li><?php $f->l_checkBox_field_d('equipment_cb'); ?></li>
       <li><?php $f->l_checkBox_field_d('electronic_format_cb'); ?></li>
       <li><?php $f->l_checkBox_field_d('onhand_with_rev_cb'); ?></li>
       <li><?php $f->l_checkBox_field_d('item_rev_number'); ?></li>
       <li><?php $f->l_text_field_d('locator_control'); ?></li>
       <li><?php $f->l_checkBox_field_d('kit_cb'); ?></li>
      </ul>
     </div>
     <div class="second_rowset">
      <div class="panel panel-collapse panel-ino-classy medium_box">
       <div class="panel-heading"><div class="panel-title"><?php echo gettext('Lot Information') ?></div></div>
       <div class="panel-body">
        <ul class="column line_field">
         <li><?php $f->l_select_field_from_array('lot_uniqueness', item::$ls_uniqueness_a, $$class->lot_uniqueness); ?>   </li>
         <li><?php $f->l_select_field_from_array('lot_generation', item::$ls_generation_a, $$class->lot_generation); ?></li> 
         <li><?php $f->l_text_field_d('lot_prefix'); ?></li> 
         <li><?php $f->l_text_field_d('lot_starting_number'); ?></li>
        </ul>
       </div>
      </div>
      <div class="panel panel-collapse panel-ino-classy medium_box">
       <div class="panel-heading"><div class="panel-title"><?php echo gettext('Serial Information') ?></div></div>
       <div class="panel-body">
        <ul class="column line_field">
         <li><?php $f->l_select_field_from_array('serial_uniqueness', item::$ls_uniqueness_a, $$class->serial_uniqueness); ?>         </li>
         <li><?php $f->l_select_field_from_array('serial_generation', item::$ls_generation_a, $$class->serial_generation); ?>         </li> 
         <li><?php $f->l_text_field_d('serial_prefix'); ?></li> 
         <li><?php $f->l_text_field_d('serial_starting_number'); ?></li>
        </ul>
       </div>
      </div>
      <div class="panel panel-collapse panel-ino-classy medium_box">
       <div class="panel-heading"><div class="panel-title"><?php echo gettext('Measurement Information') ?></div></div>
       <div class="panel-body">
        <ul class="column line_field">
         <li><?php $f->l_select_field_from_object('weight_uom_id', uom::find_all(), 'uom_id', 'uom_name', $$class->weight_uom_id, 'weight_uom_id', '', '', $readonly); ?></li>
         <li><?php $f->l_text_field_d('weight'); ?></li> 
         <li><?php $f->l_select_field_from_object('volume_uom_id', uom::find_all(), 'uom_id', 'uom_name', $$class->volume_uom_id, 'volume_uom_id', '', '', $readonly); ?></li>
         <li><?php $f->l_text_field_d('volume'); ?></li>
         <li><?php $f->l_select_field_from_object('dimension_uom_id', uom::find_all(), 'uom_id', 'uom_name', $$class->dimension_uom_id, 'dimension_uom_id', '', '', $readonly); ?></li>
         <li><?php $f->l_text_field_d('length'); ?></li>
         <li><?php $f->l_text_field_d('width'); ?></li>
         <li><?php $f->l_text_field_d('height'); ?></li>
        </ul>
       </div>
      </div>

     </div> 
     <!--                end of tab2 div three_column-->
    </div>
    <!--end of tab2 (purchasing)!!!! start of sales tab-->
    <div id="tabsLine-3" class="tabContent">
     <div class="first_rowset"> 
      <ul class="column header_field">
       <li><?php $f->l_checkBox_field_d('customer_ordered_cb'); ?></li> 
       <li><?php $f->l_checkBox_field_d('internal_ordered_cb'); ?></li>
       <li><?php $f->l_checkBox_field_d('shippable_cb'); ?></li>
       <li><?php $f->l_checkBox_field_d('returnable_cb'); ?></li>
      </ul>
     </div>
     <div class="second_rowset">
      <div class="panel panel-collapse panel-ino-classy medium_box">
       <div class="panel-heading"><div class="panel-title"><?php echo gettext('Rule Information') ?></div></div>
       <div class="panel-body">
        <ul class="column line_field">
         <li><?php $f->l_text_field_d('atp'); ?></li>
         <li><?php $f->l_text_field_d('picking_rule'); ?></li>
        </ul>
       </div>
      </div>
     </div>
    </div> 
    <!--                end of tab3 div three_column-->
    <!--end of tab3 (sales)!!!!start of purchasing tab-->
    <div id="tabsLine-4" class="tabContent">
     <div class="first_rowset"> 
      <ul class="column header_field">
       <li><?php $f->l_checkBox_field_d('customer_ordered_cb'); ?></li>
       <li><?php $f->l_checkBox_field_d('purchased_cb'); ?></li>
       <li><?php $f->l_checkBox_field_d('use_asl_cb'); ?></li>
       <li><?php $f->l_checkBox_field_d('customer_ordered_cb'); ?></li>
       <li><?php $f->l_checkBox_field_d('customer_ordered_cb'); ?></li>
       <li><label><img src="<?php echo HOME_URL; ?>themes/images/serach.png" class="select_popup select_sourcing_rule clickable">
         <?php echo gettext('Sourcing Rule') ?></label><?php $f->text_field_d('sourcing_rule') ?></li>
       <li><?php $f->l_text_field_d('invoice_matching'); ?></li>
       <li><?php $f->l_text_field_d('default_buyer'); ?></li>
       <li><?php $f->l_text_field_d('list_price'); ?></li>
       <li><?php // $f->l_text_field_d('un_number'); ?></li>
      </ul>
     </div>
     <div class="second_rowset">
      <div class="panel panel-collapse panel-ino-classy extra_large_box">
       <div class="panel-heading"><div class="panel-title"><?php gettext('Receipt Information'); ?></div></div>
       <div class="panel-body">
        <ul class="column header_field">
         <li><?php $f->l_text_field_d('receipt_routing'); ?></li>
         <li><?php $f->l_text_field_d('receipt_sub_inventory'); ?></li>
         <li><?php $f->l_text_field_d('over_receipt_percentage'); ?></li>
         <li><?php $f->l_text_field_d('over_receipt_action'); ?></li>
         <li><?php $f->l_text_field_d('receipt_days_early'); ?></li>
         <li><?php $f->l_text_field_d('receipt_days_late'); ?></li>
         <li><?php $f->l_text_field_d('receipt_day_action'); ?></li>
        </ul>
       </div>
      </div>
     </div> 
    </div>
    <!--end of tab4(purchasing)!!! start of MFG tab-->
    <div id="tabsLine-5" class="tabContent">
     <div class="first_rowset"> 
      <ul class="column header_field"> 
       <li><?php $f->l_select_field_from_object('make_buy', item::manufacturing_item_types(), 'option_line_code', 'option_line_code', $$class->make_buy, 'make_buy', 'medium', 1, $readonly); ?>       </li>
       <li><?php $f->l_checkBox_field_d('bom_enabled_cb'); ?></li>
       <li><?php $f->l_select_field_from_object('bom_type', item::bom_types(), 'option_line_code', 'option_line_value', $$class->bom_type, 'bom_type'); ?>       </li>
       <li><?php $f->l_checkBox_field_d('build_in_wip_cb'); ?></li>
       <li><?php $f->l_select_field_from_object('wip_supply_type', bom_header::wip_supply_type(), 'option_line_code', 'option_line_value', $$class->wip_supply_type, 'wip_supply_type', 'medium', $readonly); ?>       </li>
       <li><?php $f->l_select_field_from_object('wip_supply_subinventory', subinventory::find_all_of_org_id($$class->org_id), 'subinventory_id', 'subinventory', $$class->wip_supply_subinventory, 'wip_supply_subinventory', 'subinventory_id medium', '', $readonly); ?>       </li>
       <li><?php $f->l_select_field_from_object('wip_supply_locator', locator::find_all_of_subinventory($$class->wip_supply_subinventory), 'locator_id', 'locator', $$class->wip_supply_locator, 'wip_supply_locator', 'locator_id medium', '', $readonly); ?>       </li>
      </ul>
     </div>
     <div class="second_rowset">
      <div class="panel panel-collapse panel-ino-classy large_box">
       <div class="panel-heading"><div class="panel-title"><?php echo gettext('Cost Information') ?></div></div>
       <div class="panel-body">
        <ul class="column header_field">
         <li><?php $f->l_checkBox_field_d('costing_enabled_cb'); ?></li>
         <li><?php $f->l_checkBox_field_d('inventory_asset_cb'); ?></li>
         <li><?php echo $f->l_ac_field_d('cogs_ac_id'); ?> </li>
         <li><?php echo $f->l_ac_field_d('deffered_cogs_ac_id'); ?> </li>
        </ul>
       </div>
      </div>
     </div> 
    </div>
    <!--end of tab5 (Manufacturing)!! start of planning -->
    <div id="tabsLine-6" class="tabContent">
     <div class="first_rowset"> 
      <ul class="column header_field">
       <li><?php $f->l_checkBox_field_d('allow_negative_balance_cb'); ?></li>
       <li><?php $f->l_text_field_d('planner'); ?></li>
       <li><?php echo $f->l_select_field_from_object('planning_method', item::planning_method(), 'option_line_code', 'option_line_value', $$class->planning_method); ?></li>
       <li><?php $f->l_text_field_d('forecast_method'); ?></li>
       <li><?php $f->l_text_field_d('forecast_control'); ?></li>
      </ul>
     </div>
     <div class="second_rowset">
      <div class="panel panel-collapse panel-ino-classy medium_box">
       <div class="panel-heading"><div class="panel-title"><?php echo gettext('Order Modifiers') ?></div></div>
       <div class="panel-body">
        <ul class="column header_field">
         <li><?php $f->l_number_field_d('fix_order_quantity'); ?></li>
         <li><?php $f->l_number_field_d('fix_days_supply'); ?></li>
         <li><?php $f->l_number_field_d('fix_lot_multiplier'); ?></li>
         <li><?php $f->l_number_field_d('minimum_order_quantity'); ?></li>
         <li><?php $f->l_number_field_d('maximum_order_quantity'); ?></li>
        </ul>
       </div>
      </div>

      <div class="panel panel-collapse panel-ino-classy medium_box">
       <div class="panel-heading"><div class="panel-title"><?php echo gettext('Time Fences') ?></div></div>
       <div class="panel-body">
        <ul class="column header_field">
         <li><?php $f->l_text_field_d('demand_timefence'); ?></li>
         <li><?php $f->l_text_field_d('planning_timefence'); ?></li>
         <li><?php $f->l_text_field_d('release_timefence'); ?></li>
         <li><?php echo $f->l_select_field_from_object('rounding_option', item::rounding_option(), 'option_line_code', 'option_line_value', $$class->rounding_option, 'rounding_option', '', '', $readonly); ?>         </li>
        </ul>
       </div>
      </div>

      <div class="panel panel-collapse panel-ino-classy medium_box">
       <div class="panel-heading"><div class="panel-title"><?php echo gettext('Min Max Planning') ?></div></div>
       <div class="panel-body">
        <ul class="column header_field">
         <li><?php $f->l_number_field_d('minmax_min_quantity'); ?></li>
         <li><?php $f->l_number_field_d('minmax_max_quantity'); ?></li>
         <li><?php $f->l_number_field_d('minmax_multibin_number'); ?></li>
         <li><?php $f->l_number_field_d('minmax_multibin_size'); ?></li>
        </ul>
       </div>

      </div>

     </div> 
    </div>
    <div id="tabsLine-7" class="tabContent">
     <div class="first_rowset"> 
      <ul class="column header_field"> 
       <li><?php   echo $f->l_select_field_from_array('am_asset_type', item::$am_asset_type_a, $$class->am_asset_type, 'am_asset_type');     ?>    </li> 
      </ul>
     </div>
     <div class="panel panel-collapse panel-ino-classy medium_box">
      <div class="panel-heading"><div class="panel-title"><?php echo gettext('Safety Stock') ?></div></div>
      <div class="panel-body">
       <ul class="column header_field">
        <li><?php $f->l_number_field_d('saftey_stock_quantity'); ?></li>
        <li><?php $f->l_number_field_d('saftey_stock_days'); ?></li>
        <li><?php $f->l_number_field_d('saftey_stock_percentage'); ?></li>
       </ul>
      </div>
     </div>
     <div class="panel panel-collapse panel-ino-classy medium_box">
      <div class="panel-heading"><div class="panel-title"><?php echo gettext('Asset Maintenance') ?></div></div>
      <div class="panel-body">
       <ul class="column line_field">
        <li><?php $f->l_text_field_d('am_activity_cause'); ?></li>
        <li><?php $f->l_text_field_d('am_activity_type'); ?></li>
        <li><?php $f->l_text_field_d('am_activity_source'); ?></li>
       </ul>
      </div>

     </div>
    </div> 
    <!--end of tab6 (planning)...start of lead times-->
    <div id="tabsLine-8" class="tabContent">
     <div class="first_rowset"> 
      <ul class="column header_field">
       <li><?php $f->l_checkBox_field_d('invoiceable_cb'); ?></li>
       <li><?php $f->l_text_field_d('invoice_matching'); ?></li>
       <li><?php echo $f->l_select_field_from_object('op_tax_class', item::product_tax_class(), 'option_line_code', 'option_line_value', $$class->op_tax_class, '', 'output_tax') ?>       </li>
       <li><?php echo $f->l_select_field_from_object('ip_tax_class', item::product_tax_class(), 'option_line_code', 'option_line_value', $$class->ip_tax_class, '', 'input_tax') ?>       </li>
      </ul>
     </div> 
     <div class="second_rowset">
      <div class="panel panel-collapse panel-ino-classy extra_large_box">
       <div class="panel-heading"><div class="panel-title">Account</div></div>
       <div class="panel-body">
        <ul class="column line_field">
         <li><?php $f->l_ac_field_d('material_ac_id'); ?></li>
         <li><?php $f->l_ac_field_d('material_oh_ac_id'); ?></li>
         <li><?php $f->l_ac_field_d('overhead_ac_id'); ?></li>
         <li><?php $f->l_ac_field_d('resource_ac_id'); ?></li>
         <li><?php $f->l_ac_field_d('osp_ac_id'); ?></li>
         <li><?php $f->l_ac_field_d('expense_ac_id'); ?></li>
         <li><?php $f->l_ac_field_d('sales_ac_id'); ?> </li>
        </ul>
       </div>
      </div>
     </div> 
    </div>
    <!--                  end of tab7 (Fiance)--> 
    <div id="tabsLine-9" class="tabContent">
     <?php echo!empty($secondary_field_stmt) ? $secondary_field_stmt : null; ?>
    </div>
   </div>


  </div>
 </div> 
</form>

<div id="js_data">
 <ul id="js_saving_data">
  <li class="headerClassName" data-headerClassName="item" ></li>
  <li class="savingOnlyHeader" data-savingOnlyHeader="true" ></li>
  <li class="primary_column_id" data-primary_column_id="item_id" ></li>
  <li class="form_header_id" data-form_header_id="item" ></li>
 </ul>
 <ul id="js_contextMenu_data">
  <li class="docHedaderId" data-docHedaderId="item_id" ></li>
  <li class="btn1DivId" data-btn1DivId="item" ></li>
 </ul>
</div>