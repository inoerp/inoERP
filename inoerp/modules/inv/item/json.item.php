<?php include_once("../../../include/basics/header.inc"); ?>
<script src="item.js"></script>

<div id="json_save_header"> <?php json_save('org', 'item', 'item_number', 'item_id'); ?></div>
<div id="json_delete_line"> <?php  json_delete('item'); ?> </div>
<!--<div id="new_search_criteria"> <?php //   add_new_search_criteria(); ?> </div>-->

<?php include_template('footer.inc') ?>