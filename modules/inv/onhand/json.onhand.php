<?php include_once("subinventory_simple.inc"); ?>

<div id="new_search_criteria">
  <?php
  if (!empty($_GET["new_search_criteria"])) {
    $new_search_criteria = $_GET["new_search_criteria"];
     }
  ?>
  <li><label><?php echo $new_search_criteria ;?> : </label>
    <input type="search" name="<?php echo $new_search_criteria ;?>" id="<?php echo $new_search_criteria ;?>" 
           value="" 
           maxlength="50" >
  </li>
</div>

<?php include_template('footer.inc') ?>