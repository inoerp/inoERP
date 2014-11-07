<div id="all_contents">
 <div id="content_left"></div>
 <div id="content_right">
	<div id="content_right_left">
	 <div id="content_top"></div>
	 <div id="content">
		<div id="structure">
		 <div id="org_divId">
			<!--    START OF FORM HEADER-->
			<div class="error"></div><div id="loading"></div>
			<div class="show_loading_small"></div>
			<?php echo (!empty($show_message)) ? $show_message : ""; ?> 
			<span class="heading"> View - Static Query Builder  </span>
			<!--    End of place for showing error messages-->
			<div id ="form_header">
			 <form action=""  method="post" id="view_header"  name="view_header">
				<div id="view_a">
				 <div class="large_shadow_box">
					<ul class="column three_column"> 
					 <li> 
						<label><img src="<?php echo HOME_URL; ?>themes/default/images/serach.png" class="view_id select_popup clickable">
						 View Id : </label> 
						<?php $f->text_field_ds('view_id') ?>
						<a name="show" href="form.php?class_name=view" class="show view_id">	<img src="<?php echo HOME_URL; ?>themes/images/refresh.png" class="clickable"></a> 
					 </li> 
					 <li><label>View Name : </label> <?php $f->text_field_dm('view_name'); ?> </li> 
					 <li><label>Description : </label> <?php $f->text_field_dm('description'); ?> </li> 
					 <li class="display_type"><label> Display Type: </label> <?php echo $view_display_type_statement; ?>
					 </li>
					</ul> 
				 </div>
				</div>
				<div id="basic_settings"><span class="heading">Basic Settings</span>
				 <ul>
					<li class="view_label"><label>path: </label>
					 <span class="add_new_path" ><img  src="<?php echo HOME_URL; ?>themes/images/plus_10.png" alt="add new path" />New Path</span>
					 <?php echo (!empty($view_path_statement)) ? $view_path_statement : ""; ?>
					</li>
				 </ul>

				</div>
				<div><label>Logical Settings</label>
				 <?php
				 if (!empty($view->logical_settings)) {
					echo '<ul id="logical_settings">';
					echo base64_decode($view->logical_settings);
					echo '</ul>';
				 } else {
					?>
 				 <ul id="logical_settings">
 					<li><label>Tables</label> 
 					 <input type="button" value="Save Tables" class="button save_tables" id="save_tables">
 					 <input type="button" value="Save Query" class="button save_query" id="save_query">
					 	<span class="add_new_table" ><img  src="<?php echo HOME_URL; ?>themes/images/plus_10.png" alt="add new table" />New Table</span>
 					</li>
 					<div id="display_div"> 
 					 <ul class="display_records table_object0">
 						<li id="table_records"><label>Table Name </label>
 						 <select class="all_table_names">
							 <?php echo!empty($table_option_statement) ? $table_option_statement : ""; ?>
 							<option value="" class="remove_table">Remove Table</option>
 						 </select>
 						</li>
 						<li class="field_records record_no0"><Label>Field</label>
 						 <select class="table_fields">
 							<option value=" " disabled>Select Table</option>
 						 </select>
 						</li>
 					 </ul>
 					</div>
 					<li id="show_field_li"><label>Show Fields</label>
 					 <div id="show_field_buttons">
 						<span class="add_new_fields">Available Fields</span>
 					 </div>
 					</li>
 					<li id="condition_li"><label>Conditions</label>
 					 <div id="condition_buttons">
   <!--							 <input type="button" value="Save Condtions" class="button save_conditions" id="save_conditions">-->
 						<span class="add_new_conditions" ><img  src="<?php echo HOME_URL; ?>themes/images/plus_10.png" alt="add new conditions" />New Conditions</span>
 					 </div>

 					 <div id="condition_buttons_div">

 					 </div>
 					 <div id="condition_buttons_info">
 					 </div>
 					 <table id="condition_buttons_table">
 						<thead>
 						 <tr>
 							<th>Parameter</th>
 							<th>Condition</th>
 							<th>Value</th>
 						 </tr>
 						</thead>
 						<tbody>
 						 <tr class="condition_row">
 							<td class="condition_row_parameter">

 							</td>
 							<td class="condition_row_condition">
 							 <!--									 <label>Operator</label>-->
 							 <ul><li>
 								 <select class="condition_operator_type">
 									<option value=""	></option>
 									<option value="database">Database</option>
 									<option value="manual">Manual Entry</option>
 									<option value="remove">Remove</option>
 								 </select>

 								</li><li>
 								 <select class="condition_operator">
 									<option value=' = '> is equal to </option>
 									<option value=' != '> is not equal to </option>
 									<option value=' > '> is greater than </option>
 									<option value=' >= '> >= </option>
 									<option value=' < '> is less than </option>
 									<option value=' <= '> <= </option>
 									<option value=' LIKE '> contains </option>
 									<option value=' IS NULL '> is NULL </option>
 									<option value=' IS NOT NULL '> is not NULL </option>

 								 </select>
 								</li>
 							 </ul>
 							</td>
 							<td class="condition_row_value">
 							 <input type="text" class="condition_row_value_input input">
 							</td>
 						 </tr>
 						</tbody>
 					 </table>
 					</li> 
 					<li id="sort_sqlQuery">
 					 <ul>
 						<li id="sorting_li">
 						 <label>Sorting</label>
 						 <span class="add_new_sort_criteria" ><img  src="<?php echo HOME_URL; ?>themes/images/plus_10.png" alt="add new conditions" />New Sorting Criteria</span>
 						 <table id="sort_fields_table">
 							<thead>
 							 <tr>
 								<th>Fields</th>
 								<th>Sort by</th>
 							 </tr>
 							</thead>
 							<tbody>
 							 <tr class="sort_fields_row">
 								<td class="sort_fields_field_value">

 								</td>
 								<td class="sort_fields_sortBy">
 								 <select class="sort_fields_values">
 									<option value=""	></option>
 									<option value='ASC'> Ascending</option>
 									<option value='DESC'> Descending </option>
 									<option value="remove">Remove</option>
 								 </select>
 								</td>
 							 </tr>
 							</tbody>
 						 </table>
 						</li> 
 						<li><label>Parameter</label></li> 
 						<li><label>Relationships</label></li> 
 						<li><label>Callback</label></li> 
 					</li>
 				 </ul>
 				 </li>
 				 </ul>
				 <?php } ?>
				 <input type="hidden" name="logical_settings" id="logical_settings_value">
				</div>
				<div id="view_query"><label>SQL Query</label>
				 <textarea name="query" readonly class="query" id="query" rows="6" cols="118"><?php echo base64_decode($view->query_v); ?></textarea>
				 <ul id="sql_query">
					<li class="select">
					 <label>SELECT</label>
					 <textarea name="select" readonly class="select" id="select" rows="6" cols="30"><?php echo $view->select_v; ?></textarea>
					</li>
					<li class="select">
					 <label>FROM</label>
					 <textarea name="from" readonly class="from" id="from" rows="6" cols="15"><?php echo $view->from_v; ?></textarea>
					</li>
					<li class="select">
					 <label>WHERE</label>
					 <textarea name="where" readonly class="where" id="where" rows="6" cols="15"><?php echo $view->where_v; ?></textarea>
					</li>
					<li class="select">
					 <label>ORDER BY</label>
					 <textarea name="order_by" readonly class="order_by" id="order_by" rows="6" cols="15"><?php echo $view->order_by; ?></textarea>
					</li>
					<li class="select">
					 <label>FILTERS</label>
					 <textarea name="filters" class="filters" id="filters" rows="6" cols="15"><?php echo $view->filters; ?></textarea>
					</li>
					<li class="select">
					 <label>End clause</label>
					 <textarea name="query_end" readonly class="query_end" id="query_end" rows="6" cols="10"><?php echo $view->query_end; ?></textarea>
					</li>
				 </ul>
				</div> 
				<div id="live_display"><label>Live Display</label>
				 <div id="live_display_data">
					<?php echo!empty($view_result) ? $view_result : ""; ?>
				 </div>
				</div>

			 </form>   
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
