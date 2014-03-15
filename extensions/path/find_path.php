<?php include_once("path.inc"); ?>
<div id="find_structure">    
  <div id="path">        
    <div id="path_details">            
      <h2>Paths </h2>
      <?php
      echo '<table class="normal">
                <thead>
				<tr>
                  <th>Path Id</th>
                  <th>Name</th>
                  <th>Description</th>
                  <th>Action</th>
				</tr> 
				</thead>
                <tbody>';

      $path = path::find_all();
      foreach ($path as $record) {
        echo '<tr><td>' . $record->path_id . '</td>';
        echo '<td>' . $record->name . '</td>';
        echo '<td>' . $record->description . '</td>';
        echo '<td><input type="radio" name="select_path_id" class="select_path_id"                 
				value="' . $record->path_id . '"></td>';
      }
      echo ' </tbody> </table>';
      ?>               <!--            end of table-->        
    </div>    
  </div>    
  <div class="form_submit">        
    <ul>   
      <li> <input type="button"  id="selected" value="Select Option"></li>            
      <li> <div class="button-cancel"> <a href="path.php">Cancel Action</a> </div></li>        
    </ul>    
  </div>
</div><!--   end of structure-->

<?php include_template('footer.inc') ?>