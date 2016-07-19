<!DOCTYPE html>
<html>
 <head>
  <meta http-equiv="Content-Type" content="text/html; charset=UTF-8">
  <meta name="keywords" content="ERP,PHP ERP,Open Source ERP ">
  <title>inoERP Installation</title>
  <link href="engine/install/install.css" media="all" rel="stylesheet" type="text/css" />
  <script src="../../includes/js/jquery-2.0.3.min.js"></script>
  <script src="../../includes/js/jquery-ui.min.js"></script>
  <script src="engine/install/install.js"></script>
 </head>
 <body>
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
      } else if (($_GET['action'][0] == 'complete_install')) {
       require_once 'steps/complete_install.php';
      }
      ?>
     </div>

    </div>
   </div>
  </div>
 </body>
</html>