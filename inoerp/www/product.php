<?php

$dont_check_login = true;
?>
<?php

$content_class = true;
$class_names[] = 'ec_product_view';
?>
<?php

   require_once __DIR__.'/includes/basics/wloader.inc';
	 include_once(__DIR__.'/../inoerp_server/includes/functions/loader.inc');

if ($continue) {
 $reflector = new ReflectionClass($class);
 $fnname = $reflector->getFileName();
 $fdir = dirname($fnname);

 $include_file_names = glob($fdir . DS . "*.inc");
 $css_file_names = glob($fdir . "/*.css");
 $template_file_names = glob($fdir . DS . "*_template.php");

 if ($showContextMenu) {
  $js_file_names = glob($fdir . "/*.js");
  $js_file_paths = [];
  foreach ($js_file_names as $key => $js_file_name) {
   if (strpos($js_file_name, 'modules')) {
    $js_file_path = str_replace('\\', '/', substr($js_file_name, strpos($js_file_name, 'modules')));
   } else if (strpos($js_file_name, 'extensions')) {
    $js_file_path = str_replace('\\', '/', substr($js_file_name, strpos($js_file_name, 'extensions')));
   }
   array_push($js_file_paths, $js_file_path);
  }
 }

 $css_file_paths = [];
 foreach ($css_file_names as $key => $css_file_name) {
  if (strpos($css_file_name, 'modules')) {
   $css_file_path = str_replace('\\', '/', substr($css_file_name, strpos($css_file_name, 'modules')));
  } else if (strpos($css_file_name, 'extensions')) {
   $css_file_path = str_replace('\\', '/', substr($css_file_name, strpos($css_file_name, 'extensions')));
  } else if (strpos($css_file_name, 'engine')) {
   $css_file_path = str_replace('\\', '/', substr($css_file_name, strpos($css_file_name, 'engine')));
  }
  array_push($css_file_paths, $css_file_path);
 }

 foreach ($include_file_names as $key => $pathname) {
  include_once "$pathname";
 }
 $custom_inc_file_name = HOME_DIR . '/custom/include/' . $class . '_include.inc';
 if (file_exists($custom_inc_file_name)) {
  include_once "$custom_inc_file_name";
 }
} else {
 return;
}

include_once(THEME_DIR . '/product_template.inc');
?>