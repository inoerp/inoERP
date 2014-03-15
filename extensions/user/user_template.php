<div id="all_contents">
 <div id="content_left"></div>
 <div id="content_right">
	<div id="content_right_left">
	 <div id="content_top"></div>
	 <div id="content">
		<div id="structure">
		 <div id="userDiv">
			<!--    START OF FORM HEADER-->
			<div class="error"></div><div id="loading"></div>
			<?php echo (!empty($show_message)) ? $show_message : ""; ?> 
			<!--    End of place for showing error messages-->
			<div id ="form_header">
			 <div id="tabsHeader">
				<form action="" method="post" id="user_header" name="user_header">
				 <div class="large_shadow_box">
					<ul class="column four_column">
					 <li><label><img id="user_popup" class="showPointer user_popup" src="<?php echo HOME_URL; ?>themes/images/serach.png"/>User ID :</label> 
						<?php echo form::text_field_dsr('user_id'); ?><a name="show" class="show user_id">
						 <img src="<?php echo HOME_URL; ?>themes/images/refresh.png"/></a> 
					 </li>
					 <li><label>User Name :</label>  
						<?php echo form::text_field_dm('username'); ?>
					 </li>
					 <li><label>Password  : </label> 
						<input type="password" name="enteredPassword[]" maxlength="50" id="enteredPassword" size="30" pattern="(?=^.{8,}$)((?=.*\d)|(?=.*\W+))(?![.\n])(?=.*[A-Z])(?=.*[a-z]).*$"
									  >
					 </li>
					 <li><label>Retype Password  : </label> 
						<input type="password" name="enteredRePassword[]" maxlength="50" id="enteredRePassword" size="30" pattern="(?=^.{8,}$)((?=.*\d)|(?=.*\W+))(?![.\n])(?=.*[A-Z])(?=.*[a-z]).*$"
									 >
					 </li>
					 <li><label>First Name : </label>
						<?php echo form::text_field_dm('first_name'); ?>
					 </li>
					 <li><label>Last Name : </label>
						<?php echo form::text_field_dm('last_name'); ?>
					 </li>
					 <li><label>e-Mail ID :</label> 
						<?php echo form::text_field_dm('email'); ?>
					 </li>
					 <li><label>Phone :</label> 
						<?php echo form::number_field_d('phone'); ?>
					 </li>
					</ul>
					<!--<p> <input type="submit"  name="submit" class="button" value="Create New User">-->
				 </div>
				</form>
			 </div>
			</div>    

			<div id ="form_line" class="form_line"><span class="heading">User Role Access </span>
			 <form action=""  method="post" id="user_role"  name="user_role">

				<table id="form_data_table" class="form">
				 <thead>
					<tr>
					 <th class="doubleRow" rowspan="2">Action</th>
					 <th class="doubleRow" rowspan="2">User Role Access Id</th>
					 <th class="singleRowDoubleColumn" rowspan="1" colspan="2">Role Name </th>
					<tr>
					 <th class="singleRow" rowspan="1" colspan="1" >Role ID </th>
					 <th class="singleRow" rowspan="1" colspan="1" >Description</th>
					</tr>
					</tr>
				 </thead>
				 <tbody class="form_data_line_tbody user_role_assignment_values">
					<?php
					$linecount = 0;
					foreach ($user_role_object as $form_line_array) {
					 ?>
 					<tr class="user_role_assignment<?php echo $linecount; ?>">
 					 <td>   
 						<ul class="inline_action">
 						 <li class="add_row_img"><img  src="<?php echo HOME_URL; ?>themes/images/add.png"  alt="add new line" /></li>
 						 <li class="remove_row_img"><img src="<?php echo HOME_URL; ?>themes/images/remove.png" alt="remove this line" /> </li>
 						 <li><input type="checkbox" name="user_role_id_cb" value="<?php echo htmlentities($form_line_array->user_role_id); ?>"></li>           
 							<li><?php echo form::hidden_field('user_id', $$class->user_id); ?></li>
						</ul>
 					 </td>
 					 <td><?php echo form::text_field('user_role_id', $form_line_array->user_role_id, '8', '12', '', '', '', '1'); ?></td>
 					 <td colspan="4"><select name="role_id" class="role_id select">
 						 <option value=""></option>
							<?php
							$selected = "";
							foreach ($allRoles as $role) {
							 if ($form_line_array->role_id == $role->option_line_id) {
								$selected = "selected";
							 } else {
								$selected = "";
							 }
							 echo "<optgroup label=\"$role->option_line_code\">";
							 echo "<option value=\"$role->option_line_id\"   $selected>";
							 echo $role->option_line_id . "&nbsp;&nbsp;&nbsp;&nbsp; | &nbsp;&nbsp;&nbsp;&nbsp;  " . $role->description;
							 echo "</option>";
							 echo "</optgroup>>";
							}
							?>
 						</select>
 					 </td>
 					</tr>
					 <?php
					 $linecount++;
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
