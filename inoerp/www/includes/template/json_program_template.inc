<div id="json_form_data">
 <?php
 echo '<ul id="js_files">';
 echo '<li>includes/js/program.js</li>';
 If (property_exists($class, 'js_fileName_prg')) {
  echo '<li>' . $class::$js_fileName_prg . '</li>';
 }
 echo '</ul>';

 if (property_exists($class, 'css_fileName_prg')) {
  echo '<ul id="css_files">';
  foreach ($css_file_paths as $key => $css_file) {
   echo '<li>' . $css_file . '</li>';
  }
  echo '</ul>';
 }
 ?>
 <div id='structure'>
      <?php
    if (property_exists($class_first, 'module') && !property_exists($class_first, 'dont_show_bread_crum')) {
     $module_name = $class_first::$module;
     $module_name_c = strtoupper($module_name);
     $form_bread_crum = '<ul class=inline-list>';
     $form_bread_crum .= "<li title=\"" . gettext('My Dashboard') . "\" >" . '<a  class="ajax-link" href="' . HOME_URL . 'form.php?class_name=user_dashboard_v"> ' . gettext( 'Dashboard' ) . '  >> </a></li>';
     $form_bread_crum .= '<li title="' . gettext($module_name_c) . '" ><a  class="ajax-link" href="' . HOME_URL . 'form.php?module_code=' . $module_name . '">&nbsp; ' . gettext( $module_name_c ) . ' </a></li>';
     $form_bread_crum .= '</ul>';
     echo $form_bread_crum;
    }
    ?>
 <div id="searchForm">
  <span class="heading"><?php echo!empty($program_name) ? $program_name : ""; ?></span>
  <?php echo!(empty($search_form)) ? $search_form : ""; ?>
  <?php $f->hidden_field('program_name', $program_name); ?>
 </div>
  </div>
</div>
