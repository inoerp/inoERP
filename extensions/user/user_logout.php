<? ob_start(); ?>
<?php include_once("user.inc"); ?>
<?php 
session_start();

$session->logout();

$_SESSION = array();
if(isset($_COOKIE['session_name()']))
{
    setcookie(session_name(), '',  time()-4200, '/');
}
session_destroy();

redirect_to(HOME_URL);
?>
<? ob_flush(); ?>