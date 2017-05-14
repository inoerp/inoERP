<?php

if (preg_match('/(?i)msie [5-8]/', $_SERVER['HTTP_USER_AGENT'])) {
 echo ($_SERVER['HTTP_USER_AGENT']);
 echo "<h2>Sorry! Your browser is outdated and not compatible with this site!!!</h2> "
 . "Please use any modern browsers such as Firefox, Opera, Chrome, IE 10+ ";
 exit;
}
$dont_check_login = true;
?>
<?php
require_once __DIR__.'/includes/basics/wloader.inc';

if (file_exists('install.php')) {
 if (isset($_GET['install'])) {
  if ($_GET['install'] == 'done') {
   // Delete the insatll file after installation
   @unlink('install.php');
   // Redirect to main page
   header('location: index.php');
  }
 } else {
  header('location: install.php');
 }
 return;
}

//header('location: form.php?class_name=user_dashboard_v');

if (empty($_GET['class_name']) && empty($_GET['cname'])) {
 $class_names[] = 'index';
} else if (!empty($_GET['class_name'])) {
 $class_names[] = $_GET['class_name'];
} elseif (!empty($_GET['cname'])) {
 $class_names[] = $_GET['cname'];
}


if (empty($_GET['doc_type']) && empty($_GET['dtype'])) {
 $doc_type = 'content';
} else if (!empty($_GET['doc_type'])) {
 $doc_type = $_GET['doc_type'];
} elseif (!empty($_GET['dtype'])) {
 $doc_type = $_GET['dtype'];
}



switch ($doc_type) {
 case 'content' :
  include_once(__DIR__.'/../inoerp_server/includes/functions/loader.inc');
  if ($class == 'index') {
   if (!empty($si) && ($si->default_home_page == 'content')) {
    include_once THEME_DIR . '/home_page_template.php';
   } else if (!empty($si) && !empty(($si->default_home_page))) {
    include_once THEME_DIR . $si->default_home_page;
   } else {
    header('location: form.php?class_name=user_dashboard_v');
   }
  } else {
   include_once 'content.php';
  }
  break;

 case 'product' :
  include_once 'product.php';
  break;

 case 'form' :
  include_once 'form.php';
  break;

  case 'pform' :
  include_once __DIR__.'/public/public_form.php';
  break;
 
 default :
  include_once 'content.php';
  break;
}
?>