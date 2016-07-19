<?php include_once("../../includes/basics/header.inc"); ?>
<div id="json_save_header"> <div class="json_message"><?php json_save('extension', 'content', 'subject', 'content_id'); ?></div></div>
<div id="json_delete_header"><div class="json_message">
  <?php
  if (!empty($_GET['delete']) && $_GET['delete'] == 1) {
   $content_id = $_GET['header_id'];
   $result = content::delete($content_id);

   if ($result == 1) {
    echo 'Comment is deleted!';
   } else {
    return false;
   }
  }
  ?>
 </div></div>

<div id="json_drop_column">
 <?php
 if (!empty($_GET['delete']) && $_GET['delete'] == 1) {
  $content_name = $_GET['content_name'];
  $field_name = $_GET['field_name'];

  $result = content::drop_column($content_name, $field_name);

  if ($result == 1) {
   echo 'Comment is deleted!';
  } else {
   return false;
  }
 }
 ?>
</div>



<?php include_template('footer.inc') ?>