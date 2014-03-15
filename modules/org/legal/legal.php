<?php
if (!empty($_GET['mode'])) {
 $mode = $_GET['mode'];
} else {
 $path_access = -99;
 $mode = 1;
}
?>
<?php
include_once("legal.inc");
if (empty($_POST)) {
 try {
	require_once ino_include(THEME_DIR, 'legal_template.php');
 } catch (Exception $e) {
	echo $e->getMessage();
 }
}
?>