<?php $pageTitle = " All chart of accounts "; ?>
<?php include_once("../../../include/basics/header.inc"); ?>
<script src="coa.js"></script>

<div id="structure">
  <div id="coa">
    <div id="coa_details">
      <h2>All Chart of accounts </h2>
      <?php
      coa::coa_page();
      echo '<hr>';
      ?>

    </div>
  </div>
</div>
<!--   end of structure-->
<?php include_template('footer.inc') ?>
