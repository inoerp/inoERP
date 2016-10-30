<div id="json_form_data">
 <div id="structure"><?php echo getBreadCrumb($class_first); ?>
  <div class="heading search-top-msg">
   <?php
   if (!empty($_GET['function_name'])) {
    echo '<span>' . gettext(ucwords(str_replace('_', ' ', $_GET['function_name']))) . ' ' . gettext('Report') . '</span>';
   } else {
    echo '<span>' . gettext('Search') . ' ' . gettext(ucwords(str_replace('_', ' ', $class))) . '</span>';
   }
   ?>
  </div>
  <div id="search_page">
   <div id ="form_header">
    <?php echo (!empty($show_message)) ? $show_message : ""; ?> 
   </div>
   <div id="list_contents">
    <div id="searchForm" ><div class='hideDiv_input fa fa-minus-circle fa-2x clickable'></div>
     <div class='hideDiv_input_element'><?php echo!(empty($search_form)) ? $search_form : ""; ?></div></div>
    <div id="searchResult">
     <?php
     if (!empty($total_count)) {
      ?>
      <div id="searchResultMessages" >
       <ul class="inline_list heading">
        <li><?php echo gettext('Download All Data in') ?> </li>
        <li>
         <!--download page creation for all records-->
         <?php
         if (!empty($all_download_sql)) {
          echo show_download_button_inSelectFormat(($all_download_sql), $total_count, $total_count_all, 'sql_query');
         }
         ?>
         <!--download page completion-->	 
        </li>
        <li id="export_excel_searchResult" class="clickable" title="<?php echo gettext('Export to Excel')?>"><i class="fa fa-file-excel-o"></i></li>
        <li id="print_searchResult" class="print clickable" title="<?php echo gettext('Print')?>"><i class="fa fa-print"></i></li>
        <li><button class="btn btn-primary" type="button"><?php echo gettext('Total Records')?> <span class="badge"><?php echo $total_count; ?></span></button></li>
       </ul>
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

   </div>
  </div>
 </div>

</div>
