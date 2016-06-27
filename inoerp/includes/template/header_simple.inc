<? ob_start(); ?>
<?php require_once __DIR__.'/../basics/basics.inc' ?>
<?php $session->redirect_login(); ?>
<?php $url = $_SERVER['REQUEST_URI']; ?>
<!--inoEMS - The First Enterprise Management System!-->
<!DOCTYPE html>
<html>
 <head>
  <meta http-equiv="Content-Type" content="text/html; charset=UTF-8">
  <title><?php echo isset($pageTitle) ? $pageTitle . ' - inoERP!' : ' inoERP! ' ?></title>
  <link href="<?php echo HOME_URL; ?>themes/print.css" media="all" rel="stylesheet" type="text/css" />
 </head>
 <body>
	<?php
	global $path_access;
	if ($path_access < 0) {
	 die("You dont have access to this page! :  ");
	}
	?>
	<? ob_flush(); ?>