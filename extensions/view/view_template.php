<div id="all_contents">
 <div id="content_left"></div>
 <div id="content_right">
  <div id="content_right_left">
   <div id="content_top"></div>
   <div id="content">
    <div id="structure">
     <div id="viewId">
      <div id="form_top">
       <ul class="form_top">
        <li><input type="button" class="button refresh" value="Refresh" name="refresh"/> </li>
        <li> <a class="button" href="view.php">New Object</a> </li>
        <li><input type="submit" form="view_header" name="submit_view" id="submit_view" class="button" Value="Save"></li>
        <li> <a class="button" href="view_results.php?view_id=<?php echo htmlentities($view->view_id); ?>">View Page</a> </li>
        <li> <input type="submit" class="button delete" form="coa_combination_form" name="delete_row" id="delete_row" value="Delete"></li>
        <li><input type="reset" class="button" form="view_header" name="reset" Value="Reset All"></li>
        <li><script>document.write('<a class="button" href="' + document.referrer + '">Go Back</a>');</script></li>
       </ul>
      </div>
      <!--    START OF FORM HEADER-->
      <div id ="form_header">
       <ul id="form_box"> 
        <li>

         <div id="loading"><img alt="Loading..." 
                                src="<?php echo HOME_URL; ?>themes/images/loading.gif"/></div>
        </li>
        <li>   <!--    Place for showing error messages-->

         <div class="error"></div>
				 <?php echo (!empty($show_message)) ? $show_message : ""; ?> 


         <!--    End of place for showing error messages-->
        </li>
        <!--Search form creation    -->

        <li>
         <div id="scrollElement">
          <form action=""  method="post" id="view_header"  name="view_header">
           <div id="view_a">
            <ul id="first">
             <li class="view_id"><label>View ID : </label>
              <input type="text" size="7" readonly maxlength="25" name="view_id" placeholder="sys number"
                     id="input_view_id" value="<?php echo htmlentities($view->view_id); ?>">
             </li>
             <li class="view_label"><label>View Name: </label>
              <input type="text" size="15" id="view" maxlength="25" name="view" value="<?php echo htmlentities($view->view); ?>">
             </li>
             <li class="description"><label>Description : </label>
              <input type="text" size="30" maxlength="256" name="description" value="<?php echo htmlentities($view->description); ?>">
             </li>
						  <li class="display_type"><label> Display Type: </label>
              <?php echo $view_display_type_statement; ?>
             </li>
            </ul>
           </div>
           <div id="basic_settings"><label>Basic Settings</label>
						<ul>
						 <li class="view_label"><label>path: </label>
							<span class="add_new_path" ><img  src="<?php echo HOME_URL; ?>themes/images/plus_10.png" alt="add new path" />New Path</span>
							<?php echo (!empty($view_path_statement)) ? $view_path_statement : ""; ?>
						 </li>
						</ul>

           </div>
           <div><label>Logical Settings</label>
						<?php 
						if(!empty($view->logical_settings)){ 
						 echo '<ul id="logical_settings">';
						 echo base64_decode($view->logical_settings);
						 echo '</ul>';
						}else{
						?>
						<ul id="logical_settings">
						 <li><label>Tables</label> 
							<input type="button" value="Save Tables" class="button save_tables" id="save_tables">
							<input type="button" value="Save Query" class="button save_query" id="save_query">
						 </li>
						 <div id="display_div"> 
							<ul id="display_records0">
							 <span class="add_new_table" ><img  src="<?php echo HOME_URL; ?>themes/images/plus_10.png" alt="add new table" />New Table</span>
							 <span class="add_new_field" ><img  src="<?php echo HOME_URL; ?>themes/images/plus_10.png" alt="add new table" />New Field</span>
							 <li id="table_records"><label>Table Name </label>
								<select class="all_table_names">
								 <?php echo!empty($table_option_statement) ? $table_option_statement : ""; ?>
								 <option value="" class="remove_table">Remove Table</option>
								</select>
							 </li>
							 <li id="field_records0"><Label>Field</label>
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
						<?php  } ?>
					 <input type="hidden" name="logical_settings" id="logical_settings_value">
					 </div>
					 <div id="view_query"><label>SQL Query</label>
						<textarea name="query" readonly class="query" id="query" rows="6" cols="118"><?php 
						echo base64_decode($view->query) ; ?></textarea>
						<ul id="sql_query">
						 <li class="select">
							<label>SELECT</label>
						<textarea name="select" readonly class="select" id="select" rows="6" cols="30"><?php 
						echo $view->select ; ?></textarea>
						 </li>
						 						 <li class="select">
							<label>FROM</label>
						<textarea name="from" readonly class="from" id="from" rows="6" cols="15"><?php 
						echo $view->from ; ?></textarea>
						 </li>
						 						 <li class="select">
							<label>WHERE</label>
						<textarea name="where" readonly class="where" id="where" rows="6" cols="15"><?php 
						echo $view->where ; ?></textarea>
						 </li>
						 	<li class="select">
							<label>ORDER BY</label>
						<textarea name="order_by" readonly class="order_by" id="order_by" rows="6" cols="15"><?php 
						echo $view->order_by ; ?></textarea>
						 </li>
						 						 	<li class="select">
							<label>FILTERS</label>
						<textarea name="filters" class="filters" id="filters" rows="6" cols="15"><?php 
						echo $view->filters ; ?></textarea>
						 </li>
						 						 	<li class="select">
							<label>End clause</label>
						<textarea name="query_end" readonly class="query_end" id="query_end" rows="6" cols="10"><?php 
						echo $view->query_end ; ?></textarea>
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
				</li>
			 </ul>
			</div>  


		 </div>
		 <!--END OF FORM HEADER-->  
		</div>
		<!--   end of structure-->
	 </div>
	 <div id="content_bottom"></div>
	</div>
	<div id="content_right_right"></div>
 </div>

</div>

<?php include_template('footer.inc') ?>
