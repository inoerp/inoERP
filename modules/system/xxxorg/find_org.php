<?php include_once("option_simple.inc"); ?>
<div id="structure">    
  <div id="option">        
    <div id="option_details">            
      <h2>Option Headers </h2>
      <?php
      echo '<table class="normal">
                <thead>
				<tr>
				<th>Option Id</th>                    
				<th>Type</th>                    
	            <th>Description</th>                    
				<th>Module</th>
                <th>Status</th>
				<th>Action</th> 
				</tr> 
				</thead>
                <tbody>';

      $option = option_header::find_all_headers();
      foreach ($option as $record) {
        echo '<tr><td>' . $record->option_id . '</td>';
        echo '<td>' . $record->option_type . '</td> ';
        echo '<td>' . $record->description . '</td>';
        echo '<td>' . $record->module . '</td>';
        echo '<td>' . $record->status . '</td>';
        echo '<td><input type="radio" name="select_option_id" class="select_option_id"                 
				value="' . $record->option_id . '"></td>';
      }
      echo ' </tbody> </table>';
      ?>               <!--            end of table-->        
    </div>    
  </div>    
  <div class="form_submit">        
    <ul>   
      <li> <input type="button"  id="selected" value="Select Option"></li>            
           
    </ul>    
  </div>
</div><!--   end of structure-->

<?php include_template('footer.inc') ?>