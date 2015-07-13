<div id="installation_header"><h1>inoERP installation : </h1><h2> Requirements (Step 1)</h2></div>
<ul class="list-unstyled">
 <?php
  $proceed = true;
  if (version_compare(PHP_VERSION, "5.5", "<")) {
   echo '<li class="error alert alert-danger">PHP 5.5 or greater is required system</li>';
   $proceed = false;
  } else {
   echo '<li class="proceed alert alert-success">PHP Version : ' . PHP_VERSION . '</li>';
  }

  if (is_readable(HOME_DIR . DS . 'includes' . DS . 'basics' . DS . 'basics.inc')) {
   echo '<li class="proceed alert alert-success">' . translation('Basic file is readable', 'system') . '</li>';
  } else {
   echo '<li class="error alert alert-danger">' . translation('Basic file is not readable', 'system') . '</li>';
   $proceed = false;
  }

  if (in_array('gettext', $php_modules)) {
   echo '<li class="proceed alert alert-success">' . translation('Module gettext is installed', 'system') . '</li>';
  } else {
   echo '<li class="error alert alert-danger">' . translation('gettext module is required', 'system') . '</li>';
   $proceed = false;
  }
  
    foreach ($module_array as $mod) {
   if (is_dir(HOME_DIR.DS.'modules'.DS.$mod . '/')) {
    echo '<li class="proceed alert alert-success">' . translation('Module: <b> :mod </b> exists', 'system', array(':mod' => $mod)) . '</li>';
   } else {
    echo '<li class="error alert alert-danger">' . translation('Module: <b> :mod </b> does not exists', 'system', array(':mod' => $mod)) . '</li>';
    $proceed = false;
   }
  }

  if (in_array('PDO', $php_modules)) {
   echo '<li class="proceed alert alert-success">' . translation('Module PDO is installed', 'system') . '</li>';
  } else {
   echo '<li class="error alert alert-danger">' . translation('Module PDO is required', 'system') . '</li>';
   $proceed = false;
  }
  
      foreach ($extensions_array as $extn) {
   if (is_dir(HOME_DIR.DS.'extensions'.DS.$extn . '/')) {
    echo '<li class="proceed alert alert-success">' . translation('Extension: <b> :extn </b> exists', 'system', array(':extn' => $extn)) . '</li>';
   } else {
    echo '<li class="error alert alert-danger">' . translation('Extension: <b> :extn </b> does not exists', 'system', array(':extn' => $extn)) . '</li>';
    $proceed = false;
   }
  }

  if (function_exists('apache_get_modules')) {
   if (!in_array('mod_rewrite', apache_get_modules())) {
    echo '<li class="error alert alert-danger">' . translation('Apache Mod Rewrite is required', 'system') . '</li>';
    $proceed = false;
   } else {
    echo '<li class="proceed alert alert-success">' . translation('Module Mod Rewrite is installed', 'system') . '</li>';
   }
  } else {
   echo '<li class="proceed alert alert-success">' . translation('Module Mod Rewrite is installed', 'system') . '</li>';
  }

  foreach ($dir_array as $dir) {
   if (is_writable($dir . '/')) {
    echo '<li class="proceed alert alert-success">' . translation('Directory: <b> :dir </b> is writable', 'system', array(':dir' => $dir)) . '</li>';
   } else {
    echo '<li class="error alert alert-danger">' . translation('Directory: <b> :dir </b> not writable', 'system', array(':dir' => $dir)) . '</li>';
    $proceed = false;
   }
  }

  foreach ($file_array as $file) {
   $complete_file = HOME_DIR . DS . $file;
   if (is_writable($complete_file)) {
    echo '<li class="proceed alert alert-success">' . translation('File: <b> :file </b> is writable', 'system', array(':file' => $file)) . '</li>';
   } else {
    echo '<li class="error alert alert-danger">' . $complete_file . translation('File: <b> : file </b> not writable', 'system', array(':file' => $file)) . '</li>';
    $proceed = false;
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
  echo "<a href='install.php?action=dbsettings' class='button btn-primary continue'>Continue</a>";
 } else {
  echo "<a href='' class='button btn-primary error'>Fix above error to proceed further</a>";
 }
?>
     