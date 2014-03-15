<?php include_once("../../../include/basics/header.inc"); ?>
<script src="coa_combination.js"></script>
<div id="json_delete_line"> <?php json_delete('coa_combination', 'coa_combination_line'); ?> </div>
<div id="json_save_header"> <?php json_save('gl', 'coa_combination', 'combination', 'coa_combination_id'); ?></div>
<?php include_template('footer.inc') ?>