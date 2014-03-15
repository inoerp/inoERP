<div id="all_contents">
 <div id="content_left"></div>
 <div id="content_right">
	<div id="content_right_left">
	 <div id="content_top"></div>
	 <div id="content">
		<div id="structure">
		 <div id="role_pathId">
			<div id="form_top">
			 <?php
			 $current_page_path = "role_path.php";
			 form::form_button($current_page_path);
			 ?>
			</div>
			<!--    START OF FORM HEADER-->
			<div id ="form_header">
			 <div class="error"></div><div id="loading"></div>
			 <div class="show_loading_small"></div>
			 <?php echo (!empty($show_message)) ? $show_message : ""; ?> 
			 <!--    End of place for showing error messages-->
			 <div class="large_shadow_box four_column"><span class="heading">Role Details </span>
				<ul>
				 <li>
					<label> Select Role : </label>
					<?php echo form::select_field_from_object('role_id', role_path::roles(), 'option_line_id', 'option_line_code', $role_id, 'role_id'); ?>
					<a name="show" href="role_path.php?role_id=" class="show option_header_id">
					 <img src="<?php echo HOME_URL; ?>themes/images/refresh.png"/></a> 
				 </li>						
				 <li><label>Role Id : </label>
					<?php echo form::text_field('role_id', $role_id, '20', '', '', '', 'role_id'); ?>
				 </li>
				 <li><label>Description : </label>
					<?php echo form::text_field('description', $role->description, '20'); ?>
				 </li>
				 <li><label>Extra Field : </label>
					<?php echo form::extra_field($role->efid); ?>
				 </li>
				 <li><label>Status : </label>
					<?php echo form::status_field($role->status); ?>
				 </li>
				 <li><label>Revision : </label>
					<?php echo form::revision_enabled_field($role->rev_enabled); ?>
				 </li>
				 <li><label>Revision No: </label>
					<?php echo form::text_field('rev_number', $role->rev_number, '10'); ?>
				 </li>
				</ul>
			 </div>
			</div>
			<!--END OF FORM HEADER-->
			<div id ="form_line" class="form_line"><span class="heading">Role Page Access </span>
			 <form action=""  method="post" id="role_path"  name="role_path">

				<table id="form_data_table" class="form">
				 <thead>
					<tr>
					 <th class="doubleRow" rowspan="2">Action</th>
					 <th class="doubleRow" rowspan="2">Role Path Id</th>
					 <th class="singleRowDoubleColumn" rowspan="1" colspan="2">Path Name </th>
					<tr>
					 <th class="singleRow" rowspan="1" colspan="1" >Path ID </th>
					 <th class="singleRow" rowspan="1" colspan="1" >Value</th>
					</tr>
					</tr>
				 </thead>
				 <tbody id="form_data_line_tbody">
					<?php
					$linecount = 0;
					foreach ($role_path_object as $form_line_array) {
					 if (!empty($form_line_array->role_path_id)) {
						$path = path::find_by_id($form_line_array->role_path_id);
					 } else {
						$path = new path();
					 }
					 ?>
 					<tr class="option_line_tr<?php echo $linecount; ?> form_line_row">

 					 <td>   
 						<ul class="inline_action">
 						 <li class="add_row_img"><img  src="<?php echo HOME_URL; ?>themes/images/add.png"  alt="add new line" /></li>
 						 <li class="remove_row_img"><img src="<?php echo HOME_URL; ?>themes/images/remove.png" alt="remove this line" /> </li>
 						 <li><input type="checkbox" name="role_path_id_cb" value="<?php echo htmlentities($form_line_array->role_path_id); ?>"></li>           
 						</ul>
 					 </td>
 					 <td><?php echo form::text_field('role_path_id', $form_line_array->role_path_id, '8', '12', '', '', '', '1'); ?></td>
   <!--					 <td><?php // echo form::select_field_from_object('path_name', $allPaths, 'path_id', 'name', $form_line_array->path_id, 'path_name');    ?></td>
 					 <td><?php // echo form::text_field('path_id', $path->path_id, '10', '50', '', '', '','1');    ?></td>
 					 <td><?php // echo form::text_field('path_value', $path->value, '80', '500', '', '', '','1');    ?></td>-->
 					 <td colspan="4"><select name="path_id" class="path_id select">
 						 <option value=""></option>
							<?php
							$selected = "";
							foreach ($allPaths as $path) {
							 if ($form_line_array->path_id == $path->path_id) {
								$selected = "selected";
							 } else {
								$selected = "";
							 }
							 echo "<optgroup label=\"$path->name\">";
							 echo "<option value=\"$path->path_id\"   $selected>";
							 echo $path->path_id . "&nbsp;&nbsp;&nbsp;&nbsp; | &nbsp;&nbsp;&nbsp;&nbsp;  " . $path->value;
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
