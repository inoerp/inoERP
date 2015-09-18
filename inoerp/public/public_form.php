<?php

$form_page = true;
$dont_check_login = true;
if (!empty($_GET['router'])) {
 $router = $_GET['router'];
 $router_file = __DIR__ . "/includes/router/$router.php";
 if (file_exists($router_file)) {
  include_once __DIR__ . "/includes/router/$router.php";
 } else {
  die('Access Denied');
 }
} else if (!empty($_GET['class_name'])) {
 $class_names = $_GET['class_name'];
} else if (!empty($_GET['cname'])) {
 $class_names = $_GET['cname'];
} else {
 die('No class found!. Error @ form.php @@ line 15');
}
?>
<?php
include_once('includes/functions/loader.inc');

//exit script in case of delete statement
if ((!empty($_GET['delete'])) && ($_GET['delete'] == 1)) {
 return;
}


 try {

//     if(in_array($class, inoform::$docs_notAllowd_inDirectWebForm) && ($verify_web_form_allowed)){
//    $access_denied_msg = ('You can\'t open this page directly from webfrom. Please use the navigator');
//   }

  if (!in_array('ADMIN', $_SESSION['user_roles'])) {
   if (in_array($class, inoform::$docs_notAllowd_inDirectWebForm) && ($verify_web_form_allowed)) {
    $access_denied_msg = ('You can\'t open this page directly from webfrom. Please use the navigator');
   }
  }

  if ($continue) {
   if (!empty($_GET['window_type'])) {
    switch ($_GET['window_type']) {
     case 'popup':
      include_once(THEME_DIR . '/popup_main_template.inc');
      break;

     default :
      include_once(THEME_DIR . '/public_template.inc');
      break;
    }
   } else {
    include_once(THEME_DIR . '/public_template.inc');
   }
  } else {
   $continue = false;
   access_denied_redirection();
//   echo "<h2>Could n't call the header</h2> Error @ form.php line " . __LINE__;
   return;
  }

  if (!empty($_GET['view_type']) && $_GET['view_type'] == 'list') {
   require_once(INC_BASICS . DS . "search_page.inc");
  } else if (($update_access)) {
   require_once ino_include(THEME_DIR, $template_file_names[0]);
  } else if (($write_access) && (empty($$class->$class_id_first))) {
   require_once ino_include(THEME_DIR, $template_file_names[0]);
  } else if (($read_access) && ($mode == 2)) {
   require_once ino_include(THEME_DIR, $template_file_names[0]);
  } else {
   access_denied();
  }
 } catch (Exception $e) {
  echo $e->getMessage();
 }

?>