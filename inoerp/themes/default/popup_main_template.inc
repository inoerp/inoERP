<!DOCTYPE html>
<html>
 <head>
  <meta http-equiv="Content-Type" content="text/html; charset=UTF-8">
  <meta name="viewport" content="width=device-width, initial-scale=1">
  <?php
  if (!empty($metaname_description)) {
   echo "<meta name='description' content=\"inoERP - A Open Source PHP based Enterprise Management System\">";
  }
  ?>
  <meta name="keywords" content="ERP,PHP ERP,Open Source ERP ">
  <title><?php echo isset($pageTitle) ? $pageTitle . ' - inoERP!' : ' inoERP! ' ?></title>
  <link href="<?php echo THEME_URL; ?>/public.css" media="all" rel="stylesheet" type="text/css" />
  <link href="<?php echo THEME_URL; ?>/menu.css" media="all" rel="stylesheet" type="text/css" />
  <link href="<?php echo THEME_URL; ?>/jquery.css" media="all" rel="stylesheet" type="text/css" />
  <link href="<?php echo HOME_URL; ?>tparty/bootstrap/css/bootstrap.css" rel="stylesheet">
  <link href="<?php echo HOME_URL; ?>tparty/bootstrap/css/style.css" rel="stylesheet">
  <link href="<?php echo HOME_URL; ?>tparty/font-awesome/css/font-awesome.min.css" rel="stylesheet">
  <link href='https://fonts.googleapis.com/css?family=PT+Sans:400,400italic,700,700italic' rel='stylesheet' type='text/css'>
  <link href='https://fonts.googleapis.com/css?family=Lato:400,300,400italic,300italic,700,700italic,900' rel='stylesheet' type='text/css'>
  <link href='https://fonts.googleapis.com/css?family=Exo:400,300,600,500,400italic,700italic,800,900' rel='stylesheet' type='text/css'>
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
  <script src="<?php echo HOME_URL; ?>tparty/bootstrap/js/bootstrap.min.js"></script>
  <script src="<?php echo HOME_URL; ?>tparty/bootstrap/js/menu.js"></script>
  <script src="includes/js/custom/tinymce/tinymce.min.js"></script>
  <script src="includes/js/save.js"></script>
  <script src="includes/js/custom_plugins.js"></script>
  <script src="includes/js/basics.js"></script>
<script src="themes/default/js/theme.js"></script>
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
  <?php
  if ($si->maintenance_cb == 1) {
   echo ino_access_denied('Site is under maintenance mode');
   return;
  }
  ?>
  <div id="popup-window">
  <div class="ino navbar-form">
   <div id="navigation_bar"   class="col-sm-11 col-sm-offset-2 col-md-11 col-md-offset-2">
    <div id="header_top_quick_nav" >
     <ul class="list-group inline_list">
      <li role="presentation"><i class="fa fa-close clickable close_popup_window" title="Close Window"></i></li>
      <li class="show_loading_small"><img src="<?php echo HOME_URL ?>/themes/images/form/small_loading_bar.gif"></li>
     </ul>
    </div>
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
     <?php if ($show_header_links) { ?>
      <!--       <div class="social-icons">
              <span><a class="flaticon-list90 clickable erp_dashborad" href="form.php?class_name=user_dashboard_v&mode=2" title="<?php //echo gettext('ERP Dashboard') ?>"> <?php //echo gettext('ERP Dashboard') ?> </a></span>
             </div> end social icons -->
     <?php } ?>
    </div>
   </div>
  </div>

   <div class="row">
    <div class="col-sm-2 col-md-2 sidebar">
     <div id="sys_msg_box">
      <div class="error"></div><div id="loading"></div>
     </div>
    </div>
    <div id="erp_form_area" class="col-sm-10 col-sm-offset-2 col-md-10 col-md-offset-2 mainbar">
     <div id="content">
      <div id="structure">
       <?php
       if (!empty($show_message)) { 
        echo '<div class="alert alert-warning alert-dismissible" role="alert"><button type="button" class="close" data-dismiss="alert" aria-label="' . gettext('Close') . '"><span aria-hidden="true">&times;</span></button>'.
        $show_message.
        '</div>';
       }
             if (!empty($access_denied_msg)) {
       echo ino_access_denied($access_denied_msg);
      } else if (!empty($template_file_names)) {
       foreach ($template_file_names as $key => $tmpl_file) {
        include_once $tmpl_file;
       }
      }
       ?>
      </div>
      <!--   end of structure-->
     </div>
     <div id='overlay'></div>
    </div>

   </div>

</div>

  <!--footer content-->
  <?php
  global $f;
  echo (!empty($footer_bottom)) ? "<div id=\"footer_bottom\"> $footer_bottom </div>" : "";
  echo $f->hidden_field_withId('home_url', HOME_URL);
  ?>
  <div class="hidden">
   <?php
   echo searching_tips();
   echo ino_filter_form();
   ?>
  </div>
 </body>
</html>
<?php
// 5. Close connection
if (isset($dbc)) {
 $dbc->close_connection();
}
?>
