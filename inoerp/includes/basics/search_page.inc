<!DOCTYPE html>
<html>
 <head>
  <meta http-equiv="Content-Type" content="text/html; charset=UTF-8">
  <?php
  if (!empty($metaname_description)) {
   echo "<meta name='description' content=\"inoERP - A Open Source PHP based Enterprise Management System\">";
  }
  ?>
  <meta name="keywords" content="ERP,PHP ERP,Open Source ERP ">
  <title><?php echo isset($pageTitle) ? $pageTitle . ' - inoERP!' : ' inoERP! ' ?></title>
  <link href="<?php
  echo defined('THEME_URL') ? THEME_URL : 'themees/default';
  echo (!empty($content_class)) ? '/content_layout.css' : '/layout.css'
  ?>" media="all" rel="stylesheet" type="text/css" />
  <link href="<?php echo defined('THEME_URL') ? THEME_URL : 'themes/default'; ?>/public.css" media="all" rel="stylesheet" type="text/css" />
  <link href="<?php echo defined('THEME_URL') ? THEME_URL : 'themes/default'; ?>/menu.css" media="all" rel="stylesheet" type="text/css" />
  <link href="<?php echo defined('THEME_URL') ? THEME_URL : 'themes/default'; ?>/jquery.css" media="all" rel="stylesheet" type="text/css" />
  <link href="includes/ecss/search.css" media="all" rel="stylesheet" type="text/css" />
  <?php
  if (!empty($css_file_paths)) {
   foreach ($css_file_paths as $key => $css_file) {
    ?>
    <link href="<?php echo HOME_URL . $css_file; ?>" media="all" rel="stylesheet" type="text/css" />
    <?php
   }
  }
  ?>
  <script src="includes/js/jquery-2.0.3.min.js"></script>
  <script src="includes/js/jquery-ui.min.js"></script>
  <script src="includes/js/custom/tinymce/tinymce.min.js"></script>
  <script src="includes/js/save.js"></script>
  <script src="includes/js/custom_plugins.js"></script>
  <script src="includes/js/basics.js"></script>
  <?php
  if (!empty($js_file_paths)) {
   foreach ($js_file_paths as $key => $js_file) {
    ?>
    <script src="<?php echo HOME_URL . $js_file; ?>"></script>
    <?php
   }
  }
  ?>
 </head>
 <body>
  <!--     Check if its a find page  Exclude the header &amp; left block section-->
  <div id="header_top_container">
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
  <?php
  if (!empty($showBlock)) {
   include_once 'header_template.inc';
  }
  ?>
  <?php
  if ($si->maintenance_cb == 1) {
   echo "<div class='error'>Site is under maintenance mode </div>";
  }
  if (!empty($access_deined)) {
   exit("Access denied ! <br> $msg <input action='action' class='button' type='button' value='Go Back' onclick='history.go(-1);' />");
  }
  ?>

  <div id="all_contents">
 <div id="content_left"></div>
 <div id="content_right">
  <div id="content_right_left">
   <div id="content_top"></div>
   <div id="content">
    <div class="error"></div><div class="show_loading_small"></div><div id="loading"></div>
    <div id="main">
     <div id="structure"><span class="heading"><?php  echo 'Search ' . ucwords(str_replace('_',' ',$class)) ;?></span>
      <div id="search_page">
       <div id ="form_header">
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
  <!--footer content-->

  <?php echo (!empty($footer_top)) ? "<div id=\"footer_top\"> $footer_top </div>" : ""; ?>
  <div id="footer" class="topBottomBG">
   <div id="footer_top"></div>
   <div id="footer_message">
    <?php
    global $si;
    echo nl2br($si->footer_message);
    ?>
   </div>
  </div>

  <?php
  global $f;
  echo (!empty($footer_bottom)) ? "<div id=\"footer_bottom\"> $footer_bottom </div>" : "";
  echo $f->hidden_field_withId('home_url', HOME_URL);
  ?>
  <?php echo searching_tips(); ?>
 </body>
</html>
<?php
// 5. Close connection
if (isset($dbc)) {
 $dbc->close_connection();
}
?>







