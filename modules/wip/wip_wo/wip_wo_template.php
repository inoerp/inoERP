<div id="all_contents">
 <div id="content_header"></div>
 <div id="content_left"></div>
 <div id="content_right">
	<div id="content_right_left">
	 <div id="content_top"></div>
	 <div id="content">
		<div id="structure">
		 <div id="wip_wo_divId">
			<!--    START OF FORM HEADER-->
			<div class="error"></div><div id="loading"></div>
			<?php echo (!empty($show_message)) ? $show_message : ""; ?> 
			<!--    End of place for showing error messages-->
			<div id="form_all">
			 <div id ="form_header">	 <span class="heading"> Work Order Header </span>
				<form action=""  method="post" id="wip_wo_header"  name="wip_wo_header">
				 <div id="tabsHeader">
					<ul class="tabMain">
					 <li><a href="#tabsHeader-1">Basic Info</a></li>
					 <li><a href="#tabsHeader-2">Planning</a></li>
					 <li><a href="#tabsHeader-3">History</a></li>
					 <li><a href="#tabsHeader-4">BOM & Routing</a></li>
					</ul>
					<div class="tabContainer">
					 <div id="tabsHeader-1" class="tabContent">
						<div class="large_shadow_box"> 
						 <ul class="column five_column">
							<li>
							 <label><img src="<?php echo HOME_URL; ?>themes/images/serach.png" class="wip_wo_header_id select_popup clickable">
								WO Header Id : </label>
							 <?php echo $f->text_field_dsr('wip_wo_header_id'); ?>
							 <a name="show" class="show wip_wo_header_id"><img src="<?php echo HOME_URL; ?>themes/images/refresh.png"/></a> 
							</li>
							<li><label>Inventory (1): </label>
							 <?php echo form::select_field_from_object('org_id', org::find_all_inventory(), 'org_id', 'org', $$class->org_id, 'org_id', $readonly); ?>
							</li>
							<li><label>WO Number : </label>
							 <?php echo form::text_field_d('wo_number'); ?>
							</li>
							<li><label>WO Type (2) : </label>
							 <?php echo form::select_field_from_object('wo_type', wip_wo_header::wip_wo_type(), 'option_line_code', 'option_line_value', $$class->wo_type, 'wo_type', $readonly, 'wo_type'); ?>
							</li>
							<li><label>Accounting Group (3) : </label>
							 <?php echo $f->select_field_from_object('wip_accounting_group_id', wip_accounting_group::find_by_orgId($$class->org_id),'wip_accounting_group_id', 'wip_accounting_group', $$class->wip_accounting_group_id,'wip_accounting_group_id','',1,'readonly1' ); ?>
							 
							</li>
							<li><label>Item Id : </label><?php $f->text_field_drm('item_id_m'); ?>
							</li>
							<li><label><img src="<?php echo HOME_URL; ?>themes/images/serach.png" class="select_item_number select_popup clickable">Item Number(2) : </label>
							 <?php $f->text_field_d('item_number', 'select_item_number'); ?>
							 <?php echo $f->hidden_field_withId('processing_lt', $$class->processing_lt); ?>
							</li>
							<li><label>Description: </label>
							 <?php $f->text_field_d('item_description'); ?>
							</li>
							<li><label>UOM : </label>
							 <?php echo $f->select_field_from_object('uom', uom::find_all(), 'uom_id', 'uom_name', $$class->uom, 'uom', '', '', $readonly); ?>
							</li>
							<li><label>Status : </label>                      
							 <span class="button"><?php echo!empty($$class->wo_status) ? $$class->wo_status : ""; ?></span>
							</li>
						 </ul>
						</div>
					 </div>
					 <div id="tabsHeader-2" class="tabContent">
						<div> 
						 <ul class="column five_column">
							<li id="document_status"><label>Change Status : </label>
							 <?php echo form::select_field_from_object('wo_status', wip_wo_header::wip_wo_status(), 'option_line_code', 'option_line_value', $$class->wo_status, 'set_wo_status', $readonly, '', ''); ?>
							</li>
							<li><label>WO Start Date : </label>
							 <?php echo form::date_fieldFromToday('start_date', $$class->start_date, 1) ?>
							</li>
							<li><label>Completion Date : </label>
							 <?php echo form::date_fieldFromToday('completion_date', $$class->completion_date, 1) ?>
							</li>
							<li><label>Quantity : </label>
							 <?php form::number_field_dm('quantity'); ?>
							</li>
							<li><label>Nettable Quantity : </label>
							 <?php form::number_field_dm('nettable_quantity'); ?>
							</li>
							<li><label>Schedule Group: </label>
							 <?php form::number_field_d('schedule_group'); ?>
							</li>
							<li><label>Build Sequence : </label>
							 <?php form::number_field_d('build_sequence'); ?>
							</li>
							<li><label>Line : </label>
							 <?php form::number_field_d('line'); ?>
							</li>
							<li><label>Scheduling Priority : </label>
							 <?php form::number_field_d('scheduling_priority'); ?>
							</li>
						 </ul>
						</div>
					 </div>
					 <div id="tabsHeader-3" class="tabContent">
						<div> 
						 <ul class="column five_column">
							<li><label>Remaining Qty : </label>
							 <?php form::number_field_drs('remaining_quantity'); ?>
							</li>
							<li><label>Completed Qty :</label>
							 <?php form::number_field_drs('completed_quantity'); ?>
							</li>
							<li><label>Scrapped Qty :</label>
							 <?php echo form::number_field_drs('scrapped_quantity'); ?>
							</li>
							<li><label>Release Date :</label>
							 <?php echo form::date_fieldAnyDay('released_date', $$class->released_date) ?>
							</li>
							<li><label>First Unit Complete Date :</label>
							 <?php echo form::date_fieldAnyDay('first_unit_completed_date', $$class->first_unit_completed_date) ?>
							</li>
							<li><label>Last Unit Complete Date :</label>
							 <?php echo form::date_fieldAnyDay('last_unit_completed_date', $$class->last_unit_completed_date) ?>
							</li>
						 </ul>
						</div>
					 </div>
					 <div id="tabsHeader-4" class="tabContent">
						<div> 
						 <ul class="column five_column">
							<li><label>Referenced BOM : </label>
							 <?php echo form::text_field_d('reference_bom_item_id_m'); ?>
							</li>
							<li><label>Referenced Routing :</label>
							 <?php echo form::text_field_d('reference_routing_item_id_m'); ?>
							</li>
							<li><label>BOM Exploded :</label>
							 <?php echo form::checkBox_field('bom_exploded_cb', $$class->bom_exploded_cb, 'bom_exploded_cb', 1); ?>
							</li>
							<li><label>Routing Exploded :</label>
							 <?php echo form::checkBox_field('routing_exploded_cb', $$class->routing_exploded_cb, 'routing_exploded_cb', 1); ?>
							</li>
							<li><label>Completion Subinventory :</label>
							 <?php echo $f->select_field_from_object('completion_sub_inventory', subinventory::find_all_of_org_id($$class->org_id), 'subinventory_id', 'subinventory', $$class->completion_sub_inventory, '', 'subinventory_id', '', $readonly); ?>
							</li>
							<li><label>Completion Locator :</label>
							 <?php echo $f->select_field_from_object('completion_locator', locator::find_all_of_subinventory($$class->completion_sub_inventory), 'locator_id', 'locator', $$class->completion_locator, '', 'locator_id', '', $readonly); ?>
							</li>
						 </ul>
						</div>
					 </div>
					</div>

				 </div>
				</form>
			 </div>
			 <span class="heading"> Work Order Details </span>
			 <div id="tabsLine">
				<ul class="tabMain">
				 <li><a href="#tabsLine-1">Routing</a></li>
				 <li><a href="#tabsLine-2">Routing-2</a></li>
				 <li><a href="#tabsLine-3">BOM</a></li>
				 <li><a href="#tabsLine-4">BOM-2</a></li>
				</ul>
				<div class="tabContainer"> 
				 <div id ="form_line" class="form_line">
					<form action=""  method="post" id="wip_wo_routing_line"  name="wip_wo_routing_line">
					 <div id="tabsLine-1" class="tabContent">
						<table class="form_line_data_table">
						 <thead> 
							<tr>
							 <th>Action</th>
							 <th>WO Routing Id</th>
							 <th>Sequence</th>
							 <th>Department</th>
							 <th>Description</th>
							 <th>Count Point</th>
							 <th>Auto Charge</th>
							 <th>Back flush</th>
							 <th>MTQ</th>
							 <th>Resource Details</th>
							</tr>
						 </thead>
						 <tbody class="form_data_line_tbody wip_wo_routing_line_values" >
							<?php
							$count = 0;
							foreach ($wip_wo_routing_line_object as $wip_wo_routing_line) {
							 ?>         
 							<tr class="wip_wo_routing<?php echo $count ?>">
 							 <td>    
 								<ul class="inline_action">
 								 <li class="add_row_img"><img  src="<?php echo HOME_URL; ?>themes/images/add.png"  alt="add new line" /></li>
 								 <li class="remove_row_img"><img src="<?php echo HOME_URL; ?>themes/images/remove.png" alt="remove this line" /> </li>
 								 <li><input type="checkbox" name="line_id_cb" value="<?php echo htmlentities($wip_wo_routing_line->wip_wo_routing_line_id); ?>"></li>           
 								 <li><?php echo form::hidden_field('wip_wo_header_id', $$class->wip_wo_header_id); ?></li>
 								</ul>
 							 </td>
 							 <td><?php form::text_field_wid2('wip_wo_routing_line_id'); ?></td>
 							 <td><?php form::number_field_wid2s('routing_sequence'); ?></td>
 							 <td><?php echo form::select_field_from_object('department_id', bom_department::find_all(), 'bom_department_id', 'department', $$class_second->department_id, 'department_id', $readonly); ?></td>
 							 <td><?php form::text_field_wid2('description'); ?></td>
 							 <td><?php echo form::checkBox_field('count_point_cb', $$class_second->count_point_cb); ?></td>
 							 <td><?php echo form::checkBox_field('auto_charge_cb', $$class_second->auto_charge_cb); ?></td>
 							 <td><?php echo form::checkBox_field('backflush_cb', $$class_second->backflush_cb); ?></td>
 							 <td><?php form::number_field_wid2s('minimum_transfer_quantity'); ?></td>
 							 <td class="add_detail_values"><img src="<?php echo HOME_URL; ?>themes/images/page_add_icon_16.png" class="add_detail_values_img" alt="add detail values" />
 								<!--</td></tr>-->	
								 <?php
								 $wip_wo_routing_line_id = $wip_wo_routing_line->wip_wo_routing_line_id;
								 if (!empty($wip_wo_routing_line_id)) {
									$wip_wo_routing_detail_object = wip_wo_routing_detail::find_by_wipWo_lineId($wip_wo_routing_line_id);
								 } else {
									$wip_wo_routing_detail_object = array();
								 }
								 if (count($wip_wo_routing_detail_object) == 0) {
									$wip_wo_routing_detail = new wip_wo_routing_detail();
									$wip_wo_routing_detail_object = array();
									array_push($wip_wo_routing_detail_object, $wip_wo_routing_detail);
								 }
								 ?>
 								<div class="class_detail_form">
 								 <fieldset class="form_detail_data_fs"><legend>Detail Data</legend>
 									<div class="tabsDetail">
 									 <ul class="tabMain">
 										<li class="tabLink"><a href="#tabsDetail-1-1">Resource</a></li>
 										<li class="tabLink"><a href="#tabsDetail-2-1">Quantities</a></li>
 									 </ul>
 									 <div class="tabContainer">
 										<div id="tabsDetail-1-1" class="tabContent">
 										 <table class="form form_detail_data_table detail">
 											<thead>
 											 <tr>
 												<th>Action</th>
 												<th>Detail Id</th>
 												<th>Resource Seq</th>
 												<th>Resource</th>
 												<th>Basis</th>
 												<th>Usage</th>
 												<th>Schedule</th>
 												<th>Units</th>
 												<th>Rate</th>
 												<th>Charge Type</th>
 											 </tr>
 											</thead>
 											<tbody class="form_data_detail_tbody">
												<?php
												$detailCount = 0;
												foreach ($wip_wo_routing_detail_object as $wip_wo_routing_detail) {
												 $class_third = 'wip_wo_routing_detail';
												 $$class_third = &$wip_wo_routing_detail;
												 ?>
												 <tr class="wip_wo_routing_detail<?php echo $count . '-' . $detailCount; ?><?php echo $detailCount != 0 ? ' new_object' : '' ?>">
													<td>   
													 <ul class="inline_action">
														<li class="add_row_detail_img"><img  src="<?php echo HOME_URL; ?>themes/images/add.png"  alt="add new line" /></li>
														<li class="remove_row_img"><img src="<?php echo HOME_URL; ?>themes/images/remove.png" alt="remove this line" /> </li>
														<li><input type="checkbox" name="detail_id_cb" value="<?php echo htmlentities($wip_wo_routing_detail->wip_wo_routing_detail_id); ?>"></li>           
														<li><?php echo form::hidden_field('wip_wo_routing_line_id', $wip_wo_routing_line->wip_wo_routing_line_id); ?></li>
														<li><?php echo form::hidden_field('wip_wo_header_id', $$class->wip_wo_header_id); ?></li>

													 </ul>
													</td>
													<td><?php form::text_field_wid3sr('wip_wo_routing_detail_id'); ?></td>
													<td><?php form::text_field_wid3sm('resource_sequence'); ?></td>
													<td><?php echo form::select_field_from_object('resource_id', bom_resource::find_all(), 'bom_resource_id', 'resource', $$class_third->resource_id, '', $readonly, 'resource_id', '', 1); ?></td>
													<td><?php echo form::select_field_from_object('charge_basis', bom_header::bom_charge_basis(), 'option_line_code', 'option_line_value', $$class_third->charge_basis, '', $readonly, 'default_basis', '', 1); ?></td>
													<td><?php form::number_field_wid3s('resource_usage') ?></td>
													<td><?php echo form::select_field_from_object('resource_schedule', bom_header::bom_schedule_option(), 'option_line_code', 'option_line_value', $$class_third->resource_schedule, '', $readonly, 'default_basis', '', 1); ?></td>
													<td><?php form::number_field_wid3s('assigned_units') ?></td>
													<td><?php echo form::checkBox_field('standard_rate_cb', $$class_third->standard_rate_cb); ?></td>
													<td><?php echo form::select_field_from_object('charge_type', bom_resource::charge_type(), 'option_line_code', 'option_line_value', $$class_third->charge_type, '', $readonly, '', '', 1); ?></td>
												 </tr>
												 <?php
												 $detailCount++;
												}
												?>
 											</tbody>
 											</tbody>
 										 </table>
 										</div>
 										<div id="tabsDetail-2-1" class="tabContent">
 										 <table class="form form_detail_data_table detail">
 											<thead>
 											 <tr>
 												<th>Required Qty</th>
 												<th>Applied Qty</th>
 												<th>Open Qty</th>
 											 </tr>
 											</thead>
 											<tbody class="form_data_detail_tbody">
												<?php
												$detailCount = 0;
												foreach ($wip_wo_routing_detail_object as $wip_wo_routing_detail) {
												 $class_third = 'wip_wo_routing_detail';
												 $$class_third = &$wip_wo_routing_detail;
												 $$class_third->open_quantity = $$class_third->required_quantity - $$class_third->applied_quantity;
												 ?>
												 <tr class="wip_wo_routing_detail<?php echo $count . '-' . $detailCount; ?><?php echo $detailCount != 0 ? ' new_object' : '' ?>">
													<td><?php form::number_field_wid3s('required_quantity'); ?></td>
													<td><?php form::number_field_wid3sr('applied_quantity'); ?></td>
													<td><?php form::number_field_wid3sr('open_quantity'); ?></td>

												 </tr>
												 <?php
												 $detailCount++;
												}
												?>
 											</tbody>
 										 </table>
 										</div>
 									 </div>
 									</div>
 								 </fieldset>
 								</div>							
 							 </td>
 							</tr>
							 <?php
							 $count = $count + 1;
							}
							?>
						 </tbody>
						</table>
					 </div>
					 <div id="tabsLine-2" class="tabContent">
						<table class="form_line_data_table">
						 <thead> 
							<tr>
							 <th>Queue</th>
							 <th>Running</th>
							 <th>Rejected</th>
							 <th>Scrapped</th>
							 <th>To Move</th>
							 <th>Start Date</th>
							 <th>Completion Date</th>
							 <th>Progress %</th>
							</tr>
						 </thead>
						 <tbody class="form_data_line_tbody wip_wo_routing_line_values" >
							<?php
							$count = 0;
							foreach ($wip_wo_routing_line_object as $wip_wo_routing_line) {
							 ?>         
 							<tr class="wip_wo_routing<?php echo $count ?>">
 							 <td><?php form::text_field_wid2sr('queue_quantity'); ?></td>
 							 <td><?php form::number_field_wid2sr('running_quantity'); ?></td>
 							 <td><?php form::text_field_wid2sr('rejected_quantity'); ?></td>
 							 <td><?php form::text_field_wid2sr('scrapped_quantity'); ?></td>
 							 <td><?php form::number_field_wid2sr('tomove_quantity'); ?></td>
 							 <td><?php echo form::date_fieldFromToday('start_date', ino_date($$class_second->start_date)); ?></td>
 							 <td><?php echo form::date_fieldFromToday('completion_date', ino_date($$class_second->completion_date)); ?></td>
 							 <td><?php form::text_field_wid2sr('completed_quantity'); ?></td>
 							</tr>
							 <?php
							 $count = $count + 1;
							}
							?>
						 </tbody>
						</table>
					 </div>
					</form>

					<form action=""  method="post" id="wip_wo_bom_line"  name="wip_wo_bom_line">
					 <div id="tabsLine-3" class="tabContent">
						<table class="form_line_data_table">
						 <thead> 
							<tr>
							 <th>Action</th>
							 <th>WO BOM Id</th>
							 <th>BOM Seq</th>
							 <th>Routing Seq</th>
							 <th>Item Id</th>
							 <th>Item Number</th>
							 <th>Item Desc</th>
							 <th>UOM</th>
							 <th>Usage Basis</th>
							 <th>Quantity</th>
							</tr>
						 </thead>
						 <tbody class="form_data_line_tbody2 wip_wo_bom_values" >
							<?php
							$count = 0;
							foreach ($wip_wo_bom_object as $wip_wo_bom) {
							 if (!empty($wip_wo_bom->component_item_id_m)) {
								$item = item::find_by_id($wip_wo_bom->component_item_id_m);
								$$class_fourth->component_item_number = $item->item_number;
								$$class_fourth->component_description = $item->item_description;
								$$class_fourth->component_uom = $item->uom_id;
							 }
							 ?>         
 							<tr class="wip_wo_bom<?php echo $count ?>">
 							 <td>    
 								<ul class="inline_action">
 								 <li class="add_row_img"><img  src="<?php echo HOME_URL; ?>themes/images/add.png"  alt="add new line" /></li>
 								 <li class="remove_row_img"><img src="<?php echo HOME_URL; ?>themes/images/remove.png" alt="remove this line" /> </li>
 								 <li><input type="checkbox" name="line_id_cb" value="<?php echo htmlentities($wip_wo_bom->wip_wo_bom_id); ?>"></li>           
 								 <li><?php echo form::hidden_field('wip_wo_header_id', $$class->wip_wo_header_id); ?></li>
 								</ul>
 							 </td>
 							 <td><?php form::text_field_wid4s('wip_wo_bom_id'); ?></td>
 							 <td><?php form::text_field_wid4sm('bom_sequence'); ?></td>
 							 <td><?php echo!empty($routing_line_details) ? form::select_field_from_object('routing_sequence', $routing_line_details, 'routing_sequence', 'routing_sequence', $$class_fourth->routing_sequence, 'routing_sequence') : form::text_field_wid4s('routing_sequence'); ?></td>
 							 <td><?php echo $f->text_field('component_item_id_m', $$class_fourth->component_item_id_m, '8', '', 'item_id_m', 1, $readonly); ?></td>
 							 <td><?php echo $f->text_field('component_item_number', $$class_fourth->component_item_number, '20', '', 'select_item_number', '', $readonly); ?>
 								<img src="<?php echo HOME_URL; ?>themes/images/serach.png" class="select_item_number select_popup"></td>
 							 <td><?php echo $f->text_field('component_description', $$class_fourth->component_description, '20', '', 'item_description', '', $readonly); ?></td>
 							 <td><?php echo $f->select_field_from_object('component_uom', uom::find_all(), 'uom_id', 'uom_name', $$class_fourth->component_uom, '', 'uom_id', '', $readonly); ?></td>
 							 <td><?php echo form::select_field_from_object('usage_basis', bom_header::bom_charge_basis(), 'option_line_code', 'option_line_value', $$class_fourth->usage_basis, '', $readonly, 'usage_basis', '', 1); ?></td>
 							 <td><?php form::number_field_wid4sm('usage_quantity'); ?></td>
 							</tr>
							 <?php
							 $count = $count + 1;
							}
							?>
						 </tbody>
						</table>
					 </div>
					 <div id="tabsLine-4" class="tabContent">
						<table class="form_line_data_table">
						 <thead> 
							<tr>
							 <th>Required</th>
							 <th>Issued</th>
							 <th>Open</th>
							 <th>Onhand</th>
							 <th>Supply Type</th>
							 <th>Sub inventory</th>
							 <th>Locator</th>
							</tr>
						 </thead>
						 <tbody class="form_data_line_tbody2 wip_wo_bom_values" >
							<?php
							$count = 0;
							foreach ($wip_wo_bom_object as $wip_wo_bom) {
							 $wip_wo_bom->open_quantity = $wip_wo_bom->required_quantity - $wip_wo_bom->issued_quantity;
							 ?>         
 							<tr class="wip_wo_bom<?php echo $count ?>">
 							 <td><?php form::number_field_wid4s('required_quantity'); ?></td>
 							 <td><?php form::number_field_wid4sr('issued_quantity'); ?></td>
 							 <td><?php form::number_field_wid4sr('open_quantity'); ?></td>
 							 <td></td>
 							 <td><?php echo $f->select_field_from_object('wip_supply_type', bom_header::wip_supply_type(), 'option_line_code', 'option_line_value', $$class_fourth->wip_supply_type, '', 'wip_supply_type', '', $readonly); ?></td>
 							 <td><?php echo $f->select_field_from_object('supply_sub_inventory', subinventory::find_all_of_org_id($$class->org_id), 'subinventory_id', 'subinventory', $$class_fourth->supply_sub_inventory, '', 'subinventory_id', '', $readonly); ?></td>
 							 <td><?php echo $f->select_field_from_object('supply_locator', locator::find_all_of_subinventory($$class_fourth->supply_sub_inventory), 'locator_id', 'locator', $$class_fourth->supply_locator, '', 'locator_id', '', $readonly); ?></td>
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

			</div>
			<!--END OF FORM -->
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