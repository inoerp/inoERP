<?php
$form_page = true;
require_once __DIR__.'/includes/basics/wloader.inc';
if (!empty($_GET['router'])) {
 $router = $_GET['router'];
 $router_file = __DIR__ . "/../inoerp_server/includes/router/$router.php";
 if (file_exists($router_file)) {
  include_once __DIR__ . "/../inoerp_server/includes/router/$router.php";
  return;
 } else {
  die('Access Denied');
 }
} else if (!empty($_GET['class_name'])) {
 $class_names = $_GET['class_name'];
} else if (!empty($_GET['module_code'])) {

 $class_names = 'ino_generic';
 $type = !empty($_GET['type']) ? $_GET['type'] : null;
 include_once(__DIR__ . '/../inoerp_server/includes/basics/basics.inc');
 
  /*
  * Get all modules in system and  check if module code exists
  * If module code does not exists then show error message
  */
 $all_modules = option_header::find_options_byName('SYS_MODULE');
 $mod_does_not_exists = true;
 foreach($all_modules as $mod){
	if($mod->option_line_code == $_GET['module_code']){
	 $mod_does_not_exists = false;
	 break;
	}
 }
 if($mod_does_not_exists){
	access_denied_redirection();
 }
 
 $path = new path();
 
 
 if (!empty($_GET['path_id'])) {
  $ino_generic_html = $path->findBy_moduleCode($_GET['module_code'], $type, array($_GET['path_id']));
 } else {
  $ino_generic_html = $path->findBy_moduleCode($_GET['module_code'], $type, null);
 }
 include_once(__DIR__ . '/../inoerp_server/includes/functions/loader.inc');
 if (!empty($_GET['window_type']) && $_GET['window_type'] == 'popup') {
  include_once(THEME_DIR . '/popup_main_template.inc');
 } else {
  include_once(THEME_DIR . '/main_template.inc');
 }
 return;
} else {
 $class_names = ['user_dashboard_v'];
// die('No class found!. Error @ form.php @@ line 15');
}
?>
<?php
//$dont_check_login = true;
include_once(__DIR__ . '/../inoerp_server/includes/functions/loader.inc');

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
   if (!empty($_GET['window_type'])) {
    switch ($_GET['window_type']) {
     case 'popup':
      include_once(THEME_DIR . '/popup_main_template.inc');
      break;

     case 'pub':
      
      include_once(THEME_DIR . '/public_template.inc');
      break;

     default :
      include_once(THEME_DIR . '/main_template.inc');
      break;
    }
   }else{
    include_once(THEME_DIR . '/main_template.inc');
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
}
?>