<div id="all_contents">
 <div id="content_left"></div>
 <div id="content_right">
	<div id="content_right_left">
	 <div id="content_top"></div>
	 <div id="content">
		<div id="structure">
		 <div id="period_divId">
			<!--    START OF FORM HEADER-->
			<div class="error"></div><div id="loading"></div>
			<?php echo (!empty($show_message)) ? $show_message : ""; ?> 
			<!--    End of place for showing error messages-->

			<div id ="form_header">
			 <form action=""  method="post" id="gl_period"  name="gl_period">
				<div id="tabsHeader">
         <ul class="tabMain">
          <li><a href="#tabsHeader-1">Accounting Period</a></li>
          <li><a href="#tabsHeader-2">Encumbrance Period</a></li>
         </ul>
				 <div class="tabContainer">
					<div id="tabsHeader-1" class="tabContent">
					 <div class="large_shadow_box"> 
						<ul class="column five_column">
						 <li><label>Select Ledger : </label>
							<?php echo form::select_field_from_object('ledger_id', gl_ledger::find_all(), 'gl_ledger_id', 'ledger', $gl_period_object[0]->ledger_id, 'ledger_id'); ?>
							<a name="show" class="show ledger_id">
							 <img src="<?php echo HOME_URL; ?>themes/images/refresh.png"/></a> 
						 </li>
						 <li><label>Current Open Period : </label>
							<?php echo $cop_stmt; ?>
						 </li>
						 <li><label>Next Period Name: </label>
							<?php echo form::select_field_from_object('gl_calendar_id', $next_open_period, 'gl_calendar_id', 'name', '', 'new_gl_calendar_id', $readonly); ?>
						 </li>
						 <li><label>Next Period Status: </label>
							<?php echo form::text_field('status', 'AVAILABLE', '', '', '', '', 'status', 1); ?>
						 </li>
						 <li><input type="button" class="button" id="open_next_period" value="Open Next Period" 
												<?php echo ($readonly == 1) ? 'disabled' : ''; ?>				></li>
						</ul>
					 </div>
					</div>
					<div id="tabsHeader-2" class="tabContent">
					 <div> 
						<ul class="column five_column">
						 <li>
						 </li>
						</ul>
					 </div>
					</div>
				 </div>
				</div>
			 </form>
			</div>

			<div id="form_line" class="form_line"><span class="heading">Existing & Available Periods </span>
			 <form action=""  method="post" id="gl_period_line"  name="gl_period_line">
				<div id="tabsLine">
				 <ul class="tabMain">
					<li><a href="#tabsLine-1">Calendar View  </a></li>
					<li><a href="#tabsLine-2">Future </a></li>
				 </ul>
				 <div class="tabContainer"> 

					<div id="tabsLine-1" class="tabContent">
					 <table class="form_table">
						<thead> 
						 <tr>
							<th>Action</th>
							<th>Period Id</th>
							<th>Period Name</th>
							<th>Status</th>
							<th>Year</th>
							<th>Quarter</th>
							<th>Number</th>
							<th>From Date</th>
							<th>To Date</th>
							<th>Cal Name</th>
							<th>Cal Id</th>
						 </tr>
						</thead>
						<tbody class="form_data_line_tbody calendar_values" >
						 <?php
						 $count = 0;
						 foreach ($gl_period_object as $gl_period) {
							$class_second = 'gl_period';
							$$class_second = &$gl_period;
							?>         
 						 <tr class="calendar_line<?php echo $count ?>">
 							<td>    
 							 <ul class="inline_action">
 								<li class="add_row_img"><img  src="<?php echo HOME_URL; ?>themes/images/add.png"  alt="add" /></li>
 								<li class="remove_row_img"><img src="<?php echo HOME_URL; ?>themes/images/remove.png" alt="remove" /> </li>
 								<li><input type="checkbox" name="line_id_cb" value="<?php echo htmlentities($$class->gl_period_id); ?>">
									<?php echo form::hidden_field('ledger_id', $gl_period->ledger_id); ?></li>
 							 </ul>
 							</td>
 							<td><?php form::number_field_wid2sr('gl_period_id') ?></td>
							<td><?php form::text_field_wid2r('period_name') ?></td>
 							<td><?php
								echo form::select_field_from_object_ap(array('name' => 'status', 'ob' => gl_period::gl_period_status(),
										'ob_value' => 'option_line_code', 'ob_desc' => 'option_line_value', 'value' => $gl_period->status, 'disabled' => $gl_period->en_dis));
								?></td>
 							<td class="yearPicker"><?php form::number_field_wid2sr('year'); ?></td>
 							<td><?php form::number_field_wid2sr('quarter'); ?></td>
 							<td><?php form::number_field_wid2sr('number'); ?></td>
 							<td><?php echo form::date_fieldAnyDay_m('from_date', $$class_second->from_date, 1, 'date', '', 1); ?></td>
 							<td><?php echo form::date_fieldAnyDay_m('to_date', $$class_second->to_date, 1, 'date', '', 1); ?></td>
 							<td><?php echo form::text_field('cal_period_name', $gl_period->name, 15, '', 1, '', '', 1); ?></td>
 							<td><?php form::number_field_wid2sr('gl_calendar_id'); ?></td>
 						 </tr>
							<?php
							$count = $count + 1;
						 }
						 ?>
						</tbody>
					 </table>
					</div>
					<div id="tabsLine-2" class="tabContent">

					</div>

				 </div>

				</div>
			 </form>

			</div>
			<div id="pagination" style="clear: both;">
			 <?php echo!(empty($pagination_statement)) ? $pagination_statement : "";
			 ?>
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
