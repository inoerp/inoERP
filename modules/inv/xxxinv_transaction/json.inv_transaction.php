<?php include_once("../../../include/basics/header.inc"); ?>
<script src="inv_transaction.js"></script>

<div id="json_save_header"> <?php 
//echo '<br/>in json inv trnx file';
//echo '<pre>';
//print_r($_POST);
//echo '<pre>';
json_save('inventory', 'inv_transaction', 'item_id', 'inv_transaction_id'); ?></div>
<div id="json_delete_line"> <?php  json_delete('inv_transaction'); ?> </div>

<?php include_template('footer.inc') ?>