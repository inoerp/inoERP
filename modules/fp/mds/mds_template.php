<div id="all_contents">
 <div id="content_left"></div>
 <div id="content_right">
	<div id="content_right_left">
	 <div id="content_top"></div>
	 <div id="content">
		<div id="structure">
		 <div id="mds_divId">
			<!--    START OF FORM HEADER-->
			<div class="error"></div><div id="loading"></div>
			<?php echo (!empty($show_message)) ? $show_message : ""; ?> 
			<!--    End of place for showing error messages-->

			<div id ="form_header"><span class="heading">MDS Header  </span>
			 <form action=""  method="post" id="mds_header"  name="mds_header">
				<div id="tabsHeader">
         <ul class="tabMain">
          <li><a href="#tabsHeader-1">Basic Info</a></li>
					<li><a href="#tabsHeader-2">Actions</a></li>
         </ul>
				 <div class="tabContainer">
					<div id="tabsHeader-1" class="tabContent">
					 <div class="large_shadow_box"> 
						<ul class="column four_column">
						 <li><label><img src="<?php echo HOME_URL; ?>themes/images/serach.png" class="mds_header_id select_popup clickable">
							 MDS Id : </label>
							<?php echo form::text_field('fp_mds_header_id', $$class->fp_mds_header_id, '15', '25', '', 'System Number', 'fp_mds_header_id', $readonly) ?>
							<a name="show" href="form.php?class_name=fp_mds_header" class="show fp_mds_header_id">	
							 <img src="<?php echo HOME_URL; ?>themes/images/refresh.png" class="clickable"></a> 
						 </li>
						 <li><label>Inventory Org (1)</label>
							<?php echo $f->select_field_from_object('org_id', org::find_all_inventory(), 'org_id', 'org', $$class->org_id, 'org_id', '', 1, $readonly); ?>
						 </li>
						 <li><label>MDS (2): </label>
							<?php form::text_field_dm('mds_name'); ?>
						 </li>
						 <li><label>Description: </label>
							<?php form::text_field_dm('description'); ?>
						 </li>
						 <li><label>Source List (3)</label>
							<?php echo $f->select_field_from_object('fp_source_list_header_id', fp_source_list_header::find_all_demandPlan(), 'fp_source_list_header_id', 'source_list', $$class->fp_source_list_header_id, '', '', 1, $readonly); ?>
						 </li>
						 <li><label>Include SO: </label>
							<?php echo $f->checkBox_field_d('include_so_cb'); ?>
						 <li><label>Status : </label>                      
							<?php echo form::status_field($$class->status, $readonly); ?>
						 </li>
						</ul>
					 </div>
					</div>
					<div id="tabsHeader-2" class="tabContent">
					 <div> 
						<ul class="column five_column">
						 <li><label>Action</label>
							<select name="mds_action[]" class=" select  mds_action" id="mds_action" >
							 <option value="" ></option>
							 <option value="LOAD_MDS" >Load MDS</option>
							</select>
						 </li>
						</ul>

						<div id="comment" class="shoe_comments">
						</div>
					 </div>
					</div>
				 </div>

				</div>
			 </form>
			</div>

			<div id="form_line" class="form_line"><span class="heading">MDS Lines </span>
			 <form action=""  method="post" id="mds_line"  name="mds_line">
				<div id="tabsLine">
				 <ul class="tabMain">
					<li><a href="#tabsLine-1">Main</a></li>
					<li><a href="#tabsLine-2">Future</a></li>
				 </ul>
				 <div class="tabContainer">
					<div id="tabsLine-1" class="tabContent">
					 <table class="form_line_data_table">
						<thead> 
						 <tr>
							<th>Action</th>
							<th>Seq#</th>
							<th>Line Id</th>
							<th>Item Id</th>
							<th>Item Number</th>
							<th>Date</th>
							<th>Source Type</th>
							<th>Source Header</th>
							<th>Source Line</th>
							<th>Quantity</th>
						 </tr>
						</thead>
						<tbody class="form_data_line_tbody">
						 <?php
						 $count = 0;
						 foreach ($fp_mds_line_object as $fp_mds_line) {
							?>         
 						 <tr class="mds_line<?php echo $count ?>">
 							<td>    
 							 <ul class="inline_action">
 								<li class="add_row_img"><img  src="<?php echo HOME_URL; ?>themes/images/add.png"  alt="add new line" /></li>
 								<li class="remove_row_img"><img src="<?php echo HOME_URL; ?>themes/images/remove.png" alt="remove this line" /> </li>
 								<li><input type="checkbox" name="line_id_cb" value="<?php echo htmlentities($$class_second->fp_mds_line_id); ?>"></li>           
 								<li><?php echo form::hidden_field('fp_mds_header_id', $$class->fp_mds_header_id); ?></li>
 							 </ul>
 							</td>
 							<td><?php $f->seq_field_d($count); ?></td>
 							<td><?php form::text_field_wid2sr('fp_mds_line_id'); ?></td>
 							<td><?php form::text_field_wid2sr('item_id_m'); ?></td>
 							<td><?php form::text_field_wid2('item_number', 'select_item_number'); ?>
 							 <img src="<?php echo HOME_URL; ?>themes/images/serach.png" class="select_item_number select_popup"></td>
 							<td><?php echo $f->date_fieldAnyDay('demand_date', $$class_second->demand_date); ?></td>
 							<td><?php $f->text_field_wid2s('source_type'); ?></td>
 							<td><?php $f->text_field_wid2s('source_header_id'); ?></td>
 							<td><?php $f->text_field_wid2s('source_line_id'); ?></td>
 							<td><?php echo $f->number_field('quantity', $$class_second->quantity); ?></td>
 						 </tr>
							<?php
							$count = $count + 1;
						 }
						 ?>
						</tbody>
					 </table>
					</div>
					<div id="tabsLine-2" class="scrollElement tabContent">
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
