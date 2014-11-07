<div id="all_contents">
 <div id="content_left"></div>
 <div id="content_right">
	<div id="content_right_left">
	 <div id="content_top"></div>
	 <div id="content">
		<div id="coa_structure_id">
		 <div id="coa_combination_divId">
			<!--    START OF FORM HEADER-->
			<div class="error"></div><div id="loading"></div>
			<?php echo (!empty($show_message)) ? $show_message : ""; ?> 
			<!--    End of place for showing error messages-->
			<div id="form_all">
			 <div id ="form_header">
				<span class="heading">Chart Of Account Code Combinations </span> 
			 </div>
			 <table class="form_table">
				<tr>
				 <td>
					<label><a href="select.php?class_name=<?php echo $class; ?>" class="select popup">
								<img src="<?php echo HOME_URL; ?>themes/images/serach.png"/></a>
					 COA Id : </label>
					<?php echo form::number_field_ds('coa_id'); ?>
					<a name="show" class="show coa_id_show">
					 <img src="<?php echo HOME_URL; ?>themes/images/refresh.png"/></a> 
				 </td>
				 <td>	<label>Structure : </label>
					<?php echo form::select_field_from_object('coa_structure_id', coa::coa_structures(), 'option_header_id', 'option_type', $$class_second->coa_structure_id, 'coa_structure_id', $readonly); ?>
					<a name="show" class="show coa_structure_show">
					 <img src="<?php echo HOME_URL; ?>themes/images/refresh.png"/></a> 
				 </td>
				</tr>
			 </table>
			</div>
			<div id ="form_line" class="coa_combination"><span class="heading">Value Group Details </span>
			 <div id="tabsLine">
				<ul class="tabMain">
				 <li><a href="#tabsLine-1">Basics - View Only </a></li>
				 <li><a href="#tabsLine-2">Field Values </a></li>
				 <li><a href="#tabsLine-3">Effectivity </a></li>
				</ul>
				<div class="tabContainer"> 
				 <form action=""  method="post" id="coa_combination_line"  name="coa_combination_line">
					<div id="tabsLine-1" class="tabContent">
					 <table class="form_table">
						<thead> 
						 <tr>
							<th>Action</th>
							<th>CC Id</th>
							<th>Code Combination</th>
							<th>Description</th>

						 </tr>
						</thead>
						<tbody class="form_data_line_tbody coa_combination_values" >
						 <?php
						 $count = 0;
						 foreach ($coa_combination_object as $coa_combination) {
							?>         
 						 <tr class="coa_combination_line<?php echo $count ?>">
 							<td>    
 							 <ul class="inline_action">
 								<li class="add_row_img"><img  src="<?php echo HOME_URL; ?>themes/images/add.png"  alt="add new line" /></li>
 								<li class="remove_row_img"><img src="<?php echo HOME_URL; ?>themes/images/remove.png" alt="remove this line" /> </li>
 								<li><input type="checkbox" name="line_id_cb" value="<?php echo htmlentities($coa_combination->coa_combination_id); ?>"></li>           
 								<li><?php echo form::hidden_field('coa_id', $$class_second->coa_id); ?></li>
 								<li><?php echo form::hidden_field('coa_structure_id', $$class_second->coa_structure_id); ?></li>
 							 </ul>
 							</td>

 							<td><?php form::number_field_widsr('coa_combination_id'); ?></td>
 							<td><?php echo form::text_field('combination', $$class->combination, 30, '', 1, '', 'Non editable - Enter segment/field values', 1); ?></td>
 							<td><?php echo form::text_field('description', $$class->description, 60, '', 1, '', 'Non editable - Enter segment/field values', 1) ?></td>

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
						 <tr><?php
							if (!empty($$class_second->coa_id)) {
							 foreach (coa::coa_display_by_coaId($$class_second->coa_id) as $key => $value) {
								echo!empty($value) ? "<th>$value : </th>" : '';
							 }
							}
							?>
						 </tr>
						</thead>
						<tbody class="form_data_line_tbody coa_combination_values" >
						 <?php
						 $count = 0;
						 foreach ($coa_combination_object as $coa_combination) {
							echo '<tr class="coa_combination_line' . $count . '">';
							if (!empty($$class_second->coa_id)) {
							 $datacount = 1;
							 foreach (coa::coa_display_by_coaId($$class_second->coa_id) as $key => $value) {
								if (!empty($value)) {
								 $option_line = option_line::find_by_optionId_lineCode($$class_second->coa_structure_id, $value);
								 $field_name = 'field' . $datacount;
								 $descArray = ['code', 'description'];
								 echo '<td>' .
								 form::select_field_from_object($field_name, sys_value_group_line::find_by_header_id($option_line->value_group_id), 'code', $descArray, $$class->$field_name, '', $readonly, 'field_values', '', 1)
								 . '</td>';
								 $datacount++;
								}
							 }
							}
							echo '</tr>';
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
							<th>Status</th>
							<th>Start Date</th>
							<th>End Date</th>
						 </tr>
						</thead>
						<tbody class="form_data_line_tbody coa_combination_values" >
						 <?php
						 $count = 0;
						 foreach ($coa_combination_object as $coa_combination) {
							?>         
 						 <tr class="coa_combination_line<?php echo $count ?>">
 							<td><?php echo form::status_field_d('status'); ?></td>
 							<td><?php echo form::date_fieldAnyDay('effective_start_date', $$class->effective_start_date, '10', '', '', ''); ?></td>
 							<td><?php echo form::date_fieldAnyDay('effective_end_date', $$class->effective_end_date, '10', '', '', ''); ?></td>
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
		 <div id="pagination" style="clear: both;">
			<?php echo!(empty($pagination_statement)) ? $pagination_statement : "";
			?>
		 </div>
		 <!--END OF FORM -->
		</div>
	 </div>
	 <!--   end of coa_structure_id-->
	</div>
	<div id="content_bottom"></div>
 </div>
 <div id="content_right_right"></div>
</div>

</div>

<?php include_template('footer.inc') ?>