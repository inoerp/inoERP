<?php 
if(!empty($_GET['mode'])){
 $mode = $_GET['mode'];
}else{
 $path_access = -99;
 $mode = 1;
}
?>
<?php require_once('coa.inc') ?>
<?php empty($_POST) ? require_once('coa_template.php'):  false ;?>
