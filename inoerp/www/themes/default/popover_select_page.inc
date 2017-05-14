<div id="popover_erp_form_area">
  <div id="select_page">
   <div id ="popover_form_header">
    <div class="error"></div><div class="loading"></div>
    <?php echo (!empty($show_message)) ? $show_message : ""; ?> 
   </div>
   <div id="list_contents">
    <div id="searchForm" ><div class='hideDiv_input fa fa-minus-circle clickable '></div>
     <div class='hideDiv_input_element'><?php echo!(empty($search_form)) ? $search_form : ""; ?></div></div>
    
     <div id="selectResult">
      <div id="selectResult_page">
       <?php
       if (!empty($total_count)) {
        ?>
        <div id="searchResultMessages">
         <ul class="inline_list">
          <li><button class="btn btn-primary" type="button"><?php echo gettext('Accessible Records'); ?> <span class="badge"><?php echo $total_count; ?></span></button></li>
          <li><button class="btn btn-warning" type="button"><?php echo gettext('Total Records'); ?> <span class="badge"><?php echo $total_count_all; ?></span></button></li>
         </ul>
        </div>
        <?php
       }

       if (!empty($select_result_statement)) {
        ?>
        <div id="scrollElement">
         <div id="print">
          <div id="select_result"> <?php echo!(empty($select_result_statement)) ? $select_result_statement : ""; ?></div>
         </div>
        </div>
       <?php } else {
        ?>
        <div id="scrollElement">
         <div id="print">
          <div id="select_result"> 
           <table class="find_page normal">
            <thead> 
             <tr>
              <th><?php echo gettext('Click Select')?></th>
              <?php
              if (property_exists($class, 'column')) {
               $column_array = $$class->column;
              } else {
               $column_array = $$class->field_a;
              }
              $column_count = 1;
              foreach ($column_array as $key => $value) {
               echo '<th>' . $value . '</th>';
               $column_count++;
               if ($column_count >= 8) {
                break;
               }
              }
              ?>
             </tr>
            </thead>

            <?php
            If (!empty($search_result)) {
             if (isset($_GET['window_type']) && $_GET['window_type'] = 'popover') {
              $quick_select_class = 'popover_quick_select';
             } else {
              $quick_select_class = 'quick_select';
             }
             echo '<tbody>';
             foreach ($search_result as $record) {
              $primary_column = $class::$primary_column;
              echo '<tr>';
              echo '<td><button data-select_field="' . $primary_column . '"  data-select_field_value="' . $record->$primary_column . '"'
              . ' class=" button ' . $primary_column . ' ' . $quick_select_class . '">' . $record->$primary_column . '</button></td>';
              foreach ($column_array as $key => $value) {
               echo "<td class=\"$value\">" . $record->$value . '</td>';
              }
              echo '</tr>';
             }
             echo '</tbody>';
            }
            ?>

           </table>
          </div>
         </div>
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
