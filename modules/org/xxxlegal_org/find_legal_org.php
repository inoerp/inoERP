<?php include_once("../../../include/basics/header_find.inc"); ?>
<script src="legal_org.js"></script>
<div id="structure">    
  <div id="legal_org">        
    <div id="legal_org_details">            
      <h2>Legal Organizations </h2>
      <?php
      echo '<table class="normal">
                <thead>
				<tr>
                  <th>Legal Org Id</th>
				  <th>Org Id</th>
                  <th>Name</th>
                  <th>Description</th>
                  <th>Action</th>
				</tr> 
				</thead>
                <tbody>';

      $legal_org = legal_org::find_all();
      foreach ($legal_org as $record) {
        $org = org_header::find_by_legal_id($record->legal_id);
        echo '<tr><td><input type="button" class="quick_select button"
          value="' . $record->legal_id . '"></td>';
		echo '<td>' . $org->org_id . '</td>';
        echo '<td>' . $org->name . '</td>';
        echo '<td>' . $org->description . '</td>';
        echo '<td><input type="radio" name="select_legal_id" class="select_legal_id"                 
				value="' . $record->legal_id . '"></td>';
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

<?php include_template('footer_find.inc') ?>