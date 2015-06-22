<div id="all_contents">
 <div id="content_left"></div>
 <div id="content_right">
	<div id="content_right_left">
	 <div id="content_top"></div>
	 <div id="content">
		<div id="structure">
		 <div id="sd_shipping_control_divId">
			<div id="form_top">
			</div>
			<?php echo (!empty($show_message)) ? $show_message : ""; ?> 
			<!--    End of place for showing error messages-->
			<div id ="form_header"><span class="heading">Shipping Control </span>
			 <form action=""  method="post" id="sd_shipping_control"  name="sd_shipping_control">
				<div class="large_shadow_box">
				 <ul class="column five_column"> 
					<?php echo form::hidden_field('sd_shipping_control_id', $$class->sd_shipping_control_id); ?>
					<li><label>Inventory Org :</label>
					 <?php echo $f->select_field_from_object('org_id', org::find_all_inventory(), 'org_id', 'org', $$class->org_id, 'org_id', '', 1, $readonly1); ?>
					 <a name="show" href="form.php?class_name=sd_shipping_control" class="show org_id">	<img src="<?php echo HOME_URL; ?>themes/images/refresh.png" class="clickable"></a> 
					</li>
					<li><label>Extra Field : </label>
					 <?php echo form::extra_field($$class->ef_id, '10', $readonly); ?>
					</li>
					<li><label>Revision : </label>
					 <?php echo form::revision_enabled_field($$class->rev_enabled, $readonly); ?>
					</li>
					<li><label>Revision No: </label>
					 <?php echo form::text_field('rev_number', $$class->rev_number, '10', '', '', '', '', $readonly); ?>
					</li>
				 </ul>
				</div>
				<div id ="form_line" class="form_line"><span class="heading">Details </span>
				 <div id="tabsLine">
					<ul class="tabMain">
					 <li><a href="#tabsLine-1">Shipping Info</a></li>
					 <li><a href="#tabsLine-2">Future</a></li>
					</ul>
					<div class="tabContainer"> 
					 <div id="tabsLine-1" class="tabContent">
						<div> 
						 <ul class="column five_column"> 
							<li><label>Staging Sub Inventory : </label>
							 <?php echo $f->select_field_from_object('staging_subinventory_id', subinventory::find_all_of_org_id($$class->org_id), 'subinventory_id', 'subinventory', $$class->staging_subinventory_id, '', 'subinventory_id', '', $readonly); ?>
							</li>
							<li><label>Staging Locator : </label>
							 <?php echo $f->select_field_from_object('staging_locator_id', locator::find_all_of_subinventory($$class->staging_subinventory_id), 'locator_id', 'locator', $$class->staging_locator_id, '', 'locator_id', '', $readonly); ?>
							</li>
							<li><label>Default Picking Rule : </label>
							 <?php $f->text_field_d('default_picking_rule_id') ?>
							</li>
							<li><label>Delivery On Picking : </label>
							 <?php $f->checkBox_field_d('delivery_onpicking_cb') ?>
							</li>
							<li><label>Auto-Split On Picking : </label>
							 <?php $f->checkBox_field_d('autosplit_onpicking_cb') ?>
							</li>
							<li><label>Deffer Invoicing : </label>
							 <?php $f->checkBox_field_d('deffer_invoicing_cb') ?>
							</li>
						 </ul> 
						</div> 
						<!--end of tab1 div three_column-->
					 </div> 
					 <!--              end of tab1-->

					 <div id="tabsLine-2"  class="tabContent">

					 </div>
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
