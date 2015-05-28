<?php

$form_page = true;
if (!empty($_GET['class_name'])) {
 $class_names = $_GET['class_name'];
} else if (!empty($_GET['module_code'])) {
 $class_names = 'ino_generic';
 $type = !empty($_GET['type']) ? $_GET['type'] : null;
 include_once('includes/basics/basics.inc');
 $path = new path();
 if (!empty($_GET['path_id'])) {
  $ino_generic_html = $path->findBy_moduleCode($_GET['module_code'],$type, array($_GET['path_id']));
 } else {
  $ino_generic_html = $path->findBy_moduleCode($_GET['module_code'], $type, null);
 }
 include_once('includes/functions/loader.inc');
 if (!empty($_GET['window_type']) && $_GET['window_type'] == 'popup') {
  include_once(THEME_DIR . '/popup_main_template.inc');
 } else {
  include_once(THEME_DIR . '/main_template.inc');
 }
 return;
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

if (empty($_POST)) {
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
   if (!empty($_GET['window_type']) && $_GET['window_type'] == 'popup') {
    include_once(THEME_DIR . '/popup_main_template.inc');
   } else {
    include_once(THEME_DIR . '/main_template.inc');
   }
  } else {
   $continue = false;
//   pa($$class);
   echo "<h2>Could n't call the header</h2> Error @ form.php line ".__LINE__;
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
}
?>