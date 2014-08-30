<?php include_once("module.inc"); ?>
<div id="structure">
  <div id="module">
    <div id="odulem_details">
      <h2>All Modules </h2>
      <?php
      module::module_page();
      echo '<hr>';
      ?>

    </div>
  </div>
</div>
<!--   end of structure-->
<?php include_template('footer.inc') ?>
