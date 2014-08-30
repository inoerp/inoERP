<?php $pageTitle = " Find chart of accounts "; ?>
<?php include_once("../../../include/basics/header.inc"); ?>
<script src="coa.js"></script>
<div id="structure">    
  <div id="coa">        
    <div id="coa_details">            
      <h2>Chart of Accounts </h2>
      <?php
      echo '<table class="normal">
                <thead>
				<tr>
                  <th>COA Id</th>
                  <th>Name</th>
				  <th>Structure</th>
                  <th>Description</th>
                  <th>Action</th>
				</tr> 
				</thead>
                <tbody>';

      $coa = coa::find_all();
      foreach ($coa as $record) {
        echo '<tr><td>' . $record->coa_id . '</td>';
        echo '<td>' . $record->name . '</td>';
		echo '<td>' . $record->structure . '</td>';
        echo '<td>' . $record->description . '</td>';
        echo '<td><input type="radio" name="select_coa_id" class="select_coa_id"                 
				value="' . $record->coa_id . '||'.$record->name . '|1|'.$record->structure . '"></td>';
      }
      echo ' </tbody> </table>';
      ?>               <!--            end of table-->        
    </div>    
  </div>    
  <div class="form_submit">        
    <ul>   
      <li> <input type="button" id="selected" class="button" value="Select Option">
      <input type="button" class="button" onclick="window.close();" value="Cancel Action">
      </li>        
    </ul>    
  </div>
</div><!--   end of structure-->

<?php include_template('footer.inc') ?>