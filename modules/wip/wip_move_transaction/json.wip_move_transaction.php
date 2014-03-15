<?php include_once("../../../include/basics/header.inc"); ?>
<script src="wip_move_transaction.js"></script>

<div id="json_save_header"><div class="json_message"> <?php json_save('inventory', 'wip_move_transaction', 'item_id', 'wip_move_transaction_id'); ?></div></div>
<div id="json_delete_line"> <?php  json_delete('wip_move_transaction'); ?> </div>

<?php include_template('footer.inc') ?>