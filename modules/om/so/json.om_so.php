<?php include_once("../../include/basics/header.inc"); ?>
<script src="supplier.js"></script>

<div id="json_save_header"> <?php json_save('om_so', 'om_so_header', 'om_so_type', 'om_so_header_id', 'om_so_number'); ?></div>
<div id="json_save_line"><div class="json_message">
	<?php
	json_saveLineDetail('om_so', 'om_so_line', 'item_description', 'om_so_line_id', 'om_so_detail', 'shipment_number', 'om_so_detail_id');
	?>
 </div></div>
<div id="json_delete_line"> <?php json_delete('om_so_line'); ?> </div>

<?php include_template('footer.inc') ?>