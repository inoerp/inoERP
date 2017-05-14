<!DOCTYPE html>
<html>
 <head>
  <meta http-equiv="Content-Type" content="text/html; charset=UTF-8">
  <meta name="keywords" content="ERP,PHP ERP,Open Source ERP ">
  <title>inoERP Installation</title>
  <script src="<?php echo HOME_URL; ?>js/jquery-2.0.3.min.js"></script>
  <script src="<?php echo HOME_URL; ?>js/jquery-ui.min.js"></script>
  <script src="<?php echo HOME_URL; ?>includes/engine/install/install.js"></script>
  <link href="<?php echo HOME_URL; ?>vendor/bootstrap/css/bootstrap.css" rel="stylesheet">
  <link href="<?php echo HOME_URL; ?>vendor/bootstrap/css/style.css" rel="stylesheet">
  <link href="<?php echo HOME_URL; ?>vendor/font-awesome/css/font-awesome.min.css" rel="stylesheet">
  <link href="<?php echo HOME_URL; ?>themes/default/public.css" rel="stylesheet">
  <link href='https://fonts.googleapis.com/css?family=PT+Sans:400,400italic,700,700italic' rel='stylesheet' type='text/css'>
  <link href='https://fonts.googleapis.com/css?family=Lato:400,300,400italic,300italic,700,700italic,900' rel='stylesheet' type='text/css'>
  <link href='https://fonts.googleapis.com/css?family=Exo:400,300,600,500,400italic,700italic,800,900' rel='stylesheet' type='text/css'>
 </head>
 <body>
  <div class="white-wrapper jt-shadow">
   <div class="container">
    <div class="clearfix"></div>
   </div>
  </div>
  <div class="grey-wrapper jt-shadow no-padding-imp">
   <div class="container">
   <div id="content">
    <div id="main">
     <div id="structure">
      <div id="contents">
       <?php
       if (empty($_GET['action'])) {
        require_once 'steps/verify.php';
       } else if (!empty($_POST)) {
        require_once 'steps/start_install.php';
       } else if (($_GET['action'] == 'dbsettings')) {
        require_once 'steps/dbsettings.php';
       } else if (($_GET['action'] == 'start_install2')) {
        require_once 'steps/start_install2.php';
       }else if (($_GET['action'][0] == 'complete_install')) {
        require_once 'steps/complete_install.php';
       }
       ?>
      </div>

     </div>
    </div>
   </div>
    </div>
  </div>
 </body>
</html>