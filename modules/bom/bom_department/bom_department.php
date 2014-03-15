<?php 
if(!empty($_GET['mode'])){
 $mode = $_GET['mode'];
}else{
 $path_access = -99;
 $mode = 1;
}
?>
<?php include_once("bom_department.inc"); ?>
<?php empty($_POST) ? require_once('bom_department_template.php'): false ;?>