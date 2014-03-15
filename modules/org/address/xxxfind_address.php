<?php include_once("address.inc"); ?>
<div id="structure">    
  <div id="address">        
    <div id="address_details">            
      <h2>Addresses </h2>
      <?php
      echo '<table class="normal">
                <thead>
				<tr>
                  <th>Address Id</th>
                  <th>Name</th>
                  <th>Description</th>
                  <th>Action</th>
				</tr> 
				</thead>
                <tbody>';

      $address = address::find_all();
      foreach ($address as $record) {
        echo '<tr><td>' . $record->address_id . '</td>';
        echo '<td>' . $record->name . '</td>';
        echo '<td>' . $record->description . '</td>';
        echo '<td><input type="radio" name="select_address_id" class="select_address_id"                 
				value="' . $record->address_id . '"></td>';
      }
      echo ' </tbody> </table>';
      ?>               <!--            end of table-->        
    </div>    
  </div>    
  <div class="form_submit">        
    <ul>   
      <li> <input type="button" class="button"  id="selected_address_id" value="Select Option">          
      <input type="button" class="button" onclick="window.close()" value="Cancel Action"></li>        
    </ul>    
  </div>
</div><!--   end of structure-->

<?php include_template('footer.inc') ?>