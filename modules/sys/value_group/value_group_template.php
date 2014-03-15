<div id="all_contents">
 <div id="content_left"></div>
 <div id="content_right">
	<div id="content_right_left">
	 <div id="content_top"></div>
	 <div id="content">
		<div id="structure">
		 <div id="sys_value_group_divId">
			<!--    START OF FORM HEADER-->
			<div class="error"></div><div id="loading"></div>
			<?php echo (!empty($show_message)) ? $show_message : ""; ?> 
			<!--    End of place for showing error messages-->
			<div id="form_all">
			 <form action=""  method="post" id="sys_value_group_header"  name="sys_value_group_header">
				<div id ="form_header">
				 <div id="tabsHeader">
					<ul class="tabMain">
					 <li><a href="#tabsHeader-1">Basic Info</a></li>
					 <li><a href="#tabsHeader-2">Validation</a></li>
					 <li><a href="#tabsHeader-3">Future</a></li>
					</ul>
					<div class="tabContainer">
					 <div id="tabsHeader-1" class="tabContent">
						<div class="large_shadow_box"> 
						 <ul class="column five_column">
							<li>
							 <label><img id="sys_value_group_header_id_popup" class="showPointer popup" src="<?php echo HOME_URL; ?>themes/images/serach.png"/>
								Value Group Id : </label>
							 <?php echo form::number_field_drs('sys_value_group_header_id'); ?>
							 <a name="show" class="show sys_value_group_header_id">
								<img src="<?php echo HOME_URL; ?>themes/images/refresh.png"/></a> 
							</li>
							<li><label>Value Group(1) : </label>
							 <?php echo form::text_field_dm('value_group'); ?>
							</li>
							<li><label>Access Level* : </label>
							 <?php echo form::select_field_from_array('access_level', sys_value_group_header::$access_level_array, $$class->access_level, 'access_level', $readonly); ?>
							</li>
							<li><label>Description : </label>
							 <?php echo form::text_field_dm('description'); ?>
							</li>
							<li><label>Module* : </label>
							 <?php echo form::select_field_from_object('module_id', module::find_all(), 'module_id', 'name', $$class->module_id, 'module_id', $readonly); ?>
							</li>
							<li><label>Assignment : </label>
							 <?php echo form::select_field_from_object('option_assignments', option_header::option_assignments(), 'option_line_code', 'option_line_value', $$class->option_assignments, 'option_assignments', $readonly); ?>
							</li>
							<li><label>Status : </label>
							 <?php echo form::status_field_d('status'); ?>
							</li>
							<li><label>Revision : </label>
							 <?php form::revision_enabled_field_d('rev_enabled'); ?>
							</li>
							<li><label>Revision No: </label>
							 <?php form::text_field_ds('rev_number'); ?>
							</li>
						 </ul>
						</div>
					 </div>
					 <div id="tabsHeader-2" class="tabContent">
						<div> 
						 <ul class="column five_column">
							<li><label>Validation Type : </label>
							 <?php echo form::select_field_from_object('validation_type', sys_value_group_header::validation_types(), 'option_line_code', 'option_line_value', $$class->validation_type, '', $readonly, 'validation_type', ''); ?></li>
							<li><label>Field Type : </label>
							 <?php echo form::select_field_from_object('field_type', content_type::content_field_type(), 'option_line_code', 'option_line_value', $$class->field_type, '', $readonly, 'field_type', ''); ?></li>
							<li><label>Min Size : </label>
							 <?php echo form::number_field_d('min_size'); ?></li>
							<li><label>Max Size : </label>
							 <?php echo form::number_field_d('max_size'); ?></li>
							<li><label>Fixed Size : </label>
							 <?php echo form::number_field_d('fixed_size'); ?></li>
							<li><label>Min Value : </label>
							 <?php echo form::number_field_d('min_value'); ?></li>
							<li><label>Max Value </label>
							 <?php echo form::number_field_d('max_value'); ?></li>
							<li><label>Number Only : </label>
							 <?php form::checkBox_field_d('number_only_cb'); ?></li>
							<li><label>Uppercase Only : </label>
							 <?php form::checkBox_field_d('uppercase_only_cb'); ?></li>
						 </ul>
						</div>
					 </div>
					 <div id="tabsHeader-3" class="tabContent">
						<div> 
						 <ul class="column five_column">
						 </ul>
						</div>
					 </div>
					</div>
				 </div>
				</div>
			 </form>
			 <div id ="form_line" class="form_line"><span class="heading">Value Group Details </span>
				<div id="tabsLine">
				 <ul class="tabMain">
					<li><a href="#tabsLine-1">values</a></li>
					<li><a href="#tabsLine-2">Parent Relationship </a></li>
					<li><a href="#tabsLine-3">Finance </a></li>
					<li><a href="#tabsLine-4">Item </a></li>
				 </ul>
				 <div class="tabContainer"> 
					<form action=""  method="post" id="sys_value_group_line_line"  name="sys_value_group_line_line">
					 <div id="tabsLine-1" class="tabContent">
						<table class="form_table">
						 <thead> 
							<tr>
							 <th>Action</th>
							 <th>Line Id</th>
							 <th>Code</th>
							 <th>Value</th>
							 <th>Description</th>
							 <th>Status</th>
							 <th>Start Date</th>
							 <th>End Date</th>
							</tr>
						 </thead>
						 <tbody class="form_data_line_tbody sys_value_group_line_values" >
							<?php
							$count = 0;
							foreach ($sys_value_group_line_object as $sys_value_group_line) {
							 ?>         
 							<tr class="sys_value_group_line<?php echo $count ?>">
 							 <td>    
 								<ul class="inline_action">
 								 <li class="add_row_img"><img  src="<?php echo HOME_URL; ?>themes/images/add.png"  alt="add new line" /></li>
 								 <li class="remove_row_img"><img src="<?php echo HOME_URL; ?>themes/images/remove.png" alt="remove this line" /> </li>
 								 <li><input type="checkbox" name="line_id_cb" value="<?php echo htmlentities($sys_value_group_line->sys_value_group_line_id); ?>"></li>           
 								 <li><?php echo form::hidden_field('sys_value_group_header_id', $$class->sys_value_group_header_id); ?></li>
 								</ul>
 							 </td>
 							 <td><?php form::number_field_wid2sr('sys_value_group_line_id'); ?></td>
 							 <td><?php form::text_field_wid2sm('code') ?></td>
 							 <td><?php form::text_field_wid2s('code_value') ?></td>
 							 <td><?php form::text_field_wid2s('description') ?></td>
 							 <td><?php echo form::status_field_d2('status'); ?></td>
 							 <td><?php echo form::date_field('effective_start_date', $$class_second->effective_start_date, '10', '', '', ''); ?></td>
 							 <td><?php echo form::date_field('effective_end_date', $$class_second->effective_end_date, '10', '', '', ''); ?></td>
 							</tr>
							 <?php
							 $count = $count + 1;
							}
							?>
						 </tbody>
						</table>
					 </div>
					 <div id="tabsLine-2" class="tabContent">
						<table class="form_table">
						 <thead> 
							<tr>
							 <th>Is Parent</th>
							 <th>Parent Name</th>
							</tr>
						 </thead>
						 <tbody class="form_data_line_tbody sys_value_group_line_values" >
							<?php
							$count = 0;
							foreach ($sys_value_group_line_object as $sys_value_group_line) {
							 ?>         
 							<tr class="sys_value_group_line<?php echo $count ?>">
 							 <td><?php echo form::checkBox_field_d2('parent_cb'); ?></td>
 							 <td><?php $obj = new sys_value_group_line();
							echo form::select_field_from_object('parent_line_id', $obj->findBy_parentId($$class->sys_value_group_header_id), 'code', 'code_value', $$class_second->parent_line_id, '', $readonly);
							 ?></td>
 							</tr>
							 <?php
							 $count = $count + 1;
							}
							?>
						 </tbody>
						</table>
					 </div>
					 <div id="tabsLine-3" class="tabContent">
						<table class="form_table">
						 <thead> 
							<tr>
							 <th>Account Qualifier</th>
							 <th>Allow Budgeting</th>
							 <th>Allow Posting</th>
							</tr>
						 </thead>
						 <tbody class="form_data_line_tbody sys_value_group_line_values" >
							<?php
							$count = 0;
							foreach ($sys_value_group_line_object as $sys_value_group_line) {
							 ?>         
 							<tr class="sys_value_group_line<?php echo $count ?>">
 							 <td><?php echo form::select_field_from_object('account_qualifier', coa::coa_account_types(), 'option_line_code', 'option_line_value', $$class_second->account_qualifier, 'account_qualifier', $readonly); ?></td>
 							 <td><?php echo form::checkBox_field_d2('allow_budgeting_cb'); ?></td>
 							 <td><?php echo form::checkBox_field_d2('allow_posting_cb'); ?></td>
 							</tr>
							 <?php
							 $count = $count + 1;
							}
							?>
						 </tbody>
						</table>
					 </div>
					 <div id="tabsLine-4" class="tabContent">

					 </div>
					</form>
				 </div>

				</div>
			 </div> 
			 <div id="pagination" style="clear: both;">
				<?php echo!(empty($pagination_statement)) ? $pagination_statement : "";
				?>
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