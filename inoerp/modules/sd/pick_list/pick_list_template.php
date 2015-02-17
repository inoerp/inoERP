<?php
if (empty($_SESSION['pick_list'])) {
 echo '<div class="jumbotron"><div class="alert alert-danger alert-dismissible" role="alert"><h1>No Pick List Found.</h1> <br>'
 . '<p class="lead">Navigate to Pick Sales Order and Pick Orders to Pick List</p></div></div>';
 return;
}
?>
<div class="col-sm-12 col-md-12">
 <?php
 echo show_download_button($data_ar);
 ?>
</div>
<div class="col-sm-12 col-md-12">
 <?php
// pa($posData);
 $f->data_arrOfObjs = $data_ar;
 $f->column_array_s = ['item_number', 'item_description', 'staging_subinventory', 'staging_locator',
  'so_number', 'line_number', 'from_subinventory', 'from_locator', 'line_quantity', 'sd_so_line_id'];
 echo $f->show_arrayData_in_tabularTable();
 ?>
</div>