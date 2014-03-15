<div id="all_contents">
 <div id="content_left"></div>
 <div id="content_right">
	<div id="content_right_left">
	 <div id="content_top"></div>
	 <div id="content">
		<div id="structure">
		 <div id="payment_term_divId">
			<!--    START OF FORM HEADER-->
			<div class="error"></div><div id="loading"></div>
			<?php echo (!empty($show_message)) ? $show_message : ""; ?> 
			<!--    End of place for showing error messages-->

			<div id ="form_header">
			 <form action=""  method="post" id="payment_term_header"  name="payment_term_header">
				<div id="tabsHeader">
				 <div class="large_shadow_box"><span class="heading">Payment Term Header </span>
					<ul class="column four_column">
					 <li>
						<label><img id="payment_term_id_find_popup" class="showPointer" src="<?php echo HOME_URL; ?>themes/images/serach.png"/>
						 Payment Term Id : </label>
						<?php echo form::text_field_d('payment_term_id'); ?>
						 <img id="payment_term_id_show" class="showPointer" src="<?php echo HOME_URL; ?>themes/images/refresh.png"/>
					 </li>
					 <li><label>Payment Term : </label>
						<?php echo form::text_field_d('payment_term'); ?>
											 </li>
					 <li><label>Description : </label>
						<?php echo form::text_field_d('description'); ?>
					 </li>
					 <li><label>Prepayment : </label>
						<?php echo form::checkBox_field('prepayment_cb', $$class->prepayment_cb, 'prepayment_cb', $readonly); ?>
					 </li> 
					 <li><label>Ef Id : </label>
						<?php echo form::extra_field($$class->ef_id, '10', $readonly); ?>
					 </li>
					 <li><label>Status : </label>                      
						<?php echo form::status_field($$class->status, $readonly); ?>
					 </li>
					 <li><label>Revision : </label>
						<?php echo form::checkBox_field('rev_enabled_cb', $$class->rev_enabled_cb, 'rev_enabled_cb', $readonly); ?>
					 </li> 
					 <li><label>Rev Number : </label>
						<?php form::text_field_wid('rev_number'); ?>

					 </li> 
					</ul>
				 </div>

        </div>
			 </form>
			</div>

			<div id ="form_line" class="form_line"><span class="heading">PO Lines & Shipments </span>

			 <div id="tabsLine">
				<ul class="tabMain">
				 <li><a href="#tabsLine-1">Schedule</a></li>
				 <li><a href="#tabsLine-2">Discount</a></li>
				</ul>
				<div class="tabContainer">
				 <form action=""  method="post" id="payment_term_schedule_line"  name="payment_term_schedule_line">
					<div id="tabsLine-1" class="tabContent">
					 <table class="form_line_data_table">
						<thead> 
						 <tr>
							<th>Action</th>
							<th>Schedule Id</th>
							<th>Seq Number</th>
							<th>Percentage</th>
							<th>Due Days</th>
							<th>Due Dates</th>
							<th>Date of Month</th>
							<th>Ef id</th>
						 </tr>
						</thead>
						<tbody class="form_data_line_tbody payment_term_schedule_values" >
						 <?php
						 $count = 0;
						 foreach ($payment_term_schedule_object as $payment_term_schedule) {
							?>         
 						 <tr class="payment_term_schedule<?php echo $count ?>">
 							<td>    
 							 <ul class="inline_action">
 								<li class="add_row_img"><img  src="<?php echo HOME_URL; ?>themes/images/add.png"  alt="add new line" /></li>
 								<li class="remove_row_img"><img src="<?php echo HOME_URL; ?>themes/images/remove.png" alt="remove this line" /> </li>
 								<li><input type="checkbox" name="line_id_cb" value="<?php echo htmlentities($payment_term_schedule->payment_term_schedule_id); ?>"></li>           
 								<li><?php echo form::hidden_field('payment_term_id', $$class->payment_term_id); ?></li>
 							 </ul>
 							</td>
 							<td><?php form::text_field_wid2('payment_term_schedule_id'); ?></td>
 							<td><?php form::text_field_wid2('seq_number'); ?></td>
 							<td><?php form::text_field_wid2('amount_percentage'); ?></td>
 							<td><?php form::text_field_wid2('due_days'); ?></td>
 							<td><?php form::text_field_wid2('due_dates'); ?></td>
 							<td><?php form::text_field_wid2('due_date_of_month'); ?></td>
 							<td><?php form::text_field_wid2('ef_id'); ?></td>
 						 </tr>
							<?php
							$count = $count + 1;
						 }
						 ?>
						</tbody>
					 </table>
					</div>
				 </form>
				 <form action=""  method="post" id="payment_term_discount_line"  name="payment_term_discount_line">
					<div id="tabsLine-2" class="tabContent">
					 <table class="form_line_data_table">
						<thead> 
						 <tr>
							<th>Action</th>
							<th>Discount Id</th>
							<th>Seq Number</th>
							<th>Percentage</th>
							<th>Due Days</th>
							<th>Due Dates</th>
							<th>Date of Month</th>
							<th>Ef id</th>
						 </tr>
						</thead>
						<tbody class="form_data_line_tbody2 payment_term_discount_values">
						 <?php
						 $count = 0;
						 foreach ($payment_term_discount_object as $payment_term_discount) {
							?>         
 						 <tr class="payment_term_discount<?php echo $count ?>">
 							<td>    
 							 <ul class="inline_action">
 								<li class="add_row_img"><img  src="<?php echo HOME_URL; ?>themes/images/add.png"  alt="add new line" /></li>
 								<li class="remove_row_img"><img src="<?php echo HOME_URL; ?>themes/images/remove.png" alt="remove this line" /> </li>
 								<li><input type="checkbox" name="line_id_cb" value="<?php echo htmlentities($payment_term_schedule->payment_term_discount_id); ?>"></li>           
 								<li><?php echo form::hidden_field('payment_term_id', $$class->payment_term_id); ?></li>
 							 </ul>
 							</td>
 							<td><?php form::text_field_wid3('payment_term_discount_id'); ?></td>
 							<td><?php form::text_field_wid3('seq_number'); ?></td>
 							<td><?php form::text_field_wid3('discount_percentage'); ?></td>
 							<td><?php form::text_field_wid3('due_days'); ?></td>
 							<td><?php form::text_field_wid3('due_dates'); ?></td>
 							<td><?php form::text_field_wid3('due_date_of_month'); ?></td>
 							<td><?php form::text_field_wid3('ef_id'); ?></td>
 						 </tr>
							<?php
							$count = $count + 1;
						 }
						 ?>
						</tbody>
						<!--                  Showing a blank form for new entry-->

					 </table>
					</div>
				 </form>

				</div>
			 </div>

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
