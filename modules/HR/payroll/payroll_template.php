<div id="all_contents">
 <div id="content_left"></div>
 <div id="content_right">
	<div id="content_right_left">
	 <div id="content_top"></div>
	 <div id="content">
		<div id="structure">
		 <div id="mdm_price_list_divId">
			<!--    START OF FORM HEADER-->
			<div class="error"></div><div id="loading"></div>
			<?php echo (!empty($show_message)) ? $show_message : ""; ?> 
			<!--    End of place for showing error messages-->
			<div id="form_all">
			 <form action=""  method="post" id="mdm_price_list_header"  name="mdm_price_list_header">
				<div id ="form_header">
				 <div id="tabsHeader">
					<ul class="tabMain">
					 <li><a href="#tabsHeader-1">Basic Info</a></li>
					 <li><a href="#tabsHeader-2">Other</a></li>
					</ul>
					<div class="tabContainer">
					 <div id="tabsHeader-1" class="tabContent">
						<div class="large_shadow_box"> 
						 <ul class="column four_column">
							<li>
							 <label><img src="<?php echo HOME_URL; ?>themes/images/serach.png" class="mdm_price_list_header_id select_popup clickable">
								Price List Id : </label>
							 <?php echo form::number_field_drs('mdm_price_list_header_id'); ?>
							 <a name="show" class="show mdm_price_list_header_id">
								<img src="<?php echo HOME_URL; ?>themes/images/refresh.png"/></a> 
							</li>
							<li><label>Prices List : </label>
							 <?php echo form::text_field_dm('price_list'); ?>
							</li>
							<li><label>Module* : </label>
							 <?php echo form::select_field_from_array('module_name', mdm_price_list_header::$module_a, $$class->module_name, 'module_name', $readonly); ?>
							</li>
							<li><label>Description : </label>
							 <?php echo form::text_field_dm('description'); ?>
							</li>
							<li><label>Currency : </label>
							 <?php echo form::select_field_from_object('currency_code', option_header::currencies(), 'option_line_code', 'option_line_value', $$class->currency_code, 'currency_code', $readonly, '', '', 1); ?>
							</li>
						 </ul>
						</div>
					 </div>
					 <div id="tabsHeader-2" class="tabContent">
						<div> 
						 <ul class="column four_column">
							<li><label>Status : </label><?php echo form::status_field_d('status'); ?></li>
							<li><label>Multi Currency : </label>
							 <?php
							 $f = new inoform();
							 echo $f->checkBox_field('allow_mutli_currency_cb', $$class->allow_mutli_currency_cb);
							 ?>
							</li>
							<li><label>Conversion Type : </label>
               <?php echo $f->select_field_from_object('currency_conversion_type', gl_currency_conversion::currency_conversion_type(), 'option_line_code', 'option_line_code', $$class->currency_conversion_type, 'currency_conversion_type', '', 1, $readonly); ?>
            	</li>
						 </ul>
						</div>
					 </div>
					</div>
				 </div>
				</div>
			 </form>
			 <div id ="form_line" class="form_line"><span class="heading">Price List Details </span>
				<div id="tabsLine">
				 <ul class="tabMain">
					<li><a href="#tabsLine-1">Values</a></li>
					<li><a href="#tabsLine-2">Prices</a></li>
					<li><a href="#tabsLine-3">Restrictions</a></li>
				 </ul>
				 <div class="tabContainer"> 
					<form action=""  method="post" id="mdm_price_list_line_line"  name="mdm_price_list_line_line">
					 <div id="tabsLine-1" class="tabContent">
						<table class="form_table">
						 <thead> 
							<tr>
							 <th>Action</th>
							 <th>Line Id</th>
							 <th>Type</th>
							 <th>Item</th>
							 <th>Description</th>
							 <th>UOM</th>
							 <th>Start Date</th>
							 <th>End Date</th>
							</tr>
						 </thead>
						 <tbody class="form_data_line_tbody mdm_price_list_line_values" >
							<?php
							$count = 0;
							foreach ($mdm_price_list_line_object as $mdm_price_list_line) {
							 ?>         
 							<tr class="mdm_price_list_line<?php echo $count ?>">
 							 <td>    
 								<ul class="inline_action">
 								 <li class="add_row_img"><img  src="<?php echo HOME_URL; ?>themes/images/add.png"  alt="add new line" /></li>
 								 <li class="remove_row_img"><img src="<?php echo HOME_URL; ?>themes/images/remove.png" alt="remove this line" /> </li>
 								 <li><input type="checkbox" name="line_id_cb" value="<?php echo htmlentities($mdm_price_list_line->mdm_price_list_line_id); ?>"></li>           
 								 <li><?php echo form::hidden_field('mdm_price_list_header_id', $$class->mdm_price_list_header_id); ?></li>
 								</ul>
 							 </td>
 							 <td><?php form::number_field_wid2sr('mdm_price_list_line_id'); ?></td>
               <td><?php echo $f->select_field_from_array('line_type', mdm_price_list_line::$line_type_a, $$class_second->line_type); ?></td>
               <td><?php echo $f->hidden_field('item_id_m', $$class_second->item_id_m);
                form::text_field_wid2('item_number', 'select_item_number'); ?>
 								<img src="<?php echo HOME_URL; ?>themes/images/serach.png" class="select_item_number_only select_popup"></td>
 							 <td><?php form::text_field_wid2('item_description'); ?></td>
 							 <td><?php
								 echo form::select_field_from_object('uom_id', uom::find_all(), 'uom_id', 'uom_name', $$class_second->uom_id, '', '', 'uom_id');
								 ?></td>
							 <td><?php echo $f->date_fieldAnyDay('effective_start_date', $$class_second->effective_start_date); ?></td>
 							 <td><?php echo $f->date_fieldAnyDay('effective_end_date', $$class_second->effective_end_date); ?></td>
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
							 <th>Unit Price</th>
							 <th>Formula</th>
							</tr>
						 </thead>
						 <tbody class="form_data_line_tbody mdm_price_list_line_values" >
							<?php
							$count = 0;
							foreach ($mdm_price_list_line_object as $mdm_price_list_line) {
							 ?>         
 							<tr class="mdm_price_list_line<?php echo $count ?>">
							 <td><?php $f->text_field_wid2('unit_price'); ?></td>
 							 <td><?php $f->text_field_wid2('formula'); ?></td>
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
							 <th>Inventory Org</th>
							 </tr>
						 </thead>
						 <tbody class="form_data_line_tbody mdm_price_list_line_values" >
							<?php
							$count = 0;
							foreach ($mdm_price_list_line_object as $mdm_price_list_line) {
							 ?>         
 							<tr class="mdm_price_list_line<?php echo $count ?>">
							 <td><?php echo $f->select_field_from_object('org_id', org::find_all_inventory(), 'org_id', 'org', $$class_second->org_id, '', '', '', $readonly); ?></td>
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
			 <div id="pagination" style="clear: both;">
				<?php echo!(empty($pagination_statement)) ? $pagination_statement : "";
				?>
			 </div>
			</div>
			<!--END OF FORM -->
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