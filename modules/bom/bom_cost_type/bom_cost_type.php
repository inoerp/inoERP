<?php 
if(!empty($_GET['mode'])){
 $mode = $_GET['mode'];
}else{
 $path_access = -99;
 $mode = 1;
}
?>
<?php include_once("bom_cost_type.inc"); ?>
<?php empty($_POST) ? require_once('bom_cost_type_template.php'): false ;?>
