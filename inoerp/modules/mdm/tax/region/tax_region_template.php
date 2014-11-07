<div id="all_contents">
 <div id="content_left"></div>
 <div id="content_right">
	<div id="content_right_left">
	 <div id="content_top"></div>
	 <div id="content">
		<div id="coa_structure_id">
		 <div id="tax_region_divId">
			<!--    START OF FORM HEADER-->
			<div class="error"></div><div id="loading"></div>
			<?php echo (!empty($show_message)) ? $show_message : ""; ?> 
			<!--    End of place for showing error messages-->
			<div id="form_all">
			 <div id="form_headerDiv">
				<form action=""  method="post" id="mdm_tax_region_line"  name="tax_region_line">
				 <table class="form_table">
					<tr><td>
						<label>Country :</label>
						<?php echo form::select_field_from_object('country_code', mdm_tax_region::country(), 'option_line_code', 'option_line_value', $country_code_h, 'country_code', $readonly1); ?>
						<a name="show" class="show mdm_tax_region clickable">
						 <img src="<?php echo HOME_URL; ?>themes/images/refresh.png"/></a> 
					 </td></tr>
				 </table>
				 <div id ="form_line" class="mdm_tax_region"><span class="heading">Region Details </span>
					<div id="tabsLine">
					 <ul class="tabMain">
						<li><a href="#tabsLine-1">Location </a></li>
						<li><a href="#tabsLine-2">Reporting </a></li>
					 </ul>
					 <div class="tabContainer"> 

						<div id="tabsLine-1" class="tabContent">
						 <table class="form_table">
							<thead> 
							 <tr>
								<th>Action</th>
								<th>Id</th>
								<th>Country Code</th>
								<th>State</th>
								<th>City</th>
								<th>Region Name</th>
								<th>Description</th>
							 </tr>
							</thead>
							<tbody class="form_data_line_tbody tax_region_values" >
							 <?php
							 $count = 0;
							 foreach ($tax_region_object as $mdm_tax_region) {
								if(empty($mdm_tax_region->country_code)){
								 $mdm_tax_region->country_code = $country_code_h;
								}
								?>         
 							 <tr class="tax_region_line<?php echo $count ?>">
 								<td>    
 								 <ul class="inline_action">
 									<li class="add_row_img"><img  src="<?php echo HOME_URL; ?>themes/images/add.png"  alt="add new line" /></li>
 									<li class="remove_row_img"><img src="<?php echo HOME_URL; ?>themes/images/remove.png" alt="remove this line" /> </li>
 									<li><input type="checkbox" name="line_id_cb" value="<?php echo htmlentities($$class->mdm_tax_region_id); ?>"></li>           
 									<li><?php echo form::hidden_field('country_code', $country_code_h); ?></li>
 								 </ul>
 								</td>
 								<td><?php form::number_field_drs('mdm_tax_region_id') ?></td>
								<td><?php $f->text_field_widrm('country_code','line_data'); ?></td>
								<td><?php $f->text_field_wid('state','dontCopy'); ?></td>
 								<td><?php $f->text_field_wid('city','dontCopy'); ?></td>
 								<td><?php $f->text_field_wid('tax_region_name','dontCopy'); ?></td>
 								<td><?php $f->text_field_wid('description','dontCopy'); ?></td>
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
								<th>Status</th>
								<th>Regime</th>
								<th>Jurisdiction</th>
							 </tr>
							</thead>
							<tbody class="form_data_line_tbody tax_region_values" >
							 <?php
							 $count = 0;
							 foreach ($tax_region_object as $tax_region) {
								?>         
 							 <tr class="tax_region_line<?php echo $count ?>">
 								<td><?php $f->status_field_d('status'); ?></td>
 								<td><?php form::text_field_wid('tax_regime'); ?></td>
 								<td><?php form::text_field_wid('tax_jurisdiction'); ?></td>
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