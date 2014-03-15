<?php 
if(!empty($_GET['mode'])){
 $mode = $_GET['mode'];
}else{
 $path_access = -99;
 $mode = 1;
}
?>
<?php require_once('content_type.inc') ?>
<?php 
if(!empty($_POST)){
 return;
}
?>
<?php empty($_POST) ? require_once('content_type_template.php'): false ;?>
