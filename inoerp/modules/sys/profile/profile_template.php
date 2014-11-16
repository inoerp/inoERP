<div id="all_contents">
 <div id="content_left"></div>
 <div id="content_right">
	<div id="content_right_left">
	 <div id="content_top"></div>
	 <div id="content">
		<div id="structure">
		 <div id="sys_profile_divId">
			<!--    START OF FORM HEADER-->
			<div class="error"></div><div id="loading"></div>
			<?php echo (!empty($show_message)) ? $show_message : ""; ?> 
			<!--    End of place for showing error messages-->
			<div id="form_all"><span class="heading">Profile Header </span>
			 <form action=""  method="post" id="sys_profile_header"  name="sys_profile_header">
				<div id ="form_header">
				 <div id="tabsHeader">
					<ul class="tabMain">
					 <li><a href="#tabsHeader-1">Basic Info</a></li>
					</ul>
					<div class="tabContainer">
					 <div id="tabsHeader-1" class="tabContent">
						<div class="large_shadow_box"> 
						 <ul class="column four_column">
							<li> <label><img src="<?php echo HOME_URL; ?>themes/images/serach.png" class="sys_profile_header_id select_popup clickable">
								Profile Id : </label>
							 <?php
							 $f = new inoform();
							 echo form::number_field_drs('sys_profile_header_id');
							 ?>
							</li>
							<li><label>Access Level : </label>
							 <?php echo $f->select_field_from_array('access_level', sys_profile_header::$access_level_a, $$class->access_level); ?>
							</li>
							<li><label>Profile Name : </label> <?php $f->text_field_dlm('profile_name'); ?> </li>
              <li><label>Class Name : </label> <?php $f->text_field_dlm('class_name'); ?> </li>
							<li><label>Description : </label> <?php $f->text_field_d('description'); ?></li>
							<li><label>Profile Level : </label>
							 <?php echo $f->select_field_from_array('profile_level', sys_profile_header::$profile_level_a, $$class->profile_level, 'profile_level'); ?>
							 <a name="show" class="show sys_profile_header_id"> <img src="<?php echo HOME_URL; ?>themes/images/refresh.png"/></a> 
							</li>
						 </ul>
						</div>
					 </div>
					</div>
				 </div>
				</div>
			 </form>
			 <div id ="form_line" class="form_line"><span class="heading">Profile Values </span>
				<div id="tabsLine">
				 <ul class="tabMain">
					<li><a href="#tabsLine-1">Values</a></li>
					<li><a href="#tabsLine-2">Custom Query</a></li>
				 </ul>
				 <div class="tabContainer"> 
					<form action=""  method="post" id="sys_profile_line_line"  name="sys_profile_line_line">
					 <div id="tabsLine-1" class="tabContent">
						<table class="form_table">
						 <thead> 
							<tr>
							 <th>Action</th>
							 <th>Line Id</th> 
							 <?php
							 switch ($profile_level) {
								case 'SITE' :
								 echo "<th>Site</th>";
								 echo "<th>Value</th>";
								 break;

								case 'BUSINESS' :
								 echo "<th>Business Org</th>";
								 echo "<th>Value</th>";
								 break;

								case 'INVENTORY' :
								 echo "<th>Inventory Org</th>";
								 echo "<th>Value</th>";
								 break;

								case 'USER' :
								 echo "<th>User Name</th>";
								 echo "<th>Value</th>";
								 break;


								case 'default':
								 echo "<th>Site</th>";
								 echo "<th>Value</th>";
								 break;
							 }
							 ?>
							</tr>
						 </thead>
						 <tbody class="form_data_line_tbody sys_profile_line_values" >
							<?php
							$count = 0;
							$org = new org();
							foreach ($sys_profile_line_object as $sys_profile_line) {
							 ?>         
 							<tr class="sys_profile_line<?php echo $count ?>">
 							 <td>    
 								<ul class="inline_action">
 								 <li class="add_row_img"><img  src="<?php echo HOME_URL; ?>themes/images/add.png"  alt="add new line" /></li>
 								 <li class="remove_row_img"><img src="<?php echo HOME_URL; ?>themes/images/remove.png" alt="remove this line" /> </li>
 								 <li><input type="checkbox" name="line_id_cb" value="<?php echo htmlentities($sys_profile_line->sys_profile_line_id); ?>"></li>           
 								 <li><?php echo form::hidden_field('sys_profile_header_id', $$class->sys_profile_header_id); ?></li>
 								 <li><?php echo form::hidden_field('profile_level', $$class->profile_level); ?></li>
 								</ul>
 							 </td>
 							 <td><?php form::number_field_wid2sr('sys_profile_line_id'); ?></td>
								<?php
								switch ($profile_level) {
								 case 'SITE' :
									echo "<td>";
									echo $f->text_field('level_name', 'SITE', '', '', '', 1, 1) . '</td><td>';
									break;

								 case 'BUSINESS' :
									echo "<td>";
									echo $f->select_field_from_object('level_name', $org->findAll_business(), 'org_id', 'org', $$class_second->level_name, '', '', 1) . "</td><td>";
									break;

								 case 'INVENTORY' :
									echo "<td>";
									echo $f->select_field_from_object('level_name', $org->findAll_inventory(), 'org_id', 'org', $$class_second->level_name, '', '', 1) . "</td><td>";
									break;


								 case 'USER' :
									echo '<td>';
                  echo $f->select_field_from_object('level_name', user::find_all(), 'user_id', 'username', $$class_second->level_name, '', '', 1) . "</td><td>";
									break;
								}
								if (empty($line_values)) {
								 echo $f->text_field_wid2('level_value') . '</td>';
								} else {
								 echo $f->select_field_from_object('level_value', $line_values, $line_key, $line_desc, $$class_second->level_value, '', '', '') . "</td>";
								}
								?>
 							</tr>
							 <?php
							 $count = $count + 1;
							}
							?>
						 </tbody>
						</table>
					 </div>
					 <div id="tabsLine-2" class="tabContent">
					 </div>
					</form>
				 </div>

				</div>
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