<div id="all_contents">
 <div id="content_left"></div>
 <div id="content_right">
	<div id="content_right_left">
	 <div id="content_top"></div>
	 <div id="content">
		<div id="structure">
		 <div id="item_divId">
			<div id="form_top">
			</div>
			<!--    START OF FORM HEADER-->
			<div class="error"></div><div id="loading"></div>
			<?php echo (!empty($show_message)) ? $show_message : ""; ?> 
			<!--    End of place for showing error messages-->

			<form action=""  method="post" id="item"  name="item">
			 <div id ="form_header">
				<div id="tabsHeader">
         <ul class="tabMain">
          <li><a href="#tabsHeader-1">Basic Info</a></li>
          <li><a href="#tabsHeader-2">Inv Assignment</a></li>
          <li><a href="#tabsHeader-3">Attachments</a></li>
					<li><a href="#tabsHeader-4">Actions</a></li>
         </ul>
				 <div class="tabContainer"> 
					<div id="tabsHeader-1" class="tabContent">
					 <div class="large_shadow_box"> 
						<ul class="column five_column">
						 <li>
							<label> Inventory Org : </label>
							<?php
							if (!empty($item->org_id)) {
							 echo form::select_field_from_object('org_id', $org->findAll_inventory(), 'org_id', 'org', $item->org_id, 'org_id', $readonly, '', '', 1);
							} else {
							 echo form::select_field_from_object('org_id', $org->findAll_item_master(), 'org_id', 'org', $item->org_id, 'org_id', $readonly, '', '', 1);
							}
							?> 
						 </li>
						 <li>
							<label><img src="<?php echo HOME_URL; ?>themes/images/serach.png" class="item_id select_popup clickable">
							 Item Id : </label>
							<?php echo form::text_field('item_id', $item->item_id, '15', '25', '', 'System Number', 'item_id', $readonly) ?>
							<a name="show" href="?item_id=" class="show item_id"><img src="<?php echo HOME_URL; ?>themes/images/refresh.png"/></a> 
						 </li>
						 <li><label>Item Number<img src="<?php echo HOME_URL; ?>themes/default/images/plus_10.png" class="disable_autocomplete item_number clickable"> : </label><?php $f->text_field_dm('item_number', 'select_item_number'); ?>
							<a name="show" href="?item_id=" class="show item_number"><img src="<?php echo HOME_URL; ?>themes/images/refresh.png"/></a> 
						 </li>
						 <li><label> Description : </label><?php $f->text_field_d('item_description'); ?></li>
						</ul>
					 </div>
					</div>
					<div id="tabsHeader-2" class="tabContent">
					 <div class="large_shadow_box"> 
						<?php echo!(empty($assigned_inventory_statement)) ? $assigned_inventory_statement : ""; ?>
					 </div>
					</div>
					<div id="tabsHeader-3" class="tabContent">
					 <div> 
						<div id="show_attachment" class="show_attachment">
						 <div id="file_upload_form">
							<ul class="inRow asperWidth">
							 <li><input type="file" id="attachments" class="attachments" name="attachments[]" multiple/></li>
							 <li> <input type="button" value="Attach" form="file_upload" name="attach_submit" id="attach_submit" class="submit button"></li>
							 <li class="show_loading_small"><img alt="Loading..." src="<?php echo HOME_URL; ?>themes/images/small_loading.gif"/></li>
							</ul>
						 </div>
						 <div id="uploaded_file_details"></div>
						 <?php echo file::attachment_statement($file); ?>
						</div>
					 </div>
					</div>
					<div id="tabsHeader-4" class="tabContent">
					 <div> 
						<ul class="column four_column">
						 <li><label><img src="<?php echo HOME_URL; ?>themes/images/serach.png" class="select_item_template select_popup">
							 Item/Template: </label><input type="text" class="text_field select_item_template item_template" id="item_template">
							<button class="button non_clickable apply_item_template " id="apply_item_template">Apply</button>
						 </li>
						 <li><label>View & Update</label><button class="button non_clickable item_category " id="item_category">Categories</button></li>
						 <li><label>View & Update</label><button class="button non_clickable item_catalog" id="item_catalog">Catalogs</button></li>
						 <li><label>View & Update</label><button class="button non_clickable item_reference" id="item_reference">References</button></li>
            </ul>
					 </div>
					</div>
				 </div>

        </div>
			 </div>
			 <div id ="form_line" class="form_line"><span class="heading"> Item Details </span>
				<div id="tabsLine">
         <ul class="tabMain">
          <li><a href="#tabsLine-1">Main</a></li>
          <li><a href="#tabsLine-2">Inventory</a></li>
          <li><a href="#tabsLine-3">Sales</a></li>
          <li><a href="#tabsLine-4">Purchasing</a></li>
          <li><a href="#tabsLine-5">Manufacturing</a></li>
          <li><a href="#tabsLine-6">Planning</a></li>
          <li><a href="#tabsLine-7">Financial</a></li>
         </ul>
				 <div class="tabContainer"> 
					<div id="tabsLine-1" class="tabContent">
					 <div class="first_rowset"> 
						<ul class="column five_column"> 
						 <li><label>Item Type : </label> 
							<?php echo $f->select_field_from_object('item_type', item::item_types(), 'option_line_code', 'option_line_code', $item->item_type, 'item_type', '', 1, $readonly); ?>
						 </li> 
						 <li><label>UOM : </label>
							<?php echo form::select_field_from_object('uom_id', uom::find_all(), 'uom_id', 'uom_name', $item->uom_id, 'uom_id',  '', 1, $readonly); ?>
						 </li>
						 <li><label>Item Status : </label>
							<?php echo form::select_field_from_object('item_status', item::item_status(), 'option_line_id', 'option_line_code', $item->item_status, 'item_status', $readonly); ?>
						 </li>
						 <li><label>Revision : </label>
							<?php echo form::checkBox_field('rev_enabled_cb', $$class->rev_enabled_cb, 'rev_enabled_cb', $readonly); ?>
						 </li>
						 <li><label>Revision No: </label>
							<?php echo form::text_field('rev_number', $item->rev_number, '10', '', '', '', '', $readonly); ?>
						 </li>
						</ul>
					 </div>
					 <div class="second_rowset">
						<ul>
						 <li class="medium_box itemMaster_Main">
						 <box_heading>Long Descriptions </box_heading> 
						 <?php echo form::text_area('long_description', $item->long_description, '3', '22', ''); ?>
						 </li>
						 <li class="large_box itemMaster_leadtimes">
						 <box_heading>Lead time Information </box_heading> 
						 <ul>
							<li><label>Pre Processing : </label> 
							 <?php echo form::text_field_d('pre_processing_lt'); ?>
							</li>
							<li><label>Processing : </label> 
							 <?php echo form::text_field_d('processing_lt'); ?>
							</li> 
							<li><label>Post Processing : </label>
							 <?php echo form::text_field_d('post_processing_lt'); ?>
							</li> 
							<li><label>Cumulative Mfg : </label> 
							 <?php echo form::text_field_d('cumulative_mfg_lt'); ?>
							</li>
							<li><label>Cumulative Total : </label> 
							 <?php echo form::text_field_d('cumulative_total_lt'); ?>
							</li>
							<li><label>Lead time Lot Size : </label> 
							 <?php echo form::text_field_d('lt_lot_size'); ?>
							</li>
						 </ul>
						 </li>
						</ul>
					 </div>
					 <!--end of tab1 div three_column-->
					</div> 
					<!--end of tab1-->
					<div id="tabsLine-2" class="tabContent">
					 <div class="first_rowset"> 
						<ul class="column five_column"> 
						 <li><label>Inventory Item : </label> 
							<?php echo form::checkBox_field('inventory_item_cb', $$class->inventory_item_cb, '', $readonly); ?>
						 </li>
						 <li><label>Stockable : </label> 
							<?php echo form::checkBox_field('stockable_cb', $$class->stockable_cb, '', $readonly); ?>
						 </li>
						 <li><label>Transactable : </label> 
							<?php echo form::checkBox_field('transactable_cb', $$class->transactable_cb, '', $readonly); ?>
						 </li>
						 <li><label>Reservable : </label> 
							<?php echo form::checkBox_field('reservable_cb', $$class->reservable_cb, '', $readonly); ?>
						 </li>
						 <li><label>Cycle count enabled : </label> 
							<?php echo form::checkBox_field('cycle_count_enabled_cb', $$class->cycle_count_enabled_cb, '', $readonly); ?>
						 </li>
						 <li><label>Equipment : </label> 
							<?php echo form::checkBox_field('equipment_cb', $$class->equipment_cb, '', $readonly); ?>
						 </li>
						 <li><label>Electronic Format : </label> 
							<?php echo form::checkBox_field('electronic_format_cb', $$class->electronic_format_cb, '', $readonly); ?>
						 </li>
						 <li><label>Item Rev Enabled : </label> 
							<?php echo form::checkBox_field('item_rev_enabled_cb', $$class->item_rev_enabled_cb, '', $readonly); ?>
						 </li> 
						 <li><label>Rev Number : </label> 
							<?php echo form::text_field_d('item_rev_number'); ?>
						 </li>
						 <li><label>Locator Control : </label> 
							<?php echo form::text_field_d('locator_control'); ?>
						 </li>
						</ul>
					 </div>
					 <div class="second_rowset">
						<ul class="small_box itemMaster_lot">
						 <box_heading>Lot Information </box_heading> 
						 <li><label>Lot Uniqueness : </label> 
							<?php echo form::text_field_d('lot_uniqueness'); ?>
						 </li>
						 <li><label>Lot Generation : </label> 
							<?php echo form::text_field_d('lot_generation'); ?>
						 </li> 
						 <li><label>Lot Prefix : </label> 
							<?php echo form::text_field_d('lot_prefix'); ?>
						 </li> 
						 <li><label>Lot Starting Number : </label> 
							<?php echo form::text_field_d('lot_starting_number'); ?>
						 </li>
						</ul>

						<ul class="small_box itemMaster_serial">
						 <box_heading>Serial Information </box_heading> 
						 <li><label>Serial Uniqueness : </label> 
							<?php echo form::text_field_d('serial_uniqueness'); ?>
						 </li>
						 <li><label>Serial Generation : </label> 
							<?php echo form::text_field_d('serial_generation'); ?>
						 </li> 
						 <li><label>Serial Prefix : </label> 
							<?php echo form::text_field_d('serial_prefix'); ?>
						 </li> 
						 <li><label>Serial Starting Number : </label> 
							<?php echo form::text_field_d('serial_starting_number'); ?>
						 </li>
						</ul>
						<ul>
						 <div class="large_box itemMaster_physical"><box_heading>Item Information </box_heading> 
							<li><label>Weight UOM : </label>
							 <?php echo form::select_field_from_object('weight_uom_id', uom::find_all(), 'uom_id', 'uom_name', $item->weight_uom_id, 'weight_uom_id', $readonly); ?></li>
							<li><label>Weight : </label><?php echo form::text_field_d('weight'); ?></li> 
							<li><label>Volume UOM : </label>
							 <?php echo form::select_field_from_object('volume_uom_id', uom::find_all(), 'uom_id', 'uom_name', $item->volume_uom_id, 'volume_uom_id', $readonly); ?></li>
							<li><label>Volume : </label><?php echo form::text_field_d('volume'); ?></li>
							<li><label>Dimension UOM : </label>
							 <?php echo form::select_field_from_object('dimension_uom_id', uom::find_all(), 'uom_id', 'uom_name', $item->dimension_uom_id, 'dimension_uom_id', $readonly); ?></li>
							<li><label>Length : </label><?php echo form::text_field_d('length'); ?></li>
							<li><label>Width : </label><?php echo form::text_field_d('width'); ?></li>
							<li><label>Volume : </label><?php echo form::text_field_d('volume'); ?></li>
						 </div>
						</ul>

					 </div> 
					 <!--                end of tab2 div three_column-->
					</div>
					<!--end of tab2 (purchasing)!!!! start of sales tab-->
					<div id="tabsLine-3" class="tabContent">
					 <div class="first_rowset"> 
						<ul class="column five_column"> 
						 <li><label>Customer Ordered : </label>
							<?php echo form::checkBox_field('customer_ordered_cb', $$class->customer_ordered_cb, '', $readonly); ?>
						 </li>
						 <li><label>Internal Ordered : </label>
							<?php echo form::checkBox_field('internal_ordered_cb', $$class->internal_ordered_cb, '', $readonly); ?>
						 </li>
						 <li><label>Shippable : </label> 
							<?php echo form::checkBox_field('shippable_cb', $$class->shippable_cb, '', $readonly); ?>
						 </li>
						 <li><label>Returnable : </label> 
							<?php echo form::checkBox_field('returnable_cb', $$class->returnable_cb, '', $readonly); ?>
						 </li>
						</ul>
					 </div>
					 <div class="second_rowset">
						<ul class="small_box rule"><box_heading>Rule Information </box_heading> 
						 <li><label>Available to promise : </label> 
							<?php echo form::text_field_d('atp'); ?>
						 </li>
						 <li><label>Picking Rule : </label> 
							<?php echo form::text_field_d('picking_rule'); ?>
						 </li>
						 <li><label>Sourcing Rule : </label> 
							<?php echo form::text_field_d('sourcing_rule'); ?>
						 </li>
						</ul>
					 </div>
					</div> 
					<!--                end of tab3 div three_column-->
					<!--end of tab3 (sales)!!!!start of purchasing tab-->
					<div id="tabsLine-4" class="tabContent">
					 <div class="first_rowset"> 
						<ul class="column five_column"> 
						 <li><label>Purchased : </label> 
							<?php echo form::checkBox_field('purchased_cb', $$class->purchased_cb, '', $readonly); ?>
						 </li>
						 <li><label>ASL usage mandatory : </label> 
							<?php echo form::checkBox_field('use_asl_cb', $$class->use_asl_cb, '', $readonly); ?>
						 </li>
						 <li><label>Invoice Matching : </label> 
							<?php echo form::text_field_d('invoice_matching'); ?>
						 </li>
						 <li><label>Default Buyer : </label> 
							<?php echo form::text_field_d('default_buyer'); ?>
						 </li>
						 <li><label>List Price : </label> 
							<?php echo form::text_field_d('list_price'); ?>
						 </li> 
						 <li><label>UN Number : </label> 
							<?php echo form::text_field_d('un_number'); ?>
						 </li> 
						</ul>
					 </div>
					 <div class="second_rowset">
						<ul class="large_box itemMaster_receipt"><box_heading>Receipt Information </box_heading> 
						 <li><label>Receipt Routing : </label>
							<?php echo form::text_field_d('receipt_routing'); ?>
						 </li> 
						 <li><label>Receiving SubInventory : </label>
							<?php echo form::text_field_d('receipt_sub_inventory'); ?>
						 </li> 
						 <li><label>Over Receipt % : </label>
							<?php echo form::text_field_d('over_receipt_percentage'); ?>
						 </li>
						 <li><label>Over Receipt Action : </label>
							<?php echo form::text_field_d('over_receipt_action'); ?>
						 </li>
						 <li><label>Allowed early receipt days : </label>
							<?php echo form::text_field_d('receipt_days_early'); ?>
						 </li> 
						 <li><label>Allowed late receipt days : </label>
							<?php echo form::text_field_d('receipt_days_late'); ?>
						 </li> 
						 <li><label>Receipt Day Action : </label>
							<?php echo form::text_field_d('receipt_day_action'); ?>
						 </li>
						</ul>
					 </div> 
					</div>
					<!--end of tab4(purchasing)!!! start of MFG tab-->
					<div id="tabsLine-5" class="tabContent">
					 <div class="first_rowset"> 
						<ul class="column five_column"> 
						 <li><label>Make or Buy : </label>
							<?php echo form::select_field_from_object('make_buy', item::manufacturing_item_types(), 'option_line_code', 'option_line_code', $item->make_buy, 'make_buy', $readonly); ?>
						 </li>
						 <li><label>BOM Enabled : </label>
							<?php echo form::checkBox_field('bom_enabled_cb', $$class->bom_enabled_cb, '', $readonly); ?>
						 </li>
						 <li><label>BOM Type: </label>
							<?php echo form::text_field_d('bom_type'); ?>
						 </li>
						 <li><label>Build in WIP : </label>
							<?php echo form::checkBox_field('build_in_wip_cb', $$class->build_in_wip_cb, '', $readonly); ?>
						 </li>
						 <li><label>WIP Supply Type: </label> 
							<?php echo form::select_field_from_object('wip_supply_type', bom_header::wip_supply_type(), 'option_line_code', 'option_line_value', $item->wip_supply_type, '', $readonly, '', '', ''); ?>
						 </li>
						 <li><label>Supply Subinventory: </label> 
							<?php echo form::select_field_from_object('wip_supply_subinventory', subinventory::find_all_of_org_id($item->org_id), 'subinventory_id', 'subinventory', $item->wip_supply_subinventory, '', $readonly, 'subinventory_id', '', ''); ?>
						 </li>
						 <li><label>Supply Locator: </label> 
							<?php echo form::select_field_from_object('wip_supply_locator', locator::find_all_of_subinventory($item->wip_supply_subinventory), 'locator_id', 'locator', $item->wip_supply_locator, '', $readonly, 'locator_id', '', ''); ?>
						 </li>

						</ul>
					 </div>
					 <div class="second_rowset">
						<ul class="small_box rule"><box_heading>Cost Information </box_heading> 
						 <li><label>Costing Enabled : </label> 
							<?php echo form::checkBox_field('costing_enabled_cb', $$class->costing_enabled_cb, '', $readonly); ?>
						 </li>
						 <li><label>Inventory Asset : </label>
							<?php echo form::checkBox_field('inventory_asset_cb', $$class->inventory_asset_cb, '', $readonly); ?>
						 </li>
						 <li><label>COGS Ac : </label>
							<?php echo form::text_field_d('cogs_ac'); ?>
						 </li>
						 <li><label>Deferred COGS Ac : </label>
							<?php echo form::text_field_d('deffered_cogs_ac'); ?>
						 </li>
						</ul>
					 </div> 
					</div>
					<!--end of tab5 (Manufacturing)!! start of planning -->
					<div id="tabsLine-6" class="tabContent">
					 <div class="first_rowset"> 
						<ul class="column five_column"> 
						 <li><label>Allow Negative Balance: </label>
							<?php echo form::checkBox_field('allow_negative_balance_cb', $$class->allow_negative_balance_cb, '', $readonly); ?>
						 </li> 
						 <li><label>Planner: </label>
							<?php echo form::text_field_d('planner'); ?>
						 </li>
						 <li><label>Planning Method: </label>
							<?php echo form::text_field_d('planning_method'); ?>
						 </li>
						 <li><label>Forecast Method: </label>
							<?php echo form::text_field_d('forecast_method'); ?>
						 </li>
						 <li><label>Forecast Control: </label> 
							<?php echo form::text_field_d('forecast_control'); ?>
						 </li>
						</ul>
					 </div>
					 <div class="second_rowset">
						<ul class="small_box order_modifiers"><box_heading>Order Modifiers </box_heading> 
						 <li><label>Fix Order Quantity : </label>
							<?php echo form::number_field_d('fix_order_quantity'); ?>
						 </li>
						 <li><label>Fix Days Supply : </label>
							<?php echo form::number_field_d('fix_days_supply'); ?>
						 </li>
						 <li><label>Fix Lot Multiplier : </label> 
							<?php echo form::number_field_d('fix_lot_multiplier'); ?>
						 </li>
						 <li><label>Minimum Order Quantity : </label>
							<?php echo form::number_field_d('minimum_order_quantity'); ?>
						 </li>
						 <li><label>Maximum Order Quantity : </label>
							<?php echo form::number_field_d('maximum_order_quantity'); ?>
						 </li>
						</ul> 

						<ul class="small_box timefence"><box_heading>Time Fences </box_heading> 
						 <li><label>Demand Time Fence : </label><?php echo form::text_field_d('demand_timefence'); ?></li>
						 <li><label>Planning Time Fence : </label><?php echo form::text_field_d('planning_timefence'); ?></li>
						 <li><label>Release Time Fence : </label><?php echo form::text_field_d('release_timefence'); ?></li>
						</ul> 
					 </div> 
					</div>
					<!--end of tab6 (planning)...start of lead times-->
					<div id="tabsLine-7" class="tabContent">
					 <div class="first_rowset"> 
						<ul class="column five_column"> 
						 <li><label>Invoicable: </label>
							<?php echo form::text_field_d('demand_timefence'); ?>
						 </li>
						 <li><label>Invoice Matching: </label>
							<?php echo form::text_field_d('demand_timefence'); ?>
						 </li>
						 <li><label>AP Tax: </label>
							<?php echo form::text_field_d('demand_timefence'); ?>
						 </li>
						 <li><label>Sales Tax: </label>
							<?php echo form::text_field_d('demand_timefence'); ?>
						 </li>
						 <li><label>AP Payment Term: </label>
							<?php echo form::text_field_d('demand_timefence'); ?>
						 </li>
						 <li><label>AR Payment Term: </label>
							<?php echo form::text_field_d('demand_timefence'); ?>
						 </li>
						</ul>
					 </div> 
					 <div class="second_rowset">
						<ul class="three_column">
						 <li><label>Material Ac: </label><?php $f->ac_field_d('material_ac_id'); ?></li>
						 <li><label>Material OH Ac: </label><?php $f->ac_field_d('material_ac_id'); ?></li>
						 <li><label>OverHead Ac: </label> <?php $f->ac_field_d('material_ac_id'); ?></li>
						 <li><label>Resource Ac: </label> <?php $f->ac_field_d('resource_ac'); ?></li>
						 <li><label>Expense Ac: </label><?php $f->ac_field_d('expense_ac'); ?></li>
						 <li><label>OSP Ac: </label> <?php $f->ac_field_d('material_ac_id'); ?> </li>
						 <li><label>Sales Ac: </label><?php $f->ac_field_d('sales_ac'); ?> </li>
						</ul>
					 </div> 
					</div>
					<!--                  end of tab7 (Fiance)--> 
				 </div>


        </div>
			 </div> 
			</form>

			<!--END OF FORM HEADER-->
		 </div>
		</div>
		<!--   end of structure-->
	 </div>
	 <div id="content_bottom"></div>
	</div>
	<div id="content_right_right"></div>
 </div>

</div>

<?php include_template('footer.inc') ?>
