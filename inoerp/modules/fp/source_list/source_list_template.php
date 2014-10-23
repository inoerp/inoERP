<div id="all_contents">
 <div id="content_left"></div>
 <div id="content_right">
	<div id="content_right_left">
	 <div id="content_top"></div>
	 <div id="content">
		<div id="structure">
		 <div id="source_list_divId">
			<!--    START OF FORM HEADER-->
			<div class="error"></div><div id="loading"></div>
			<?php echo (!empty($show_message)) ? $show_message : ""; ?> 
			<!--    End of place for showing error messages-->

			<div id ="form_header"><span class="heading">Source List Header  </span>
			 <form action=""  method="post" id="source_list_header"  name="source_list_header">
				<div id="tabsHeader">
         <ul class="tabMain">
          <li><a href="#tabsHeader-1">Basic Info</a></li>
         </ul>
				 <div class="tabContainer">
					<div id="tabsHeader-1" class="tabContent">
					 <div class="large_shadow_box"> 
						<ul class="column four_column">
						 <li><label><img src="<?php echo HOME_URL; ?>themes/images/serach.png" class="source_list_header_id select_popup clickable">
							 Source List Id : </label>
							<?php echo $f->text_field_dr('fp_source_list_header_id') ?>
							<a name="show" href="form.php?class_name=fp_source_list_header" class="show fp_source_list_header_id">	
							 <img src="<?php echo HOME_URL; ?>themes/images/refresh.png" class="clickable"></a> 
						 </li>
						 <li><label>Inventory Org (1)</label>
							<?php echo $f->select_field_from_object('org_id', org::find_all_inventory(), 'org_id', 'org', $$class->org_id, 'org_id', '', 1, $readonly); ?>
						 </li>
						 <li><label>Type (2)</label>
							<?php echo $f->select_field_from_object('source_list_type', fp_source_list_header::source_list_type(), 'option_line_code', 'option_line_value', $$class->source_list_type, 'source_list_type', '', 1, $readonly); ?>
						 </li>
						 <li><label>Source List (3): </label>
							<?php form::text_field_dm('source_list'); ?>
						 </li>
						 <li><label>Description: </label>
							<?php form::text_field_d('description'); ?>
						 </li>
						 <li><label>Status : </label>                      
							<?php echo form::status_field($$class->status, $readonly); ?>
						 </li>
						</ul>
					 </div>
					</div>
				 </div>

				</div>
			 </form>
			</div>

			<div id="form_line" class="form_line"><span class="heading">Source List Lines </span>
			 <form action=""  method="post" id="source_list_line"  name="source_list_line">
				<div id="tabsLine">
				 <ul class="tabMain">
					<li><a href="#tabsLine-1">Main</a></li>
				 </ul>
				 <div class="tabContainer">
					<div id="tabsLine-1" class="tabContent">
					 <table class="form_line_data_table">
						<thead> 
						 <tr>
							<th>Action</th>
							<th>Line Id</th>
							<th>Type</th>
							<th>Source List</th>
							<th>Comments</th>
						 </tr>
						</thead>
						<tbody class="form_data_line_tbody">
						 <?php
						 $count = 0;
						 foreach ($fp_source_list_line_object as $fp_source_list_line) {
							?>         
 						 <tr class="source_list_line<?php echo $count ?>">
 							<td>    
 							 <ul class="inline_action">
 								<li class="add_row_img"><img  src="<?php echo HOME_URL; ?>themes/images/add.png"  alt="add new line" /></li>
 								<li class="remove_row_img"><img src="<?php echo HOME_URL; ?>themes/images/remove.png" alt="remove this line" /> </li>
 								<li><input type="checkbox" name="line_id_cb" value="<?php echo htmlentities($$class_second->fp_source_list_line_id); ?>"></li>           
 								<li><?php echo form::hidden_field('fp_source_list_header_id', $$class->fp_source_list_header_id); ?></li>
 							 </ul>
 							</td>
 							<td><?php form::text_field_wid2sr('fp_source_list_line_id'); ?></td>
							<td><?php echo $f->select_field_from_object('source_list_line_type', fp_source_list_line::source_list_line_type(), 'option_line_code', 'option_line_value', $$class_second->source_list_line_type, '', '', 1, $readonly); ?></td>
							<td><?php echo $f->select_field_from_object('source_list_id', fp_forecast_header::find_all(), 'fp_forecast_header_id', 'forecast', $$class_second->source_list_id, '', '', 1, $readonly); ?></td>
							<td><?php form::text_field_wid2('description'); ?></td>
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
			 </form>
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
