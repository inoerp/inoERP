<div id="commentForm">
 <script src="<?php echo HOME_URL . 'extensions/comment/' ?>comment.js"></script> 
 <div id="output">
 </div>
 <!--    START OF FORM HEADER-->
	<div class="error"></div><div id="loading"></div>
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
		 <ul class='inRow asperWidth'><li>
			 <label>Subject : </label>
			 <input type="text"  name="subject" value="<?php echo htmlentities($comment->subject); ?>" 
							size="25"  maxlength="150" class="subject" placeholder="Write a brief subject on the comment."> 
			</li>
			<li>
			 <label>Name on comment : </label>
			 <input type="text"  name="weightage" value="<?php echo htmlentities($comment->comment_by); ?>" 
							size="25"  maxlength="150" class="comment_by" placeholder="Comment By"> 
			</li>
			<!--<li><input type="button"  value="File" id="comment_attachment_button" name=""></li>-->
<!--<li><input type="button" class="button refresh" value="Refresh" name="refresh"/> </li>-->
			<li><input type="button" name="submit_comment" class="submit_comment" Value="Save"></li>
			<li> <input type="button" name="delete_comment" class="delete_comment" value="Delete"></li>
<!--         <li id="loading"><img alt="Loading..." 
												 src="<?php // echo HOME_URL;   ?>themes/images/small_loading.gif"/></li>-->
		 </ul>
		</div>
		<div id="commentId"><label>Comment : </label>
		 <textarea required name="comment" class="mediumtext" rows="18" cols="80"><?php
			echo (!empty($comment->comment)) ? htmlentities($comment->comment) : "";
			?> </textarea>

		</div>
		<div id="file_upload_form">
		 <ul class="inRow asperWidth">
			<li><input type="file" id="attachments" class="attachments" name="attachments[]" multiple/></li>
			<li> <input type="button" value="Attach" form="file_upload" name="attach_submit" id="attach_submit" class="submit button"></li>
			<li class="show_loading_small"><img alt="Loading..." src="<?php echo HOME_URL; ?>themes/images/small_loading.gif"/></li>
		 </ul>
		</div>
		<div id="uploaded_file_details">		</div>
		 <?php echo file::attachment_statement($file); ?>
		<div id="attachment_comment">

		</div>
	 </form>

 <!--END OF FORM HEADER-->  
</div>
<!--   end of structure-->
