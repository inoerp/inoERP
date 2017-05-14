<div id="installation_header">
 <div class="page-header">
  <h1>inoERP installation <small>Requirements (Step 1)</small></h1>
</div>
</div>
<ul class="list-unstyled list-group row">
 <?php
  $proceed = true;
  if (version_compare(PHP_VERSION, "5.5", "<")) {
   echo '<li class="error alert alert-danger list-group-item col-md-4 ">PHP 5.5 or greater is required system</li>';
   $proceed = false;
  } else {
   echo '<li class="proceed alert alert-success list-group-item col-md-4  ">PHP Version : ' . PHP_VERSION . '</li>';
  }

  if (is_readable(HOME_DIR . DS . 'includes' . DS . 'basics' . DS . 'basics.inc')) {
   echo '<li class="proceed alert alert-success list-group-item col-md-4  ">' . translation('Basic file is readable', 'system') . '</li>';
  } else {
   echo '<li class="error alert alert-danger list-group-item col-md-4 ">' . translation('Basic file is not readable', 'system') . '</li>';
   $proceed = false;
  }

  if (in_array('gettext', $php_modules)) {
   echo '<li class="proceed alert alert-success list-group-item col-md-4  ">' . translation('Module gettext is installed', 'system') . '</li>';
  } else {
   echo '<li class="error alert alert-danger list-group-item col-md-4 ">' . translation('gettext module is required', 'system') . '</li>';
   $proceed = false;
  }
  
    foreach ($module_array as $mod) {
   if (is_dir(HOME_DIR.DS.'modules'.DS.$mod . '/')) {
    echo '<li class="proceed alert alert-success list-group-item col-md-4 ">' . translation('Module: <b> :mod </b> exists', 'system', array(':mod' => $mod)) . '</li>';
   } else {
    echo '<li class="error alert alert-danger list-group-item col-md-4 ">' . translation('Module: <b> :mod </b> does not exists', 'system', array(':mod' => $mod)) . '</li>';
    $proceed = false;
   }
  }

  if (in_array('PDO', $php_modules)) {
   echo '<li class="proceed alert alert-success list-group-item col-md-4 ">' . translation('Module PDO is installed', 'system') . '</li>';
  } else {
   echo '<li class="error alert alert-danger list-group-item col-md-4 ">' . translation('Module PDO is required', 'system') . '</li>';
   $proceed = false;
  }
  
      foreach ($extensions_array as $extn) {
   if (is_dir(HOME_DIR.DS.'extensions'.DS.$extn . '/')) {
    echo '<li class="proceed alert alert-success list-group-item col-md-4 ">' . translation('Extension: <b> :extn </b> exists', 'system', array(':extn' => $extn)) . '</li>';
   } else {
    echo '<li class="error alert alert-danger list-group-item col-md-4 ">' . translation('Extension: <b> :extn </b> does not exists', 'system', array(':extn' => $extn)) . '</li>';
    $proceed = false;
   }
  }

  if (function_exists('apache_get_modules')) {
   if (!in_array('mod_rewrite', apache_get_modules())) {
    echo '<li class="error alert alert-danger list-group-item col-md-4 ">' . translation('Apache Mod Rewrite is required', 'system') . '</li>';
    $proceed = false;
   } else {
    echo '<li class="proceed alert alert-success list-group-item col-md-4 ">' . translation('Module Mod Rewrite is installed', 'system') . '</li>';
   }
  } else {
   echo '<li class="proceed alert alert-success list-group-item col-md-4 ">' . translation('Module Mod Rewrite is installed', 'system') . '</li>';
  }

  foreach ($dir_array as $dir) {
   if (is_writable($dir . '/')) {
    echo '<li class="proceed alert alert-success list-group-item col-md-4 ">' . translation('Directory: <b> :dir </b> is writable', 'system', array(':dir' => $dir)) . '</li>';
   } else {
    echo '<li class="error alert alert-danger list-group-item col-md-4 ">' . translation('Directory: <b> :dir </b> not writable', 'system', array(':dir' => $dir)) . '</li>';
    $proceed = false;
   }
  }

	$go_to_install = false;
	
  foreach ($file_array as $file) {
   $complete_file =  $file;
   if (is_writable($complete_file)) {
    echo '<li class="proceed alert alert-success list-group-item col-md-4 ">' . translation('File: <b> :file </b> is writable', 'system', array(':file' => $file)) . '</li>';
   } else {
		$go_to_install = true;
    echo '<li class="error alert alert-danger list-group-item col-md-12 ">' . $complete_file . translation(' File: <b> : file </b> is not writable', 'system', array(':file' => $file)) ;
    echo '<br>You can proceed with installtion. However, make sure that database settings are correct<li>';
   }
  }

//  if (is_writable('.htaccess')) {
//   echo '<li class="proceed alert alert-success">' . translation('Main .htaccess file writable', 'system') . '</li>';
//  } else {
//   echo '<li class="error alert alert-danger">' . translation('Main .htaccess file not writable', 'system') . '</li>';
//   $proceed = false;
//  }
 ?>
</ul>
<?php
 if ($proceed) {
	if($go_to_install){
	 echo "<a href='install.php?action=start_install2' role='button' class='btn-primary btn-lg'>Continue</a>";
	}else{
	 echo "<a href='install.php?action=dbsettings' role='button' class='btn-primary btn-lg'>Continue</a>";
	}
  
 } else {
  echo "<a href='' role='button' class='btn-primary btn-lg'>Fix above error to proceed further</a>";
 }
?>
     