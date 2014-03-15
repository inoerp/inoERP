<?php $dont_check_login = true;
include_once("../../include/basics/header.inc"); ?>
<script src="user.js"></script>
<div id="json_save_header"> <div class="json_message"><?php json_save('user', 'user', 'username', 'user_id'); ?></div></div>
<div id="json_save_line"><?php json_saveLineData('user', 'user_role', 'role_id', 'user_role_id'); ?></div>
<div id="json_delete_line"> <?php  json_delete('wip_wo'); ?> </div>

<?php include_template('footer.inc') ?>