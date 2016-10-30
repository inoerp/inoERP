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
  <nav class="navbar navbar-inverse navbar-fixed-top">
   <div class="container-fluid">
    <div class="navbar-header">
     <button type="button" class="navbar-toggle collapsed" data-toggle="collapse" data-target="#navbar" aria-expanded="false" aria-controls="navbar">
      <span class="sr-only"><?php echo gettext('Toggle navigation') ?></span>
      <span class="icon-bar"></span>
     </button>
     <img src="<?php
     echo HOME_URL;
     echo!empty($si->logo_path) ? $si->logo_path : 'files/logo.png'
     ?>" class="logo_image" alt="logo"/>
     <a class="navbar-brand" href="<?php echo HOME_URL; ?>"><?php echo!empty($si->site_name) ? $si->site_name : 'inoERP'; ?></a>
    </div>
    <div id="navbar" class="navbar-collapse collapse">
     <ul class="nav navbar-nav navbar-right">
      <li><a href="http://demo.inoideas.org/extensions/ino_user/user_login.php" ><?php echo gettext('Demo') ?> <div class="arrow-up"></div></a></li>
      <li><a href="https://github.com/inoerp/inoERP" ><?php echo gettext('Download') ?> <div class="arrow-up"></div></a></li>
      <li class="active"><a href="http://inoideas.org/content.php?mode=9&content_type=forum&category_id=7" ><i class="fa fa-comments-o"></i> <?php echo gettext('Ask a Question') ?> <div class="arrow-up"></div></a></li>
      <li><a href="<?php echo HOME_URL; ?>content.php?content_type=documentation&amp;category_id=30"><?php echo gettext('Documentation') ?> <div class="arrow-up"></div></a></li><!-- end standard drop down -->
      <li><a href="<?php echo HOME_URL; ?>content.php?content_type=forum&amp;category_id=1"><?php echo gettext('Forum') ?> <div class="arrow-up"></div></a></li>

      <li>
       <div class="topbar-login ino_right_top">
        <?php if (!empty($_SESSION['login_status'])) { ?>
         <div class="dropdown">
          <button class="btn btn-default dropdown-toggle" type="button" id="menu1" data-toggle="dropdown"><i class="fa fa-user"> </i><?php echo ' ' . ucfirst($_SESSION['username']); ?>
           <span class="caret"></span></button>
          <ul class="dropdown-menu" role="menu" aria-labelledby="menu1">
           <!--<li role="presentation" class="dropdown-header">Dropdown header 1</li>-->
           <li role="presentation"><a role="menuitem" tabindex="-1" href="<?php echo HOME_URL; ?>"><i class="fa fa-home"></i> <?php echo gettext('Home')?></a></li>
           <li role="presentation"><a role="menuitem" tabindex="-1" href="<?php echo HOME_URL . 'form.php?class_name=user&mode=9&user_id=' . $_SESSION['user_id']; ?>"> <?php echo gettext('My Details')?></a></li>
           <li role="presentation"><a role="menuitem" class="pull-right" tabindex="-1" href="<?php echo HOME_URL . 'form.php?class_name=user_activity_v&amp;mode=2&amp;user_id=' . $_SESSION['user_id']; ?>"><i class="fa fa-tasks"></i> <?php echo gettext('Activities')?></a></li>
           <li role="presentation"><a role="menuitem" class="pull-right" tabindex="-1" href="<?php echo HOME_URL . 'search.php?class_name=sys_notification_user'; ?>"><i class="fa fa-bell-slash-o"></i> <?php echo gettext('Notification')?></a></li>
           <li role="presentation"><a role="menuitem"  tabindex="-1" href="<?php echo HOME_URL . 'form.php?class_name=user_dashboard_v&amp;mode=2&amp;user_id=' . $_SESSION['user_id']; ?>"><i class="fa fa-dashboard"></i> <?php echo gettext('Dashboard')?></a></li>
           <li role="presentation"><a role="menuitem"  tabindex="-1" href="<?php echo HOME_URL . 'form.php?class_name=user_dashboard_config&amp;mode=9&amp;user_id=' . $_SESSION['user_id']; ?>"><i class="fa fa-cog"></i> <?php echo gettext('Configure')?></a></li>
           <li role="presentation" class="divider"></li>
           <li role="presentation"><a role="menuitem"  tabindex="-1" href="<?php echo HOME_URL . 'extensions/ino_user/user_logout.php'; ?>"><i class="fa fa-sign-out"></i> <?php echo gettext('LogOut')?></a></li>
          </ul>
         </div>
         <?php
        } else {
         include_once 'extensions/ino_user/popup_login/user_popup_login_template.php';
        }
        ?>
       </div>
      </li>
     </ul>
     <?php echo $ss->entry_form($_GET); ?>
    </div>
   </div>

  </nav>
  <div class="ino navbar-form">
   <div id="navigation_bar"   class="col-sm-9 col-sm-offset-3 col-md-10 col-md-offset-2 mainbar">
    <div id="header_top_quick_nav" >
     <ul class="list-group inline_list">
      <li role="presentation"><i class="fa fa-toggle-left clickable right_bar_navigation_menu" title="<?php echo gettext('Toggle Navigation Menu')?>"></i></li>
      <li role="presentation"><a  href="<?php echo HOME_URL; ?>"><i class="fa fa-home" title="<?php echo gettext('Home')?>"></i></a></li>
      <li role="presentation"><a  href="#"><i class="fa fa-info" title="<?php echo gettext('Messages')?>"></i></a></li>
      <li role="presentation"><a  href="<?php echo HOME_URL . 'form.php?class_name=user_dashboard_v&amp;mode=2&amp;user_id=' . $_SESSION['user_id']; ?>"><i class="fa fa-dashboard" title="<?php echo gettext('Dashboard')?>"></i></a></li>
      <li>
       <div class="btn-group">
        <button type="button" class="btn btn-xs btn-info"  title="<?php echo gettext('Favourites')?>"><i class="fa fa-star-o" title="<?php echo gettext('Favourites')?>"></i></button>
        <button type="button" title="<?php echo gettext('Favourites')?>" class="btn btn-xs btn-info dropdown-toggle" data-toggle="dropdown" aria-expanded="false">
         <span class="caret"></span>
         <span class="sr-only"><?php echo gettext('Toggle Dropdown')?></span>
        </button>
        <?php echo $fav->show_currentUser_fav(true); ?>
       </div>
      </li>
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
              <span><a class="flaticon-list90 clickable erp_dashborad" href="form.php?class_name=user_dashboard_v&mode=2" title="<?php //echo gettext('ERP Dashboard'); ?>"> <?php //echo gettext('ERP Dashboard'); ?> </a></span>
             </div> end social icons -->
     <?php } ?>
    </div>
   </div>
  </div>

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

  <div class="container-fluid">
   <div class="row">
    <div class="col-sm-3 col-md-2 sidebar">
     <div id="accordion">
      <h3 class="clickable nav-panel"><i class="fa fa-warning"></i> <?php echo gettext( 'Transaction Alerts' ); ?></h3>
      <div>
       <div id="sys_msg_box">
        <div class="error"></div><div id="loading"></div>
       </div>
      </div>
      <h3 class="clickable nav-panel"><i class="fa fa-navicon"></i> <?php echo gettext( 'Navigation Menu' ); ?></h3>
      <div>
       <div id="sys_menu_left_vertical">
        <div class="btn-group-sm" role="group" aria-label="...">
         <button type="button" id='expand_all_nav' class="btn btn-default"><?php echo gettext( 'Expand All' ); ?></button>
         <button type="button" id='collapse_all_nav' class="btn btn-default"><?php echo gettext( 'Collapse All' ); ?></button>
        </div>
        <?php
        $pat = new path();
        echo ($pat->path_allpaths_block(array('divClass' => 'tree_view')));
        ?>
       </div>
      </div>
      <h3 class="clickable nav-panel recent-visits"><i class="fa fa-history"></i> <?php echo gettext( 'Recent Visits' ); ?></h3>
      <div>
       <div id="recent-visits">
        <?php echo ino_recent_visits(); ?>
       </div>
      </div>

     </div>
    </div>
    <div id="divider-bar" class="col-m-1"><i class="fa fa-toggle-left clickable"></i></div>

    <div id="erp_form_area" class="col-sm-9 col-sm-offset-3 col-md-10 col-md-offset-2 mainbar">
     <div id="content">
      <div id="structure"><span class="heading">
        <?php
        if (!empty($_GET['function_name'])) {
         echo '<div class="alert alert-info" role="alert" >' . ucwords(str_replace('_', ' ', $_GET['function_name'])) . ' ' . gettext('Report') . '</div>';
        } else if (!empty($class)) {
         echo '<div class="alert alert-info" role="alert" >' . gettext('Search') . ' ' . gettext(ucwords(str_replace('_', ' ', $class))) . '</div>';
        }
        ?>
       </span>
       <div id="search_page">
        <div id ="form_header">
         <?php echo (!empty($show_message)) ? $show_message : ""; ?> 
        </div>
        <div id="list_contents">
         <div id="searchForm" ><div class='hideDiv_input fa fa-plus-circle clickable'></div>
          <div class='hideDiv_input_element'><?php echo!(empty($search_form)) ? $search_form : ""; ?></div></div>
         <div id="searchResult" class="heading">
          <?php
          if (!empty($total_count)) {
           ?>
           <div id="searchResultMessages">
            <ul class="inline_list">
             <li><?php echo gettext('Download All Data in') ?> </li>
             <li>
              <!--download page creation for all records-->
              <?php
              if (!empty($all_download_sql)) {
               if (empty($search_class_array_all)) {
                $search_class_obj_all = $$class->findBySql($all_download_sql);
                $search_class_array_all = json_decode(json_encode($search_class_obj_all), true);
               }
               ?>
               <!--download page form-->
               <form action="<?php echo HOME_URL; ?>download.php" method="POST" name="download_all" id="download_all" target="_blank">
                <input type="hidden"  name="data" value="<?php print base64_encode(serialize($search_class_array_all)) ?>" >
                <input type="radio" name="download_format" checked="checked" value="excel_format"><?php echo gettext('Excel') ?> 
                <input type="radio" name="download_format" value="text_format"><?php echo gettext('Text') ?>
                <input type="radio" name="download_format" value="pdf_format"><?php echo gettext('Pdf') ?>
                <input type="radio" name="download_format" value="xml_format"><?php echo gettext('XML') ?>
                <input type="radio" name="download_format" value="worddoc_format"><?php echo gettext('Word Doc') ?>
                <input type="submit"  name="export_allResult" value="<?php echo gettext('Download') ?>" id="export_excel_allResult" class="clickable button"  >
               </form>
              <?php }
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
      <!--   end of structure-->
     </div>
    </div>
    <div class="col-sm-9 col-sm-offset-3 col-md-10 col-md-offset-2 mainbar">
     <div class="hidden" id="document_history"></div>
     <div class="footer-menu">
      <div id="half_copyrights">
       <?php
       global $si;
       echo nl2br($si->footer_message);
       ?>
       <ul>
        <li><a href="http://inoideas.org/content.php?mode=9&content_type=web_contact"><?php echo gettext( 'Contact' ); ?></a></li>
        <li><a href="https://github.com/inoerp/inoERP/releases"><?php echo gettext( 'Releases' ); ?></a></li>
        <li><a href="https://www.mozilla.org/MPL/2.0/"><?php echo gettext( 'MPL 2' ); ?></a></li>
        <li><a href="#"><?php echo gettext( 'Cookie Preferences' ); ?></a></li>
        <li class="active"><a href="#"><?php echo gettext( 'Terms of Use' ); ?></a></li>
       </ul>
      </div>
     </div><!-- end large-7 --> 
    </div>
   </div>



  </div>
  <div class="row">
   <div id="comment_form" class="none">
    <?php
    if (!empty($reference_table) && !empty($reference_id)) {
     include_once __DIR__ . '/../../comment.php';
    }
    ?>
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
