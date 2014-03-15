<div id="all_contents">
 <div id="content_left"></div>
 <div id="content_right">
	<div id="content_right_left">
	 <div id="content_top"></div>
	 <div id="content">
		<div id="structure">
		 <div id="subinventory_divId">
			<div id="subinventory_search">
			 <?php
			 if (empty($readonly)) {
				$search_form = search::search_form('subinventory', 'subinventory', 'business_search');
				if (!empty($pagination)) {
				 $pagination_statement = $pagination->show_pagination($pagination, 'subinventory', $pageno, $query_string);
				}
				echo!(empty($search_form)) ? $search_form : "";
			 }
			 ?>
			</div>
			<div id="form_top">
			</div>
			<!--    START OF FORM HEADER-->
			<div class="error"></div><div id="loading"></div>
			<div class="show_loading_small"></div>
			<?php echo (!empty($show_message)) ? $show_message : ""; ?> 
			<!--    End of place for showing error messages-->
			<div id ="form_header">
			 <form action=""  method="post" id="subinventory"  name="subinventory">
				<div id ="form_line" class="form_line"><span class="heading">Sub Inventory Details </span>
				 <div id="tabsLine">
					<?php echo subinventory::$tab_header ?>
					<div class="tabContainer">
					 <div id="tabsLine-1" class="tabContent">
						<table class="form_table">
						 <?php echo subinventory::$tabs_header1_tr ?>
						 <tbody class="subinventory_values">
							<?php
							$count = 0;
							foreach ($search_result as $subinventory) {
							 ?>         
 							<tr class="subinventory<?php echo $count ?>">
 							 <td>    
 								<ul class="inline_action">
 								 <li class="add_row_img"><img  src="<?php echo HOME_URL; ?>themes/images/add.png"  alt="add new line" /></li>
 								 <li class="remove_row_img"><img src="<?php echo HOME_URL; ?>themes/images/remove.png" alt="remove this line" /> </li>
 								 <li><input type="checkbox" name="line_id_cb" value="<?php echo htmlentities($subinventory->subinventory_id); ?>"></li>           
 								</ul>
 							 </td>
 							 <td>
								 <?php form::text_field_wid('subinventory_id'); ?>
 							 </td>
 							 <td>
								 <?php echo form::select_field_from_object('org_id', org::find_all_inventory(), 'org_id', 'org', $$class->org_id, 'org_id', $readonly); ?>
 							 </td>
 							 <td>
								 <?php echo form::select_field_from_object('type', subinventory::subinventory_type(), 'option_line_code', 'option_line_code', $$class->type, 'type', $readonly); ?>
 							 </td>
 							 <td>
								 <?php form::text_field_wid('subinventory'); ?>
 							 </td>
 							 <td>
								 <?php form::text_field_wid('description'); ?>
 							 </td>
 							 <td>  
								 <?php echo form::select_field_from_object('locator_control', subinventory::locator_control(), 'option_line_code', 'option_line_code', $$class->locator_control, 'locator_control', $readonly); ?>	 
 							 </td>
 							 <td>
								 <?php echo form::checkBox_field('allow_negative_balance_cb' . $count, $$class->allow_negative_balance_cb, 'allow_negative_balance_cb', $readonly); ?>
 							 </td>
 							</tr>
							 <?php
							 $count = $count + 1;
							}
							?>
						 </tbody>
						</table>
					 </div>
					 <div id="tabsLine-2" class="scrollElement" class="tabContent">
						<table class="form_table">
						 <?php echo subinventory::$tabs_header2_tr ?>
						 <tbody class="subinventory_values">
							<?php
							$count = 0;
							foreach ($search_result as $subinventory) {
							 ?>         
 							<tr class="subinventory<?php echo $count ?>">
 							 <td>
								 <?php form::text_field_wid('default_cost_group'); ?>
 							 </td>
 							 <td>
								 <?php form::account_field('material_ac_id'); ?>
 							 </td>
 							 <td>
								 <?php form::account_field('material_oh_ac_id'); ?>
 							 </td>
 							 <td>
								 <?php form::account_field('overhead_ac_id'); ?>
 							 </td>
 							 <td>
								 <?php form::account_field('resource_ac_id'); ?>
 							 </td>
 							 <td>
								 <?php form::account_field('osp_ac_id'); ?>
 							 </td>
 							 <td>
								 <?php form::account_field('expense_ac_id'); ?>
 							 </td> 
 							</tr>
							 <?php
							 $count = $count + 1;
							}
							?>
						 </tbody>
						 <!--                  Showing a blank form for new entry-->

						</table>
					 </div>
					 <div id="tabsLine-3" class="tabContent">
						<table class="form_table" >
						 <?php echo subinventory::$tabs_header3_tr ?>
						 <tbody class="subinventory_values">
							<?php
							$count = 0;
							foreach ($search_result as $subinventory) {
							 ?>         
 							<tr class="subinventory<?php echo $count ?>">
 							 <td>
								 <?php echo form::extra_field($$class->ef_id, '10', $readonly); ?>
 							 </td>
 							 <td>                      
								 <?php echo form::status_field($$class->status, $readonly); ?>
 							 </td>
 							 <td>
								 <?php echo form::checkBox_field('rev_enabled_cb' . $count, $$class->rev_enabled_cb, 'rev_enabled_cb', $readonly); ?>
 							 </td> 
 							 <td>
								 <?php form::text_field_wid('rev_number'); ?>

 							 </td> 

 							</tr>
							 <?php
							 $count = $count + 1;
							}
							?>
						 </tbody>
						 <!--                  Showing a blank form for new entry-->

						</table>
					 </div>
					</div>
				 </div>
				</div> 
			 </form>
			</div>
			<!--END OF FORM HEADER-->
			<div id="pagination" style="clear: both;">
			 <?php echo!(empty($pagination_statement)) ? $pagination_statement : "";
			 ?>
			</div>
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
