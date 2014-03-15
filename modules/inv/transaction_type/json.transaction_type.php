<?php include_once("../../../include/basics/header.inc"); ?>
<script src="transaction_type.js"></script>

<div id="json_save_header"> <?php json_save('inventory', 'transaction_type', 'transaction_type', 'transaction_type_id'); ?></div>
<div id="json_delete_line"> <?php  json_delete('transaction_type'); ?> </div>

<?php include_template('footer.inc') ?>