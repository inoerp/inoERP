<?php

 ini_set('display_errors', 1);
 error_reporting(E_ALL);
 set_time_limit(0);

 $db_type_a = array( 'demo' => 'Demo Instance',   'production' =>'Production Instance');
 
 $dont_check_login = true;
 $class_names = 'ino_install';

 include_once(__DIR__.'/includes/engine/install/class_ino_install.inc');
 include_once(__DIR__.'/includes/engine/install/include/basics.inc');
 include_once(__DIR__.'/includes/basics/wloader.inc');

 // Get array with the names of all modules compiled and loaded
 $php_modules = get_loaded_extensions();

 // Rewrite base
 $rewrite_base = str_replace(array("index.php", "install.php"), "", $_SERVER['PHP_SELF']);

 // Errors array
 $errors = array();

 // Module Directories to check
 $module_array = array('gl','ap','ar','inv','org','sys','hr', 'wip','bom');
 
 // Extension Directories to check
 $extensions_array = array('ino_user','block','comment','content','content_type','file','path', 'site_info');

 // Write Directories to check
 $dir_array = array('files');

 // Files to check
 $file1 =  HOME_DIR. DS. 'includes' . DS . 'basics' . DS . 'settings' . DS . 'dbsettings.php';
 $file_array = array($file1);

//exit script in case of delete statement
 /*
  * 1. Verify DB Settings are defined
  * 2. Verify able to connect to the DB
  */

 include_once(__DIR__.'/includes/engine/install/install_template.php');
?>
