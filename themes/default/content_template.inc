<div id="all_contents">
 <div id="content_header"></div>
 <div id="content_left"></div>
 <div id="content_right">
  <div id="content_right_left">
   <div id="content_top"></div>
   <div id="contentDivId">
    <div id="main"> 
     <div id="structure">
      <div id="content_divId">
       <!--    START OF FORM HEADER-->
			 <div class="error"></div><div id="loading"></div>
			 <?php echo (!empty($show_message)) ? $show_message : ""; ?> 
			 <!--    End of place for showing error messages-->
			 <div id="form_all">
				<div id ="form_header">
				 <div class='heading'> <?php echo $content_type->description; ?></div>
				 <form action=""  method="post" id="content"  name="content">
					<!--create empty form or a single id when search is not clicked and the id is referred from other content -->
					<?php echo $f->hidden_field_withId('content_id', $$class->content_id); ?>
					<?php echo $f->hidden_field_withId('content_type_id', $content_type->content_type_id); ?>
					<?php echo $f->hidden_field_withId('content_type', $content_type_name); ?>
					<div id="subject"><label>Subject : </label>
					 <?php echo form::text_field('subject', $$class->subject, 100) ?>
					 <span class="button"><a class="show content_id" href="content.php?content_id=
																	 <?php echo $$class->content_id; ?>&content_type=<?php echo $content_type_name ?>">View</a></span>
					</div>

					<div id="extra_form_element">
					 <?php echo!empty($form_element) ? $form_element : "" ?>
					</div>
					<!--End of Content-->
					<div id="show_attachment" class="show_attachment">
					 <div id="file_upload_form">
						<ul class="inRow asperWidth">
						 <li><input type="file" id="attachments" class="attachments" name="attachments[]" multiple/></li>
						 <li> <input type="button" value="Attach" form="file_upload" name="attach_submit" id="attach_submit" class="submit button"></li>
						 <li class="show_loading_small"><img alt="Loading..." src="<?php echo HOME_URL; ?>themes/images/small_loading.gif"/></li>
						</ul>
					 </div>
					 <div id="uploaded_file_details"></div>
					 <?php echo file::attachment_statement($file); ?>
					</div>
					<div id="content_elements">
					 <ul id="content_element" class="inRow asperWidth">
						<li> 
						 <?php
						 if (!empty($category_select_statement_array)) {
							foreach ($category_select_statement_array as $category_select_statement) {
							 echo '<label>Category</label>';
							 echo $category_select_statement;
							}
						 } else {
							if (!empty($categories_of_content_type_select_option_array)) {
							 foreach ($categories_of_content_type_select_option_array as $records) {
								echo '<label>Category</label>';
								echo $records;
							 }
							}
						 }
						 ?>
						</li>
						<li id="terms"><label>Tags : </label> 
						 <?php
						 $f = new inoform();
						 echo $f->text_field('terms', $$class->terms, '30')
						 ?> </li>
						<li class="published_cb"> <label>Published : </label> 
						 <?php echo form::checkBox_field('published_cb', $$class->published_cb); ?></li>
						<li><label>Weight : </label><?php form::text_field_ds('weightage'); ?> </li>
						<li class="rev_enabled_cb"> <label>Rev enabled : </label>
						 <?php echo form::checkBox_field('rev_enabled_cb', $$class->rev_enabled_cb); ?></li>
						<li><label>Rev Number : </label><?php form::text_field_ds('rev_number'); ?></li>
						<li><label>Parent : </label><?php form::text_field_ds('parent_id'); ?></li>
						<li class="show_in_fp_cb"> <label>Show in Front Page : </label>
						 <?php echo form::checkBox_field('show_in_fp_cb', $$class->show_in_fp_cb); ?></li>
					 </ul>
					</div>
					<!--<div class="submit"><input type="submit" value="save" name="submit_content" class="button"></div>-->
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
