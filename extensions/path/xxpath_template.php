<div id="all_contents">
 <div id="content_left"></div>
 <div id="content_right">
	<div id="content_right_left">
	 <div id="content_top"></div>
	 <div id="content">
		<div id="structure">
		 <div id="path">
			<div id="form_top">
			 <ul class="form_top">
				<li> <a class="button" href="path.php">Create New</a> </li> 
				<li><input type="submit" class="button" form="path_header" name="submit_path" id="submit_path" Value="Save"></li>
<!--        <li><input type="submit" class="button" form="org_line" name="submit_line"  id="submit_line" Value="Save Line"></li>-->
				<li><input type="reset" class="button" name="reset" form="org_line" Value="Reset All"></li>
				<li><a name="show" href="path.php?path_id=<?php echo htmlentities($path->path_id); ?>" class="show button">View</a></li>
				<li><a name="paths" href="paths.php" class="button paths">Paths</a></li>
				<li> <input type="submit" class="button" form="path_header" name="delete" id="delete"
										onclick="return confirm('Are you sure?');"     value="Delete"></li>
				<li><script>document.write('<a class="button" href="' + document.referrer + '">Go Back</a>');</script></li>
			 </ul>
			</div>
			<div id ="form_header">
			 <form action="path.php" method="post" size="30" id="path_header"  >
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
				 <h9>New Option Entry! </h9>
				 <li class="ncontrol"><span class="heading">Path Header </span> 
					<div class="two_column"> 
					 <ul> 
						<li><label>
							<!--                  <a href="find_path.php" class="popup"> 
																		<img src="<?php // echo HOME_URL;    ?>themes/images/serach.png"/></a>-->
							Path Id :</label> 
						 <input type="text" readonly name="path_id" id="path_id" maxlength="30" size="30"
										placeholder="System Generated No" value="<?php echo htmlentities($path->path_id); ?>">
						 <!--<a name="show" href="path.php?path_id=" class="show">Show</a>-->
						</li>
						<li><label>Parent Name :</label> 
						 <select name="parent_id" id="parent_id"> 
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
						 <input type="text" required name="name" id="email" maxlength="60" size="60"
										placeholder="Enter a valid path" value="<?php echo htmlentities($path->name); ?>">
						</li>
						<li><label>Path Value :</label>  
						 <input type="text" required name="value" maxlength="60" id="value" size="60" 
										placeholder="Enter path relative to site home" value="<?php echo htmlentities($path->value); ?>">
						 <!--validation message place for username-->
						</li>
						<li><label>Description  : </label> 
						 <input type="text" required name="description" maxlength="100" id="description" size="60" 
										placeholder="Enter path descrip. Limit 100 characters" value="<?php echo htmlentities($path->description); ?>">
						</li>
						<li><label>Module : </label>
						 <Select name="module" id="module"> 
							<option value="" ></option>   
							<?php
							$module = module::find_all();
							foreach ($module as $record) {
							 echo '<option value="' . $record->module_id . '" ';
							 echo $record->module_id == $path->module ? 'selected' : 'none ';
							 echo '>' . $record->name . '</option>';
							}
							?>

						 </select>
						</li>
						<li><label>ID Column name : </label>
						 <Select name="id_column_name" id="id_column_name"> 
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
						 <input type="checkbox" name="primary_cb"  value="1"
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
				 </li>
				</ul>

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
