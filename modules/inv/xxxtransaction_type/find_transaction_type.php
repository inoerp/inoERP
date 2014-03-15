<?php include_once("../../../include/basics/header_find.inc"); ?>
<script src="transaction_type.js"></script>
<div id="structure">    
  <div id="transaction_type">        
    <div id="transaction_type_details">            
      <h2>Item Headers </h2>
      <?php
      $result = array();
      $transaction_type = new transaction_type();
      $search_array = transaction_type::$field_array;
      foreach ($search_array as $key => $value) {
        if (empty($_POST[$value])) {
          $_POST[$value] = "";
        }
      }

      if (empty($_POST['submit_search'])) {
        $column_array = ["inventory_id",
            "transaction_type_number",
            "transaction_type_type",
            "transaction_type",
            "transaction_type_status",
            "created_by",
            "creation_date"
        ];
      }
      ?>

      <?php
      $whereFields = array();
      if (!empty($_POST['submit_search'])) {
        $column_var = $_POST["column_array"];
        $column_array = unserialize(base64_decode($column_var));

        if (!empty($_POST['new_column'])) {
          $new_column = $_POST['new_column'];
          array_push($column_array, $new_column);
        }

        foreach ($search_array as $key => $value) {
          if (!empty($_POST[$value])) {
            $whereFields[] = sprintf("`%s` LIKE '%%%s%%'", $value, trim(mysql_prep($_POST[$value])));
          } else {
            $msg = "No criteria entered";
          }
        }

        if (count($whereFields) > 0) {
          // Construct the WHERE clause by gluing the fields
          // together with a " AND " separator.
          $whereClause = "WHERE " . implode(" AND ", $whereFields);

          // And then create the SQL query itself.
          $sql = "SELECT * FROM transaction_type " . $whereClause;
        } else {
          $sql = "SELECT * FROM transaction_type ";
        }
        $result = transaction_type::find_by_sql($sql);
      }
      ?>

      <br><br>
      <form action="find_transaction_type.php" name="search_transaction_type" method="POST" class="search_transaction_type" id="search_transaction_type">
        <ul class="search_form">                   
          <li><label>Item Number : </label>
            <input type="text" id="transaction_type_number" name="transaction_type_number" value="<?php echo htmlentities($_POST['transaction_type_number']); ?>" 
                   maxlength="50" >
          </li>
          <li><label>Inventory Id : </label>
            <input type="search" name="inventory_id" id="inventory_id" value="<?php echo htmlentities($_POST['inventory_id']); ?>" 
                   maxlength="50" >
          </li>
          <li><label>Item Type : </label>
            <input type="search" name="transaction_type_type" id="transaction_type_type" value="<?php echo htmlentities($_POST['transaction_type_type']); ?>" 
                   maxlength="50" >
          </li>
          <li>
            <label>last_update_by : </label>
            <input id="last_update_by" type="search" maxlength="50" value="<?php echo htmlentities($_POST['last_update_by']); ?>" name="last_update_by">
          </li>
          <li><label>Planner : </label>
            <input type="search" name="planner" id="planner" value="<?php echo htmlentities($_POST['planner']); ?>" 
                   maxlength="50" >
          </li>
          <li>
          <lable>Add dynamic search criteria </lable>
          <select name="new_search_criteria" id="new_search_criteria" class="new_search_criteria"> 
            <option value=""> </option>
            <?php
            foreach ($search_array as $key => $value) {
              echo '<option value="' . htmlentities($value) . '"';
              echo '>' . $value . '</option>';
            }
            ?> 
          </select>
          </li>
          <li>
            <input type="button" class="add button" id="new_search_criteria_add" value="Add">
          </li>
          <!--          send the existing column array to POST-->
          <li><input type="hidden" name="column_array" id="column_array" value="<?php print base64_encode(serialize($column_array)) ?>" >
          </li>
        </ul>
        <ul class="add_new_search">
          <li>
          <lable>Add a new column</lable>
          <select name="new_column" id="new_column" > 
            <option value=""> </option>
            <?php
            foreach ($search_array as $key => $value) {
              echo '<option value="' . htmlentities($value) . '"';
              echo '>' . $value . '</option>';
            }
            ?> 
          </select>

          </li>
        </ul>
        <ul class="form_buttons">
          <li><input type="reset" form="search_transaction_type" name="reset_search" class="reset button" value="Reset All"></li>
          <li><input type="submit" form="search_transaction_type" name="submit_search" class="search button" value="Search"></li>

        </ul>
      </form> 
      <table class="normal">
        <thead> 
          <tr>
            <th>Click Select</th>
            <?php
            foreach ($column_array as $key => $value) {
              echo '<th>' . $value . '</th>';
            }
            ?>
             <th>Action</th>
          </tr>
        </thead>

        <?php
        If ($result) {
          echo '<tbody>';
          foreach ($result as $record) {
            echo '<tr>';
            echo '<td><input type="button" class="quick_select button"
          value="' . $record->transaction_type_id . '"></td>';
            $inventory_org = inventory_org::find_by_id($record->inventory_id);
            foreach ($column_array as $key => $value) {
              echo '<td>' . $record->$value . '</td>';
            }
            echo '<td><input type="radio" name="select_transaction_type_id" class="select_transaction_type_id"                 
				value="' . $record->transaction_type_id . '"></td>';
            echo '</tr>';
          }
          echo '</tbody>';
        }
        ?>

      </table>

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