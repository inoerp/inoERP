<?php include_once("../../../../includes/basics/basics.inc"); ?>
<?php

 if (!empty($_GET['find_report_list']) && !empty($_GET['report_type'])) {
  $report_type = $_GET['report_type'];
  if ($report_type == 'block') {
   $block = new block();
   $block_i = $block->findAll();
   echo '<div id="return_divId">';
   foreach ($block_i as $b) {
    echo "<option value='{$b->block_id}' >" . $b->title . '</option>';
   }
   echo '</div>';
  } else if ($report_type == 'view') {
   $view = new view();
   $view_i = $view->findAll();
   echo '<div id="return_divId">';
   foreach ($view_i as $b) {
    echo "<option value='{$b->view_id}' >" . $b->view_name . '</option>';
   }
   echo '</div>';
  } else {
   return false;
  }
 }
?>