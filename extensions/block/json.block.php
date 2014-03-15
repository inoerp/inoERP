<?php include_once("../../include/basics/header.inc"); ?>
<div id="json_save_header"> <div class="json_message"><?php json_save('extension', 'block', 'name', 'block_id'); ?></div></div>
<div id="json_delete_block">
  <?php
  if(!empty($_GET['delete']) && $_GET['delete']==1 ){
   $block_id = $_GET['block_id'];
   
  
  $result = block::delete($block_id);
    if ($result == 1) {
   echo 'Block is deleted!';
  } else {
    echo " Error code: $result ! ";
  }
  }
  ?>
</div>


<?php include_template('footer.inc') ?>