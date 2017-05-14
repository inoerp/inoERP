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
  <link href="<?php echo HOME_URL; ?>vendor/bootstrap/css/bootstrap.css" rel="stylesheet">
  <link href="<?php echo HOME_URL; ?>vendor/bootstrap/css/style.css" rel="stylesheet">
  <link href="<?php echo HOME_URL; ?>vendor/font-awesome/css/font-awesome.min.css" rel="stylesheet">
  <link href='http://fonts.googleapis.com/css?family=PT+Sans:400,400italic,700,700italic' rel='stylesheet' type='text/css'>
  <link href='http://fonts.googleapis.com/css?family=Lato:400,300,400italic,300italic,700,700italic,900' rel='stylesheet' type='text/css'>
  <link href='http://fonts.googleapis.com/css?family=Exo:400,300,600,500,400italic,700italic,800,900' rel='stylesheet' type='text/css'>
  <?php
  if (!empty($css_file_paths)) {
   foreach ($css_file_paths as $key => $css_file) {
    ?>
    <link href="<?php echo HOME_URL . $css_file; ?>" media="all" rel="stylesheet" type="text/css" />
    <?php
   }
  }
  ?>
  </head>
 <body>
<div id="ino-body">
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



  <div id="select_page_body2" class="row">
   <div class= "container-fluid">
    <div class="hidden-sm hidden-xs col-md-2 sidebar">
     <div id="accordion">
      <h3 class="clickable nav-panel" style="background-color:<?php echo $si->heading_color; ?>"><i class="fa fa-warning"></i> <?php echo gettext('Transaction Alerts') ?></h3>
      <div>
       <div id="sys_msg_box">
        <div class="error"></div><div id="loading"></div>
       </div>
      </div>
     </div>
    </div>


    <div id="erp_form_area" class="col-md-10 col-sm-12 col-md-offset-2">

     <div class="row">
      <div class="col-md-2">
       <a  role="button" class="erp-links form-page btn btn-lg btn-info" href="<?php echo HOME_URL; ?>"><i class="fa fa-file-text-o" title="Form Page"></i> <?php echo gettext('Create New Record'); ?></a>
      </div>
      <div class="col-md-2">
       <button  role="button" id="refresh_button" class="erp-links select-page btn btn-lg btn-info" ><i class="fa fa-search" title="Search & List Page"></i> <?php echo gettext('Search To Select'); ?></button>
      </div>
      <div id="header_top_container" class="col-md-6 pull-right">

      </div>
     </div>

     <div id="structure" class="row">
      <div id="select_page">
       <div id ="form_header">
        <div class="error"></div><div id="loading"></div>
        <?php echo (!empty($show_message)) ? $show_message : ""; ?> 
       </div>
       <div id="list_contents">
        <div id="searchForm" ><div class='hideDiv_input fa fa-plus-circle'></div>
         <div class='hideDiv_input_element'><?php echo!(empty($search_form)) ? $search_form : ""; ?></div></div>
        <div id="form_line" class="form_line">
         <div id="selectResult">
          <div id="selectResult_page">
           <table class="find_page normal">
            <thead> 
             <tr>
              <th><?php echo gettext('Click Select')?></th>
              <?php
              if (property_exists($class, 'column')) {
               $column_array = $$class->column;
              } else {
               $column_array = $$class->field_a;
              }
              foreach ($column_array as $key => $value) {
               echo '<th>' . $value . '</th>';
              }
              ?>
             </tr>
            </thead>

            <?php
            If (!empty($search_result)) {
             echo '<tbody>';
             foreach ($search_result as $k => $record) {
              $primary_column = $class::$primary_column;
              $tr_class = 'rowno_' . $k;
              echo "<tr class='{$tr_class}'>";
              echo '<td><button  class="quick_select button ' . $primary_column . '">' . $record->$primary_column . '</button></td>';
              foreach ($column_array as $key => $value) {
               echo "<td class=\"$value\">" . $record->$value . '</td>';
              }
              echo '</tr>';
             }
             echo '</tbody>';
            }
            ?>

           </table>
          </div>
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

    <div class="clearfix"></div>

   </div><!-- end container -->
  </div><!-- end transparent-bg -->
  <?php
  global $f;
  echo (!empty($footer_bottom)) ? "<div id=\"footer_bottom\"> $footer_bottom </div>" : "";
  echo $f->hidden_field_withId('home_url', HOME_URL);
  ?>
  <div class="row">
   <?php echo searching_tips(); ?>
  </div>
  </div>
	
	<script src="js/jquery-2.0.3.min.js"></script>
   <script src="js/jquery-ui.min.js"></script>
   <script src="<?php echo HOME_URL; ?>vendor/bootstrap/js/bootstrap.min.js"></script>
   <script src="<?php echo HOME_URL; ?>vendor/bootstrap/js/menu.js"></script>
   <script src="js/custom/tinymce/tinymce.min.js"></script>
   <script type="text/javascript" src="includes/basics/js_control.php"></script>
   <script src="js/save.js"></script>
   <script src="js/custom_plugins.js"></script>
   <script src="js/basics.js"></script>
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
 </body>
</html>
<?php
// 5. Close connection
if (isset($dbc)) {
 $dbc->close_connection();
}
?>
