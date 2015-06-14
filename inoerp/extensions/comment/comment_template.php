<div id="commentForm">
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
   <span class="show_loading_small"><img alt="Loading..." src="<?php echo HOME_URL; ?>themes/images/small_loading.gif"/></span>
   <div id="commentId" class="row"><label>Comment</label>
    <textarea name="comment" class="ed-mediumtext" rows="8" cols="100"><?php
     echo (!empty($comment->comment)) ? htmlentities($comment->comment) : "";
     ?> </textarea>

   </div>
   <div id="file_upload_form" class="row small-top-margin">
    <ul class="inRow asperWidth">
     <li class="btn btn-info active inline input_file clickable"  role="button"><input type="file" id="comment_attachments"  class="input_file_btn clickable" name="attachments[]" multiple/>
      <i class="fa fa-paperclip clickable"></i>&nbsp;&nbsp;Select File</li>
     <li><input type="button"  role="button" value="Attach"  name="attach_submit" id="comment_attach_submit" class="btn btn-info active comment_attach_submit"></li>
        <?php $user_name = isset($_SESSION['username']) ? $_SESSION['username'] : 'Anonymous'; ?>
     <li><div class="input-group">
       <span class="input-group-addon" id="basic-addon1">Reply as </span>
       <input type="text" name="comment_by" class="form-control comment_by height-unset" placeholder="<?php echo $user_name ?>" aria-describedby="basic-addon1" >
      </div></li>
     <li><input type="button" role="button" name="submit_comment" class="btn btn-warning ino-btn submit_comment" Value="Post"></li>
     <?php
     echo form::hidden_field('class_name', $class);
     echo $f->hidden_field_withId('upload_type', 'only_server');
     ?>

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
