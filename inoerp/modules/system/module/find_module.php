<?php include_once("module.inc"); ?>
<div id="structure">    
  <div id="module">        
    <div id="module_details">            
      <h2>Option Headers </h2>
      <?php
      echo '<table class="normal">
                <thead>
				<tr>
                  <th>Module Id</th>
                  <th>Number</th>
                  <th>Name</th>
                  <th>Description</th>
                  <th>Action</th>
				</tr> 
				</thead>
                <tbody>';

      $module = module::find_all();
      foreach ($module as $record) {
        echo '<tr><td>' . $record->module_id . '</td>';
        echo '<td>' . $record->number . '</td> ';
        echo '<td>' . $record->name . '</td>';
        echo '<td>' . $record->description . '</td>';
        echo '<td><input type="radio" name="select_module_id" class="select_module_id"                 
				value="' . $record->module_id . '"></td>';
      }
      echo ' </tbody> </table>';
      ?>               <!--            end of table-->        
    </div>    
  </div>    
  <div class="form_submit">        
    <ul>   
      <li> <input type="button"  id="selected" value="Select Option"></li>            
      <li> <div class="button-cancel"> <a href="module.php">Cancel Action</a> </div></li>        
    </ul>    
  </div>
</div><!--   end of structure-->

<?php include_template('footer.inc') ?>