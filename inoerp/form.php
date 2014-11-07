<?php
if (!empty($_GET['class_name'])) {
 $class_names = $_GET['class_name'];
} else if (!empty($_GET['module_code'])) {
 $class_names = 'ino_generic';
 $type = !empty($_GET['type']) ? $_GET['type'] : null;
 include_once('includes/basics/basics.inc');
 $path = new path();
 $ino_generic_html = $path->findBy_moduleCode($_GET['module_code'], $type);
  include_once('includes/functions/loader.inc');
	require_once ino_include(THEME_DIR, $template_file_names[0]);
 return;
} else {
 die('No class found!');
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
	if (($update_access)) {
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