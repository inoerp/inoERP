<div id="all_contents">
 <div id="content_left"></div>
<div id="content_right">
 <div id="content_right_left">
  <div id="content_top"></div>
<div id="content">
<div id="structure">
 <div id="content_type">
  <!--    START OF FORM HEADER-->
  <div id ="form_header">
   <ul id="form_box"> 
    <li>

     <div id="loading"><img alt="Loading..." 
                            src="<?php echo HOME_URL; ?>themes/images/loading.gif"/></div>
    </li>
    <li>   <!--    Place for showing error messages-->

     <div class="error"></div>
     <?php echo (!empty($show_message)) ? $show_message : ""; ?> 


     <!--    End of place for showing error messages-->
    </li>
    <!--Search form creation    -->
    <li>
       <div id="content_type_search">
            <br>
            <form action="content_types.php" name="search_content_type" method="GET" class="search_box content_type_form" id="search_content_type">
              <ul class="search_form">                   
                <li><label>Content Type Id : </label>
                  <input type="text" id="content_type_id" name="content_type_id" value="<?php
          echo!(is_array($_GET['content_type_id'])) ? htmlentities($_GET['content_type_id']) : "";
          ?>" 
                         maxlength="50" >
                </li>
                <li><label>Content Type : </label>
                  <input type="search" name="content_type" id="content_type" value="<?php
          echo!(is_array($_GET['content_type'])) ? htmlentities($_GET['content_type']) : "";
          ?>" 
                         maxlength="50" >
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
                <li><a href="content_types.php" class="reset button"> Reset All</a></li>
                <li><input type="submit" form="search_content_type" name="submit_search" class="search button" value="Search"></li>

              </ul>
            </form> 

          </div>
     
     
     
    </li>
    <li>
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
          If (!empty($result)) {
            echo '<tbody>';
            foreach ($result as $record) {
              echo '<tr>';
              foreach ($column_array as $key => $value) {
                echo '<td>' . $record->$value . '</td>';
              }
              echo '<td><a href="content_type.php?content_type_id=' . $record->content_type_id . '">Update</a></td>';
              echo '</tr>';
            }
            echo '</tbody>';
          }
          ?>

        </table>
      </div>
     </div>
    </li>
   </ul>
  </div>  

 <div id="pagination" style="clear: both;">
        <?php
        if (isset($pagination) && $pagination->total_pages() > 1) {
          if ($pagination->has_previous_page()) {
            echo "<a href=\"content_types.php?pageno=";
            echo $pagination->previous_page() . '&' . $query_string;
            echo "\"> &laquo; Previous </a> ";
          }

          for ($i = 1; $i <= $pagination->total_pages(); $i++) {
            if ($i == $pageno) {
              echo " <span class=\"selected\">{$i}</span> ";
            } else {
              echo " <a href=\"content_types.php?pageno={$i}&" . remove_querystring_var($query_string, 'pageno');
              echo '\">' . $i . '</a>';
            }
          }

          if ($pagination->has_next_page()) {
            echo " <a href=\"content_types.php?pageno=";
            echo $pagination->next_page() . '&' . remove_querystring_var($query_string, 'pageno');
            echo "\">Next &raquo;</a> ";
          }
        }
        ?>
      </div>
  
   <div id="download_data">
      <!--download page creation-->
      <ul class="data_export">
        <li> <input type="submit" class="download button excel" value="<?php echo $per_page ?> Records" form="download"></li>
        <li> <input type="submit" class="download button excel" value="All Records" form="download_all"></li>
        <li> <input type="button" class="download button print" value="Print"></li>
      </ul>
     
     <?php
      if (!empty($sql)) {
        $uom_obj = uom::find_by_sql($sql);
        $uom_array = json_decode(json_encode($uom_obj), true);
      }
      ?>
      <!--download page form-->
      <form action="<?php echo HOME_URL; ?>download.php" method="POST" name="download" id="download">
        <input type="hidden"  name="data" value="<?php print base64_encode(serialize($uom_array)) ?>" >

      </form>

      <!--download page creation for all records-->
      <?php
      if (!empty($all_download_sql)) {
        $uom_obj_all = uom::find_by_sql($all_download_sql);
        $uom_array_all = json_decode(json_encode($uom_obj_all), true);
      }
      ?>
      <!--download page form-->
      <form action="<?php echo HOME_URL; ?>download.php" method="POST" name="download_all" id="download_all">
        <input type="hidden"  name="data" value="<?php print base64_encode(serialize($uom_array_all)) ?>" >
      </form>
      </div> 
 </div>
 <!--END OF FORM HEADER-->  
</div>
<!--   end of structure-->
</div>
  <div id="content_bottom"></div>
 </div>
 <div id="content_right_right"></div>
 </div>

</div>

<?php include_template('footer.inc') ?>

