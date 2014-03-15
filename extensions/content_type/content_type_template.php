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
			 <form action=""  method="post" id="content_type_header"  name="content_type_header" class="content_type_header">
				<div id="tabsHeader">
				 <ul class="tabMain">
          <li><a href="#tabsHeader-1">Basic Info</a></li>
          <li><a href="#tabsHeader-2">Categories</a></li>
         </ul>
				 <div class="tabContainer">
					<div id="tabsHeader-1" class="tabContent">
					 <div class="large_shadow_box"> 
						<ul class="column four_column">
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
						 <li class="allow_comment_cb"> <label>Enable Comments ? : </label>    
							<?php echo form::checkBox_field('allow_comment_cb', $$class->allow_comment_cb); ?></li>
						 <li><input type="button" class="button drop_table" name="drop_table" id="drop_table" value="Delete Content Type"></li>
						</ul>
					 </div>
					</div>
					<div id="tabsHeader-2" class="tabContent">
					 <div> 
						<ul class="column five_column">
						 <?php
						 if ((isset($category)) && (count($category) > 0)) {
							foreach ($category as $obj) {
							 echo $removeImage;
							 echo form::select_field_from_object('category_id', category::major_categories(), 'category_id', 'category', $obj->category_id, '', $readonly, 'category_id', '', '');
							 echo '</li>';
							}
						 }
						 echo $addImage;
						 echo form::select_field_from_object('category_id', category::major_categories(), 'category_id', 'category', 'category_id', '', $readonly, 'category_id', '', '');
						 echo '</li>';
						 ?> 
						 </li>
						</ul>
					 </div>
					</div>
				 </div>
				</div>
				<div id="form_line" class="form_line"><span class="heading">Content Type Fields/Columns </span>
				 <div id="tabsLine">
					<ul class="tabMain">
					 <li><a href="#tabsLine-1">Main</a></li>
					 <li><a href="#tabsLine-2">Future</a></li>
					</ul>
					<div class="tabContainer">
					 <div id="tabsLine-1" class="tabContent">
						<table class="form_line_data_table">
						 <thead> 
							<tr>
							<tr>
							 <th>Action</th>
							 <th>Field Label</th>
							 <th>Position</th>
							 <th>Required</th>
							 <th>Field Name</th>
							 <th>Field Type</th>
							 <th>Number</th>
							 <th>enum Values</th>
							 <th>Option List</th>
							</tr>
							</tr>
						 </thead>
						 <tbody class="field_values_list">
							<?php
							$count = 0;
							foreach ($new_content_type_object as $new_content_type) {
							 $content_type_reference = content_type_reference::find_by_contentTypeId_fieldName($$class->content_type_id, $$class_second->field_name);
							 if (($content_type_reference) == false) {
								$content_type_reference = new content_type_reference;
							 }
							 $class_third = 'content_type_reference';
							 $$class_third = &$content_type_reference;
							 ?>   
 							<tr class="content_type<?php echo $count ?>">
 							 <td>    
 								<ul class="inline_action">
 								 <li class="add_row_img"><img  src="<?php echo HOME_URL; ?>themes/images/add.png"  alt="add new line" /></li>
 								 <li class="remove_row_img"><img src="<?php echo HOME_URL; ?>themes/images/remove.png" alt="remove this line" /> </li>
 								 <li><input type="checkbox" name="field_name_cb" class="checkbox" value="<?php echo $$class_second->Field; ?>"></li>           		   
 								 <li><?php echo!empty($content_type_reference) ? form::hidden_field('content_type_reference_id', $$class_third->content_type_reference_id) : ''; ?></li>
 								</ul>
 							 </td>
 							 <td><?php form::text_field_wid3('field_label') ?></td>
 							 <td><?php echo form::select_field_from_array('field_position', dbObject::$position_array, $$class_third->field_position); ?></td>
 							 <td><?php echo form::checkBox_field('required_cb', $$class_third->required_cb); ?></td>
 							 <td><?php
								 !empty($$class_second->field_name) ? $fielNamereadonly = 1 : $fielNamereadonly = '';
								 echo form::text_field('field_name', $$class_second->field_name, 20, 50, 1, 'use small letters', '', $fielNamereadonly, 'field_name')
								 ?></td>
 							 <td>
								 <?php echo form::select_field_from_object('field_type', content_type::content_field_type(), 'option_line_code', 'option_line_value', $$class_second->field_type, '', $readonly, 'field_type', '') ?>
 							 </td>
 							 <td><?php form::number_field_wid2s('field_num'); ?></td>    
 							 <td><?php form::text_field_wid2('field_enum'); ?></td>  
 							 <td><?php echo form::select_field_from_object('option_type', option_header::find_all(), 'option_header_id', 'option_type', $$class_third->option_type, '', $readonly, 'option_type', '', '') ?></td>  
 							</tr>
							 <?php
							 $count++;
							}
							?>
						 </tbody>
						</table>
					 </div>
					 <div id="tabsLine-2" class="scrollElement tabContent">
					 </div>
					</div>
				 </div>
				</div>
			 </form>   
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
