<div id="all_contents">
 <div id="content_left"></div>
 <div id="content_right">
	<div id="content_right_left">
	 <div id="content_top"></div>
	 <div id="content">
		<div id="coa_structure_id">
		 <div id="calendar_divId">
			<!--    START OF FORM HEADER-->
			<div class="error"></div><div id="loading"></div>
			<?php echo (!empty($show_message)) ? $show_message : ""; ?> 
			<!--    End of place for showing error messages-->
			<div id="form_all">
			 <div id="form_headerDiv">
				<form action=""  method="post" id="calendar_line"  name="calendar_line">
				 <table class="form_table">
					<tr>
					 <td>	<label>Calendar : </label>
						<?php echo form::select_field_from_object('option_line_code', gl_calendar::gl_calendar_names(), 'option_line_code', 'option_line_value', $calendar_object[0]->option_line_code, 'option_line_code', $readonly); ?>
						<a name="show" class="show gl_calendar">
						 <img src="<?php echo HOME_URL; ?>themes/images/refresh.png"/></a> 
					 </td>
					</tr>
				 </table>

				 <div id ="form_line" class="form_line"><span class="heading">Calendar Period Details </span>
					<div id="tabsLine">
					 <ul class="tabMain">
						<li><a href="#tabsLine-1">Basics - View Only </a></li>
						<li><a href="#tabsLine-2">Effectivity </a></li>
					 </ul>
					 <div class="tabContainer"> 

						<div id="tabsLine-1" class="tabContent">
						 <table class="form_table">
							<thead> 
							 <tr>
								<th>Action</th>
								<th>Id</th>
								<th>Period Type</th>
								<th>Prefix</th>
								<th>Year</th>
								<th>Quarter</th>
								<th>Number</th>
								<th>From Date</th>
								<th>To Date</th>
								<th>Name</th>
							 </tr>
							</thead>
							<tbody class="form_data_line_tbody calendar_values" >
							 <?php
							 $count = 0;
							 foreach ($calendar_object as $gl_calendar) {
								?>         
 							 <tr class="calendar_line<?php echo $count ?>">
 								<td>    
 								 <ul class="inline_action">
 									<li class="add_row_img"><img  src="<?php echo HOME_URL; ?>themes/images/add.png"  alt="add new line" /></li>
 									<li class="remove_row_img"><img src="<?php echo HOME_URL; ?>themes/images/remove.png" alt="remove this line" /> </li>
 									<li><input type="checkbox" name="line_id_cb" value="<?php echo htmlentities($$class->gl_calendar_id); ?>"></li>           
 									<li><?php echo form::hidden_field('option_line_code', $$class->option_line_code); ?></li>
 								 </ul>
 								</td>
 								<td><?php form::number_field_drs('gl_calendar_id') ?></td>
 								<td><?php echo form::select_field_from_object('calendar_type', gl_calendar::period_types(), 'option_line_code', 'option_line_value', $$class->calendar_type, '', $readonly); ?></td>
 								<td><?php form::text_field_widsm('name_prefix'); ?></td>
 								<td class="yearPicker"><?php form::number_field_widsm('year'); ?></td>
 								<td><?php form::number_field_widsm('quarter'); ?></td>
 								<td><?php form::number_field_widsm('number'); ?></td>
 								<td><?php echo form::date_fieldAnyDay_m('from_date', $$class->from_date, 1, 'date'); ?></td>
 								<td><?php echo form::date_fieldAnyDay_m('to_date', $$class->to_date, 1, 'date'); ?></td>
 								<td><?php form::text_field_widsrm('name'); ?></td>
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
								<th>Adjusting Period</th>
								<th>EF id</th>
							 </tr>
							</thead>
							<tbody class="form_data_line_tbody calendar_values" >
							 <?php
							 $count = 0;
							 foreach ($calendar_object as $calendar) {
								?>         
 							 <tr class="calendar_line<?php echo $count ?>">
 								<td><?php echo form::checkBox_field_d('adjustment_period_cb'); ?></td>
 								<td><?php echo form::number_field_wids('ef_id'); ?></td>
 							 </tr>
								<?php
								$count = $count + 1;
							 }
							 ?>
							</tbody>
						 </table>
						</div>

					 </div>

					</div>
				 </div> 
				</form>
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