<?php include_once("../../../include/basics/header_find.inc"); ?>
<script src="item.js"></script>
<div id="structure">    
  <div id="item">        
    <div id="item_details">            
      <h2>Item Headers </h2>
      <?php
      echo '<table class="normal">
                <thead>
				<tr>
                  <th>Item Id</th>
                  <th>Item Number</th>
                  <th>Item Description</th>
				  <th>Org Id</th>
                  <th>Org Name</th>
                  <th>Action</th>
				</tr> 
				</thead>
                <tbody>';

      $item = item::find_all();
      foreach ($item as $record) {
        $org = org_header::find_by_inventory_id($record->inventory_id);
        echo '<tr><td><input type="button" class="quick_select button"
          value="' . $record->item_id . '"></td>';
        echo '<td>' . $record->item_number . '</td>';
        echo '<td>' . $record->description . '</td>';
		echo '<td>' . $org->org_id . '</td>';
        echo '<td>' . $org->name . '</td>';
        echo '<td><input type="radio" name="select_item_id" class="select_item_id"                 
				value="' . $record->item_id . '"></td>';
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