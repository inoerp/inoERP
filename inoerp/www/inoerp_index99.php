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
$class_names[] = 'content';
?>
<?php
include_once("includes/functions/loader.inc");
$pageTitle = 'Home';
?>
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
  <title><?php echo isset($pageTitle) ? $pageTitle . ' | inoERP ' : ' inoERP  ' ?></title>
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
  <link href="<?php echo HOME_URL; ?>vendor/bootstrap/css/bootstrap.css" rel="stylesheet">
  <!-- Styles -->
  <link href="<?php echo HOME_URL; ?>vendor/bootstrap/css/style.css" rel="stylesheet">
  <!-- Carousel Slider -->
  <link href="<?php echo HOME_URL; ?>vendor/font-awesome/css/font-awesome.min.css" rel="stylesheet">
  <link href='https://fonts.googleapis.com/css?family=PT+Sans:400,400italic,700,700italic' rel='stylesheet' type='text/css'>
  <link href='https://fonts.googleapis.com/css?family=Lato:400,300,400italic,300italic,700,700italic,900' rel='stylesheet' type='text/css'>
  <link href='https://fonts.googleapis.com/css?family=Exo:400,300,600,500,400italic,700italic,800,900' rel='stylesheet' type='text/css'>
  <script src="<?php echo HOME_URL; ?>includes/js/jquery-2.0.3.min.js"></script>
  <script src="<?php echo HOME_URL; ?>includes/js/jquery-ui.min.js"></script>
  <script src="<?php echo HOME_URL; ?>vendor/bootstrap/js/bootstrap.min.js"></script>
  <script src="<?php echo HOME_URL; ?>vendor/bootstrap/js/menu.js"></script>
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
 <body id="ino-home">
  <nav class="navbar navbar-default navbar-fixed-top">
  <div id="topbar" class="topbar clearfix">
   <div class="container">
    <div class="row">
     <div class="col-lg-1 col-md-1 hidden-sm hidden-xs pull-left "><img class="img-vs" src="http://inoideas.org/files/logo.png"/></div>
     <div class="hidden-md hidden-lg pull-left"><a class="fa fa-navicon clickable right_navicon" href="#"></a><div id="navbar-collapse-right" class="hidden"><j class="fa fa-close ino-close-right-navbar clickable white-font-link" title="close navigation"></j><?php echo $menu_line->show_menu_list(1); ?></div></div>
      <div id="navbar-collapse-1" class="navbar-collapse collapse navbar-right hidden-sm hidden-xs  pull-left"> <?php echo $menu_line->show_menu_list(1); ?></div>
     
     <div class="callus col-lg-5 col-md-5 col-sm-7 hidden-xs">
      <span class="topbar-email"><i class="fa fa-envelope"></i> <a href="<?php echo HOME_URL . 'content.php?mode=9&content_type=web_contact' ?>"><?php echo!empty($si->email) ? $si->email : 'contact@site.org' ?></a></span>
      <span class="topbar-phone"><i class="fa fa-phone"></i> <a href="#"><?php echo!empty($si->phone_no) ? $si->phone_no : '1-111-1111' ?></a></span>
     </div><!-- end callus -->
     <div class="topbar-login col-lg-1 col-md-1 col-sm-1 col-xs-5 pull-right "><?php ino_topbar_login(); ?></div>
    </div>
    </div>
   </div><!-- end container -->
  </nav>

  <div class="video-container" style="margin-top: -15px">
   <div class="col-md-12">

    <div align="center" class="embed-responsive embed-responsive-16by9 video-display" >
     <video autoplay loop muted class="embed-responsive-item">
      <source src="files/video/inoerp_intro1.mp4" type="video/mp4">
     </video>
    </div>

    <div align="center" class="video-message text-center hidden-xs">
     <h1 class="message1">inoERP Simple & Effective ERP</h1>
    </div>

    <!--  </div><!-- end accordion first -->
    <!--  </div> --><!-- end widget -->
   </div>
  </div>
  <hr class="clearfix">

  <div class="white-wrapper">
   <div class="container">
    <!-- end col-lg-6 -->
    <div class="col-md-5 ">
     <div class="release_message">
      <span class="longHeading">inoERP is an open source web based enterprise management system.
       It’s built using open source technologies and has a wide range of features suitable for running 
       various kind of  businesses. <br>
       The primary objective of inoERP is to provide a <span class="text-success">dynamic pull based automated transaction 
        system </span>(using IOT & RFID)
      </span>
      <span class="heading">inoERP 0.4.1 </span>
      InoERP version 0.4.1 is released on 31-Jan-2016 , and is now available for download. This version is fully functional and ready for production usage. 
      <br>Read the change log <a href="http://inoideas.org/content/change-log"> here </a> and the commits
      <a href="https://github.com/inoerp/inoERP/commits/master"> here </a>
      <br>Download the latest version from  <a href="https://github.com/inoerp/inoERP"> GitHub  </a>, or 
      <a href="https://sourceforge.net/projects/inoerp/"> Source Forge  </a>
      <br>
      <form action="https://www.google.com" id="cse-search-box" target="_blank">
       <div>
        <input type="hidden" name="cx" value="partner-pub-3081028146173931:7997050045" />
        <input type="hidden" name="ie" value="UTF-8" />
        <input type="text" name="q" size="40" />
        <input type="submit" name="sa" value="Search" />
       </div>
      </form>
      <script type="text/javascript" src="https://www.google.com/coop/cse/brand?form=cse-search-box&amp;lang=en"></script>

     </div>
    </div><!-- end col-lg-6 -->
   </div><!-- end container -->
  </div>
  <div class="grey-wrapper jt-shadow no-padding-imp">
   <div class="container">
    <div class="text-center text-warning"><h1> Modules & Extensions</h1></div>
    <div class="col-md-4 col-sm-6">
     <div class="panel panel-ino-light-grey">
      <!-- Default panel contents -->
      <div class="panel-heading  text-center large-text-bold"><i class="fa fa-bank"></i> Finance</div>
      <div class="panel-body">
       <ul class="list-group">
        <li class="list-group-item">Accounts Payable</li>
        <li class="list-group-item">Accounts Receivable</li>
        <li class="list-group-item">Fixed Asset</li>
        <li class="list-group-item">General Ledger</li>
        <li class="list-group-item">Project Billing</li>
        <li class="list-group-item">Project Costing</li>
       </ul>
      </div>
     </div>
    </div>


    <div class="col-md-4 col-sm-6">
     <div class="panel panel-ino-light-grey">
      <!-- Default panel contents -->
      <div class="panel-heading text-center large-text-bold"><i class="fa fa-truck"></i> Supply Chain</div>
      <div class="panel-body">
       <ul class="list-group">
        <li class="list-group-item">Sales & Distribution</li>
        <li class="list-group-item">Inventory</li>
        <li class="list-group-item">Purchasing</li>
        <li class="list-group-item">Forecasting & Planning</li>
        <li class="list-group-item">Point of Sale</li>
        <li class="list-group-item">eCommerce</li>
       </ul>
      </div>
     </div>
    </div>

    <div class="col-md-4 col-sm-6">
     <div class="panel panel-ino-light-grey">
      <!-- Default panel contents -->
      <div class="panel-heading text-center large-text-bold"><i class="fa fa-cogs"></i> Manufacturing</div>
      <div class="panel-body">
       <ul class="list-group">
        <li class="list-group-item">BOM & Formula</li>
        <li class="list-group-item">Routing & Recipe</li>
        <li class="list-group-item">Cost Management</li>
        <li class="list-group-item">Quality</li>
        <li class="list-group-item">Process Manufacturing</li>
        <li class="list-group-item">Manufacturing Execution System</li>
       </ul>
      </div>
     </div>
    </div>

    <div class="col-md-4 col-sm-6">
     <div class="panel panel-ino-light-grey">
      <!-- Default panel contents -->
      <div class="panel-heading text-center large-text-bold"><i class="fa fa-life-bouy"></i> Service & Support</div>
      <div class="panel-body">
       <ul class="list-group">
        <li class="list-group-item">Service Contract</li>
        <li class="list-group-item">Support Help Desk</li>
        <li class="list-group-item">Change Management</li>
        <li class="list-group-item">Document & Workflow Management</li>
        <li class="list-group-item">Asset Maintenance</li>
        <li class="list-group-item">RFID & Barcode</li>
       </ul>
      </div>
     </div>
    </div>

    <div class="col-md-4 col-sm-6">
     <div class="panel panel-ino-light-grey">
      <!-- Default panel contents -->
      <div class="panel-heading text-center large-text-bold"><i class="fa fa-users"></i> Human Resource</div>
      <div class="panel-body">
       <ul class="list-group">
        <li class="list-group-item">Employee</li>
        <li class="list-group-item">Compensation, Payroll & Expense</li>
        <li class="list-group-item">Approval Process</li>
        <li class="list-group-item">Timesheet & Leave Management</li>
        <li class="list-group-item">Self Service</li>
        <li class="list-group-item">Work Structure</li>
       </ul>
      </div>
     </div>
    </div>


    <div class="col-md-4 col-sm-6">
     <div class="panel panel-ino-light-grey">
      <!-- Default panel contents -->
      <div class="panel-heading  text-center large-text-bold"><i class="fa fa-sliders"></i> Extensions</div>
      <div class="panel-body">
       <ul class="list-group">
        <li class="list-group-item">User, Role & Group</li=>
        <li class="list-group-item">Content Management</li>
        <li class="list-group-item">Notification, eMail & Chat</li>
        <li class="list-group-item">Site, Theme & Blocks</li>
        <li class="list-group-item">Custom Form, Reports, Menus</li>
        <li class="list-group-item">...Many More..</li>
       </ul>
      </div>
     </div>
    </div>

   </div>

  </div>




  <div class="white-wrapper no-padding-imp">
   <div class="container">
    <div style="text-align:center;"> <h1>Special Features</h1></div>
    <div class="services_vertical">
     <div class="col-sm-6">
      <div class="service_vertical_box">
       <div class="service-icon">
        <i class="fa fa-lightbulb-o fa-4x"></i>
       </div>
       <h3>Dynamic Pull Based System</h3>
       <p>
        Dynamic pull system is an advanced version of pull system which encompasses the best feature of traditional pull system & MRP. </p>
       <a href="http://inoideas.org/content.php?mode=2&content_id=197&content_type_id=47" class="readmore">Read More...</a>
      </div><!-- end service_vertical_box -->
     </div><!-- end col-lg-4 -->
     <div class="col-sm-6">
      <div class="service_vertical_box">
       <div class="service-icon">
        <i class="fa fa-cogs fa-4x"></i>
       </div>
       <h3>Custom Report Builder</h3>
       <p>The product comes with an inbuilt drag & drop query builder, which can be used to create any kind of custom reports without writing any PHP, SQL code  </p>
       <a href="https://www.youtube.com/watch?feature=player_embedded&v=uOzP_v9glRc&list=PLI9s_lIFpC099xADLymQcDCmrDhnkxcjM" class="readmore">Read More...</a>
      </div><!-- end service_vertical_box -->
     </div><!-- end col-lg-4 -->
     <div class="col-sm-6">
      <div class="service_vertical_box">
       <div class="service-icon">
        <i class="fa fa-tablet fa-4x"></i>
       </div>
       <h3>Multi-Device Usage</h3>
       <p>ino ERP can be used with any modern browser through desktop, laptop & mobile devices with any resolution size. </p>
       <a href="#" class="readmore">Read More...</a>
      </div><!-- end service_vertical_box -->
     </div><!-- end col-lg-4 -->
     <div class="col-sm-6">
      <div class="service_vertical_box">
       <div class="service-icon">
        <i class="fa fa-crosshairs fa-4x"></i>
       </div>
       <h3>End to End System</h3>
       <p>Can be used as a single system for end to end supply chain, fiance, document approval, HR & MES system. </p>
       <a href="http://inoideas.org/content.php?mode=2&content_id=245&content_type=documentation" class="readmore">Read More...</a>
      </div><!-- end service_vertical_box -->
     </div><!-- end col-lg-4 -->
     <div class="col-sm-6">
      <div class="service_vertical_box">
       <div class="service-icon">
        <i class="fa fa-users fa-4x"></i>
       </div>
       <h3>in-Built CMS & Collaboration </h3>
       <p>The in-built content management system seamlessly integrate with the ERP system. Can be used for employee, supplier & customer collaboration </p>
       <!--<a href="#" class="readmore">Read More...</a>-->
      </div><!-- end service_vertical_box -->
     </div><!-- end col-lg-4 -->
     <div class="col-sm-6">
      <div class="service_vertical_box">
       <div class="service-icon">
        <i class="fa fa-bars fa-4x"></i>
       </div>
       <h3>Flexible Architecture</h3>
       <p>All forms, reports & documents are flexible enough to add any kind of new element as per the business requirement. </p>
       <!--<a href="#" class="readmore">Read More...</a>-->
      </div><!-- end service_vertical_box -->
     </div><!-- end col-lg-4 -->
     <div class="clearfix"></div>
    </div><!-- end services_vertical -->
   </div><!-- end container -->
  </div><!-- end transparent-bg -->

  <!-- end grey-wrapper -->
  <div class="grey-wrapper jt-shadow padding-top content_summary">
   <div class="make-center wow fadeInUp animated" style="visibility: visible;">
    <div class="container">
     <div id="structure">
      <?php
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
      $fp_contnts_ai->seek($position);
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
       echo '<div class="col-md-4 col-sm-6' . $count_class_val . ' ">
              <div class="panel panel-ino-light-grey">
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

  <div class="make-bg-full">
   <div class="calloutbox-full-mini nocontainer">
    <div class="long-twitter">
     <p class="lead"><i class="fa fa-star"></i>
      All ino ERP code is Copyright by the Original Authors as mentioned on COPYRIGHT.txt file.
      <br>inoERP is an open Source software; you can redistribute it and/or modify
      it under the terms of the Mozilla Public License Version 2.0 </p>
    </div>
   </div><!-- end calloutbox -->
  </div><!-- make bg -->
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

       <li><a href="http://inoideas.org/content.php?mode=9&content_type=web_contact">Contact</a></li>
       <li><a href="https://github.com/inoerp/inoERP/releases">Releases</a></li>
       <li><a href="https://www.mozilla.org/MPL/2.0/">MPL 2</a></li>
       <li><a href="#">Cookie Preferences</a></li>
       <li class="active"><a href="#">Terms of Use</a></li>

      </ul>
     </div>
    </div><!-- end large-7 --> 
   </div><!-- end container -->
  </div>

  <div class="dmtop">Scroll to Top</div>
  <!-- Main Scripts-->

  <?php
  global $f;
  echo (!empty($footer_bottom)) ? "<div id=\"footer_bottom\"> $footer_bottom </div>" : "";
  echo $f->hidden_field_withId('home_url', HOME_URL);
  echo '<div class="hidden">' .$si->analytics_code .'</div>';
  ?>
  <div class="hidden"><a href="http://www.beyondsecurity.com/vulnerability-scanner-verification/inoideas.org"><img src="https://seal.beyondsecurity.com/verification-images/inoideas.org/vulnerability-scanner-2.gif" alt="Website Security Test" border="0" /></a></div>
 </body>
</html>