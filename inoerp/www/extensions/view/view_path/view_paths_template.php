<div id="all_contents">
 <div id="content_left"></div>
 <div id="content_right">
  <div id="content_right_left">
   <div id="content_top"></div>
   <div id="content">
    <div id="main">

     <div id="structure">
      <div id="contents">
       <div id ="form_header">
        <ul id="form_box"> 
         <li>
          <div id="loading"><img alt="<?php echo gettext('Loading...') ?>" src="<?php echo HOME_URL; ?>themes/images/loading.gif"/></div>
         </li>
         <li> 
          <div class="error"></div>
          <?php echo (!empty($show_message)) ? $show_message : ""; ?> 
         </li>

        </ul>
       </div>
       <div id="page_contents">
        <br><br>
        <div id="view_searchId">
         <br>
         <?php echo!(empty($search_form)) ? $search_form : ""; ?>

        </div>

        <?php
        if (!empty($total_count)) {
         echo '<h3>' . gettext('Total Records') . ' : ' . $total_count . '</h3>';
        }
        ?>
        <div id="scrollElement">
         <div id="print">
          <?php echo!(empty($search_result)) ? $search_result : ""; ?>
         </div>
        </div>
        <div id="pagination" style="clear: both;">
         <?php echo!(empty($pagination_statement)) ? $pagination_statement : "";
         ?> 
        </div>
        <!--download page creation-->
        <ul class="data_export">
         <li> <input type="submit" class="download button excel" value="<?php echo $per_page . ' ' . gettext('Records'); ?>" form="download"></li>
         <li> <input type="submit" class="download button excel" value="<?php echo gettext('All Records'); ?>" form="download_all"></li>
         <li> <input type="button" class="download button print" value="<?php echo gettext('Print'); ?>"></li>
         <li id="export_excel_searchResult" class="clickable" title="<?php echo gettext('Export to Excel'); ?>"><i class="fa fa-file-excel-o"></i></li>
         <li id="print_searchResult" class=" print clickable" title="<?php echo gettext('Print'); ?>"><i class="fa fa-print"></i></li>
        </ul>

        <?php
        if (!empty($sql)) {
         $view_obj = extn_view::find_by_sql($sql);
         $view_array = json_decode(json_encode($view_obj), true);
        }
        ?>
        <!--download page form-->
        <form action="<?php echo HOME_URL; ?>download.php" method="POST" name="download" id="download">
         <input type="hidden"  name="data" value="<?php print base64_encode(serialize($view_array)) ?>" >

        </form>

        <!--download page creation for all records-->
        <?php
        if (!empty($all_download_sql)) {
         $view_obj_all = extn_view::find_by_sql($all_download_sql);
         $view_array_all = json_decode(json_encode($view_obj_all), true);
        }
        ?>
        <!--download page form-->
        <form action="<?php echo HOME_URL; ?>download.php" method="POST" name="download_all" id="download_all">
         <input type="hidden"  name="data" value="<?php print base64_encode(serialize($view_array_all)) ?>" >
        </form>
        <!--download page completion-->
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

<?php include_template('footer.inc') ?>
