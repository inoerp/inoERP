<div id="all_contents">
 <div id="content_left"></div>
 <div id="content_right">
	<div id="content_right_left">
	 <div id="content_top"></div>
	 <div id="content">
		<div id="structure">
		 <div id="subinventory_divId">
			<div id="form_top">
			</div>
			<!--    START OF FORM HEADER-->
			<div class="error"></div><div id="loading"></div>
			<div class="show_loading_small"></div>
			<?php echo (!empty($show_message)) ? $show_message : ""; ?> 
			<!--    End of place for showing error messages-->
			<div id ="form_header"><span class="heading">Subinventory </span>
			 <form action=""  method="post" id="subinventory"  name="subinventory">
				<div class="large_shadow_box">
				 <ul class="column five_column"> 
					<li> 
					 <label><img src="<?php echo HOME_URL; ?>themes/images/serach.png" class="subinventory_id select_popup clickable">
						Subinventory Id : </label> 
					 <?php $f->text_field_ds('subinventory_id') ?>
					 <a name="show" href="form.php?class_name=subinventory" class="show subinventory_id">	<img src="<?php echo HOME_URL; ?>themes/images/refresh.png" class="clickable"></a> 
					</li> 
					<li><label>Organization :</label>
					 <?php echo form::select_field_from_object('org_id', org::find_all_inventory(), 'org_id', 'org', $subinventory->org_id, 'org_id', $readonly); ?>
					</li>
					<li><label>Type :</label>
					 <?php echo form::select_field_from_object('type', subinventory::subinventory_type(), 'option_line_code', 'option_line_value', $$class->type, 'type', $readonly); ?>
					</li>
					<li><label>Sub Inventory :</label>
					 <?php form::text_field_wid('subinventory'); ?>
					</li>
					<li><label>Description :</label>
					 <?php form::text_field_wid('description'); ?>
					</li>
					<li><label>Extra Field : </label>
					 <?php echo form::extra_field($subinventory->ef_id, '10', $readonly); ?>
					</li>
					<li><label>Status : </label>
					 <?php echo form::status_field($subinventory->status, $readonly); ?>
					</li>
					<li><label>Revision : </label>
					 <?php echo form::revision_enabled_field($subinventory->rev_enabled_cb, $readonly); ?>
					</li>
					<li><label>Revision No: </label>
					 <?php echo form::text_field('rev_number', $subinventory->rev_number, '10', '', '', '', '', $readonly); ?>
					</li>
				 </ul>
				</div>
				<div id ="form_line" class="form_line"><span class="heading">Subinventory Details </span>
				 <div id="tabs">
					<ul class="tabMain">
					 <li><a href="#tabsLine-1">Basic Info</a></li>
					 <li><a href="#tabsLine-2">Accounts</a></li>
					</ul>
					<div class="tabContainer"> 
					 <div id="tabsLine-1" class="tabContent">
						<div > 
						 <ul class="column four_column"> 
							<li><label>Locator Control : </label>
							 <?php echo form::select_field_from_object('locator_control', subinventory::locator_control(), 'option_line_code', 'option_line_code', $$class->locator_control, 'locator_control', $readonly); ?>	 
							</li>
							<li><label>Allow Negative Balance : </label>
							 <?php echo form::checkBox_field_d('allow_negative_balance_cb'); ?>
							</li> 
							<li><label>Cost Group : </label>
							 <?php form::text_field_wid('default_cost_group'); ?>
							</li> 
							<li><label>Shipment Picking Priority : </label>
							 <?php echo form::number_field('shipment_pick_priority', $$class->shipment_pick_priority); ?>
							</li>
						 </ul> 
						</div> 
						<!--end of tab1 div three_column-->
					 </div> 
					 <div id="tabsLine-2"  class="tabContent">
						<div> 
						 <ul class="column four_column">
							<li><label>Material Ac: </label><?php $f->ac_field_d('material_ac_id'); ?></li>  
							<li><label>Over Head Ac: </label><?php $f->ac_field_d('overhead_ac_id'); ?></li> 
							<li><label>Material OH Ac: </label><?php $f->ac_field_d('material_oh_ac_id'); ?></li> 
							<li><label>Resource Ac : </label><?php $f->ac_field_d('resource_ac_id'); ?></li>  
							<li><label>OSP Ac : </label><?php $f->ac_field_d('osp_ac_id'); ?></li>  
							<li><label>Expense Ac : </label><?php $f->ac_field_d('expense_ac_id'); ?></li>  
						 </ul>
						</div> 
						<!--                end of tab2 div three_column-->
					 </div>
					 <!--end of tab5-->
					</div>

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
