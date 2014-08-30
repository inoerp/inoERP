<?php include_once("../../../include/basics/header.inc"); ?>
<script src="gl_calendar.js"></script>
<div id="json_delete_line"> <?php json_delete('gl_calendar', 'gl_calendar_line'); ?> </div>
<div id="json_save_line"><div class="json_message" ><?php json_saveLineData('gl', 'gl_calendar', 'name', 'gl_calendar_id'); ?></div></div>
<?php include_template('footer.inc') ?>