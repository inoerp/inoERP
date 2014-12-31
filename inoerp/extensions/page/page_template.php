<div id="all_contents">
 <div id="content_left"></div>
 <div id="content_right">
	<div id="content_right_left">
	 <div id="content_top"></div>
	 <div id="content">

		<div id="structure">
		 <div id="page_divId">
			<div class="error"></div><div id="loading"></div>
			<?php echo (!empty($show_message)) ? $show_message : ""; ?> 
			<!--    START OF FORM HEADER-->
			<div id ="form_header">

			 <form action=""  method="post" id="page_header"  name="page_header">
				<!--create empty form or a single id when search is not clicked and the id is referred from other page -->
				<?php echo $f->hidden_field_withId('page_id', $$class->page_id); ?>
				<div id="subject"><label>Subject : </label>
				 <input type="text"  name="subject" value="<?php echo htmlentities($$class->subject); ?>" 
								size="135"  maxlength="250" class="subject" placeholder="Write a brief subject on the content."> 
				 <span><a class="button" href="form.php?class_name=page_view&page_id=<?php echo $$class->page_id; ?>">View</a></span>
				</div>
				<div id="contentId"><label>Content : </label>
				 <textarea required name="content" class="plaintext" rows="18" cols="80"><?php
					echo base64_decode($page->content);
//                echo !empty($$class->content_php_cb) ? base64_decode($page->content) : $page->content;
					?> </textarea>
				</div>
				<div id="show_attachment">
				 <input type="button" class="button" value="Attachements" id="attachment_button" name="">
				 <div id="attachment_page">
					<?php
					if (isset($file) && count($file) > 0) {
					 echo '<ul  class="header"><li>Hide</li><li>Delete</li><li>File</li></ul>';
					 foreach ($file as $records) {
						echo '<ul>';
						echo '<li><input type="checkbox" name="show" value="1"></li>';
						echo '<li><input type="checkbox" name="delete" value="1"></li>';
						echo '<a href=' . HOME_URL . $records->file_path . $records->file_name . '>' . $records->file_name . '</a></li>';
						echo '</ul>';
					 }
					}
					?>
				 </div>
				</div>
				<div id="page_element">
				 <ul>
					<li><label>Tags : </label><?php $f->text_field_d('terms'); ?> </li>
					<li class="published_cb"> <label>Published : </label>
					 <?php echo $f->checkBox_field('published_cb', $$class->published_cb); ?></li>
					<li><label>Front Page : </label> <?php echo $f->checkBox_field('show_in_frontpage_cb', $$class->show_in_frontpage_cb); ?></li>
					<li><label>PHP Code : </label> <?php echo $f->checkBox_field('content_php_cb', $$class->content_php_cb); ?></li>
					<li><label>Weightage : </label><?php $f->text_field_d('weightage'); ?> </li>
					<li class="rev_enabled_cb"> <label>Rev enabled : </label> <?php echo $f->checkBox_field('rev_enabled_cb', $$class->rev_enabled_cb); ?></li>           
					<li><label>Rev Number : </label><?php $f->text_field_ds('rev_number'); ?> </li>
					<li><label>Parent : </label><?php $f->text_field_ds('parent_id'); ?> </li>
				 </ul>
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
	<div id="content_right_right"></div>
 </div>

</div>

<?php include_template('footer.inc') ?>