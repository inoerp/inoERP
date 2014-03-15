<?php $pageTitle = " inv_transactions - View, Download, Print & Update all inv_transactions "; ?>
<?php include_once("../../../include/basics/header.inc"); ?>
<script src="inv_transaction.js"></script>


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
<div id='pageTitle'>All inv_transactions</div>
<div id="structure">
  <div id="inv_transaction">
    <div id="inv_transaction_details">
      <h2>All inv_transactions </h2>
      <div id="loading"><img alt="Loading..." 
                             src="<?php echo HOME_URL; ?>themes/images/loading.gif"/></div>
        <?php
        $result = array();
        $inv_transaction = new inv_transaction();
        $search_array = inv_transaction::$field_array;

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
            $column_array = ["inv_transaction_id",
                "type",
                "type_class",
                "transaction_action",
                "description",
                "allow_negative_balance",
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
          $sql = "SELECT * FROM inv_transaction " . $whereClause;
          $count_sql = "SELECT COUNT(*) FROM inv_transaction " . $whereClause;
          $all_download_sql = "SELECT * FROM inv_transaction " . $whereClause;
        } else {
          $sql = "SELECT * FROM inv_transaction ";
          $count_sql = "SELECT COUNT(*) FROM inv_transaction ";
          $all_download_sql = "SELECT * FROM inv_transaction ";
        }

        $total_count = inv_transaction::count_all_by_sql($count_sql);

        if(!empty($per_page)){
        $pagination = new pagination($page, $per_page, $total_count);
//        $offset = isset($pagination) ? $pagination->offset() : 0;
        $sql .=" LIMIT {$per_page} ";
        $sql .=" OFFSET {$pagination->offset()}";
        }
        $result = inv_transaction::find_by_sql($sql);
      }
      ?>

      <br><br>
      <div id="inv_transaction_search">
            <br>
            <form action="inv_transactions.php" name="search_inv_transaction" method="GET" class="search_box inv_transaction_form" id="search_inv_transaction">
              <ul class="search_form">                   
                <li><label>Transaction Type Id : </label>
                  <input type="text" id="inv_transaction_id" name="inv_transaction_id" value="<?php
                  echo!(is_array($_GET['inv_transaction_id'])) ? htmlentities($_GET['inv_transaction_id']) : "";
                  ?>" maxlength="50" >
                </li>
                <li><label>Transaction Type: </label>
                  <input type="search" name="inv_transaction" id="inv_transaction" value="<?php
                  echo!(is_array($_GET['type'])) ? htmlentities($_GET['type']) : "";
                  ?>"  maxlength="50" >
                </li>
                <li><label>Type Class : </label>
                  <select name="type_class" id="type_class" class="type_class"> 
                    <option value=""> </option>
                    <?php
                    $type_class = inv_transaction::inv_transaction_class();
                    foreach ($type_class as $key => $value) {
                      echo '<option value="' . htmlentities($value->option_line_code) . '"';
                      echo (($_GET['type_class']) == $value->option_line_code) ? "selected" : "";
                      echo '>' . $value->description_l . '</option>';
                    }
                    ?> 
                  </select>
                </li>
                <li><label>Transaction Action : </label>
                  <select name="transaction_action" id="transaction_action" class="transaction_action"> 
                    <option value=""> </option>
                    <?php
                    $transaction_action = inv_transaction::transaction_action();
                    foreach ($transaction_action as $key => $value) {
                      echo '<option value="' . htmlentities($value->option_line_code) . '"';
                      echo(($_GET['transaction_action']) == $value->option_line_code) ? "selected" : "";
                      echo '>' . $value->description_l . '</option>';
                    }
                    ?> 
                  </select>
                </li>
                <li>
                  <label>Description : </label>
                  <input id="description" type="search" maxlength="50" value="<?php
                  echo!(is_array($_GET['description'])) ? htmlentities($_GET['description']) : "";
                  ?>" name="description">
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
                <li>
                <lable>Records per page</lable>
                <select name="per_page" id="per_page" > 
                  <option value="10">10</option>
                  <option value="20" <?php echo $per_page == 20 ? "selected" : "" ?>>20</option>
                  <option value="50" <?php echo $per_page == 50 ? "selected" : "" ?>>50</option>
                  <option value="100" <?php echo $per_page == 100 ? "selected" : "" ?>>100</option>
                  <option value="1000" <?php echo $per_page == 1000 ? "selected" : "" ?>>1000</option>
                  <option value="all" <?php echo $per_page == "all" ? "selected" : "" ?>>All</option>
                  <option value="1" <?php echo $per_page == "1" ? "selected" : "" ?>>1</option>
                </select>
                </li>
              </ul>
              <ul class="form_buttons">
                <li><a href="inv_transaction.php" class="reset button"> Reset All</a></li>
                <li><input type="submit" form="search_inv_transaction" name="submit_search" class="search button" value="Search"></li>

              </ul>
            </form> 

          </div>

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
                switch  ($value){
                case "transaction_action":
                    $transaction_action = inv_transaction::transaction_action_description($record->$value);
                    $option_line=$transaction_action[0];
                    echo '<td>' . $option_line->description_l . '</td>';
                    break;
                
                  default : 
                    echo '<td>' . $record->$value . '</td>';
                }
              }
              echo '<td><a href="inv_transaction.php?inv_transaction_id=' . $record->inv_transaction_id . '">Update</a></td>';
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
            echo "<a href=\"inv_transactions.php?page=";
            echo $pagination->previous_page() . '&' . $query_string;
            echo "\"> &laquo; Previous </a> ";
          }

          for ($i = 1; $i <= $pagination->total_pages(); $i++) {
            if ($i == $page) {
              echo " <span class=\"selected\">{$i}</span> ";
            } else {
              echo " <a href=\"inv_transactions.php?page={$i}&" . remove_querystring_var($query_string, 'page');
              echo '\">' . $i . '</a>';
            }
          }

          if ($pagination->has_next_page()) {
            echo " <a href=\"inv_transactions.php?page=";
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
        $inv_transaction_obj = inv_transaction::find_by_sql($sql);
        $inv_transaction_array = json_decode(json_encode($inv_transaction_obj), true);
      }
      ?>
      <!--download page form-->
      <form action="<?php echo HOME_URL; ?>download.php" method="POST" name="download" id="download">
        <input type="hidden"  name="data" value="<?php print base64_encode(serialize($inv_transaction_array)) ?>" >

      </form>

      <!--download page creation for all records-->
      <?php
      if (!empty($all_download_sql)) {
        $inv_transaction_obj_all = inv_transaction::find_by_sql($all_download_sql);
        $inv_transaction_array_all = json_decode(json_encode($inv_transaction_obj_all), true);
      }
      ?>
      <!--download page form-->
      <form action="<?php echo HOME_URL; ?>download.php" method="POST" name="download_all" id="download_all">
        <input type="hidden"  name="data" value="<?php print base64_encode(serialize($inv_transaction_array_all)) ?>" >
      </form>
      <!--download page completion-->

    </div>
  </div>
</div>
<!--   end of structure-->
<?php include_template('footer.inc') ?>
