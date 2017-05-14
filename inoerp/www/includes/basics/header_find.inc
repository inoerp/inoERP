<? ob_start(); ?>
<?php require_once 'basics.inc' ?>
<?php $session->redirect_login();?>
<!--inoEMS - The First Enterprise Management System!-->
<!DOCTYPE html>
<html>
    <head>
        <meta http-equiv="Content-Type" content="text/html; charset=UTF-8">
        <title><?php echo isset($pageTitle) ? $pageTitle . ' - inoERP!' : ' inoERP! ' ?></title>
        <link href="<?php echo HOME_URL; ?>themes/layout.css" media="all" rel="stylesheet" type="text/css" />
        <link href="<?php echo HOME_URL; ?>themes/public.css" media="all" rel="stylesheet" type="text/css" />
        <link href="<?php echo HOME_URL; ?>themes/menu.css" media="all" rel="stylesheet" type="text/css" />
        <link href="<?php echo HOME_URL; ?>themes/jquery.css" media="all" rel="stylesheet" type="text/css" />
        <script src="<?php echo HOME_URL; ?>include/js/jquery-2.0.3.min.js"></script>
        <script src="http://code.jquery.com/ui/1.10.3/jquery-ui.js"></script>
        <script src="<?php echo HOME_URL; ?>extensions/custom/tinymce/tinymce.min.js"></script>
        <script src="<?php echo HOME_URL; ?>include/js/basics.js"></script>
        <script src="<?php echo HOME_URL; ?>include/js/expandcollapsed.js"></script>
    </head>
    <body>
   <div id="main_find">
            
  <? ob_flush(); ?>