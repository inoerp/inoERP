<? ob_start(); ?>
<?php include_once('../../includes/basics/header_simple.inc'); ?>
<?php
session_start();
$bc = new block_cache();
$bc->session_id = session_id();
$bc->delete_allBy_sessionId();
$session->logout();
$_SESSION = array();

//if (isset($_COOKIE['session_name()'])) {
// setcookie(session_name(), '', time() - 4200, '/');
//}

if (ini_get("session.use_cookies")) {
 $params = session_get_cookie_params();
 setcookie(session_name(), '', time() - 42000, $params["path"], $params["domain"], $params["secure"], $params["httponly"]
 );
}
session_destroy();
redirect_to(HOME_URL);
?>
<? ob_flush(); ?>