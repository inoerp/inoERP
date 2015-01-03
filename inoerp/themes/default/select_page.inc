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
 <?php
  if ($si->maintenance_cb == 1) {
   echo "<div class='error'>Site is under maintenance mode </div>";
  }
  if (!empty($access_deined)) {
   exit("Access denied ! <br> $msg <input action='action' class='button' type='button' value='Go Back' onclick='history.go(-1);' />");
  }
  ?>
<div id="all_contents">
	<div id="content">
	 <div id="main">
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
						<th>Click Select</th>
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
						echo '<td><span  class="quick_select button '. $primary_column . '">'. $record->$primary_column . '</td>';
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
  <script type="text/javascript">
 $(document).ready(function() {
	$('#select_page').on('click', '#search_reset_btn', function(e) {
	 e.preventDefault();
	 $(this).closest('#searchForm').find('.search_form').find('input:text, select').each(function() {
		$(this).val('');
	 });
	})

 });
</script>
 </body>
</html>
<?php
// 5. Close connection
if (isset($dbc)) {
 $dbc->close_connection();
}
?>