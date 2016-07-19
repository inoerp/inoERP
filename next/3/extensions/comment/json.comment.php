<?php
  if(!empty($_GET['delete']) && $_GET['delete']==1 ){
   $comment_id = $_GET['comment_id'];
	 include_once 'comment.php?comment_id='.$comment_id;
   $result=comment::delete($comment_id);
  
	 echo '<div id="delete_comment">';
 if ($result == 1) {
   echo '<div class="message">Comment is deleted!</div>';
  } else {
    return false;
  }
	echo '</div>';
  }
 ?>
