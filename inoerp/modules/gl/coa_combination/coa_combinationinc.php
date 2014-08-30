<?php include_once("../../../include/basics/header.inc"); ?>
<?php require_once("class.coa_combination.inc"); ?>
<script src="coa_combination.js"></script>

<!--Put the navigation & other stuffs at the left Menu-->
<?php
  echo '<div id="left-block">';
  path::path_block();
path::path_menu();
  echo '</div>';
 path::path_menu();
?>