<div id="all_contents">
 <div id="content_left"></div>
 <div id="content_right">
	<div id="content_right_left">
	 <div id="content_top"></div>
	 <div id="content">
		<div id="structure">
		 <div id="item_cost_divId">
			<!--    START OF FORM HEADER-->
			<div class="error"></div><div id="loading"></div>
			<?php echo (!empty($show_message)) ? $show_message : ""; ?> 
			<!--    End of place for showing error messages-->

			<div id ="form_header"><span class="heading">Item Cost Header </span>
			 <form action=""  method="post" id="ext_test_case_header"  name="ext_test_case_header">
				<div id="tabsHeader">
         <ul class="tabMain">
          <li><a href="#tabsHeader-1">Basic Info</a></li>
          <li><a href="#tabsHeader-2">Notes</a></li>
					<li><a href="#tabsHeader-3">Attachments</a></li>
				 </ul>
				 <div class="tabContainer">
					<div id="tabsHeader-1" class="tabContent">
					 <div class="large_shadow_box"> 
						<ul class="column five_column">
						 <li><label><img src="<?php echo HOME_URL; ?>themes/images/serach.png" class="sd_delivery_header_id select_popup clickable">
							 Header Id 	</label><?php echo form::text_field_dsr('ext_test_case_header_id'); ?><a name="show" href="form.php?class_name=ext_test_case_header" class="show ext_test_case_header clickable">
							 <img src="<?php echo HOME_URL; ?>themes/images/refresh.png"/></a> 
						 </li>
						 <li><label>Module Name </label>
							<?php echo $f->text_field_dm('module_name'); ?>
						 </li>
						 <li><label>Name </label>
							<?php echo $f->text_field_dm('name'); ?>
						 </li>
						 <li><label>Description </label>
							<?php echo $f->text_field_d('description'); ?>
						 </li>
						</ul>
					 </div>
					</div>
					<div id="tabsHeader-2" class="tabContent">
					 <div> 
						<div id="comments">
						 <div id="comment_list">
							<?php echo!(empty($comments)) ? $comments : ""; ?>
						 </div>
						 <?php
						 $reference_table = 'ext_test_case_header';
						 $reference_id = $$class->ext_test_case_header_id;
						 include_once HOME_DIR . '/comment.php';
						 ?>
						 <div id="new_comment">
						 </div>
						</div>
					 </div>
					</div>
					<div id="tabsHeader-3" class="tabContent">
					 <div> 
						<div id="show_attachment" class="show_attachment">
						 <div id="file_upload_form">
							<ul class="inRow asperWidth">
							 <li><input type="file" id="attachments" class="attachments" name="attachments[]" multiple/></li>
							 <li> <input type="button" value="Attach" form="file_upload" name="attach_submit" id="attach_submit" class="submit button"></li>
							 <li class="show_loading_small"><img alt="Loading..." src="<?php echo HOME_URL; ?>themes/images/small_loading.gif"/></li>
							</ul>
						 </div>
						 <div id="uploaded_file_details"></div>
						 <?php echo extn_file::attachment_statement($file); ?>
						</div>
					 </div>
					</div>
				 </div>

				</div>
			 </form>
			</div>

			<div id="form_line" class="form_line"><span class="heading">Cost Lines</span>
			 <form action=""  method="post" id="po_site"  name="ext_test_case_line">
				<div id="tabsLine">
				 <ul class="tabMain">
					<li><a href="#tabsLine-1">Basic</a></li>
					</ul>
				 <div class="tabContainer">
					<div id="tabsLine-1" class="tabContent">
					 <table class="form_line_data_table">
						<thead> 
						 <tr>
							<th>Action</th>
							<th>Line Id</th>
							<th>Line Number</th>
							<th>Step Action</th>
							<th>Input</th>
							<th>Expected Result</th>
						 </tr>
						</thead>
						<tbody class="form_data_line_tbody">
						 <?php
						 $count = 0;
						 foreach ($ext_test_case_line_object as $ext_test_case_line) {
													?>         
 						 <tr class="ext_test_case_line<?php echo $count ?>">
 							<td>    
 							 <ul class="inline_action">
 								<li class="add_row_img"><img  src="<?php echo HOME_URL; ?>themes/images/add.png"  alt="add" /></li>
 								<li class="remove_row_img"><img src="<?php echo HOME_URL; ?>themes/images/remove.png" alt="remove" /> </li>
 								<li><input type="checkbox" name="line_id_cb" value="<?php echo $$class_second->ext_test_case_line_id; ?>"></li>           
 								<li><?php echo form::hidden_field('ext_test_case_header_id', $$class->ext_test_case_header_id); ?></li>
 							 </ul>
 							</td>
 							<td><?php form::text_field_wid2sr('ext_test_case_line_id'); ?></td>
 							<td><?php echo $f->text_field_wid2s('line_number'); ?></td>
							<td><?php echo $f->text_area('step_action', $$class_second->step_action, '3'); ?></td>
							<td><?php echo $f->text_area('input', $$class_second->input, '3'); ?></td>
							<td><?php echo $f->text_area('expected_result', $$class_second->expected_result, '3'); ?></td>
 						 </tr>
							<?php
							$count = $count + 1;
						 }
						 ?>
						</tbody>
					 </table>
					</div>
				 </div>
				</div>
			 </form>
			</div>

			<!--END OF FORM HEADER-->
		 </div>
		</div>
		<!--   end of structure-->
	 </div>
	 <div id="content_bottom"></div>
	</div>
	<!--<div id="content_right_right"></div>-->
 </div>

</div>
<?php include_template('footer.inc') ?>
