<div id="all_contents">
 <div id="content_left"></div>
 <div id="content_right">
	<div id="content_right_left">
	 <div id="content_top"></div>
	 <div id="content">
		<div id="structure">
		 <div id="locator_divId">
			<!--    START OF FORM HEADER-->
			<div class="error"></div><div id="loading"></div>
			<?php echo (!empty($show_message)) ? $show_message : ""; ?> 
			<!--    End of place for showing error messages-->
			<div id ="form_header">
			 <form action="path.php" method="post" size="30" id="path" name="path"  >
				<div > 
				 <ul class="two_column"> 
					<li><label><img src="<?php echo HOME_URL; ?>themes/default/images/serach.png" class="path_id select_popup clickable">
						Path Id :</label><?php $f->text_field_ds('path_id') ?>
					 <a name="show" href="form.php?class_name=path" class="show path_id">	<img src="<?php echo HOME_URL; ?>themes/images/refresh.png" class="clickable"></a> 
					</li>
					<li><label>Parent Name :</label> 
					 <select name="parent_id[]" id="parent_id"> 
						<option value="" ></option> 
						<?php
						$parent = path::find_all();
						foreach ($parent as $record) {
						 echo '<option value="' . $record->path_id . '" ';
						 echo $record->path_id == $path->parent_id ? 'selected' : 'none ';
						 echo '>' . $record->name . '</option>';
						}
						?> 
					 </select> 
					</li>
					<li><label>Path Name :</label> 
					 <input type="text" required name="name[]" id="name" maxlength="60" size="60"
									placeholder="Enter a valid path" value="<?php echo htmlentities($path->name); ?>">
					</li>
					<li><label>Path Value :</label>  
					 <input type="text" required name="path_link[]" maxlength="500" id="path_link" size="60" 
									placeholder="Enter path relative to site home" value="<?php echo htmlentities($path->path_link); ?>">
					 <!--validation message place for username-->
					</li>
					<li><label>Description  : </label> 
					 <input type="text" required name="description[]" maxlength="100" id="description" size="60" 
									placeholder="Enter path descrip. Limit 100 characters" value="<?php echo htmlentities($path->description); ?>">
					</li>
					<li><label>Class/Obj Name  : </label> <?php $f->text_field_d('obj_class_name') ?></li>
					<li><label>Mode  : </label> <?php $f->text_field_ds('mode') ?></li>
					<li><label>Module : </label>
					 <Select name="module_id[]" id="module"> 
						<option value="" ></option>   
						<?php
						$module = module::find_all();
						foreach ($module as $record) {
						 echo '<option value="' . $record->module_id . '" ';
						 echo $record->module_id == $path->module_id ? 'selected' : 'none ';
						 echo '>' . $record->name . '</option>';
						}
						?>

					 </select>
					</li>
					<li><label>ID Column name : </label>
					 <Select name="id_column_name[]" id="id_column_name"> 
						<option value="" ></option>   
						<?php
						$coumn_name = view::find_all_idColumns();
						foreach ($coumn_name as $key => $value) {
						 echo '<option value="' . $value . '" ';
						 echo $value == $path->id_column_name ? 'selected' : 'none ';
						 echo '>' . $value . '</option>';
						}
						?> 

					 </select>
					</li>

					<li class="primary_cb"> <label>Primary ? : </label>            
					 <input type="checkbox" name="primary_cb[]"  value="1"
					 <?php
					 if ($path->primary_cb == 1) {
						echo " checked";
					 } else {
						echo "";
					 }
					 ?> >
					</li>
				 </ul>
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
