<div id="all_contents">
 <div id="content_right">
  <div id="content_right_left">
   <div id="content">
		<div id="structure">
		 <div id="option_detailId">
			<div id="form_top">
			 <ul class="form_top">
        <li><input type="button" class="button refresh" value="Refresh" name="refresh"/> </li>
        <li> <a class="button" href="option.php">New Object</a> </li>
        <li><input type="submit" form="option_detail" name="submit_option_detail" id="submit_option_detail" class="button" Value="Save"></li>
        <li> <input type="button" class="button delete" form="coa_combination_form" name="delete_row" id="delete_row" value="Delete"></li>
        <li><input type="reset" class="button" form="view_header" name="reset" Value="Reset All"></li>
        <li><script>document.write('<a class="button" href="' + document.referrer + '">Go Back</a>');</script></li>
       </ul>
			 <?php // echo (!empty(form::$form_button_ul)) ? form::$form_button_ul : ""; ?>
			</div>
			<!--    Place for showing error messages-->
			<div class="error"></div><div id="loading"></div>
			<div class="show_loading_small"></div>
			<?php echo (!empty($show_message)) ? $show_message : ""; ?> 
			 <div class="three_column">
				<ul>
				 <li>
					<label>Option Id : </label>
					<?php echo form::text_field('option_header_id', $option_header_object->option_header_id, '10', '', '', '', 'option_header_id', '1'); ?>
				 </li>
				 <li><label>Option Type : </label>
					<?php echo form::text_field('option_type', $option_header_object->option_type, '20', '', '', '', 'option_type', '1'); ?>
				 </li>
				 <li><label>Type Description : </label>
					<?php echo form::text_field('type_description', $option_header_object->description, '20', '', '', '', 'option_type', '1'); ?>
				 </li>
				 <li><label>Line Id : </label>
					<?php echo form::text_field('option_line_id', $option_line_object->option_line_id, '10', '', '', '', 'option_line_id', '1'); ?>
				 </li>
				 <li><label>Line Code : </label>
					<?php echo form::text_field('option_line_code', $option_line_object->option_line_code, '20', '', '', '', 'option_line_code', '1'); ?>
				 </li>
				 <li><label>Code Description : </label>
					<?php echo form::text_field('code_description', $option_line_object->description, '20', '', '', '', 'code_description', '1'); ?>
				 </li>
				</ul>
			 </div>
			
			<!--    End of place for showing error messages-->
			<form action=""  method="post" id="option_detail"  name="option_detail">
			 <!--    START OF FORM HEADER-->
			 <div id ="form_line">

				<table id="form_data_table">
				 <thead>
					<tr>
					 <th>Action</th>
					 <th>Detail Id</th>
					 <th>Value</th>
					 <th>Description</th>
					 <th>E Field</th>
					 <th>Status</th>
					 <th>Revision</th>
					 <th>Rev #</th>
					 <th>Start Date</th>
					 <th>End Date</th>
					</tr>
				 </thead>
				 <tbody>
					<?php
					$count = 0;
					foreach ($option_detail_object as $option_detail) {
					 ?>
 					<tr class="option_line_tr<?php echo $count; ?>">
 					 <td>   
 						<ul class="inline_action">
 						 <li class="add_row_img"><img  src="<?php echo HOME_URL; ?>themes/images/add.png"  alt="add new line" /></li>
 						 <li class="remove_row_detail_img"><img src="<?php echo HOME_URL; ?>themes/images/remove.png" alt="remove this line" /> </li>
 						 <li><input type="checkbox" name="option_line_id_cb" value="<?php echo htmlentities($option_detail->option_detail_id); ?>"></li>           
						 <li><?php echo form::hidden_field('option_line_id', $option_line_object->option_line_id); ?></li>
						 <li><?php echo form::hidden_field('option_header_id', $option_header_object->option_header_id); ?></li>
				
						 </ul>
 					 </td>
 					 <td><?php echo form::text_field('option_detail_id', $option_detail->option_detail_id, '8', '12', '', 'System number', 'option_line_id'); ?></td>
 					 <td><?php echo form::text_field('option_detail_value', $option_detail->option_detail_value, 'required', '20', '50', 'No special characters', ''); ?></td>
 					 <td><?php echo form::text_field('description', $option_detail->description, '20'); ?></td>
 					 <td><?php echo form::extra_field($option_detail->efid, '5'); ?></td>
 					 <td><?php echo form::status_field($option_detail->status); ?></td>
 					 <td><?php echo form::revision_enabled_field($option_detail->rev_enabled); ?></td>
 					 <td><?php echo form::text_field('rev_number', $option_detail->rev_number, '5'); ?></td>
 					 <td><?php echo form::date_field('effective_start_date', $option_detail->effective_start_date, '10', '', '', ''); ?></td>
 					 <td><?php echo form::date_field('effective_end_date', $option_detail->effective_end_date, '10', '', '', ''); ?></td>
 					</tr>
					 <?php
					 $count++;
					}
					?>
				 </tbody>
				</table>


			 </div>
			 <!--END OF FORM HEADER-->
			</form> 

		 </div>
		</div>
		<!--   end of structure-->
	 </div>
	</div>
 </div>

</div>

<?php include_template('footer.inc') ?>
