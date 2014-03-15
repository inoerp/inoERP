<?php include_once("../../../include/basics/header.inc"); ?>

    <div id="json_save_header"> <div class="json_message"><?php json_save('extension', 'page', 'content', 'page_id'); ?></div></div>

    <div id="json_delete_line"><div class="json_message"> <?php  json_delete('page_id'); ?> </div></div>
<?php include_template('footer.inc') ?>