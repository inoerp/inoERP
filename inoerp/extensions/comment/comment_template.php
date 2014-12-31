<div id="commentForm">
 <script src="<?php $f = new inoform();  echo HOME_URL . 'extensions/comment/' ?>comment.js"></script> 
 <div id="commentForm_witoutjs">
 <div id="output">
 </div>
 <!--    START OF FORM HEADER-->
	<div class="comment_error"></div><div id="comment_loading"></div>
	<?php echo (!empty($show_message)) ? $show_message : ""; ?> 
	 <form action="<?php echo HOME_URL . 'extensions/comment/post_comment.php'; ?>"  method="post" class="comment"  name="comment" >
		<!--create empty form or a single id when search is not clicked and the id is referred from other comment -->
		<div class="hidden"><input type="hidden"
															 name="comment_id" value="<?php echo htmlentities($comment->comment_id); ?>">
		</div>
		<div class="hidden"><input type="hidden" name="reference_table" 
															 value="<?php echo empty($comment->reference_table) ? htmlentities($reference_table) : htmlentities($comment->reference_table); ?>">
		</div>
		<div class="hidden"><input type="hidden" name="reference_id" 
															 value="<?php echo empty($comment->reference_id) ? htmlentities($reference_id) : htmlentities($comment->reference_id); ?>">
		</div>
		<div id="comment_subject" >
		 <ul class='inRow asperWidth'>
      <li><label>Subject : </label><?php echo $f->text_field('subject', str_replace(array('<p>', '</p>'), ' ',$comment->subject),'','','medium') ?></li>
			<li><label>Name on comment : </label><?php echo $f->text_field('comment_by',$comment->comment_by) ?></li>
			<li><input type="button" name="submit_comment" class="submit_comment" Value="Save"></li>
			<li> <input type="button" name="delete_comment" class="delete_comment" value="Delete"></li>
		 </ul>
		</div>
		<div id="commentId"><label>Comment : </label>
		 <textarea name="comment" class="mediumtext" rows="18" cols="80"><?php
			echo (!empty($comment->comment)) ? htmlentities($comment->comment) : "";
			?> </textarea>

		</div>
		<div id="file_upload_form">
		 <ul class="inRow asperWidth">
			<li><input type="file" id="comment_attachments" class="attachments" name="attachments[]" multiple/></li>
			<li> <input type="button" value="Attach"  name="attach_submit" id="comment_attach_submit" class="submit button comment_attach_submit"></li>
			<li class="show_loading_small"><img alt="Loading..." src="<?php echo HOME_URL; ?>themes/images/small_loading.gif"/></li>
		 </ul>
		 <div class="uploaded_file_details"></div>
		</div>
		<div id="uploaded_file_details">		</div>
		 <?php echo file::attachment_statement($file); ?>
	 </form>
</div>
 <!--END OF FORM HEADER-->  
</div>
<!--   end of structure-->
