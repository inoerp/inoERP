<div id="all_contents">
 <div id="content_left"></div>
 <div id="content_right">
  <div id="content_right_left">
   <div id="content_top"></div>
   <div id="content">
    <div id="structure">
     <div id="content_typeDivId">
			<!--    START OF FORM HEADER-->
			<div class="error"></div><div id="loading"></div>
			<?php echo (!empty($show_message)) ? $show_message : ""; ?> 
      <div id ="form_header">
			 <div id="scrollElement">
				<form action=""  method="post" id="content_type_header"  name="content_type_header">
				 <div id="content_type_a">
					<ul id="first">
					 <li class="content_type_id"><label>Type ID : </label>
						<?php form::number_field_drs('content_type_id'); ?><a name="show" class="show content_type_id">
						 <img src="<?php echo HOME_URL; ?>themes/images/refresh.png"/></a></li>
					 <li class="content_type_label"><label>Content Type : </label>
						<?php form::text_field_dm('content_type'); ?></li>
					 <li class="description"><label>Description : </label>
						<?php form::text_field_dm('description'); ?></li>
					 <li class="has_subject_vb"> <label>Subject ? : </label>  
						<?php echo form::checkBox_field('has_subject_cb', $$class->has_subject_cb); ?></li>
					 <li class="subject_label"><label>Subject Label : </label>
						<?php form::text_field_d('subject_label'); ?></li>
					 <li class="allow_file_cb"> <label>Attachment ? : </label>    
						<?php echo form::checkBox_field('allow_file_cb', $$class->allow_file_cb); ?></li>
					
					</ul>
					<ul id="second">
					 <li class="blank_category_list"><label>Primary Category :</label> 
						<?php
						if ((isset($category)) && (count($category) > 0)) {
						 foreach ($category as $obj) {
							echo form::select_field_from_object('category_id', category::major_categories(), 'category_id', 'category', $obj->category_id, '', $readonly, 'category_id', '', '');
						 }
						} else {
						 echo form::select_field_from_object('category_id', category::major_categories(), 'category_id', 'category', 'category_id', '', $readonly, 'category_id', '', '');
						}
						?> 
					 </li>
					  <li><input type="button" class="button drop_table" name="drop_table" id="drop_table" value="Delete Content Type"></li>
					</ul>
				 </div>
				 <div id="content_type_new_fields">
					<table class="form_table">
					 <thead> 
						<tr>
						 <th>Action</th>
						 <th>Field Label</th>
						 <th>Field Name</th>
						 <th>Field Type</th>
						 <th>Number</th>
						 <th>Values</th>
						</tr>
					 </thead>
					 <tbody class="field_values_list">
						<?php
//          echo '$content_type->content_type_id is '.$content_type->content_type_id;
						if ((!empty($content_type->content_type_id)) && ($content_type->content_type_id > 0 )) {
						 $fields = new_content_type::find_fields_by_id($content_type->content_type_id);
						} else {
						 $fields = array(
								 [ "Field" => "",
										 "Type" => "(0)"]
						 );
						}
						$i = 0;
						foreach ($fields as $records) {
//                       echo '<pre>';
//           print_r($records);
//           echo '<pre>';
						 unset($field_num);
						 unset($field_type);
						 unset($field_enum);
						 $type = $records['Type'];
						 $type_array = explode("(", $type);
						 if (is_array($type_array)) {
							$field_type = $type_array[0];
							if (!empty($type_array[1])) {
							 $field_num = rtrim($type_array[1], ")");
							 if ($field_type == "enum") {
								$field_enum = $field_num;
								$field_num = "";
							 }
							}
						 } else {
							$field_type = $type;
						 }
//                                  echo '<pre>';
//           print_r($type_array);
//           echo '<pre>';
						 ?>
 						<tr class="content_type<?php echo $i ?>">
 						 <td>    
 							<ul class="inline_action">
 							 <li class="add_row_img"><img  src="<?php echo HOME_URL; ?>themes/images/add.png"  alt="add new line" /></li>
 							 <li class="remove_row_img"><img src="<?php echo HOME_URL; ?>themes/images/remove.png" alt="remove this line" /> </li>
 							 <li><input type="checkbox" name="field_name_cb" class="checkbox" value="<?php echo!(empty($records['Field'])) ? htmlentities($records['Field']) : ""; ?>"></li>           		   
							</ul>
 						 </td>
 						 <td><?php form::text_field_wid('field_label') ?></td>
						 <td><?php !empty($records['Field']) ? $fielNamereadonly =1 : $fielNamereadonly ='';
						echo form::text_field('field_name', $records['Field'], 20, 50, 1, 'use small letters', '', $fielNamereadonly, 'field_name') ?></td>
 						 <td>    
 							<select name="field_type[]" class="field_type"> <?php echo $field_type; ?>
 							 <option value="" ></option> 
 							 <option value="varchar" <?php echo ($field_type == "varchar") ? " selected " : "" ?>>Text</option> 
 							 <option value="int" <?php echo ($field_type == "int") ? " selected " : "" ?>>Number</option> 
 							 <option value="text" <?php echo ($field_type == "text") ? " selected " : "" ?>>Text Area</option> 
 							 <option value="text" <?php echo ($field_type == "mediumtext") ? " selected " : "" ?>>Simple Text Area</option> 
 							 <option value="enum" <?php echo ($field_type == "enum") ? " selected " : "" ?>>Enum List</option> 
 							 <option value="tinyint" <?php echo ($field_type == "tinyint") ? " selected " : "" ?> >Check Box</option> 
 							 <option value="date" <?php echo ($field_type == "date") ? " selected " : "" ?> >Date</option> 
 							</select> 
 						 </td>
 						 <td><?php form::number_field_wids('field_num') ?></td>    
						 <td><?php form::text_field_wid('field_enum') ?></td>     
 						</tr>
						 <?php
						 $i++;
						}
						?>
					 </tbody>
					</table>
				 </div>
				</form>   
			 </div>
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
