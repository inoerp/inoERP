<div id="json_form_data">
 <div id="header_top_container" style="display: block;">
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
 $mode = !empty($_GET['mode']) ? ($_GET['mode']) : '2';
 echo "<div id='mode'>$mode</mode>";
 ?>
 <?php
 if (!empty($js_file_paths)) {
  echo '<ul id="js_files">';
  foreach ($js_file_paths as $key => $js_file) {
   echo '<li>' . $js_file . '</li>';
  }
  echo '</ul>';
 }

 if (!empty($css_file_paths)) {
  echo '<ul id="css_files">';
  foreach ($css_file_paths as $key => $css_file) {
   echo '<li>' . $css_file . '</li>';
  }
  echo '</ul>';
 }

 if (!empty($template_file_names)) {
  echo '<div id="structure">';
  foreach ($template_file_names as $key => $tmpl_file) {
   include_once $tmpl_file;
  }
  echo '</div>';
 }

 if (!empty($reference_table) && !empty($reference_id)) {
  echo '<div id="comment_form" class="none">';
  include_once '../../comment.php';
  echo '</div>';
 }
 ?>
</div>