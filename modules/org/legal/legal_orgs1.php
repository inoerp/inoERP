<?php include_once("enterprise.inc"); ?>
<div id="structure">
  <div id="enterprise">
    <div id="enterprise_details">
      <h2>All Enterprises </h2>
      <?php
      enterprise::enterprise_page();
      echo '<hr>';
      ?>

    </div>
  </div>
</div>
<!--   end of structure-->
<?php include_template('footer.inc') ?>
