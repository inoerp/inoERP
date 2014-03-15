<?php $pageTitle=" uoms - View, Download, Print & Update all uoms " ;?>
<?php include_once("uom.inc"); ?>
<?php 
$page = !(empty($_GET['page'])) ? (int)$_GET['page'] : 1;
$per_page = 20;
$total_count = uom::count_all();

$pagination = new pagination($page, $per_page, $total_count );
?>
<div id='pageTitle'>All UOMs</div>
<div id="structure">
  <div id="uom">
    <div id="uom_details">
      <h2>All UOMs </h2>
      <?php
      $result = array();
      $uom = new uom();
      $search_array = uom::$field_array;
      foreach ($search_array as $key => $value) {
        if (empty($_POST[$value])) {
          $_POST[$value] = "";
        }
      }

      if (empty($_POST['submit_search'])) {
        $column_array = ["uom_id",
            "class",
            "uom",
            "description",
            "primary",
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
          $sql = "SELECT * FROM uom " . $whereClause;
        } else {
          $sql = "SELECT * FROM uom ";
        }
        $sql .=" LIMIT {$per_page} ";
        $sql .=" OFFSET {$pagination->offset()}";

        $result = uom::find_by_sql($sql);
//        echo '<pre>';
//        print_r($result);
//        echo '<pre>';
      }
      ?>

      <br><br>
      <form action="uoms.php" name="search_uom" method="POST" class="search_box uom_form" id="search_uom">
        <ul class="search_form">                   
          <li><label>UOM Id : </label>
            <input type="text" id="uom_id" name="uom_id" value="<?php echo htmlentities($_POST['uom_id']); ?>" 
                   maxlength="50" >
          </li>
          <li><label>UOM Class : </label>
            <input type="search" name="class" id="class" value="<?php echo htmlentities($_POST['class']); ?>" 
                   maxlength="50" >
          </li>
          <li><label>Unit of measure : </label>
            <input type="search" name="uom" id="uom" value="<?php echo htmlentities($_POST['uom']); ?>" 
                   maxlength="50" >
          </li>
          <li>
            <label>Description : </label>
            <input id="description" type="search" maxlength="50" value="<?php echo htmlentities($_POST['description']) ; ?>" name="description">
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
          <li><input type="reset" form="search_uom" name="reset_search" class="reset button" value="Reset All"></li>
          <li><input type="submit" form="search_uom" name="submit_search" class="search button" value="Search"></li>

        </ul>
      </form> 


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
            echo '<td><a href="uom.php?uom_id=' . $record->uom_id . '">Update</a></td>';
            echo '</tr>';
          }
          echo '</tbody>';
        }
        ?>

      </table>
      <div id="pagination" style="clear: both;">
<?php
	if($pagination->total_pages() > 1) {
		
		if($pagination->has_previous_page()) { 
    	echo "<a href=\"uoms.php?page=";
      echo $pagination->previous_page();
      echo "\">&laquo; Previous</a> "; 
    }

		for($i=1; $i <= $pagination->total_pages(); $i++) {
			if($i == $page) {
				echo " <span class=\"selected\">{$i}</span> ";
			} else {
				echo " <a href=\"uoms.php?page={$i}\">{$i}</a> "; 
			}
		}

		if($pagination->has_next_page()) { 
			echo " <a href=\"uoms.php?page=";
			echo $pagination->next_page();
			echo "\">Next &raquo;</a> "; 
    }
		
	}

?>
</div>
      <!--download page creation-->
      <?php
      if(!empty($sql))
      { 
      $uom_obj = uom::find_by_sql($sql);
      $uom_array = json_decode(json_encode($uom_obj), true);
      }
      ?>
            <!--download page form-->
      <form action="<?php echo HOME_URL; ?>download.php" method="POST" name="uom_download">
        <input type="hidden"  name="data" value="<?php print base64_encode(serialize($uom_array)) ?>" >
        <input type="submit" class="download button" value="DownLoad">
      </form>

    </div>
  </div>
</div>
<!--   end of structure-->
<?php include_template('footer.inc') ?>
