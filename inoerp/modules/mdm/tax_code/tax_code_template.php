<div id="all_contents">
 <div id="content_left"></div>
 <div id="content_right">
	<div id="content_right_left">
	 <div id="content_top"></div>
	 <div id="content">
		<div id="coa_structure_id">
		 <div id="tax_code_divId">
			<!--    START OF FORM HEADER-->
			<div class="error"></div><div id="loading"></div>
			<?php echo (!empty($show_message)) ? $show_message : ""; ?> 
			<!--    End of place for showing error messages-->
			<div id="form_all">
			 <div id="form_headerDiv">
				<form action=""  method="post" id="mdm_tax_code_line"  name="tax_code_line">
				 <table class="form_table">
					<tr><td>
						<label>Business Org :</label>
						<?php echo form::select_field_from_object('org_id', org::find_all_business(), 'org_id', 'org', $org_id_h, 'org_id', $readonly1); ?>
						<a name="show" class="show mdm_tax_code clickable">
						 <img src="<?php echo HOME_URL; ?>themes/images/refresh.png"/></a> 
					 </td></tr>
				 </table>
				 <div id ="form_line" class="mdm_tax_code"><span class="heading">Tax Details </span>
					<div id="tabsLine">
					 <ul class="tabMain">
						<li><a href="#tabsLine-1">Tax Code </a></li>
						<li><a href="#tabsLine-2">Control </a></li>
						<li><a href="#tabsLine-3">Reporting </a></li>
					 </ul>
					 <div class="tabContainer"> 

						<div id="tabsLine-1" class="tabContent">
						 <table class="form_table">
							<thead> 
							 <tr>
                
								<th>Action</th>
                <th>Seq#</th>
								<th>Id</th>
								<th>Code</th>
								<th>Type</th>
								<th>Description</th>
								<th>In or Out</th>
								<th>Dr or Cr </th>
								<th>Calculation</th>
								<th>Percentage</th>
								<th>Amount</th>
							 </tr>
							</thead>
							<tbody class="form_data_line_tbody tax_code_values" >
							 <?php
							 $count = 0;
							 foreach ($tax_code_object as $mdm_tax_code) {
								?>         
 							 <tr class="tax_code_line<?php echo $count ?>">
 								<td>    
 								 <ul class="inline_action">
 									<li class="add_row_img"><img  src="<?php echo HOME_URL; ?>themes/images/add.png"  alt="add new line" /></li>
 									<li class="remove_row_img"><img src="<?php echo HOME_URL; ?>themes/images/remove.png" alt="remove this line" /> </li>
 									<li><input type="checkbox" name="line_id_cb" value="<?php echo htmlentities($$class->mdm_tax_code_id); ?>"></li>           
 									<li><?php echo form::hidden_field('org_id', $org_id_h); ?></li>
 								 </ul>
 								</td>
                <td><?php $f->seq_field_d($count) ?></td>
 								<td><?php form::number_field_drs('mdm_tax_code_id') ?></td>
 								<td><?php form::text_field_widm('tax_code'); ?></td>
 								<td><?php echo form::select_field_from_object('tax_type', mdm_tax_code::tax_type(), 'option_line_code', 'option_line_value', $$class->tax_type, '', $readonly); ?></td>
 								<td><?php form::text_field_wid('description'); ?></td>
 								<td><?php echo $f->select_field_from_array('in_out', mdm_tax_code::$in_out_a, $$class->in_out, 'in_out', '', '', $readonly, $readonly1) ?></td>
 								<td><?php echo $f->select_field_from_array('dr_cr', mdm_tax_code::$dr_cr_a, $$class->dr_cr, 'dr_cr', '', '', $readonly, $readonly1) ?></td>
 								<td><?php echo $f->select_field_from_array('calculation_method', mdm_tax_code::$calculation_method_a, $$class->calculation_method, 'calculation_method', '', '', $readonly, $readonly1) ?></td>
 								<td><?php form::number_field_ds('percentage') ?></td>
 								<td><?php form::number_field_ds('tax_amount') ?></td>
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
                <th>Seq#</th>
								<th>Start Date</th>
								<th>End Date</th>
								<th>Account</th>
								<th>Ad hoc Rate</th>
								<th>Exemption</th>
								<th>Status</th>
							 </tr>
							</thead>
							<tbody class="form_data_line_tbody tax_code_values" >
							 <?php
							 $count = 0;
							 foreach ($tax_code_object as $tax_code) {
								?>         
 							 <tr class="tax_code_line<?php echo $count ?>">
                <td><?php $f->seq_field_d($count) ?></td>
 								<td><?php
									echo $f->date_fieldAnyDay_m('effective_start_date', $$class->effective_start_date,'');
									?></td>
 								<td><?php echo $f->date_fieldAnyDay('effective_end_date', $$class->effective_end_date); ?></td>
 								<td><?php $f->ac_field_dm('tax_ac_id'); ?></td>
 								<td><?php $f->checkBox_field_d('allow_adhoc_rate_cb'); ?></td>
 								<td><?php $f->checkBox_field_d('allow_tax_exemptions_cb'); ?></td>
								<td><?php $f->status_field_d('status'); ?></td>
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
                <th>Seq#</th>
								<th>Regime</th>
								<th>Jurisdiction</th>
								<th>Printed Name</th>
								<th>Offset Tax</th>
							 </tr>
							</thead>
							<tbody class="form_data_line_tbody tax_code_values" >
							 <?php
							 $count = 0;
							 foreach ($tax_code_object as $tax_code) {
								?>         
 							 <tr class="tax_code_line<?php echo $count ?>">
                <td><?php $f->seq_field_d($count) ?></td>
 								<td><?php form::text_field_wid('tax_regime'); ?></td>
								<td><?php form::text_field_wid('tax_jurisdiction'); ?></td>
								<td><?php form::text_field_wid('printed_tax_name'); ?></td>
								<td><?php form::text_field_wid('offset_tax_code'); ?></td>
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