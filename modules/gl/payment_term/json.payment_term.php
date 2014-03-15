<?php include_once("../../../include/basics/header.inc"); ?>
<script src="payment_term.js"></script>

<div id="json_save_header"> <?php json_save('gl', 'payment_term', 'payment_term', 'payment_term_id'); ?></div>
<div id="json_save_line"><?php json_saveLineData('gl', 'payment_term_schedule', 'seq_number', 'payment_term_schedule_id'); ?></div>
<div id="json_save_line2"><?php json_saveLineData2('gl', 'payment_term_discount', 'seq_number', 'payment_term_discount_id'); ?></div>
<div id="json_delete_line"> <?php json_delete('payment_term_schedule'); ?> </div>

<?php include_template('footer.inc') ?>