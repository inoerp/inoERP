<?php include_once("../../../includes/function/loader.inc"); ?>
<script src="ledger.js"></script>

<div id="json_delete_line"> <?php json_delete('gl_ledger_balancing_values', 'gl_ledger_balancing_values_id'); ?> </div>
<div id="json_save_header"> <?php json_save('gl', 'gl_ledger', 'ledger', 'gl_ledger_id'); ?></div>
<div id="json_save_line"><?php json_saveLineData('gl', 'gl_ledger_balancing_values', 'gl_ledger_id', 'gl_ledger_balancing_values_id'); ?></div>

<?php include_template('footer.inc') ?>