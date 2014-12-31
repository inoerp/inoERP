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
 <div id="searchForm">
  <span class="heading"><?php echo!empty($program_name) ? $program_name : ""; ?></span>
  <?php echo!(empty($search_form)) ? $search_form : ""; ?>
  <?php $f->hidden_field('program_name', $program_name); ?>
 </div>
  </div>
</div>