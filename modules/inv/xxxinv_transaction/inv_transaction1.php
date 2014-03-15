<?php $pageTitle = " Inventory Transactions - Create & Update all Inventory Transaction "; ?>
<?php include_once("../../../include/basics/header.inc"); ?>
<?php include_once("inv_transaction_functions.inc"); ?>

<script src="inv_transaction.js"></script>
<div id="structure">
 <div id="inv_transaction">
  <div id="form_top">
   <ul class="form_top">
    <li><input type="button" class="button refresh" value="Refresh" name="refresh"/> </li>
    <li> <a class="button" href="inv_transaction.php">New Object</a> </li>
    <li><input type="button" id="add_object" class="button" value="New Line" name="add_object"/> </li>
    <li><input type="submit" form="inv_transaction_header" name="submit_inv_transaction" id="submit_inv_transaction" class="button" Value="Save"></li>
    <li> <input type="button" class="button remove_row" id="remove_row" Value="Remove"></li>
    <li> <input type="submit" class="button delete" form="coa_combination_form" name="delete_row" id="delete_row" value="Delete"></li>
    <li><input type="reset" class="button" form="inv_transaction_header" name="reset" Value="Reset All"></li>
    <li><script>document.write('<a class="button" href="' + document.referrer + '">Go Back</a>');</script></li>
   </ul>
  </div>
  <!--    START OF FORM HEADER-->
  <div id ="form_header">
   <ul id="form_box"> 
    <li>   <!--    Place for showing error messages-->
     <?php
     $x= 0;
     if (!empty($msg)) {
      echo '<div id="dialog_box">';
      if (is_array($msg)) {
       foreach ($msg as $key => $value) {
        if (is_array($value)) {
         foreach ($value as $key1 => $value1) {
          $x ++;
          echo 'Message ' . $x . ' : ' . $value1 . '<br />';
         }
        } else {
         $x++;
         echo 'Message ' . $x . ' : ' . $value . '<br />';
        }
       } 
      }
      else {
        echo $msg;
       }

       echo '</div>';
      }
      ?> 
      <!--    End of place for showing error messages-->
     </li>


     <li>
      <div id="scrollElement">
       <form action="inv_transaction.php"  method="post" id="inv_transaction_header"  name="inv_transaction_header">
        <!--create empty form or a single id when search is not clicked and the id is referred from other page -->
        <span class="heading">Inventory Transaction </span> 
        <table class="form_table">
         <tr>
          <td><lable>Inventory Org </lable>
         <select name="org_id[]" id="org_id" class="org_id" required> 
          <option value=""> </option>
          <?php
          $inventory_org = org_header::find_all_inventory_org();
          foreach ($inventory_org as $key => $value) {
           echo '<option value="' . htmlentities($value->org_id) . '"';
           echo ($inv_transaction->org_id == $value->org_id) ? " selected" : "";
           echo '>' . $value->name . '</option>';
          }
          ?> 
         </select>
         </td>
         <td><lable>Transaction Type </lable>
         <select name="transaction_type_id[]" id="transaction_type_id" class="transaction_type_id" required> 
          <option value=""> </option>
          <?php
          $transaction_type = transaction_type::find_all();
          foreach ($transaction_type as $key => $value) {
           echo '<option value="' . htmlentities($value->transaction_type_id) . '"';
           echo ($inv_transaction->transaction_type_id == $value->transaction_type_id) ? " selected" : "";
           echo '>' . $value->type . '</option>';
          }
          ?> 
         </select>
         </td>
         </tr>
        </table>
        <div id="tabs">
         <ul class="tabMain">
          <li><a href="#tabs1">General Info</a></li>
          <li><a href="#tabs2">Reference Info</a></li>
          <li><a href="#tabs3">Finance Info</a></li>
         </ul>
         <div id="tabs1">
          <table class="form_table">
           <thead> 
            <tr>
             <th>Action</th>
             <th>Item Number</th>
             <th>UOM</th>
             <th>Quantity</th>
             <th>From SubInv</th>
             <th>From Locator </th>
             <th>To SubInv</th>
             <th>To Locator</th>

            </tr>
           </thead>
           <tbody class="inv_transaction_values">
            <tr id="inv_transaction_rowtab1">
             <td>    
              <ul class="inline_action">
               <li class="add_row_img"><img  src="<?php echo HOME_URL; ?>themes/images/add.png"  alt="add new line" /></li>
               <li class="remove_row_img"><img src="<?php echo HOME_URL; ?>themes/images/remove.png" alt="remove this line" /> </li>
               <li><input type="checkbox" name="inv_transaction_id_cb" value="<?php echo htmlentities($inv_transaction->transaction_id); ?>"></li>
              </ul>
             </td>
             <td>
              <a href="../item/find_item.php" class="item_number popup"> 
               <img src="<?php echo HOME_URL; ?>themes/images/serach.png"/></a> 
              <input type="text"  name="item_number[]" id="item_number" size="15" value="<?php echo htmlentities($inv_transaction->item_number); ?>" 
                     maxlength="50" id="item_number" placeholder="Enter the item no"> 
             </td>
             <td>
              <input type="text"  name="uom_id[]" id="uom_id" size="10" value="<?php echo htmlentities($inv_transaction->uom_id); ?>" 
                     maxlength="50" placeholder="Unit of measure"> 
             </td>
             <td>
              <input type="text" name="quantity[]" value="<?php echo htmlentities($inv_transaction->quantity); ?>" 
                     size="10" maxlength="20"  id="quantity"> 
             </td>
             <td>
              <select name="from_subinventory_id[]" id="from_subinventory_id" class="from_subinventory_id" > 
               <option value="Select Org" disabled> </option>
              </select>
             </td>
             <td>
              <select name="from_locator_id[]" id="from_locator_id" class="from_locator_id" > 
               <option value="Select Org" disabled> </option>
              </select>
             </td>
             <td>
              <select name="to_subinventory_id[]" id="to_subinventory_id" class="to_subinventory_id" > 
               <option value="Select Org" disabled> </option>
              </select>
             </td>
             <td>
              <select name="to_locator_id[]" id="to_locator_id" class="to_locator_id" > 
               <option value="Select Org" disabled> </option>
              </select>
             </td>
            </tr>
           </tbody>
          </table>
         </div>
         <div id="tabs2">
          <table class="form_table">
           <thead> 
            <tr>
             <th>Lot</th>
             <th>Serial</th>
             <th>Document Type</th>
             <th>Doc. Number</th>
             <th>Doc. Id</th>
             <th>Reason</th>
             <th>Reference</th>
             <th>Description</th>
             <th>Ef Id</th>
            </tr>
           </thead>
           <tbody class="inv_transaction_values">
            <tr id="inv_transaction_rowtab2">
             <td>
              <input type="text" name="lot_number[]" value="<?php echo htmlentities($inv_transaction->lot_number); ?>" 
                     size="10" maxlength="50"  id="lot_number"> 
             </td>
             <td>
              <input type="text" name="serial_number[]" value="<?php echo htmlentities($inv_transaction->serial_number); ?>" 
                     size="10" maxlength="50"  id="serial_number"> 
             </td>
             <td>
              <input type="text" name="document_type[]" value="<?php echo htmlentities($inv_transaction->document_type); ?>" 
                     size="15" maxlength="150"  id="document_type"> 
             </td>
             <td>
              <input type="text" name="document_number[]" value="<?php echo htmlentities($inv_transaction->document_number); ?>" 
                     size="15" maxlength="150"  id="document_number"> 
             </td>
             <td>
              <input type="text" name="document_id[]" value="<?php echo htmlentities($inv_transaction->document_id); ?>" 
                     size="5" maxlength="150"  id="document_id"> 
             </td>
             <td>
              <input type="text" name="reason[]" value="<?php echo htmlentities($inv_transaction->reason); ?>" 
                     size="15" maxlength="150"  id="reason"> 
             </td>
             <td>
              <input type="text" name="reference[]" value="<?php echo htmlentities($inv_transaction->reference); ?>" 
                     size="15" maxlength="10"  id="reference"> 
             </td>
             <td>
              <input type="text" name="description[]" value="<?php echo htmlentities($inv_transaction->description); ?>" 
                     size="25" maxlength="150"  id="description"> 
             </td>
             <td>
              <input type="text" name="ef_id[]" value="<?php echo htmlentities($inv_transaction->ef_id); ?>" 
                     size="5" maxlength="20"  id="ef_id"> 
             </td>

            </tr>
           </tbody>
          </table>
         </div>
         <div id="tabs3">
          <table class="form_table">
           <thead> 
            <tr>
             <th>Account</th>
             <th>Amount</th>
             <th>Costed Amount</th>
             <th>Transferred To GL<th>
            </tr>
           </thead>
           <tbody class="inv_transaction_values">
            <tr id="inv_transaction_rowtab3">
             <td>
              <input type="text" name="account[]" value="<?php echo htmlentities($inv_transaction->account); ?>" 
                     size="25" maxlength="150"  id="account"> 
             </td>
             <td>
              <input type="text" name="amount[]" value="<?php echo htmlentities($inv_transaction->amount); ?>" 
                     size="15" maxlength="10"  id="amount"> 
             </td>
             <td>
              <input type="text" name="costed_amount[]" value="<?php echo htmlentities($inv_transaction->costed_amount); ?>" 
                     size="15" maxlength="10"  id="costed_amount"> 
             </td>
             <td>
              <input type="checkbox" name="rev_enabled0" readonly
                     value="1"
                     <?php
                     if ($inv_transaction->transfer_to_gl == 1) {
                      echo " checked";
                     } else {
                      echo "";
                     }
                     ?> >  
             </td> 

            </tr>
           </tbody>
          </table>
         </div>
        </div>

        <!--                 complete Showing a blank form for new entry-->
       </form>
      </div>  

     </li>

    </ul>
    <div id="pagination" style="clear: both;">
     <?php
     if (isset($pagination)) {
      if ($pagination->has_previous_page()) {
       echo "<a href=\"inv_transaction.php?page=";
       echo $pagination->previous_page() . '&' . $query_string;
       echo "\"> &laquo; Previous </a> ";
      }

      for ($i = 1; $i <= $pagination->total_pages(); $i++) {
       if ($i == $page) {
        echo " <span class=\"selected\">{$i}</span> ";
       } else {
        echo " <a href=\"inv_transaction.php?page={$i}&" . remove_querystring_var($query_string, 'page');
        echo '&submit_search=Search';
        echo '\">' . $i . '</a>';
       }
      }

      if ($pagination->has_next_page()) {
       echo " <a href=\"inv_transaction.php?page=";
       echo $pagination->next_page() . '&' . remove_querystring_var($query_string, 'page');
       echo '&submit_search=Search';
       echo "\">Next &raquo;</a> ";
      }
     }
     ?>
    </div>


    <!--download page creation-->
    <ul class="data_export">
     <li> <input type="submit" class="download button excel" value="<?php echo $per_page ?> Records" form="download"></li>
     <li> <input type="submit" class="download button excel" value="All Records" form="download_all"></li>
     <li> <input type="button" class="download button print" value="Print"></li>
    </ul>

    <?php
    if (!empty($sql)) {
     $inv_transaction_obj = inv_transaction::find_by_sql($sql);
     $inv_transaction_array = json_decode(json_encode($inv_transaction_obj), true);
    }
    ?>
    <!--download page form-->
    <form action="<?php echo HOME_URL; ?>download.php" method="POST" name="download" id="download">
     <input type="hidden"  name="data" value="<?php print base64_encode(serialize($inv_transaction_array)) ?>" >

    </form>

    <!--download page creation for all records-->
    <?php
    if (!empty($all_download_sql)) {
     $inv_transaction_obj_all = inv_transaction::find_by_sql($all_download_sql);
     $inv_transaction_array_all = json_decode(json_encode($inv_transaction_obj_all), true);
    }
    ?>
    <!--download page form-->
    <form action="<?php echo HOME_URL; ?>download.php" method="POST" name="download_all" id="download_all">
     <input type="hidden"  name="data" value="<?php print base64_encode(serialize($inv_transaction_array_all)) ?>" >
    </form>
    <!--download page completion-->


   </div>
   <!--END OF FORM HEADER-->  
  </div>
 </div>
 <!--   end of structure-->

 <?php include_template('footer.inc') ?>
