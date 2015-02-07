<div id="searchResult">
 <?php
 if (!empty($total_count)) {
  ?>
  <div id="searchResultMessages">
   <ul class="inline_list">
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
       <input type="hidden"  name="data" value="<?php print base64_encode(serialize($search_class_array_all)) ?>" >
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
    <li id="export_excel_searchResult" class="clickable" title="Export to Excel"><i class="fa fa-file-excel-o"></i></li>
    <li id="print_searchResult" class="print clickable" title="Print"><i class="fa fa-print"></i></li>
    <li><button class="btn btn-primary" type="button">Total records <span class="badge"><?php echo $total_count; ?></span></button></li>
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