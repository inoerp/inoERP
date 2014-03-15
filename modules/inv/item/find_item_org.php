<?php include_once("../../../include/basics/header_find.inc"); ?>
<script src="inventory_org.js"></script>
<div id="find_structure">    
  <div id="inventory_org">        
    <div id="inventory_org_details">            
      <h2>Enterprise Headers </h2>
      <?php
      echo '<table class="normal">
                <thead>
				<tr>
                  <th>Inventory Org Id</th>
				  <th>Org Id</th>
                  <th>Name</th>
                  <th>Description</th>
                  <th>Action</th>
				</tr> 
				</thead>
                <tbody>';

      $inventory_org = inventory_org::find_all();
      foreach ($inventory_org as $record) {
        $org = org_header::find_by_org_id($record->org_id);
        echo '<tr><td><input type="button" class="quick_select button"
          value="' . $record->org_id . '"></td>';
		echo '<td>' . $org->org_id . '</td>';
        echo '<td>' . $org->name . '</td>';
        echo '<td>' . $org->description . '</td>';
        echo '<td><input type="radio" name="select_org_id" class="select_org_id"                 
				value="' . $record->org_id . '"></td>';
      }
      echo ' </tbody> </table>';
      ?>               <!--            end of table-->        
    </div>    
  </div>    
  <div class="form_submit">        
    <ul>   
      <li> <input type="button" id="selected" class="button" value="Select Option">
      <input type="button" class="button" onclick="window.close()" value="Cancel Action">
      </li>        
    </ul>    
  </div>
</div><!--   end of structure-->

<?php include_template('footer.inc') ?>