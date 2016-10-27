<?php
if (preg_match('/(?i)msie [5-8]/', $_SERVER['HTTP_USER_AGENT'])) {
 echo ($_SERVER['HTTP_USER_AGENT']);
 echo "<h2>Sorry! Your browser is outdated and not compatible with this site!!!</h2> "
 . "Please use any modern browsers such as Firefox, Opera, Chrome, IE 10+ ";
 exit;
}
$dont_check_login = true;
?>
<?php
if (file_exists('install.php')) {
 if (isset($_GET['install'])) {
  if ($_GET['install'] == 'done') {
   // Delete the insatll file after installation
   @unlink('install.php');
   // Redirect to main page
   header('location: index.php');
  }
 } else {
  header('location: install.php');
 }
 return;
}
?>
<?php
$content_class = true;
if (empty($_GET['class_name']) && empty($_GET['cname'])) {
 $class_names[] = 'content';
} else if (!empty($_GET['class_name'])) {
 $class_names[] = $_GET['class_name'];
} elseif (!empty($_GET['cname'])) {
 $class_names[] = $_GET['cname'];
}
?>
<?php
include_once("includes/functions/loader.inc");
?>
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
  <link rel="shortcut icon" type="image/x-icon" href="files/favicon.ico">
  <link href="<?php
