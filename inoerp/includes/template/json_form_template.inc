<div id="json_form_data">
 <?php
 if ($no_organization_access) {
  echo '<div id="structure">';
  echo ino_access_denied_organizationAcess();
  echo '</div></div>';
  return;
 }
 ?>
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

 if (!empty($access_denied_msg)) {
  echo '<div id="structure">';
  echo ino_access_denied($access_denied_msg);
  echo '</div>';
 } else if (!empty($template_file_names)) {
  echo '<div id="structure">';
  echo getBreadCrumb($class_first);
  foreach ($template_file_names as $key => $tmpl_file) {
   include_once $tmpl_file;
  }
  echo '</div>';
 }

 if (property_exists($$class, 'primary_column')) {
  $primary_column_h = $class::$primary_column;

  if (!empty($$class->$primary_column_h)) {
   $user_creationBy = user::find_by_id($$class->created_by);
   $user_lastUpdateBy = user::find_by_id($$class->last_update_by);
   echo '<div id="document_history" ><ul id="document_history_ul">';
   if (!empty($user_creationBy)) {
    echo '<li id="created_by">Created By : ' . $user_creationBy->username . '</li>';
    echo '<li id="creation_date">Creation Date : ' . $$class->creation_date . '</li>';
   }
   if (!empty($user_creationBy)) {
    echo '<li id="last_update_by">Last Update By : ' . $user_lastUpdateBy->username . '</li>';
    echo '<li id="last_update_date">Last Update Date : ' . $$class->last_update_date . '</li>';
   }
   echo '</ul></div>';
  }
 }


 if (!empty($reference_table) && !empty($reference_id)) {
  echo '<div id="comment_form" class="none">';
  include_once '../../comment.php';
  echo '</div>';
 }
 ?>
</div>