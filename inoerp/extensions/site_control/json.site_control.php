<?php include_once("../../include/basics/header.inc"); ?>
<script src="site_control.js"></script>

<div id="json_save_header"><div class="json_message"> 
 <?php json_save('site_control', 'site_control_header', 'site_name', 'site_control_header_id'); ?>
 </div>
</div>
<div id="json_save_line">
 <?php
 json_saveLineData('site_control', 'site_control_line', 'component_item_id', 'site_control_line_id');
 ?>
</div>

<?php include_template('footer.inc') ?>