<? ob_start(); ?>
<?php require_once 'basics.inc' ; check_browser();?>
<!--inoEMS - The First Enterprise Management System!-->
<!DOCTYPE html>
<html>
 <head>
  <meta http-equiv="Content-Type" content="text/html; charset=UTF-8">
	<meta name="robots" content="noindex">
	<meta name="description" content="inoERP - A Open Source PHP/C++ based Enterprise Management System">
	<meta name="keywords" content="ERP,PHP ERP,Open Source ERP ">
  <title><?php echo isset($pageTitle) ? $pageTitle . ' - inoERP!' : ' inoERP! ' ?></title>
  <link href="<?php echo HOME_URL; ?>themes/default/layout.css" media="all" rel="stylesheet" type="text/css" />
  <link href="<?php echo HOME_URL; ?>themes/default/public.css" media="all" rel="stylesheet" type="text/css" />
  <link href="<?php echo HOME_URL; ?>themes/default/menu.css" media="all" rel="stylesheet" type="text/css" />
  <link href="<?php echo HOME_URL; ?>themes/default/jquery.css" media="all" rel="stylesheet" type="text/css" />
  <script src="<?php echo HOME_URL; ?>includes/js/jquery-2.0.3.min.js"></script>
  <script src="http://code.jquery.com/ui/1.10.3/jquery-ui.js"></script>
  <script src="<?php echo HOME_URL; ?>includes/js/jquery.hotkeys.js"></script>
	<script src="<?php echo HOME_URL; ?>includes/js/custom/tinymce/tinymce.min.js"></script>
 	<script src="<?php echo HOME_URL; ?>includes/js/save.js"></script>
	<script src="<?php echo HOME_URL; ?>includes/js/basics.js"></script>
 </head>
    <body>
   <div id="header" class="headerBgColor">
    <div class="logo"><h2><?php global $si;
		echo "<a href=\" " . HOME_URL . " \"> " . $si->site_name . "</a>"; ?>!</h1> </div>
    <div class="header_info"><?php // path::path_menu(); ?></div>
    <div class="user_info">
    </div>
   </div>
  <div id="header_bottom"></div>