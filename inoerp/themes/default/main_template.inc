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
  echo THEME_URL;
  echo (!empty($content_class)) ? '/content_layout.css' : '/layout.css'
  ?>" media="all" rel="stylesheet" type="text/css" />
  <link href="<?php echo THEME_URL; ?>/public.css" media="all" rel="stylesheet" type="text/css" />
  <link href="<?php echo THEME_URL; ?>/menu.css" media="all" rel="stylesheet" type="text/css" />
  <link href="<?php echo THEME_URL; ?>/jquery.css" media="all" rel="stylesheet" type="text/css" />
  <!--<link href="<?php // echo HOME_URL; ?>tparty/bootstrap/css/bootstrap.css" rel="stylesheet">-->
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
  <!--<script src="<?php // echo HOME_URL; ?>tparty/bootstrap/js/bootstrap.min.js"></script>-->
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
  if ($showBlock) {
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
      <div class="error clickable"></div><div id="loading"></div>
      <div id="structure">
       <?php
       echo (!empty($show_message)) ? $show_message : "";
       if (!empty($template_file_names)) {
                foreach ($template_file_names as $key => $tmpl_file) {
         include_once $tmpl_file;
        }
       }
       ?>
      </div>
      <!--   end of structure-->
     </div>
     <div id="content_bottom"></div>
    </div>
    <div id="content_right_right"></div>
   </div>

  </div>
  <!--footer content-->
  <div id="comment_form" class="none">
   <?php

   if (!empty($reference_table) && !empty($reference_id)) {
    include_once __DIR__ . '../../comment.php';
   }
   ?>
  </div>
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
 </body>
</html>
<?php
// 5. Close connection
if (isset($dbc)) {
 $dbc->close_connection();
}
?>