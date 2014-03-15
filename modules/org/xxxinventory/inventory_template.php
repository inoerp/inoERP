<div id="all_contents">
 <div id="content_left"></div>
 <div id="content_right">
	<div id="content_right_left">
	 <div id="content_top"></div>
	 <div id="content">
		<div id="structure">
		 <div id="inventory_divId">
			<div id="form_top">
			 <?php
			 $current_page_path = "inventory.php";
			 if (empty($readonly)) {
				form::form_button($current_page_path);
				$readonly = "";
			 } else {
				$readonly = 1;
			 }
			 ?>
			</div>
			<!--    START OF FORM HEADER-->
			<div class="error"></div><div id="loading"></div>
			<div class="show_loading_small"></div>
			<?php echo (!empty($show_message)) ? $show_message : ""; ?> 
			<!--    End of place for showing error messages-->
			<div id ="form_header">
			 <form action=""  method="post" id="inventory"  name="inventory">
				<div class="large_shadow_box"><span class="heading">Inventory Org Header </span>
				 <ul class="column five_column"> 
					<li><label><a href="find_inventory.php" class="popup"> 
						 <img src="<?php echo HOME_URL; ?>themes/images/serach.png"/></a>Inventory Id :</label> 
					 <?php echo form::text_field('inventory_id', $inventory->inventory_id, '10', '', '', 'System number', 'inventory_id', $readonly); ?>
					 <a name="show" href="inventory.php?inventory_id=" class="show"><img src="<?php echo HOME_URL; ?>themes/images/refresh.png"/></a> 
					</li>
					<li><label>Organization :</label>
					 <?php echo form::select_field_from_object('org_id', org::find_all_inventory(), 'org_id', 'org', $inventory->org_id, 'org_id', $readonly); ?>
					</li>
					<li><label>Extra Field : </label>
					 <?php echo form::extra_field($inventory->ef_id, '10', $readonly); ?>
					</li>
					<li><label>Status : </label>
					 <?php echo form::status_field($inventory->status, $readonly); ?>
					</li>
					<li><label>Revision : </label>
					 <?php echo form::revision_enabled_field($inventory->rev_enabled, $readonly); ?>
					</li>
					<li><label>Revision No: </label>
					 <?php echo form::text_field('rev_number', $inventory->rev_number, '10', '', '', '', '', $readonly); ?>
					</li>
				 </ul>
				</div>
				<div id ="form_line" class="form_line"><span class="heading">Inventory Org Details </span>
				 <div id="tabs">
					<ul>
					 <li><a href="#tabs-1">Basic Info</a></li>
					 <li><a href="#tabs-2">Item Attribute</a></li>
					 <li><a href="#tabs-3">Sourcing</a></li>
					 <li><a href="#tabs-4">Costing Details</a></li>
					 <li><a href="#tabs-5">Accounts</a></li>
					</ul>
					<div id="tabs-1">
					 <div class="three_column"> 
						<ul> 
						 <li><label>Type of Inventory Org : </label> 
							<?php echo form::select_field_from_object('type', inventory::inventory_org_types(), 'option_line_code', 'option_line_code', $inventory->type, 'type', $readonly); ?>
							</li> 
						 <li><label>Inventory Code : </label>
							<?php echo form::text_field('code', $inventory->code, '10', '', '', 'Unique Code', 'code', $readonly); ?>
						 </li>
						 <li><label>Item Master Org ? : </label> 
							<?php echo form::checkBox_field('item_master_cb', $inventory->item_master_cb, 'item_master_cb', $readonly); ?>
						 </li> 
						 <li><label>Master Inventory Org : </label>
							<?php echo form::select_field_from_object('master_org', org::find_all_item_master(), 'org', 'org', $inventory->master_org, 'master_org', $readonly); ?>
						 </li> 
						 <li><label>Work Calendar : </label> 
							<input type="text" name="calendar" value="<?php echo htmlentities($inventory->calendar); ?>
										 " maxlength="50" id="calendar"> 
						 </li>
						 <li><label>Locator Control : </label>
							<?php echo form::text_field('locator_control', $inventory->locator_control, '30', '', '', 'Unique Code', 'locator_control', $readonly); ?>
						 </li>
						 <li><label>Allow Negative Balance : </label>
							<?php echo form::checkBox_field('allow_negative_balance_cb', $inventory->allow_negative_balance_cb, 'allow_negative_balance_cb', $readonly); ?>
						 </li> 
						</ul> 
					 </div> 
					 <!--end of tab1 div three_column-->
					</div> 
					<!--              end of tab1-->

					<div id="tabs-2">
					 <div class="three_column"> 
						<ul>
						 <li><label>Item Rev Enabled : </label>
							<?php echo form::checkBox_field('item_rev_enabled_cb', $inventory->item_rev_enabled_cb, 'item_rev_enabled_cb', $readonly); ?>
						 </li> 
						 <li><label>Revision Start Number : </label>
						<?php echo form::text_field('rev_start_number', $inventory->rev_start_number, '30', '', '', '', 'rev_start_number', $readonly); ?>
						</li>
						 <li><label>Lot Uniqueness : </label> 
							<input type="text" name="lot_uniqueness" value="<?php echo htmlentities($inventory->lot_uniqueness); ?>" 
										 maxlength="50"  id="lot_uniqueness"> 
						 </li>
						 <li><label>Lot Generation : </label> 
							<input type="text" name="lot_generation" value="<?php echo htmlentities($inventory->lot_generation); ?>" 
										 maxlength="50"  id="lot_generation"> 
						 </li> 
						 <li><label>Lot Prefix : </label> 
							<input type="text" name="lot_prefix" value="<?php echo htmlentities($inventory->lot_prefix); ?>
										 " maxlength="50" id="lot_prefix"> 
						 </li> 
						 <li><label>Lot Starting Number : </label> 
							<input type="text" name="lot_starting_number" value="<?php echo htmlentities($inventory->lot_starting_number); ?>
										 " maxlength="50" id="lot_starting_number"> 
						 </li>
						 <li><label>Serial Uniqueness : </label> 
							<input type="text" name="serial_uniqueness" value="<?php echo htmlentities($inventory->serial_uniqueness); ?>" 
										 maxlength="50"  id="serial_uniqueness"> 
						 </li>
						 <li><label>Serial Generation : </label> 
							<input type="text" name="serial_generation" value="<?php echo htmlentities($inventory->serial_generation); ?>" 
										 maxlength="50"  id="serial_generation"> 
						 </li> 
						 <li><label>Serial Prefix : </label> 
							<input type="text" name="serial_prefix" value="<?php echo htmlentities($inventory->serial_prefix); ?>
										 " maxlength="50" id="serial_prefix"> 
						 </li> 
						 <li><label>Serial Starting Number : </label> 
							<input type="text" name="serial_starting_number" value="<?php echo htmlentities($inventory->serial_starting_number); ?>
										 " maxlength="50" id="serial_starting_number"> 
						 </li>

						</ul>

					 </div> 
					 <!--                end of tab2 div three_column-->
					</div>
					<!--end of tab2-->

					<div id="tabs-3">
					 <div class="three_column"> 
						<ul>
						 <li><label>Available to promise : </label> 
							<input type="text" name="atp" value="<?php echo htmlentities($inventory->atp); ?>" 
										 maxlength="50"  id="atp"> 
						 </li>
						 <li><label>Picking Rule : </label> 
							<input type="text" name="picking_rule" value="<?php echo htmlentities($inventory->picking_rule); ?>" 
										 maxlength="50"  id="picking_rule"> 
						 </li>
						 <li><label>Sourcing Rule : </label> 
							<input type="text" name="sourcing_rule" value="<?php echo htmlentities($inventory->sourcing_rule); ?>" 
										 maxlength="50"  id="sourcing_rule"> 
						 </li>
						</ul>

					 </div> 
					 <!--                end of tab2 div three_column-->
					</div>
					<!--end of tab3-->

					<div id="tabs-4">
					 <div class="two_column"> 
						<ul>
						 <li><label>Costing Org : </label> 
							<?php echo form::select_field_from_object('costing_org', org::find_all_inventory(), 'org', 'org', $inventory->costing_org, 'costing_org', $readonly); ?>
						 </li>
						 <li><label>Costing Method : </label> 
							<?php echo form::select_field_from_object('costing_method', inventory::costing_methods(), 'option_line_code', 'option_line_code', $inventory->costing_method, 'costing_method', $readonly); ?>
						 </li>
						 <li><label>Transfer to GL : </label>
							<?php echo form::checkBox_field('transfer_to_gl_cb', $inventory->transfer_to_gl_cb, 'transfer_to_gl_cb', $readonly); ?>
						 </li> 
						 <li><label>Default Cost Group : </label> 
							<input type="text" name="default_cost_group" value="<?php echo htmlentities($inventory->default_cost_group); ?>" 
										 size="40" maxlength="150"  id="default_cost_group"> 
						 </li> 
						 <li><label>Material Ac : </label> 
							<?php echo form::select_field_from_object('material_ac_id', $all_code_combinations, 'coa_combination_id', 'combination', $inventory->material_ac_id, 'material_ac_id', $readonly); ?>
						 </li> 
						 <li><label>Material Overhead Ac: </label> 
							<?php echo form::select_field_from_object('material_oh_ac_id', $all_code_combinations, 'coa_combination_id', 'combination', $inventory->material_oh_ac_id, 'material_oh_ac_id', $readonly); ?>
						 </li>
						 <li><label>Overhead Ac: </label>
							<?php echo form::select_field_from_object('overhead_ac_id', $all_code_combinations, 'coa_combination_id', 'combination', $inventory->overhead_ac_id, 'overhead_ac_id', $readonly); ?>
						 </li>
						 <li><label>Resource Ac: </label> 
							<?php echo form::select_field_from_object('resource_ac_id', $all_code_combinations, 'coa_combination_id', 'combination', $inventory->resource_ac_id, 'resource_ac_id', $readonly); ?>
						 </li>
						 <li><label>Expense Ac: </label> 
							<?php echo form::select_field_from_object('expense_ac_id', $all_code_combinations, 'coa_combination_id', 'combination', $inventory->expense_ac_id, 'expense_ac_id', $readonly); ?>
						 </li>
						</ul>
					 </div> 
					 <!--                end of tab2 div three_column-->
					</div>
					<!--end of tab4-->

					<div id="tabs-5">
					 <div class="two_column"> 
						<ul>
						 <li><label>Inter Org Receivable Ac: </label> 
							<?php account_field('inter_org_receivable_ac_id'); ?>
						 </li>
						 <li><label>Inter Org PPV Ac : </label>
							<?php account_field('inter_org_ppv_ac_id'); ?>
						 </li>
						 <li><label>Inter Org Payable Ac : </label> 
							<?php account_field('inter_org_payable_ac_id'); ?>
						 </li>
						 <li><label>Inter Org InTransit Ac : </label> 
							<?php account_field('inter_org_intransit_ac_id'); ?>
						 </li> 
						 <li><label>Inv AP Accrual Ac : </label> 
							<?php account_field('inv_ap_accrual_ac_id'); ?>
						 </li> 
						 <li><label>Inv AP Expense Accrual Ac : </label> 
							<?php account_field('inv_ap_exp_accrual_ac_id'); ?>
						 </li>
						 <li><label>Inventory PPV Ac : </label> 
							<?php account_field('inv_ppv_ac_id'); ?>
						 </li>
						 <li><label>Inventory IPV Ac : </label> 
							<?php account_field('inv_ipv_ac_id'); ?>
						 </li>
						 <li><label>Sales Ac : </label> 
							<?php account_field('sales_ac_id'); ?>
						 </li> 
						 <li><label>COGS Ac : </label> 
							<?php account_field('cogs_ac_id'); ?>
						 </li> 
						 <li><label>Deferred COGS Ac : </label> 
							<?php account_field('deferred_cogs_ac_id'); ?>
						 </li>

						</ul>

					 </div> 
					 <!--                end of tab2 div three_column-->
					</div>
					<!--end of tab5-->
				 </div> 
				</div> 
			 </form>
			</div>
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
