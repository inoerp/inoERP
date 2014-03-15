<?php
if (!empty($_GET['mode'])) {
 $mode = $_GET['mode'];
} else {
 $path_access = -99;
 $mode = 1;
}
?>
<?php
include_once("po.inc");
if (empty($_POST)) {
 try {
	require_once ino_include(THEME_DIR, 'po_template.php');
 } catch (Exception $e) {
	echo $e->getMessage();
 }
}
?>
<?php // empty($_POST) ? require_once 'po_template.php' : false;  ?>
