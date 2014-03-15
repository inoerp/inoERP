<div id="all_contents">
 <div id="content_header"></div>
 <div id="content_left"></div>
 <div id="content_right">
  <div id="content_right_left">
   <div id="content_top"></div>
   <div id="content">
    <div id="main"> 
     <div id="structure">
      <div id="block_divId">
       <!--    START OF FORM HEADER-->
			 <div class="error"></div><div id="loading"></div>
			 <?php echo (!empty($show_message)) ? $show_message : ""; ?> 
			 <!--    End of place for showing error messages-->
			 <div id="form_all">
				<div id ="form_header">
				 <form action=""  method="post" id="block_header"  name="block_content_header">
					<!--create empty form or a single id when search is not clicked and the id is referred from other block_content -->
					<?php echo form::hidden_field('block_id', $$class->block_id); ?>	
					<?php echo form::hidden_field('block_content_id', $$class_second->block_content_id); ?>	
					<table>
					 <tr>
						<td><label>Block Title : </label>
						 <input type="text"  name="title" value="<?php echo htmlentities($$class->title); ?>" 
										size="40"  maxlength="250" class="subject" placeholder="title of the block"> 
						</td>
						<td><label>Show Title : </label><?php echo form::checkBox_field('show_title_cb', $$class->show_title_cb); ?></td>
					 </tr>
					 <tr>
						<td><label>Weight : </label>
						 <?php echo form::select_field_from_array('weight', dbObject::$position_array, $$class->weight); ?></td>
						<td><label>Position : </label>
						 <?php echo form::select_field_from_array('position', block::$position_array, $$class->position); ?></td>							</td>
					 </tr>
					 <tr>
						<td><label>Reference Table : </label><?php form::text_field_d('reference_table'); ?></td>
						<td><label>Block Name: </label><?php form::text_field_d('name'); ?></td>
					 </tr>
					 <!--Start of  block content-->
					 <?php if ((!empty($_GET['custom_block'])) && ($_GET['custom_block'] == 1)) { ?>
 					 <tr><td colspan="2"><label>Block Content : </label>
 						 <textarea required name="content" class="noformat" rows="8" cols="80" placeholder=' '><?php echo $$class_second->content; ?></textarea>
 						</td></tr>
 					 <tr> <td>	label>Block Info : </label><?php form::text_field_d2('info'); ?> </td>
						<td><label>Block content contains PHP Code : </label> <?php echo form::checkBox_field('content_php_cb', $$class_second->content_php_cb); ?></td>
 					 </tr>
						<?php
					 }
					 ?>
					 <!--End of  block content-->
					 <tr>
						<td><label>Enabled : </label><?php echo form::checkBox_field('enabled_cb', $$class->enabled_cb); ?></td>
						<td><label> Visibility Option : </label>
						 <?php echo form::select_field_from_array('visibility_option', block::$visibility_option_array, $$class->visibility_option); ?></td>
						 </tr>
					 <tr>
						<td colspan="2">
						 <div id="visibility"><label> Visibility : </label>
							<textarea name="visibility" class="noformat" rows="4" cols="80"><?php echo base64_decode($block->visibility); ?></textarea>
						 </div>
						</td>
					 </tr>
					</table>
				 </form>
				</div>
			 </div>
			</div>
		 </div>
		 <!--   end of structure-->
		</div>
	 </div>
	 <div id="content_bottom"></div>
	</div>
	<div id="content_right_right"></div>
 </div>

</div>

<?php include_template('footer.inc') ?>
