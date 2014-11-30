<link href="includes/ecss/search.css" media="all" rel="stylesheet" type="text/css" />

<div id="all_contents">
 <div id="content_left"></div>
 <div id="content_right">
  <div id="content_right_left">
   <div id="content_top"></div>
   <div id="content">
    <div id="main">
     <div id="structure">
      <div id="search_page">
       <div id ="form_header">
        <div class="error"></div><div class="show_loading_small"></div><div id="loading"></div>
        <?php echo (!empty($show_message)) ? $show_message : ""; ?> 
       </div>
       <div id="list_contents">
        <div id="searchForm" ><div class='hideDiv_input'></div>
         <div class="show_loading_small"><img src="<?php echo HOME_URL ?>/themes/images/form/small_loading_bar.gif"></div>
         <div class='hideDiv_input_element'><?php echo!(empty($search_form)) ? $search_form : ""; ?></div></div>
        <div id="searchResult">
         <?php
         if (!empty($total_count)) {
          ?>
          <div id="searchResultMessages">
           <ul class="inline_list">
            <li><?php echo '<h3>Total records : ' . $total_count . '</h3>  '; ?></li>
            <li>Download All Data in </li>
            <li>
             <!--download page creation for all records-->
             <?php
             if (!empty($all_download_sql)) {
              $search_class_obj_all = $$class->findBySql($all_download_sql);
              $search_class_array_all = json_decode(json_encode($search_class_obj_all), true);
              ?>
              <!--download page form-->
              <form action="<?php echo HOME_URL; ?>download.php" method="POST" name="download_all" id="download_all" target="_blank">
               <input type="hidden"  name="data" value="<?php print  base64_encode(serialize($search_class_array_all)) ?>" >
               <input type="radio" name="download_format" checked="checked" value="excel_format">Excel 
               <input type="radio" name="download_format" value="text_format">Text
               <input type="radio" name="download_format" value="pdf_format">Pdf
               <input type="radio" name="download_format" value="xml_format">XML
               <input type="radio" name="download_format" value="worddoc_format">Word Doc
               <input type="submit"  name="export_allResult" value="Download" id="export_excel_allResult" class="clickable button"  >
              </form>
             <?php }
             ?>
             <!--download page completion-->	 
            </li>
            <li id="export_excel_searchResult" class="flaticon-spreadsheet6 clickable" title="Export to Excel"></li>
            <li id="print_searchResult" class="flaticon-print42 print clickable" title="Print"></li>
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
   </div>
   <div id="content_bottom"></div>
  </div>
  <div id="content_right_right"></div>
 </div>
</div>
<?php echo searching_tips(); ?>
<?php include_template('footer.inc') ?>
