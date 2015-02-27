<div id="all_contents">
<div id="structure">
		 <div id="locator_divId">
			<div id="locator_search">
			 <?php
			 if (empty($readonly)) {
				if (property_exists($$class, 'option_lists')) {
				 $s->option_lists = $$class->option_lists;
				}
				$s->setProperty('_search_order_by', filter_input(INPUT_GET, 'search_order_by'));
				$s->setProperty('_search_asc_desc', filter_input(INPUT_GET, 'search_asc_desc'));
				$s->setProperty('_per_page', filter_input(INPUT_GET, 'per_page'));
				$s->setProperty('_searching_class', $class);
				$s->setProperty('_initial_search_array', $$class->initial_search);
				$search_form = $search->search_form($$class);
				if (!empty($pagination)) {
				 $pagination_statement = $pagination->show_pagination($pagination, 'locator', $pageno, $query_string);
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
			 <form action=""  method="post" id="locator"  name="locator">
				<div id ="form_line" class="form_line"><span class="heading">Locator Details </span>
				 <table class="form_table">
					<?php echo locator::$view_table_line_tr ?>
					<tbody class="form_data_line_tbody">
					 <?php
					 $count = 0;
					 if(!empty($search_result)){
					 foreach ($search_result as $locator) {
						?>         
 					 <tr class="locator_line<?php echo $count ?>">
 						<td>    
 						 <ul class="inline_action">
 							<li class="add_row_img"><img  src="<?php echo HOME_URL; ?>themes/images/add.png"  alt="add new line" /></li>
 							<li class="remove_row_img"><img src="<?php echo HOME_URL; ?>themes/images/remove.png" alt="remove this line" /> </li>
 							<li><input type="checkbox" name="line_id_cb" value="<?php echo htmlentities($locator->locator_id); ?>"></li>           
 						 </ul>
 						</td>
 						<td>
							<?php echo form::select_field_from_object('org_id', org::find_all_inventory(), 'org_id', 'org', $$class->org_id, 'org_id', $readonly); ?>
 						</td>
 						<td>
							<?php echo form::select_field_from_object('subinventory_id', subinventory::find_all(), 'subinventory_id', 'subinventory', $$class->subinventory_id, 'subinventory_id', $readonly); ?>
 						</td>
 						<td class="single_line"><?php echo  locator::locator_structure(); ?></td>
 						<td><?php echo form::text_field_widsr('locator_id'); ?></td>
 						<td><?php form::text_field_wid('locator'); ?></td>
 						<td><?php form::text_field_wid('alias'); ?></td>
 						<td><?php echo form::extra_field($$class->ef_id, '10', $readonly); ?></td>
 						<td><?php echo form::status_field($$class->status, $readonly); ?></td>
 					 </tr>
						<?php
						$count = $count + 1;
					 }
					 }
					 ?>
					</tbody>
				 </table>
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

</div>
<script type=text/javascript>
 //save class
 var classSave = new saveMainClass();
 classSave.json_url = 'form.php?class_name=locator';
 classSave.line_key_field = 'locator';
 classSave.single_line = false;
 classSave.savingOnlyHeader = false;
 classSave.lineClassName = 'locator';
 classSave.saveMain();
 
 //add new row in multi action template
 $("#content").on("click", ".add_row_img", function() {
	var addNewRow = new add_new_rowMain();
	addNewRow.trClass = 'locator_line';
	addNewRow.tbodyClass = 'form_data_line_tbody';
	addNewRow.noOfTabs = 1;
	addNewRow.removeDefault = true;
	addNewRow.add_new_row();
	});
</script>

