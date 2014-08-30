<div id="all_contents">
 <div id="content_left"></div>
 <div id="content_right">
  <div id="content_right_left">
   <div id="content_top"></div>
   <div id="content">
		<div id="structure">
		 <div id="option">
			<div id="form_top">
			 <?php echo (!empty(form::$form_button_ul)) ? form::$form_button_ul : "" ;  ?>
			</div>
			<!--    START OF FORM HEADER-->
			<div id ="form_header">
			 <form action=""  method="post" id="option_header"  name="option_header">
        <ul id="form_box"> 
				 <li>   <!--    Place for showing error messages-->
					<div class="error"></div><div id="loading"></div>
				 <?php echo (!empty($show_message)) ? $show_message : ""; ?> 
					<!--    End of place for showing error messages-->
				 </li>
				  <li class="ncontrol"><span class="heading">Option Header </span>
					<div class="three_column">
					 <ul>
						<li>
						 <label><a href="find_option.php" class="popup">
							 <img src="<?php echo HOME_URL; ?>themes/images/serach.png"/></a>
							Option Id : </label>
						 <input type="text" name="option_header_id[]" value="<?php echo htmlentities($option_header->option_header_id); ?>" 
										maxlength="50" id="option_header_id" placeholder="System generated number"/>
						 <a name="show" href="option.php?option_header_id=" class="show option_header_id">
							<img src="<?php echo HOME_URL; ?>themes/images/refresh.png"/></a> 
						</li>
						<li><label>Option Type : </label>
						 <input type="text" required name="option_type[]" value="<?php echo htmlentities($option_header->option_type); ?>" 
										maxlength="50" id ="option_type" placeholder="Avoid any special characters"/>
						</li>
						<li><label>Access Level** : </label>
						 <Select name="access_level[]" required id="access_level"/> 
							<option value=""></option>
							<option value="system" <?php echo $option_header->access_level == 'system' ? 'selected' : ''; ?> >System</option>
							<option value="user" <?php echo $option_header->access_level == 'user' ? 'selected' : ''; ?> >User</option>
							<option value="both" <?php echo $option_header->access_level == 'both' ? 'selected' : ''; ?> >Both</option>                
						 </select> 
						</li>
						<li><label>Description : </label>
						 <input type="text" name="description[]" value="<?php echo htmlentities($option_header->description); ?>" maxlength="100" 
										id="description">
						</li>
						<li><label>Module : </label>
						 <Select name="module[]" id="module"> 
							<option value="" ></option>   
							<?php
							$module = module::find_all();
							foreach ($module as $record) {
							 echo '<option value="' . $record->module_id . '" ';
							 echo $record->module_id == $option_header->module ? 'selected' : 'none ';
							 echo '>' . $record->name . '</option>';
							}
							?>

						 </select>
						</li>
						<li><label>Extra Field : </label>
						 <input type="text" name="efid[]" value="<?php echo htmlentities($option_header->efid); ?>" maxlength="50" 
										id="efid">
						</li>
						<li><label>Status : </label>
						 <Select name="status[]" id="status" >
							<option value="" ></option>
							<option value="active" <?php
							echo $option_header->status == 'active' ? 'selected' : ''; ?> > Active </option>
							<option value="inactive" <?php 
							echo $option_header->status == 'inactive' ? 'selected' : ''; ?> > Inactive </option>                                   
						 </select>
						</li>
						<li><label>Revision : </label>
						 <Select name="rev_enabled[]" id="rev_enabled"> 
							<option value="" ></option>   
							<option value="enabled" <?php
							echo 	$option_header->rev_enabled == 'enabled' ? 'selected' : '';	?> >Enabled</option>
							<option value="disabled" <?php
							echo $option_header->rev_enabled == 'disabled' ? 'selected' : ''; ?>>Disabled</option>                                   
						 </select>
						</li>
						<li><label>Revision No: </label>
						 <input type="text"  name="rev_number[]" value="<?php echo htmlentities($option_header->rev_number); ?>" maxlength="50" id="rev_number">
						</li>
					 </ul>
					</div>
				 </li>
        </ul>
			 </form> 
			</div>

			<!--END OF FORM HEADER-->

			<!--Start of the option line
			First check if $option_id_l fetched from $_GET variable
			If the value exists then fetch the object from database & show the object
			If the value is not set then make it zero & show a blank form-->

			<div id ="form_line">
			 <form action="option.php"  method="post" id="option_line"  name="option_line">


				<table id="option_line_table">
				 <thead>
					<tr>
					 <th>Action</th>
					 <th>Line Id</th>
					 <th>Option Code</th>
					 <th>Description</th>
					 <th>E Field</th>
					 <th>Status</th>
					 <th>Revision</th>
					 <th>Rev #</th>
					 <th>Start Date</th>
					 <th>End Date</th>
					 

					</tr>
				 </thead>
				 <tbody>
					<?php
					$count = 0;
					foreach ($option_line_object as $option_line) {
					 ?>
						<tr class="option_line_tr<?php echo $count;?>">
						 <td>   
							<ul class="inline_action">
							 <li class="add_row_img"><img  src="<?php echo HOME_URL; ?>themes/images/add.png"  alt="add new line" /></li>
							 <li class="remove_row_img"><img src="<?php echo HOME_URL; ?>themes/images/remove.png" alt="remove this line" /> </li>
							 <li><input type="checkbox" name="option_line_id_cb" value="<?php echo htmlentities($option_line->option_line_id); ?>"></li>           
							</ul>
						 </td>
						 <td>
							<input type="text" required readonly name="option_line_id[]"  class ="option_line_id"
										 value="<?php echo htmlentities($option_line->option_line_id); ?>" size="10" maxlength="20" 
										 class ="option_line_id" placeholder="Sys generated no">
<!--							<input type="hidden" name="option_header_id[]" 
 										value="<?php // echo htmlentities($option_header->option_header_id); ?>" maxlength="50" 
 										class ="option_header_id" placeholder="Value defaults from header">-->
						 </td>
						 <td>
							<input type="text" required name="option_line_code[]" value="<?php echo htmlentities($option_line->option_line_code); ?>" maxlength="50" 
										 class="option_line_code" placeholder="Avoid any special characters">
						 </td>
						 <td>
							<input type="text"  name="description[]" value="<?php echo htmlentities($option_line->description); ?>" maxlength="100" 
										 class="description">
						 </td>
						 <td>
							<input type="text"  name="efid[]" value="<?php echo htmlentities($option_line->efid); ?>" maxlength="20" size="6"
										 class="efid">
						 </td>
						 <td>
						 <Select name="status[]" class="status" >
							<option value="" ></option>
							<option value="active" <?php
							echo $option_line->status == 'active' ? 'selected' : ''; ?> > Active </option>
							<option value="inactive" <?php 
							echo $option_line->status == 'inactive' ? 'selected' : ''; ?> > Inactive </option>                                   
						 </select>
						 </td>
						 <td>
						 <Select name="rev_enabled[]" class="rev_enabled"> 
							<option value="" ></option>   
							<option value="enabled" <?php
							echo 	$option_line->rev_enabled == 'enabled' ? 'selected' : '';	?> >Enabled</option>
							<option value="disabled" <?php
							echo $option_line->rev_enabled == 'disabled' ? 'selected' : ''; ?>>Disabled</option>                                   
						 </select>
						 </td>
						 <td>
							<input type="text"  name="rev_number[]" value="<?php echo htmlentities($option_line->rev_number); ?>" maxlength="20" size="6" class="rev_number">
						 </td>
						 <td>
							<input type="date"  name="effective_start_date[]"  
										 value="<?php echo htmlentities($option_line->effective_start_date); ?>"
										 maxlength="50" id="effective_start_date">
						 </td>
						 <td>
							<input type="date"  name="effective_end_date[]" 
										 value="<?php echo htmlentities($option_line->effective_end_date); ?>"
										 maxlength="50" id="effective_end_date">
						 </td>
						</tr>
						<?php
						$count++;
					 }
					?>
				 </tbody>
				</table>

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
