<?php include_once("../../../include/basics/header.inc"); ?>
<script src="uom.js"></script>

<div id="json_save_header"> <?php json_save('org', 'uom', 'uom', 'uom_id'); ?></div>
<div id="json_delete_line"> <?php  json_delete('uom'); ?> </div>
<!--<div id="new_search_criteria"> <?php //   add_new_search_criteria(); ?> </div>-->

<?php include_template('footer.inc') ?>