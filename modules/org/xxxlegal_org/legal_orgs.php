<?php include_once("legal_org.inc"); ?>
<div id="structure">
  <div id="legal_org">
    <div id="legal_org_details">
      <h2>All Legal Orgs </h2>
      <?php
      legal_org::legal_org_page();
      echo '<hr>';
      ?>

    </div>
  </div>
</div>
<!--   end of structure-->
<?php include_template('footer.inc') ?>
