<?php include_once("address.inc"); ?>

<div id="structure">
    <div id="address"><div id="address_details">
            <h2>All addresses </h2>
                      
            <?php address::address_page(); ?>
<!--            end of table-->
        </div>
    </div>
    <p><br/>
              
  </div>
<!--   end of structure-->

<?php include_template('footer.inc') ?>
