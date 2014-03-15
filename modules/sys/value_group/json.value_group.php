<?php include_once("../../../include/basics/header.inc"); ?>
<script src="option.js"></script>

<div id="json_delete_line"> <?php json_delete('sys_value_group_line', 'sys_value_group_line_id'); ?> </div>
<div id="json_save_header"> <?php json_save('sys', 'sys_value_group_header', 'value_group', 'sys_value_group_header_id'); ?></div>
<div id="json_save_line"><?php json_saveLineData('sys', 'sys_value_group_line', 'code', 'sys_value_group_line_id'); ?></div>

<?php include_template('footer.inc') ?>