//  echo THEME_URL;
//  echo (!empty($content_class)) ? '/content_layout.css' : '/layout.css'
  ?>" media="all" rel="stylesheet" type="text/css" />
  <link href="<?php echo THEME_URL; ?>/public.css" media="all" rel="stylesheet" type="text/css" />
  <link href="<?php echo THEME_URL; ?>/menu.css" media="all" rel="stylesheet" type="text/css" />
  <link href="<?php echo THEME_URL; ?>/jquery.css" media="all" rel="stylesheet" type="text/css" />
  <?php
  if (!empty($css_file_paths)) {
   foreach ($css_file_paths as $key => $css_file) {
    ?>
    <link href="<?php echo HOME_URL . $css_file; ?>" media="all" rel="stylesheet" type="text/css" />
    <?php
   }
  }
  ?>
  <link href="<?php echo HOME_URL; ?>tparty/bootstrap/css/bootstrap.css" rel="stylesheet">
  <!-- Styles -->
  <link href="<?php echo HOME_URL; ?>tparty/bootstrap/css/style.css" rel="stylesheet">
  <!-- Carousel Slider -->
  <link href="<?php echo HOME_URL; ?>tparty/font-awesome/css/font-awesome.min.css" rel="stylesheet">
  <link href='https://fonts.googleapis.com/css?family=PT+Sans:400,400italic,700,700italic' rel='stylesheet' type='text/css'>
  <link href='https://fonts.googleapis.com/css?family=Lato:400,300,400italic,300italic,700,700italic,900' rel='stylesheet' type='text/css'>
  <link href='https://fonts.googleapis.com/css?family=Exo:400,300,600,500,400italic,700italic,800,900' rel='stylesheet' type='text/css'>
  <link href="<?php echo HOME_URL; ?>themes/default/index.css" media="all" rel="stylesheet" type="text/css" />
  <script src="<?php echo HOME_URL; ?>includes/js/jquery-2.0.3.min.js"></script>
  <script src="<?php echo HOME_URL; ?>includes/js/jquery-ui.min.js"></script>
  <script src="<?php echo HOME_URL; ?>tparty/bootstrap/js/bootstrap.min.js"></script>
  <script src="<?php echo HOME_URL; ?>tparty/bootstrap/js/menu.js"></script>
  <script src="<?php echo HOME_URL; ?>includes/js/custom/tinymce/tinymce.min.js"></script>
  <script src="<?php echo HOME_URL; ?>includes/js/save.js"></script>
  <script src="<?php echo HOME_URL; ?>includes/js/custom_plugins.js"></script>
  <script src="<?php echo HOME_URL; ?>includes/js/basics.js"></script>
  <script src="<?php echo HOME_URL; ?>includes/js/jssor.slider.mini.js"></script>

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

  <nav class="navbar navbar-default navbar-fixed-top">
   <div id="topbar" class="topbar clearfix ">
    <div class="container">
     <div class="row">
      <?php
      if ($showBlock) {
       echo '<div id = "header_top" class = "clear"></div>';
      }
      ?>
      <div class="col-lg-4 col-md-4 col-sm-4">
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
        <div class="social-icons">
         <span><a class="fa fa-dashboard clickable erp_dashborad" href="form.php?class_name=user_dashboard_v&mode=2" title="<?php echo gettext('ERP Dashboard') ?>"> <?php echo gettext('ERP Dashboard') ?> </a></span>
        </div><!-- end social icons -->
       <?php } ?>

      </div><!-- end columns -->

      <div class="col-lg-8 col-md-8 col-sm-8 ">
       <div class="topmenu">
        <div class="topbar-login"><?php ino_topbar_login();   ?></div>
       </div><!-- end top menu -->
       <div class="callus">
        <span class="topbar-email"><i class="fa fa-envelope"></i> <a href="<?php echo HOME_URL . 'content.php?mode=9&content_type=web_contact' ?>"><?php echo!empty($si->email) ? $si->email : gettext('contact@site.org'); ?></a></span>
        <span class="topbar-phone"><i class="fa fa-phone"></i> <a href="#"><?php echo!empty($si->phone_no) ? $si->phone_no : '1-111-1111' ?></a></span>
       </div><!-- end callus -->
      </div><!-- end columns -->
     </div>
    </div><!-- end container -->
   </div><!-- end topbar -->

   <header id="header-style-1">
    <div class="container">
     <nav class="navbar yamm navbar-default ">
      <div class="navbar-header">
       <img src="<?php
       echo HOME_URL;
       echo!empty($si->logo_path) ? $si->logo_path : 'files/logo.png'
       ?>" class="logo_image" alt="logo"/>
       <a href="<?php echo HOME_URL; ?>" class="navbar-brand"><?php echo!empty($si->site_name) ? $si->site_name : 'inoERP'; ?></a>
      </div>
      <div id="navbar-collapse-1" class="navbar-collapse collapse navbar-right">
       <ul class="nav nav-pills">
        <li><a href="http://inoideas.org/content/demo" ><?php echo gettext('Demo'); ?> <div class="arrow-up"></div></a></li>
        <li><a href="https://github.com/inoerp/inoERP" ><?php echo gettext('Download'); ?> <div class="arrow-up"></div></a></li>
        <li class="active"><a href="<?php echo HOME_URL; ?>content.php?mode=9&content_type=forum&category_id=7" ><i class="fa fa-comments-o"></i> <?php echo gettext('Ask a Question'); ?> <div class="arrow-up"></div></a></li>
        <li><a href="<?php echo HOME_URL; ?>content.php?content_type=documentation&amp;category_id=30"><?php echo gettext('Documentation'); ?> <div class="arrow-up"></div></a></li><!-- end standard drop down -->
        <li><a href="<?php echo HOME_URL; ?>content.php?content_type=forum&amp;category_id=1"><?php echo gettext('Forum'); ?> <div class="arrow-up"></div></a></li>
        <li role="presentation" class="dropdown">
         <a class="dropdown-toggle" data-toggle="dropdown" href="#" role="button" aria-expanded="false">
          More <span class="caret"></span>
         </a>
         <ul class="dropdown-menu" role="menu">
          <li><a href="<?php echo HOME_URL; ?>"><?php echo gettext('Home'); ?> <div class="arrow-up"></div></a></li>
          <li><a href="<?php echo HOME_URL; ?>content.php?mode=2&amp;content_id=197&amp;content_type_id=47"><?php echo gettext('About'); ?> <div class="arrow-up"></div></a> </li><!-- end drop down -->
         </ul>
        </li>
       </ul><!-- end navbar-nav -->
      </div><!-- #navbar-collapse-1 -->			
     </nav>
    </div><!-- end container -->
   </header><!-- end header-style-1 -->
  </nav>
  <?php
  if ($showBlock) {
   echo '<div id="header_bottom"></div>';
  }
  ?>

  <?php
  if ($si->maintenance_cb == 1) {
   echo ino_access_denied('Site is under maintenance mode');
   return;
  }

  if (!empty($access_denied_msg)) {
   echo ino_access_denied($access_denied_msg);
   return;
  }
  ?>
  <!-- end grey-wrapper -->
  <div class="jt-shadow grey-wrapper first_content padding-top content_summary">
   <div class="make-center wow fadeInUp animated" style="visibility: visible;">
    <div class="container">
     <div id="structure">
      <a class="list-header" href="http://localhost/inoerp/form.php?class_name=po_requisition_header&amp;mode=9">&nbsp;<i class="fa fa-dot-circle-o"></i> &nbsp; <?php echo gettext('Requisition'); ?></a>
      <div id='form-modal'>
       Form Here
       <div id='mod-structure'> </div>
       <div id='mod-header_top_container'> </div>
      </div>

      <?php
