<?php 
if(!empty($_GET['mode'])){
 $mode = $_GET['mode'];
}else{
 $path_access = -99;
 $mode = 1;
}
?>
<?php require_once('value_group.inc') ?>
<?php empty($_POST) ? require_once('value_group_template.php'): false ;?>