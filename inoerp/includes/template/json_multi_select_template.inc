<div id="json_multi_select_data">
 <div id="header_top_container" style="display: block;">
  <?php
  $show_header_links = true;
  if ((!empty($mode)) && ($mode > 8) && !empty($access_level) && $access_level > 3) {
   if (empty($current_page_path)) {
    $current_page_path = thisPage_url();
   }
   $f->form_button_withImage($current_page_path);
   $show_header_links = false;
  }
  ?>
 </div>
 <ul id="css_files" class="none"><li>includes/ecss/search.css</li></ul>
 <ul id="js_files" class="none"><?php
  If (!empty($action_class_i) && property_exists($action_class_i, 'js_fileName')) {
   echo '<li>' . $action_class_i::$js_fileName . '</li>';
  }
  ?></ul>
 <div id="searchResult">
  <div id="multi_<?php echo $class ?>">
   <?php
   if (!empty($multi_select_actions)) {
    echo '<div class="well well-sm">' . $multi_select_actions . '</div>';
   }
   ?>
   <div id="tabsLine">
    <ul class="tabMain">
     <?php
     if (property_exists($class, 'primary_column')) {
      $primary_column_v = $class::$primary_column;
     }

     if (property_exists($class, 'multi_select_column')) {
      $column_array = $$class->multi_select_column;
     } else if (property_exists($class, 'column')) {
      $column_array = $$class->column;
     } else {
      $column_array = $$class->field_a;
     }

     $all_columns = (!empty($multi_selct_input_fields) && is_array($multi_selct_input_fields)) ? array_merge($multi_selct_input_fields, $column_array) : $column_array;
     $no_of_columns_per_tab = 11;
     $total_columns = (!empty($multi_selct_input_fields) && is_array($multi_selct_input_fields)) ? count($multi_selct_input_fields) + count($column_array) : count($column_array);
     if (!empty($multi_select_select_fields) && is_array($multi_select_select_fields) && count($multi_select_select_fields) > 2) {
      $no_of_columns_per_tab = 10;
     }
     $no_of_tabs = ceil($total_columns / $no_of_columns_per_tab);
     if (!empty($multi_select_tabs)) {
      $no_of_tabs++;
      $no_of_tab_count = 0;
     }
     for ($i = 0; $i < $no_of_tabs; $i++) {
      echo "<li><a href=\"#tabsLine-$i\">Tab No $i </a></li>";
     }
     ?>
    </ul>
    <div class="tabContainer"> 
     <?php
     $multi_select_select_fields_header_not_shown = true;
     for ($i = 0; $i < $no_of_tabs; $i++) {
      ?>
      <div id="tabsLine-<?php echo $i ?>" class="tabContent">
       <table class="form_line_data_table">
        <thead> 
         <tr>
          <?php
          if ($i == 0) {
           echo "<th>Select<br><i class='select_all fa fa-level-down clickable' title='Select All'></i>&nbsp;<i class='deselect_all fa fa-level-up clickable' title='Deselect All'></i></th>";
          }
          echo '<th>' . gettext(ucwords(str_replace('_', ' ', $primary_column_v))) . '</th>';
          if (($i == 0) && (!empty($multi_selct_input_fields) && !is_array($multi_selct_input_fields))) {
           echo '<th>Line Action</th>';
          }
          $new_start = ($i * ($no_of_columns_per_tab - 1)) + $i;
          $new_end = $new_start + ($no_of_columns_per_tab - 1);
          for ($j = $new_start; $j <= $new_end; $j++) {
           if ($j > $total_columns - 1) {
            break;
           }
           if (($i == 0) && ($multi_select_select_fields_header_not_shown) && !empty($multi_select_select_fields) && is_array($multi_select_select_fields)) {
            foreach ($multi_select_select_fields as $mssf_key => $mssf_val) {
             echo '<th>' . ucwords(str_replace('_', ' ', $mssf_key)) . '</th>';
            }
            $multi_select_select_fields_header_not_shown = false;
           }
           echo '<th>' . ucwords(str_replace('_', ' ', $all_columns[$j])) . '</th>';
          }
          if (!empty($multi_select_tabs) && ($i == $no_of_tabs - 1)) {
           echo $multi_select_tabs['tab_header'];
          }
          ?>
         </tr>
        </thead>
        <tbody class="form_data_line_tbody multi_select_values" >
         <?php
         $count = 0;
         if (!empty($search_result)) {
          foreach ($search_result as $records) {
           $multi_select_select_fields_not_shown = true;
           ?>         
           <tr class="multi_select_value_line<?php echo $count ?>">
            <?php
            if ($i == 0) {
             if (isset($records->$primary_column_v)) {
              $primary_column_val = $records->$primary_column_v;
             } else {
              $primary_column_val = null;
             }
             echo "<td><input type=\"checkbox\" name=\"line_id_cb\" class=\"line_id_cb\"  value=\"$primary_column_val\">";
             echo "<input type=\"hidden\" name=\"multi_action_class\" class=\"hidden multi_action_class\"  value=\"$action_class\">";
             if (!empty($header_id_value)) {
              echo "<input type=\"hidden\" name=\"$header_id_name\" class=\"hidden $header_id_name\"  value=\"$header_id_value\">";
             }
             echo "<input type=\"hidden\" name=\"action\" class=\"hidden action\"  value=\"$action_message\">";
             echo!empty($hidden_field_stmt) ? $hidden_field_stmt : '';
            }
            echo '</td><td>' . $records->$primary_column_v . '</td>';
            if (!empty($multi_select_tabs) && ($i == $no_of_tabs - 1)) {
//                 echo $multi_select_tabs;
             echo $multi_select_tabs['tab_row_content'];
            }
            if (($i == 0) && (!empty($multi_selct_input_fields) && !is_array($multi_selct_input_fields))) {
             echo '<td>' . $multi_selct_input_fields . '</td>';
            }
            if (($i == 0) && ($multi_select_select_fields_not_shown) && !empty($multi_select_select_fields) && is_array($multi_select_select_fields)) {
             foreach ($multi_select_select_fields as $mssf_key => $mssf_val) {
              echo '<td>' . $mssf_val . '</td>';
             }
             $multi_select_select_fields_not_shown = false;
            }
            $new_start = ($i * ($no_of_columns_per_tab - 1)) + $i;
            $new_end = $new_start + ($no_of_columns_per_tab - 1);
            for ($k = $new_start; $k <= $new_end; $k++) {
             if ($k > $total_columns - 1) {
              break;
             }
             if ((!empty($multi_selct_input_fields) && is_array($multi_selct_input_fields)) && (in_array($all_columns[$k], $multi_selct_input_fields))) {
              $readonly = null;
              $div_class_name = ' multi_select_input ';
             } else {
              $readonly = 'readonly';
              $div_class_name = ' existing_fields  ';
             }
             $field_name = $all_columns[$k];
             $bracketName = $field_name . '[]';
             if ((property_exists($records, $all_columns[$k]))) {
              if ((!empty($multi_selct_input_fields) && is_array($multi_selct_input_fields)) && (in_array($all_columns[$k], $multi_selct_input_fields))) {
               $value = null;
              } else {
                      $value = $records->{$all_columns[$k]};
              }
              echo "<td><input type=\"text\" name=\"$bracketName\" class=\"$div_class_name text $all_columns[$k]\" value=\"$value\" $readonly size=\"12\"> </td>";
             } else {
              $field_method_name = 'multi_select_field_' . $field_name;
              if (method_exists($class, $field_method_name)) {
               $field_stmt1 = call_user_func(array($class, $field_method_name), $records);
               echo "<td> $field_stmt1 </td>";
              } else {
               echo "<td><input type=\"text\" name=\"$bracketName\" class=\"$div_class_name text $all_columns[$k]\" value=\" \" $readonly size=\"12\"> </td>";
              }
             }
            }
            ?>
           </tr>
           <?php
           $count = $count + 1;
          }
         }
         ?>
        </tbody>
       </table>
      </div>
     <?php } ?>

    </div>

   </div>

   <div class="pagination" style="clear: both;">
    <?php echo!(empty($pagination_statement)) ? $pagination_statement : "";
    ?>
   </div>
  </div> 
 </div>
</div>