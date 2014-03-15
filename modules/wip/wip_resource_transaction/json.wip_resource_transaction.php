<?php include_once("../../../include/basics/header.inc"); ?>
<script src="wip_resource_transaction.js"></script>

<!--<div id="json_save_header"><div class="json_message"> <?php // json_save('wip', 'wip_resource_transaction', 'transaction_quantity', 'wip_resource_transaction_id'); ?></div></div>-->
<div id="json_save_line"><?php json_saveLineData('wip', 'wip_resource_transaction', 'wip_wo_routing_detail_id', 'wip_resource_transaction_id'); ?></div>
<div id="json_delete_line"> <?php  json_delete('wip_resource_transaction'); ?> </div>

<?php include_template('footer.inc') ?>