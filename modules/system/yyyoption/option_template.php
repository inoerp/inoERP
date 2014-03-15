<div id="all_contents">
 <div id="content_left"></div>
 <div id="content_right">
  <div id="content_right_left">
   <div id="content_top"></div>
   <div id="content">
		<div id="structure">
		 <div id="option">
			<div id="form_top">
			 <?php echo (!empty(form::$form_button_ul)) ? form::$form_button_ul : ""; ?>
			</div>
			<!--    START OF FORM HEADER-->
			<div id ="form_header">
			 <form action=""  method="post" id="option_header"  name="option_header">
        <ul id="form_box"> 
				 <li>   <!--    Place for showing error messages-->
					<div class="error"></div><div id="loading"></div>
					<div class="show_loading_small"></div>
					<?php echo (!empty($show_message)) ? $show_message : ""; ?> 
					<!--    End of place for showing error messages-->
				 </li>
				 <li class="ncontrol"><span class="heading">Option Header </span>
					<div class="three_column">
					 <ul>
						<li>
						 <label><a href="find_option.php" class="popup">
							 <img src="<?php echo HOME_URL; ?>themes/images/serach.png"/></a>
							Option Id : </label>
						 <?php echo form::text_field('option_header_id', $option_header->option_header_id, '10', '','', 'System number', 'option_header_id'); ?>
						 <a name="show" href="option.php?option_header_id=" class="show option_header_id">
							<img src="<?php echo HOME_URL; ?>themes/images/refresh.png"/></a> 
						</li>
						<li><label>Option Type* : </label>
						 <?php echo form::text_field('option_type', $option_header->option_type, '20','','required', 'No special characters', 'option_type'); ?>
						</li>
						<li><label>Access Level* : </label>
						 <?php echo form::select_field_from_array('access_level', option_header::$access_level_array, $option_header->access_level, 'access_level'); ?>
						</li>
						<li><label>Description : </label>
						 <?php echo form::text_field('description', $option_header->description, '20'); ?>
						</li>
						<li><label>Module* : </label>
						 <?php echo form::select_field_from_object('module', module::find_all(), 'module_id', 'name', $option_header->module, 'module'); ?>
						</li>
						<li><label>Extra Field : </label>
						 <?php echo form::extra_field($option_header->efid); ?>
						</li>
						<li><label>Status : </label>
						 <?php echo form::status_field($option_header->status); ?>
						</li>
						<li><label>Revision : </label>
						 <?php echo form::revision_enabled_field($option_header->rev_enabled); ?>
						</li>
						<li><label>Revision No: </label>
						 <?php echo form::text_field('rev_number', $option_header->rev_number, '10'); ?>
						</li>
					 </ul>
					</div>
				 </li>
        </ul>
			 </form> 
			</div>
			<!--END OF FORM HEADER-->
			<div id ="form_line">
			 <form action="option.php"  method="post" id="option_line"  name="option_line">
				<table id="form_data_table">
				 <thead>
					<tr>
					 <th>Action</th>
					 <th>Line Id</th>
					 <th>Option Code</th>
					 <th>Description</th>
					 <th>E Field</th>
					 <th>Status</th>
					 <th>Revision</th>
					 <th>Rev #</th>
					 <th>Start Date</th>
					 <th>End Date</th>
					 <th>Add Values</th>
					</tr>
				 </thead>
				 <tbody id="form_data_tbody">
					<?php
					$count = 0;
					foreach ($option_line_object as $option_line) {
					 ?>
 					<tr class="option_line_tr<?php echo $count; ?>">
 					 <td>   
 						<ul class="inline_action">
 						 <li class="add_row_img"><img  src="<?php echo HOME_URL; ?>themes/images/add.png"  alt="add new line" /></li>
 						 <li class="remove_row_img"><img src="<?php echo HOME_URL; ?>themes/images/remove.png" alt="remove this line" /> </li>
 						 <li><input type="checkbox" name="option_line_id_cb" value="<?php echo htmlentities($option_line->option_line_id); ?>"></li>           
 						</ul>
 					 </td>
 					 <td><?php echo form::text_field('option_line_id', $option_line->option_line_id, '8', '12', '', 'System number', ''); ?></td>
 					 <td><?php echo form::text_field('option_line_code', $option_line->option_line_code, 'required', '20','50', 'No special characters', ''); ?></td>
 					 <td><?php echo form::text_field('description', $option_line->description, '20'); ?></td>
 					 <td><?php echo form::extra_field($option_line->efid,'5'); ?></td>
 					 <td><?php echo form::status_field($option_line->status); ?></td>
 					 <td><?php echo form::revision_enabled_field($option_line->rev_enabled); ?></td>
 					 <td><?php echo form::text_field('rev_number', $option_header->rev_number, '5'); ?></td>
 					 <td><?php echo form::date_field('effective_start_date', $option_line->effective_start_date, '10', '','', ''); ?></td>
 					 <td><?php echo form::date_field('effective_end_date', $option_line->effective_end_date, '10', '','', ''); ?></td>
					 <td class="add_detail_values"><img src="<?php echo HOME_URL; ?>themes/images/Toolbar_add_folder_icon.png" class="add_detail_values_img" alt="add detail values" /></td>
 					</tr>
					 <?php
					 $count++;
					}
					?>
				 </tbody>
				</table>

			 </form> 
			</div>

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
