<div id="all_contents">
 <div id="content_left"></div>
 <div id="content_right">
	<div id="content_right_left">
	 <div id="content_top"></div>
	 <div id="content">
		<div id="structure">
		 <div id="bom_standard_operation_divId">
			<!--    START OF FORM HEADER-->
			<div class="error"></div><div id="loading"></div>
			<?php echo (!empty($show_message)) ? $show_message : ""; ?> 
			<!--    End of place for showing error messages-->
			<div id="form_all"><span class="heading">Standard Operation</span>
			 <form action=""  method="post" id="bom_standard_operation"  name="bom_standard_operation">
				<div id ="form_header">
				 <div id="tabsHeader">
					<div class="large_shadow_box">
					 <ul class="column five_column">
						<li>
						 <label><img src="<?php echo HOME_URL; ?>themes/images/serach.png" class="bom_standard_operation_id select_popup clickable">
							Standard Operation Id : </label><?php echo $f->text_field_ds('bom_standard_operation_id'); ?>
						 <a name="show" class="show bom_standard_operation_id_show">
							<img src="<?php echo HOME_URL; ?>themes/images/refresh.png"/></a> </li>
						<li><label>Inventory(1) : </label>
						 <?php echo form::select_field_from_object('org_id', org::find_all_inventory(), 'org_id', 'org', $$class->org_id, 'org_id', $readonly); ?>
						</li>
						<li><label>Department(2) : </label>
						 <?php echo form::select_field_from_object('department_id', bom_department::find_all(), 'bom_department_id', 'department', $$class->department_id, 'department_id', $readonly); ?>
						</li>
						<li><label>Standard Operation : </label>
						 <?php echo form::text_field_d('standard_operation'); ?>
						</li>
						<li><label>Description : </label>
						 <?php echo form::text_field_d('description'); ?>
						</li>
						<li><label>Count Point : </label>
						 <?php echo form::checkBox_field('count_point_cb', $$class->count_point_cb); ?>
						</li>
						<li><label>Auto Charge : </label>
						 <?php echo form::checkBox_field('auto_charge_cb', $$class->auto_charge_cb); ?>
						</li>
						<li><label>Back Flush : </label>
						 <?php echo form::checkBox_field('count_point_cb', $$class->backflush_cb); ?>
						</li>
						<li><label>Ef Id : </label>
						 <?php echo form::extra_field($$class->ef_id, '10', $readonly); ?>
						</li>
						<li><label>Status : </label>                      
						 <?php echo form::status_field($$class->status, $readonly); ?>
						</li>
					 </ul>
					</div>

				 </div>
				</div>
			 </form>
			 <div id ="form_line" class="form_line"><span class="heading">Standard Operation Details </span>
				<div id="tabsLine">
				 <ul class="tabMain">
					<li><a href="#tabsLine-1">Resource Assignment</a></li>
					<li><a href="#tabsLine-2">Future </a></li>
				 </ul>
				 <div class="tabContainer"> 
					<form action=""  method="post" id="bom_standard_operation_resource_assignment_line"  name="bom_standard_operation_resource_assignment_line">
					 <div id="tabsLine-1" class="tabContent">
						<table class="form_line_data_table">
						 <thead> 
							<tr>
							 <th>Action</th>
							 <th>Assign. Id</th>
							 <th>Resource Seq</th>
							 <th>Resource</th>
							 <th>Basis</th>
							 <th>Usage</th>
							 <th>Schedule</th>
							 <th>Units</th>
							 <th>24 Hours</th>
							 <th>Stnd. Rate</th>
							 <th>Charge Type</th>
							</tr>
						 </thead>
						 <tbody class="form_data_line_tbody bom_standard_operation_resource_assignment_values" >
							<?php
							$count = 0;
							foreach ($bom_standard_operation_resource_assignment_object as $bom_standard_operation_resource_assignment) {
							 ?>         
 							<tr class="bom_standard_operation_resource_assignment<?php echo $count ?>">
 							 <td>    
 								<ul class="inline_action">
 								 <li class="add_row_img"><img  src="<?php echo HOME_URL; ?>themes/images/add.png"  alt="add new line" /></li>
 								 <li class="remove_row_img"><img src="<?php echo HOME_URL; ?>themes/images/remove.png" alt="remove this line" /> </li>
 								 <li><input type="checkbox" name="line_id_cb" value="<?php echo htmlentities($bom_standard_operation_resource_assignment->bom_standard_operation_resource_assignment_id); ?>"></li>           
 								 <li><?php echo form::hidden_field('bom_standard_operation_id', $$class->bom_standard_operation_id); ?></li>
 								</ul>
 							 </td>
 							 <td><?php form::text_field_wid2sr('bom_standard_operation_resource_assignment_id'); ?></td>
							 <td><?php form::number_field_wid2s('resource_sequence') ?></td>
 							 <td>
								 <?php echo form::select_field_from_object('resource_id', bom_resource::find_all(), 'bom_resource_id', 'resource', $$class_second->resource_id, '', $readonly, 'resource_id'); ?>
 							 </td>
 							 <td><?php echo form::select_field_from_object('charge_basis', bom_header::bom_charge_basis(), 'option_line_id', 'option_line_code', $$class_second->charge_basis, 'charge_basis', $readonly, 'default_basis'); ?></td>
 							 <td><?php form::number_field_wid2s('resource_usage') ?></td>
							 <td><?php echo form::select_field_from_object('resource_schedule', bom_header::bom_schedule_option(), 'option_line_id', 'option_line_code', $$class_second->resource_schedule, 'resource_schedule', $readonly, 'default_basis'); ?></td>
							 <td><?php form::number_field_wid2s('assigned_units') ?></td>
							 <td><?php echo form::checkBox_field('twenty_four_hr_cb', $$class_second->twenty_four_hr_cb); ?></td>
							 <td><?php echo form::checkBox_field('standard_rate_cb', $$class_second->standard_rate_cb); ?></td>
							 <td><?php echo form::select_field_from_object('charge_type', bom_resource::charge_type(), 'option_line_code', 'option_line_code', $$class_second->charge_type, 'charge_type', $readonly); ?></td>
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