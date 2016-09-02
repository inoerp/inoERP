<?php
  if(!empty($_GET['delete']) && $_GET['delete']==1 ){
   $comment_id = $_GET['extn_comment_id'];
	 include_once 'comment.php?extn_commentt_id='.$comment_id;
   $result=extn_comment::delete($comment_id);
  
	 echo '<div id="delete_comment">';
 if ($result == 1) {
   echo '<div class="message">Comment is deleted!</div>';
  } else {
    return false;
  }
	echo '</div>';
  }
 ?>