//      pa($_SESSION['user_profile']);
//      pa(get_declared_classes());
      $content = new content();
      $subject_no_of_char = 50;
      $summary_no_of_char = 300;
      $fp_contnts = $content->frontPage_contents(200, 500);

      $pageno = !empty($_GET['pageno']) ? $_GET['pageno'] : 1;
      $per_page = !empty($_GET['per_page']) ? $_GET['per_page'] : 6;
      $total_count = count($fp_contnts);
      $pagination = new pagination($pageno, $per_page, $total_count);
      $pagination->setProperty('_path', 'index.php?');
      $position = ($pageno - 1) * $per_page;

      $fp_contnts_ai = new ArrayIterator($fp_contnts);
      if ($position > 0) {
       $fp_contnts_ai->seek($position);
      }
      $cont_count = 1;
      while ($fp_contnts_ai->valid()) {
       $contnent = $fp_contnts_ai->current();
       if ($cont_count == 1 || $cont_count == 4) {
        $count_class_val = ' first ';
       } else if ($cont_count == 2 || $cont_count == 5) {
        $count_class_val = ' last ';
       } else {
        $count_class_val = '';
       }
       echo '<div class="col-lg-4' . $count_class_val . ' ">
              <div class="panel panel-success">
                <div class="panel-heading">';
       echo "<h3 class='panel-title'>";
       echo '<a href="' . HOME_URL . 'content.php?mode=2&'
       . 'content_id=' . $contnent->content_id . '&content_type_id=' . $contnent->content_type_id . '">';
       echo substr($contnent->subject, 0, $subject_no_of_char) . "</a></h3>";
       echo '</div>';
       echo "<div class='panel-body'>" . ino_strip_html($contnent->content_summary, $summary_no_of_char) . "</div>";
       echo '</div></div>';
       $cont_count++;
       $fp_contnts_ai->next();
       if ($fp_contnts_ai->key() == $position + $per_page) {
        $cont_count = 1;
        break;
       }
      }
      ?>
     </div>
    </div>
   </div>
  </div>
  <div id="pagination1" style="clear: both;" class="pagination">
   <?php echo $pagination->show_pagination(); ?>
  </div>

  <div id="footer-style-1">
   <div class="container">
    <div id="footer_top"></div>
   </div>
  </div>
  <div id="copyrights">
   <div class="container">
    <div class="col-lg-5 col-md-6 col-sm-12">
     <div class="copyright-text">
      <p>
       <?php
       global $si;
       echo nl2br($si->footer_message);
       ?>
      </p>
     </div><!-- end copyright-text -->
    </div><!-- end widget -->
    <div class="col-lg-7 col-md-6 col-sm-12 clearfix">
     <div class="footer-menu">
      <ul class="menu">

       <li><a href="http://inoideas.org/content.php?mode=9&content_type=web_contact"><?php echo gettext('Contact'); ?></a></li>
       <li><a href="https://github.com/inoerp/inoERP/releases"><?php echo gettext('Releases'); ?></a></li>
       <li><a href="https://www.mozilla.org/MPL/2.0/"><?php echo gettext('MPL 2'); ?></a></li>
       <li><a href="#"><?php echo gettext('Cookie Preferences'); ?></a></li>
       <li class="active"><a href="#"><?php echo gettext('Terms of Use'); ?></a></li>

      </ul>
     </div>
    </div><!-- end large-7 --> 
   </div><!-- end container -->
  </div>
  <div class="dmtop"><?php echo gettext('Scroll to Top'); ?></div>

  <?php
  global $f;
  echo (!empty($footer_bottom)) ? "<div id=\"footer_bottom\"> $footer_bottom </div>" : "";
  echo $f->hidden_field_withId('home_url', HOME_URL);
  echo $si->analytics_code;
  ?>
  <script>
           $(document).ready(function () {
   dialog = $("#form-modal").dialog({
   autoOpen: false,
           height: 500,
           width: 900,
           modal: true,
           buttons: {
                   Cancel: function () {
                   dialog.dialog("close");
                   }
           },
           close: function () {
           dialog.dialog("close");
           }
   });
           $("#structure a.list-header").on("click", function(e) {
   e.preventDefault();
           var urlLink = $(this).attr('href');
           var urlLink_a = urlLink.split('?');
           var urlLink_firstPart_a = urlLink_a[0].split('/');
           var pageType = urlLink_firstPart_a.pop();
           if (pageType == 'form.php') {
   var formUrl = 'includes/json/json_form.php?' + urlLink_a[1];
   } else if (pageType == 'program.php') {
   var formUrl = 'includes/json/json_program.php?' + urlLink_a[1];
   } else {
   var formUrl = urlLink;
   }
   
   $.when(getModalFormDetails(formUrl)).then(
    dialog.dialog("open"));
           
   });
   });
   
   
   function getModalFormDetails(url) {
 return $.ajax({
  url: url,
  type: 'get',
  data: {
  },
  beforeSend: function () {
   $('#overlay').css('display', 'block');
  },
  complete: function () {

  }
 }).done(function (result) {
  var newContent = $(result).find('div#structure').html();
  var allButton = $(result).find('div#header_top_container #form_top_image').html();
  if (typeof allButton === 'undefined') {
   allButton = '';
  }
  var commentForm = $(result).find('div#comment_form').html();
  if (newContent) {
   $('#mod-structure').replaceWith('<div id="mod-structure">' + newContent + '</div>');
   $('#mod-header_top_container').replaceWith('<div id="mod-header_top_container"> <ul id="form_top_image" class="draggable">' + allButton + '</ul></div>');
   $('#display_comment_form').append(commentForm);
   if ($(result).find('div#document_history').html()) {
    $('#document_history').replaceWith('<div id="document_history">' + $(result).find('div#document_history').html() + '</div>');
   }
   var homeUrl = $('#home_url').val();

   $(result).find('#js_files').find('li').each(function () {
    $.getScript($(this).html());
   });
   $(result).find('ul#css_files').find('li').each(function () {
    var filePath = $(this).html();
    if (!$("link[href='" + filePath + "']").length) {
     $('<link href="' + filePath + '" rel="stylesheet">').appendTo("head");
    }
   });
   $.getScript(homeUrl + "includes/js/reload.js").done(function () {
    $('#overlay').css('display', 'none');
   });
  } else {
   $('#overlay').css('display', 'none');
  }

 }).fail(function () {
  alert("Form loading failed!");
  $('#overlay').css('display', 'none');
 });
}


  </script>
 </body>
</html>
