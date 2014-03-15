<?php
if (!empty($_GET['class_name'])) {
 $class_names = $_GET['class_name'];
} else {
 die('No class found!');
}
?>
<?php
include_once('includes/functions/loader.inc');

if (empty($_POST)) {
 try {
	require_once ino_include(THEME_DIR, $template_file_names[0]);
 } catch (Exception $e) {
	echo $e->getMessage();
 }
}
?>