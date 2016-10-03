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
//  echo THEME_URL;
//  echo (!empty($content_class)) ? '/content_layout.css' : '/layout.css'
  ?>" media="all" rel="stylesheet" type="text/css" />
  <link href="<?php echo THEME_URL; ?>/public.css" media="all" rel="stylesheet" type="text/css" />
  <link href="<?php echo THEME_URL; ?>/menu.css" media="all" rel="stylesheet" type="text/css" />
  <link href="<?php echo THEME_URL; ?>/jquery.css" media="all" rel="stylesheet" type="text/css" />
  <link href="<?php echo HOME_URL; ?>tparty/bootstrap/css/bootstrap.css" rel="stylesheet">
  <link href="<?php echo HOME_URL; ?>tparty/bootstrap/css/style.css" rel="stylesheet">
  <link href="<?php echo HOME_URL; ?>tparty/font-awesome/css/font-awesome.min.css" rel="stylesheet">
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

  <div class="row">
   <div class="container">
    <div id="erp_form_area">
     <div id="structure">
     <div id="select_page">
      <div id ="form_header">
       <div class="error"></div><div id="loading"></div>
       <?php echo (!empty($show_message)) ? $show_message : ""; ?> 
       <ul id="form_box"> 
      </div>
      <div id="list_contents">
       <div id="searchForm"><?php echo!(empty($search_form)) ? $search_form : ""; ?></div>
       <div id="form_line" class="form_line">
        <div id="print">
         <table class="find_page normal">
          <thead> 
           <tr>
            <th><?php echo gettext('Click Select'); ?></th>
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
           foreach ($search_result as $record) {
            $primary_column = $class::$primary_column;
            echo '<tr>';
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
  <div class="row">
   <?php echo searching_tips(); ?>
  </div>
 </body>
</html>
<?php
// 5. Close connection
if (isset($dbc)) {
 $dbc->close_connection();
}
?>
