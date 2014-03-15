<?php $pageTitle = " transaction_types - View, Download, Print & Update all transaction_types "; ?>
<?php include_once("transaction_type.inc"); ?>
<?php
$page = !(empty($_GET['page'])) ? (int) $_GET['page'] : 1;

if(!(empty($_GET['per_page']))){
  if($_GET['per_page']=="all"){
  $per_page = "";
    }
  else{
    $per_page =(int) $_GET['per_page'];
  }
}else{
$per_page =  10;
}

?>
<div id='pageTitle'>All transaction_types</div>
<div id="structure">
  <div id="transaction_type">
    <div id="transaction_type_details">
      <h2>All transaction_types </h2>
      <div id="loading"><img alt="Loading..." 
                             src="<?php echo HOME_URL; ?>themes/images/loading.gif"/></div>
        <?php
        $result = array();
        $transaction_type = new transaction_type();
        $search_array = transaction_type::$field_array;

        //field array represents all fields
        if (!empty($_SERVER['QUERY_STRING'])) {
          $query_string = $_SERVER['QUERY_STRING'];
          if (!empty($_GET['page'])) {
            $query_string = substr($query_string, 7);
          }
        } else {
          $query_string = "";
        }

        if (empty($_GET['search_array'])) {
          foreach ($search_array as $key => $value) {
            if (empty($_GET[$value])) {
              $_GET[$value] = "";
            }
          }
        }
        //column array contains fixed columns of the table shown by default
        if (empty($_GET['column_array'])) {
          $column_array = ["transaction_type_id",
              "class",
              "transaction_type",
              "description",
              "primary",
              "created_by",
              "creation_date"
          ];
        } else {
          $column_var = $_GET["column_array"];
          $column_array = unserialize(base64_decode($column_var));
        }
        ?>

      <?php
      $whereFields = array();

      if (!empty($_GET)) {

        if (!empty($_GET['new_column'])) {
          $new_column = $_GET['new_column'];
          array_push($column_array, $new_column);
        }

        foreach ($search_array as $key => $value) {
          if (!empty($_GET[$value])) {
            $whereFields[] = sprintf("`%s` LIKE '%%%s%%'", $value, trim(mysql_prep($_GET[$value])));
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
          $count_sql = "SELECT COUNT(*) FROM transaction_type " . $whereClause;
          $all_download_sql = "SELECT * FROM transaction_type " . $whereClause;
        } else {
          $sql = "SELECT * FROM transaction_type ";
          $count_sql = "SELECT COUNT(*) FROM transaction_type ";
          $all_download_sql = "SELECT * FROM transaction_type ";
        }

        $total_count = transaction_type::count_all_by_sql($count_sql);

        if(!empty($per_page)){
        $pagination = new pagination($page, $per_page, $total_count);
//        $offset = isset($pagination) ? $pagination->offset() : 0;
        $sql .=" LIMIT {$per_page} ";
        $sql .=" OFFSET {$pagination->offset()}";
        }
        $result = transaction_type::find_by_sql($sql);
      }
      ?>

      <br><br>
      <form action="transaction_types.php" name="search_transaction_type" method="GET" class="search_box transaction_type_form" id="search_transaction_type">
        <ul class="search_form">                   
          <li><label>transaction_type Id : </label>
            <input type="text" id="transaction_type_id" name="transaction_type_id" value="<?php echo htmlentities($_GET['transaction_type_id']); ?>" 
                   maxlength="50" >
          </li>
          <li><label>transaction_type Class : </label>
            <input type="search" name="class" id="class" value="<?php echo htmlentities($_GET['class']); ?>" 
                   maxlength="50" >
          </li>
          <li><label>Unit of measure : </label>
            <input type="search" name="transaction_type" id="transaction_type" value="<?php echo htmlentities($_GET['transaction_type']); ?>" 
                   maxlength="50" >
          </li>
          <li>
            <label>Description : </label>
            <input id="description" type="search" maxlength="50" value="<?php echo htmlentities($_GET['description']); ?>" name="description">
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
          <li><input type="hidden" name="column_array" id="column_array" value="<?php print base64_encode(serialize($column_array)) ?>" ></li>
          <!--     send existing search criteria-->

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
          <li>
          <lable>Records per page</lable>
          <select name="per_page" id="per_page" > 
            <option value="10">10</option>
            <option value="20" <?php echo $per_page ==20 ? "selected" : "" ?>>20</option>
            <option value="50" <?php echo $per_page ==50 ? "selected" : "" ?>>50</option>
            <option value="100" <?php echo $per_page ==100 ? "selected" : "" ?>>100</option>
            <option value="1000" <?php echo $per_page ==1000 ? "selected" : "" ?>>1000</option>
            <option value="all" <?php echo  $per_page =="all" ? "selected" : "" ?>>All</option>
            <option value="1" <?php echo $per_page ==1 ? "selected" : "" ?>>1</option>
         </select>

          </li>
        </ul>
        <ul class="form_buttons">
          <li><a href="transaction_types.php" class="reset button"> Reset All</a></li>
          <li><input type="submit" form="search_transaction_type" name="submit_search" class="search button" value="Search"></li>

        </ul>
      </form> 

      <?php
      if (!empty($total_count)) {
        echo '<h3>Total records : ' . $total_count . '</h3>';
      }
      ?>
      <div id="scrollElement">
      <div id="print">
        <table class="normal">
          <thead> 
            <tr>
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
              foreach ($column_array as $key => $value) {
                echo '<td>' . $record->$value . '</td>';
              }
              echo '<td><a href="transaction_type.php?transaction_type_id=' . $record->transaction_type_id . '">Update</a></td>';
              echo '</tr>';
            }
            echo '</tbody>';
          }
          ?>

        </table>
      </div>
      </div>
      <div id="pagination" style="clear: both;">
        <?php
        if (isset($pagination) && $pagination->total_pages() > 1) {
          if ($pagination->has_previous_page()) {
            echo "<a href=\"transaction_types.php?page=";
            echo $pagination->previous_page() . '&' . $query_string;
            echo "\"> &laquo; Previous </a> ";
          }

          for ($i = 1; $i <= $pagination->total_pages(); $i++) {
            if ($i == $page) {
              echo " <span class=\"selected\">{$i}</span> ";
            } else {
              echo " <a href=\"transaction_types.php?page={$i}&" . remove_querystring_var($query_string, 'page');
              echo '\">' . $i . '</a>';
            }
          }

          if ($pagination->has_next_page()) {
            echo " <a href=\"transaction_types.php?page=";
            echo $pagination->next_page() . '&' . remove_querystring_var($query_string, 'page');
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
        $transaction_type_obj = transaction_type::find_by_sql($sql);
        $transaction_type_array = json_decode(json_encode($transaction_type_obj), true);
      }
      ?>
      <!--download page form-->
      <form action="<?php echo HOME_URL; ?>download.php" method="POST" name="download" id="download">
        <input type="hidden"  name="data" value="<?php print base64_encode(serialize($transaction_type_array)) ?>" >

      </form>

      <!--download page creation for all records-->
      <?php
      if (!empty($all_download_sql)) {
        $transaction_type_obj_all = transaction_type::find_by_sql($all_download_sql);
        $transaction_type_array_all = json_decode(json_encode($transaction_type_obj_all), true);
      }
      ?>
      <!--download page form-->
      <form action="<?php echo HOME_URL; ?>download.php" method="POST" name="download_all" id="download_all">
        <input type="hidden"  name="data" value="<?php print base64_encode(serialize($transaction_type_array_all)) ?>" >
      </form>
      <!--download page completion-->

    </div>
  </div>
</div>
<!--   end of structure-->
<?php include_template('footer.inc') ?>
