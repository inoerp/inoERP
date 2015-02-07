<?php
$form_page = true;
if (!empty($_GET['class_name'])) {
 $class_names = $_GET['class_name'];
} else if (!empty($_GET['module_code'])) {
 $class_names = 'ino_generic';
 $type = !empty($_GET['type']) ? $_GET['type'] : null;
 include_once('includes/basics/basics.inc');
 $path = new path();
 $ino_generic_html = $path->findBy_moduleCode($_GET['module_code'], $type);
 include_once('includes/functions/loader.inc');
 include_once(THEME_DIR . '/main_template.inc');
 return;
} else {
 die('No class found!. Error @ form.php @@ line 15');
}
?>
<?php

include_once('includes/functions/loader.inc');

//exit script in case of delete statement
if ((!empty($_GET['delete'])) && ($_GET['delete'] == 1)) {
 return;
}

if (empty($_POST)) {
 try {
//  $mode = !empty($mode) ? $mode : 2;
  if ($continue) {
   include_once(THEME_DIR . '/main_template.inc');
  } else {
   $continue = false;
   echo "<h2>Could n't call the header</h2>";
   return;
  }

  if (!empty($_GET['view_type']) && $_GET['view_type'] == 'list') {
   require_once(INC_BASICS . DS . "search_page.inc");
  } else if (($update_access)) {
   require_once ino_include(THEME_DIR, $template_file_names[0]);
  } else if (($write_access) && (empty($$class->$class_id_first))) {
   require_once ino_include(THEME_DIR, $template_file_names[0]);
  } else if (($read_access) && ($mode == 2)) {
   require_once ino_include(THEME_DIR, $template_file_names[0]);
  } else {
   access_denied();
  }
 } catch (Exception $e) {
  echo $e->getMessage();
 }
}
?>
<script type="text/javascript">
 $(document).ready(function () {

//    if (localStorage.getItem("form_erp_loaded") === 'undefined' || localStorage.getItem("form_erp_loaded") === null) {
//   localStorage.setItem("form_erp_loaded", 1);
//           $.getScript("includes/js/erp.js");
//  }
  
 });
</script>