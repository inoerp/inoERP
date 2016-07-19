<div id="searchResult">
 <?php
 if (!empty($total_count)) {
  ?>
  <div id="searchResultMessages">
      <?php
      if (!empty($all_download_sql)) {
//       if (empty($search_class_array_all)) {
//        $search_class_obj_all = $$class->findBySql($all_download_sql);
//        $search_class_array_all = json_decode(json_encode($search_class_obj_all), true);
//       }
       echo show_download_button_inSelectFormat(($all_download_sql), $total_count, $total_count_all, 'sql_query');
      }
      ?>
  </div>
 <?php } ?>
 <div id="scrollElement">
  <div id="print">
   <div id="search_result"> <?php echo!(empty($search_result_statement)) ? $search_result_statement : ""; ?></div>
  </div>
 </div>
 <div class="pagination" style="clear: both;">
  <?php echo!(empty($pagination_statement)) ? $pagination_statement : "";
  ?>
 </div>

</div>