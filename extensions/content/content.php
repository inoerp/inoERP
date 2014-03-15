<?php 
if(!empty($_GET['mode'])){
 $mode = $_GET['mode'];
}elseif(!empty($_POST['mode'])){
 $mode = $_POST['mode'];
}else{
 $path_access = -99;
 $mode = 1;
}
?>
<?php require_once('content.inc') ?>
<?php  
if(!empty($_POST)){
 return;
}
?>
<?php $allow_content_update = false;
if((!empty($_SESSION['username'])) && ($content->created_by == $_SESSION['username'])){
 $allow_content_update = true;
}elseif((!empty($_SESSION['user_roles']))&&(in_array('admin',$_SESSION['user_roles']))){
 $allow_content_update = true;
}
?>
<?php 
if($allow_content_update){
    require_once('content_template.php' );
}else{
    die('<div class="error message">Acees Denied - You don\'t have the enough authority to access the requested content!');
}
?>
